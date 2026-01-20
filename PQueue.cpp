/*
 * LaQueue
 * 
 * 
 * This is part of a series of labs for the Liberal Arts and Science Academy.
 * The series of labs provides a mockup of an POSIX Operating System
 * referred to as LA(SA)nix or LAnix.
 *  
 * (c) copyright 2018, James Shockey - all rights reserved
 * 
 * */

#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include "PQueue.h"



/*
 * Class Priority Queue
 */

		
/*
* Insert into Priority Queue
*/
void PQueue::push(void *item, int priority)
{
	node* tent  = new node;
	tent -> priority = priority;
	tent -> data = item;
	tent -> link = NULL;



	if (front == NULL || priority > front -> priority){
		tent -> link = front;
		front = tent;
		return;
	}

	node* avail = front;
	


	while (avail -> link != NULL && avail ->link -> priority >= priority){
		avail = avail -> link;
	}

	tent -> link = avail -> link;
	avail -> link = tent;

}

/*
 * Delete from Priority Queue
 */
void* PQueue::top()
{
	if (front == NULL) {
		return NULL;
	}

	return front->data;
}
/*
 * Delete from Priority Queue
 */
void PQueue::pop()
{
	if (front == NULL) {
		return;
	}
	node* news = front;
	front = front -> link;
	delete news;

}

/*
 * Print Priority Queue
 */
void PQueue::display()
{

	node* pra = front;


	if (pra == NULL){
		std::cout << "not full" << std::endl;
	}
	
	/* Use the following out command for the data */
	std::cout<<pra->priority<<" "<<(char*)pra->data<<std::endl;

}
	
