#include <iostream>
using namespace std;

//#define POINTERS_BASICS


void main()
{
	setlocale(LC_ALL, "");

#ifdef POINTERS_BASICS

int a = 2;
int* pa = &a;
cout << a << endl; //вывод значения переменной 'а' на экран
cout << &a << endl; //взятие адреса переменной 'а' прямо при выводе
cout << pa << endl; //вывод адреса переменной 'а', хранящегося в указателе 'pa'
cout << *pa << endl; //разыменование указателя 'pa' и вывод значения переменной 'a'

int* pb;
int b = 3;
pb = &b;
cout << pb;
//int = int
//int* = указатель на 'int'

#endif //POINTERS_BASICS

	const int n = 5;
	int arr[n] = { 1,2,3,4,5 };
	cout << arr << endl;
	cout << *arr << endl;
	for (int i = 0; i < n; i++)
	{
		cout << *(arr + i) << "\t"; //ход на 4 байта, т.к. массив типа int (4 байта)
	}
	cout << endl;
}