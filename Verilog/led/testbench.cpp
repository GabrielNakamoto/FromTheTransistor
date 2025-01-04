#include <iostream>
#include <memory>

#include "Vled_blink.h"
#include "verilated.h"
#include "verilated_vcd_c.h"

// 1mhz 	=	1 million cycles per second
// period	=	1 / 1 * 10^6 
// 			=	1 * 10^-6

static constexpr int CLOCK_PERIOD = 1e-6; // in seconds

int main(int argc, char **argv)
{
	Verilated::commandArgs(argc, argv);

	const std::unique_ptr<VerilatedVcdC> trace { new VerilatedVcdC };
	std::unique_ptr<Vled_blink> top { new Vled_blink };

	Verilated::traceEverOn(true);

	top->trace(trace.get(), 10);
	trace->open("led_blink.vcd");

	top->clk = 0;

	for (int i = 0; i < 100000; ++i)
	{
		top->clk = !top->clk;
		top->eval();

		trace->dump(i * CLOCK_PERIOD / 2);

		Verilated::timeInc(CLOCK_PERIOD / 2);
	}

	trace->close();

	return 0;
}
