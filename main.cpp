#include <iostream>
using namespace std;

//#define POINTERS_BASICS


void main()
{
	setlocale(LC_ALL, "");

#ifdef POINTERS_BASICS

int a = 2;
int* pa = &a;
cout << a << endl; //����� �������� ���������� '�' �� �����
cout << &a << endl; //������ ������ ���������� '�' ����� ��� ������
cout << pa << endl; //����� ������ ���������� '�', ����������� � ��������� 'pa'
cout << *pa << endl; //������������� ��������� 'pa' � ����� �������� ���������� 'a'

int* pb;
int b = 3;
pb = &b;
cout << pb;
//int = int
//int* = ��������� �� 'int'

#endif //POINTERS_BASICS

	const int n = 5;
	int arr[n] = { 1,2,3,4,5 };
	cout << arr << endl;
	cout << *arr << endl;
	for (int i = 0; i < n; i++)
	{
		cout << *(arr + i) << "\t"; //��� �� 4 �����, �.�. ������ ���� int (4 �����)
	}
	cout << endl;
}