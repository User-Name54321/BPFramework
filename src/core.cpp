#define SDL_MAIN_HANDLED 1
#include "../include/core.h"

import std;

namespace BPF {
	int Engine::init(const char* name) //auto start different systems and create window
	{
		SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO | SDL_INIT_EVENTS);

		window.createWindow(name);
		renderer.initRender(window.window);
		window.readyWindow();

		return 0;
	}

	bool Engine::run() //main loop
	{
		if (!sysevents.checkQueue()) {
			return false;
		};
		
		renderer.draw();
		return true;
	}

	int Engine::quit() //shut down everything
	{
		renderer.quitRender();
		window.destroyWindow();
		SDL_Quit();
		return 0;
	}
}

