#include "Termo.h"

Termo::Termo(){
    termo = "";
    peso = 0;
} 

Termo::Termo(const string termo_, int peso_){
    termo = termo_;
    peso = peso_;
} 

int Termo::compararPeloPeso(const Termo& t1, const Termo& t2) {
    if (t1.peso > t2.peso) {
        return 1;
    }else if (t1.peso==t2.peso){
        return 0;
    }else{
        return -1;
    }
}

int Termo::compararPeloPrefixo(const Termo& t1, const Termo& t2, int r) {
    string pref1 = t1.termo.substr(0, r);
    string pref2 = t2.termo.substr(0, r);

    if (pref1 > pref2){
        return 1;
    }else if(pref1==pref2){
        return 0;
    }else{
        return -1;
    }
}

bool Termo::operator<(const Termo& t2) const {
    return termo < t2.termo;
}

std::ostream& operator<<(std::ostream& out, const Termo& t) {
    out << "(" << t.termo << ", " << t.peso << ")";
    return out;
}

int Termo::getPeso() const {
    return peso;
}

const string& Termo::getTermo() const {
    return termo;
}

