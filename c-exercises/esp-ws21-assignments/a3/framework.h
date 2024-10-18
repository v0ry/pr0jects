//-----------------------------------------------------------------------------
// framework.h
//
// Framework for ESP A3.
//
// compile-time-configuration:
//   To enable the 'load' command used for bonus define 'BONUS' before
//   including this framework header.
//   Example:
//     ...
//     #define BONUS
//     #include "framework.h"
//     ...
//-----------------------------------------------------------------------------
//
#pragma once
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define TOKEN_SEPARATORS " \t\n"

/*
  Enum representing one in 4 possible commands as well as an additional
  unknown command.

  Note: The additional <LOAD> command will only be enabled when 'BONUS'
        is defined!
*/
typedef enum _Command_ {
  INSERT,
  SAVE,
  QUIT,
  HELP,
  UNKNOWN
#ifdef BONUS
  ,LOAD
#endif

} Command;

/*
  Enum representing the positioning of a word on the gamefield.
*/
typedef enum _Orientation_ {
  HORIZONTAL,
  VERTICAL
} Orientation;

/*
  Data structure representing a parsed input command.
*/
typedef struct _Input_ {
  // value representing one of the possible commands or <UNKNOWN> in case
  // of an unknown command.
  Command command_;
  // flag that will be set when a parsing error occurs (i.e. wrong number
  // of positional arguments to command)
  bool is_error_;
  // row index parameter of the insert command. Represented with letters.
  // Not range checked by parseCommand function.
  // Valid only when command_ is <INSERT>.
  char row_;
  // column index parameter of the insert command. Represented with letters.
  // Not range checked by parseCommand function.
  // Valid only when command_ is <INSERT>.
  char column_;
  // value representing the orientation parameter of the insert command.
  // Valid only when command_ is <INSERT>.
  Orientation orientation_;
  // the word parameter of the insert command. Will be allocated heap memory
  // in case of a successful input command. (i.e. is_error_ == false)
  // Valid only when command_ is <INSERT>.
  char *word_;
  // indicates if input is only whitespaces
  bool only_whitespaces_;
  // the file-name parameter of the load command. Will be allocated heap memory
  // in case of a successful load command. (i.e. is_error_ == false)
  // Valid only when command_ is <LOAD>.
  // Will only be enabled when 'BONUS' is defined.
#ifdef BONUS
  char* load_config_;
#endif
} Input;

// ----------------------------------------------------------------------------
// Parses the command and its arguments from the string <line>
//
// Saves the parsed values to applicable parameters in <input>.
//
// The string word_ (and load_config_) in the input structure will be allocated
// heap memory and will thus have to be freed in case of a successful insert 
// command.
//
// The parsed values are not range or value checked. (i.e. column_ could be
// out of range/something different than a-o)
//
// Note: To enable the 'load' command define 'BONUS' before including
//       the framework!
//
// @param line  the string to parse
// @param input the data structure representing the parsed data.
//
void parseCommand(char *line, Input *input);

//-----------------------------------------------------------------------------
///
/// Transfoms a string to all lowercase characters.
///
/// @param string the string to transform
//
void stringToLower(char *string);

//-----------------------------------------------------------------------------
///
/// Parses the insert command.
///
/// @param input the data structure representing the parsed data
//
void parseInsertCommand(Input *input);

//-----------------------------------------------------------------------------
///
/// Parses the load command
///
/// @param input the data structure representing the parsed data
//
#ifdef BONUS
void parseLoadCommand(Input *input);
#endif

//-----------------------------------------------------------------------------
///
/// Parses the orientation parameter of the insert command
///
/// @param input the data structure representing the parsed data
/// @param token the string containing the raw parameter input to be parsed.
///
/// @return non-zero if parsing succeeded
//
bool parseOrientationParameter(Input *input, char *token);

// ----------------------------------------------------------------------------
void parseCommand(char *line, Input *input)
{
  memset(input, 0, sizeof(Input));

  char* token = strtok(line, TOKEN_SEPARATORS);
  stringToLower(token);
  input->only_whitespaces_ = false;
  
  if (token == NULL)
  {
    input->command_ = UNKNOWN;
    input->only_whitespaces_ = true;
  }
  else if (strcmp("insert", token) == 0)
  {
    parseInsertCommand(input);
  }
  else if (strcmp("help", token) == 0)
  {
    input->command_ = HELP;
  }
  else if (strcmp("quit", token) == 0)
  {
    input->command_ = QUIT;
  }
  else if (strcmp("save", token) == 0)
  {
    input->command_ = SAVE;
  }
#ifdef BONUS
  else if (strcmp("load", token) == 0)
  {
    parseLoadCommand(input);
  }
#endif
  else // unknown command
  {
    input->command_ = UNKNOWN;
    input->is_error_ = true;
  }
}

//-----------------------------------------------------------------------------
void stringToLower(char *string)
{
  for (size_t i = 0; string != NULL && string[i] != '\0'; ++i)
    {
      string[i] = tolower(string[i]);
    }
}

//-----------------------------------------------------------------------------
void parseInsertCommand(Input *input) {
  input->command_ = INSERT;

  // parse row parameter
  char *token = strtok(NULL, TOKEN_SEPARATORS);
  stringToLower(token);

  if (token == NULL || strlen(token) > 1)
  {
    input->is_error_ = true;
    return;
  }

  input->row_ = token[0];

  // parse column parameter
  token = strtok(NULL, TOKEN_SEPARATORS);
  stringToLower(token);

  if (token == NULL || strlen(token) > 1)
  {
    input->is_error_ = true;
    return;
  }

  input->column_ = token[0];

  // parse orientation parameter
  token = strtok(NULL, TOKEN_SEPARATORS);
  stringToLower(token);

  if (!parseOrientationParameter(input, token))
  {
    input->is_error_ = true;
    return;
  }

  // parse word parameter
  token = strtok(NULL, TOKEN_SEPARATORS);
  stringToLower(token);
  if (token == NULL)
  {
    input->is_error_ = true;
    return;
  }

  char *word = malloc(strlen(token) + 1);
  if (word == NULL)
  {
    input->is_error_ = true;
    return;
  }

  strcpy(word, token);
  input->word_ = word;
}

#ifdef BONUS
//-----------------------------------------------------------------------------
void parseLoadCommand(Input *input)
{
  input->command_ = LOAD;

  // parse parameter
  char *token = strtok(NULL, TOKEN_SEPARATORS);

  if (token == NULL)
  {
    input->is_error_ = true;
    return;
  }
  char* config_string = (char*) malloc(strlen(token) + 1);
  strcpy(config_string, token);
  input->load_config_ = config_string;
}
#endif

//-----------------------------------------------------------------------------
bool parseOrientationParameter(Input *input, char *token)
{
  if (token == NULL || strlen(token) > 1)
  {
    input->is_error_ = true;
    return false;
  }

  switch (token[0])
  {
  case 'h':
    input->orientation_ = HORIZONTAL;
    break;
  case 'v':
    input->orientation_ = VERTICAL;
    break;
  default:
    return false;
  }
  
  return true;
}
