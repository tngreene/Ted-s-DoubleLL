#include "TestLinkedList.h"
/*	Name: Theodore N Greene
	Date: 3/3/2014
	Purpose: To test linked list methods
	Exceptions: do it all in main
*/
TestLinkedList::TestLinkedList(void)
{
}


TestLinkedList::~TestLinkedList(void)
{
}

int main()
{
	Node<char> outList[4];
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
	
	//All the same as count-1
	ll.insertNode(a,-1);
	ll.insertNode(b,0);
	ll.insertNode(c,1);
	ll.insertNode(d,2);
	ll.insertNode(e,3);
	ll.insertNode(f,4);
	ll.insertNode(g,5);
	
	ll.traverseForward(ll.getCount()-1,true);

	ll.traverseReverse(ll.getCount()-1,true);
	ll.insertNode(b,2);
	ll.insertNode(b,3);
	ll.insertNode(b,1);
	ll.traverseForward(ll.getCount()-1,true);

	ll.traverseReverse(ll.getCount()-1,true);
	/*
	//Cases for remove: Remove head
	ll.removeNode(0);
	//Cases for remove: remove tail
	ll.removeNode(ll.getCount()-1);
	//Cases for remove: remove inside
	ll.removeNode(3);

	ll.traverseForward(ll.getCount()-1,true);

	ll.traverseReverse(ll.getCount()-1,true);
	ll.insertNode(x,-1);
	ll.insertNode(y,ll.getCount()-1);
	ll.insertNode(z,2);

	ll.traverseForward(ll.getCount()-1,true);

	ll.traverseReverse(ll.getCount()-1,true);

	Node<char> * fOPtr = ll.findFirstOf(b);
	Node<char> * lOPtr = ll.findLastOf(b);
	*/
	ll.findAll(b,outList,4);
	}//The deconstructor will be called here

	return 0;
}