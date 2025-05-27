#include <iostream>
#include <fstream>
#include <string>
#include <ctime>

using namespace std;

const int MAX_K = 10;

void merge(const string& output, const string& input1, const string& input2) {

    ifstream in1(input1), in2(input2);
    ofstream out(output);

    int val1, val2;
    bool hasVal1 = !!(in1 >> val1), hasVal2 = !!(in2 >> val2);

    while (hasVal1 && hasVal2) {
        if (val1 <= val2) {
            out << val1 << endl;
            hasVal1 = !!(in1 >> val1);
        } else {
            out << val2 << endl;
            hasVal2 = !!(in2 >> val2);
        }
    }

    while (hasVal1) { out << val1 << endl; hasVal1 = !!(in1 >> val1); }
    while (hasVal2) { out << val2 << endl; hasVal2 = !!(in2 >> val2); }

    in1.close(); in2.close(); out.close();
}

void distribute(const string& input, string tapes[], int tapeCount) {
    ifstream in(input);
    ofstream outs[MAX_K];

    for (int i = 0; i < tapeCount; i++) {
        outs[i].open(tapes[i]);
    }

    int current, next;
    if (!(in >> current)) return;

    int tapeIdx = 0;
    outs[tapeIdx] << current << endl;

    while (in >> next) {
        if (next < current) {
            tapeIdx = (tapeIdx + 1) % tapeCount;
        }
        outs[tapeIdx] << next << endl;
        current = next;
    }

    for (int i = 0; i < tapeCount; i++) outs[i].close();
    in.close();
}

void naturalMergeSort(const string& inputFile, const string& outputFile, int k = 3) {
    if (k < 2) {
        cerr << "Недопустимое количество лент" << endl;
        return;
    }

    string tapes[MAX_K];
    for (int i = 0; i < k; i++) {
        tapes[i] = "temp_tape_" + to_string(i) + ".txt";
    }

    distribute(inputFile, tapes, k);

    string tempFile = "temp_merge.txt";
    int activeTapes = k;

    while (activeTapes > 1) {
        int tape1 = -1, tape2 = -1;
        for (int i = 0; i < k; ++i) {
            ifstream f(tapes[i]);
            if (f.peek() != EOF) {
                if (tape1 == -1) tape1 = i;
                else if (tape2 == -1) tape2 = i;
            }
            f.close();
        }

        if (tape2 == -1) break;

        merge(tempFile, tapes[tape1], tapes[tape2]);

        remove(tapes[tape1].c_str());
        remove(tapes[tape2].c_str());
        rename(tempFile.c_str(), tapes[tape1].c_str());

        activeTapes--;
    }

    for (int i = 0; i < k; ++i) {
        ifstream f(tapes[i]);
        if (f.peek() != EOF) {
            f.close();
            remove(outputFile.c_str());
            rename(tapes[i].c_str(), outputFile.c_str());
            break;
        }
        f.close();
    }

    for (int i = 0; i < k; i++) remove(tapes[i].c_str());
}

int main() {
    srand(unsigned(time(nullptr)));

    int n;
    cin >> n;
    int mas[n];

    ofstream file("input.txt");

    cout << "Array:" << endl;
    for (int i = 0; i < n; i++) {
        mas[i] = rand() % 100 - 50;
        file << mas[i] << endl;
        cout << mas[i] << ' ';
    }
    file.close();

    cout << endl << endl;

    string inputFile = "input.txt";
    string outputFile = "output_sorted.txt";

    naturalMergeSort(inputFile, outputFile, 10);

    cout << "Sorted:" << endl;
    ifstream sorted(outputFile);
    int x;
    while (sorted >> x) {
        cout << x << ' ';
    }
    cout << endl << endl;
    sorted.close();

    return 0;
}
