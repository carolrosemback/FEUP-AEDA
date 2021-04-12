#include "Gallery.h"
#include <ostream>
#include <algorithm>
using namespace std;

Gallery::Gallery(vector<Paint*> c): catalog(PaintCatalogItem("", "", 0, 0.00)), collection(c) {

}

vector<Paint*> Gallery::getCollection() const {
    return collection;
}

void Gallery::setCollection(vector<Paint*> c) {
    collection = c;
}

priority_queue<ExhibitionItem> Gallery::getPaintsToShow() const {
    return paintsToShow;
}
HashTableAuthorRecord Gallery::getAuthorRecords () const {
    return  authorRecords;
}

void Gallery::addAuthorRecord(AuthorRecord ar) {
    authorRecords.insert(ar);
}

void Gallery::generateCatalog() {
    catalog.makeEmpty();
    for(int i = 0; i < collection.size(); i++) {
        catalog.insert(collection[i]);
    }
}

BST<PaintCatalogItem> Gallery::getCatalog() const {
    return catalog;
}


void Gallery::prepareExhibition() {
    while( !paintsToShow.empty())
        paintsToShow.pop();
    for(int i = 0; i < collection.size(); i++) {
        ExhibitionItem ei(collection[i]);
        paintsToShow.push(ei);
    }
}

//-------------------------------------------------------------------------------

vector<Paint*> Gallery::getPaintsBy(string a) const {
    vector<Paint*> tmp;
    BSTItrIn<PaintCatalogItem> itrIn(catalog);
    while(!itrIn.isAtEnd()){
        if(itrIn.retrieve().getAuthor()==a){
            tmp.push_back(itrIn.retrieve().getPaint());
        }
        itrIn.advance();
    }
    return tmp;
}


vector<Paint*> Gallery::getPaintsBetween(int y1, int y2) const {
    vector<Paint*> tmp;
    BSTItrIn<PaintCatalogItem> itrIn(catalog);
    while(!itrIn.isAtEnd()){
        if(itrIn.retrieve().getYear() > y1 && itrIn.retrieve().getYear() < y2){
            tmp.push_back(itrIn.retrieve().getPaint());
        }
        itrIn.advance();
    }
    return tmp;
}


bool Gallery::updateTitle(Paint* p, string tnew) {
    BSTItrIn<PaintCatalogItem> itrIn(catalog);
    bool suceed=false;
    while(!itrIn.isAtEnd()){
        if(itrIn.retrieve().getYear()==p->getYear() && itrIn.retrieve().getAuthor()==p->getAuthor() && itrIn.retrieve().getTitle()==p->getTitle() && itrIn.retrieve().getPrice()==p->getPrice()){
            p->changeTitle(tnew);
            itrIn.retrieve().getPaint()->changeTitle(tnew);
            suceed=true;
        }
        itrIn.advance();
    }
    return suceed;

    }



//TODO
int Gallery::recordAvailablePainters() { //carrega a tabela de dispersao com AuthorRecords
    AuthorRecord authortmp("");
    for(auto& elem: collection){
        authortmp = AuthorRecord(elem->getAuthor());
        for(auto& author: authorRecords){
            if(elem->getAuthor() == author.getAuthor()){
                authortmp = author;
                authortmp.addAvaliablePaint();
                authorRecords.erase(author.getAuthor());
                break;
            }
        }
        authorRecords.insert(authortmp);
    }
    return authorRecords.size();
}

//TODO
double Gallery::totalSells() const {
    double sells = 0;
    for(const auto& elem: authorRecords){
        sells += elem.getTotalSells();
    }
    return sells;
}

//TODO
double Gallery::sellPaint(string a, string t) {
    AuthorRecord authortmp("");
    double sell = 0;
    for(auto& elem: collection){
        if(elem->getAuthor() == a && elem->getTitle() == t){
            authortmp = AuthorRecord(a);
            for(auto& author: authorRecords){
                if(author.getAuthor() == a){
                    authortmp = author;
                    authortmp.recordSell(elem->getPrice());
                    sell = elem->getPrice();
                    break;
                }
            }
            authorRecords.erase(a);
            authorRecords.insert(authortmp);
            collection.erase(find(collection.begin(),collection.end(),elem));
            break;
        }
    }
    return sell;
}

//TODO
vector<Paint*> Gallery::nBestExibition(int n, int maxPerYear) {  //escolhe as N mais caras pinturas, dos anos mais antigos, para realizar uma exposição
    vector<Paint*> tmp;
    priority_queue<ExhibitionItem> tmpPrioQ;
    int notMaxPerYear = maxPerYear;
    int yearChecking = paintsToShow.top().getYear();
    while(!paintsToShow.empty()){
        auto elem = paintsToShow.top().getPaint();
        if(elem->getYear() != yearChecking){
            notMaxPerYear = maxPerYear;
            yearChecking = elem->getYear();
        }
        if(!notMaxPerYear || !n) tmpPrioQ.push(elem);
        else{
            notMaxPerYear--;
            tmp.push_back(elem);
            n--;
        }
        paintsToShow.pop();
    }
    paintsToShow = tmpPrioQ;
    return tmp;
}

//TODO
int Gallery::itemExibitionOrder(string a, string t) {
    priority_queue<ExhibitionItem> show=paintsToShow;
    int counter =1;
    int indx = 0;
    while (!paintsToShow.empty()){
        if(paintsToShow.top().getAuthor()==a && paintsToShow.top().getTitle()==t){
            indx = counter;
        }
        counter++;
        paintsToShow.pop();
    }
    paintsToShow=show;
    return indx;
}

