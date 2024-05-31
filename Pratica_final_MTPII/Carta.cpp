#include "Carta.h"
#include <cstdlib>
using namespace std;

Carta::Carta() {
    a_pal = 'P';
    a_valor = 1;
    a_visible = false;
}


Carta::Carta(char pal, int valor, bool visible) {
    a_pal = pal;
    a_valor = valor;
    a_visible = visible;
}

char Carta::pal() {
    return a_pal;
}

int Carta::valor() {
    return a_valor;
}

void Carta::revelar() {
    a_visible = true;
}

void Carta::amagar() {
    a_visible = false;
}

bool Carta::es_visible() const {
    return a_visible;
}

bool Carta::tenim_carta() const {
    return (a_pal != ' ');
}

void Carta::mostrar() 
{
    if (a_visible) 
    {
        cout << valor_a_string(a_valor) << pal_a_char(a_pal) << " ";
    }
    else 
    {
        cout << "**";
    }
}

void Carta::mostrar_debug() const
{
    cout << "(" << a_pal << "," << a_valor << ")";
}

char Carta::pal_a_char(char pal) {
    if (pal == 'P') {
        return 'P';
    }
    else if (pal == 'c') {
        return 'c';
    }
    else if (pal == 'd') {
        return 'd';
    }
    else if (pal == 'T') {
        return 'T';
    }
    else {
        return ' ';
    }
}


string Carta::valor_a_string(int valor) {
    if (valor == 1) {
        return "A";
    }
    else if (valor == 10) {
        return "D";
    }
    else if (valor == 11) {
        return "J";
    }
    else if (valor == 12) {
        return "Q";
    }
    else if (valor == 13) {
        return "K";
    }
    else {
        return to_string(valor);
    }
}