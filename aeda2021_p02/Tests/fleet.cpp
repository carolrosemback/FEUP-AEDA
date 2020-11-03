#include "fleet.h"
#include <string>

using namespace std;

vector<Vehicle *> Fleet::getVehicles() const {
    return vehicles;
}

void Fleet::addVehicle(Vehicle *v1) {
    vehicles.push_back(v1);
}

int Fleet::numVehicles() const{
    return vehicles.size();
}
int Fleet::lowestYear() const{
    if (vehicles.size()==0)
        return 0;
    auto it=vehicles.begin();
    int menorA=(*it)->getYear();
    it++;
    while(it!=vehicles.end()) {
        int ano1=(*it)->getYear();
        if (ano1<menorA) menorA=ano1;
        it++;
    }
    return menorA;
}

ostream &operator<<(ostream &o, const Fleet &f) {
    for(auto it = f.vehicles.begin(); it != f.vehicles.end(); it++){
        (*it)->info();
    }
}

vector<Vehicle *> Fleet::operator()(int yearM) const {
    vector<Vehicle *> vehiclesYear;
    if (vehicles.size()==0)
        return vehiclesYear;
    auto it = vehicles.begin();
    while(it != vehicles.end())
    {
        if((*it)->getYear() == yearM)
            vehiclesYear.push_back(*it);
        it++;
    }
    return vehiclesYear;
}

float Fleet::totalTax() const{
    float count = 0;
    if (vehicles.size()==0)
        return 0;
    for(auto vehicle : vehicles)
    {
        count += (vehicle->calculateTax());
    }
    return count;
}

unsigned Fleet::removeOldVehicles(int y1){
    int n=0;
    vector<Vehicle *>::const_iterator it = vehicles.begin();
    while(it != vehicles.end())
    {
        if ((*it)->getYear()<= y1)
        {
            it = vehicles.erase(it);
            n++;
        }
        else
            it++;
    }
    return n;
}


