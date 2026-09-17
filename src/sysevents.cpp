#include "../include/sysevents.h"

#include <string>

namespace BPF {

	bool SysEvents::checkQueue() //will need to integrate with own events queue
	{
		SDL_Event pulledEvent;

		while (SDL_PollEvent(&pulledEvent)) {

			Event temp;

			switch (pulledEvent.type) {
			case SDL_EVENT_QUIT:
				return false;
			case SDL_EVENT_MOUSE_MOTION:
				x = pulledEvent.motion.x;
				y = pulledEvent.motion.y;
				dx = pulledEvent.motion.xrel;
				dy = pulledEvent.motion.yrel;
				break;
			case SDL_EVENT_MOUSE_BUTTON_DOWN:
				temp.addData(pulledEvent.button.button, NULL, NULL, x, y);
				obsSys.notify(temp);
				break;
			case SDL_EVENT_TEXT_INPUT: 
				temp.addData(*pulledEvent.text.text);
				obsSys.notify(temp);
				break;
			case SDL_EVENT_KEY_DOWN:
				temp.addData(pulledEvent.key.key);
				obsSys.notify(temp);
				break;
			} // add usage of component system
		}

		return true;
	}

	void SysEvents::addObserver(Observer* observer)
	{
		obsSys.addObserver(observer);
	}

	void SysEvents::removeObserver(Observer* observer)
	{
		obsSys.removeObserver(observer);
	}
}