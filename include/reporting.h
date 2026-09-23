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
		//need to use SDL iostream
		bool init();
		bool run();
		static void log(void* userdata, int category, SDL_LogPriority priority, const char* message);
		void quit();

		Logger();
		~Logger();
		
	};
}

