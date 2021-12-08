module tb;
    
reg clk = 0;


top DUT(.clk(clk));




initial begin
    $dumpfile("WAVES.vcd");
    $dumpvars;

end

always #5 clk = !clk;

initial begin
    #5000000 $finish;
end




endmodule