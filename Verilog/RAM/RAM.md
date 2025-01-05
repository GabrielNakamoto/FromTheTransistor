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

## Interface

```verilog
module RAM8(
	output wire [15:0] out,
	input wire [15:0] in,
	input wire [2:0] address,
	input wire load,
	input wire clk
);
```

## Implementation

My RAM consists of a:

- **Distributer** an 8-way dmux circuit that distributes the load input signal
to the correct register
- **Registers** the 16 bit registers which will connect the 16-bit input signal to their enclosed
output register if the load signal is on
- **Selector** an 8-way 16-bit mux circuit that will 'select' or set the output wire's signal to the
output of the register corresponding to the provided address


<p align="center">
<i>Diagram of my RAM module created by me! using <a href="https://github.com/YosysHQ/yosys">this awesome project</a></i>
</p>

![Diagram of 8 x 16 bit register ram module](ram.png)
