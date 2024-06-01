#ifndef TAULER_H
#define TAULER_H
#include "Carta.h"
#include "Baralla.h"
#include "PilaCartes.h"
class Tauler {
public:

    Tauler();
    ~Tauler();
    Tauler(const Tauler& other);
    Tauler& operator=(const Tauler& o);
    int n_files() const;
    int n_columnes() const;
    void posar_carta(int col, int fila, const Carta& carta);
    void repartir(Baralla& baralla);
    void mostra_tauler() const;

private:
    Carta** taula;
    int files;
    int columnes;

    void allibera();
    void reserva();
    void copia(const Tauler& t);
};

#endif // TAULER_H




/*class Tauler {
public:
    Tauler();
    ~Tauler();

    void repartir(Baralla& baralla);
    void mostrar() const;

private:
    static const int COLUMNES = 7;
    static const int FILES = 19;
    Carta* matriu[COLUMNES][FILES];
    int ocupacio[COLUMNES];

    void inicialitzar();
};*/

