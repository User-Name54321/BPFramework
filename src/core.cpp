#include "../include/core.h"


import std;

namespace BPF {
	int Engine::init(const char* name)
	{
		SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO | SDL_INIT_EVENTS);

		window->createWindow(name);
		renderer->initRender(window->window);
		window->readyWindow();

		return 0;
	}
	int Engine::quit()
	{
		SDL_Quit();
		return 0;
	}
}

