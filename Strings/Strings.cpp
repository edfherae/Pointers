#include <iostream>
#include <sstream>
#include <string>
using namespace std;
#define tab "\t"

char* erase(char* arr, int& N, int index);
void to_lower(char* str, int N);
void to_upper(char* str, int N);
char* shrink(char* str, int& N);
bool is_palindrome(char* arr, int N);
bool is_int_number(char* arr, int N);
int to_int_number(char* arr, int N);

int main()
{
	setlocale(LC_ALL, "");
	int N = 6;
	//проблемы с заполнением массива вводом
	//{"qwerty"}
	char* str = new char[N] {'q','w',' ','w','q','\0'};
	cout << str << endl;
	//to_lower(str, N);
	str = shrink(str, N);
	cout << str << endl;
	to_upper(str, N);
	cout << str << endl;
	to_lower(str, N);
	cout << str << endl << is_palindrome(str, N) << endl;

	char* num = new char[5] {'0', '5', '7', '8', '\0'};
	cout << to_int_number(num, 5);
	cout << num << tab << is_int_number(num, N) << endl;

	//string name;
	//getline(cin, name);
	delete[] str;
}

char* erase(char* arr, int& N, int index)
{
	char* buffer = new char[--N] {};
	for (int i = 0; i < N; i++)
		buffer[i] = arr[i < index ? i : i + 1];
	delete[] arr;
	return buffer;
}
void to_lower(char* str, int N)
{
	for (int i = 0; i < N - 1; i++)
		if (str[i] <= 90 and str[i] >= 65)
			str[i] += 32;
}
void to_upper(char* str, int N)
{
	for (int i = 0; i < N - 1; i++)
		if (str[i] <= 122 and str[i] >= 97)
			str[i] -= 32;
}
char* shrink(char* arr, int& N)
{
	for (int i = 0; i < N; i++)
		if (arr[i] == 32)
			arr = erase(arr, N, i);
	return arr;
}
bool is_palindrome(char* arr, int N)
{
	bool palindrome = true;
	for (int i = 0, j = N - 1; (i < N / 2) and palindrome; i++, j--)
		if (arr[i] != arr[j - 1]) palindrome = false;
	return palindrome;
}
bool is_int_number(char* arr, int N)
{
	bool int_num = true;
	for (int i = 0; i < N - 1; i++)
		if (arr[i] < 48 or arr[i] > 57) int_num = false;
	return int_num;
}
int to_int_number(char* arr, int N)
{
	int sum = 0;
	if (!is_int_number) 
	{
		cout << "Число не типа int\n";
		return 0;
	}
	else
	{
		for (int i = N - 1, place = 1; i >= 0; i--, place *= 10)
			sum += arr[i] * place;
	}
	return sum;
}