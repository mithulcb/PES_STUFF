module halfadder(aa,bb,ss,cy);
input aa ,bb ;
output ss ,cy ;
assign ss= aa^bb;
assign cy= aa&bb;
endmodule
