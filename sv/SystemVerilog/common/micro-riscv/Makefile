MAKEFILEDIR := $(dir $(realpath $(lastword $(MAKEFILE_LIST))))
MAKEFILEDIRNAME := $(basename $(MAKEFILEDIR))

SIMDIR := $(MAKEFILEDIR)_sim/
ASMDIR := $(MAKEFILEDIR)../testcases/
ASMSOURCES := $(wildcard $(ASMDIR)*.asm)
RTLSOURCES := $(wildcard $(MAKEFILEDIR)*.sv) $(wildcard $(MAKEFILEDIR)ips/*.sv)
CPUNAME := riscv_core
CPUROOT :=
TEST_DIFFS = $(ASMSOURCES:$(ASMDIR)%.asm=$(SIMDIR)%.isa.diff) $(ASMSOURCES:$(ASMDIR)%.asm=$(SIMDIR)%.rtl.diff)

IVERILOGFLAGS ?= -Wall -g2012 -Wno-sensitivity-entire-array -I$(MAKEFILEDIR)ips
RISCVASMFLAGS ?= -e $(MAKEFILEDIR)../mul_extension.py
RISCVSIMFLAGS ?= --trace -e $(MAKEFILEDIR)../mul_extension.py
GTKWAVESAVE   ?= $(MAKEFILEDIR)$(CPUNAME).gtkw

ifeq (, $(shell which iverilog))
  IVERILOG      := iverilog-11 -g2012
else
  IVERILOG      := iverilog -g2012
endif

GTKWAVE  ?= gtkwave
RISCVASM ?= riscvasm.py
RISCVSIM ?= riscvsim.py

#help
#helpThe main targets of this Makefile are:
#help	all	generates the micro-RISCV simulator and assembles the test programs
all: $(SIMDIR)$(CPUNAME).vvp $(ASMSOURCES:$(ASMDIR)%.asm=$(SIMDIR)%.hex) $(ASMSOURCES:$(ASMDIR)%.asm=$(SIMDIR)%.words.hex)

#help	clean	clean up temporary files
.PHONY: clean
clean:
	rm -rf $(SIMDIR)

#help	help	displays this help
.PHONY: help
help:
	@cat ${MAKEFILE_LIST} | sed -n 's/^#help//p'


$(SIMDIR)%.isa.diff: $(ASMDIR)%.ref.stdout $(SIMDIR)%.isa.stdout
	diff $^ | tee $@

$(SIMDIR)%.rtl.diff: $(ASMDIR)%.ref.stdout $(SIMDIR)%.rtl.stdout
	diff $^ | tee $@

#help	test	executes all simulations and checks stdout
.PHONY: test
test: $(TEST_DIFFS)
	@\
	n=0; p=0; f=0; \
	for t in $(TEST_DIFFS); do \
		n=$$((n + 1)); \
		echo -n ">> `basename $${t%.diff}`"; \
		if [ ! -s $$t ]; then \
			p=$$((p + 1)); \
			echo " [PASS]"; \
		else \
			f=$$((f + 1)); \
			echo " [FAIL]"; \
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
	$(RISCVASM) $(RISCVASMFLAGS) -o $@ $^

.PRECIOUS: $(SIMDIR)%.words.hex
$(SIMDIR)%.words.hex: $(ASMDIR)%.asm
	@mkdir -p $(SIMDIR)
	$(RISCVASM) $(RISCVASMFLAGS) -f words -o $@ $^

###############################################################################
# ISA SIMULATION
###############################################################################
SIM_LOG_ARGS = > $(SIMDIR)$*.isa.log
.PRECIOUS: $(SIMDIR)%.isa.stdout $(SIMDIR)%.isa.log
$(SIMDIR)%.isa.stdout $(SIMDIR)%.isa.log: $(SIMDIR)%.words.hex $(wildcard $(ASMDIR)*.stdin)
	cp $(ASMDIR)$*.stdin $(SIMDIR)stdin.txt || touch $(SIMDIR)stdin.txt
	$(RISCVSIM) $< $(RISCVSIMFLAGS) --stdin $(SIMDIR)stdin.txt --stdout $(SIMDIR)$*.isa.stdout $(SIM_LOG_ARGS)

###############################################################################
# RTL SIMULATION
###############################################################################
ifeq (${CPUROOT},)
$(SIMDIR)$(CPUNAME).vvp: $(RTLSOURCES)
	@mkdir -p $(SIMDIR)
	$(IVERILOG) $(IVERILOGFLAGS) -o $@ -s testbench $^
else
$(SIMDIR)$(CPUNAME).vvp:
	cd $(CPUROOT) && $(MAKE) $(SIMDIR)$(CPUNAME).vvp
	@mkdir -p $(SIMDIR)
	cp $(CPUROOT)$(SIMDIR)$(CPUNAME).vvp $(SIMDIR)
endif

LOG_ARGS = > $*.rtl.log
.PRECIOUS: $(SIMDIR)%.vcd $(SIMDIR)%.rtl.stdout $(SIMDIR)%.rtl.log
$(SIMDIR)%.vcd $(SIMDIR)%.rtl.stdout $(SIMDIR)%.rtl.log: $(SIMDIR)%.hex $(SIMDIR)$(CPUNAME).vvp $(wildcard $(ASMDIR)*.stdin)
	cp $(ASMDIR)$*.stdin $(SIMDIR)stdin.txt || touch $(SIMDIR)stdin.txt
	cd $(SIMDIR) && ./$(CPUNAME).vvp +PROGRAM=$*.hex $(LOG_ARGS)
	mv $(SIMDIR)$(CPUNAME).vcd $(SIMDIR)$*.vcd
	mv $(SIMDIR)stdout.txt $(SIMDIR)$*.rtl.stdout

###############################################################################
# INTERACTIVE TARGETS
###############################################################################
#help
#help	sim TARGET=<target_name>	runs the ISA simulation of the target
.PHONY: sim run view
sim:
ifeq (${TARGET},)
	@echo "ERROR: No TARGET has been specified!"
	@echo "Usage: make $@ TARGET=<target_name>"
	@exit 1
endif # TARGET is empty
	rm -f $(SIMDIR)${TARGET}.isa.log
	@$(MAKE) --no-print-directory $(SIMDIR)${TARGET}.isa.log TARGET=$(TARGET) SIM_LOG_ARGS="| tee \$$(SIMDIR)\$$*.isa.log"

#help	run TARGET=<target_name>	runs the verilog simulation of the target
run:
ifeq (${TARGET},)
	@echo "ERROR: No TARGET has been specified!"
	@echo "Usage: make $@ TARGET=<target_name>"
	@exit 1
endif # TARGET is empty
	rm -f $(SIMDIR)${TARGET}.rtl.log
	@$(MAKE) --no-print-directory $(SIMDIR)${TARGET}.rtl.log TARGET=$(TARGET) LOG_ARGS="| tee \$$*.rtl.log"

#help	view TARGET=<target_name>	views the waveforms from the verilog simulation of the target
view:
ifeq (${TARGET},)
	@echo "ERROR: No TARGET has been specified!"
	@echo "Usage: make $@ TARGET=<target_name>"
	@exit 1
endif # TARGET is empty
	@$(MAKE) --no-print-directory $(SIMDIR)${TARGET}.vcd TARGET=$(TARGET)
	$(GTKWAVE) --save $(CPUROOT)$(CPUNAME).gtkw $(SIMDIR)$(TARGET).vcd
