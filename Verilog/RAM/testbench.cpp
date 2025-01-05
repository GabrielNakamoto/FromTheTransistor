#include <iostream>
#include <memory>
#include <map>

#include "VRAM8.h"
#include "verilated.h"
#include "verilated_vcd_c.h"

uint16_t clockTick(std::unique_ptr<VRAM8> &ram)
{
	ram->clk = 0;
	ram->eval();

	ram->clk = 1;
	ram->eval();

	return ram->out;
}

int main(int argc, char **argv)
{
	Verilated::commandArgs(argc, argv);

	std::unique_ptr<VRAM8> top { new VRAM8 };

	top->clk = 1;

	char		ch = 'y';
	uint16_t	output_reg;
	while (tolower(ch) == 'y')
	{
		uint16_t 		address;
		uint16_t 		input;
		unsigned int 	load;

		printf("Address (0 -> 7):\t\t");
		std::cin >> address;

		printf("Input (16 bit number):\t\t");
		std::cin >> input;

		printf("Load (0 / 1):\t\t");
		std::cin >> load;

		top->address = address;
		top->in = input;
		top->load = load;
		top->clk = !top->clk;

		output_reg = clockTick(top);

		printf("Result:\t\t%d\n", output);

		std::cout << "Continue? [Y/N]\n";
		std::cin >> ch;
	}

	top->final();

	return 0;
}
