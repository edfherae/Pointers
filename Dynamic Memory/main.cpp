#include <iostream>
using namespace std;

#define tab "\t"

void FillRand(int arr[], const int n);
void Print(int arr[], const int n);

int main()
{
    setlocale(LC_ALL, "");
    srand(time(NULL));
    int n;
    cout << "¬ведите размер массива\n"; cin >> n;
    int* arr = new int[n];
    FillRand(arr, n);
    Print(arr, n);

    int* temp_arr = new int[n];
    for (int i = 0; i < n; i++)
    {
        temp_arr[i] = arr[i];
    }

    int value;
    cout << "¬ведите некое целое число "; cin >> value;

    delete[] arr;
    arr = new int[n + 1];

    for (int i = 0; i < n; i++)
    {
        arr[i] = temp_arr[i];
    }
    arr[n] = value;
    n++;
    Print(arr, n);

    delete[] arr;
    delete[] temp_arr;
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