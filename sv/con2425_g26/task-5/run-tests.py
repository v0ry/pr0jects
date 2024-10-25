#!/usr/bin/env python3

import subprocess, unicodedata, re, signal
from sys import exit, stdout as sys_stdout
from glob import glob

print('Waiting for g++ build (timeout 30s)...', end='')
sys_stdout.flush()
try:
    gcc = subprocess.run(
        ['g++','-std=c++20','-g','-Wall','-Wextra','-Werror','-O0'] + glob('__test/staging/*.cpp') + glob('__test/staging/framework/*.cpp') + ['__test/staging/framework/test-parser.a'] + ['-o','quib_test'],
        stdout=subprocess.PIPE, stderr=subprocess.STDOUT, text=True,
        timeout=30
    )
    if gcc.returncode == 0:
        print('OK.')
    else:
        print('failed.\n')
        print(gcc.stdout)
        print('\n== FAILURE: gcc exited with nonzero code (%d) ==' % gcc.returncode)
        exit(0)
except subprocess.TimeoutExpired as e:
    print('timed out.\n')
    print(e.stdout)
    print('\n== FAILURE: Timeout (30s) hit while waiting for g++ build ==')
    exit(0)

print('Now starting test run.', end='\n\n')

# TEST FRAMEWORK STARTS HERE 

class _TestFailedException(Exception):
    def __init__(self, text):
        self.text = text
    def __str__(self):
        return self.text

class _TestSkippedException(Exception):
    pass

_LongestSectionName = 0
_Tests = []
_CurrentSection = None

def SECTION_START(name):
    global _CurrentSection, _LongestSectionName
    _CurrentSection = []
    _Tests.append((name, _CurrentSection))
    _LongestSectionName = max(_LongestSectionName, len(name))

def Test(name,key):
    _CurrentSection.append((name,key))

def writeOutput(testName, testKey, stdout, stderr, withAlert):
    if stdout is None: stdout = ''
    elif type(stdout) is bytes: stdout = stdout.decode()
    if stderr is None: stderr = ''
    elif type(stderr) is bytes: stderr = stderr.decode()
    filename = unicodedata.normalize('NFKD',str(testName)).encode('ascii','ignore').decode('ascii')
    filename = re.sub(r'[^\w\s-]', '', filename.lower())
    filename = re.sub(r'[-\s]+', '-', filename).strip('-_')
    filename = f'test_output/{filename}.txt'
    with open(filename, 'w') as of:
        of.write('== STANDARD OUTPUT ==\n')
        of.write(stdout)
        of.write('\n\n== STANDARD ERROR ==\n')
        of.write(stderr)
        of.write('\n')
    
    if withAlert:
        print(f"(!!>) Full output for '{testName}' written to '{filename}'.")
        print(f"(!!>) To re-run just this test, use:\n(!!!>) make clean && make quib && valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --show-error-list=yes ./quib {testKey}")
        print("\n")

# END OF TEST FRAMEWORK, ACTUAL TESTS BELOW
# TESTS CORRESPOND TO LOGIC IN test.cpp

SECTION_START('Basics')
Test('You are opening/closing a UDP socket', 'udp_socket')
Test('Connections can be opened and discarded', 'open_close')
Test('The initial packet and its reply might include data', 'initial_data')

SECTION_START('Packet Loss & Connection Timeout')
Test('A connection should never time out by itself (are you sending PINGs to elicit ACKs?)', 'timeout_keepalive')
Test('The initial packet is retried, and the connection can time out', 'initial_nack')
Test('You do not send lone ACKs for non-ack-eliciting packets', 'ack_eliciting')
Test('You are abiding by flow control limits', 'flow_control_outgoing')
Test('You are advertising increasing flow control limits yourself', 'flow_control_incoming')
Test('An intermediate chunk doesn\'t get ack\'d and should be resent', 'intermediate_chunk_nack')
Test('The final chunk doesn\'t get ack\'d and should be resent', 'final_chunk_nack')
Test('There is no head-of-line blocking between different streams', 'no_head_of_line_blocking')

SECTION_START('Trying To Get You To Misbehave')
Test('You are not exceeding the maximum packet size', 'packet_size_bait')
Test('You are not exceeding the packet size even when multiple streams are involved', 'packet_size_bait_multiple')
Test('You are correctly re-ordering data', 'unordered_receipt')
Test('We can read data in smaller chunks than what was sent', 'undersized_reads')
Test('We can read data in larger chunks than what was sent', 'oversized_reads')
Test('You correctly indicate end-of-stream even if no new data was added (sending)', 'eos_no_data_send')
Test('You correctly indicate end-of-stream even if no new data was added (receiving)', 'eos_no_data_recv')
Test('You correctly encode complex ACK sequences', 'complex_ack')
Test('Discarding various nullptr-s is a no-op', 'discard_null');

SECTION_START('Mutiplexing')
Test('Multiple parallel connections can coexist (incoming)', 'multiple_connections_incoming')
Test('Multiple parallel connections can coexist (outgoing)', 'multiple_connections_outgoing')
Test('Streams can send and receive data concurrently', 'stream_interleaving')

SECTION_START('Connection/Stream Termination')
Test('You correctly (re-)send data even after the connection has been discarded', 'discard_before_finalize')
Test('You do not send data after an incomplete stream has been discarded', 'reset_stream_incomplete')
Test('You no longer re-send lost data after an incomplete stream has been discarded', 'reset_stream_incomplete_2')
Test('You keep re-sending lost data after a complete stream has been discarded', 'reset_stream_complete')
Test('You no longer re-send lost data after receiving STOP_SENDING for a stream', 'stop_sending_outgoing')
Test('You produce STOP_SENDING when the application discards an in-progress stream', 'stop_sending_incoming')
Test('You re-send STOP_SENDING if it is not acknowledged', 'stop_sending_incoming_2')
Test('Attempts to read from a stream after it has been reset should fail', 'reset_stream_incoming')

SECTION_START('Misbehaving Server')
Test('Final size violation: high then low', 'final_size_violation_down')
Test('Final size violation: low then high', 'final_size_violation_up')
Test('Invalid packet: empty payload', 'empty_payload')
Test('Invalid initial packet: not flagged as initial', 'no_initial_reply')
Test('Stream state error: attempt to initiate a client-initiated stream id', 'stream_state_error')
Test('Invalid packet: unknown frame type', 'unknown_frame_type')

SECTION_START('Misbehaving Application')
Test('Attempt to send to a unidirectional read-only stream', 'send_to_readonly')
Test('Attempt to read from an unidirectional write-only stream', 'recv_from_writeonly')

# END OF TEST DEFINITIONS

_TestResults = []

def printValgrind(stderr):
    p = False
    for line in stderr.splitlines():
        if not line[:2] == '==':
            continue
        if not p:
            if '== HEAP SUMMARY:' in line:
                p = True
        if p:
            print(line)

for (sectionName, testData) in _Tests:
    print('== %s ==' % sectionName)
    numStr = str(len(testData))
    fmtStr = ('[%%%dd/%s] "%%s"... ' % (len(numStr), numStr))
    
    nPass = 0
    nFail = 0
    nSkip = 0
    
    for (idx, (testName, testKey)) in enumerate(testData, 1):
        print(fmtStr % (idx, testName), end='')
        sys_stdout.flush()
        
        try:
            proc = subprocess.run(
                ['valgrind','--leak-check=full','--show-leak-kinds=all','--track-origins=yes','--show-error-list=yes','--error-exitcode=42','./quib_test',testKey],
                stdout=subprocess.PIPE, stderr=subprocess.PIPE, text=True,
                timeout=5
            )
            if proc.returncode == 0:
                print('OK.')
                nPass += 1
                writeOutput(testName, testKey, proc.stdout, proc.stderr, False)
            elif proc.returncode == 1:
                print('SKIP.')
                nSkip += 1
            else:
                print('\x1b[2K\r\n(!!) ', end='')
                if (proc.returncode < 0):
                    try:
                        whichSignal = signal.Signals(-proc.returncode).name
                    except ValueError:
                        whichSignal = f'unknown signal (program exited with {proc.returncode})'
                    print(fmtStr % (idx, testName), end=f'FAIL (terminated with {whichSignal}).\n')
                    printValgrind(proc.stderr)
                elif (proc.returncode == 42):
                    print(fmtStr % (idx, testName), end='LEAKS.\n')
                    printValgrind(proc.stderr)
                else:
                    print(fmtStr % (idx, testName), end='FAIL.\n')
                    for line in proc.stderr.splitlines():
                        if line[:2] == '==':
                            continue
                        print(line)
                nFail += 1
                writeOutput(testName, testKey, proc.stdout, proc.stderr, True)
        except subprocess.TimeoutExpired as e:
            print('\x1b[2K\r\n(!!) ', end='')
            print(fmtStr % (idx, testName), end='TIMEOUT (5 sec).\n')
            print(str(e), end='\n')
            printValgrind(e.stderr.decode())
            nFail += 1
            writeOutput(testName, testKey, e.stdout, e.stderr, True)
    
    _TestResults.append((sectionName, (nPass, nFail, nSkip)))
    print('')

print('\n== Test summary: ==')
for (sectionName, (nPass, nFail, nSkip)) in _TestResults:
    print('%s: %2d passed, %2d failed, %2d skipped' % (sectionName.ljust(_LongestSectionName), nPass, nFail, nSkip))
