#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <list>

using namespace std;

// 1. Wyznaczanie miejsc zerowych funkcji metodą połowienia
double funkcja(double x) {
    return x*x - 6;
}

double miejsceZeroweMetodaPolowienia(double a, double b, double epsilon) {
    double fa = funkcja(a);
    double fb = funkcja(b);

    if (fa * fb > 0) {
        cout << "Nie można zagwarantować istnienia miejsca zerowego w przedziale [" << a << ", " << b << "]." << endl;
        return -1;
    }

    while ((b - a) / 2 > epsilon) {
        double c = (a + b) / 2;
        double fc = funkcja(c);

        if (fc == 0)
            return c;
        else if (fa * fc < 0)
            b = c;
        else
            a = c;
    }
    return (a + b) / 2;
}

// 2. Obliczanie pierwiastka kwadratowego metodą Herona
double pierwiastekKwadratowyMetodaHerona(double x) {
    if (x == 0) return 0;
    double guess = x / 2.0;

    while (true) {
        double nextGuess = 0.5 * (guess + x / guess);

        if (abs(nextGuess - guess) < 0.0001) {
            return nextGuess;
        }
        guess = nextGuess;
    }
}

// 3. Stos (from scratch)
class Stos {
private:
    vector<int> stos;
public:
    void dodaj(int element) {
        stos.push_back(element);
    }

    void wypisz() {
        for (int i = stos.size() - 1; i >= 0; --i) {
            cout << stos[i] << " ";
        }
        cout << endl;
    }

    void usun() {
        if (!stos.empty())
            stos.pop_back();
    }
};

// 4. Lista dwukierunkowa (biblioteka standardowa C++)
void dodajElementyZPlikuDoListy(const string& nazwaPliku, list<int>& lista) {
    ifstream plik(nazwaPliku);
    if (!plik.is_open()) {
        cout << "Nie można otworzyć pliku." << endl;
        return;
    }

    string linia;
    while (getline(plik, linia, ',')) {
        int element;
        stringstream(linia) >> element;
        lista.push_back(element);
    }

    plik.close();
}

void sortujListe(list<int>& lista) {
    lista.sort();
}

void usunElementZListy(list<int>& lista, int element) {
    lista.remove(element);
}

void dodajElementDoListy(list<int>& lista, int element) {
    lista.push_back(element);
}

void wypiszListe(const list<int>& lista) {
    cout << "Zawartość listy: ";
    for (const auto& element : lista) {
        cout << element << " ";
    }
    cout << endl;
}

int main() {
    // 1. Wyznaczanie miejsc zerowych funkcji metodą połowienia
    double miejsceZero = miejsceZeroweMetodaPolowienia(0, 5, 0.0001);
    cout << "Miejsce zerowe: " << miejsceZero << endl;

    // 2. Obliczanie pierwiastka kwadratowego metodą Herona
    double sqrtValue = pierwiastekKwadratowyMetodaHerona(30);
    cout << "Pierwiastek kwadratowy z wynosi: " << sqrtValue << endl;

    // 3. Stos (from scratch)
    Stos stos;
    stos.dodaj(5);
    stos.dodaj(10);
    stos.dodaj(15);
    stos.wypisz();
    stos.usun();
    stos.wypisz();

    // 4. Lista dwukierunkowa (biblioteka standardowa C++)
    list<int> lista;
    dodajElementyZPlikuDoListy("plik.txt", lista);
    sortujListe(lista);
    wypiszListe(lista);
    usunElementZListy(lista, 10);
    dodajElementDoListy(lista, 20);
    wypiszListe(lista);

    return 0;
}
