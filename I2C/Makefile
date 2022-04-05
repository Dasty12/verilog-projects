MODULE = I2C


VSRC :=     I2C.sv \
			tb_I2C.sv \
		
		
		
	
.PHONY:simIca
simIca:WaveIcarus.vcd 



clean:
	rm -rf .stamp./;
	rm -rf ./obj_dir
	rm -rf waveform.vcd
	rm -rf WaveIcarus.vcd
	rm -rf Icarus
	
	
	
WaveIcarus.vcd: Icarus/tb_$(MODULE) 
	vvp Icarus/tb_$(MODULE)
	
	
Icarus/tb_$(MODULE): Icarus I2C.sv tb_I2C.sv 
	iverilog -g2012 -o Icarus/tb_$(MODULE) I2C.sv tb_I2C.sv 
	
Icarus:
	@mkdir -p Icarus
	
	
	