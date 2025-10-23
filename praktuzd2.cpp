#include <iostream>
#include <string>
using namespace std;
int main() {
    const int MAXPAZYMIAI = 10;
    const int MAXMOKINIAI = 2;
    string vardai[MAXMOKINIAI];
    int pazymiai[MAXMOKINIAI][MAXPAZYMIAI];
    int pazymiukiekis[MAXMOKINIAI];
    int mokiniukiekis = 0;
    int pasirinkimas;

    while (pasirinkimas != 0) {
        cout << "1. Prideti mokini ir jo pazymius" << endl;
        cout << "2. Perziureti visu mokiniu pazymius" << endl;
        cout << "3. Perziureti konkretaus mokinio pazymius" << endl;
        cout << "4. Atnaujinti pazymi" << endl;
        cout << "5. Pasalinti mokini" << endl;
        cout << "0. Baigti" << endl;
        cin >> pasirinkimas;
        switch (pasirinkimas) {
            case 1: {
                if (mokiniukiekis >= MAXMOKINIAI) {
                    cout << "Pasiektas maksimalus mokiniu skaicius" << endl;
                    break;
                }


                cout << "Iveskite mokinio varda: " << endl;
                cin >> vardai[mokiniukiekis];
                cout << "Kiek pazymiu ivesti (iki 10): " << endl;
                cin >> pazymiukiekis[mokiniukiekis];
                if (pazymiukiekis[mokiniukiekis] > MAXPAZYMIAI) {
                    cout << "Per didelis pazymiu kiekis" << endl;
                    break;
                }
                for (int i = 0; i < pazymiukiekis[mokiniukiekis]; i++) {
                    cout << "Pazymys " << i + 1 << ": " << endl;
                    cin >> pazymiai[mokiniukiekis][i];
                }
            }

            mokiniukiekis++;
            cout << "Mokinys pridetas." << endl;
            break;
            case 2: {
                if (mokiniukiekis == 0) {
                    cout << "Mokiniu sarasas tuscias." << endl;
                }

                cout << "Visi mokiniai" << endl;
                for (int i = 0; i < mokiniukiekis; i++) {
                    cout << vardai[i] << " ";
                    for (int j = 0; j < pazymiukiekis[i]; j++) {
                        cout << pazymiai[i][j] << " ";
                    }
                    cout << endl;
                }
                break;
            }
            case 3: {
                if (mokiniukiekis == 0) {
                    cout << "Mokiniu sarasas tuscias." << endl;
                }
                string paieska;
                cout << "Iveskite mokinio varda: " << endl;
                cin >> paieska;
                for (int i = 0; i < mokiniukiekis; i++) {
                    if (vardai[i] == paieska) {
                        cout << vardai[i] << " pazymiai: " << endl;
                        for (int j = 0; j < pazymiukiekis[i]; j++) {
                            cout << pazymiai[i][j] << " ";
                        } cout << endl;
                    }
                }
            break;
            }
            case 4: {
                if (mokiniukiekis == 0) {
                    cout << "Mokiniu sarasas tuscias." << endl;
                }
                string paieska;
                cout << "Iveskite mokinio varda: " << endl;
                cin >> paieska;
                for (int i = 0; i < mokiniukiekis; i++) {
                    if (vardai[i] == paieska) {
                        cout << vardai[i] << " pazymiu kiekis: " << pazymiukiekis[i] << endl;
                        for (int j = 0; j < pazymiukiekis[i]; j++) {
                            cout << j + 1 << ". " << pazymiai[i][j] << endl;
                        }
                    }
                    int numeris;
                    cout << "Kuri pazymi pakeisti (1-" << pazymiukiekis[i] << "): " << endl;
                    cin >> numeris;
                    cout << "Iveskite nauja pazymi: " << endl;
                    cin >> pazymiai[i][numeris - 1];
                    cout << "Pazymys atnaujintas" << endl;
                    break;
                }
            break;
            }
            case 5: {
                string vardas;
                cout << "Iveskite mokini kuri norite pasalinti: " << endl;
                cin >> vardas;
                for (int i = 0; i < mokiniukiekis; i++) {
                    for (int k = i; k < mokiniukiekis - 1; k++) {
                        vardai[k] = vardai[k + 1];
                        pazymiukiekis[k] = pazymiukiekis[k + 1];
                        for (int j = 0; j < MAXPAZYMIAI; j++) {
                            pazymiai[k][j] = pazymiai[k + 1][j];
                        }
                    }
                    mokiniukiekis--;
                    cout << "Mokinys pasalintas" << endl;
                    break;
                }
            }
                break;
            case 0: {
                cout << "Programa baigia darba" << endl;
                break;
            }
            default: {
                cout << "Pasirinkimo nera" << endl;
            }
        }
    }
    return 0;
}
