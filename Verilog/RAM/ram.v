module dmux(in, sel, a, b);

	input wire in, sel;
	output wire a, b;

	wire ns;

	// a if sel = 0, else b
	not n1(ns, sel);
	and a1(a, ns, in);

	// b if sel and in
	and a2(b, sel, in);

endmodule

module dmux4way(in, sel, a, b, c, d);

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

/*
module dmux8way(in, sel, a, b, c, d, e, f, g, h);

	input wire in;
	input wire [2:0] sel;

	output wire a, b, c, d, e, f, g, h;

endmodule


// 8 16-bit registers
module RAM8(in, address, load, out);

	input wire in, address, load;
	output wire out;

	// distribute load
	// dmux 8 way

	// calculate outputs

	// select output and connect it with output

endmodule
*/
