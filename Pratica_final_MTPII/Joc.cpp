#include "Joc.h"

Joc::Joc(unsigned& llavor) 
{
    a_baralla = new Baralla(llavor);
    a_ma = new PilaCartes();
    a_descartades = new PilaCartes();
    a_tauler = new Tauler();
    // Inicialitzem les piles dels pals
    for (int i = 0; i < 4; ++i) {
        piles[i] = new PilaCartes();
    }
}

Joc::~Joc() {
    delete a_ma;
    delete a_descartades;
    for (int i = 0; i < 4; ++i) {
        delete piles[i];
    }
}

void Joc::inicialitzarJoc() 
{
    // Pas 1: Barrejem la baralla
    a_baralla->barreja();
    // Pas 2: Emplenem el tauler amb cartes
    emplenar_tauler();
    // Pas 3: Quan el tauler està ple i queden cartes,
    //        ens les anem posant a la mà
    while (not a_baralla->es_buida()) 
    {
        a_ma->empila(a_baralla->agafa_carta());
    }
}

void Joc::mostraEstat() const {
    cout << "ESTAT DEL JOC" << endl << endl;
    cout << "Ma: " << a_ma->cim() << "  Descartades: " << a_descartades->cim() << endl;
    a_tauler->mostra_tauler();

    cout << "JOC EN CURS" << endl;
}

void Joc::emplenar_tauler()
{
    // TODO:
    // Fer que Joc distribueixi les fitxes pel tauler.
    // Tauler només ha de posar o treure les fitxes. (posar_carta -> a_tauler.posar_carta(..))

    for (int i = 0; i < a_tauler->n_columnes(); i++)
    {
        for (int j = 0; j < a_tauler->n_files(); j++)
        {
            Carta c = a_baralla->agafa_carta();
            if (i == j) c.revelar();
            a_tauler->posar_carta(i, j, c);
        }
    }
}

/*void Joc::repartirCartes() {
    tauler.repartir(baralla);
    while (baralla.teCartes()) {
        a_ma.empilar(baralla.obtenirSeguentCarta());
    }
}

void Joc::mostrarEstatDelJoc() const {
    std::cout << "ESTAT DEL JOC" << std::endl;
    std::cout << "Ma: " << a_ma.mostrarCim() << "  Descartades: " << a_descartades.mostrarCim() << std::endl;
    tauler.mostrar();
}*/

/*void Joc::mostraEstat() const {
    cout << "ESTAT DEL JOC" << endl << endl;

    // Mostra les piles dels pals
    cout << " ";
    for (int i = 0; i < 4; ++i) {
        if (piles[i] == NULL) {
            cout << "** ";
        }
        else {
            piles[i]->mostrar();
            cout << " ";
        }
    }
    cout << "   ";

    // Mostra les cartes a ma i descartades
    if (a_ma == NULL) {
        cout << "** ";
    }
    else {
        a_ma->mostrar();
        cout << " ";
    }

    if (a_descartades == NULL) {
        cout << "**";
    }
    else {
        a_descartades->mostrar();
    }
    cout << endl << endl;

    // Mostra el tauler
    a_tauler->mostra();

    cout << "JOC EN CURS" << endl;
}*/