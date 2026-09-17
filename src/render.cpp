#include "../include/render.h"
#include <SDL3_image/SDL_image.h>



import std;


namespace BPF {
	Sprite::Sprite(SDL_Renderer* renderPtr, std::string file)
	{
		SDL_Surface* surface = IMG_Load(file.c_str());
		texture = SDL_CreateTextureFromSurface(renderPtr, surface);
		SDL_DestroySurface(surface);
	}

	Sprite::~Sprite()
	{
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

	
	void Render::createTexture(std::string path) // add newly created sprite to vector
	{
		spriteList.emplace_back(Sprite(renderer, path));
	}
	
	void Render::submitTexture(Sprite* ptr) 
	{
		renderList.push_back(ptr);
	}
	
	void Render::draw() //render listed textures
	{
		for (int i = 0; i < renderList.size(); i++) {
			SDL_RenderTextureRotated(renderer, renderList[i]->texture, NULL, &renderList[i]->position, renderList[i]->rotation, NULL,  SDL_FLIP_VERTICAL); 
		}
		renderList.clear();
	}

}