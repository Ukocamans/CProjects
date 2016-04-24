#include <iostream>
#include "LinkedList.h"

using namespace std;

int main()
{
	LinkedList<int> matrix1(2, 2),matrix2(2,3), *matrix3;
	matrix3 = NULL;
	matrix1.insert(1);
	matrix1.insert(1);
	matrix1.insert(2);
	matrix1.insert(2);

	matrix2.insert(1);
	matrix2.insert(2);
	matrix2.insert(3);
	matrix2.insert(4);
	matrix2.insert(5);
	matrix2.insert(6);

	

	matrix3 = matrix1.multiply(matrix2);

	matrix3->print();
	
	return 0;
}