#include <iostream>
#include <memory>
#include <map>

#include "VRAM8.h"
#include "verilated.h"

void cycle(const std::unique_ptr<VRAM8> &top)
{
	for (int i = 0; i < 2; ++i)
	{
		top->clk = !top->clk;
		top->eval();
	}
}

void printRegisters(const std::unique_ptr<VRAM8> &top)
{
	std::printf("Register\tWord\n");
	std::printf("----------------\n");
	for (int r = 0; r < 8; ++r)
	{
		top->address = r;
		top->load = 0;

		cycle(top);

		std::printf("%d\t%d\n", r, static_cast<int>(top->out));
	}
	std::printf("\n");
}

int main(int argc, char **argv)
{
	Verilated::commandArgs(argc, argv);

	std::unique_ptr<VRAM8> top { new VRAM8 };

	top->clk = 1;

	char	ch = 'y';
	while (tolower(ch) == 'y')
	{
		uint16_t 		address;
		uint16_t 		input;
		unsigned int 	load;

		printf("\nAddress:\t\t");
		std::cin >> address;
		printf("Input Number (16-bits):\t");
		std::cin >> input;
		printf("Load Bit (1/0):\t\t");
		std::cin >> load;

		top->address = address;
		top->in = input;
		top->load = load;

		cycle(top);

		printf("\nOutput (Reg %d):\t%d\n\n", address, static_cast<int>(top->out));
		printRegisters(top);
		printf("Continue? [Y/N]:\t");
		std::cin >> ch;
	}

	top->final();

	return 0;
}
