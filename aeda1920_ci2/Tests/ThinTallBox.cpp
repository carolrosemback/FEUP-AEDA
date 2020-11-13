#include <algorithm>
#include "ThinTallBox.h"
#include "WideFlatBox.h"

ThinTallBox::ThinTallBox(double capacity) : Box(capacity) {
}

ThinTallBox::ThinTallBox(double capacity, stack<Object> objects, double content_size) : Box(capacity) {
	this->objects = objects;
	this->setContentSize(content_size);
}

stack<Object> ThinTallBox::getObjects() const {
    return objects;
}

void ThinTallBox::remove(Object object) {
	Object next_object = next();
	if(!(next_object == object)) {
		throw InaccessibleObjectException(object);
	} else {
		setContentSize(getContentSize()-next_object.getSize());
		objects.pop();
	}
}

const Object& ThinTallBox::next() const {
	return objects.top();
}


void ThinTallBox::insert(Object object) {
    if(getCapacity() == getContentSize() || getCapacity() < getContentSize()+object.getSize())
        throw ObjectDoesNotFitException();
    else
    {
        objects.push(object);
        setContentSize(getContentSize()+object.getSize());
    }

}

void ThinTallBox::sortObjects()
{
    std::vector<Object> sortedObjects;
    while(!objects.empty()){
        sortedObjects.push_back(objects.top());
        objects.pop();
    }
    std::sort(sortedObjects.begin(), sortedObjects.end());
    for(const auto & object : sortedObjects)
        objects.push(object);
}