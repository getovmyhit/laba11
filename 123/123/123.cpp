// ConsoleApplication1.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h" 
#include <omp.h>
#include <conio.h>
#include <intrin.h>
#include <stdlib.h>
#include <iostream> 
#include <time.h> 
using namespace std;
#include <iomanip> 



int main()
{

	
	int matrix[100][100], // статический массив 
		rows = 0, // строки 
		columns = 0; // столбцы 
	float time2;
	cout << "Vvedite kolvo strok matrici: ";
	cin >> rows;

	cout << "Vvedite kolvo stolbcov matrici: ";
	cin >> columns;

	// заполнение матрицы 
	for (int ix = 0; ix < rows; ix++)
		for (int jx = 0; jx < columns; jx++)
		{
			cout << "matrix[" << (ix + 1) << "][" << (jx + 1) << "] = ";
			cin >> matrix[ix][jx];
		}

	int vector[100]; // вектор 
	cout << "vvedite elementi vektora:\n";

	// заполнение вектора 
	for (int ix = 0; ix < columns; ix++)
	{
		cout << "vector[" << (ix + 1) << "] = ";
		cin >> vector[ix];
	}

	cout << "\nvvedennaya matrica:\n";
	for (int ix = 0; ix < rows; ix++)
	{
		for (int jx = 0; jx < columns; jx++)
		{
			cout << setw(4) << matrix[ix][jx];
		}
		cout << endl;
	}

	cout << "\nvvedenniy vector:\n";
	for (int ix = 0; ix < columns; ix++)
	{
		cout << setw(4) << vector[ix] << endl;
	}

	int out[100]; // выходной вектор 
	int m;
	cout << "\nVo skolko potokov vipolnit?:\n";
	cin >> m;
	//int par;
	//par = omp_get_thread_num(m);
	time2 = __rdtsc();
#pragma omp parallel 
	{
#pragma omp parallel for num_threads(m)
		for (int ix = 0; ix < rows; ix++)
		{
			out[ix] = 0;
			for (int jx = 0; jx < columns; jx++)
				out[ix] += matrix[ix][jx] * vector[jx];
		}

		{
			cout << " thread " << m << ' ' << omp_get_thread_num() << endl;
		}
	}
	time2 = __rdtsc() - time2;
	cout << "Time2: " << time2 / 1595400000 << " seconds" << "\n";
	cout << "\nrezult vektor:\n";
	for (int ix = 0; ix < rows; ix++)
	{
		cout << setw(4) << out[ix] << m << endl;
	}


	system("pause\n"); return 0;
}
