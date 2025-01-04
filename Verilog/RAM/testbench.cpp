#include <iostream>
#include <memory>
#include <map>

#include "Vdmux4way.h"
#include "verilated.h"
#include "verilated_vcd_c.h"

template<typename T>
void evaluateModule(std::unique_ptr<T> &module, unsigned char in, uint8_t sel, int a, int b, int c, int d)
{
	module->in = in;
	module->sel = sel;

	module->eval();

	printf("Result: 	[%d, %d, %d, %d]\n", module->a, module->b, module->c, module->d);
	printf("Expected: 	[%d, %d, %d, %d]\n\n", a, b, c, d);
}

int main(int argc, char **argv)
{
	Verilated::commandArgs(argc, argv);

	std::unique_ptr<Vdmux4way> top { new Vdmux4way };

	evaluateModule<Vdmux4way>(top, 1, 0, 1, 0, 0, 0);
	evaluateModule<Vdmux4way>(top, 1, 1, 0, 1, 0, 0);
	evaluateModule<Vdmux4way>(top, 1, 2, 0, 0, 1, 0);
	evaluateModule<Vdmux4way>(top, 1, 3, 0, 0, 0, 1);

	top->final();

	return 0;
}
