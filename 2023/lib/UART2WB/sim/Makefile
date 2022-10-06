MODULE = top_Uart2wb

PROJ_FILES += -I../rtl
#CPP_FILES = ../../UART/SW/UartRxDrv.cpp \
#	        ../../UART/SW/UartRxMon.cpp

DEFINE = OPT_SIM

.PHONY:sim
sim:waveform.vcd

.PHONY:verilate
verilate: .stamp.verilate

.PHONY:build
buidl: obj_dir/V$(MODULE)

.PHONY:waves
waves: waveform.vcd
	@echo
	@echo "### WAVES ###"
	gtkwave waveform.vcd

waveform.vcd: ./obj_dir/V$(MODULE)
	@echo 
	@echo "### BUILDING SIM ###"
	@./obj_dir/V$(MODULE) + verilator+rand+reset+2

./obj_dir/V$(MODULE): .stamp.verilate
	@echo
	@echo "### BUILDING SIM ###"
	make -C obj_dir -f V$(MODULE).mk V$(MODULE)
	
.stamp.verilate: $(MODULE).sv tb_$(MODULE).cpp $(CPP_FILES)
	@echo
	@echo "### VERILATING ###"
	verilator -I.. $(PROJ_FILES) -Wall   -D$(DEFINE) --trace --x-assign unique --x-initial unique -cc $(MODULE).sv --exe tb_$(MODULE).cpp $(CPP_FILES)
	@touch .stamp.verilate

.PHONY:lint
lint: $(MODULE).sv
	verilator -I.. $(PROJ_FILES) -D$(DEFINE) --lint-only $(MODULE).sv

.PHONY: clean
clean:
	rm -rf .stamp.*;
	rm -rf ./obj_dir
	rm -rf waveform.vcd
