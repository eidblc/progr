#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

using namespace std;

struct menuItemType {
    string menuItem;
    double menuPrice;
};

int getData(menuItemType menuList[], int maxSize) {
    ifstream in("menu.txt");
    if (!in) {
        cout << "Nepavyko atidaryti meniu failo" << endl;
        return 0;
    }

    int menuCount = 0;
    double kaina;
    string pavadinimas;

    while (in >> kaina) {
        in.ignore();
        getline(in, pavadinimas);

        if (pavadinimas.size() > 0) {
            menuList[menuCount].menuPrice = kaina;
            menuList[menuCount].menuItem = pavadinimas;
            menuCount++;
        }

        if (menuCount >= maxSize) break;
    }

    in.close();
    return menuCount;
}

int showMenu(menuItemType menuList[], int menuCount) {
    cout << "Sveiki atvyke i restorana" << endl;
    cout << "Pusryciu meniu:" << endl;

    for (int i = 0; i < menuCount; i++) {
        cout << setw(2) << i + 1 << ". "
             << left << setw(35) << menuList[i].menuItem
             << right << setw(6) << menuList[i].menuPrice << " EUR" << endl;
    }

    cout << "Iveskite patiekalo numeri. 0 - baigti uzsakyma." << endl;
    return 0;
}

double printCheck(menuItemType menuList[], int menuCount, int kiekis[]) {
    ofstream out("receipt.txt");
    if (!out) {
        cout << "Klaida su receipt.txt" << endl;
        return 0;
    }

    out << fixed << setprecision(2);

    double suma = 0;

    cout << endl;
    cout << "Sveiki atvyke i restorana" << endl << endl;

    out << "Sveiki atvyke i restorana" << endl << endl;

    for (int i = 0; i < menuCount; i++) {
        if (kiekis[i] > 0) {
            double eilutesSuma = kiekis[i] * menuList[i].menuPrice;
            suma = suma + eilutesSuma;

            cout << setw(2) << kiekis[i] << "  "
                 << left << setw(35) << menuList[i].menuItem
                 << right << setw(6) << eilutesSuma << " EUR" << endl;

            out << setw(2) << kiekis[i] << "  "
                << left << setw(35) << menuList[i].menuItem
                << right << setw(6) << eilutesSuma << " EUR" << endl;
        }
    }

    double pvm = suma * 0.21;
    double galutine = suma + pvm;

    cout << endl;
    cout << left << setw(39) << "Mokesciai (21%)" << right << setw(6) << pvm << " EUR" << endl;
    cout << left << setw(39) << "Galutine suma"   << right << setw(6) << galutine << " EUR" << endl;

    out << endl;
    out << left << setw(39) << "Mokesciai (21%)" << right << setw(6) << pvm << " EUR" << endl;
    out << left << setw(39) << "Galutine suma"   << right << setw(6) << galutine << " EUR" << endl;

    out.close();
    cout << endl;
    cout << "Saskaita issaugota faile: receipt.txt" << endl;

    return galutine;
}

int main() {
    cout << fixed << setprecision(2);

    constexpr int MAX = 50;
    menuItemType menuList[MAX];
    int kiekis[MAX];

    int menuCount = getData(menuList, MAX);
    if (menuCount == 0) return 0;

    for (int i = 0; i < menuCount; i++) {
        kiekis[i] = 0;
    }

    showMenu(menuList, menuCount);

    int pasirinkimas = -1;

    while (pasirinkimas != 0) {
        cout << "Patiekalo numeris (0 - baigti): ";
        cin >> pasirinkimas;

        if (pasirinkimas == 0) break;

        if (pasirinkimas < 1 || pasirinkimas > menuCount) {
            cout << "Tokio pasirinkimo nera" << endl;
        } else {
            int porcijos;
            cout << "Porciju kiekis: " << endl;
            cin >> porcijos;
            kiekis[pasirinkimas - 1] = kiekis[pasirinkimas - 1] + porcijos;
            cout << "Prideta." << endl;
            }
        }


    printCheck(menuList, menuCount, kiekis);

    return 0;
}
