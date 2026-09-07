#pragma once
#include <vector>

namespace BPF {

	class Object { // goal is to be able to create a new object which is lightweight and can have any number of objects or functionalities
	private:
	public:
		unsigned int id;
		virtual void update();
	};

	class ObjectHandler { //contains list and stuff
	private:
	public:
		std::vector<Object*> objectList; // might want to tie in ids or smtn
	};
}