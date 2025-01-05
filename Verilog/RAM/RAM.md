# RAM

As part of learning verilog, and having just followed the beginning of nand2tetris in my
learning journey, I decided to redimplement my 8 x 16-bit register ram module in verilog.

Since it seemed there were no multiplexors or de-multiplexors builtin to verilog,
I built my own!

I also implemented a load based 16-bit register module to use.

[ram.v](ram.v) includes the following modules:

- dmux
- dmux_4way
- dmux_8way
- mux
- mux16
- mux16_4way
- mux16_8way
- Register16
- RAM8
