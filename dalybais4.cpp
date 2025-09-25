#include <iostream>
using namespace std;
int main() {
    int skaicius = 0;
    cout << "skaiciai dalus is 4: " << endl;
    while (skaicius <= 20) {
        skaicius = skaicius + 1;
        if (skaicius % 4 == 0) {
            cout << skaicius << endl;
        }
    }
    return 0;
}
