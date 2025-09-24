#include <iostream>
using namespace std;
int main() {
    int pazymys;
    cout << "Egzamino pazymys: " << endl;
    cin >> pazymys;
    switch (pazymys) {
        case 1: cout << "egzaminas neislaikytas" << endl; break;
        case 2: cout << "egzaminas neislaikytas" << endl; break;
        case 3: cout << "egzaminas neislaikytas" << endl; break;
        case 4: cout << "egzaminas neislaikytas" << endl; break;
        case 5: cout << "patenkinamai" << endl; break;
        case 6: cout << "patenkinamai" << endl; break;
        case 7: cout << "gerai" << endl; break;
        case 8: cout << "gerai" << endl; break;
        case 9: cout << "labai gerai" << endl; break;
        case 10: cout << "puikiai" << endl; break;
        default: cout << "ivestas netinkamas pazymys" << endl; break;
    }
    return 0;
}
