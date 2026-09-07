#pragma once
#include <SDL3/SDL_main.h>
#include "window.h"
#include "render.h"
#include "sysevents.h"
#include "object.h"

#include <vector>

namespace BPF {
	class Engine {
	private:
		Render renderer;
		Window window;
		SysEvents sysevents;

		std::vector<ObjectHandler*> objectLists;
	public:
		int init(const char* name);
		bool run();
		int quit();

	};

}
