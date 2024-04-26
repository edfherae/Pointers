#include <iostream>
using namespace std;

#define tab "\t"

void FillRand(int arr[], const int n);
void Print(int arr[], const int n);

int main()
{
	setlocale(LC_ALL, "");
	const int n = 10;
	int count_even = 0, count_odd = 0;
	int* arr = new int[n];
	FillRand(arr, n);
	Print(arr, n);
	for (int i = 0; i < n; i++)
	{
		(*(arr + i) % 2 == 0) ? count_even++ : count_odd++;
	}

	int* even = new int[count_even];
	int* odd = new int[count_odd];
	for (int i = 0, ev = count_even - 1, od = count_odd - 1; i < n; i++)
	{
		if (*(arr + i) % 2 == 0)
		{
			even[ev] = *(arr + i);
			ev--;
		}
		else if (*(arr + i) % 2 != 0)
		{
			odd[od] = *(arr + i);
			od--;
		}
	}

	cout << endl << "Even nums:\n";
	Print(even, count_even);
	cout << endl << "Odd nums:\n";
	Print(odd, count_odd);

	delete[] even;
	delete[] odd;
	delete[] arr;
}

void FillRand(int arr[], const int n)
{
	for (int i = 0; i < n; i++)
	{
		arr[i] = rand() % 100;
	}
}

void Print(int arr[], const int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << tab;
	}
	cout << endl;
}