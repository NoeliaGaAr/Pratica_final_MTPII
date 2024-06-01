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
    //Descripció: Aquesta classe representa una baralla de cartes.Conté una sèrie de mètodes per gestionar i manipular les cartes de la baralla, com barrejar - les, afegir - ne o treure'n, i mostrar l'estat de la baralla.
    public:
        // CONSTRUCTORS
        Baralla();
        // Pre: --; Post: Crea una baralla de cartes buida amb una llavor aleatòria
        Baralla(unsigned llavor);
        // Pre: Assignació de una llavor; Post: Crea una baralla de cartes buida amb la llavor especificada
        Baralla(const Baralla& b);
        // Pre: --; Post: Crea una còpia de la baralla 'b'
    
        // DESTRUCTOR
        ~Baralla();
        // Pre: --; Post: Allibera la memòria dinàmica reservada per a les cartes de la baralla
    
        // OPERADORS
        Baralla& operator=(const Baralla& b);
        // Pre: --; Post: Assigna la baralla 'b' a la baralla actual
    
        // MÈTODES CONSULTORS
        void mostra_baralla() const;
        // Pre: --; Post: Mostra les cartes de la baralla actual
        bool es_buida() const;
        // Pre: --; Post: Retorna cert si la baralla està buida, fals altrament

        // MÈTODES MODIFICADORS
        void barreja();
        // Pre: --; Post: Barreja les cartes de la baralla
        void afegir_carta(Carta c);
        // Pre: --; Post: Afegeix una carta a la baralla
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
        // Pre: --; Post: Allibera la memòria dinàmica reservada per a les cartes de la baralla
        void copia(const Baralla& b);
        // Pre: --; Post: Copia la baralla 'b' a la baralla actual
        void reserva();
        // Pre: --; Post: Reserva memòria per a les cartes de la baralla
        void crear_baralla();
        // Pre: --; Post: Crea una baralla de 52 cartes amb valors i pals adequats
        int aleatori(int N);
        // Pre: N és un enter positiu; Post: Retorna un nombre aleatori entre 0 i N-1
        void intercanviar(Carta& a, Carta& b);
        // Pre: A=a i B=b; Post: A=b i B=a
};

#endif // BARALLA_H
