#include <iostream>
using namespace std;
int main() {
    float indelis = 1000;
    float palukanos = 1.05;
    int metai = 10;
    float suma = indelis;
    for (int i = 1; i <= 10; i++) {
        suma = suma * palukanos;
    }
    cout << suma << endl;
    return 0;
}
