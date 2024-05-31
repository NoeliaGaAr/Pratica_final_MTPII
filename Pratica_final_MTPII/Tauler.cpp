#include "Tauler.h"
#include <iostream>
#include <iomanip>
#include <cstdlib>

using namespace std;

const int MAX_FILES = 19;
const int MAX_COLUMNES = 7;

Tauler::Tauler() 
{
    files = 7;
    columnes = 7;
    reserva();
}

Tauler::~Tauler() {
    allibera();
}

Tauler::Tauler(const Tauler& other) {
    copia(other);
}

void Tauler::posar_carta(int col, int fila, const Carta& carta) {
    if (col >= 0 && col < columnes && fila >= 0 && fila < files) {
        taula[fila][col] = carta;
    }
    else {
        cout << "Posició invàlida!" << endl;
    }
}

void Tauler::repartir(Baralla& baralla) {
    
    /*for (int i = 0; i < files; ++i) {
        for (int j = 0; j <= i; ++j) {
            Carta carta = baralla.agafa_carta();
            if (carta.) {
                taula[i][j] = carta; // Desreferència el punter per assignar el valor
                delete carta; // Allibera la memòria assignada per 'baralla.agafa_carta()'
            }
            else {
                cout << "No hi ha més cartes a la baralla!" << endl;
                return;
            }
        }
    }*/
}
/*void Tauler::inicialitzar(Baralla& baralla) {
    int carta_index = 0;
    for (int col = 0; col < columnes; col++) {
        for (int fila = 0; fila < files; fila++) {
            if (fila < files - 1 - col) {
                // Cartes tapades
                taula[fila][col] = Carta(' ', 0, false);
            }
            else {
                // Cartes destapades
                Carta* carta = baralla.agafa_carta();
                if (carta != nullptr) {
                    taula[fila][col] = carta;
                    carta_index++;
                }
            }
        }
    }
}*/

void Tauler::mostra_tauler() const
{
    // TODO: Fa un espai extra entre "Qc **", fa "Qc  **" i no hauria.
     
    // Mostrar estat del joc
    cout << "               **" << endl;
    cout << "c1 c2 c3 c4 c5 c6 c7" << endl;

    // Recorrem totes les files (0..files-1)
    for (int fila = 0; fila < files; fila++)
    {
        // Mostrem un espai quan canviem de fila, relatiu a aquesta
        for (int espais = 0; espais < fila; espais++) {
            cout << "   "; // tres espais per desplaçar la fila
        }

        // Recorrem les columnes (fila..columnes-1)
        for (int col = fila; col < columnes; col++)
        {
            // Si NO tenim una carta a la casella...
            if (!taula[fila][col].es_visible())
            {
                // Mostrem "**"
                cout << "**";
            }
            // Altrament...
            else
            {
                // Mostrem la carta que hi ha a la casella
                taula[fila][col].mostrar();
            }
            // Mostrem un espai de separació (independentment del que fem)
            if (col < columnes - 1) cout << " ";
        }

        // Mostrem la fila a la que estem
        cout << " f" << fila + 1 << endl;
    }
}

void Tauler::allibera() {
    for (int i = 0; i < files; i++) {
        delete[] taula[i];
    }
    delete[] taula;
}

void Tauler::reserva() {
    taula = new Carta * [files];
    for (int i = 0; i < files; i++) {
        taula[i] = new Carta[columnes];
    }
}

Tauler& Tauler::operator=(const Tauler& o) {
    if (this != &o) {
        allibera();
        copia(o);
    }
    return *this;
}

int Tauler::n_files() const
{
    return files;
}

int Tauler::n_columnes() const
{
    return columnes;
}

void Tauler::copia(const Tauler& t) {
    // Alliberem la memòria actual del tauler
    allibera();

    // Reservem memòria per la nova matriu de cartes
    taula = new Carta * [files];
    for (int i = 0; i < files; i++) {
        taula[i] = new Carta[columnes];
    }

    // Copiem les cartes de la taula original a la nova taula
    for (int fila = 0; fila < files; fila++) {
        for (int col = 0; col < columnes; col++) {
            taula[fila][col] = Carta((t.taula[fila][col]));
        }
    }
}











/*Tauler::Tauler() {
    inicialitzar();
}

Tauler::~Tauler() {
    for (int col = 0; col < COLUMNES; ++col) {
        for (int fila = 0; fila < ocupacio[col]; ++fila) {
            delete matriu[col][fila];
        }
    }
}

void Tauler::inicialitzar() {
    for (int col = 0; col < COLUMNES; ++col) {
        ocupacio[col] = 0;
        for (int fila = 0; fila < FILES; ++fila) {
            matriu[col][fila] = nullptr;
        }
    }
}

void Tauler::repartir(Baralla& baralla) {
    for (int col = 0; col < COLUMNES; ++col) {
        for (int fila = 0; fila <= col; ++fila) {
            Carta* carta = baralla.cartes[--baralla.a_n];  // Treu l'última carta de la baralla
            matriu[col][fila] = carta;
            ocupacio[col]++;
            if (fila == col) {
                carta->obrir();  // Obre la carta a la part superior de cada columna
            }
        }
    }
}

void Tauler::mostrar() const {
    std::cout << "c1 c2 c3 c4 c5 c6 c7" << std::endl;
    for (int fila = 0; fila < FILES; fila++) {
        bool filaBuida = true;
        for (int col = 0; col < COLUMNES; col++) {
            if (matriu[col][fila]) {
                matriu[col][fila]->mostrar();
                filaBuida = false;
            }
            else {
                std::cout << "   ";
            }
        }
        if (filaBuida) break;
        std::cout << "f" << (fila + 1);
        if (fila + 1 < 10) {
            std::cout << " ";
        }
        std::cout << std::endl;
    }
}*/
