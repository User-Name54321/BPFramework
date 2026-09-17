#pragma once
#include <SDL3/sdl.h>

#include "../include/events.h"

namespace BPF {
	class SysEvents {
	private:
		ObserverManager obsSys;
		float x;            
		float y;            
		float dx;         
		float dy;
	public:
		void addObserver(Observer* observer);
		void removeObserver(Observer* observer);

		bool checkQueue(); // return 1 for quit, 0 for continue
	};
}