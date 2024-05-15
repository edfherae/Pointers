#include <iostream>
using namespace std;
using std::cin;
using std::cout;
using std::endl;

#define tab "\t"

void FillRand(int arr[], const int n, int minRand = 0, int maxRand = 100);
void FillRand(int** arr, const int rows, const int cols);
void Print(int arr[], const int n);
void Print(int** arr, const int rows, const int cols);
int* push_back(int* arr, int& n, int value);
int* push_front(int* arr, int& n, int value);
int* pop_back(int* arr, int& n);
int* pop_front(int* arr, int& n);
int* insert(int* arr, int& n, int value, int index);
int* erase(int* arr, int& n, int index);

int** Allocate(const int rows, const int cols);
void Clear(int** arr, const int rows);
int** push_row_front(int** arr, int& rows, const int cols);
int** push_row_back(int** arr, int& rows, const int cols);
int** insert_row(int** arr, int& rows, const int cols, const int index);
int** pop_row_back(int** arr, int& rows, const int cols);
int** pop_row_front(int** arr, int& rows, const int cols);
int** erase_row(int** arr, int& rows, const int cols, const int index);
void push_col_back(int** arr, const int rows, int& cols);
void push_col_front(int** arr, const int rows, int& cols);
void insert_col(int** arr, const int rows, int& cols, int index);
void pop_col_back(int** arr, const int rows, int& cols);
void pop_col_front(int** arr, const int rows, int& cols);
void erase_col(int** arr, const int rows, int& cols, int index);

//#define DYNAMIC_MEMORY_1
#define DYNAMIC_MEMORY_2
//#define DYNAMIC_MEMORY_3
//#define PREFORMANCE_CHECK

int main()
{
    setlocale(LC_ALL, "");
    srand(time(NULL));
#ifdef DYNAMIC_MEMORY_1
    int n;
    cout << "Введите размер массива\n"; cin >> n;
    int* arr = new int[n];
    FillRand(arr, n);
    Print(arr, n);

    int value, index;
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

    int** arr = Allocate(rows, cols);
    FillRand(arr, rows, cols);
    Print(arr, rows, cols);

    cout << "push_row_front\n";
    arr = push_row_front(arr, rows, cols);
    Print(arr, rows, cols);
    cout << "insert_row\n";
    cout << "Введите индекс вставки строки "; cin >> index;
    arr = insert_row(arr, rows, cols, index);
    Print(arr, rows, cols);
    cout << "pop_row_back\n";
    arr = pop_row_back(arr, rows, cols);
    Print(arr, rows, cols);
    cout << "pop_row_front\n";
    arr = pop_row_front(arr, rows, cols);
    Print(arr, rows, cols);
    cout << "erase_row\n";
    cout << "Введите индекс аннигилирования строки "; cin >> index;
    arr = erase_row(arr, rows, cols, index);
    Print(arr, rows, cols);
    cout << "push_col_back\n";
    push_col_back(arr, rows, cols);
    Print(arr, rows, cols);
    cout << "push_col_front\n";
    push_col_front(arr, rows, cols);
    Print(arr, rows, cols);
    cout << "insert_col\n";
    cout << "Введите индекс вставки столбика "; cin >> index;
    insert_col(arr, rows, cols, index);
    Print(arr, rows, cols);
    cout << "pop_col_back\n";
    pop_col_back(arr, rows, cols);
    Print(arr, rows, cols);
    cout << "pop_col_front\n";
    pop_col_front(arr, rows, cols);
    Print(arr, rows, cols);
    cout << "erase_col\n";
    cout << "Введите индекс аннигилирования столбика "; cin >> index;
    erase_col(arr, rows, cols, index);
    Print(arr, rows, cols);

    Clear(arr, rows);

#endif //DYNAMIC_MEMORY_2

#ifdef DYNAMIC_MEMORY_3 //рассуждения (в процессе)
    //  можно ли пройтись по многомерным динамическим массивам, используя алгебру указателей?
    //  есть некий указатель на указатели int **Arr, инициализируем 4 указателя при помощи new int* [4] {};
    //  если имя массива (указатель) указывает всегда на первый элемент последовательности => *Arr содержит в себе адрес ячейки
    //памяти первого элемента последовательности (массива указателей), соответственно, чтобы получить доступ к следующему указателю (строке)
    //нужно прописать 
    int **Arr = new int* [4] {};
    cout << Arr << tab; //адрес указателя на указатели
    cout << *Arr << endl; //адрес первого указателя
    //cout << **Arr << tab;
    Arr = Allocate(4, 3);
    cout << Arr << tab;
    cout << *Arr << tab; 
    cout << **Arr << tab;
#endif //DYNAMIC_MEMORY_3

#ifdef PREFORMANCE_CHECK
    int rows, cols;
    cout << "Введите количество строк: "; cin >> rows;
    cout << "Введите количество элементов строки: "; cin >> cols;

    int** arr = Allocate(rows, cols);
    FillRand(arr, rows, cols);
    Print(arr, rows, cols);
    //pop_row_front(arr, rows, cols); Есть вопросик в реализации
    Print(arr + 1, rows - 1, cols);


    Clear(arr, rows);
#endif
}

void FillRand(int arr[], const int n, int minRand, int maxRand)
{
    for (int i = 0; i < n; i++)
        arr[i] = rand() % (maxRand - minRand) + minRand;
}
void FillRand(int** arr, const int rows, const int cols)
{
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            arr[i][j] = rand() % 100;
}
void Print(int arr[], const int n)
{
    for (int i = 0; i < n; i++)
        cout << arr[i] << tab;
    cout << endl;
}
void Print(int** arr, const int rows, const int cols)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
            cout << arr[i][j] << tab;
        cout << endl;
    }
    cout << endl;
}
int* push_back(int* arr, int& n, int value)
{
    int* buffer = new int[n + 1];
    for (int i = 0; i < n; i++)
        buffer[i] = arr[i];
    delete[] arr;
    arr = buffer;
    arr[n++] = value;
    return arr;
}
int* push_front(int* arr, int& n, int value)
{
    int* buffer = new int[n + 1];
    for (int i = 0; i < n; i++)
        buffer[i + 1] = arr[i];
    delete[] arr;
    arr = buffer;
    arr[0] = value;
    n++;
    return arr;
}
int* pop_back(int* arr, int& n)
{
    int* buffer = new int[--n];
    for (int i = 0; i < n; i++) buffer[i] = arr[i];
    delete[] arr;
    return buffer;
}
int* pop_front(int* arr, int& n)
{
    int* buffer = new int[--n];
    for (int i = 0; i < n; i++) buffer[i] = arr[i + 1];
    delete[] arr;
    return buffer;
}
int* insert(int* arr, int& n, int value, int index)
{
    int* buffer = new int[++n];
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
int* erase(int* arr, int& n, int index)
{
    int* buffer = new int[--n];
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

int** Allocate(const int rows, const int cols)
{
    int** buffer = new int* [rows] {};
    for (int i = 0; i < rows; i++)
        buffer[i] = new int[cols] {};
    return buffer;
}
void Clear(int** arr, const int rows)
{
    for (int i = 0; i < rows; i++)
        delete[] arr[i];
    delete[] arr;
    arr = nullptr;
}
int** push_row_front(int** arr, int& rows, const int cols)
{
    int** buffer = new int* [rows + 1] {};
    for (int i = 0; i < rows; i++) buffer[i + 1] = arr[i];
    delete[] arr;
    buffer[0] = new int [cols] {};
    rows++;
    return buffer;
}

int** push_row_back(int** arr, int& rows, const int cols) //за основу
{
    //1) создаем буферный массив указателей нужного размера
    int** buffer = new int* [rows + 1] {};
    //2) копируем строки из исходного массива в массив указателей
    for (int i = 0; i < rows; i++) buffer[i] = arr[i];
    //3) удаляем исходный массив указателей
    delete[] arr;
    //4) создаем строку и добавляем ее в массив
    buffer[rows] = new int[cols] {};
    //5) после добавления строки в массив, количество его строк увеличивается
    rows++;
    return buffer;
}

int** insert_row(int** arr, int& rows, const int cols, const int index)
{
    int** buffer = new int* [++rows] {};
    for (int i = 0, temp = 0; i < rows - 1; i++)
    {
        if (i == index) temp++;
        buffer[i + temp] = arr[i];
    }
    delete[] arr;
    buffer[index] = new int[cols] {};
    return buffer;
}
int** pop_row_back(int** arr, int& rows, const int cols) //за основу
{
    int** buffer = new int* [--rows];//переопределяем массив указателей
    for (int i = 0; i < rows; i++) buffer[i] = arr[i]; //копируем указатели на строки в новый массив
    delete[] arr[rows]; //удаляем удаляемую строку из памяти
    delete[] arr;
    return buffer;
}
//void pop_row_back(int** arr, int& rows, const int cols) //Error Heap Corruption
//{
//    delete[] arr[rows - 1];
//    rows--;
//}
//int** pop_row_front(int** arr, int& rows, const int cols)
//{
//    pop_row_back(arr, rows);
//}
int** pop_row_front(int** arr, int& rows, const int cols)
{
    int** buffer = new int* [--rows];
    for (int i = 0; i < rows + 1; i++) buffer[i] = arr[i + 1];
    delete[] arr;
    return buffer;
    /*delete[] arr[0];
    rows--;
    arr += 1;*/
}
int** erase_row(int** arr, int& rows, const int cols, const int index)
{
    int** buffer = new int* [--rows] {};
    for (int i = 0, temp = 0; i < rows + 1; i++)
    {
        if (i == index) temp++;
        buffer[i] = arr[i + temp];
    }
    delete[] arr;
    return buffer;
}
void push_col_back(int** arr, const int rows, int& cols)
{
    for (int i = 0; i < rows; i++)
    {
        int* buffer = new int[cols + 1] {};
        for (int j = 0; j < cols; j++)
            buffer[j] = arr[i][j];
        delete[] arr[i];
        arr[i] = buffer;
    }
    cols++;
}
void push_col_front(int** arr, const int rows, int& cols)
{
    for (int i = 0; i < rows; i++)
    {
        int* buffer = new int[cols + 1] {}; //int* - строка, int** - массив указаьелей
        for (int j = 0; j < cols; j++)
            buffer[j + 1] = arr[i][j];
        delete[] arr[i];
        arr[i] = buffer;
    }
    cols++;
}
void insert_col(int** arr, const int rows, int& cols, int index)
{
    for (int i = 0; i < rows; i++)
    {
        int* buffer = new int[cols + 1] {};
        for (int j = 0, temp = 0; j < cols; j++)
        {
            if (j == index) temp++;
            buffer[j + temp] = arr[i][j];

            //if (buff_j == index) buff_j++;
            //else buffer[buff_j++] = arr[i][arr_j++];
        }
        delete[] arr[i];
        arr[i] = buffer;
    }
    cols++;
}
void pop_col_back(int** arr, const int rows, int& cols)
{
    cols--;
    for (int i = 0; i < rows; i++)
    {
        int* buffer = new int [cols] {};
        for (int j = 0; j < cols; j++)
            buffer[j] = arr[i][j];
        delete[] arr[i];
        arr[i] = buffer;
    }
}
void pop_col_front(int** arr, const int rows, int& cols)
{
    cols--;
    for (int i = 0; i < rows; i++)
    {
        int* buffer = new int [cols] {};
        for (int j = 0; j < cols; j++)
            buffer[j] = arr[i][j + 1];
        delete[] arr[i];
        arr[i] = buffer;
    }
}
void erase_col(int** arr, const int rows, int& cols, int index)
{
    cols--;
    for (int i = 0; i < rows; i++)
    {
        int* buffer = new int [cols] {};
        for (int j = 0, temp = 0; j < cols; j++)
        {
            if (j == index) temp++;
            buffer[j] = arr[i][j + temp];
        }
        delete[] arr[i];
        arr[i] = buffer;
    }
}