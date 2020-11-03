#include "veterinary.h"
#include <sstream>
using namespace std;

string Veterinary::getName() const {
    return name;
}

Veterinary::Veterinary(string nome, int cod) {
    this->name = nome;
    this->codOrder = cod;
}

string Veterinary::getInfo() const {
    stringstream ss;
    ss << name << ", " << codOrder;
    return ss.str();
}


