#include "../include/render.h"
#include <SDL3_image/SDL_image.h>



import std;


namespace BPF {
	int Render::initRender(SDL_Window* window)
	{
		renderer = SDL_CreateRenderer(window, NULL);

		return 0;
	}
	void Render::quitRender()
	{
		SDL_DestroyRenderer(renderer);
	};

	void Render::createTexture(std::string path, std::string name)
	{ // might want to redo to use whatever its called
		SDL_Surface* surface = IMG_Load(path.c_str()); // requires SDL_Image extensions

		if (surface == nullptr) {
			std::cout << "failed surface loading\n" << SDL_GetError() << "\n";
			return;
		}

		SDL_Texture* txtr = SDL_CreateTextureFromSurface(renderer, surface);
		SDL_DestroySurface(surface);

		if (txtr == nullptr) {
			std::cout << "failed texture loading\n" << SDL_GetError() << "\n";
			return;
		}

		textureList.emplace_back(Texture{ name, txtr });
	}
	
	unsigned int Render::createSprite(unsigned int id) // add newly created sprite to vector
	{
		return spriteList.newObject(id);
	}

	bool Render::setTextureSprite(unsigned int spriteID, std::string textureName) 
	{
		auto* temp = spriteList.returnObject(spriteID);
		if (temp == nullptr) {
			return false;
		}
		for (int i = 0; i < textureList.size(); i++) {
			if (textureList[i].name == textureName) {
				temp->texture = textureList[i].texture;
				return true;
			}
		}
		return false;
	}

	bool Render::deleteSprite(unsigned int id)
	{
		auto* temp = spriteList.returnObject(id); // access the ecs or whatever
		if (temp == nullptr) { // catch failure to find
			return false;
		}

		SDL_DestroyTexture(temp->texture); // needs to be accessed from wherever they stored

		return true;
	}
	
	bool Render::submitSprite(unsigned int id) 
	{

		auto* ptr = spriteList.returnObject(id);
		if (ptr == nullptr) {
			return false;
		}
		renderList.push_back(ptr);

		return true;
	}
	
	void Render::draw() //render listed textures
	{
		SDL_RenderClear(renderer);

		for (int i = 0; i < renderList.size(); i++) {
			if (!SDL_RenderTextureRotated(renderer, renderList[i]->texture, NULL, &renderList[i]->position, renderList[i]->rotation, NULL, SDL_FLIP_VERTICAL)) {
				std::cout << SDL_GetError() << "\n";
			}
		}

		SDL_RenderPresent(renderer);
		
	}

}