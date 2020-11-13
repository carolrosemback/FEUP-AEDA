/*
 * BankOfficer.cpp
 */
#include "BankOfficer.h"

unsigned int BankOfficer::idBankOfficers = 1;
BankOfficer::BankOfficer(): id(0) {}

void BankOfficer::setName(string nm){
	name = nm;
}

string BankOfficer::getName() const{
	return name;
}

vector<Account *> BankOfficer::getAccounts() const {
	return myAccounts;
}

void BankOfficer::addAccount(Account *a) {
	myAccounts.push_back(a);
}

unsigned int BankOfficer::getID() const{
	return id;
}


// ----------------------------------------------------------------------------------------------


BankOfficer::BankOfficer(string name): name(name), id(idBankOfficers++), myAccounts(vector<Account*>()){}

bool BankOfficer::operator>(const BankOfficer &bo2) {
    if(myAccounts.size() == bo2.getAccounts().size())
            return name > bo2.getName();
    return myAccounts.size() > bo2.getAccounts().size();
}



