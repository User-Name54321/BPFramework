#pragma once
#include <SDL3/sdl.h>

namespace BPF {
	class Window {
	private:
		int width, height = 0;
	public:
		SDL_Window* window;
		bool createWindow(const char* name); // Creates window with given name.
		bool readyWindow(); // Makes window visible, already called in core init function.
		void destroyWindow(); // Destroys the window.
	};

}
