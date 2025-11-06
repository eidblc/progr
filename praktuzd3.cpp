#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

using namespace std;

int main() {
    int pasirinkimas;
    string failas, naujasfailas;
    cout << fixed << setprecision(2);

    while (pasirinkimas != 0) {
        cout << "1. Apskaiciuoti bilietu pardavimus" << endl;
        cout << "2. Atnaujinti darbuotoju atlyginimus" << endl;
        cout << "0. Baigti programa" << endl;
        cin >> pasirinkimas;

        if (pasirinkimas == 1) {
            cout << "Iveskite bilietu failo pavadinima: ";
            cin >> failas;
            cout << "Iveskite rezultatu failo pavadinima: ";
            cin >> naujasfailas;

            ifstream in(failas);
            ofstream out(naujasfailas);

            if (!in) {
                cout << "Nepavyko atidaryti failo!" << endl;
            } else {
                double kaina, suma = 0;
                int kiekis, visiBilietai = 0;
                string eilute;
                while (in >> kaina >> kiekis) {
                    suma = suma + (kaina * kiekis);
                    visiBilietai = visiBilietai + kiekis;
                }
                cout << "Parduota bilietu: " << visiBilietai << endl;
                cout << "Bendra suma: " << suma << " EUR" << endl;
                out << "Parduota bilietu: " << visiBilietai << endl;
                out << "Bendra suma: " << suma << " EUR" << endl;
                cout << "Rezultatai issaugoti faile: " << naujasfailas << endl;
            }
            in.close();
            out.close();
        }

        else if (pasirinkimas == 2) {
            cout << "Iveskite atlyginimu failo pavadinima (pvz. salary.txt): ";
            cin >> failas;
            cout << "Iveskite naujo failo pavadinima (pvz. newSalary.txt): ";
            cin >> naujasfailas;

            ifstream in(failas);
            ofstream out(naujasfailas);

            if (!in) {
                cout << "Nepavyko atidaryti failo!" << endl;
            } else {
                string pavarde, vardas;
                double atlyginimas, procentas, naujas;
                while (in >> pavarde >> vardas >> atlyginimas >> procentas) {
                    naujas = atlyginimas + (atlyginimas * procentas / 100);
                    cout << pavarde << " " << vardas << " " << naujas << endl;
                    out << pavarde << " " << vardas << " " << naujas << endl;
                }
                cout << "Atnaujinti atlyginimai issaugoti faile: " << naujasfailas << endl;
            }
            in.close();
            out.close();
        }

        else if (pasirinkimas == 0) {
            cout << "Programa baigta." << endl;
            break;
        }

        else {
            cout << "Tokio pasirinkimo nera!" << endl;
        }
    }

    return 0;
}
