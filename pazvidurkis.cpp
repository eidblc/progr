#include <iostream>
using namespace std;
int main() {
    int p1 = 7;
    int p2 = 1;
    int p3 = 3;
    double vid = 0;
    vid = (p1 + p2 + p3) / 3;
    if (vid >= 5) {
        cout << "Vidurkis teigiamas." << endl;
    } else {
        cout << "Vidurkis neigiamas" << endl;
    }
    return 0;
}