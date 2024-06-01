// Noelia Gargallo Arroyo
// Usuari u1979924
// Pràctica final MTP2

#include <iostream>
#include <cmath>
#include <cstdlib>

#include "Joc.h"

using namespace std;

// Funcions
void mostrar_menu() {
    cout << "MENU" << endl;
    cout << "1. OBRIR UNA CARTA (O TORNAR A COMENCAR)" << endl;
    cout << "2. POSAR UNA CARTA (MA->TAULER)" << endl;
    cout << "3. POSAR UNA CARTA (MA->PILA)" << endl;
    cout << "4. MOURE UNA CARTA (TAULER->TAULER)" << endl;
    cout << "5. MOURE UNA CARTA (TAULER->PILA)" << endl;
    cout << "6. RECUPERAR UNA CARTA (PILA->TAULER)" << endl;
    cout << "E. ESPIAR EL TAULER" << endl;
    cout << "M. MOSTRAR EL MENU" << endl;
    cout << "A. ABANDONAR LA PARTIDA" << endl;
}

void gestionar_menu(Joc& joc) {
    int opcio;
    cout << "OPCIO: ";
    cin >> opcio;

    while (opcio != 8) {

        if (opcio == 1) {
            joc.obrir_una_carta();
        }
        else if (opcio == 2) {
            int columna;
            cout << "Entra la columna desti: ";
            cin >> columna;
            joc.posar_cartaMa_tauler(columna);
        }
        else if (opcio == 3) {
            joc.posar_cartaMa_pila();
        }
        /*else if (opcio == "4") {
            int colOrigen, fila, colDesti;
            cout << "Entra la columna origen: ";
            cin >> colOrigen;
            cout << "Entra la fila: ";
            cin >> fila;
            cout << "Entra la columna destí: ";
            cin >> colDesti;
            joc.moureCartaTaulerTauler(colOrigen, fila, colDesti);
        }
        else if (opcio == "5") {
            int colOrigen;
            cout << "Entra la columna origen: ";
            cin >> colOrigen;
            joc.moureCartaTaulerPila(colOrigen);
        }
        else if (opcio == "6") {
            int coll, colDesti;
            cout << "Entra la pila origen (1: piques, 2: cors, 3: diamants, 4: trèvols): ";
            cin >> coll;
            cout << "Entra la columna destí: ";
            cin >> colDesti;
            joc.recuperarCartaPilaTauler(coll - 1, colDesti);
        }
        else if (opcio == "E") {
            joc.espiarTauler();
        }*/
        else if (opcio == 'M') {
            mostrar_menu();
        }
        joc.mostra_estat();
        cout << "OPCIO: ";
        cin >> opcio;
    }
}
// Main
int main() 
{
    unsigned llavor;
    cout << "ENTRA LA LLAVOR: " << endl;
    cin >> llavor;

    Joc joc(llavor);
    joc.inicialitzar_joc();
    joc.mostra_estat();
    mostrar_menu();
    gestionar_menu(joc);

    return 0;
}

// PENDENT

// > Gestionar tema espais q no se pq no es fan bé (veure tauler.cpp)
// > Quan posa les cartes al tauler, les dos últimes no funcionen (per defecte P,-1,false)
// > Mirar com fer quan es mostra una carta buida (si mostrem ** a carta o a tauler)
// > Mostrar mà
