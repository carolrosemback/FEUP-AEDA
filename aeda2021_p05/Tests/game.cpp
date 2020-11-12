#include "game.h"
#include <cstdlib>
#include <ctime>
#include <iostream>
using namespace std;


unsigned int Game::numberOfWords(string phrase)
{
    if ( phrase.length() == 0 ) return 0;

    unsigned n=1;
    size_t pos = phrase.find(' ');
    while (pos != string::npos) {
        phrase = phrase.substr(pos+1);
        pos = phrase.find(' ');
        n++;
    }
    return n;
}

Game::Game()
{
    this->kids.clear(); //inicializa a lista kids
}

Game::Game(list<Kid>& l2)
{
    this->kids = l2; //inicializa a lista kids com l2
}


void Game::addKid(const Kid &k1)
{
    kids.push_back(k1);
}

list<Kid> Game::getKids() const
{
    return kids;
}

string Game::write() const
{
    stringstream oss;
    auto it = kids.begin();
    auto ite = kids.end();
    while(it != ite)
    {
        oss << it->write() << endl;
        it++;
    }
    return oss.str();
}


Kid& Game::loseGame(string phrase)
{
    int nwords = numberOfWords(phrase)-1;
    auto it = kids.begin();
    auto ite = kids.end();
    while(kids.size() > 1)
    {
        int nKids = kids.size();
        int p = nwords%nKids;
        for(int i =0; i < p; i++)
        {
            it++;
            if (it == ite )
                it = kids.begin();
        }
        cout << "leaves: " << it->write() << endl;
        it = kids.erase(it);
        if (it == ite ) it = kids.begin();
    }
    return *it;
}


list<Kid>& Game::reverse()
{
    kids.reverse();
    return this->kids;
}


list<Kid> Game::removeOlder(unsigned id)
{
    list<Kid> l1;
    list<Kid>::iterator it;
    for(it = kids.begin(); it != kids.end(); it++)
    {
        if((*it).getAge() > id)
        {
            l1.push_back(*it);
            it = kids.erase(it);
        }
    }
    return l1;
}


void Game::setKids(const list<Kid>& l1)
{
    this->kids = l1;
}


bool Game::operator==(Game& g2)
{
    /*
	if(kids == g2.kids)
	    return true;
	return false;
     */

  if( this->kids.size() != g2.kids.size() )
      return false;

    auto it1 = this->kids.begin();
    auto ite = this->kids.end();
    auto it2 = g2.kids.begin();

    for(; it1 != ite; it1++, it2++)
    {
        if( !((*it1) == (*it2)) )
            return false;
    }
    return true;
}


list<Kid> Game::shuffle() const
{
    list<Kid> tempList = this->kids;
    list<Kid> newList;

    int rPos;
    srand(time(NULL));

    while( !tempList.empty() )
    {
        rPos = rand() % tempList.size(); //random positions
        auto it = tempList.begin();
        for(int i = 0; i < rPos; i++, it++);
        newList.push_back(*it);
        tempList.erase(it);
    }
    return newList;
}
