#pragma once
#include <SDL3/sdl.h>

#include "../include/events.h"

namespace BPF {
	class SysEvents {
	private:
;
		float x;            
		float y;            
		float dx;         
		float dy;
	public:
		ObserverManager keyInput;
		ObserverManager mouseInput; // need to figure out what to do with this

		bool checkQueue(); // return 1 for quit, 0 for continue
	};
}