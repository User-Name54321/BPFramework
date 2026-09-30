#define SDL_MAIN_HANDLED 1
#include "../include/core.h"

import std;

namespace BPF {
	int Engine::init(const char* name) 
	{
		SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO | SDL_INIT_EVENTS);

		window.createWindow(name);
		renderer.initRender(window.window);
		window.readyWindow();

		SDL_Log("init done");

		return 0;
	}

	bool Engine::run(bool gameT, int tps) // If gameT is true, use gameloop
	{ 


		if (gameT == true) { // using game time loop
			uint64_t current = SDL_GetTicksNS();
			uint64_t elapsed = current - logicTimeChecked;
			logicTimeChecked = current;
			
			logicTimeSince += elapsed;
			while (logicTimeSince >= 1000000000 / tps) { // check if need to update

				
				if (!sysevents.checkQueue()) {
					return false;
				};

				// UPDATE FUNCTIONS HERE
				

				logicTimeSince -= 1000000000 / tps;
			}
			return true;
		}
		else { // If gameT is false, go as fast as possible
			if (!sysevents.checkQueue()) {
				return false;
			};

			return true;
		}
	}

	bool Engine::render(int fps)
	{
		uint64_t current = SDL_GetTicksNS();
		uint64_t elapsed = current - renderTimeChecked;
		renderTimeChecked = current;
		
		renderTimeSince += elapsed;
		if (renderTimeSince >= 1000000000 / fps) {
			

			
			renderer.draw();

			renderTimeSince -= 1000000000 / fps;
		}

		// NEED TO IMPLEMENT SLEEP JERE
		if (renderTimeSince < 1000000000 / fps) { //might want it to also know tps?
			SDL_DelayPrecise((1000000000 / fps) - renderTimeSince);
		}
		
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

