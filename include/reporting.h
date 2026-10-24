#pragma once

#include <iostream>
#include <SDL3/SDL.h>
#include <string>

namespace BPF {
	class Logger {
	private:
		SDL_AsyncIOQueue* queue;
		SDL_AsyncIO* file;

		std::string msg;
	public:
		enum priority {
			LOG,
			LOW,
			MEDIUM,
			HIGH,
			CRITICAL
		};
		//need to use SDL iostream
		bool init();
		bool run();
		static void log(void* userdata, int category, priority priority, const char* message); //need to figure out how to include prorities
		void quit();

		Logger();
		~Logger();
		
	};
}

