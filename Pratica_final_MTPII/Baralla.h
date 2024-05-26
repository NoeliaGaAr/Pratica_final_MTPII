// Noelia Gargallo Arroyo
// Usuari u1979924
// Pràctica final MTP2

#ifndef BARALLA_H
#define BARALLA_H
#include <cmath>
#include "Carta.h"
#include <cstdlib>
using namespace std;

class Baralla 
{
    public:
        // CONSTRUCTORS
        Baralla();
        // Pre: --; Post: 
        Baralla(unsigned llavor);
        // Pre: --; Post: 
        Baralla(const Baralla& b);
        // Pre: --; Post: 
    
        // DESTRUCTOR
        ~Baralla();
        // Pre: --; Post:
    
        // OPERADORS
        Baralla& operator=(const Baralla& b);
        // Pre: --; Post: 
    
        // MÈTODES CONSULTORS
        void mostra_baralla() const;
        // Pre: --; Post: 
        bool es_buida() const;
        // Pre: --; Post: 

        // MÈTODES MODIFICADORS
        void barreja();
        // Pre: --; Post: 
        void afegir_carta(Carta c);
        // Pre: --; Post: 
        Carta agafa_carta();
        // Pre: --; Post: Retorna la carta de la posició a_n-1, altrament retorna una carta amb valor -1

    private:
        // CONSTANTS DE CLASSE
        const int MAX_CARTES = 52;                  // Màxim de cartes del Solitari
        const int FISHER_YATES_A = 1103515245;      // Variable per l'algoritme Fisher-Yates
        const int FISHER_YATES_C = 12345;           // Variable per l'algoritme Fisher-Yates
        const int FISHER_YATES_M = 32768;           // Variable per l'algoritme Fisher-Yates

        // ATRIBUTS
        Carta* cartes;                              // Taula de cartes
        int a_n;                                    // Nombre de cartes
        unsigned Xn;                                // Llavor


        // MÈTODES PRIVATS
        void allibera();
        // Pre: --; Post: 
        void copia(const Baralla& b);
        // Pre: --; Post: 
        void reserva();
        // Pre: --; Post: 
        void crear_baralla();
        // Pre: --; Post: 
        int aleatori(int N);
        // Pre: --; Post: 
        void intercanviar(Carta& a, Carta& b);
        // Pre: --; Post: 
};

#endif // BARALLA_H

