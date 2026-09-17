#include "../include/events.h"

namespace BPF {

	void Event::addData(int a, int b, unsigned int id, float c, float d, int e)
	{
		a = data;
		b = data2;
		c = data3;
		d = data4;
		e = data5;

		entityId = id;
	}

	void Observer::notify(Object* reciever, Event event) // reciever?
	{
		
	}

	void ObserverManager::notify(Event event)
	{
		for (int i = 0; i < observerList.size(); i++) {
			observerList[i]->notify(NULL, event); //fix null? idk what thats supposed to be
		}
	}

	void ObserverManager::addObserver(Observer* observer)
	{
		observerList.push_back(observer);
	}
	void ObserverManager::removeObserver(Observer* observer)
	{
		auto i = std::find(observerList.begin(), observerList.end(), observer);
		if (i != observerList.end()) {
			observerList.erase(i);
		}
	}
}