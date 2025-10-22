#include <iostream>
#include <string>
using namespace std;
int main() {
    const int MAXPAZYMIAI = 10;
    const int MAXMOKINIAI = 100;
    string vardai[MAXMOKINIAI];
    int pazymiai[MAXMOKINIAI][MAXPAZYMIAI];
    int pazymiukiekis[MAXMOKINIAI];
    int mokiniukiekis = 0;
    int pasirinkimas;

    while (pasirinkimas != 0) {
        cout << "1. Prideti mokini ir jo pazymius";
        cout << "2. Perziureti visu mokiniu pazymius";
        cout << "3. Perziureti konkretaus mokinio pazymius";
        cout << "4. Atnaujinti pazymi";
        cout << "5. Pasalinti mokini";
        cout << "0. Baigti";
        cin >> pasirinkimas;
        switch (pasirinkimas) {
            case 1: {
                if (mokiniukiekis >= MAXMOKINIAI) {
                    cout << "Pasiektas maksimalus mokiniu skaicius";
                    break;
                }
                cout << "Iveskite mokinio varda: ";
                cin >> vardai[mokiniukiekis];
                cout << "Kiek pazymiu ivesti (iki 10): ";
                cin >> pazymiukiekis[mokiniukiekis];
                for (int i = 0; i < pazymiukiekis[mokiniukiekis]; i++) {
                    cout << "Pazymys " << i + 1 << ": ";
                    cin >> pazymiai[mokiniukiekis][i];
                }
            }
            break;
            mokiniukiekis++;
            cout << "Mokinys pridetas." << endl;
            case 2: {
                if (mokiniukiekis == 0) {
                    cout << "Mokiniu sarasas tuscias.";
                    break;
                }
                cout << "Visi mokiniai";
                for (int i = 0; i < mokiniukiekis; i++) {
                    cout << vardai[i] << " ";
                    for (int j = 0; j < pazymiukiekis[i]; j++) {
                        cout << pazymiai[i][j] << " ";
                    }
                    cout << endl;
                }
                break;
            }

        }
    }
    return 0;
}

