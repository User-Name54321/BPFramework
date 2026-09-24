#include "../include/reporting.h"

namespace BPF {
	bool Logger::init()
	{
		queue = SDL_CreateAsyncIOQueue();
		file = SDL_AsyncIOFromFile("log.txt", "w");
		std::cout << "logging ok\n";
		if (queue == nullptr || file == nullptr) {
			return false;
		}
		SDL_SetLogOutputFunction(log, this); // might be an issue
		return true;
	}

	bool Logger::run()
	{
		SDL_AsyncIOOutcome* outcome;
		while (SDL_GetAsyncIOResult(queue, outcome)) {
		}
		return true;
	}

	void Logger::log(void* userdata, int category, SDL_LogPriority priority, const char* message)
	{
		
		BPF::Logger* here = static_cast<Logger*>(userdata);
		here->msg = message;
		SDL_WriteAsyncIO(here->file, &here->msg, 0, sizeof(here->msg), here->queue, nullptr);
	
	}

	void Logger::quit()
	{
		SDL_CloseAsyncIO(file, true, queue, nullptr);
		SDL_DestroyAsyncIOQueue(queue);
		file = nullptr;
		queue = nullptr;
	}

	Logger::Logger()
	{
		
	}
	Logger::~Logger()
	{
		SDL_SetLogOutputFunction(SDL_GetDefaultLogOutputFunction(), nullptr);
	}
}