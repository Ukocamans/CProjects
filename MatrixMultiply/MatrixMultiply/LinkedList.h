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
	LinkedList<itemType>* multiply(LinkedList &otherMatrix);
	LinkedList<itemType>& operator=(LinkedList<itemType>& otherList);

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
			newNode->index1 = head.numofelem / head.col;
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
		cout << "Matrix[" << current->index1 << "][" << current->index2 << "] : " << current->data << endl;;
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

template <class itemType>
LinkedList<itemType>& LinkedList<itemType>::operator=(LinkedList<itemType>& otherList)
{
	_2DNode<itemType> *newNode;
	_2DNode<itemType> *current;

	if (head.link != NULL)
	{
		initialize();
	}
	else
	{
		current = otherList.head.link;
		head.numofelem = otherList.head.numofelem;
		head.row = otherList.head.row;
		head.col = otherList.head.col;
		newNode = new _2DNode<itemType>;
		newNode->data = current->data;
		newNode->index1 = current->index1;
		newNode->index2 = current->index2;
		newNode->next = NULL;
		head.link = newNode;
		last = newNode;
		current = current->next;
		while (current != NULL)
		{
			newNode = new _2DNode<itemType>;
			newNode->data = current->data;
			newNode->index1 = current->index1;
			newNode->index2 = current->index2;
			newNode->next = NULL;
			last->next = newNode;
			last = newNode;
			current = current->next;
		}
	}
	return *this;
}

template <class itemType>
LinkedList<itemType>* LinkedList<itemType>::multiply(LinkedList &otherMatrix)
{

	/*
	for(i=0; i<r1; ++i)
	{
		for(j=0; j<c2; ++j)
		{
			for(k=0; k<c1; ++k)
			{
				mult[i][j]+=a[i][k]*b[k][j];
			}
		}
	}
	*/

	if (head.col != otherMatrix.head.row)
	{
		cout << "This matrixes can't be multiplied.\nFirst matrix column must be equal to the second matrix row" << endl;
		exit(EXIT_FAILURE);
	}
	int temp = 0;
	
	LinkedList<int> *matrix3;
	matrix3 = new LinkedList<int>(head.row, otherMatrix.head.col);
	
	for (int i = 0; i<head.row; ++i)
	{
		for (int j = 0; j<otherMatrix.head.col; ++j)
		{
			for (int k = 0; k<head.col; ++k)
			{
				temp += (indexSearch(i, k) * otherMatrix.indexSearch(k, j));
				if (k == head.col-1)
				{
					matrix3->insert(temp);
					temp = 0;
				}
			}
		}
	}

	return matrix3;

}

#endif // !LINKEDLIST_H


