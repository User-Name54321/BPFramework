#include "../include/sysevents.h"

namespace BPF {

	bool SysEvents::checkQueue() //will need to integrate with own events queue
	{
		SDL_Event pulledEvent;

		while (SDL_PollEvent(&pulledEvent)) {
			switch (pulledEvent.type) {
			case SDL_EVENT_QUIT:
				return false;
			case SDL_EVENT_TEXT_INPUT: //printing chars
				pulledEvent; // need some sort of struct which can house all
			case SDL_EVENT_KEY_DOWN:

			}
		}

		return true;
	}
}