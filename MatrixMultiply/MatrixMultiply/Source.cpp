/*
	Author : Umurcan Kocaman
	Number : 1301020441
*/

#include <iostream>
#include "LinkedList.h"

using namespace std;

int main()
{
	LinkedList<int> *matrix1,*matrix2, *matrix3;

	int row,row2;
	int col,col2;
	int val;

	cout << "Write row length for your first matrix : ";
	cin >> row;
	cout << "Write column length for your first matrix : ";
	cin >> col;
	matrix1 = new LinkedList<int>(row, col);
	int **arr1 = new int*[row];
	for (int i = 0; i < row; i++)
	{
		arr1[i] = new int[col];
	}

	cout << endl;

	cout << "Write row length for your second matrix : ";
	cin >> row2;
	cout << "Write column length for your second matrix : ";
	cin >> col2;

	cout << endl;

	matrix2 = new LinkedList<int>(row2, col2);
	int **arr2 = new int*[row2];
	for (int i = 0; i < row2; i++)
	{
		arr2[i] = new int[col2];
	}

	matrix1->isMultipliable(*matrix2);

	cout << "Write elements of your first matrix" << endl;
	cout << endl;
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			cout << "Matrix1[" << i << "][" << j << "] : ";
			cin >> val;
			arr1[i][j] = val;
		}
	}

	matrix1->arrayToLList(arr1);
	cout << endl;

	cout << "Write elements of your second matrix" << endl;
	cout << endl;
	for (int i = 0; i < row2; i++)
	{
		for (int j = 0; j < col2; j++)
		{
			cout << "Matrix2[" << i << "][" << j << "] : ";
			cin >> val;
			arr2[i][j] = val;
		}
	}

	matrix2->arrayToLList(arr2);
	
	cout << endl;
	cout << endl;

	matrix3 = matrix1->multiply(*matrix2);

	cout << "Multiplied matrix is : " << endl;
	cout << endl;
	matrix3->print();
	
	return 0;
}