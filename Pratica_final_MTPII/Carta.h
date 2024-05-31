#ifndef CARTA_H
#define CARTA_H

#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

class Carta {
public:
    Carta();
    char pal();
    int valor();
    Carta(char pal, int valor, bool visible);
    void revelar();
    void amagar();
    bool es_visible() const;
    bool tenim_carta() const;
    void mostrar();
    void mostrar_debug() const;

private:
    char a_pal;
    int a_valor;
    bool a_visible;

    char pal_a_char(char pal);
    string valor_a_string(int valor);
};

#endif // CARTA_H

