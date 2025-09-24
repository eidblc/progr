#include <iostream>
using namespace std;
int main() {
    int suma = 0;
    int x = 0;
    while (x <= 19) {
        x = x + 1;
        if (x % 2 != 0) {
            suma = suma + x;
        }
    }
    cout << "nelyginiu skaiciu suma: " << suma << endl;
    return 0;
}
