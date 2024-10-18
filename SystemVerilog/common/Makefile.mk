ifeq (, $(shell which iverilog))
  IVERILOG      := iverilog-11
else
  IVERILOG      := iverilog
endif

SV2V          := sv2v
YOSYS         := yosys
GTKWAVE       := gtkwave

IVLFLAGS      := -g2012 -Wall -Wno-sensitivity-entire-array
SV2VFLAGS     :=
SYNTHTEMPLATE := synth.ys.in
SYNTHSCRIPT   := synth.ys

LIBPATH       := ../common
LIBSOURCE     := $(LIBPATH)/cmos_cells.v
LIBFILE       := $(LIBPATH)/cmos_cells.lib

TESTSOURCES   := testbench.sv
SYNTHSOURCE   := syn.v
NONSYNTH_SRC  := $(LIBSOURCE) $(SYNTHSOURCE) $(TESTSOURCES)

ifeq (, $(filter-out $(NONSYNTH_SRC),$(wildcard *.sv)))

SYNTH_SRC_V   := $(filter-out $(NONSYNTH_SRC),$(wildcard *.v))
BASE          := $(basename $(firstword $(strip $(SYNTH_SRC_V))))

.PHONY: rm-generated-v
rm-generated-v:

else

SYNTH_SRC_SV  := $(filter-out $(NONSYNTH_SRC),$(wildcard *.sv))
SYNTH_SRC_V   := $(SYNTH_SRC_SV:.sv=.v)
BASE          := $(basename $(firstword $(strip $(SYNTH_SRC_V))))

$(SYNTH_SRC_V): $(SYNTH_SRC_SV)
	$(SV2V) $(SV2VFLAGS) $(SYNTH_SRC_SV) -w $(SYNTH_SRC_V)

.PHONY: rm-generated-v
rm-generated-v:
	rm -f $(SYNTH_SRC_V)

endif

all: build build-syn

build: $(BASE).sim.vvp

syn: $(SYNTHSOURCE)

build-syn: $(BASE).syn.vvp

$(BASE).sim.vvp: $(SYNTH_SRC_V) $(TESTSOURCES)
	$(IVERILOG) $(IVLFLAGS) -o $@ $^

$(BASE).syn.vvp: $(SYNTHSOURCE) $(LIBSOURCE) $(TESTSOURCES)
	$(IVERILOG) $(IVLFLAGS) -o $@ $^

$(SYNTHSCRIPT): $(SYNTHTEMPLATE)
	cat $^ \
		| sed 's|@LIBSOURCE@|$(LIBSOURCE)|g' \
		| sed 's|@LIBFILE@|$(LIBFILE)|g' \
		| sed 's|@SYNTHSOURCE@|$(SYNTHSOURCE)|g' \
	> $@

$(SYNTHSOURCE): $(SYNTHSCRIPT) $(SYNTH_SRC_V)
	$(YOSYS) -o $@ -s $^

.PHONY: show
show: $(SYNTHSCRIPT) $(SYNTH_SRC_V)
	$(YOSYS) -b verilog -o $@ -s $^ -p show

.PHONY: view
view:
	$(GTKWAVE) $(BASE).vcd

.PHONY: run
run: build
	./$(BASE).sim.vvp

.PHONY: run-syn
run-syn: build-syn
	./$(BASE).syn.vvp

.PHONY: clean
clean: rm-generated-v
	rm -f $(BASE).sim.vvp $(BASE).syn.vvp $(SYNTHSCRIPT) $(SYNTHSOURCE) $(BASE).vcd show
