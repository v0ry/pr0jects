OBJ_NAME = lfsr.o
IVERILOG = iverilog
IVERILOG_FLAGS = -g2012

MATR_NUM := 0

.PHONY: magic
magic: lfsr.o
	./$(OBJ_NAME)

$(OBJ_NAME): lfsr.sv testbench.sv 
	$(IVERILOG) $(IVERILOG_FLAGS) -o $@ $^

.PHONY: reference
reference:
	@python3 ./reference.py $(MATR_NUM)

.PHONY: clean
clean:
	rm $(OBJ_NAME)
