#include <iostream>
using namespace std;
int main() {
    int pasirinkimas, valiuta;
    int pal, pir, par;
    double kiekis;
    double GBP_Bendras   = 0.8729;
    double GBP_Pirkti    = 0.8600;
    double GBP_Parduoti  = 0.9220;
    double USD_Bendras   = 1.1793;
    double USD_Pirkti    = 1.1460;
    double USD_Parduoti  = 1.2340;
    double INR_Bendras   = 104.6918;
    double INR_Pirkti    = 101.3862;
    double INR_Parduoti  = 107.8546;
    cout << "1. Palyginti valiutas" << endl;
    cout << "2. Pirkti valiuta" << endl;
    cout << "3. Parduoti valiuta" << endl;
    cin >> pasirinkimas;


    switch (pasirinkimas) {
        case 1:
            cout << "1. Eurai EUR" << endl;
        cout << "2. Didziosios Britanijos svarai GBP" << endl;
        cout << "3. Jungtiniu Amerikos valstiju doleriai USD" << endl;
        cout << "4. Indijos rupijai INR" << endl;
        cin >> valiuta;
        cout << "Iveskite kieki: " << endl;
        cin >> kiekis;

        if (valiuta == 1) {
            cout << "Palyginti su: " << endl;
            cout << "1. Didziosios Britanijos Svarais GBP" << endl;
            cout << "2. Jungtiniu Amerikos Valstiju Doleriais USD" << endl;
            cout << "3. Indijos rupijais INR" << endl;
            cin >> pal;
            if (pal == 1) {
                cout << kiekis << "EUR = " << kiekis * GBP_Bendras << "GBP" << endl;
            } else if (pal == 2) {
                cout << kiekis << "EUR = " << kiekis * USD_Bendras << "USD" << endl;
            } else if (pal == 3) {
                cout << kiekis << "EUR = " << kiekis * INR_Bendras << "INR" << endl;
            }
        } else if (valiuta == 2) {
            cout << kiekis << "GBP = " << kiekis / GBP_Pirkti << "EUR" << endl;
        }
    }
    return 0;
}
