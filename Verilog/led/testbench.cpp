#include <iostream>
#include <memory>

#include "Vled_blink.h"
#include "verilated.h"
#include "verilated_vcd_c.h"

int main(int argc, char **argv)
{
	Verilated::commandArgs(argc, argv);

	const std::unique_ptr<VerilatedVcdC> trace { new VerilatedVcdC };
	std::unique_ptr<Vled_blink> top { new Vled_blink };

	Verilated::traceEverOn(true);

	top->trace(trace.get(), 10);
	trace->open("led_blink.vcd");

	top->clk = 0;

	int sim_time = 0;
	for (int i = 0; i < 100000; ++i)
	{
		top->clk = !top->clk;
		top->eval();

		trace->dump(sim_time);
		sim_time += 5;

		Verilated::timeInc(5);
	}

	trace->close();

	return 0;
}
