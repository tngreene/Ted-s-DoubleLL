/*	Name: Theodore N Greene
	Date: 02/28/2014
	Purpose: To represent a linked list made of nodes and methods to transverse it and edit it
	Exceptions: your type T must be able to be printed out using cout OR be very aware not to pass in anything
	for the traverse method, must have operator overloads for == and !=
*/
#pragma once
#include <iostream>
#include "Node.h"
#include <cmath>

using namespace std;

template <typename T>
class LinkedList
{
private:
	//Head of list
	Node<T> * headNode;
	//Tail of list
	Node<T> * tailNode;

	//The number of nodes in the list
	int count;

public:
	LinkedList(void)
	{
		headNode = NULL;
		tailNode = NULL;

		count = 0;
	}

	~LinkedList(void)
	{
		while(count > 0)
		{
			removeNode(0);
		}
	}

	//Gets the head of the list in the form of a constant pointer
	Node<T> * const getHead()
	{
		return headNode;
	}

	//Gets the tail of the list in the form of a constant pointer
	Node<T> * const getTail()
	{
		return tailNode;
	}
	
	int getCount()
	{
		return count;
	}

	//This inserts a node after a certain index
	//Index must be between -1 and the number of nodes-1
	//In the case of an empty list it will insert at index 0
	//Index = -1: insertion at the head
	//Index = number of nodes-1: inserted at the end
	void insertNode(T & nodeData, int index)
	{
		//If there are no nodes in the list yet, make the head point and tail point to this new one
		//Doesn't matter about index because there is nothing in the list
		if(headNode==NULL)
		{
			Node<T> * firstNode = new Node<T>(nodeData);
			//Set the head of the list equal to this new node
			headNode = firstNode;
		
			//Set the tail of the list equal to this new node
			tailNode = firstNode;
			count++;
			return;
		}

		//If the index seems out of range
		if(index > count-1 || index < -1)
		{
			
			cout << "Index " << index <<" is out of range" << endl;
			return;
		}

		Node<T> * newNode = new Node<T>(nodeData);

		if(index == -1)//We are inserting making the new head node
		{
			//Set our new node's next node to be the start of the list
			newNode->setNext(headNode);

			//Set the node at the start of the list to have its pervious pointer be the new node
			headNode->setPrev(newNode);

			//Move the head of list to the new node (which is now in index 0)
			headNode = newNode;
		}
		else if(index == count-1)//We are inserting to the end of the list
		{
			//Set our new node's previous node to be the start of the list
			newNode->setPrev(tailNode);

			//Set the node at the end of the list to have it's next ptr be the new one
			tailNode->setNext(newNode);
			
			//Move the tail of the list to the new node
			tailNode = newNode;
		}
		else //We are inserting in the middle somewhere
		{
			int middleOfList = floor(count/2);

			//This represents n, we will be inserting after it
			Node<T> * nodeAtIndex;

			if(index <= middleOfList)
			{	
				nodeAtIndex = traverseForward(index);
			}
			else
			{
				nodeAtIndex = traverseReverse(getCount()-1-index);
			}
			//Make the new node point where it should be
			newNode->setPrev(nodeAtIndex);
			newNode->setNext(nodeAtIndex->getNext());
			
			nodeAtIndex->getNext()->setPrev(newNode);
			nodeAtIndex->setNext(newNode);
		}
		
		count++;
	}
	
	//Removes a node at a certain index
	//Returns the pointer to the removed node
	//Index must be between 0 and (size of list-1)
	void removeNode(int index)
    {
        //If the index is less than 0 OR greater than or equal to the count
        if (index < 0 || index > count-1)
        {
            cout << "Index " << index << " is out of range!" << endl;
            return;
        }
         //This represents n, we will be removing
		Node<T> * nodeAtIndex;
		
		int middleOfList = floor(count/2);
		if(index <= middleOfList)
		{	
			nodeAtIndex = traverseForward(index);
		}
		else
		{
			nodeAtIndex = traverseReverse(index);
		}

		if (index == 0)//We are deleting the head
        {
            if (count == 1)//Special case for only having one 
            {
				delete nodeAtIndex;
				headNode = NULL;
                tailNode = NULL;
				count = 0;
				return;
            }

            //Set the head equal to the 2nd node
            headNode = nodeAtIndex->getNext();
            //Set the 2nd node's previous property equal to the null
            
			nodeAtIndex->getNext()->setPrev(NULL);
            
			//Now that the list has moved on delete this node
			delete nodeAtIndex;

            //Decreases the count
			count--;
        }
		else if (index == count-1)//If we are removing the tail
        {
            //Set the tail equal to the 2nd to last node
			tailNode = nodeAtIndex->getPrev();

            //Set the 2nd to last node's previous property equal to null
			nodeAtIndex->getPrev()->setNext(NULL);

            //Now that the node is no longer needed delete it
			delete nodeAtIndex;

            //Decreases the count
            count--;
        }
        else
        {
            //Moves the previous node's connection to the next nodes connection
			nodeAtIndex->getPrev()->setNext(nodeAtIndex->getNext());

            //Moves the previous node's connection to the next nodes connection
			nodeAtIndex->getNext()->setPrev(nodeAtIndex->getPrev());

			//Delete the now unneeded node
            delete nodeAtIndex;

            //Decreases the count
            count--;
        }

		return;
    }

	//Trys to find some kind of data in the list
	//If found it will return a pointer to that node
	//If not found it will return NULL
	Node<T> * findFirstOf(T& data)
	{
		//Create a utilityNode for moving through
		Node<T> * utilNode = headNode;

		//Keep going until you have the end of the list
		while(utilNode != NULL)
		{
			//If the data in the current node is what you're loooking for
			if(utilNode->getNodeData() == data)
			{
				return utilNode;
			}
			//otherwise go to the next one
			utilNode = utilNode->getNext();
		}
		//If you go through the entire list with out finding something return null
		return NULL;
	}

	//Trys to find some kind of data in the list
	//If found it will return a pointer to that node
	//If not found it will return NULL
	Node<T> * findLastOf(T& data)
	{
		//Create a utilityNode for moving through
		Node<T> * utilNode = tailNode;

		//Keep going until you have the end of the list
		while(utilNode != NULL)
		{
			//If the data in the current node is what you're looking for
			if(utilNode->getNodeData() == data)
			{
				return utilNode;
			}
			//otherwise go to the previous one
			utilNode = utilNode->getPrev();
		}
		//If you go through the entire list with out finding something return null
		return NULL;
	}

	//Finds all the nodes with a certain data point
	//and stores it in an array of Nodes
	//Returns true if the operation was a success, false if there was a problem
	bool findAll(T& data, Node<T> outList[], int sizeOfArr)
	{
		//If the size of their array is bigger than the list
		//Exit early
		if(sizeOfArr > count-1)
		{
			cout << "The size of the array larger than list size-1!" << endl;
			return false;
		}
		//Create a utilityNode for moving through
		Node<T> * utilNode = headNode;

		int i = 0;
		//Keep going until you have the end of the list or have went over the size of the array
		while(utilNode != NULL && i < sizeOfArr)
		{
			//If the data in the current node is what you're looking for
			if(utilNode->getNodeData() == data)
			{
				//Copy that
				outList[i] = *utilNode;
				i++;//Increment only when another node has been copied
			}
			//otherwise go to the next one
			utilNode = utilNode->getNext();
		}
		//Return that all went well
		return true;
	}

	//Walks down list to index N (inclusive), returns the pointer to that node
	//toIndex (also refered to as N) must be between 0 and (listSize - 1)
	//It has an optional paramter to use cout to print it. Type T must be able to print to use that!
	Node<T> * traverseForward(int toIndex, bool printData=false)
	{
		//Catches an empty list
		if(headNode == NULL)
		{
			cout << "You have an empty list!" << endl;
			return NULL;
		}

		if(toIndex < 0 || toIndex > count-1)	
		{
			cout << "Index: " << toIndex << " is not in range! Returning NULL" << endl;
			return NULL;
		}
			
		//This node's only purpose is to go through to the end of the list
		Node<T> * utilNode = headNode;
		if(printData == true)
		{
			cout << "N#: H Data: " << utilNode->getNodeData() << "\n";
		}
		
		//For the as many points up to the chosen index
		for (int i = 0; i < toIndex; i++)
        {
			//Traverse down the list by getting the next node and setting it to this one
			utilNode = utilNode->getNext();

			if(printData == true)
			{
				cout << "N#: " << i+1 << " Data: " << utilNode->getNodeData() << "\n";
			}
		}

		return utilNode;
	}

	//Walks up list to index N (inclusive), returns the pointer to that node
	//toIndex (also refered to as N) must be between 0 and (list size-1)
	//It has an optional paramter to use cout to print it. Type T must be able to print to use that!
	Node<T> * traverseReverse(int toIndex, bool printData=false)
	{
		//Catches an empty list
		if(tailNode == NULL)
		{
			cout << "You have an empty list!" << endl;
			return NULL;
		}

		if(toIndex < 0 || toIndex > count-1)	
		{
			cout << "Index: " << toIndex << " is not in range! Returning NULL" << endl;
			return NULL;
		}
			
		//This node's only purpose is to go through to the end of the list
		Node<T> * utilNode = tailNode;
		
		if(printData == true)
		{
			cout << "N#: T Data: " << utilNode->getNodeData() << "\n";
		}

		//For the length of the array
		for (int i = getCount()-1; i > toIndex; i--)
		{
			//Traverse down the list by getting the previous node and setting it to this one
			utilNode = utilNode->getPrev();

			if(printData == true)
			{
				cout << "N#: " << i-1 << " Data: " << utilNode->getNodeData() << "\n";
			}
		}

		return utilNode;
	}
};