#pragma once
#include <SDL3/SDL_main.h>
#include "window.h"
#include "render.h"
#include "sysevents.h"
#include "object.h"

#include <cstdint>
#include <vector>

namespace BPF {
	class Engine {
	private:
		uint64_t logicTimeChecked = 0;
		uint64_t renderTimeChecked = 0;
		uint64_t logicTimeSince = 0;
		uint64_t renderTimeSince = 0;
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

		int init(const char* name); // Starts SDL systems, starts BPF renderer and window.
		bool run(bool gameT = false,  int tps = 30); // Main loop - polls for input
		bool render(int fps = 60); // Works in tandem with main loop to render, manages cpu sleeping
		int quit(); // Destroys services.

	};
	
}
