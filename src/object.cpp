#include "../include/object.h"
import std;

namespace BPF {
	Object::Object(unsigned int num)
	{
		id = num;
	}

	Object::Object() = default;

	void Object::update() // needed?
	{

	
	}

	ObjectManager::ObjectManager(unsigned int maxObj) : maxObjects(maxObj)
	{
		for (unsigned int i = 0; i < maxObjects; i++) {
			freeIdList.emplace_back(i + 1);
		}
	}

	unsigned int ObjectManager::newObject()
	{
		objectList.emplace_back(Object{});
	}


}