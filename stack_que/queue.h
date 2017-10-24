// This is the header file for queue.h This is the interface file for the class Queue
// which is a class for a queue of symbols
#ifndef QUEUE_H
#define QUEUE_H


	struct QueueNode
	{
		char data;
		QueueNode *link;
	};

	typedef QueueNode* QueueNodePtr;

	class Queue
	{
	public:
		Queue(); //initializes an empty queue
		
		Queue(const Queue& aQueue); //copy constructor

		~Queue(); // destructor

		void add(char item);

		char remove(); //Returns the item from the front of the list if the queue is not empty
		
		bool empty() const; //True if queue is empty. False otherwise. 
	private:
		QueueNodePtr front; // points to the front of the queue
		QueueNodePtr back; // points to the back of the queue
	};
#endif //Queue_H

