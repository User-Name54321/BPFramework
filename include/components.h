#pragma once

#pragma once
#include <vector>

namespace BPF {

	struct DComponent { // only data
	public:

	}; 

	template <typename O>
	class ComponentManager { //contains list and stuff
	private: 
		const unsigned int maxObjects; 

		unsigned int activeObj;
		
		std::vector<unsigned int> idIndex; //sparse - maxObjects + 1 == free
		std::vector<O> componentList; //dense 
	public:
		unsigned int newObject(unsigned int id = 4294967295);

		void deleteObject(unsigned int id);

		O* returnObject(unsigned int id);

		ComponentManager(unsigned int maxObj = 1000);
	}; // need way to 

	template <typename O>
	O* ComponentManager<O>::returnObject(unsigned int id)
	{
		if (idIndex[id] != maxObjects + 1) {
			return &componentList[idIndex[id]];
		}

		return nullptr;
	}

	template <typename O>
	ComponentManager<O>::ComponentManager(unsigned int maxObj) : maxObjects(maxObj)
	{
		idIndex.resize(maxObj, maxObj + 1);
	}

	template <typename O>
	unsigned int ComponentManager<O>::newObject(unsigned int id) // might need to be able to provide? need to lock components and ecs component ids together - or just leave unlocked
	{
		activeObj++;
		if (id == 4294967295) { // if in no id provided mode
			for (int i = 0; i < maxObjects; i++) { // i = id
				if (idIndex[i] == maxObjects + 1) { // this loop and if only finds free id
					componentList.emplace_back(O{});
					idIndex[i] = componentList.size() - 1;
					return i;
				}
			}
		}
		else {
			if (idIndex[id] == maxObjects + 1) {
				componentList.emplace_back(O{});
				idIndex[id] = componentList.size() - 1;
				return id;
			}
		}

		return maxObjects + 1;
	}

	template <typename O>
	void ComponentManager<O>::deleteObject(unsigned int id)
	{
		if (idIndex[id] != maxObjects + 1) {
			std::swap(componentList[idIndex[id]], componentList.back());
			componentList.pop_back();			
			idIndex[id] = maxObjects + 1;
		}
	}

}