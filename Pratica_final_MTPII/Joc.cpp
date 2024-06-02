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

void Joc::inicialitzar_joc() 
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
        //cout << "Carta empilada: "; a_ma->cim().mostrar_debug(); cout << endl;
    }
}

void Joc::mostra_estat() const {
    cout << "ESTAT DEL JOC" << endl;
    // Mostrem les piles de colls (piles de pals)
    for (int i = 0; i < 4; ++i) {
        if (piles[i]->buida()) {
            cout << "   "; // Espai en blanc per a una pila buida
        }
        else {
            Carta cimPila = piles[i]->cim();
            cimPila.revelar();
            cimPila.mostrar();
            cout << "  ";
        }
    }
    cout << "   ";
    //Pila mà cartes
    Carta c = a_ma->cim();
    if (!c.es_visible()) {
        cout << "**";
    }
    else {
        c.mostrar();
    }
     c.mostrar(); 
    //Pila descartades; 
    Carta d = a_descartades->cim();
    if (!a_descartades->buida()) {
        d.revelar();
        d.mostrar();
    }
    else
    {
        cout << "";
    }
     cout << endl;
    a_tauler->mostra_tauler();

    cout << "JOC EN CURS" << endl;
}

void Joc::emplenar_tauler()
{
    // Nombres de columnes i files
    int n_col = a_tauler->n_columnes();
    int n_fil = a_tauler->n_files();

    // Per cada columna
    for (int i = 0; i < n_col; i++)
    {
        // Per cada fila dins de la columna, fins la fila i+1 (per limitar les files per columna)
        for (int j = 0; j <= i && j < n_fil; j++)
        {
            // Agafa una carta de la baralla
            Carta c = a_baralla->agafa_carta();
            
            // Revela la carta si és l'última de la columna (fila més baixa)
            if (j == i)
                c.revelar();

            // Col·loca la carta al tauler
            a_tauler->posar_carta(j, i, c);

            // Debugging
            /*c.mostrar_debug();
            cout << " posada a columna " << i+1 << ", fila " << j+1 << endl;*/
        }
    }
}

void Joc::obrir_una_carta() {
    // Comprovar si hi ha cartes a la mà
    if (!a_ma->buida()) {
        // Treure una carta de la mà
        //cout << "Carta al cim: "; a_ma->cim().mostrar_debug(); cout << endl;
        Carta carta = a_ma->cim();
        a_descartades->empila(carta);
        a_ma->desempila();
        /*cout << "------" << endl;
        cout << "Carta de la ma: "; carta.mostrar_debug(); cout << endl;
        cout << "------" << endl;*/
        // Posar la carta sobre la pila de descartades
        

        // Revelar la carta
        carta.revelar();
        //carta.mostrar_debug();
    }
    else {
        // Si la mà està buida, reciclar les cartes de la pila de descartades
        while (!a_descartades->buida()) {
            Carta carta = a_ma->cim();
            a_descartades->desempila();
            carta.amagar(); // Amagar les cartes abans de posar-les a la mà
            a_ma->empila(carta);
        }
    }
}

void Joc::posar_cartaMa_tauler(int columnaDesti) {
    // Comprovem si hi ha cartes a la pila de descartades
    if (a_descartades->buida()) {
        cout << "No hi ha cap carta a la pila de descartades." << endl;
    }
    columnaDesti = columnaDesti - 1;

    // Comprovem si la columna és vàlida
    if (!a_tauler->columna_valida(columnaDesti)) {
        cout << "La columna indicada no és vàlida." << endl;
    }

    // Obtenim la carta del cim de la pila de descartades
    Carta carta = a_descartades->cim();

    // Comprovem si la carta es pot posar a la columna
    if (a_tauler->columna_buida(columnaDesti)) {
        // Si la columna està buida, qualsevol carta pot ser-hi posada
        a_tauler->afegir_carta(columnaDesti, carta);
        a_descartades->desempila();
        cout << "Carta posada a la columna." << endl;
    }
    else {
        // Obtenim la carta al cim de la columna indicada
        Carta cimColumna = a_tauler->cim_columna(columnaDesti);

        // Comprovem si la carta es pot posar a la columna
        if ((cimColumna.valor() - carta.valor() == 1) &&
            (((carta.pal() == 'P' || carta.pal() == 'T') && (cimColumna.pal() == 'c' || cimColumna.pal() == 'd')) ||
                ((carta.pal() == 'c' || carta.pal() == 'd') && (cimColumna.pal() == 'P' || cimColumna.pal() == 'T')))) {
            a_tauler->afegir_carta(columnaDesti, carta);
            carta.revelar(); // Revelem la carta
            if (carta.es_visible()) carta.mostrar(); // Mostrem la carta
            a_descartades->desempila();
            cout << "Carta posada a la columna." << endl;
        }
        else {
            cout << "No es pot moure la carta a aquesta columna." << endl;
        }
    }
}

void Joc::posar_cartaMa_pila() {
    // Comprovem si la pila de descartades té almenys una carta.
    if (!a_descartades->buida()) {
        // Obtenim la carta del cim de la pila de descartades.
        Carta carta = a_descartades->cim();

        // Determinem a quina pila correspon la carta.
        int pilaDesti = -1;
        switch (carta.pal()) {
        case 'P': pilaDesti = 0; break;  // Piques
        case 'c': pilaDesti = 1; break;  // Cors
        case 'd': pilaDesti = 2; break;  // Diamants
        case 'T': pilaDesti = 3; break;  // Trèvols
        default: break;
        }

        // Si la carta pertany a una pila vàlida...
        if (pilaDesti != -1) {
            // Comprovem si la pila de destí està buida o si la carta del cim de la pila de descartades
            // és compatible amb la carta de la pila de destí.
            if ((piles[pilaDesti]->buida() && carta.valor() == 1) ||
                (!piles[pilaDesti]->buida() && piles[pilaDesti]->cim().valor() == carta.valor() - 1)) {
                // Movem la carta de la mà a la pila de destí.
                piles[pilaDesti]->empila(carta);  // Primer empilem la carta a la pila de destí
                a_descartades->desempila();  // Després eliminem la carta de la pila de descartades
                cout << "Carta " << carta.valor() << " de " << carta.pal() << " afegida a la pila de " << carta.pal() << "." << endl;
            }
            else {
                cout << "La carta no pot ser posada a la pila corresponent." << endl;
            }
        }
    }
    else {
        cout << "No hi ha cap carta per agafar de la mà per posar a les piles." << endl;
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