MODULE=WB_master

VSRC := ../UART/UartRx.sv \
		../UART/UartTop.sv \
		../UART/UartTx.sv \
		../UART/UartCoder.sv \
		../UART/decoder/UartDecoder.sv \
		wishbone_top.sv \



.PHONY:simIca
simIca:WaveIcarus.vcd 

.PHONY:sim
sim: waveform.vcd

.PHONY:verilate
verilate: verilateStemp
	@echo "ahoj"

.PHONY:build
build: obj_dir/V$(MODULE)


.PHONY:waves
waves: waveform.vcd	
	@echo
	@echo "### WAVES ###"
	gtkwave waveform.vcd
	
	
waveform.vcd: ./obj_dir/V$(MODULE)
	@echo 
	@echo "### SIMULATING ###"
	@./obj_dir/V$(MODULE) +verilator+rand+reset+2


./obj_dir/V$(MODULE): verilateStemp
	@echo
	@echo "### BUILDING SIM ###"
	make -C obj_dir -f V$(MODULE).mk V$(MODULE)


verilateStemp: $(MODULE).sv tb_$(MODULE).cpp
	@echo
	@echo "### VERILATING ###"
	verilator --trace --timescale 1ns/1ns --x-assign unique --x-initial unique -cc $(MODULE).sv --exe tb_$(MODULE).cpp
	@touch .stamp.verilate
	
	
.PHONY:lint
lint: $(MODULE).sv
	verilator --lint-only $(MODULE).sv
	
.PHONY: clean
clean:
	rm -rf .stamp./;
	rm -rf ./obj_dir
	rm -rf waveform.vcd
	rm -rf WaveIcarus.vcd
	rm -rf Icarus
	
	
	
WaveIcarus.vcd: Icarus/tb_$(MODULE) 
	vvp Icarus/tb_$(MODULE)
	
	
Icarus/tb_$(MODULE): Icarus tb_$(MODULE).sv $(MODULE).sv WB_slave.sv $(VSRC)
	iverilog -g2012 -o Icarus/tb_$(MODULE) tb_$(MODULE).sv $(MODULE).sv WB_slave.sv $(VSRC)
	
Icarus:
	@mkdir -p Icarus
	
	
	