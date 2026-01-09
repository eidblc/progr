#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <iomanip>

using namespace std;
const int KLAUSIMU_SK = 20;
const double MAX_BALU = 40.0;

struct Studentas {
    string id;
    char atsakymai[KLAUSIMU_SK];
    int surinktiTaskai;
    double procentai;
    int galutinisPazymys;
};

int nustatytiPazymi(double proc) {
    if (proc >= 95) return 10;
    if (proc >= 85) return 9;
    if (proc >= 75) return 8;
    if (proc >= 65) return 7;
    if (proc >= 55) return 6;
    if (proc >= 45) return 5;
    if (proc >= 35) return 4;
    if (proc >= 25) return 3;
    if (proc >= 15) return 2;
    return 1;
}

int skaiciuotiTaskus(const char studentoAts[], const char teisingiAts[]) {
    int suma = 0;
    for (int i = 0; i < KLAUSIMU_SK; i++) {
        if (studentoAts[i] == teisingiAts[i]) {
            suma += 2;
        } else if (studentoAts[i] != '-') {
            suma -= 1;
        }
    }
    return suma;
}

void nuskaitymas(vector<Studentas>& grupe, char teisingiAtsakymai[]) {
    ifstream failas("testData.txt");
    if (!failas) {
        cout << "Nepavyko atidaryti failo testData.txt" << endl;
        return;
    }

    for (int i = 0; i < KLAUSIMU_SK; i++) {
        failas >> teisingiAtsakymai[i];
    }

    Studentas temp;
    while (failas >> temp.id) {
        for (int i = 0; i < KLAUSIMU_SK; i++) {
            char simbolis;
            failas >> simbolis;
            if (simbolis == 't') simbolis = 'T';
            if (simbolis == 'f') simbolis = 'F';
            temp.atsakymai[i] = simbolis;
        }

        temp.surinktiTaskai = skaiciuotiTaskus(temp.atsakymai, teisingiAtsakymai);
        double proc = (temp.surinktiTaskai / MAX_BALU) * 100.0;
        if (proc < 0) proc = 0;
        temp.procentai = proc;
        temp.galutinisPazymys = nustatytiPazymi(proc);
        grupe.push_back(temp);
    }
    failas.close();
}

void isvesti(const vector<Studentas>& grupe) {
    ofstream rezultatuFailas("results.txt");
    rezultatuFailas << left << setw(15) << "Studento ID"
                    << setw(10) << "Taskai"
                    << setw(12) << "Procentai"
                    << setw(10) << "Pazymys" << endl;
    for (const auto& stud : grupe) {
        rezultatuFailas << left << setw(15) << stud.id
                        << setw(10) << stud.surinktiTaskai
                        << fixed << setprecision(1) << setw(12) << stud.procentai
                        << stud.galutinisPazymys << endl;
    }

    rezultatuFailas.close();
    cout << "Duomenys sekmingai irasyti i results.txt" << endl;
}

void statistika(const vector<Studentas>& grupe) {
    if (grupe.empty()) {
        cout << "Nera duomenu." << endl;
        return;
    }

    double pazymiuSuma = 0;
    double procentuSuma = 0;
    int minPazymys = 11;
    int maxPazymys = 0;
    int pazymiuKiekis[11] = {0};
    for (const auto& stud : grupe) {

        pazymiuSuma += stud.galutinisPazymys;
        procentuSuma += stud.procentai;

        if (stud.galutinisPazymys > maxPazymys) maxPazymys = stud.galutinisPazymys;
        if (stud.galutinisPazymys < minPazymys) minPazymys = stud.galutinisPazymys;

        if (stud.galutinisPazymys >= 1 && stud.galutinisPazymys <= 10)
            pazymiuKiekis[stud.galutinisPazymys]++;
    }

    double vidutinisPazymys = pazymiuSuma / grupe.size();

    cout << "KLASES STATISTIKA" << endl;
    cout << "Studentu skaicius: " << grupe.size() << endl;

    cout << "Vidutinis pazymys: " << fixed << setprecision(1) << vidutinisPazymys << endl;
    cout << "Vidutinis procentas: " << (procentuSuma / grupe.size()) << "%" << endl;
    cout << "Didziausias pazymys: " << maxPazymys << endl;
    cout << "Maziausias pazymys: " << minPazymys << endl;

    cout << "Pazymiu pasiskirstymas: ";
    for (int i = 1; i <= 10; i++) {
        if (pazymiuKiekis[i] > 0) {
            cout << "[" << i << "]:" << pazymiuKiekis[i] << " ";
        }
    }
    cout << endl << endl;
}

void ieskoti(const vector<Studentas>& grupe) {
    string ivestis;
    while (true) {
        cout << "Iveskite studento ID (0 - grizti): ";
        cin >> ivestis;

        if (ivestis == "0") break;

        bool rasta = false;
        for (const auto& stud : grupe) {
            if (stud.id == ivestis) {
                cout << "-> Rastas: " << stud.id
                     << ", Pazymys: " << stud.galutinisPazymys
                     << ", Taskai: " << stud.surinktiTaskai << endl;
                rasta = true;
                break;
            }
        }
        if (!rasta) cout << "Studentas nerastas." << endl;
    }
}

void analizuoti(const vector<Studentas>& grupe, const char teisingiAts[]) {
    if (grupe.empty()) {
        cout << "Nera duomenu." << endl;
        return;
    }

    cout << "KIEKVIENO KLAUSIMO ANALIZE" << endl;

    cout << left << setw(10) << "Klausimas"
         << right << setw(10) << "Teisingai"
         << setw(14) << "Neteisingai"
         << setw(12) << "Neatsake" << endl;


    for (int i = 0; i < KLAUSIMU_SK; ++i) {
        int teisingai = 0;
        int neteisingai = 0;
        int neatsake = 0;

        for (const auto& studentas : grupe) {
            char studAts = studentas.atsakymai[i];
            char teisAts = teisingiAts[i];

            if (studAts == teisAts) {
                teisingai++;
            }

            else if (studAts == '-' || studAts == ' ') {
                neatsake++;
            }
            else {
                neteisingai++;
            }
        }

        cout << left << setw(10) << ("Nr. " + to_string(i + 1))
             << right << setw(10) << teisingai
             << setw(14) << neteisingai
             << setw(12) << neatsake << endl;
    }
}

void sunkiausias(const vector<Studentas>& grupe, const char teisingiAts[]) {
    double minProc = 100.0;
    vector<int> sunkiuKlausimuNr;

    for (int i = 0; i < KLAUSIMU_SK; i++) {
        int teisingi = 0;
        for (const auto& stud : grupe) {
            if (stud.atsakymai[i] == teisingiAts[i]) teisingi++;
        }

        double proc = (double)teisingi / grupe.size() * 100;

        if (proc < minProc) {
            minProc = proc;
            sunkiuKlausimuNr.clear();
            sunkiuKlausimuNr.push_back(i + 1);
        } else if (abs(proc - minProc) < 0.001) {
            sunkiuKlausimuNr.push_back(i + 1);
        }
    }

    cout << "\nSunkiausias klausimas (Teisingai: " << fixed << setprecision(1) << minProc << "%): ";
    for (int nr : sunkiuKlausimuNr) cout << nr << " ";
    cout << endl << endl;
}

int main() {
    vector<Studentas> studentuSarasas;
    char teisingiAtsakymai[KLAUSIMU_SK];
    nuskaitymas(studentuSarasas, teisingiAtsakymai);
    if (studentuSarasas.empty()) {
        cout << "Nepavyko nuskaityti duomenu." << endl;
        return 1;
    }

    int pasirinkimas;
    do {
        cout << "1. Klases statistika" << endl;
        cout << "2. Studento paieska" << endl;
        cout << "3. Irasyti i faila" << endl;
        cout << "4. Klausimu statistika" << endl;
        cout << "5. Sunkiausias klausimas" << endl;
        cout << "0. Iseiti" << endl;
        cout << "Pasirinkimas: ";
        cin >> pasirinkimas;

        switch (pasirinkimas) {
            case 1: statistika(studentuSarasas); break;
            case 2: ieskoti(studentuSarasas); break;
            case 3: isvesti(studentuSarasas); break;
            case 4: analizuoti(studentuSarasas, teisingiAtsakymai); break;
            case 5: sunkiausias(studentuSarasas, teisingiAtsakymai); break;
            case 0: cout << "Programa baigia darba" << endl; break;
            default: cout << "Neteisingas pasirinkimas." << endl;
        }
    } while (pasirinkimas != 0);

    return 0;
}