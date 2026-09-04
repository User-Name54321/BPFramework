#pragma once
#include <SDL3/SDL_main.h>
#include "window.h"
#include "render.h"

namespace BPF {
	class Engine {
	private:
		Render* renderer;
		Window* window;
	public:
		int init(const char* name);
		int quit();

	};

}
