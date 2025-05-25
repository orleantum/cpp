#include "Vector.h"
#include "Error.h"

Vector::Vector(int s)
{
    //если текущий размер больше максимального, то генерируется исключение
    if (s > MAX_SIZE) throw 1;
    size = s;
    beg = new int [s];
    for(int i = 0; i < size; i++)
        beg[i] = 0;
}

Vector::Vector(const Vector& v)
{
    size = v.size;
    beg = new int [size];
    for(int i = 0; i < size; i++)
        beg[i] = v.beg[i];
}

Vector::~Vector()
{
    if (beg != 0) delete[]beg;
}

Vector::Vector(int s, int *mas)
{
//если текущий размер больше максимального, то генерируется исключение
    if(s > MAX_SIZE) throw 1;
    size = s;
    beg = new int[size];
    for(int i = 0; i < size; i++)
        beg[i] = mas[i];
}

const Vector& Vector::operator=(const Vector& v)
{
    if(this == &v)return *this;
    if(beg != 0) delete[] beg;
    size = v.size;
    beg = new int [size];
    for(int i = 0; i < size; i++)
        beg[i] = v.beg[i];
    
    return *this;
}

std::ostream& operator<<(std::ostream& out, const Vector& v)
{
    if(v.size == 0) out << "Empty\n";
    else
    {
        for (int i = 0; i < v.size; i++)
            out << v.beg[i] << " ";
        out << std::endl;
    }
    
    return out;
}

std::istream& operator>>(std::istream& in, Vector& v)
{
    for (int i = 0; i < v.size; i++)
    {
        std::cout << ">";
        in >> v.beg[i];
    }
    
    return in;
}

int Vector::operator[](int i)
{
    if (i < 0) throw 2;//если индекс отрицательный, то генерируется исключение
    //если индекс больше размер вектора, то генерируется исключение
    if( i >= size) throw error("Vector length more than MAXSIZE\n");
    
    return beg[i];
}

Vector Vector::operator--()
{
    //если вектор пустой, то удалить элемент нельзи и генерируется исключение
    if (size == 0) throw 5;
    if (size == 1) //если в вектор один элемент
    {
        size = 0;
        delete[] beg;
        beg = 0;
        return *this;
    };
    
    Vector temp(size, beg);
    delete[] beg;
    size--;
    beg = new int[size];
    for(int i = 0; i < size; i++)
        beg[i] = temp.beg[i];

    return* this;
}

// Операция () — возвращает размер вектора
int Vector::operator()() const {
    return size;
}

// Операция + число — прибавляет ко всем элементам вектора
Vector Vector::operator+(int value) const {
    Vector temp(size);
    for (int i = 0; i < size; ++i)
        temp.beg[i] = beg[i] + value;
    return temp;
}

// Операция - n — удаляет n элементов с конца
Vector Vector::operator-(int n) const {
    if (n > size) throw error("Too many elements to remove");
    Vector temp(size - n);
    for (int i = 0; i < temp.size; ++i)
        temp.beg[i] = beg[i];
    return temp;
}
