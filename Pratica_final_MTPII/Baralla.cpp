#include "Baralla.h"
#include <iostream>
#include <cmath>
#include <cstdlib>
using namespace std;

// Constructor per defecte
Baralla::Baralla() {
    a_n = 0;
    Xn = 0;
    reserva();
}

// Constructor amb llavor
Baralla::Baralla(unsigned llavor) {
    a_n = 0;
    Xn = llavor;
    reserva();
    crear_baralla();
}

Baralla::Baralla(const Baralla& b) {
    copia(b);
}

Baralla::~Baralla() {
    allibera();
}

Baralla& Baralla::operator=(const Baralla& b) {
    if (this != &b) {
        allibera();
        copia(b);
    }
    return *this;
}

void Baralla::afegir_carta(Carta c) {
    cartes[a_n] = c;
    a_n++;
}

void Baralla::barreja() {
    for (int i = a_n - 1; i > 0; --i) {
        int pos = aleatori(i + 1);
        intercanviar(cartes[pos], cartes[i]);
    }
}

int Baralla::aleatori(int N) {
    Xn = 1103515245 * Xn + 12345;
    return ((Xn / 32) % 32768) % N;
}

//int Baralla::aleatori(int N) 
//{
//    int aleatori = (((FISHER_YATES_A * Xn + FISHER_YATES_C) / 32) % FISHER_YATES_M) % N;
//    Xn = FISHER_YATES_A * Xn + FISHER_YATES_C;
//    return aleatori;
//}

void Baralla::mostra_baralla() const {
    cout << "BARALLA" << endl;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 13; j++) {
            Carta carta_actual = cartes[i * 13 + j];
            carta_actual.mostrar();
        }
        cout << " ";
    }
}

void Baralla::intercanviar(Carta& a, Carta& b) {
    Carta temp = a;
    a = b;
    b = temp;
}

///
Carta Baralla::agafa_carta() 
{
    Carta c('P',-1,false);
    if (a_n > 0) 
    {
        c = cartes[a_n - 1];
        a_n--;
    }
    return c;
}

void Baralla::allibera() {
    /*for (int i = 0; i < a_n; ++i) {
        delete cartes[i];
    }*/
    delete[] cartes;
}

void Baralla::copia(const Baralla& b) {
    a_n = b.a_n;
    Xn = b.Xn;
    reserva();
    for (int i = 0; i < a_n; ++i) {
        cartes[i] = Carta((b.cartes[i]));
    }
}

void Baralla::reserva() {
    cartes = new Carta[MAX_CARTES];
}


void Baralla::crear_baralla()
{
    char pals[4] = { 'P', 'c', 'd', 'T' };

    for (int i = 0; i < 4; i++)
    {
        char pal = pals[i];
        for (int valor = 1; valor < 14; valor++)
        {
            Carta c(pal, valor, false);
            afegir_carta(c);
        }
    }
}

bool Baralla::es_buida() const {
    return a_n == 0;
}

