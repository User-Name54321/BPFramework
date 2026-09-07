#pragma once
#include <SDL3/sdl.h>

namespace BPF {
	class SysEvents {
	private:
	public:
		bool checkQueue(); // return 1 for quit, 0 for continue
	};
}