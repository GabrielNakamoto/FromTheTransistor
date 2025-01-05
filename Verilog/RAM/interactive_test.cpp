#include <iostream>
#include <memory>
#include <map>

#include "VRAM8.h"
#include "verilated.h"
#include "verilated_vcd_c.h"

static unsigned int dt = 0;


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

	char	ch = 'y';
	while (tolower(ch) == 'y')
	{
		uint16_t 		address;
		uint16_t 		input;
		unsigned int 	load;

		printf("\nAddress:\t\t");
		std::cin >> address;
		printf("Input Number (16-bits:\t");
		std::cin >> input;
		printf("Load Bit (1/0):\t\t");
		std::cin >> load;

		top->address = address;
		top->in = input;
		top->load = load;

		cycle(trace, top);

		printf("\n\nOutput (Reg %d):\t%d\n", address, static_cast<int>(top->out));
		printf("Continue? [Y/N]:\t");
		std::cin >> ch;
	}

	trace->close();
	top->final();

	return 0;
}
