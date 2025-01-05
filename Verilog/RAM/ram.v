module dmux(
	output wire a, b,
	input wire in,
	input wire sel
);

	wire ns;

	// a if sel = 0, else b
	not n1(ns, sel);
	and a1(a, ns, in);

	// b if sel and in
	and a2(b, sel, in);

endmodule

module dmux_4way(
	output wire a, b, c, d,
	input wire in,
	input wire [1:0] sel
);

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


module dmux_8way(
	output wire a, b, c, d, e, f, g, h,
	input wire in,
	input wire [2:0] sel
);
	// distribute between first halfs, then use dmux4ways

	wire h1, h2;

	dmux d1(
		.in(in),
		.sel(sel[2]),
		.a(h1),
		.b(h2));

	dmux_4way d2(
		.in(h1),
		.sel(sel[1:0]),
		.a(a),
		.b(b),
		.c(c),
		.d(d));

	dmux_4way d3(
		.in(h2),
		.sel(sel[1:0]),
		.a(e),
		.b(f),
		.c(g),
		.d(h));

endmodule

module mux(
	output wire out,
	input wire a, b,
	input wire sel
);

	wire nsel, o1, o2;

	not n1(nsel, sel);
	and a1(o1, a, nsel);

	and a2(o2, b, sel);

	or of(out, o1, o2);

endmodule

module mux16(
	output wire [15:0] out,
	input wire [15:0] a, b,
	input wire sel
);

	mux m1(out[0], a[0], b[0], sel);
	mux m2(out[1], a[1], b[1], sel);
	mux m3(out[2], a[2], b[2], sel);
	mux m4(out[3], a[3], b[3], sel);
	mux m5(out[4], a[4], b[4], sel);
	mux m6(out[5], a[5], b[5], sel);
	mux m7(out[6], a[6], b[6], sel);
	mux m8(out[7], a[7], b[7], sel);
	mux m9(out[8], a[8], b[8], sel);
	mux m10(out[9], a[9], b[9], sel);
	mux m11(out[10], a[10], b[10], sel);
	mux m12(out[11], a[11], b[11], sel);
	mux m13(out[12], a[12], b[12], sel);
	mux m14(out[13], a[13], b[13], sel);
	mux m15(out[14], a[14], b[14], sel);
	mux m16(out[15], a[15], b[15], sel);

endmodule

module mux16_4way(
	output wire [15:0] out,
	input wire [15:0] a, b, c, d,
	input wire [1:0] sel
);

	wire [15:0] h1, h2;

	mux16 m1(h1, a, b, sel[0]);
	mux16 m2(h2, c, d, sel[0]);

	mux16 m3(out, h1, h2, sel[1]);

endmodule

module mux16_8way(
	output wire [15:0] out,
	input wire [15:0] a, b, c, d, e, f, g, h,
	input wire [2:0] sel
);

	wire [15:0] h1, h2;

	mux16_4way m1(h1, a, b, c, d, sel[2:1]);
	mux16_4way m2(h2, e, f, g, h, sel[2:1]);

	mux16 m3(out, h1, h2, sel[0]);

endmodule

module Register16(
	output reg [15:0] out,
	input wire [15:0] in,
	input wire load,
	input wire clk
);

	always @(posedge clk) begin
		if(load)
			out <= in;
	end

endmodule

// 8 16-bit registers
module RAM8(
	output wire [15:0] out,
	input wire [15:0] in,
	input wire [2:0] address,
	input wire load,
	input wire clk
);
	// distributed loads
	wire l1, l2, l3, l4, l5, l6, l7, l8;

	// outputs
	wire [15:0] o1, o2, o3, o4, o5, o6, o7, o8;

	// distribute load
	// dmux 8 way
	dmux_8way distribute(	
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
	mux16_8way select(
		.out(out),
		.sel(address),
		.a(o1),
		.b(o2),
		.c(o3),
		.d(o4),
		.e(o5),
		.f(o6),
		.g(o7),
		.h(o8));

endmodule
