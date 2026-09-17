#pragma once
#include <vector>

namespace BPF {

	class Object { // goal is to be able to create a new object which is lightweight and can have any number of objects or functionalities + still needs to be linked somehow
	private:
	public:
		unsigned int id;
		virtual void update();

		Object(unsigned int num);

		Object();
	};

	class ObjectManager { //contains list and stuff
	private:
		const unsigned int maxObjects;
		std::vector<unsigned int> freeIdList; //maybe also have not free?
	public: 
		std::vector<Object> objectList; 

		unsigned int newObject();

		ObjectManager(unsigned int maxObj = 1000);
	};
}