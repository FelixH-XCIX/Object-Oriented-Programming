#include <iostream>
using namespace std;

// Functions as described on the question paper.
void inputMatrix(int**, const int, const int, int**, const int, const int);
void multiplyMatrix(int**, const int, const int, int**, const int, const int, int**);
void outputMatrix(int**, const int, const int);

int main()
{
	int rowA, rowB;
	int colA, colB;

	// Reads until an EOF condition is encountered.
	while (cin >> rowA)
	{
		cin >> colA;
		cin >> rowB >> colB;

		int** matrixA;
		int** matrixB;

		matrixA = new int* [rowA];
		for (int i = 0; i < rowA; i++) matrixA[i] = new int[colA];

		matrixB = new int* [rowB];
		for (int i = 0; i < rowB; i++) matrixB[i] = new int[colB];

		inputMatrix(matrixA, rowA, colA, matrixB, rowB, colB);
		if (colA != rowB)
		{
			cout << "Matrix multiplication failed.\n";
			continue;
		}
		else
		{
			int** results;
			results = new int* [rowA];
			for (int i = 0; i < rowA; i++) results[i] = new int[colB];
			multiplyMatrix(matrixA, rowA, colA, matrixB, rowB, colB, results);
			outputMatrix(results, rowA, colB);
			for (int i = 0; i < rowA; i++) delete[] results[i];
			delete[] results;
		}

		for (int i = 0; i < rowA; i++) delete[] matrixA[i];
		delete[] matrixA;
		for (int i = 0; i < rowB; i++) delete[] matrixB[i];
		delete[] matrixB;
	}
}

void inputMatrix(int** A, const int rowA, const int colA, int** B, const int rowB, const int colB)
{
	for (int i = 0; i < rowA; i++) for (int j = 0; j < colA; j++) cin >> A[i][j];
	for (int i = 0; i < rowB; i++) for (int j = 0; j < colB; j++) cin >> B[i][j];
}

void multiplyMatrix(int** A, const int rowA, const int colA, int** B, const int rowB, const int colB, int** R)
{
	// Initializes the results matrix's elements to 0.
	for (int i = 0; i < rowA; i++) for (int j = 0; j < colB; j++) R[i][j] = 0;

	for (int i = 0; i < rowA; i++)
	{
		for (int j = 0; j < colB; j++)
		{
			for (int k = 0; k < colA; k++) R[i][j] += (A[i][k] * B[k][j]);
		}
	}
}

void outputMatrix(int** A, const int rowA, const int colA)
{
	for (int i = 0; i < rowA; i++)
	{
		for (int j = 0; j < colA; j++)
		{
			if (j == colA - 1)
				cout << A[i][j];
			else
				cout << A[i][j] << " ";
		}
		cout << endl;
	}
}