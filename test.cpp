#include "include/Basic Program Framework.h"
#include <vector>

void printthing(BPF::Event test)
{
	std::cout << "test\n";
}

int main(int argc, char* argv[]) {

	BPF::Engine engine;

	engine.init("test");

	BPF::Logger logger;
	logger.init();

	engine.renderer.createTexture("TEST.png", "1");
	engine.renderer.createSprite(1);
	engine.renderer.setTextureSprite(1, "1");

	BPF::PositionData temp = { 0, 0, 32, 32 };

	// next test = movement + change sprite?

	engine.sysevents.keyInput.addObserver(&printthing);



	engine.renderer.updatePos(&temp, 1);

	while (engine.run(true, 30)) {

		engine.renderer.submitSprite(1);

		engine.render(60);
	}

	engine.quit();

	return 0;
}