#ifndef PILACARTES_H
#define PILACARTES_H

#include "Carta.h"
#include <string>

using namespace std;

class PilaCartes {

public:
    PilaCartes();
    PilaCartes(const PilaCartes& o);
    ~PilaCartes();

    bool buida() const;
    Carta cim() const;
    Carta* seg() const;

    void empila(Carta c);
    void desempila();
    void mostrar() const;
    PilaCartes& operator=(const PilaCartes& o);

private:
    struct Node {
        Carta* valor;
        Node* seg;
    };
    Node* a_cim;

    void copia(const PilaCartes& o);
    void allibera();
};

#endif // PILACARTES_H

