#include "animal.h"
#include <sstream>
using namespace std;

string Animal::getName() const {
	return name;
}

int Animal::getAge() const {
    return age;
}

void Animal::setVeterinary(Veterinary *vet) {
    this->vet = vet;
}

Veterinary *Animal::getVeterinary() const {
    return vet;
}

Animal::Animal(string name, int age) {
    this->name = name;
    this->age = age;
    if( age < youngest ) youngest = age;

}
int Animal::youngest = 999;

int Animal::getYoungest() {
    return youngest;
}


string Animal::getInfo() const {
    stringstream ss;
    ss << name << ", " << age;
    if (vet != NULL) ss << ", " << vet->getInfo();
    return ss.str();
}



///////////////////DOG////////////////////

Dog::Dog(string name, int age, string breed): Animal(name, age)
{
    this->breed = breed;

}

bool Dog::isYoung() const {
    if (age < 5)
        return true;
    else
        return false;
}

string Dog::getInfo() const {
    stringstream ss;
    ss << Animal::getInfo() << ", " << breed;
    return ss.str();
}


///////////////////////FLYING//////////////////////

Flying::Flying(int maxv, int maxa)
{
    maxVelocity = maxv;
    maxAltitude= maxa;
}

string Flying::getInfo() const {
    stringstream ss;
    ss << maxVelocity << ", " << maxAltitude;
    return ss.str();
}


//////////////////////BAT///////////////////////

Bat::Bat(string name, int age, int maxv, int maxa): Animal(name, age), Flying(maxv, maxa) {}

bool Bat::isYoung() const {
    if (age < 4)
        return true;
    else
        return false;
}

string Bat::getInfo() const {
    stringstream ss;
    ss << Animal::getInfo() << ", " << Flying::getInfo();
    return ss.str();
}