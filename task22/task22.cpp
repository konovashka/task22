/*Дана квадратная матрица, найти сумму элементов на главной, побочной диагонали, выше главной, ниже главной*/

#include <iostream>
using namespace std;
int** memory(int n, int m);
void fill(int** a, int n, int m);
int main_Diagonal(int** a, int n);
int side_Diagonal(int** a, int n);
int under_main_Diagonal(int** a, int n);
int above_main_Diagonal(int** a, int n);
int main()
{
	int n;
	printf("vvedite razmer\n");
	scanf_s("%d", &n);
	int** A = memory(n, n);
	fill(A, n, n);
	printf("%d\n",main_Diagonal(A,n));
	printf("%d\n",side_Diagonal(A,n));
	printf("%d\n",above_main_Diagonal(A,n));
	printf("%d\n",under_main_Diagonal(A,n));
}

//выделение памяти
int** memory(int n, int m)
{
	int** a = new int* [n];
	for (int i = 0; i < n; i++)
	{
		a[i] = new int[m];
	}
	return a;
}
//заполнение элементов
void fill(int** a, int n, int m)
{
	printf("zapolnite massiv\n");
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			scanf_s("%d", &a[i][j]);
		}
	}
}
//сумма элементов на главной диагонали
int main_Diagonal(int** a, int n)
{
	int sum = 0;
	for (int i = 0; i < n; i++)
	{
		sum += a[i][i];
	}
	return sum;
}
//сумма элементов на побочной диагонали
int side_Diagonal(int** a, int n)
{
	int sum = 0;
	for (int i = n-1; i>=0; i--)
	{
		sum += a[i][n - 1 - i];
	}
	return sum;
}
//сумма элементов под главной диагональю
int under_main_Diagonal(int** a, int n)
{
	int sum = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < i; j++)
		{
			sum += a[i][j];
		}
	}
	return sum;
}
//сумма элементов выше главной диагонали
int above_main_Diagonal(int** a, int n)
{
	int sum = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = i+1; j < n; j++)
		{
			sum += a[i][j];
		}
	}
	return sum;
}