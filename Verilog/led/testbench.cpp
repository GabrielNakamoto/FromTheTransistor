#include <iostream>
#include <memory>

#include "Vled_blink.h"
#include "verilated.h"
#include "verilated_vcd_c.h"


// 100khz = 100,000 cycles a second
// therefore each cycle would be 10^-5 second
// or 10 microseconds (10^-6 * 10)

unsigned int time_us = 0;
static constexpr double CLOCK_PERIOD = 10; // in micro-seconds

int main(int argc, char **argv)
{
	Verilated::commandArgs(argc, argv);

	std::unique_ptr<Vled_blink> top { new Vled_blink };

	Verilated::traceEverOn(true);

	const std::unique_ptr<VerilatedVcdC> trace { new VerilatedVcdC };

	// helpful -> https://github.com/verilator/verilator/issues/1937
	// 1 us = 10^-6 seconds
	trace->spTrace()->set_time_unit("1us");
	trace->spTrace()->set_time_resolution("1us");

	top->trace(trace.get(), 99);
	trace->open("led_blink.vcd");

	top->clk = 0;

	// we want to run 4 seconds of simulated time
	// @ 100khz, = 400,000 clock cycles
	// each loop iteration is a clock tick / half a cycle
	// so we run 800,000 times
	for (int i = 0; i < 800000; ++i)
	{
		top->clk = !top->clk;
		top->eval();

		trace->dump(time_us);
		time_us += CLOCK_PERIOD / 2;
	}

	top->final();
	trace->close();

	return 0;
}
