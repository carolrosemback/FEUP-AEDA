#ifndef SRC_HOTEL_H_
#define SRC_HOTEL_H_

#include <vector>
#include <list>

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
    int getFloor(){return floor;}
    NoSuchFloorException(int fl): floor(fl) { }
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

//TODO
template<class Chamber>
bool Hotel<Chamber>::addChamber(Chamber *chamber) {
    if(chambers.size() == maxCapacity)
        return false;
    for(int i = 0; i < chambers.size(); i++)
    {
        if(*chambers[i] == *chamber)
            return false;
    }
    chambers.push_back(chamber);
    return true;
}

bool compChamb(const Room* c1, const Room* c2)
{
    if(c1->getCode() < c2->getCode())
        return true;
    else if (c1->getCode() == c2->getCode())
    {
        if(c1->getFloor() > c2->getFloor())
            return true;
    }
    return false;
}

template<class Chamber>
void Hotel<Chamber>::sortChambers() {
    sort(chambers.begin(), chambers.end(), compChamb);
}


template<class Chamber>
Chamber* Hotel<Chamber>::removeChamber(std::string code, int floor) {
    Chamber *temp;
    for(auto it = chambers.begin(); it != chambers.end(); it++)
    {
        if((*it)->getCode() == code && (*it)->getFloor() == floor)
        {
            temp = *it;
            chambers.erase(it);
            return(temp);
        }
    }
   throw NoSuchChamberException();
}


template<class Chamber>
float Hotel<Chamber>::avgArea(int floor) const {
    float sum = 0;
    int count = 0;
    for(auto it= chambers.begin(); it!= chambers.end(); it++)
    {
        if((*it)->getFloor() == floor)
        {
            sum += (*it)->getArea();
            count++;
        }
    }
    float med = sum/count;

    if(count ==0)
        throw NoSuchFloorException(floor);
    return med;
}


template<class Chamber>
bool Hotel<Chamber>::doReservation(std::string code, int floor){
    for(auto it= chambers.begin(); it!= chambers.end(); it++)
    {
        if((*it)->getFloor() == floor && (*it)->getCode() == code)
        {
            if((*it)->getReservation() == true)
                return false;
            else {
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
    std::list<Chamber> res;
    bool found;
    for(auto it= chambers.begin(); it!= chambers.end(); it++)
    {
        for(auto itr = reservationsDone.begin(); itr != reservationsDone.end(); itr++) {

            if ((*it)->getCode() == (itr)->getCode() && (*it)->getFloor() == (itr)->getFloor()) {
                found = true;
                break;
            }
        }
        if(!found)
            res.push_back(*(*it));
        found = false;
    }
        return res;
}



#endif /* SRC_HOTEL_H_ */
