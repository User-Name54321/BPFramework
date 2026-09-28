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

		ComponentManager<Sprite> spriteList; 

		std::vector<Texture> textureList;

		void createTexture(std::string path, std::string name); // Given image path and name, sets up SDL texture and adds a new Texture object to textureList.


		unsigned int createSprite(unsigned int id); // Given ID, creates an empty sprite assigned to that ID in spriteList.
		bool deleteSprite(unsigned int id); // Given ID, deletes a sprite from spriteList.
		bool submitSprite(unsigned int id); // Given ID, submits a sprite to be drew on current frame.

		bool updatePos(PositionData* data, unsigned int id); // SHOULD LIKELY BE MOVED ELSEWHERE | Given PositionData object + sprite ID, gives sprite position data.

		int initRender(SDL_Window* window); // Creates SDL renderer with a specific window.
		void quitRender(); // Destroys SDL renderer given specific window.

		void draw(); // Render sprites in renderList.

		// system to manage textures
		// -need names

		// need functions to update sprite ness
		bool setTextureSprite(unsigned int spriteID, std::string textureName); // Given a sprite's ID and a texture's name, assigns the sprite a texture.


	};
}