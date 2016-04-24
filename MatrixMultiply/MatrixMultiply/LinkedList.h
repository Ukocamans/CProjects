#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>

using namespace std;

template<class itemType>
struct _2DNode
{
	int index1;
	int index2;
	itemType data;
	_2DNode<itemType> *next;
};

template<class itemType>
struct _2DMatrix
{
	int row;
	int col;
	int numofelem;
	_2DNode<itemType> *link;
};

template<class itemType>
class LinkedList
{
public:
	LinkedList();
	LinkedList(int row, int column);
	void initialize();
	bool isEmpty();
	bool isFull();
	int length();
	void print();
	itemType indexSearch(int row, int col);
	void insert(itemType item);
	//LinkedList* multiply(LinkedList &otherMatrix);

	~LinkedList();

private:
	_2DMatrix<itemType> head;
	_2DNode<itemType> *last;

};

template<class itemType>
LinkedList<itemType>::LinkedList()
{
	
	head.row = 0;
	head.col = 0;
	head.link = NULL;
	head.numofelem = 0;
	last = NULL;
}

template<class itemType>
LinkedList<itemType>::LinkedList(int row, int column)
{
	head.row = row;
	head.col = column;
	head.link = NULL;
	head.numofelem = 0;
	last = NULL;
}

template<class itemType>
bool LinkedList<itemType>::isEmpty()
{
	return head.link == NULL;
}


template<class itemType>
bool LinkedList<itemType>::isFull()
{
	return head.numofelem == head.col * head.row;
}

template<class itemType>
int LinkedList<itemType>::length()
{
	return head.numofelem;
}

template<class itemType>
void LinkedList<itemType>::initialize()
{
	if (isEmpty())
	{
		return;
	}
	else
	{
		_2DNode<itemType> *current;

		for (int i = 0; i < head.numofelem; i++)
		{
			current = head.link;
			head.link = current->next;
			delete current;
			
		}
		last = NULL;
		head.col = 0;
		head.row = 0;
		head.numofelem = 0;
	}
	
}

template<class itemType>
void LinkedList<itemType>::insert(itemType item)
{
	_2DNode<itemType> *newNode;

	newNode = new _2DNode<itemType>;

	newNode->data = item;
	newNode->next = NULL;

	if (isEmpty())
	{
		newNode->index1 = 0;
		newNode->index2 = 0;
		head.link = newNode;
		last = newNode;
		head.numofelem++;
	}
	else
	{
		
		if (isFull())
		{
			cout << "Matrix is full..." << endl;
		}
		else
		{
			newNode->index1 = head.numofelem / head.row;
			newNode->index2 = head.numofelem % head.col;
			last->next = newNode;
			last = newNode;
			head.numofelem++;
		}
	}
}

template<class itemType>
void LinkedList<itemType>::print()
{
	_2DNode<itemType> *current;
	current = head.link;
	while (current != NULL)
	{
		cout << "Row : " << current->index1 << " Collumn : " << current->index2 << " Data : " << current->data << endl;
		current = current->next;
	}
}

template<class itemType>
itemType LinkedList<itemType>::indexSearch(int row, int col)
{
	_2DNode<itemType> *current;
	current = head.link;
	while (current != NULL)
	{
		if (current->index1 == row && current->index2 == col)
		{
			return current->data;
		}
		current = current->next;
	}
}

template<class itemType>
LinkedList<itemType>::~LinkedList()
{
	initialize();
}

#endif // !LINKEDLIST_H


