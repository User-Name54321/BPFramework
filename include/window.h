#pragma once
#include <SDL3/sdl.h>

namespace BPF {
	class Window {
	private:
		int width, height = 0;
	public:
		SDL_Window* window;
		bool createWindow(const char* name);
		bool readyWindow();
		void destroyWindow();
	};

}
