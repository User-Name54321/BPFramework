#include "../include/object.h"
import std;

namespace BPF {


	Object::Object(unsigned int num)
	{
		id = num;
	}

	void Object::update() 
	{
		for (int i = 0; i < componentList.size(); i++) {
			componentList[i].update();
		}
	}

	Object* ObjectManager::returnObject(unsigned int id)
	{
		for (unsigned int i = 0; i < objectList.size(); i++) {
			if (objectList[i].id == id) {
				return &objectList[i];
			}
		}

		return nullptr;
	}

	ObjectManager::ObjectManager(unsigned int maxObj) : maxObjects(maxObj)
	{
		for (unsigned int i = 0; i < maxObjects; i++) {
			freeIdList.emplace_back(i + 1);
		}
		usedIdList.reserve(maxObj);
	}

	unsigned int ObjectManager::newObject()
	{
		unsigned int temp = freeIdList.back();
		freeIdList.pop_back();

		objectList.emplace_back(Object{ temp });

		usedIdList.emplace_back(temp);

		return temp;
	}

	void ObjectManager::deleteObject(unsigned int id)
	{
		for (int i = 0; i < objectList.size(); i++) {
			if (objectList[i].id == id) {
				std::swap(objectList[i], objectList.back());
				objectList.pop_back();
			}
		}
	}
}