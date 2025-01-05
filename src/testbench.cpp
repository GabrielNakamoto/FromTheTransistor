#include <iostream>
#include <memory>
#include <map>

#include "VRAM8.h"
#include "verilated.h"
#include "verilated_vcd_c.h"

static unsigned int dt = 0;

static const std::vector<std::tuple<uint16_t, uint16_t, unsigned int>> operations = {
// address, input, load
	{3, 	12, 	1},
	{3, 	-35, 	1},
	{3, 	0, 		0},
	{7, 	2360, 	1},
	{0, 	12, 	0},
	{0, 	15, 	1},
	{7, 	0, 		0}
};


void cycle(const std::unique_ptr<VerilatedVcdC> &trace, const std::unique_ptr<VRAM8> &top)
{
	for (int i = 0; i < 2; ++i)
	{
		top->clk = !top->clk;
		top->eval();
		trace->dump(dt++);
	}
}

int main(int argc, char **argv)
{
	Verilated::commandArgs(argc, argv);

	std::unique_ptr<VRAM8> top { new VRAM8 };

	Verilated::traceEverOn(true);

	const std::unique_ptr<VerilatedVcdC> trace { new VerilatedVcdC };

	top->trace(trace.get(), 99);
	trace->open("res.vcd");

	top->clk = 1;

	for (const auto &[address, input, load] : operations)
	{
		top->address = address;
		top->in = input;
		top->load = load;

		cycle(trace, top);
	}

	trace->close();
	top->final();

	return 0;
}
