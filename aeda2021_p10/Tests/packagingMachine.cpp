#include "packagingMachine.h"
#include <sstream>

PackagingMachine::PackagingMachine(int boxCap): boxCapacity(boxCap)
{}

unsigned PackagingMachine::numberOfBoxes() {
    return boxes.size();
}

unsigned PackagingMachine::addBox(Box& b1) {
    boxes.push(b1);
    return boxes.size();
}

HeapObj PackagingMachine::getObjects() const {
    return this->objects;
}

HeapBox PackagingMachine::getBoxes() const {
    return this->boxes;
}


unsigned PackagingMachine::loadObjects(vector<Object> &objs) {
    unsigned result =0;
	for(auto it = objs.begin(); it != objs.end(); it++)
    {
	    if((*it).getWeight() <= boxCapacity)
        {
	        objects.push(*it);
	        objs.erase(it);
	        it--;
	        result++;
        }
    }
	return result;
}

Box PackagingMachine::searchBox(Object& obj) {
	Box b;
	stack<Box> aux;
	while(!boxes.empty())
    {
	    if(boxes.top().getFree() >= obj.getWeight())
        {
	        b = boxes.top();
	        boxes.pop();
	        break;
        }
	    else
        {
	        aux.push(boxes.top());
	        boxes.pop();
        }
    }

	while(!aux.empty())
    {
	    boxes.push(aux.top());
	    aux.pop();
    }
	return b;
}


unsigned PackagingMachine::packObjects() {
    while(!objects.empty())
    {
        Object obj(objects.top().getID(),objects.top().getWeight());
        Box b = searchBox(obj);
        b.addObject(obj);
        boxes.push(b);
        objects.pop();
    }
    return boxes.size();
}


string PackagingMachine::printObjectsNotPacked() const {
    stringstream str;
    if(objects.empty())
        return "No objects!\n";

    HeapObj aux = objects;
    while(!aux.empty())
    {
	    Object obj(aux.top().getID(), aux.top().getWeight());
	    str << obj <<endl;
	    aux.pop();
    }
    return str.str();
}


Box PackagingMachine::boxWithMoreObjects() const {
	if(boxes.empty())
	    throw MachineWithoutBoxes();

    HeapBox temp = boxes;
	Box aux = temp.top();

	while(!temp.empty())
    {
        if (temp.top().getSize() > aux.getSize())
        {
            aux = temp.top();
        }
        temp.pop();
    }

	return aux;
}