#include "include/Basic Program Framework.h"

int main(int argc, char* argv[]) {

	BPF::Engine engine;

	engine.init("test");

	while (engine.run()) {

	}

	engine.quit();

	return 0;
}