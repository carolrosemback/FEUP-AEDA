#ifndef SRC_HOTEL_H_
#define SRC_HOTEL_H_

#include <vector>
#include <list>
#include <algorithm>

template <class Chamber>
class Hotel {
	std::vector<Chamber *> chambers;
	const unsigned int maxCapacity;
	const std::string city;
    std::list<Chamber> reservationsDone;
public:
	Hotel(int size, std::string municipality);
	~Hotel();
	std::vector<Chamber *> getChambers() const;
	void setChambers(std::vector<Chamber *> chambers);
	int getCapacity() const;
    std::list<Chamber> getReservationsDone() const;
	bool addChamber(Chamber *chamber);
    void addReservationDone(Chamber chamber);
    Chamber* removeChamber(std::string code, int floor);
	float avgArea(int floor) const;
	void sortChambers();
	bool doReservation(std::string code, int floor);
    std::list<Chamber> roomsNeverReserved() const;
};

class NoSuchChamberException {
public:
	NoSuchChamberException() { }
};

class NoSuchFloorException {
private:
    int floor;
public:
    NoSuchFloorException(int fl): floor(fl){};
    int getFloor() const { return floor;};

};

template <class Chamber>
Hotel<Chamber>::Hotel(int size, std::string municipality) : maxCapacity(size), city(municipality) {
}

template <class Chamber>
Hotel<Chamber>::~Hotel(){
	typename std::vector<Chamber *>::const_iterator it;
	for (it=chambers.begin(); it!=chambers.end(); it++) {
		delete *it;
	}
}

template<class Chamber>
std::vector<Chamber *> Hotel<Chamber>::getChambers() const {
	return chambers;
}

template<class Chamber>
void Hotel<Chamber>::setChambers(std::vector<Chamber*> chambers) {
	this->chambers = chambers;
}

template<class Chamber>
int Hotel<Chamber>::getCapacity() const {
	return maxCapacity;
}

template<class Chamber>
void Hotel<Chamber>::addReservationDone(Chamber chamber) {
    reservationsDone.push_back(chamber);
}

template<class Chamber>
std::list<Chamber> Hotel<Chamber>::getReservationsDone() const {
    return reservationsDone;
}

//------------------------------------------------------
//------------------------------------------------------


template<class Chamber>
bool Hotel<Chamber>::addChamber(Chamber *chamber) {
    if(maxCapacity == chambers.size())
        return false;
    else {
        for(int i =0; i < chambers.size(); i++)
        {
            if((*chambers[i]) == (*chamber))
                return false;
        }
        chambers.push_back(chamber);
        return true;
    }
}


bool compChamber(const Room* r1, const Room* r2){
    if(r1->getCode() < r2->getCode())
        return true;
    if (r1->getCode() == r2->getCode())
    {
        if(r1->getFloor() > r2->getFloor())
            return true;
    }
    return false;
}

template<class Chamber>
void Hotel<Chamber>::sortChambers() {
    sort(chambers.begin(), chambers.end(), compChamber);
}


template<class Chamber>
Chamber* Hotel<Chamber>::removeChamber(std::string code, int floor) {
    auto it = chambers.begin();
    auto ite = chambers.end();
    Chamber *temp;
    while(it != ite)
    {
        if ((*it)->getCode() == code && (*it)->getFloor() == floor)
        {
            temp = *it;
            chambers.erase(it);
            return (temp);
        }
        it++;
    }
        throw NoSuchChamberException();

}


template<class Chamber>
float Hotel<Chamber>::avgArea(int floor) const
{
    auto it = chambers.begin();
    auto ite = chambers.end();
    int size= 0;
    float count = 0;
    while(it != ite)
    {
        if ((*it)->getFloor() == floor)
        {
            count += (*it)->getArea();
            size++;
        }
        it++;
    }
    if(count == 0)
        throw NoSuchFloorException(floor);

    count = count/size;
return count;
}


template<class Chamber>
bool Hotel<Chamber>::doReservation(std::string code, int floor){
    for(auto it = chambers.begin(); it != chambers.end(); it++)
    {
        if((*it)->getCode() == code && (*it)->getFloor() == floor)
        {
            if((*it)->getReservation() == true)
                return false;
            else
            {
                (*it)->setReservation(true);
                reservationsDone.push_back(*(*it));
                return true;
            }
        }
    }
    return false;
}


template<class Chamber>
std::list<Chamber> Hotel<Chamber>::roomsNeverReserved() const {
    std::list<Chamber> notReserved;
    bool found = false;
    for(auto it = chambers.begin(); it != chambers.end(); it++)
    {
        for(auto itr = reservationsDone.begin(); itr != reservationsDone.end(); itr++)
        {
            if((*it)->getCode() == (itr)->getCode() && (*it)->getFloor() == (itr)->getFloor()){
                found = true;
                break;
            }
        }
        if(!found)
        notReserved.push_back(*(*it));

        found= false;

    }
    return notReserved;
}






#endif /* SRC_HOTEL_H_ */
