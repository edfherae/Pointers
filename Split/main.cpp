#include <iostream>
using namespace std;

#define tab "\t"

int main()
{
	setlocale(LC_ALL, "");
	const int n = 10;
	int count_even = 0, count_odd = 0;
	int* arr = new int[n];
	for (int i = 0; i < n; i++)
	{
		*(arr + i) = rand() % 25;
		cout << *(arr + i) << tab;

		if (*(arr + i) % 2 == 0)
		{
			count_even++;
		}
		else if (*(arr + i) % 2 != 0)
		{
			count_odd++;
		}
	}
	cout << endl;

	int* even = new int[count_even];
	int* odd = new int[count_odd];
	for (int i = 0, ev = count_even, od = count_odd; i < n; i++)
	{
		if (*(arr + i) % 2 == 0)
		{
			even[ev - 1] = *(arr + i);
			ev--;
			cout << *(arr + i) << " is even\n";
		}
		else if (*(arr + i) % 2 != 0)
		{
			odd[od - 1] = *(arr + i);
			od--;
			cout << *(arr + i) << " is odd\n";
		}
	}

	cout << endl << "Even nums:\n";
	for (int i = 0; i < count_even; i++)
	{
		cout << *(even + i) << tab;
	}
	cout << endl << "Odd nums:\n";
	for (int i = 0; i < count_odd; i++)
	{
		cout << *(odd + i) << tab;
	}
	cout << endl;
}