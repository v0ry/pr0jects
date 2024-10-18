MAKEFILEDIR ?= $(dir $(realpath $(lastword $(MAKEFILE_LIST))))
MICRORISCVDIR ?= ../common/micro-riscv/

SIMDIR ?= _sim/
ASMDIR ?= 
ASMSOURCES ?= $(wildcard $(ASMDIR)*.asm)
RTLSOURCES ?= $(MICRORISCVDIR)ips/cpu_package.sv $(wildcard $(MICRORISCVDIR)*.sv) $(wildcard $(MICRORISCVDIR)ips/*.sv)
CPUNAME ?= riscv_core
CPUROOT ?=
TEST_DIFFS ?= $(ASMSOURCES:$(ASMDIR)%.asm=$(SIMDIR)%.isa.diff) $(ASMSOURCES:$(ASMDIR)%.asm=$(SIMDIR)%.rtl.diff)

IVERILOGFLAGS ?= -Wall -I$(MICRORISCVDIR) -I$(MICRORISCVDIR)ips -g2012 -Wno-sensitivity-entire-array
GTKWAVESAVE   ?= $(MICRORISCVDIR)/$(CPUNAME).gtkw
RISCVASMFLAGS ?=
RISCVSIMFLAGS ?= --trace

ifeq (, $(shell which iverilog))
  IVERILOG      := iverilog-11
else
  IVERILOG      := iverilog
endif

GTKWAVE  ?= gtkwave
RISCVASM ?= riscvasm.py
RISCVSIM ?= riscvsim.py

# if there is only one file in the current directory,
# use it as target per default
ifeq ($(words $(wildcard *.asm)), 1)
  TARGET ?= $(basename $(wildcard *.asm))
endif


#help
#helpThe main targets of this Makefile are:
#help	all	generates the verilog simulator and assembles the test programs
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
	$(IVERILOG) $(IVERILOGFLAGS) -o $@ -s testbed $^
else
$(SIMDIR)$(CPUNAME).vvp:
	cd $(CPUROOT) && $(MAKE) $(CPUROOT)$(SIMDIR)$(CPUNAME).vvp
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
	echo @$(MAKE) -f $(MAKEFILEDIR)Makefile-riscv.mk --no-print-directory $(SIMDIR)${TARGET}.isa.log TARGET=$(TARGET) SIM_LOG_ARGS="| tee \$$(SIMDIR)\$$*.isa.log"
	@$(MAKE) -f $(MAKEFILEDIR)Makefile-riscv.mk --no-print-directory $(SIMDIR)${TARGET}.isa.log TARGET=$(TARGET) SIM_LOG_ARGS="| tee \$$(SIMDIR)\$$*.isa.log"

#help	run TARGET=<target_name>	runs the verilog simulation of the target
run:
ifeq (${TARGET},)
	@echo "ERROR: No TARGET has been specified!"
	@echo "Usage: make $@ TARGET=<target_name>"
	@exit 1
endif # TARGET is empty
	rm -f $(SIMDIR)${TARGET}.rtl.log
	@$(MAKE) -f $(MAKEFILEDIR)Makefile-riscv.mk --no-print-directory $(SIMDIR)${TARGET}.rtl.log TARGET=$(TARGET) LOG_ARGS="| tee \$$*.rtl.log"

#help	view TARGET=<target_name>	views the waveforms from the verilog simulation of the target
view:
ifeq (${TARGET},)
	@echo "ERROR: No TARGET has been specified!"
	@echo "Usage: make $@ TARGET=<target_name>"
	@exit 1
endif # TARGET is empty
	@$(MAKE) -f $(MAKEFILEDIR)Makefile-riscv.mk --no-print-directory $(SIMDIR)$(TARGET).vcd TARGET=$(TARGET)
	$(GTKWAVE) --save $(GTKWAVESAVE) $(SIMDIR)$(TARGET).vcd
