#include "include/Basic Program Framework.h"
#include <vector>

//int printInputForTest(BPF::Engine* engine) {
//	BPF::Observer obs;
//	engine->sysevents.addObserver(&obs)
//}

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

	BPF::ObserverManager yes;


	engine.renderer.updatePos(&temp, 1);

	while (engine.run()) {
		engine.renderer.submitSprite(1);
	}

	engine.quit();

	return 0;
}