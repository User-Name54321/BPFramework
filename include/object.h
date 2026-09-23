#pragma once
#include <vector>


namespace BPF {
	// component system type component
	class BComponent {
	private:
	public:
		virtual void update();
	};

	// WRAPPER SIDE OF COMPONENTS
	struct Object { // holds ID of valid entity
	public:
		unsigned int id;
		std::vector<BComponent> componentList;

		void update();

		Object(unsigned int num);
	}; 

	class ObjectManager { //contains list and stuff
	private: //might want to make map?
		const unsigned int maxObjects;
		std::vector<unsigned int> freeIdList; 
		std::vector<unsigned int> usedIdList;
	public: 
		std::vector<Object> objectList; 

		unsigned int newObject();
		void deleteObject(unsigned int id);

		Object* returnObject(unsigned int id);

		ObjectManager(unsigned int maxObj = 1000);
	}; 
}