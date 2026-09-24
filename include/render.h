#pragma once
#include <SDL3/sdl.h>
#include <vector>
#include <string>
#include "components.h"
#include "objects/position.h"
#include "reporting.h"


namespace BPF {
	struct Sprite { // image
	public:
		SDL_Texture* texture; // can just be hot swapped for animations
		SDL_FRect position; // NEED TO FIND A WAY TO FILL USING POSITIONS
		double rotation; // AND THESE
	};

	struct Texture {
	private:
	public:
		std::string name;
		SDL_Texture* texture;
	};

	class Render { 
	private:
		SDL_Renderer* renderer;
		std::vector<Sprite*> renderList;
	public:

		ComponentManager<Sprite> spriteList; // should actually be sparse/entity probably, will look for id or smtn position

		std::vector<Texture> textureList;

		void createTexture(std::string path, std::string name);


		unsigned int createSprite(unsigned int id);
		bool deleteSprite(unsigned int id);
		bool submitSprite(unsigned int id);

		bool updatePos(PositionData* data, unsigned int id); // should likely be moved elsewhere

		int initRender(SDL_Window* window);
		void quitRender();

		void draw();

		// system to manage textures
		// -need names

		// need functions to update sprite ness
		bool setTextureSprite(unsigned int spriteID, std::string textureName);


	};
}