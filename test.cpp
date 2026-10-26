#include "include/Basic Program Framework.h"
#include <vector>
#include <iostream>

void updateFunc()
{

}

int main(int argc, char* argv[]) {

	BPF::Engine engine;

	engine.init("test");

	engine.update = &updateFunc;

	engine.renderer.createTexture("TEST.png", "1");
	engine.renderer.createSprite(1);
	engine.renderer.setTextureSprite(1, "1");

	BPF::PositionData temp = { 0, 0, 32, 32 };

	// next test = movement + change sprite?

	engine.sysevents.keyInput.addObserver([&temp, &engine](BPF::Event e) {BPF::posMove(&temp, 20, 0); std::cout << "change detec\n"; engine.renderer.updatePos(&temp, 1); });

	engine.renderer.updatePos(&temp, 1);






	while (engine.run(true, 30)) {

		engine.renderer.submitSprite(1);
		
		engine.render(60);
	}

	engine.quit();

	return 0;
}