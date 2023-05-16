//Lab8.2.c Сортування елементів в рядках згенерованого багатомірного масиву по зростанню за допомогою функцій
#define _CRT_SECURE_NO_WARNINGS
#include <locale.h>
#include <stdio.h>
#include <time.h>
#include <conio.h>
#include <math.h>

int Gener_Arr(const int N, const int M, const int Low, const int High);
void Out_Arr(int a[5][8], const int N, const int M);
int Sort_Arr(int a[5][8], const int N, const int M);
const int N = 5, M = 8, Low = -100, High = 100;
int a[5][8];

int main(void)
{
	setlocale(LC_CTYPE, "ukr");
	Gener_Arr(N, M, Low, High);
	printf("\n\t\t\t ЗГЕНЕРОВАНА МАТРИЦЯ: \n\n");
	Out_Arr(a, N, M);
	Sort_Arr(a, N, M);
	printf("\n\n\t ОТРИМАНИЙ РЕЗУЛЬТАТ СОРТУВАННЯ ЕЛЕМЕНТIВ В РЯДАХ ПО ЗРОСТАННЮ \n");
	printf("\n\t\t\t МАТРИЦЯ ПIСЛЯ СОРТУВАННЯ: \n\n");
	Out_Arr(a, N, M);

	int getch(); getch();
	return 0;
}

//Функція - генератор масиву розміром N випадковими числами від Low до High
int Gener_Arr(const int N, const int M, const int Low, const int High)
{
	srand(time(0));
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
			a[i][j] = Low + rand() % (High - Low);
	}
	return a;
}

//Функція виведення багатомірного масиву на екран розміром N, М
void Out_Arr(int a[5][8], const int N, const int M)
{
	for (int i = 0; i < N; i++)
	{
		if (i != (N - 1) / 2) printf("\t | ");
		if (i == (N - 1) / 2) printf(" A(%d,%d)= | ", N, M);
		for (int j = 0; j < M; j++)
			printf("%d\t", a[i][j]);
		printf("\b\b\b\b\b\b| \n");
	}
}

//Функція сортування рядків масиву по зростанню "Метод вставки"
int Sort_Arr(int a[5][8], const int N, const int M)
{
	int i, j, k, vert;
	for (i = 0; i < N; i++)
	{
		for (j = 1; j < M; j++)
		{
			vert = a[i][j];
			for (k = j; k > 0 && vert < a[i][k - 1]; k--)
				a[i][k] = a[i][k - 1];
			a[i][k] = vert;
		}
	}
	return a;
}
