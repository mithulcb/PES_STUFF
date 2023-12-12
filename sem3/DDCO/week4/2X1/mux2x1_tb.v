module mux2x1_tb;
reg A,B,S;
wire X;
initial
begin
$dumpfile("mux2x1_test.vcd");
$dumpvars(0,mux2x1_tb);
end
mux2 newMUX(.i0(A), .i1(B), .j(S), .o(X));
initial
begin
#5 
S = 1'b0;
A = 1'b0;
B = 1'b0;
#5 
S = 1'b0;
A = 1'b0;
B = 1'b1;
#5 
S = 1'b0;
A = 1'b1;
B = 1'b0;
#5 
S = 1'b0;
A = 1'b1;
B = 1'b1;
#5
S = 1'b1;
A = 1'b0;
B = 1'b0;
#5
S = 1'b1;
A = 1'b0;
B = 1'b1;
#5
S = 1'b1;
A = 1'b1;
B = 1'b0;
#5
S=1'b1;
A = 1'b1;
B = 1'b1;
#5;
end
always@(A or B or S)
$monitor("At time = %t,S=%b, A=%b, B=%b,Output = %b",$time,S,A,B, X);
endmodule
