module mux4x1_tb;
reg [0:3]ii;
reg s0;
reg s1;
wire yy;
initial
begin
$dumpfile("mux4x1_test.vcd");
$dumpvars(0, mux4x1_tb);
end
mux4 newMUX(.i(ii), .j0(s0),.j1(s1),.o(yy));
initial
begin
#5
ii = 4'b1000;
s0=1'b0;
s1=1'b0;
#5      
ii= 4'b0100;
s0=1'b0;
s1=1'b1;
#5
ii = 4'b0010;
s0=1'b1;
s1=1'b0;
#5
ii= 4'b0001;
s0=1'b1;
s1=1'b1;
#5;
end
always@(ii or s0 or s1)
$monitor("At time = %t,Inputs=%b, s0=%b, s1=%b,Output = %b",$time,ii,s0,s1, yy);
endmodule