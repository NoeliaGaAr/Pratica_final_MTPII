#include "PilaCartes.h"
#include <cmath>
#include <cstdlib>
using namespace std;

PilaCartes::PilaCartes() {
    a_cim = NULL;
}

PilaCartes::PilaCartes(const PilaCartes& o) {
    copia(o);
}

PilaCartes::~PilaCartes() {
    allibera();
}

bool PilaCartes::buida() const {
    return a_cim == NULL;
}

Carta PilaCartes::cim() const {
    //return a_cim->valor;
    if (!buida()) {
        return *(a_cim->valor);
    }
    //else { return NULL; }

}

void PilaCartes::empila(Carta c) {
    Node* nou = new Node;
    nou->valor = &c;
    nou->seg = a_cim;
    a_cim = nou;
}

Carta PilaCartes::desempila() {
    Carta carta = *(a_cim->valor);
    if (!buida()) {
        Node* aux = a_cim;
        a_cim = a_cim->seg;
        delete aux;
        return carta;
    }
}

PilaCartes& PilaCartes::operator=(const PilaCartes& o) {
    if (this != &o) {
        allibera();
        copia(o);
    }
    return *this;
}

void PilaCartes::copia(const PilaCartes& o) {
    if (o.buida()) {
        a_cim = NULL;
    }
    else {
        a_cim = new Node;
        a_cim->valor = o.a_cim->valor;
        Node* p = o.a_cim->seg;
        Node* q = a_cim;
        while (p != NULL) {
            q->seg = new Node;
            q = q->seg;
            q->valor = p->valor;
            p = p->seg;
        }
        q->seg = NULL;
    }
}

void PilaCartes::allibera() {
    while (!buida()) {
        desempila();
    }
}

void PilaCartes::mostrar() const {
    Node* actual = a_cim; // Comencem des del cim de la pila
    while (actual != NULL) {
        actual->valor->mostrar(); // Mostrem la carta actual
        cout << " "; // Afegim un espai per a la separació
        actual = actual->seg; // Avancem al següent node
    }
}
