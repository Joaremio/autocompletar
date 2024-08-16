#include "Termo.h"

Termo::Termo() : termo(""), peso(0) {}

Termo::Termo(const std::string& termo, int peso) : termo(termo), peso(peso) {}

int Termo::compararPeloPeso(const Termo& t1, const Termo& t2) {
    if (t1.peso > t2.peso) return 1;
    if (t1.peso < t2.peso) return -1;
    return 0;
}

int Termo::compararPeloPrefixo(const Termo& t1, const Termo& t2, int r) {
    std::string prefixo1 = t1.termo.substr(0, r);
    std::string prefixo2 = t2.termo.substr(0, r);

    if (prefixo1 < prefixo2) return -1;
    if (prefixo1 > prefixo2) return 1;
    return 0;
}

bool Termo::operator<(const Termo& t2) const {
    return termo < t2.termo;
}

std::ostream& operator<<(std::ostream& out, const Termo& t) {
    out << "(" << t.termo << ", " << t.peso << ")";
    return out;
}

const std::string& Termo::getTermo() const {
    return termo;
}

int Termo::getPeso() const {
    return peso;
}
