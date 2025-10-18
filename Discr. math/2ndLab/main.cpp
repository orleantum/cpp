#include <iostream>
#include <vector>
using namespace std;

bool isReflexive(const vector<vector<int>>& R) {
    for (int i = 0; i < R.size(); i++)
        if (R[i][i] != 1) return false;
    return true;
}

bool isAntiReflexive(const vector<vector<int>>& R) {
    for (int i = 0; i < R.size(); i++)
        if (R[i][i] != 0) return false;
    return true;
}

bool isSymmetric(const vector<vector<int>>& R) {
    for (int i = 0; i < R.size(); i++)
        for (int j = 0; j < R.size(); j++)
            if (R[i][j] != R[j][i]) return false;
    return true;
}

bool isAntiSymmetric(const vector<vector<int>>& R) {
    for (int i = 0; i < R.size(); i++)
        for (int j = 0; j < R.size(); j++)
            if (i != j && R[i][j] == 1 && R[j][i] == 1)
                return false;
    return true;
}

bool isAsymmetric(const vector<vector<int>>& R) {
    return isAntiReflexive(R) && isAntiSymmetric(R);
}

bool isTransitive(const vector<vector<int>>& R) {
    int n = R.size();
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (R[i][j])
                for (int k = 0; k < n; k++)
                    if (R[j][k] && !R[i][k])
                        return false;
    return true;
}

bool isConnected(const vector<vector<int>>& R) {
    int n = R.size();
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (i != j && R[i][j] == 0 && R[j][i] == 0)
                return false;
    return true;
}

int main() {
    setlocale(LC_ALL, "Russian");

    int n;
    cout << "Введите размер матрицы (например, 6): ";
    cin >> n;

    vector<vector<int>> R(n, vector<int>(n));
    cout << "Введите матрицу (" << n << "x" << n << "):\n";
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> R[i][j];

    cout << "\n=== Свойства отношения ===\n";

    bool reflexive = isReflexive(R);
    bool antireflexive = isAntiReflexive(R);
    bool symmetric = isSymmetric(R);
    bool antisymmetric = isAntiSymmetric(R);
    bool asymmetric = isAsymmetric(R);
    bool transitive = isTransitive(R);
    bool connected = isConnected(R);

    cout << "Рефлексивность: " << (reflexive ? "да" : "нет") << endl;
    cout << "Антирефлексивность: " << (antireflexive ? "да" : "нет") << endl;
    cout << "Симметричность: " << (symmetric ? "да" : "нет") << endl;
    cout << "Антисимметричность: " << (antisymmetric ? "да" : "нет") << endl;
    cout << "Асимметричность: " << (asymmetric ? "да" : "нет") << endl;
    cout << "Транзитивность: " << (transitive ? "да" : "нет") << endl;
    cout << "Связность: " << (connected ? "да" : "нет") << endl;

    if (reflexive && symmetric && transitive)
        cout << "\nЭто отношение эквивалентности." << endl;
    else if (reflexive && antisymmetric && transitive)
        cout << "\nЭто отношение порядка." << endl;

    return 0;
}
