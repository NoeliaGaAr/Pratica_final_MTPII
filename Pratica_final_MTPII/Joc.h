#ifndef JOC_H
#define JOC_H

#include "Baralla.h"
#include "Carta.h"
#include "PilaCartes.h"
#include "Tauler.h"
class Joc {
public:
    Joc(); // TODO
    Joc(unsigned& llavor);
    ~Joc();
    Joc& operator=(const Joc& other);

    //void repartirCartes();
    void inicialitzarJoc();
    void mostraEstat() const;

private:
    Baralla* a_baralla;
    PilaCartes* a_ma;
    PilaCartes* a_descartades;
    PilaCartes* piles[4];
    Tauler* a_tauler;

    void emplenar_tauler();
};

#endif // JOC_H