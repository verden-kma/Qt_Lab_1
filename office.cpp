//
// Created by Andrew on 20-Apr-20.
//

#include <cstring>
#include <ostream>
#include "office.h"

using namespace std;

Office::Office(const std::vector<Person *>& people) {
    auto peopleItr = people.begin();
    while (peopleItr != people.end()) {
        _people.push_back(*peopleItr);
        peopleItr++;
    }
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

const list<Person*> Office::findByID(unsigned int id) const {
    list<Person*> res;
    auto peopleItr = _people.begin();
    while (peopleItr != _people.end()) {
        if ((*peopleItr)->getId() == id) {
            res.push_back(*peopleItr);
            return res;
        }
        peopleItr++;
    }
    return res;
}

const list<Person*> Office::findByName(const std::string& name) const {
    list<Person*> res;
    auto peopleItr = _people.begin();
    while (peopleItr != _people.end()) {
        if ((*peopleItr)->getName() == name)
            res.push_back(*peopleItr);
        peopleItr++;
    }
    return res;
}

const list<Person*> Office::findBySurname(const std::string& surname) const {
    list<Person*> res;
    auto peopleItr = _people.begin();
    while (peopleItr != _people.end()) {
        if ((*peopleItr)->getSurname() == surname)
            res.push_back(*peopleItr);
        peopleItr++;
    }
    return res;
}


const list<Person*> Office::findByAge(int age) const {
    list<Person*> res;
    auto peopleItr = _people.begin();
    while (peopleItr != _people.end()) {
        if ((*peopleItr)->getAge() == age)
            res.push_back(*peopleItr);
        peopleItr++;
    }
    return res;
}

const std::list<Person*> Office::findByPhoneNumber(BigInt number) const {
    list<Person*> res;
    auto peopleItr = _people.begin();
    while (peopleItr != _people.end()) {
        if ((*peopleItr)->hasPhoneNumber(number)) {
            res.push_back(*peopleItr);
            return res;
        }
        peopleItr++;
    }
    return res;
}

std::vector<Person*> Office::getPeople() const {
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
