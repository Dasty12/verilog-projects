#include "testbench.h"

int main(int argc, char **argv) {
	Verilated::commandArgs(argc, argv);
	TESTBENCH<Vmodule> *tb = new TESTBENCH<Vmodule>();

	while(!tb->done()) {
		tb->tick();
	} exit(EXIT_SUCCESS);
}