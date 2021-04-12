#include "bet.h"
#include <iostream>
#include <sstream>
using namespace std;


bool Bet::contains(unsigned num) const
{
        return (numbers.find(num) != numbers.end());
}

void Bet::generateBet(const vector<unsigned>& values, unsigned n)
{
   unsigned tries = 0;
   for(auto it = values.begin(); it != values.end(), tries<n; it++)
   {
       if(numbers.find(*it) == numbers.end())
       {
           numbers.insert(*it);
           tries++;
       }
   }
}

//TODO
unsigned Bet::countRights(const tabHInt& draw) const
{
    unsigned right=0;
    for(auto it = draw.begin(); it != draw.end(); it++)
    {
        if(numbers.find(*it) != numbers.end())
            right++;
    }

    return right;
}
