#include <iostream>
#include <string>
#include <cctype>
#include <cstdlib>
#include <ctime>

// ===== вспомогательные функции =====

// Проверка, есть ли значение value в массиве array длиной n
bool exists(int array[], int n, int value) {
    for (int i = 0; i < n; i++) if (array[i] == value) return true;
    return false;
}

// Печать массива в фигурных скобках
void print_array(int array[], int n) {
    std::cout << "{ ";
    for (int i = 0; i < n; i++) std::cout << array[i] << " ";
    std::cout << "}" << std::endl;
}


// ===== операции множеств =====

// Объединение множеств: A ∪ B
int* union_set(int* a, int na, int* b, int nb, int& nr) {
    int* r = new int[na + nb]; nr = 0;
    for (int i = 0; i < na; i++) r[nr++] = a[i];
    for (int j = 0; j < nb; j++)
        if (!exists(r, nr, b[j])) r[nr++] = b[j];
    return r;
}

// Пересечение множеств: A ∩ B
int* intersect_set(int* a, int na, int* b, int nb, int& nr) {
    int* r = new int[na < nb ? na : nb]; nr = 0;
    for (int i = 0; i < na; i++)
        if (exists(b, nb, a[i])) r[nr++] = a[i];
    return r;
}

// Разность множеств: A \ B
int* diff_set(int* a, int na, int* b, int nb, int& nr) {
    int* r = new int[na]; nr = 0;
    for (int i = 0; i < na; i++)
        if (!exists(b, nb, a[i])) r[nr++] = a[i];
    return r;
}

// Симметрическая разность: (A \ B) ∪ (B \ A)
int* sym_diff_set(int* a, int na, int* b, int nb, int& nr) {
    int* r1; int n1;
    r1 = diff_set(a, na, b, nb, n1);
    int* r2; int n2;
    r2 = diff_set(b, nb, a, na, n2);
    int* r = union_set(r1, n1, r2, n2, nr);
    delete[] r1; delete[] r2;
    return r;
}

// Дополнение множества: -A (относительно [-30;30])
int* complement_set(int* a, int na, int& nr) {
    nr = 0;
    int* r = new int[61]; // все числа [-30;30]
    for (int x = -30; x <= 30; x++)
        if (!exists(a, na, x)) r[nr++] = x;
    return r;
}


// ===== массивы =====
int *arrA = nullptr, *arrB = nullptr, *arrC = nullptr;
int sizeA = 0, sizeB = 0, sizeC = 0;


// ===== парсер выражений =====
struct Token {
    char type; // 'A','B','C','(',')','U','I','D','S','N','\0'
};

std::string expr; // строка с выражением
int pos=0; // текущая позиция в строке
Token cur; // текущий токен

// Лексический анализ: выделяем токены по символам
Token get_token() {
    while (pos < (int)expr.size() && isspace(expr[pos])) pos++;
    if (pos >= (int)expr.size()) return {'\0'};
    char c = expr[pos++];
    switch(c) {
        case 'A': case 'B': case 'C':
        case '(': case ')':
        case 'u': case 'i': case 'd': case 's': case '-':
            return {c};
    }
    throw std::runtime_error(std::string("Неизвестный символ: ") + c);
}
void next() { cur = get_token(); }

int* parse_expr(int& n); // объявление вперёд

// factor = A|B|C|(expr)|N factor
int* parse_factor(int& n) {
    if (cur.type == 'A') {
        next(); n = sizeA; int* r = new int[n];
        for (int i=0;i<n;i++) r[i]=arrA[i];
        return r;
    }
    if (cur.type == 'B') {
        next(); n = sizeB; int* r = new int[n];
        for (int i=0;i<n;i++) r[i]=arrB[i];
        return r;
    }
    if (cur.type == 'C') {
        next(); n = sizeC; int* r = new int[n];
        for (int i=0;i<n;i++) r[i]=arrC[i];
        return r;
    }
    if (cur.type == '(') {
        next();
        int* r = parse_expr(n);
        if (cur.type != ')') throw std::runtime_error("Ожидалась )");
        next();
        return r;
    }
    if (cur.type == '-') { // дополнение
        next();
        int n1; int* x = parse_factor(n1);
        int* r = complement_set(x, n1, n);
        delete[] x;
        return r;
    }
    throw std::runtime_error("Ожидался фактор");
}

// term = factor { ∩ factor }
int* parse_term(int& n) {
    int* left = parse_factor(n);
    while (cur.type == 'i') {
        next();
        int n2; int* right = parse_factor(n2);
        int* res = intersect_set(left, n, right, n2, n);
        delete[] left; delete[] right;
        left = res;
    }
    return left;
}

// expr = term { (∪|Δ|\\) term }
int* parse_expr(int& n) {
    int* left = parse_term(n);
    while (cur.type=='u' || cur.type=='s' || cur.type=='d') {
        char op = cur.type;
        next();
        int n2; int* right = parse_term(n2);
        int* res=nullptr;
        switch(op) {
            case 'u': res = union_set(left, n, right, n2, n); break;
            case 's': res = sym_diff_set(left, n, right, n2, n); break;
            case 'd': res = diff_set(left, n, right, n2, n); break;
        }
        delete[] left; delete[] right;
        left = res;
    }
    return left;
}


// ===== заполнение вручную =====
void manual(int array[], int n) {
    std::cout << "Диапазон допустимых значений [-30 ; 30]\n";
    for (int i = 0; i < n; i++) {
        int x;
        while (true) {
            std::cout << "Элемент " << i+1 << ": ";
            std::cin >> x;
            if (x < -30 || x > 30) {
                std::cout << "Ошибка! Допустимо только [-30;30]\n";
                continue;
            }
            if (exists(array, i, x)) {
                std::cout << "Ошибка! Такое значение уже введено. Введите другое.\n";
                continue;
            }
            break; // корректный ввод
        }
        array[i] = x;
    }
}


// ===== заполнение случайно =====
void randomize(int array[], int n) {
    for (int i = 0; i < n; i++) {
        int x;
        do {
            x = rand() % 61 - 30; // [-30;30]
        } while (exists(array, i, x)); // исключаем повторы
        array[i] = x;
    }
    std::cout << "Массив заполнен случайно.\n";
}


// ===== заполнение по условию =====
void conditions(int array[], int n) {
    std::cout << "Выберите условие:\n"
              << "1 - Только положительные\n"
              << "2 - Только отрицательные\n"
              << "3 - Только чётные\n"
              << "4 - Только нечётные\n"
              << "5 - Кратные числу k\n"
              << "Ваш выбор: ";
    int choice; std::cin >> choice;

    int k = 1;
    if (choice == 5) {
        std::cout << "Введите число k: ";
        std::cin >> k;
        if (k == 0) { std::cout << "Ошибка! k не может быть 0.\n"; return; }
    }

    int i = 0;
    while (i < n) {
        int x = rand() % 61 - 30; // [-30;30]
        bool ok = false;

        switch(choice) {
            case 1: ok = (x > 0); break;
            case 2: ok = (x < 0); break;
            case 3: ok = (x % 2 == 0); break;
            case 4: ok = (x % 2 != 0); break;
            case 5: ok = (x % k == 0); break;
        }

        if (ok && !exists(array, i, x)) {
            array[i++] = x;
        }
    }
    std::cout << "Массив заполнен по условию.\n";
}


// ===== инициализация массива =====
void array_init(int*& array, int& size) {
    std::cout << "Введите размер: ";
    std::cin >> size;
    if (size > 61) { std::cout << "Слишком большой!\n"; size = 0; return; }

    delete[] array;
    array = new int[size];

    std::cout << "Выберите способ заполнения:\n"
              << "1 - Вручную\n"
              << "2 - Случайно\n"
              << "3 - По условию\n"
              << "Ваш выбор: ";
    int mode; std::cin >> mode;

    switch (mode) {
        case 1: manual(array, size); break;
        case 2: randomize(array, size); break;
        case 3: conditions(array, size); break;
        default: std::cout << "Ошибка выбора!\n"; return;
    }

    std::cout << "Итоговый массив: ";
    print_array(array, size);
}


// ===== вычисление выражения =====
void calc_expr() {
    std::cin.ignore();
    std::cout << "\nДоступные операции:\n"
              << "u  - объединение (A u B)\n"
              << "i  - пересечение (A i B)\n"
              << "d  - разность (A d B)\n"
              << "s  - симметрическая разность (A s B)\n"
              << "-  - дополнение (- A)\n"
              << "Можно использовать скобки: (A u B) i n C\n\n";

    std::cout << "Введите выражение: ";
    std::getline(std::cin, expr);

    pos = 0;
    next();
    int n;
    int* res = parse_expr(n);

    if (cur.type != '\0')
        std::cout << "Лишние символы в выражении!\n";

    std::cout << "Результат: ";
    print_array(res, n);
    delete[] res;
}


// ===== меню =====
void menu() {
    while (true) {
        std::cout << "\nМеню:"
                  << "\n1 - Массив A"
                  << "\n2 - Массив B"
                  << "\n3 - Массив C"
                  << "\n4 - Вычислить выражение"
                  << "\n0 - Выход"
                  << "\nВаш выбор: ";
        int ch; std::cin >> ch;

        if (ch == 0) break;

        if (ch >= 1 && ch <= 3) {
            int*& arr = (ch == 1 ? arrA : (ch == 2 ? arrB : arrC));
            int& size = (ch == 1 ? sizeA : (ch == 2 ? sizeB : sizeC));

            if (size == 0) {
                std::cout << "Массив ещё не создан. Создать? (1 - да, 0 - нет): ";
                int create; std::cin >> create;
                if (create == 1) array_init(arr, size);
            } else {
                std::cout << "Массив уже существует. Действия:\n"
                          << "1 - Вывести массив\n"
                          << "2 - Пересоздать массив\n"
                          << "Ваш выбор: ";
                int action; std::cin >> action;
                if (action == 1) {
                    std::cout << "Текущий массив: ";
                    print_array(arr, size);
                } else if (action == 2) {
                    array_init(arr, size);
                }
            }
        }
        else if (ch == 4) {
            calc_expr();
        }
        else {
            std::cout << "Ошибка выбора!\n";
        }
    }
}


// ===== main =====
int main() {
    std::srand(std::time(nullptr));
    menu();
    delete[] arrA; delete[] arrB; delete[] arrC;
    return 0;
}
