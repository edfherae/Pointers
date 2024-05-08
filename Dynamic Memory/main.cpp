#include <iostream>
using namespace std;

#define tab "\t"

void FillRand(int arr[], const int n);
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
int** insert_row(int** arr, int& rows, const int cols, const int index);
int** pop_row_back(int** arr, int& rows, const int cols);
int** pop_row_front(int** arr, int& rows, const int cols);
int** erase_row(int** arr, int& rows, const int cols, const int index);
int** push_col_back(int** arr, const int rows, int& cols);
int** push_col_front(int** arr, const int rows, int& cols);
int** insert_col(int** arr, const int rows, int& cols, int index);
int** pop_col_back(int** arr, const int rows, int& cols);
int** pop_col_front(int** arr, const int rows, int& cols);
int** erase_col(int** arr, const int rows, int& cols, int index);

//#define DYNAMIC_MEMORY_1
#define DYNAMIC_MEMORY_2
//#define DYNAMIC_MEMORY_3

int main()
{
    setlocale(LC_ALL, "");
    srand(time(NULL));
#ifdef DYNAMIC_MEMORY_1
    int n;
    cout << "¬ведите размер массива\n"; cin >> n;
    int* arr = new int[n];
    FillRand(arr, n);
    Print(arr, n);

    int value, index;
    cout << "¬ведите добавл€емое в конец значение "; cin >> value;
    arr = push_back(arr, n, value);
    Print(arr, n);
    cout << "¬ведите добавл€емое в начало значение "; cin >> value;
    arr = push_front(arr, n, value);
    Print(arr, n);
    cout << "Pop_back\n";
    arr = pop_back(arr, n);
    Print(arr, n);
    cout << "Pop_front\n";
    arr = pop_front(arr, n);
    Print(arr, n);
    cout << "Insert\n¬ведите добавл€емое значение "; cin >> value;
    cout << "¬ведите индекс вставки значени€ "; cin >> index;
    arr = insert(arr, n, value, index);
    Print(arr, n);
    cout << "Erase\n¬ведите индекс удалени€ значени€ "; cin >> index;
    arr = erase(arr, n, index);
    Print(arr, n);

    delete[] arr;
#endif //DYNAMIC_MEMORY_1

#ifdef DYNAMIC_MEMORY_2
    int rows, cols, index;
    cout << "¬ведите количество строк "; cin >> rows;
    cout << "¬ведите количество элементов строки "; cin >> cols;

    int** arr = Allocate(rows, cols);
    FillRand(arr, rows, cols);
    Print(arr, rows, cols);

    cout << "push_row_front\n";
    arr = push_row_front(arr, rows, cols);
    Print(arr, rows, cols);
    cout << "insert_row\n";
    cout << "¬ведите индекс вставки строки "; cin >> index;
    arr = insert_row(arr, rows, cols, index);
    Print(arr, rows, cols);
    cout << "pop_row_back\n";
    arr = pop_row_back(arr, rows, cols);
    Print(arr, rows, cols);
    cout << "pop_row_front\n";
    arr = pop_row_front(arr, rows, cols);
    Print(arr, rows, cols);
    cout << "erase_row\n";
    cout << "¬ведите индекс аннигилировани€ строки "; cin >> index;
    arr = erase_row(arr, rows, cols, index);
    Print(arr, rows, cols);
    cout << "push_col_back\n";
    arr = push_col_back(arr, rows, cols);
    Print(arr, rows, cols);
    cout << "push_col_front\n";
    arr = push_col_front(arr, rows, cols);
    Print(arr, rows, cols);
    cout << "insert_col\n";
    cout << "¬ведите индекс вставки столбика "; cin >> index;
    arr = insert_col(arr, rows, cols, index);
    Print(arr, rows, cols);
    cout << "pop_col_back\n";
    arr = pop_col_back(arr, rows, cols);
    Print(arr, rows, cols);
    cout << "pop_col_front\n";
    arr = pop_col_front(arr, rows, cols);
    Print(arr, rows, cols);
    cout << "erase_col\n";
    cout << "¬ведите индекс аннигилировани€ столбика "; cin >> index;
    arr = erase_col(arr, rows, cols, index);
    Print(arr, rows, cols);

    Clear(arr, rows);

#endif //DYNAMIC_MEMORY_2

#ifdef DYNAMIC_MEMORY_3 //рассуждени€ (в процессе)
    //  можно ли пройтись по многомерным динамическим массивам, использу€ алгебру указателей?
    //  есть некий указатель на указатели int **Arr, инициализируем 4 указател€ при помощи new int* [4] {};
    //  если им€ массива (указатель) указывает всегда на первый элемент последовательности => *Arr содержит в себе адрес €чейки
    //пам€ти первого элемента последовательности (массива указателей), соответственно, чтобы получить доступ к следующему указателю (строке)
    //нужно прописать 
    int **Arr = new int* [4] {};
    cout << Arr << tab; //адрес указател€ на указатели
    cout << *Arr << endl; //адрес первого указател€
    //cout << **Arr << tab;
    Arr = Allocate(4, 3);
    cout << Arr << tab;
    cout << *Arr << tab; 
    cout << **Arr << tab;
#endif //DYNAMIC_MEMORY_3
}

void FillRand(int arr[], const int n)
{
    for (int i = 0; i < n; i++)
    {
        arr[i] = rand() % 100;
    }
}
void FillRand(int** arr, const int rows, const int cols)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            arr[i][j] = rand() % 100;
        }
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
void Print(int** arr, const int rows, const int cols)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cout << arr[i][j] << tab;
        }
        cout << endl;
    }
    cout << endl;
}
int* push_back(int* arr, int& n, int value)
{
    int* buffer = new int[n + 1];
    for (int i = 0; i < n; i++)
    {
        buffer[i] = arr[i];
    }
    delete[] arr;
    arr = buffer;
    arr[n] = value;
    n++;
    return arr;
}
int* push_front(int* arr, int& n, int value)
{
    int* buffer = new int[n + 1];
    for (int i = 0; i < n; i++)
    {
        buffer[i + 1] = arr[i];
    }
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
}
int** push_row_front(int** arr, int& rows, const int cols)
{
    int** buffer = Allocate(rows + 1, cols);
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            buffer[i + 1][j] = arr[i][j];
        }
    }
    Clear(arr, rows++);
    return buffer;
}
int** insert_row(int** arr, int& rows, const int cols, const int index)
{
    int** buffer = Allocate(rows + 1, cols);
    for (int i_buff = 0, i_arr = 0; i_buff < rows + 1; i_buff++)
    {
        if (i_buff != index)
        {
            for (int j = 0; j < cols; j++)
                buffer[i_buff][j] = arr[i_arr][j];
            i_arr++;
        }
        else
            continue;
    }
    Clear(arr, rows++);
    return buffer;
}
int** pop_row_back(int** arr, int& rows, const int cols)
{
    int** buffer = Allocate(rows - 1, cols);
    for (int i = 0; i < rows - 1; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            buffer[i][j] = arr[i][j];
        }
    }
    Clear(arr, rows--);
    return buffer;
}
int** pop_row_front(int** arr, int& rows, const int cols)
{
    int** buffer = Allocate(rows - 1, cols);
    for (int i = 0; i < rows - 1; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            buffer[i][j] = arr[i + 1][j];
        }
    }
    Clear(arr, rows--);
    return buffer;
}
int** erase_row(int** arr, int& rows, const int cols, const int index)
{
    int** buffer = Allocate(rows - 1, cols);
    for (int i_buff = 0, i_arr = 0; i_buff < rows - 1; i_arr++)
    {
        if (i_arr != index)
        {
            for (int j = 0; j < cols; j++)
                buffer[i_buff][j] = arr[i_arr][j];
            i_buff++;
        }
        else
            continue;
    }
    Clear(arr, rows--);
    return buffer;
}
int** push_col_back(int** arr, const int rows, int& cols)
{
    int** buffer = Allocate(rows, ++cols);
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols - 1; j++)
        {
            buffer[i][j] = arr[i][j];
        }
    }
    Clear(arr, rows);
    return buffer;
}
int** push_col_front(int** arr, const int rows, int& cols)
{
    int** buffer = Allocate(rows, ++cols);
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols - 1; j++)
        {
            buffer[i][j + 1] = arr[i][j];
        }
    }
    Clear(arr, rows);
    return buffer;
}
int** insert_col(int** arr, const int rows, int& cols, int index)
{
    int** buffer = Allocate(rows, ++cols);
    for (int i = 0; i < rows; i++)
    {
        for (int j_buff = 0, j_arr = 0; j_buff < cols - 1; j_buff++)
        {
            if (j_buff == index)
                continue;
            else
                buffer[i][j_buff] = arr[i][j_arr++];
        }
    }
    Clear(arr, rows);
    return buffer;
}
int** pop_col_back(int** arr, const int rows, int& cols)
{
    int** buffer = Allocate(rows, --cols);
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            buffer[i][j] = arr[i][j];
        }
    }
    Clear(arr, rows);
    return buffer;
}
int** pop_col_front(int** arr, const int rows, int& cols)
{
    int** buffer = Allocate(rows, --cols);
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            buffer[i][j] = arr[i][j + 1];
        }
    }
    Clear(arr, rows);
    return buffer;
}
int** erase_col(int** arr, const int rows, int& cols, int index)
{
    int** buffer = Allocate(rows, --cols);
    for (int i = 0; i < rows; i++)
    {
        for (int j_buff = 0, j_arr = 0; j_buff < cols; j_arr++)
        {
            if (j_arr == index)
                continue;
            else
                buffer[i][j_buff++] = arr[i][j_arr];
        }
    }
    Clear(arr, rows);
    return buffer;
}