#pragma once
#include <vector>
#include <memory>

namespace BPF {
	//predef
	class Object;



	struct Event { //might want union for this
	private:
	public:
		unsigned int entityId;
		int data; // needs a bit of fixing or smtn
		int data2;
		float data3;
		float data4;
		int data5;

		void addData(int a = NULL, int b = NULL, unsigned int id = NULL, float c = NULL, float d = NULL, int e = NULL); // designed bad
	};

	class Observer { // constructor could contain function pointer
	private:
	public:
		virtual void notify(Object* reciever, Event event); //should execute something or 
	};

	class ObserverManager { // holds and can broadcast events
	private:
		std::vector<Observer*> observerList; 
	public:
		void notify(Event event);
		void addObserver(Observer* observer);
		void removeObserver(Observer* observer);
	};

	class EventQueue { //don't want for input
	private:
	public:

	};

}