#include <iostream>
#include <chrono>
using namespace std;
using std::cin;
using std::cout;
using std::endl;

#define tab "\t"

void FillRand(int* arr, const int n, int minRand = 0, int maxRand = 100);
void FillRand(double* arr, const int n, int minRand = 0, int maxRand = 100);
void FillRand(char* arr, const int n);
void FillRand(int** arr, const int rows, const int cols, int minRand = 0, int maxRand = 100);
void FillRand(double** arr, const int rows, const int cols, int minRand = 0, int maxRand = 100);
template<typename T> void Print(T arr[], const int n);
template<typename T> void Print(T** arr, const int rows, const int cols);
template<typename T> T* push_back(T* arr, int& n, T value);
template<typename T> T* push_front(T* arr, int& n, T value);
template<typename T> T* pop_back(T* arr, int& n);
template<typename T> T* pop_front(T* arr, int& n);
template<typename T> T* insert(T* arr, int& n, T value, int index);
template<typename T> T* erase(T* arr, int& n, int index);

template<typename T> T** Allocate(const int rows, const int cols);
template<typename T> void Clear(T** arr, const int rows);
template<typename T> T** push_row_front(T** arr, int& rows, const int cols);
template<typename T> T** push_row_back(T** arr, int& rows, const int cols);
template<typename T> T** insert_row(T** arr, int& rows, const int cols, const int index);
template<typename T> T** pop_row_back(T** arr, int& rows, const int cols);
template<typename T> T** pop_row_front(T** arr, int& rows, const int cols);
template<typename T> T** erase_row(T** arr, int& rows, const int cols, const int index);
template<typename T> void push_col_back(T** arr, const int rows, int& cols);
template<typename T> void push_col_front(T** arr, const int rows, int& cols);
template<typename T> void insert_col(T** arr, const int rows, int& cols, int index);
template<typename T> void pop_col_back(T** arr, const int rows, int& cols);
template<typename T> void pop_col_front(T** arr, const int rows, int& cols);
template<typename T> void erase_col(T** arr, const int rows, int& cols, int index);

//#define DYNAMIC_MEMORY_1
#define DYNAMIC_MEMORY_2
//#define DYNAMIC_MEMORY_3
//#define PREFORMANCE_CHECK_1DIM
//#define PREFORMANCE_CHECK_2DIM

int main()
{
	//auto start_time = std::chrono::steady_clock::now();

	setlocale(LC_ALL, "");
	srand(time(NULL));
#ifdef DYNAMIC_MEMORY_1
	int n;
	cout << "Введите размер массива "; cin >> n;
	typedef char DataType;
	DataType* arr = new DataType[n];

	FillRand(arr, n);
	Print(arr, n);

	int index;
	DataType value;
	cout << "Введите добавляемое в конец значение "; cin >> value;
	arr = push_back(arr, n, value);
	Print(arr, n);
	cout << "Введите добавляемое в начало значение "; cin >> value;
	arr = push_front(arr, n, value);
	Print(arr, n);
	cout << "Pop_back\n";
	arr = pop_back(arr, n);
	Print(arr, n);
	cout << "Pop_front\n";
	arr = pop_front(arr, n);
	Print(arr, n);
	cout << "Insert\nВведите добавляемое значение "; cin >> value;
	cout << "Введите индекс вставки значения "; cin >> index;
	arr = insert(arr, n, value, index);
	Print(arr, n);
	cout << "Erase\nВведите индекс удаления значения "; cin >> index;
	arr = erase(arr, n, index);
	Print(arr, n);

	delete[] arr;
#endif //DYNAMIC_MEMORY_1

#ifdef DYNAMIC_MEMORY_2
	int rows, cols, index;
	cout << "Введите количество строк "; cin >> rows;
	cout << "Введите количество элементов строки "; cin >> cols;
	typedef double DataType;

	DataType** arr = nullptr;
	arr = Allocate<DataType>(rows, cols);
	FillRand(arr, rows, cols);
	Print(arr, rows, cols);

	cout << "push_row_back\n";
	arr = push_row_back(arr, rows, cols);
	Print(arr, rows, cols);
	cout << "push_row_front\n";
	arr = push_row_front(arr, rows, cols);
	Print(arr, rows, cols);
	cout << "insert_row\n";
	cout << "Введите индекс: \n"; cin >> index;
	arr = insert_row(arr, rows, cols, index);
	Print(arr, rows, cols);
	cout << "pop_row_back\n";
	arr = pop_row_back(arr, rows, cols);
	Print(arr, rows, cols);
	cout << "pop_row_front\n";
	arr = pop_row_front(arr, rows, cols);
	Print(arr, rows, cols);
	cout << "erase_row\n";
	arr = erase_row(arr, rows, cols, index);
	Print(arr, rows, cols);
	cout << "push_col_back\n";
	push_col_back(arr, rows, cols);
	Print(arr, rows, cols);
	cout << "push_col_front\n";
	push_col_front(arr, rows, cols);
	Print(arr, rows, cols);

	Clear(arr, rows);

#endif //DYNAMIC_MEMORY_2

#ifdef DYNAMIC_MEMORY_3 //рассуждения (в процессе)
	//  можно ли пройтись по многомерным динамическим массивам, используя алгебру указателей?
	//  есть некий указатель на указатели int **Arr, инициализируем 4 указателя при помощи new int* [4] {};
	//  если имя массива (указатель) указывает всегда на первый элемент последовательности => *Arr содержит в себе адрес ячейки
	//памяти первого элемента последовательности (массива указателей), соответственно, чтобы получить доступ к следующему указателю (строке)
	//нужно прописать 
	int** Arr = new int* [4] {};
	cout << Arr << tab; //адрес указателя на указатели
	cout << *Arr << endl; //адрес первого указателя
	//cout << **Arr << tab;
	Arr = Allocate(4, 3);
	cout << Arr << tab;
	cout << *Arr << tab;
	cout << **Arr << tab;
#endif //DYNAMIC_MEMORY_3

#ifdef PREFORMANCE_CHECK_1DIM
	int n = 10000;
	typedef int DataType;
	DataType* arr = new DataType[n];

	FillRand(arr, n);
	Print(arr, n);

	arr = push_back(arr, n, 0);
	Print(arr, n);
	arr = push_front(arr, n, 0);
	Print(arr, n);
	arr = pop_back(arr, n);
	Print(arr, n);
	arr = pop_front(arr, n);
	Print(arr, n);
	arr = insert(arr, n, 0, 5000);
	Print(arr, n);
	arr = erase(arr, n, 5000);
	Print(arr, n);
	delete[] arr;
	// RESULTS:
	//10000 elem
	//not inline funcs -  9229328300 ns : 9.23 с
	//+inline print -     9089548900 ns : 9.09 с
#endif

#ifdef PREFORMANCE_CHECK_2DIM

	int rows = 10, cols = 10;

	typedef int DataType;
	DataType** arr = nullptr;
	arr = Allocate(arr, rows, cols);
	FillRand(arr, rows, cols);
	Print(arr, rows, cols);

	cout << arr[0] << endl;
	cout << *arr[0] << endl;
	pop_row_front(arr, rows, cols);
	cout << arr[0] << endl;
	cout << *arr[0] << endl;

	/*arr = push_row_front(arr, rows, cols);
	arr = insert_row(arr, rows, cols, 5000);
	pop_row_back(arr, rows, cols);
	arr = pop_row_front(arr, rows, cols);
	arr = erase_row(arr, rows, cols, 5000);
	push_col_back(arr, rows, cols);
	push_col_front(arr, rows, cols);
	insert_col(arr, rows, cols, 5000);
	pop_col_back(arr, rows, cols);
	pop_col_front(arr, rows, cols);
	erase_col(arr, rows, cols, 5000);*/

	Clear(arr, rows);
	// RESULTS:
	//25000 * 20000 elem
	//not inline funcs =  48285925000 ns : 48.28 с
	//all inline funcs =  48395628400 ns : 48.39 с
	//-inline funcs, i++ > (i += 1) =  48520427200 ns : 48.30 с
#endif
	//auto end_time = std::chrono::steady_clock::now();
	//auto elapsed_ns = std::chrono::duration_cast<std::chrono::nanoseconds>(end_time - start_time);
	//std::cout << elapsed_ns.count() << " ns\n";
}

void FillRand(int* arr, const int n, int minRand, int maxRand)
{
	for (int i = 0; i < n; i++)
		arr[i] = rand() % (maxRand - minRand) + minRand;
}
void FillRand(double* arr, const int n, int minRand, int maxRand)
{
	maxRand *= 100;
	minRand *= 100;
	for (int i = 0; i < n; i++)
	{
		arr[i] = rand() % (maxRand - minRand) + minRand;
		arr[i] /= 100;
	}
}
void FillRand(char* arr, const int n)
{
	for (int i = 0; i < n; i++)
		arr[i] = rand();
}
void FillRand(int** arr, const int rows, const int cols, int minRand, int maxRand)
{
	for (int i = 0; i < rows; i++)
		FillRand(arr[i], cols);
}
void FillRand(double** arr, const int rows, const int cols, int minRand, int maxRand)
{
	for (int i = 0; i < rows; i++)
		FillRand(arr[i], cols);
}
template<typename T> void Print(T arr[], const int n)
{
	for (int i = 0; i < n; i++)
		cout << arr[i] << tab;
	cout << endl;
}
template<typename T> void Print(T** arr, const int rows, const int cols)
{
	for (int i = 0; i < rows; i++)
	{
		Print(arr[i], cols);
	}
	cout << endl;
}
template<typename T> T* push_back(T* arr, int& n, T value) //должно вызывать insert
{
	// T = double*
	// T arr[] = double**
	T* buffer = new T[n + 1];
	for (int i = 0; i < n; i++)buffer[i] = arr[i];
	delete[] arr;
	buffer[n++] = value;
	return buffer;
}
template<typename T> T* push_front(T* arr, int& n, T value) //должно вызывать insert
{
	T* buffer = new T[n + 1];
	for (int i = 0; i < n; i++)
		buffer[i + 1] = arr[i];
	delete[] arr;
	buffer[0] = value;
	n++;
	return buffer;
}
template<typename T> T* pop_back(T* arr, int& n)
{
	T* buffer = new T[--n];
	for (int i = 0; i < n; i++) buffer[i] = arr[i];
	delete[] arr;
	return buffer;
}
template<typename T> T* pop_front(T* arr, int& n)
{
	T* buffer = new T[--n];
	for (int i = 0; i < n; i++) buffer[i] = arr[i + 1];
	delete[] arr;
	return buffer;
}
template<typename T> T* insert(T* arr, int& n, T value, int index)
{
	T* buffer = new T[++n];
	/*for (int i = 0; i < index; i++) buffer[i] = arr[i];
	buffer[index] = value;
	for (int i = index + 1; i < n; i++) buffer[i + 1] = arr[i];*/

	for (int i_buff = 0, i_arr = 0; i_buff < n; i_buff++)
	{
		if (i_buff != index)
			buffer[i_buff] = arr[i_arr++];
		else
			buffer[i_buff] = value;
	}
	delete[] arr;
	return buffer;
}
template<typename T> T* erase(T* arr, int& n, int index)
{
	T* buffer = new T[--n];
	/*for (int i = 0; i < n; i++)
		buffer[i] = arr[i < index ? i : i + 1];*/

	for (int i_buff = 0, i_arr = 0; i_buff < n;)
	{
		if (i_arr == index)
			i_arr++;
		else
			buffer[i_buff++] = arr[i_arr++];
	}
	delete[] arr;
	return buffer;
}

template<typename T> T** Allocate(const int rows, const int cols)
{
	T** buffer = new T * [rows] {};
	for (int i = 0; i < rows; i++)
		buffer[i] = new T[cols]{};
	return buffer;
}
template<typename T> void Clear(T** arr, const int rows)
{
	for (int i = 0; i < rows; i++)
		delete[] arr[i];
	delete[] arr;
	arr = nullptr;
}
template<typename T> T** push_row_front(T** arr, int& rows, const int cols) //
{
	return push_front(arr, rows, new T[cols]{});
	/*T** buffer = new T * [rows + 1] {};
	for (int i = 0; i < rows; i++) buffer[i + 1] = arr[i];
	delete[] arr;
	buffer[0] = new T[cols]{};
	rows++;
	return buffer;*/
}
template<typename T> T** push_row_back(T** arr, int& rows, const int cols) //за основу
{
	return push_back(arr, rows, new T[cols]{});
}

template<typename T> T** insert_row(T** arr, int& rows, const int cols, const int index) //
{
	return insert(arr, rows, new T[cols]{}, index);
	//T** buffer = new T* [rows + 1] {};
	//for (int i = 0; i < rows; i++)
	//{
	//	buffer[i < index ? i : i + 1] = arr[i];
	//	//if (i == index) temp++;
	//	//buffer[i + temp] = arr[i];
	//}
	//delete[] arr;
	//buffer[index] = new T[cols]{};
	//rows++;
	//return buffer;
}
template<typename T> T** pop_row_back(T** arr, int& rows, const int cols)
{
	delete[] arr[rows - 1];
	return pop_back(arr, rows);
}
//int** pop_row_front(int** arr, int& rows, const int cols)
//{
//    pop_row_back(arr, rows);
//}
template<typename T> T** pop_row_front(T** arr, int& rows, const int cols) //
{
	delete[] arr[0];
	return pop_front(arr, rows);
	/*T** buffer = new T * [--rows];
	for (int i = 0; i < rows; i++) buffer[i] = arr[i + 1];
	delete[] arr;
	return buffer;*/

	/*delete[] arr[0];
	rows--;
	*arr += 1;*/
}
template<typename T> T** erase_row(T** arr, int& rows, const int cols, const int index) //
{
	delete[] arr[index];
	return erase(arr, rows, index);
	/*T** buffer = new T * [--rows] {};
	for (int i = 0, temp = 0; i < rows; i++)
	{
		buffer[i] = arr[i < index ? i : i + 1];
	}
	delete[] arr;
	return buffer;*/
}
template<typename T> void push_col_back(T** arr, const int rows, int& cols)
{
	for (int i = 0; i < rows; i++)
	{
		//T() - значение по умолчанию для шаблонного типа
		arr[i] = push_back(arr[i], cols, T());
		cols--;
	}
	cols++;
}
template<typename T> void push_col_front(T** arr, const int rows, int& cols)
{
	for (int i = 0; i < rows; i++)
	{
		//T() - значение по умолчанию для шаблонного типа
		arr[i] = push_front(arr[i], cols, T());
		cols--;
	}
	cols++;
}
template<typename T> void insert_col(T** arr, const int rows, int& cols, int index)
{
	for (int i = 0; i < rows; i++)
	{
		T* buffer = new T[cols + 1]{};
		for (int j = 0, temp = 0; j < cols; j++)
			buffer[j < index ? j : j + 1] = arr[i][j];
		delete[] arr[i];
		arr[i] = buffer;
	}
	cols++;
}
template<typename T> void pop_col_back(T** arr, const int rows, int& cols)
{
	cols--;
	for (int i = 0; i < rows; i++)
	{
		T* buffer = new T[cols]{};
		for (int j = 0; j < cols; j++)
			buffer[j] = arr[i][j];
		delete[] arr[i];
		arr[i] = buffer;
	}
}
template<typename T> void pop_col_front(T** arr, const int rows, int& cols)
{
	cols--;
	for (int i = 0; i < rows; i++)
	{
		T* buffer = new T[cols]{};
		for (int j = 0; j < cols; j++)
			buffer[j] = arr[i][j + 1];
		delete[] arr[i];
		arr[i] = buffer;
	}
}
template<typename T> void erase_col(T** arr, const int rows, int& cols, int index)
{
	cols--;
	for (int i = 0; i < rows; i++)
	{
		T* buffer = new T[cols]{};
		for (int j = 0; j < cols; j++)
			buffer[j] = arr[i][j < index ? j : j + 1]; //!!!
		delete[] arr[i];
		arr[i] = buffer;
	}
}