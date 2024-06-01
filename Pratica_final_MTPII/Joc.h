// Noelia Gargallo Arroyo
// Usuari u1979924
// Pràctica final MTP2

#ifndef JOC_H
#define JOC_H

#include "Baralla.h"
#include "Carta.h"
#include "PilaCartes.h"
#include "Tauler.h"

class Joc {
    //Descripció: Aquesta classe representa el joc de solitari. Conté tota la lògica i els components necessaris per jugar, com ara la baralla, les piles de cartes, el tauler i les regles del joc.
public:
    // CONSTRUCTORS
    Joc(); // TODO
    // Pre: --; Post: Crea un joc amb una baralla i un tauler buits, i inicialitza la resta d'atributs
    Joc(unsigned& llavor);
    // Pre: --; Post: Crea un joc amb una baralla inicialitzada amb la llavor especificada, i un tauler buit
    Joc& operator=(const Joc& other);
    // Pre: --; Post: Assigna el joc 'other' al joc actual

    //DESTRUCTOR
    ~Joc();
    // Pre: --; Post: Allibera la memòria dinàmica reservada per al joc
    
    // MODIFICADORS
    //void repartirCartes();
    void inicialitzar_joc();
    // Pre: --; Post: Inicialitza el joc amb una nova partida
    void mostra_estat() const;
    // Pre: --; Post: Mostra l'estat actual del joc
    void obrir_una_carta();
    // Pre: --; Post: Obre una carta de la pila de ma i la posa a la pila de descartades
    void posar_cartaMa_tauler(int columnaDesti);
    // Pre: La columna indicada és vàlida; Post: Posiciona una carta de la pila de ma al tauler
    void posar_cartaMa_pila();
    // Pre: --; Post: Posiciona una carta de la pila de ma a una de les piles de destí
private:
    // ATRIBUTS
    Baralla* a_baralla;         // La baralla de cartes del joc
    PilaCartes* a_ma;           // La pila de cartes de la mà del jugador
    PilaCartes* a_descartades;  // La pila de cartes descartades
    PilaCartes* piles[4];       // Les quatre piles de destí
    Tauler* a_tauler;           // El tauler de joc

    // MÈTODES PRIVATS
    void emplenar_tauler();
    // Pre: --; Post: Omple el tauler amb les cartes inicials
};

#endif // JOC_H