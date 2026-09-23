#include "../../include/objects/position.h"

namespace BPF {
	SDL_FRect posBox(PositionData* data)
	{
		return SDL_FRect(data->x, data->y, data->w, data->h);
	}

	float posRotation(PositionData* data)
	{
		return data->rotation;
	}

	void posMove(PositionData* data, float xi, float yi, bool mode)
	{
		if (mode == false) {
			data->x = xi;
			data->y = yi;
		}
		else {
			data->dx = xi;
			data->dy = yi;
		}
	}

	void posScale(PositionData* data, float xi, float yi, bool mode)
	{
		if (mode == false) {
			data->w *= xi;
			data->h *= yi;
		}
		else {
			data->dw = xi;
			data->dh = yi;
		}
	}

	void posRotate(PositionData* data, float degreesi, bool mode)
	{
		if (mode == false) {
			data->rotation = degreesi;
		}
		else {
			data->dr = degreesi;
		}
	}
	
	void posUpdate(PositionData* data) // how long do they last?
	{
		data->x += data->dx;
		data->y += data->dy;

		data->w *= data->dw;
		data->h *= data->dh;

		data->rotation += data->dr;
	}


}