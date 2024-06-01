// Noelia Gargallo Arroyo
// Usuari u1979924
// Pr�ctica final MTP2

#ifndef TAULER_H
#define TAULER_H
#include "Carta.h"
#include "Baralla.h"

class Tauler {
    //Descripci�: Aquesta classe representa el tauler de joc. �s una matriu de cartes on es poden posar les cartes durant el joc.
public:
    // CONSTRUCTORS
    Tauler();
    // Pre: --; Post: Crea un tauler buit amb les dimensions predeterminades
    Tauler(const Tauler& other);
    // Pre: --; Post: Crea una c�pia del tauler 'other'
    Tauler& operator=(const Tauler& o);
    // Pre: --; Post: Assigna el tauler 'o' al tauler actual

    //DESTRUCTOR
    ~Tauler();
    // Pre: --; Post: Allibera la mem�ria din�mica reservada pel tauler

    // CONSULTORS
    int n_files() const;
    // Pre: --; Post: Retorna el nombre de files del tauler
    int n_columnes() const;
    // Pre: --; Post: Retorna el nombre de columnes del tauler
    void mostra_tauler() const;
    // Pre: --; Post: Mostra l'estat actual del tauler

    // MODIFICADORS
    void posar_carta(int col, int fila, const Carta& carta);
    // Pre: La posici� (fila, columna) est� dins dels l�mits del tauler; Post: Posiciona la carta al tauler en la posici� (fila, columna)
    void repartir(Baralla& baralla);
    // Pre: --; Post: Reparteix les cartes de la baralla al tauler
    bool columna_valida(int columna) const;
    // Pre: Un enter columna >= 0; Post: Retorna true si la columna �s v�lida, false altrament
    bool columna_buida(int columna) const;
    // Pre: Un enter columna >= 0; Post: Retorna true si la columna est� buida, false altrament
    Carta cim_columna(int columna) const;
    // Pre: La columna no est� buida; Post: Retorna la carta al cim de la columna
    void afegir_carta(int columna, const Carta& c);
    // Pre: La columna �s v�lida; Post: Afegeix la carta 'c' a la columna indicada

private:
    // ATRIBUTS
    Carta** taula; // Matriu de punters a cartes
    int files;     // Nombre de files del tauler
    int columnes;  // Nombre de columnes del tauler

    // M�TODES PRIVATS
    void allibera();
    // Pre: --; Post: Allibera la mem�ria din�mica reservada pel tauler
    void reserva();
    // Pre: --; Post: Reserva la mem�ria din�mica per a la matriu de cartes
    void copia(const Tauler& t);
    // Pre: --; Post: Copia el contingut del tauler 't' al tauler actual
};

#endif // TAULER_H
