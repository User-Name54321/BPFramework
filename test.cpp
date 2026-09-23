#include "include/Basic Program Framework.h"

int main(int argc, char* argv[]) {

	BPF::Engine engine;

	engine.init("test");

	BPF::Logger logger;
	logger.init();

	engine.renderer.createTexture("TEST.png", "1");
	engine.renderer.createSprite(1);
	engine.renderer.setTextureSprite(1, "1");

	while (engine.run()) {
		engine.renderer.submitSprite(1);
	}

	engine.quit();

	return 0;
}