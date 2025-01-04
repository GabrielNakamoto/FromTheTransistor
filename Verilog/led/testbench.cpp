#include <iostream>
#include <memory>

#include "Vled_blink.h"
#include "verilated.h"
#include "verilated_vcd_c.h"

// 1mhz 	=	1 million cycles per second
// period	=	1 / 1 * 10^6 
// 			=	1 * 10^-6
//
// 			/ 10^-12 = 10^-6 / 10^-12 = 10^12 / 10^6 = 10^6

unsigned int time_ps = 0; // time in pico-seconds

static constexpr double CLOCK_PERIOD = 10000; // in n-seconds?

int main(int argc, char **argv)
{
	Verilated::commandArgs(argc, argv);

	std::unique_ptr<Vled_blink> top { new Vled_blink };

	Verilated::traceEverOn(true);

	const std::unique_ptr<VerilatedVcdC> trace { new VerilatedVcdC };

	// helpful -> https://github.com/verilator/verilator/issues/1937
	// 1 ns = 10^-9 seconds
	trace->spTrace()->set_time_unit("1ns");
	trace->spTrace()->set_time_resolution("1ns");

	top->trace(trace.get(), 99);
	trace->open("led_blink.vcd");

	top->clk = 0;

	// half a clock cycle
	// lets run 100,000 cycles 3 times
	// we want 100,000 cycles to be a second
	// 100khz
	// runs about 3 seconds
	for (int i = 0; i < 600000; ++i)
	{
		top->clk = !top->clk;
		top->eval();

		trace->dump(time_ps);
		time_ps += CLOCK_PERIOD / 2;
	}

	top->final();
	trace->close();

	return 0;
}
