#include "../include/window.h"
#include <SDL3/sdl.h>
 
namespace BPF {
	bool Window::createWindow(const char* name)
	{
		width = 1280;
		height = 720;
		window = SDL_CreateWindow(name, width, height, SDL_WINDOW_RESIZABLE | SDL_WINDOW_INPUT_FOCUS | SDL_WINDOW_MOUSE_FOCUS | SDL_WINDOW_HIDDEN);
		if (window == NULL) {
			return SDL_SetError("Failed window creation");
		}
		return true;
	}

	bool Window::readyWindow()
	{
		if (SDL_ShowWindow(window)) {
			return true;
		}
		return false;
	}

	void Window::destroyWindow()
	{
		SDL_DestroyWindow(window);
	}
}