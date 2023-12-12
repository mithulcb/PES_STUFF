module fa(input wire a, b, c, output wire sum, carry);
    wire[4:0]t; 
    xor x0(t[0],a,b); 
    xor x1(sum,t[0],c); 
    and a0(t[1],a,b); 
    and a1(t[2],a,c); 
    and a2(t[3],b,c); 
    or o0(t[4],t[1],t[2]); 
    or o1(carry,t[4],t[3]); 
endmodule

module fa_row1(input wire [5:0] i, output wire [1:0] o1, o2);
    fa fa0(i[0], i[1], i[2], o1[0], o1[1]);
    fa fa1(i[3], i[4], i[5], o2[0], o2[1]);
endmodule

module fa_row2(input wire [1:0] a, b, input wire c, output wire [2:0] count);
    wire carry;
    fa fa2(a[0], b[0], c, count[0], carry);
    fa fa3(a[1], b[1], carry, count[1], count[2]);
endmodule

module ones(input wire [6:0] i, output wire [2:0] o);
    wire [1:0] t1, t2;
    fa_row1 fa_r1(i[5:0], t1, t2);
    fa_row2 fa_r2(t1, t2, i[6], o);
endmodule  
