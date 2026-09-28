#pragma once
#include <vector>
#include <memory>
#include <functional>
#include <deque>


namespace BPF {

	struct Event { //might want union for this
	private:
	public:
		unsigned int entityId;
		int data; // maybe use union? this is quite inefficient
		int data2; 
		float data3;
		float data4;
		int data5;

		void addData(int a = NULL, int b = NULL, unsigned int id = NULL, float c = NULL, float d = NULL, int e = NULL); // designed bad
	};

	class ObserverManager { // holds function ptrs/lambdas to registered "observers" (callbacks), can push notifications and register/unregister observers
	private:
		using Callback = std::function<void(Event)>; 
		std::vector<Callback> observerList; // holds callbacks to observer notify functions
		std::vector<unsigned int> idList; // holds IDs to allow for deregistering | 0 = empty
	public:
		virtual void notify(Event event); // Calls all of the callbacks in the observerList with an Event as an argument.
		virtual void removeObserver(unsigned int id); // Finds and removes a registered callback.
		virtual unsigned int addObs(std::function<void(Event)>); // Implied by addObserver

		unsigned int addObserver(std::function<void(Event)> cb); // Input function. Registers a callback to a notify function. Returns ID which can be used to remove it.

		template <typename O, typename M>
		unsigned int addObserver(std::shared_ptr<O> object, M method); // Input object and method of said object. Registers a callback to notify function, returns ID which can be used to remove it. Deletion safe.

		virtual ~ObserverManager();
	};

	class EventQueue { //don't want for input
	private:
		std::deque<Event> queue;
	public:
		void pushEvent(Event e); // Adds event to back.
		Event pullEvent(); // Pulls event from front.
	};


	template <typename O, typename M>
	unsigned int ObserverManager::addObserver(std::shared_ptr<O> object, M method)
	{
		std::weak_ptr<O> temp = object;

		if (auto ptr = temp.lock())
		{
			return addObs([ptr, method]() {std::invoke(method, ptr); });
		}
		return 0;

	}

}