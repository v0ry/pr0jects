# Ensure that there are no spaces in path to avoid any undesired behavior
ifneq ($(word 2,$(realpath $(lastword $(MAKEFILE_LIST)))),)
$(error "ERROR: folder path contains spaces")
endif

# To be set in user Makefile
MAKEFILEDIR ?= $(dir $(realpath $(lastword $(MAKEFILE_LIST))))

# Absolute paths to the different source folders.
ASMDIR ?= $(MAKEFILEDIR)
CDIR ?= $(MAKEFILEDIR)
SIMDIR ?= $(MAKEFILEDIR)_sim/
TESTDIR ?= $(abspath $(MAKEFILEDIR)test)/

# Extensions for the individual file types.
ASMEXT ?= .asm
TESTEXT ?= .testvec
TESTRESEXT ?= .testvec.out

# Globbed source/input files with absolute paths.
ASMSOURCES ?= $(wildcard $(ASMDIR)*$(ASMEXT))
CSOURCES ?= $(wildcard $(CDIR)*.c)
TESTINPUTS ?= $(wildcard $(TESTDIR)*$(TESTEXT))

# Basenames for the found programs and tests inputs.
PROGRAMS ?= $(ASMSOURCES:$(ASMDIR)%$(ASMEXT)=%)
CPROGRAMS ?= $(CSOURCES:$(CDIR)%.c=%)
TESTS ?= $(TESTINPUTS:$(TESTDIR)%$(TESTEXT)=%)

RISCVASMFLAGS ?= -e m_extension.py
RISCVSIMFLAGS ?= -e m_extension.py --trace
CFLAGS        ?= -Wall -Wextra
LDFLAGS       ?=

CC       ?= gcc
RISCVASM ?= riscvasm.py
RISCVSIM ?= riscvsim.py

ASMLIB_VERSION = $(shell $(RISCVSIM) --version)
ifeq "$(ASMLIB_VERSION)" "2.1.1"
    RISCVSIMFLAGS += --abi
endif
ifeq "$(ASMLIB_VERSION)" "2.1.0"
    RISCVSIMFLAGS += --abi
endif

ifeq (${VERBOSE},)
REDIRECT := >
SILENCE := @
else
REDIRECT := | tee
SILENCE :=
endif

#help
#helpThe main targets of this Makefile are:
#help	all	Builds the test programs.
all: $(PROGRAMS:%=$(SIMDIR)%.hex) $(CPROGRAMS:%=$(SIMDIR)%.elf)

#help	info	Displays build system internal information.
info:
	@echo "ASMDIR: $(ASMDIR)"
	@echo "CDIR: $(CDIR)"
	@echo "SIMDIR: $(SIMDIR)"
	@echo "RTLDIR: $(RTLDIR)"
	@echo "TESTDIR: $(TESTDIR)"

	@echo "CPROGRAMS: $(CPROGRAMS)"
	@echo "PROGRAMS: $(PROGRAMS)"
	@echo "TESTS: $(TESTS)"

#help	clean	Cleanup temporary files.
.PHONY: clean
clean:
	rm -rf "$(SIMDIR)"

#help	help	Displays this help.
.PHONY: help
help:
	@cat ${MAKEFILE_LIST} | sed -n 's/^#help//p'

#help	test	Executes all simulations and checks stdout.
.PHONY: test
test: $(foreach _test, $(TESTS), $(foreach _program, $(CPROGRAMS), $(SIMDIR)$(_program)-$(_test).c.diff) $(foreach _program, $(PROGRAMS), $(SIMDIR)$(_program)-$(_test).isa.diff))
	@\
	n=0; p=0; f=0; \
	for t in $^; do \
		n=$$((n + 1)); \
		echo -n ">> `basename $${t%.diff}`"; \
		if [ ! -s $$t ]; then \
			p=$$((p + 1)); \
			echo " [PASS]"; \
		else \
			f=$$((f + 1)); \
			echo " [!!! FAIL !!!]"; \
		fi; \
	done; \
	echo "Total:  $$n"; \
	echo "Passed: $$p"; \
	echo "Failed: $$f"; \
	exit $$f

###############################################################################
# COMPILATION
###############################################################################
.PRECIOUS: $(SIMDIR)%.hex
$(SIMDIR)%.hex: $(ASMDIR)%.asm
	@mkdir -p $(SIMDIR)
	@echo "# Assembling \"$*\" program"
	$(SILENCE)$(RISCVASM) $(RISCVASMFLAGS) -o $@ $^

.PRECIOUS: $(SIMDIR)%.elf
$(SIMDIR)%.elf: $(ASMDIR)%.c
	@mkdir -p $(SIMDIR)
	@echo "# Compiling \"$*\" program"
	$(SILENCE)$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)

###############################################################################
# ISA SIMULATION
###############################################################################

# Generates a rule for simulating a specific program with wildcard test names.
# Arguments: program_basename
define PROGRAM_isa_sim_template =
.PHONY: sim.$(1)-%
.PRECIOUS: $(SIMDIR)$(1)-%.isa.stdout $(SIMDIR)$(1)-%.isa.log $(SIMDIR)$(1)-%.isa.diff
sim.$(1)-% $(SIMDIR)$(1)-%.isa.stdout $(SIMDIR)$(1)-%.isa.log $(SIMDIR)$(1)-%.isa.diff: $(SIMDIR)$(1).hex $(TESTDIR)%$(TESTEXT)
	@echo "# Performing ISA simulation for program \"$(1)\" and test \"$$*\""
	@test -f "$(TESTDIR)$$*$(TESTEXT)" && cp "$(TESTDIR)$$*$(TESTEXT)" "$(SIMDIR)stdin.txt" || touch "$(SIMDIR)stdin.txt"
	$(SILENCE)$(RISCVSIM) $(RISCVSIMFLAGS) --stdin "$(SIMDIR)stdin.txt" --stdout "$(SIMDIR)$(1)-$$*.isa.stdout" "$(SIMDIR)$(1).hex" $(REDIRECT) "$(SIMDIR)$(1)-$$*.isa.log" || true
	$(SILENCE)touch "$(SIMDIR)$(1)-$$*.isa.stdout"
	$(SILENCE)diff "$(TESTDIR)$$*$(TESTRESEXT)" "$(SIMDIR)$(1)-$$*.isa.stdout" | tee "$(SIMDIR)$(1)-$$*.isa.diff"
	$(SILENCE)test ! -s "$(SIMDIR)$(1)-$$*.isa.diff" || echo "ERROR! Test output mismatch detected!"
endef

$(foreach _program, $(PROGRAMS),\
    $(eval $(call PROGRAM_isa_sim_template,$(_program))))

define PROGRAM_c_sim_template =
.PHONY: c.$(1)-%
.PRECIOUS: $(SIMDIR)$(1)-%.c.stdout $(SIMDIR)$(1)-%.c.diff
c.$(1)-% $(SIMDIR)$(1)-%.c.stdout $(SIMDIR)$(1)-%.c.diff: $(SIMDIR)$(1).elf $(TESTDIR)%$(TESTEXT)
	@echo "# Performing C simulation for program \"$(1)\" and test \"$$*\""
	$(SILENCE)$(SIMDIR)$(1).elf < "$(TESTDIR)$$*$(TESTEXT)" > "$(SIMDIR)$(1)-$$*.c.stdout" || true
	$(SILENCE)touch "$(SIMDIR)$(1)-$$*.c.stdout"
	$(SILENCE)diff "$(TESTDIR)$$*$(TESTRESEXT)" "$(SIMDIR)$(1)-$$*.c.stdout" | tee "$(SIMDIR)$(1)-$$*.c.diff"
	$(SILENCE)test ! -s "$(SIMDIR)$(1)-$$*.c.diff" || echo "ERROR! Test output mismatch detected!"
endef

$(foreach _program, $(CPROGRAMS),\
    $(eval $(call PROGRAM_c_sim_template,$(_program))))

#help
#help Special variables that can be defined: (e.g., make test VERBOSE=1)
#help   VERBOSE=1	Makes program execution more verbose and prints commands.
#help   CROGRAMS=...	Restricts the supported C programs. (e.g., for test)
#help   PROGRAMS=...	Restricts the supported ASM programs. (e.g., for test)
#help   TESTS=...	Restricts the used stdin files. (e.g., for test)
