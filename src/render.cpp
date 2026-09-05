#include "../include/render.h"
#include <SDL3_image/SDL_image.h>

import std;


namespace BPF {
	Sprite::Sprite(SDL_Renderer* renderPtr, std::string file)
	{
		surface = IMG_Load(file.c_str());
		SDL_CreateTextureFromSurface(renderPtr, surface);
	}

	Sprite::~Sprite()
	{
		SDL_DestroySurface(surface);
		SDL_DestroyTexture(texture);
	}


	int Render::initRender(SDL_Window* window)
	{
		renderer = SDL_CreateRenderer(window, NULL);

		return 0;
	}
	void Render::quitRender()
	{
		SDL_DestroyRenderer(renderer);
	};


	{
		spriteList.emplace_back(Sprite(renderer, path));
	}

	{
		renderList.push_back(ptr);
	}

	{
		for (int i = 0; i < renderList.size(); i++) {
			SDL_RenderTextureRotated(renderer, renderList[i]->texture, NULL, NULL, 0, NULL, SDL_FLIP_VERTICAL); // need to replace 1st 2 NULLs with SDL_frect and 0 with double for rotation
		}
	}

}