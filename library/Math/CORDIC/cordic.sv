module cordic #(
    localparam IW = 13,
               OW = 13,
               NSTAGES=16,
               WW = 16,      // Our working bit-width
               PW = 20       // Bits in our phase variables   
)
(
    input i_clk,
    input i_rst,

    input  [IW-1:0] i_xval,
    input  [IW-1:0] i_yval,
    input  [PW-1:0] i_phase,
    output [OW-1:0] o_xval,
    output [OW-1:0] o_yval
    
);
    



reg [WW-1:0] xv [0:NSTAGES];
reg [WW-1:0] yv [0:NSTAGES];
reg [PW-1:0] ph [0:NSTAGES];

wire [WW-1:0] e_xval;
wire [WW-1:0] e_yval;

// rozsireni nasich vstupnich vstupnich signalu, na pracovni rozsah.
// rozsiri se o jeden(nebo) vic bitu v pravo
// rozsiri se o jeden bit vlevo, kvuli "accumulation cordic gain"
assign e_xval = { {i_xval[IW-1]}, i_xval, {(WW-IW-1){1'b0}} };
assign e_yval = { {i_yval[IW-1]}, i_yval, {(WW-IW-1){1'b0}} };



always @(posedge i_clk) begin
    case(i_phase[PW-1:PW-3])
        3'b000: begin //0..45 
            xv[0] <= e_xval;
            yv[0] <= e_yval;
            ph[0] <= i_phase;
        end
        3'b001: begin //45..90
            xv[0] <= -e_yval;
            yv[0] <= e_xval;
            ph[0] <= i_phase - 20'h40000;   
        end
        3'b010: begin //90..135
            xv[0] <= -e_yval;
            yv[0] <= e_xval;
            ph[0] <= i_phase -20'h40000;
        end
        3'b011:begin //135..180
            xv[0] <= -e_xval;
            yv[0] <= -e_yval;
            ph[0] <= i_phase - 20'h80000;
        end
        3'b100:begin //180..225
            xv[0] <= -e_xval;
            yv[0] <= -e_yval;
            ph[0] <= i_phase - 20'h80000;
        end
        3'b101:begin //225..270
            xv[0] <= e_yval;
            yv[0] <= -e_xval;
            ph[0] <= i_phase - 20'hc00000;
        end
        3'b110:begin //270..315
            xv[0] <= e_yval;
            yv[0] <= -e_xval;
            ph[0] <= i_phase - 20'hc00000;
        end
        3'b111:begin //315..360
            xv[0] <= e_xval;
            yv[0] <= e_yval;
            ph[0] <= i_phase;
        end
    endcase
end


wire [19:0] cordic_angle[0:NSTAGES-1];

assign	cordic_angle[ 0] = 20'h1_2e40; //  26.565051 deg
assign	cordic_angle[ 1] = 20'h0_9fb3; //  14.036243 deg
assign	cordic_angle[ 2] = 20'h0_5111; //   7.125016 deg
assign	cordic_angle[ 3] = 20'h0_28b0; //   3.576334 deg
assign	cordic_angle[ 4] = 20'h0_145d; //   1.789911 deg
assign	cordic_angle[ 5] = 20'h0_0a2f; //   0.895174 deg
assign	cordic_angle[ 6] = 20'h0_0517; //   0.447614 deg
assign	cordic_angle[ 7] = 20'h0_028b; //   0.223811 deg
assign	cordic_angle[ 8] = 20'h0_0145; //   0.111906 deg
assign	cordic_angle[ 9] = 20'h0_00a2; //   0.055953 deg	
assign	cordic_angle[10] = 20'h0_0051; //   0.027976 deg
assign	cordic_angle[11] = 20'h0_0028; //   0.013988 deg
assign	cordic_angle[12] = 20'h0_0014; //   0.006994 deg
assign	cordic_angle[13] = 20'h0_000a; //   0.003497 deg
assign	cordic_angle[14] = 20'h0_0005; //   0.001749 deg
assign	cordic_angle[15] = 20'h0_0002; //   0.000874 deg

genvar i;
generate for(i=0; i<NSTAGES; i=i+1) begin:CORDICops
    initial begin
        xv[i+1] = 0;
        yv[i+1] = 0;
        ph[i+1] = 0;
    end

    always @(posedge i_clk) begin
        if((cordic_angle[i] == 0)||(i >= WW))begin
            xv[i+1] <= xv[i];
            yv[i+1] <= yv[i];
            ph[i+1] <= ph[i];
        end else if(ph[i][PW-1]) begin // Negative phase
            xv[i+1] <= xv[i] + (yv[i]>>>(i+1));
            yv[i+1] <= yv[i] - (xv[i]>>>(i+1));
            ph[i+1] <= ph[i] + cordic_angle[i];
        end else begin 
            xv[i+1] <= xv[i] - (yv[i]>>>(i+1));
            yv[i+1] <= yv[i] + (xv[i]>>>(i+1));
            ph[i+1] <= ph[i] - cordic_angle[i];
        end 
    end


end endgenerate

endmodule



