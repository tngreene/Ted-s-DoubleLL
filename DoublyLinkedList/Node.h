/*	Name: Theodore N Greene
	Date: 02/28/2014
	Purpose: To represent a node to be put in a linked list
	Exceptions: currently can only hold any kind of data, any data type stored in a node must have the following capabilities: default constructor
*/

#pragma once
#include <iostream>

using namespace std;

template <class T>
class Node
{
private:
	//Data stored in the node
	T nodeData;

	//pointer to the next node
	Node *next;

	//pointer to the previous node
	Node *previous;

public:
	Node(void)
	{
		nodeData = T();
		next = NULL;
		previous = NULL;
	}

	Node(const T& data)
	{
		nodeData = data;

		next = NULL;
		previous = NULL;
	}
	~Node(void)
	{
	}
	
	//Accessors to return the Data 
	T& getNodeData()
	{
		return nodeData;
	}
	
	//gets the next pointer to a node
	Node* getNext()
	{
		return next;
	}

	//gets the previous pointer to a node
	Node* getPrev()
	{
		return previous;
	}

	//Mutators to change the pointer's location
	void setNext(Node* nLink)
	{
		next = nLink;
	}

	void setPrev(Node* pLink)
	{
		previous = pLink;
	}
};

