#include <iostream>
#include "LinkedList.h"

using namespace std;

int main()
{
	LinkedList<int> *matrix1,*matrix2, *matrix3;
	int row;
	int col;
	int val;

	cout << "Write row length for your first matrix : ";
	cin >> row;
	cout << "Write column length for your first matrix : ";
	cin >> col;
	matrix1 = new LinkedList<int>(row, col);

	cout << endl;

	cout << "Write elements of your first matrix" << endl;
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			cout << "Matrix1[" << i << "][" << j << "] : ";
			cin >> val;
			matrix1->insert(val);
		}
	}

	cout << endl;
	cout << endl;

	cout << "Write row length for your second matrix : ";
	cin >> row;
	cout << "Write column length for your second matrix : ";
	cin >> col;

	cout << endl;

	matrix2 = new LinkedList<int>(row, col);
	cout << "Write elements of your second matrix" << endl;
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			cout << "Matrix2[" << i << "][" << j << "] : ";
			cin >> val;
			matrix2->insert(val);
		}
	}
	
	cout << endl;
	cout << endl;

	matrix3 = matrix1->multiply(*matrix2);

	cout << "Multiplied matrix is : " << endl;

	matrix3->print();
	
	return 0;
}