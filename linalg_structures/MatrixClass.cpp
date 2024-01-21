#include "Matrix.hpp"

using namespace std;

int main()
{
	ofstream fin("output.txt");


	Matrix<int> A(3);

	cin >> A;

	fin << A;

	fin.close();
	return 0;
}
