#include <iostream>
using namespace std;

#define tab "\t"

int main()
{
    setlocale(LC_ALL, "");
    int n;
    cout << "¬ведите размер массива\n"; cin >> n;
    int* arr = new int[n];
    for (size_t i = 0; i < n; i++)
    {
        *(arr + i) = rand() % 100;
    }
    cout << endl;

    for (size_t i = 0; i < n; i++)
    {
        cout << arr[i] << tab;
    }
    cout << endl;

    delete[] arr;
}