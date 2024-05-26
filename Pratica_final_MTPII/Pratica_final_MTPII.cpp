#include <iostream>
#include <cmath>
#include <cstdlib>

#include "Joc.h"

using namespace std;

// Funcions

// Main
int main() 
{
    unsigned llavor;
    cout << "ENTRA LA LLAVOR: " << endl;
    cin >> llavor;

    Joc joc(llavor);
    joc.inicialitzarJoc();
    joc.mostraEstat();

    return 0;
}

// PENDENT

// > Gestionar tema espais q no se pq no es fan bé (veure tauler.cpp)
// > Quan posa les cartes al tauler, les dos últimes no funcionen (per defecte P,-1,false)
// > Mirar com fer quan es mostra una carta buida (si mostrem ** a carta o a tauler)
// > Mostrar mà
