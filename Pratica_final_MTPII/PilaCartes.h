// Noelia Gargallo Arroyo
// Usuari u1979924
// Pràctica final MTP2

#ifndef PILACARTES_H
#define PILACARTES_H

#include "Carta.h"
#include <string>

using namespace std;

class PilaCartes {
    //Descripció: Aquesta classe representa una pila de cartes. Les cartes es poden empilar o desempilar, i es poden accedir la carta del cim i la següent carta.
public:
    // CONSTRUCTORS
    PilaCartes();
    // Pre: --; Post: Crea una pila de cartes buida
    PilaCartes(const PilaCartes& o);
    // Pre: --; Post: Crea una còpia de la pila de cartes 'o'

    //DESTRUCTOR
    ~PilaCartes();
    // Pre: --; Post: Allibera la memòria dinàmica reservada per a la pila de cartes

    // CONSULTORS
    bool buida() const;
    // Pre: --; Post: Retorna true si la pila de cartes està buida, fals altrament
    Carta cim() const;
    // Pre: La pila no està buida; Post: Retorna la carta al cim de la pila

    // MODIFICADORS
    void empila(Carta c);
    // Pre: S'entra una Carta c; Post: Afegeix la carta 'c' al cim de la pila
    void desempila();
    // Pre: La pila no està buida; Post: Treu la carta del cim de la pila
    void mostrar() const;
    // Pre: --; Post: Mostra les cartes de la pila
    PilaCartes& operator=(const PilaCartes& o);
    // Pre: --; Post: Assigna la pila de cartes 'o' a la pila actual

private:
    // ESTRUCTURA DE NODE
    struct Node {
        Carta* valor;
        Node* seg;
    };
    Node* a_cim; // Punter al node del cim de la pila

    // MÈTODES PRIVATS
    void copia(const PilaCartes& o);
    // Pre: --; Post: Copia la pila de cartes 'o' a la pila actual
    void allibera();
    // Pre: --; Post: Allibera la memòria dinàmica reservada per a la pila de cartes
};

#endif // PILACARTES_H

