#pragma once
#include <iostream>
#include <fstream>

using namespace std;

template <class T>
class Matrix
{
private:
	int rows, cols;
	T* pMatrix;

public:
	//We construct the matrix in three different ways.
	//First, we can make it with determined rows and columns.
	Matrix(int Rows,int  Cols)
	{
		rows = Rows;
		cols = Cols;
		
		pMatrix = new T[rows * cols];	
	}
	
	//Second, we can make a square matrix with a determined size.
	Matrix(int Size)
	{
		rows = Size;
		cols = Size;

		pMatrix = new T[rows * cols];
	}

	//Lastly, we can make a matrix that is the copy of another matrix.
	Matrix(const Matrix& matrix)
	{
		rows = matrix.rows;
		cols = matrix.cols;

		pMatrix = new T[rows * cols];

		for(int i = 0; i < rows * cols; i++)
		{
			pMatrix[i] = matrix.pMatrix[i];
		}

	}

	~Matrix()
	{
		delete[] pMatrix;
	}
	
	//Allows to write in elements to the matrix.
	friend istream& operator>> (istream& s, Matrix& matrix)
	{
        	for(int i = 0; i < matrix.rows * matrix.cols; i++)
        	{
                	s >> matrix.pMatrix[i];
        	}

        	return s;
	}
	
	//Allows to print out elements to the matrix.
	friend ostream& operator<< (ostream& s, Matrix& matrix)
	{
		for(int i = 0; i < matrix.rows; i++)
		{
			for(int j = 0; j < matrix.cols; j++)
			{
				s << matrix.pMatrix[i * matrix.cols + j] << " ";
			}
			s << endl;
		}
		return s;
	}

	//Allows to read in a matrix from a file.
	friend ifstream& operator>> (ifstream& fs, Matrix& matrix)
	{
		for(int i = 0; i < matrix.rows * matrix.cols; i++)
		{
			fs >> matrix.pMatrix[i];
		}
		return fs;
	}

	//Allows to print out a matrix to a file.
	friend ofstream& operator<< (ofstream& fs, Matrix& matrix)
	{
		for(int i = 0; i < matrix.rows; i++)
		{
			for(int j = 0; j < matrix.cols; j++)
			{
				fs << matrix.pMatrix[i * matrix.cols + j] << " ";
			}
			fs << endl;
		}
		return fs;
	}
	
};

