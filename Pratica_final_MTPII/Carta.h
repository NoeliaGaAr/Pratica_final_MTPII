// Noelia Gargallo Arroyo
// Usuari u1979924
// Pr�ctica final MTP2

#ifndef CARTA_H
#define CARTA_H

#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

class Carta {
    //Descripci�: Aquesta classe representa una carta de joc. Cada carta t� un pal (cor, diamant, pic o tr�vol), un valor num�ric (de l'as al rei) i un estat de visibilitat (visible o no).
public:
    // CONSTRUCTORS
    Carta();
    // Pre: --; Post: Crea una carta buida amb pal ' ', valor 0 i no visible
    Carta(char pal, int valor, bool visible);
    // Pre: Entra un caracter pal, un enter valor>=0 i un bool visible; Post: Crea una carta amb el pal, valor i visibilitat especificats
    
    // CONSULTORS
    char pal();
    // Pre: --; Post: Retorna el pal de la carta
    int valor();
    // Pre: --; Post: Retorna el valor de la carta
    bool es_visible() const;
    // Pre: --; Post: Retorna true si la carta �s visible, fals altrament
    bool tenim_carta() const;
    // Pre: --; Post: Retorna true si la carta t� un valor v�lid, fals altrament
    void mostrar();
    // Pre: --; Post: Mostra la carta si �s visible, sin� mostra "##"
    void mostrar_debug() const;
    // Pre: --; Post: Mostra el pal i el valor de la carta

    // MODIFICADORS
    void revelar();
    // Pre: --; Post: Fa que la carta sigui visible
    void amagar();
    // Pre: --; Post: Fa que la carta sigui no visible

private:
    // ATRIBUTS
    char a_pal;         // Pal de la carta ('P', 'T', 'D', 'C')
    int a_valor;        // Valor de la carta (de 1 a 13)
    bool a_visible;     // Indica si la carta est� visible o no

    // M�TODES PRIVATS
    char pal_a_char(char pal);
    // Pre: Entra caracter de pal entre ('P', 'T', 'D', 'C'); Post: Retorna el car�cter corresponent al pal de la carta
    string valor_a_string(int valor);
    // Pre: Entra valor>=0 i valor entre 1 i 13; Post: Retorna el string corresponent al valor de la carta
};

#endif // CARTA_H

