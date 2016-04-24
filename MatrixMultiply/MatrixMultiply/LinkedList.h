#ifndef LINKEDLIST_H
#define LINKEDLIST_H

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
	_2DNode<itemType> *head;
};

template<class itemType>
class LinkedList
{
public:
	LinkedList();
	void initialize();
	bool ÝsEmpty();
	bool isFull();
	int length();
	void print();
	itemType indexSearch(int row, int col);
	void insert(itemType item);
	LinkedList* multiply(LinkedList &otherMatrix);

	~LinkedList();

private:
	_2DMatrix<itemType> *head;
	_2DNode<itemType> *last;

};

template<class itemType>
LinkedList<itemType>::LinkedList()
{
	head->row = 0;
	head->col = 0;
	head->head = NULL;
	head->numofelem = 0;
	last = head->head;
}



#endif // !LINKEDLIST_H


