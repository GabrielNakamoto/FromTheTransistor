#include <iostream>
#include <memory>
#include <map>

#include "Vdmux8way.h"
#include "verilated.h"
#include "verilated_vcd_c.h"


/*
void testDmux4Way(std::unique_ptr<Vdmux4way> &module)
{
	auto evaluateModule = [&](unsigned char in, uint8_t sel, int a, int b, int c, int d){
		module->in = in;
		module->sel = sel;

		module->eval();

		printf("Result: 	[%d, %d, %d, %d]\n", module->a, module->b, module->c, module->d);
		printf("Expected: 	[%d, %d, %d, %d]\n\n", a, b, c, d);
	};

	evaluateModule(1, 0, 1, 0, 0, 0);
	evaluateModule(1, 1, 0, 1, 0, 0);
	evaluateModule(1, 2, 0, 0, 1, 0);
	evaluateModule(1, 3, 0, 0, 0, 1);
}
*/

/*
void testDmux8Way(std::unique_ptr<Vdmux8way> &m)
{
	auto evaluateModule = [&](unsigned char in, uint16_t sel, std::vector<int> exp)
	{
		m->in = in;
		m->sel = sel;

		m->eval();

		printf("Input:\t\t%d\nSelected:\t%d\n\n", in, sel);
		printf("Result:\t\t[%d, %d, %d, %d, %d, %d, %d, %d]\n", m->a, m->b, m->c, m->d, m->e, m->f, m->g, m->h);
		printf("Expected:\t[%d, %d, %d, %d, %d, %d, %d, %d]\n\n", exp[0], exp[1], exp[2], exp[3], exp[4], exp[5], exp[6], exp[7]);
	};

	evaluateModule(1, 0, { 1, 0, 0, 0, 0, 0, 0, 0 });
}
*/

void interactiveD8W(std::unique_ptr<Vdmux8way> &m)
{
	char	ch = 'y';
	while(tolower(ch) == 'y')
	{
		unsigned int 	in;
		uint16_t 		sel;

		printf("Input bit:\t\t");
		std::cin >> in;
		printf("Selection [0->7]:\t");
		std::cin >> sel;

		m->in = static_cast<unsigned char>(in);
		m->sel = sel;

		m->eval();

		printf("\nInput:\t\t%d\nSelected:\t%d\n\n", in, sel);
		printf("Result:\t\t[%d, %d, %d, %d, %d, %d, %d, %d]\n", m->a, m->b, m->c, m->d, m->e, m->f, m->g, m->h);
		printf("Continue? [Y/N]\n");
		std::cin >> ch;
	}
}

int main(int argc, char **argv)
{
	Verilated::commandArgs(argc, argv);

	std::unique_ptr<Vdmux8way> top { new Vdmux8way };

	interactiveD8W(top);
	// testDmux8Way(top);

	top->final();

	return 0;
}
