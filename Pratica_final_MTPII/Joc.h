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
    void inicialitzar_joc();
    void mostra_estat() const;

    void obrir_una_carta();
    void posar_cartaMa_tauler(int columnaDesti);
    void posar_cartaMa_pila();
private:
    Baralla* a_baralla;
    PilaCartes* a_ma;
    PilaCartes* a_descartades;
    PilaCartes* piles[4];
    Tauler* a_tauler;

    void emplenar_tauler();
};

#endif // JOC_H