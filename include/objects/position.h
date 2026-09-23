#pragma once

#include <SDL3/sdl.h>

namespace BPF {
	struct PositionData { // implement observer actions on logic level?
	public:
		float x = 0, y = 0, w = 32, h = 32;
		float dx = 0, dy = 0, dw = 1, dh = 1;
		float rotation = 0;
		float dr = 0;		
	};

	SDL_FRect posBox(PositionData* data);
	float posRotation(PositionData* data);

	void posMove(PositionData* data, float xi, float yi, bool mode = false);
	void posScale(PositionData* data, float xi, float yi, bool mode = false);
	void posRotate(PositionData* data, float degreesi, bool mode = false);

	void posUpdate(PositionData* data);
}