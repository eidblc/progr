#include <iostream>
using namespace std;
int main() {
    int pasirinkimas, valiuta;1
    int pal, pir, par;
    double eur, inr, usd, gbp;
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
    scanf("%d", &pasirinkimas);

    cout << "1.Eurai EUR" << endl;
    cout << "2. Didziosios Britanijos svarai GBP" << endl;
    cout << "3. Jungtiniu Amerikos valstiju doleriai USD" << endl;
    cout << "4. Indijos rupijai INR" << endl;
    scanf("%d", &valiuta);

    switch (valiuta) {
        case 1:
            cout << "Ivesti EUR kieki: " << endl;
            cin >> eur;
            break;
        case 2:
            cout << "Ivesti GBP kieki: " << endl;
            cin >> gbp;
            break;
        case 3:
            cout << "Ivesti USD kieki: " << endl;
            cin >> usd;
        break;
        case 4:
            cout << "Ivesti INR kieki: " << endl;
            cin >> inr;
        break;
        default:
            cout << "Pasirinkimo nera" << endl;
            exit(0);
    }
    switch (pasirinkimas) {
        case 1:
            cout << "1. Palyginti su EUR" << endl;
            cout << "2. Palyginti su GBP" << endl;
            cout << "3. Palyginti su USD" << endl;
            cout << "4. Palyginti su INR" << endl;
            scanf("%d", &pal);
        switch(pal) {
            
        }
    }
    return 0;
}
