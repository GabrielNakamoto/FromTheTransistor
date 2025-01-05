#include <iostream>
#include <memory>
#include <map>

#include "VRAM8.h"
#include "verilated.h"
#include "verilated_vcd_c.h"

static unsigned int dt = 0;

// address, input, load, cycle offset
static const std::vector<std::tuple<uint16_t, uint16_t, unsigned int, unsigned int>> operations = {
	{3, 12, 1, 16},
	{3, 15, 0, 30}
};


void cycle(int cycles, const std::unique_ptr<VerilatedVcdC> &trace, const std::unique_ptr<VRAM8> &top)
{
	for (int i = 0; i < 2 * cycles; ++i)
	{
		dt++;
		top->clk = !top->clk;
		top->eval();
		trace->dump(dt);
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

	for (const auto &[address, input, load, cycles] : operations)
	{
		std::cout << address << ' ' << input << ' ' << load << ' ' << cycles << '\n';
		top->address = address;
		top->in = input;
		top->load = load;

		top->eval();

		cycle(cycles, trace, top);
	}

	trace->close();
	top->final();

	return 0;
}
