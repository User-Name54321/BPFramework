#include "../include/events.h"
#include <utility>

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

	ObserverManager::~ObserverManager() = default;

	void ObserverManager::notify(Event event)
	{
		for (int i = 0; i < observerList.size(); i++) {
			observerList[i](event); 
		}
	}

	unsigned int ObserverManager::addObs(std::function<void(Event)> cb)
	{
		observerList.push_back(cb);

		idList.emplace_back(observerList.size() - 1);

		return idList.size() - 1;
	}

	unsigned int ObserverManager::addObserver(std::function<void(Event)> cb)
	{
		return addObs(cb);
	}

	void ObserverManager::removeObserver(unsigned int id)
	{
		if (id < idList.size()) {
			std::swap(observerList[idList[id]], observerList.back());
			idList[id] = 0;
			observerList.pop_back();
		}
	}


	void EventQueue::pushEvent(Event e)
	{
		queue.push_back(std::move(e));
	}

	Event EventQueue::pullEvent()
	{
		auto temp = queue.front();
		queue.pop_front();
		return temp;
	}
}