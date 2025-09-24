#include <iostream>
using namespace std;
int main() {
    int erez = 3;
    if (erez == 10) {
        cout << "puiku" << endl;
    } else if (erez >= 9) {
        cout << "labai gerai" << endl;
    } else if (erez >= 7) {
        cout << "gerai" << endl;
    } else if (erez >= 5) {
        cout << "patenkinamai" << endl;
    } else if (erez < 5) {
        cout << "egzaminas neislaikytas" << endl;
    }
    return 0;
}