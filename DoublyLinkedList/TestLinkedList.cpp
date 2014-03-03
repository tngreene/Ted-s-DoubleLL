#include "TestLinkedList.h"

TestLinkedList::TestLinkedList(void)
{
}


TestLinkedList::~TestLinkedList(void)
{
}

int main()
{
	LinkedList<char> ll;
	char a = 'a';
	char b = 'b';
	char c = 'c';
	char d = 'd';
	char e = 'e';
	char f = 'f';
	char g = 'g';
	char x = 'x';
	char y = 'y';
	char z = 'z';
	char head = 'H';
	char tail = 'T';
	//All the same as count-1
	ll.insertNode(a,-1);
	ll.insertNode(b,0);
	ll.insertNode(c,1);
	ll.insertNode(d,2);
	ll.insertNode(e,3);
	ll.insertNode(f,4);
	ll.insertNode(g,5);

	ll.insertNode(x,-1+1);
	ll.insertNode(y,0+1);
	ll.insertNode(z,1+1);
	//ll.insertNode(h,7-1);
	//ll.insertNode(i,8-1);

	Node<char> * ptr0 = ll.traverseForward(ll.getCount()-1,true);
	cout << endl;
	Node<char> * ptr1 = ll.traverseReverse(ll.getCount()-1,true);
	ptr1 = ll.traverseReverse(1,true);
	return 0;
	//Create the data reader
	/*DataFile dataFile("Sample1.txt");

	//Open the file and save any error codes
	int openError = dataFile.openFile();

	if(openError != 0)
	{
		system("pause");
		return 0;
	}

	//Our linked List for this test
	LinkedList linkedList;

	char * tempLine;
	//while there are still words to read
	/*while(true)
	{
		tempLine = dataFile.nextWord();
		if(tempLine != NULL)
		{
			linkedList.insertWord(tempLine);
		}
		else
		{
			break;
		}
	}*/
	//dataFile.openFile();

	/*Node node("Balls");
	cout << node.getNodeData() << endl;
	Node* ptrN = node.getNext();
	Node* ptrP = node.getNext();
	
	Node newNode("Balls 2");
	node.setNext(newNode.getNext());
	cout << node.getNext();
	cout << node.getPrev();
	
	LinkedList ll;

	ll.insertWord("Ball");
		node = *ll.getHead();
	cout << node.getNodeData();
	
	newNode = *ll.getTail();
	cout <<newNode.getNodeData();
	ll.insertWord("Barry");
			node = *ll.getHead();
	cout << node.getNodeData();
	
	newNode = *ll.getTail();
	cout <<newNode.getNodeData();

	return 0;
	while(true)
	{
	}*/
}