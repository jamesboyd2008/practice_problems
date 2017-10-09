//This is the implementation file queue.cpp
//The interface is located in queue.h

#include <iostream>
#include <cstdlib>
#include <cstddef>
#include "queue.h"
using namespace std;


	//Uses cstddef;
	Queue::Queue() : front(NULL), back(NULL) 
	{
		// This space intentionally left blank
	}

	Queue::Queue(const Queue& aQueue)
	{
		if (aQueue.empty())
			front=back=NULL;
		else
		{
			QueueNodePtr temp_ptr_old = aQueue.front;
			QueueNodePtr temp_ptr_new;

			back = new QueueNode;
			back->data = temp_ptr_old->data;
			back->link = NULL;
			front = back;

			temp_ptr_old = temp_ptr_old->link;

			while(temp_ptr_old != NULL)
			{
				temp_ptr_new = new QueueNode;
				temp_ptr_new->data = temp_ptr_old->data;
				temp_ptr_new->link = NULL;
				back->link = temp_ptr_new;
				back = temp_ptr_new;
				temp_ptr_old = temp_ptr_new->link;
			}
		}
	}

	Queue::~Queue()
	{
		char next;
		while (!empty())
			next = remove(); // remove calls delete
	}

	bool Queue::empty() const
	{
		return( back == NULL);
	}

	void Queue::add(char item)
	{
		if (empty())
		{
			front = new QueueNode;
			front->data = item;
			front->link = NULL;
			back = front;
		}
		else
		{
			QueueNodePtr temp_ptr;
			temp_ptr = new QueueNode;
			temp_ptr->data = item;
			temp_ptr->link = NULL;
			back->link = temp_ptr;
			back = temp_ptr;
		}
	}

	char Queue::remove()
	{
		if (empty())
		{
			cout << "Error: Removing an item from an empty queue/\n";
			system("pause");
			exit(1);
		}

		char result = front->data;

		QueueNodePtr discard;
		discard = front;
		front = front->link;

		if (front == NULL) 
			back = NULL;

		delete discard;
		return result;
	}

			


