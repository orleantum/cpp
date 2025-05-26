#include <stdexcept>
#include <iostream>

using namespace std;

template <class T> class Vector;

// Предварительные объявления дружественных функций
template <class T> // T - параметр шаблона
ostream& operator<<(ostream& out, const Vector<T>& a);

template <class T>
istream& operator>>(istream& in, Vector<T>& a);

template <class T>
class Vector
{
public:
    // Конструктор с параметрами: выделяет память под s элементов и заполняет их значением k
    Vector(int s, T k);
    Vector(const Vector<T>&a); // Конструктор с параметрами
    ~Vector(); // Деструктор

    Vector&operator=(const Vector<T>&a); // Оператор присваивания
    T&operator[](int index); // Доступ по индексу +
    Vector operator+(const T k); // Добавление константы +
    int operator()(); // Оператор, возвращающий длину вектора +
    
    // Перегруженные операции ввода-вывода
    // <> — указывает на то, что функция является шаблоном
    friend ostream& operator<< <>(ostream& out, const Vector<T>&a);
    friend istream& operator>> <>(istream& in, Vector<T>&a);
    
private:
    int size; // размер вектора
    T*data; // указатель на динамический массив значений вектора
};

// определение функций
template <class T>
Vector<T>::Vector(int s, T k)
{
    size = s;
    data = new T[size];
    for (int i = 0; i < size; ++i)
        data[i] = k;
}

// конструктор с параметрами
template <class T>
Vector<T>::Vector(const Vector&a)
{
    size = a.size;
    data = new T[size];
    for (int i = 0; i < size; i++)
        data[i] = a.data[i];
}

// деструктор
template <class T>
Vector<T>::~Vector()
{
    delete[] data;
    data = 0;
}

// операция присваивания
template <class T>
Vector<T>&Vector<T>::operator=(const Vector<T>&a)
{
    if (this == &a) return *this;
    size = a.size;
    if (data != 0) delete[] data;
    data = new T[size];
    for (int i = 0; i < size; i++)
        data[i] = a.data[i];
    return *this;
}

// Операция доступа по индексу
template <class T>
T&Vector<T>::operator[](int index)
{
    if (index >= 0 && index < size)
        return data[index];
    else {
        throw std::out_of_range("Vector index out of bounds");
    }
}

// Операция для добавления константы
template <class T>
Vector<T> Vector<T>::operator+(const T k) // +k
{
    Vector<T> temp(size, k); // инициализируем
    for (int i = 0; i < size; ++i)
        temp.data[i] = data[i] + k;
    return temp;
}

// Операция для получения длины вектора
template <class T>
int Vector<T>::operator()()
{
    return size;
}

// Операции для ввода-вывода
template <class T>
ostream& operator<<(ostream&out, const Vector<T>&a)
{
    for (int i = 0; i < a.size; ++i)
        out << a.data[i] << " ";
    return out;
}

template <class T>
istream& operator>>(istream& in, Vector<T>& a)
{
    for (int i = 0; i < a.size; ++i)
        in >> a.data[i];  // читаем значение
    return in;
}
