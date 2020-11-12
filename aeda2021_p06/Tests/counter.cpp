#include <queue>
#include <cstdlib>
#include "counter.h"
#include "exceptions.h"
using namespace std;


Client::Client() {
    numGifts = rand()%5 + 1;
}

unsigned Client::getNumGifts() const {
    return numGifts;
}



Counter::Counter(unsigned wt): wrappingTime(wt) {
    numAttendedClients = 0;
    nextEnter = (rand()%20)+1;
    nextLeave = 0;
    actualTime = 0;

}


unsigned Counter::getActualTime() const {
    return actualTime;
}


unsigned Counter::getNextEnter() const {
    return nextEnter;
}

unsigned Counter::getNumAttendedClients() const {
    return numAttendedClients;
}


unsigned Counter::getWrappingTime() const {
    return wrappingTime;
}


unsigned Counter::getNextLeave() const {
    return nextLeave;
}


Client & Counter::getNextClient() {
    if(clients.empty())
        throw EmptyQueue();
    return clients.front();
}


void Counter::enter()
{
    cout << "time: " << actualTime<< endl;
    Client c1;
    if(clients.empty())
        nextLeave = actualTime + c1.getNumGifts()*wrappingTime;

    clients.push(c1);
    cout << "entering a new client with " << c1.getNumGifts() << " gifts" << endl;
    nextEnter = actualTime + (rand()%20)+1;
}


void Counter::leave()
{
    cout << "time= " << actualTime << endl;
    Client cl1;
    try {
        cl1 = getNextClient();
    }
    catch (EmptyQueue &e) {
        cout << e.getMsg() << endl;
        return;
    }
    clients.pop();
    cout << "client attended: " << cl1.getNumGifts() << " gifts" << endl;
    numAttendedClients++;
    if (clients.empty())
        nextLeave = actualTime + clients.front().getNumGifts()*wrappingTime;
}


void Counter:: nextEvent()
{
    if (clients.empty()==false) {
        if (nextEnter < nextLeave) {
            actualTime = nextEnter;
            enter();
        }
        else {
            actualTime = nextLeave;
            leave();
        }
    }
    else {
        actualTime = nextEnter;
        enter();
    }
}


ostream & operator << (ostream & out, const Counter & c2)
{
     out << "Number of attended clients: " << c2.getNumAttendedClients() << endl;
     out << "Number of waiting clients: " << c2.clients.size() << endl;
     return out;
}


