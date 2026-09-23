#pragma once
#include <SDL3/SDL_main.h>
#include "window.h"
#include "render.h"
#include "sysevents.h"
#include "object.h"

#include <vector>

namespace BPF {
	class Engine {
	private:

		//beign reond
		std::vector<ObjectManager> objectList; // will need more - maybe link somehow via pointers? idk vro hm
		// need to be able to store not just object/id list, but also each component - what will be stored here vs in logic level?
		// what will seperate logic level vs the core?
		// - logic layer could just be all functional
		// - but then that wouldnt allow for inherited things like health, etc
		// - REALLY need to be able to just add new classes/managers and be able to keep track of them
		// - could user really not track?

	public:
		Render renderer;
		Window window;
		SysEvents sysevents;

		int init(const char* name);
		bool run();
		int quit();

	};

}
