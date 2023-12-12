module assign1_tb; 
reg aa,bb,cc,aa1,bb1,cc1; 
wire ss,cy,ss1,cy1; 
assign1 add1(.a(aa),.b(bb),.cin(cc),.sum(ss),.cout(cy));
assign1 add2(.a(aa1),.b(bb1),.cin(cc1),.sum(ss1),.cout(cy1)); 
initial
begin
$dumpfile("assign1_test.vcd"); 
$dumpvars(0,assign1_tb); 
end
initial
begin
$monitor($time,"a=%b,b=%b,c=%b,sum=%b,cout=%b",aa,bb,cc,ss,cy); 
aa=1'b0;bb=1'b0;cc=1'b0; 
$monitor($time,"a1=%b,b1=%b,c1=%b,sum=%b,cout=%b",aa1,bb1,cc1,ss1,cy1); 
aa1=1'b1;bb1=1'b1;cc1=1'b1; 
end 
endmodule
