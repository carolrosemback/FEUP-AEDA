#include "player.h"


void Player::addBet(const Bet& b)
{
        bets.insert(b);
}


unsigned Player::betsInNumber(unsigned num) const
{
    unsigned total =0;
	for(auto it = bets.begin(); it != bets.end(); it++)
    {
	    if((*it).contains(num))
	        total++;
    }
	return total;
}


tabHBet Player::drawnBets(const tabHInt& draw) const
{
	tabHBet money;
	for(auto it = bets.begin(); it != bets.end(); it++)
    {
	    if((*it).countRights(draw) >= 3)
	        money.insert(*it);
    }

	return money;
}
