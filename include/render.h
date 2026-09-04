#pragma once
#include <SDL3/sdl.h>
#include <vector>
#include <string>


namespace BPF {
	class Sprite {
	private:
	public:
		SDL_Surface* surface;
		SDL_Texture* texture;
		Sprite(SDL_Renderer* renderPtr, std::string file);
		~Sprite();
	};

	class Render {
	private:
		SDL_Renderer* renderer;
		std::vector<Sprite*> renderList;
	public:
		std::vector<Sprite> spriteList;
		void createTexture(std::string path);
		void submitTexture(Sprite* ptr);

		int initRender(SDL_Window* window);
		void quitRender();

		void draw();
	};
}