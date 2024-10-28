MAKEFILEDIR ?= $(dir $(realpath $(lastword $(MAKEFILE_LIST))))

RTLSOURCES ?= $(wildcard $(MAKEFILEDIR)/tb/*.sv) $(wildcard $(MAKEFILEDIR)/src/*.sv)
LINTSOURCES ?= $(wildcard $(MAKEFILEDIR)/src/*.sv)
RTLNAME ?= calculator
TESTDIR ?= $(abspath ../task-1/test)/
TESTS ?= $(wildcard $(TESTDIR)*.testvec)

SIMDIRNAME ?= _sim/
SYNTHDIRNAME ?= _synth/
# SIMDIR ?= /Users/koka/GitHUB/sv/con2425_g26/task-1/_sim/
SIMDIR ?= $(MAKEFILEDIR)$(SIMDIRNAME)
SYNTHDIR ?= $(MAKEFILEDIR)$(SYNTHDIRNAME)

IVERILOGFLAGS ?= -Wall -g2012 -Wno-sensitivity-entire-array
IVERILOG ?= iverilog
VERILATOR ?= verilator
GTKWAVE  ?= gtkwave
YOSYS ?= yosys

#help
#helpThe main targets of this Makefile are:
#help	all	generates the verilog simulator
all: $(SIMDIR)$(RTLNAME).vvp

#help	clean	clean up temporary files
.PHONY: clean
clean:
	rm -rf $(SIMDIR)
	rm -rf $(SYNTHDIR)

#help	help	displays this help
.PHONY: help
help:
	@cat ${MAKEFILE_LIST} | sed -n 's/^#help//p'

#help	test	executes all simulations and checks stdout
.PHONY: test
test: $(TESTS:$(TESTDIR)%.testvec=$(SIMDIR)%.diff)
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
			echo " [FAIL]"; \
		fi; \
	done; \
	echo "Total:  $$n"; \
	echo "Passed: $$p"; \
	echo "Failed: $$f"; \
	exit $$f

$(SIMDIR)$(RTLNAME).vvp: $(RTLSOURCES)
	@mkdir -p $(SIMDIR)
	$(IVERILOG) $(IVERILOGFLAGS) $(RTLSOURCES) -o $@

LOG_ARGS = > $*.rtl.log
$(SIMDIR)%.out $(SIMDIR)%.vcd $(SIMDIR)%.rtl.log: $(TESTDIR)%.testvec $(SIMDIR)$(RTLNAME).vvp
	cp $< $(SIMDIR)input.txt
	cd $(SIMDIR) && ./$(RTLNAME).vvp  $(LOG_ARGS)
	cp $(SIMDIR)output.txt $(SIMDIR)$*.out
	cp $(SIMDIR)$(RTLNAME).vcd $(SIMDIR)$*.vcd

$(SIMDIR)%.diff: $(SIMDIR)%.out $(TESTDIR)%.testvec.out
	diff $^ | tee $@

###############################################################################
# INTERACTIVE TARGETS
###############################################################################
#help
#help	run TARGET=<target_name>	runs the verilog simulation of the target
run:
ifeq (${TARGET},)
	@echo "ERROR: No TARGET has been specified!"
	@echo "Usage: make $@ TARGET=<target_name>"
	@exit 1
endif # TARGET is empty
	rm -f $(SIMDIR)${TARGET}.rtl.log
	@$(MAKE) -f $(MAKEFILEDIR)Makefile --no-print-directory $(SIMDIR)${TARGET}.rtl.log TARGET=$(TARGET) LOG_ARGS="| tee \$$*.rtl.log"

#help	view TARGET=<target_name>	views the waveforms from the verilog simulation of the target
view:
ifeq (${TARGET},)
	@echo "ERROR: No TARGET has been specified!"
	@echo "Usage: make $@ TARGET=<target_name>"
	@exit 1
endif # TARGET is empty
	@$(MAKE) -f $(MAKEFILEDIR)Makefile --no-print-directory $(SIMDIR)${TARGET}.vcd TARGET=$(TARGET)
	$(GTKWAVE) --save $(MAKEFILEDIR)$(RTLNAME).gtkw $(SIMDIR)$(TARGET).vcd

#help	lint	uses verilator to show you syntax/design flaws
lint:
	$(VERILATOR) --lint-only $(LINTSOURCES)

#help 	synth    			synthesizes the design with yosys
synth:
	@mkdir -p $(SYNTHDIR)
	sv2v --incdir src -E logic src/*.sv -w $(SYNTHDIR)/calculator.v
	$(YOSYS) -T synth.ys
