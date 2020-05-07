#include <QString>
#include <ostream>
#include "Models/Office.h"

using namespace std;

Office::Office(const std::vector<Person *>& people) {
    auto peopleItr = people.begin();
    while (peopleItr != people.end()) {
        _people.push_back(*peopleItr);
        peopleItr++;
    }
}

Office::~Office() {
    for (Person* p : _people)
        delete p;
}

void Office::addPerson(Person* p) {
    _people.push_back(p);
}

bool Office::remove(const Person* p) {
    auto peopleIter = _people.begin();
    while (peopleIter != _people.end()) {
        if (**peopleIter == *p) {
            _people.erase(peopleIter);
            return true;
        }
        peopleIter++;
    }
    return false;
}

bool Office::remove(uint index) {
    if (_people.size() >= index) return false;
    _people.erase(_people.begin() + index);
    return true;
}

const list<Person*> Office::findByID(const QVariant id) {
    list<Person*> res;
    auto peopleItr = _people.begin();
    while (peopleItr != _people.end()) {
        if ((*peopleItr)->getId() == id.toUInt()) {
            res.push_back(*peopleItr);
            return res;
        }
        peopleItr++;
    }
    return res;
}

const list<Person*> Office::findByName(const QVariant name) {
    list<Person*> res;
    auto peopleItr = _people.begin();
    while (peopleItr != _people.end()) {
        if ((*peopleItr)->getName() == name.toString())
            res.push_back(*peopleItr);
        peopleItr++;
    }
    return res;
}

const list<Person*> Office::findBySurname(const QVariant surname) {
    list<Person*> res;
    auto peopleItr = _people.begin();
    while (peopleItr != _people.end()) {
        if ((*peopleItr)->getSurname() == surname.toString())
            res.push_back(*peopleItr);
        peopleItr++;
    }
    return res;
}


const list<Person*> Office::findByAge(const QVariant age) {
    list<Person*> res;
    auto peopleItr = _people.begin();
    while (peopleItr != _people.end()) {
        if ((*peopleItr)->getAge() == age.toInt())
            res.push_back(*peopleItr);
        peopleItr++;
    }
    return res;
}

const std::list<Person*> Office::findByPhoneNumber(const QVariant number) {
    list<Person*> res;
    auto peopleItr = _people.begin();
    while (peopleItr != _people.end()) {
        if ((*peopleItr)->hasPhoneNumber(number.toULongLong())) {
            res.push_back(*peopleItr);
            return res;
        }
        peopleItr++;
    }
    return res;
}

std::vector<Person*>& Office::peekPeople() {
    return _people;
}

std::ostream& operator<<(std::ostream& os, const Office& secOff) {
    auto peopleItr = secOff._people.begin();
    while (peopleItr != secOff._people.end()) {
        os << *peopleItr << endl;
        peopleItr++;
    }
    return os;
}

void Office::clearShellow() {
    _people.clear();
}




















