#include "Warehouse.h"
#include <algorithm>

Warehouse::Warehouse()  {
}

queue<ThinTallBox> Warehouse::getBoxes() {
	return boxes;
}

queue<Object> Warehouse::getObjects() {
    return objects;
}

void Warehouse::setBoxes(queue<ThinTallBox> q) {
    while (!q.empty()) {
        boxes.push(q.front());
        q.pop();
    }
}

void Warehouse::addObject(Object o1) {
    objects.push(o1);
}


int Warehouse::InsertObjectsInQueue(vector <Object> obj){
    sort(obj.begin(), obj.end());
    auto it1 = obj.begin();
    auto ite = obj.end();
    while(it1 != ite) {
        objects.push(*it1);
        it1++;
    }
    return obj.size();
}

Object Warehouse::RemoveObjectQueue(int maxSize){
    Object obj, curr;
    obj.setName("dummy");
    obj.setSize(0);

    queue<Object> temp;
    bool found = false;
    while (!objects.empty())
    {
        curr = objects.front();
        objects.pop();
        if (!found && curr.getSize() <= maxSize)
        {
            obj = curr;
            found = true;
            continue;
        }
        temp.push(curr);
    }
    while (!temp.empty())
    {
        curr = temp.front();
        temp.pop();
        objects.push(curr);
    }
    return obj;
}

int Warehouse::addPackOfBoxes(vector <ThinTallBox> boV) {
    for(const auto  box : boV)
        boxes.push(box);
    return boxes.size();
}


vector<ThinTallBox> Warehouse::DailyProcessBoxes()
{
    queue<ThinTallBox> temp;
    vector<ThinTallBox> res;

    while (!boxes.empty())
    {
        ThinTallBox box = boxes.front();
        boxes.pop();
        if(box.full())
        {
            res.push_back(box);
            continue;
        }

        int leftSize = (int)(box.getCapacity() - box.getContentSize());
        Object toAdd = RemoveObjectQueue( leftSize );
        box.insert(toAdd);
        if(box.getDays() == 0)
            res.push_back(box);
        else {
            box.setDaysToSend(box.getDays()-1);
            temp.push(box);
        };
    }
    while(!temp.empty())
    {
        ThinTallBox box = temp.front();
        temp.pop();
        boxes.push(box);
    }
    return res;
}

