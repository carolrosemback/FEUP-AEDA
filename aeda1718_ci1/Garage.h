/*
 * Garage.h
 *
 *  Created on: 24/10/2017
 *      Author: hlc
 */

#ifndef SRC_GARAGE_H_
#define SRC_GARAGE_H_

#include <vector>
#include "Car.h"

template <class Vehicle>
class Garage {
	std::vector<Vehicle *> vehicles;
	const unsigned int capacity;
public:
	Garage(int size);
	~Garage();
	std::vector<Vehicle *> getVehicles() const;
	void setVehicles(std::vector<Vehicle *> vehicles);
	int getCapacity() const;
	bool addVehicle(Vehicle *vehicle);
	Vehicle* removeVehicle(std::string brand, std::string model);
	float avgPrice(std::string brand) const;
	void sortVehicles();
};

class NoSuchVehicleException {
public:
	NoSuchVehicleException() { }
};

class NoSuchBrandException{
private:
    std::string brand;
public:
    std::string getBrand(){return brand;}
    NoSuchBrandException(std::string br): brand(br){}
};

template <class Vehicle>
Garage<Vehicle>::Garage(int size) : capacity(size) {
}

template <class Vehicle>
Garage<Vehicle>::~Garage() {
	typename std::vector<Vehicle *>::const_iterator it;
	for (it=vehicles.begin(); it!=vehicles.end(); it++) {
		delete *it;
	}
}

template<class Vehicle>
std::vector<Vehicle *> Garage<Vehicle>::getVehicles() const {
	return vehicles;
}

template<class Vehicle>
void Garage<Vehicle>::setVehicles(std::vector<Vehicle*> vehicles) {
	this->vehicles = vehicles;
}

template<class Vehicle>
int Garage<Vehicle>::getCapacity() const {
	return capacity;
}

template<class Vehicle>
bool Garage<Vehicle>::addVehicle(Vehicle *vehicle) {
    if(vehicles.size() == getCapacity())
        return false;
    for(auto it = vehicles.begin(); it != vehicles.end(); it++)
    {
        if(*(*it) == (*vehicle))
            return false;
    }
    vehicles.push_back(vehicle);
    return true;
}
bool compVehicles(Car *c1, Car *c2)
{
    if(c1->getBrand() == c2->getBrand())
        return (c1->getPrice() > c2->getPrice());
    else
        return (c1->getBrand() < c2->getBrand());
}

template<class Vehicle>
void Garage<Vehicle>::sortVehicles() {
    sort(vehicles.begin(), vehicles.end(), compVehicles);
}

template<class Vehicle>
Vehicle *Garage<Vehicle>::removeVehicle(std::string brand, std::string model) {
    for (auto it = vehicles.begin(); it != vehicles.end(); it++) {
        if ((*it)->getBrand() == brand && (*it)->getModel() == model) {
            auto temp = *it;
            vehicles.erase(it);
            return temp;
        }
    }
    throw NoSuchVehicleException();
}

template<class Vehicle>
float Garage<Vehicle>::avgPrice(std::string brand) const {
    float sum =0;
    int count =0;
    for (auto it = vehicles.begin(); it != vehicles.end(); it++) {
        if ((*it)->getBrand() == brand){
            sum += (*it)->getPrice();
            count++;
        }
    }
    if(count == 0 )
        throw NoSuchBrandException(brand);

    return sum/count;
}

#endif /* SRC_GARAGE_H_ */
