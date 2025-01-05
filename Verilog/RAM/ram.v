module dmux(a, b, in, sel);

	input wire in, sel;
	output wire a, b;

	wire ns;

	// a if sel = 0, else b
	not n1(ns, sel);
	and a1(a, ns, in);

	// b if sel and in
	and a2(b, sel, in);

endmodule

module dmux4way(a, b, c, d, in, sel);

	input wire in;
	input wire [1:0] sel;

	output wire a, b, c, d;

	wire h1, h2; // half 1 / 2 ([a,b] vs [c,d])

	// distribute between a / b and c / d
	dmux d1(
		.in(in),
		.sel(sel[1]),
		.a(h1),
		.b(h2));

	dmux d2(
		.in(h1),
		.sel(sel[0]),
		.a(a),
		.b(b));

	dmux d3(
		.in(h2),
		.sel(sel[0]),
		.a(c),
		.b(d));

endmodule


module dmux8way(a, b, c, d, e, f, g, h, in, sel);

	input wire in;
	input wire [2:0] sel;

	output wire a, b, c, d, e, f, g, h;

	// distribute between first halfs, then use dmux4ways

	wire h1, h2;

	dmux d1(
		.in(in),
		.sel(sel[2]),
		.a(h1),
		.b(h2));

	dmux4way d2(
		.in(h1),
		.sel(sel[1:0]),
		.a(a),
		.b(b),
		.c(c),
		.d(d));

	dmux4way d3(
		.in(h2),
		.sel(sel[1:0]),
		.a(e),
		.b(f),
		.c(g),
		.d(h));

endmodule

module mux(out, a, b, sel);

	input wire a, b, sel;
	output wire out;

	wire nsel, o1, o2;

	not n1(nsel, sel);
	and a1(o1, a, nsel);

	and a2(o2, b, sel);

	or of(out, o1, o2);

endmodule

module mux4way(out, a, b, c, d, sel);

	input wire a, b, c, d;
	input wire [1:0] sel;

	output wire out;

	wire h1, h2;

	mux m1(h1, a, b, sel[1]);
	mux m2(h2, c, d, sel[1]);

	mux m3(out, h1, h2, sel[0]);

endmodule

module Register16(out, in, load, clk);

	input wire [15:0] in;
	input wire load, clk;

	output wire [15:0] out;

	reg [15:0] internal;

	always @(posedge clk) begin
		out <= internal;
		if(load) begin
			internal <= in;
		end
	end

endmodule

// 8 16-bit registers
module RAM8(out, in, address, load, clk);

	input wire [15:0] in;
	input wire load, clk;
	input wire [2:0] address;

	output wire out;

	// 16-bit registers
	// reg [15:0] r1, r2, r3, r4, r5, r6, r7, r8;

	// distributed loads
	wire l1, l2, l3, l4, l5, l6, l7, l8;

	// outputs
	wire o1, o2, o3, o4, o5, o6, o7, o8;

	// distribute load
	// dmux 8 way
	dmux8way distribute(	
		.in(load),
		.sel(address),
		.a(l1),
		.b(l2),
		.c(l3),
		.d(l4),
		.e(l5),
		.f(l6),
		.g(l7),
		.h(l8));

	// calculate outputs
	Register16 r1(o1, in, l1, clk);
	Register16 r2(o2, in, l2, clk);
	Register16 r3(o3, in, l3, clk);
	Register16 r4(o4, in, l4, clk);
	Register16 r5(o5, in, l5, clk);
	Register16 r6(o6, in, l6, clk);
	Register16 r7(o7, in, l7, clk);
	Register16 r8(o8, in, l8, clk);

	// select output and connect it with output

endmodule
