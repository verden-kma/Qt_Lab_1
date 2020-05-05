#include <stdexcept>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <QRegularExpression>
#include "Models/Person.h"

using namespace std;
unsigned int Person::_freeID = 0;
const int Person::Properties = 5; // id, name, surname, age, phoneNumbers
list<unsigned long long> Person::allNumbers;

Person::Person(const QString& name, const QString& surname, int age,
               unsigned long long phoneNumber) : _id(_freeID++), _name(name), _surname(surname), _age(age) {
    if (age < 0 || age > 135) throw invalid_argument("correct age is [0;135]");
    if (!phoneNumIsNew(phoneNumber)) throw invalid_argument("phone number duplicated");
    if (phoneNumber == 0) return; // default person for view
    _primaryNumber = phoneNumber;
    _phoneNumbers.push_back(phoneNumber);
    allNumbers.push_back(phoneNumber);
}

bool Person::hasPhoneNumber(unsigned long long number) const {
    auto phonesIterator = _phoneNumbers.cbegin();
    while (phonesIterator != _phoneNumbers.end()) {
        if (*phonesIterator == number)
            return true;
        phonesIterator++;
    }
    return false;
}

bool operator==(const Person& p1, const Person& p2) {
    return p1.getId() == p2.getId();
}

ostream& operator<<(ostream& os, const Person& p) {
    os << p.getName().toStdString() << " " << p.getSurname().toStdString() << " " << to_string(p.getAge()) << " years old";
    return os;
}

const QString& Person::getName() const {
    return _name;
}

void Person::setName(const QString& name) {
    _name = name;
}

const QString& Person::getSurname() const {
    return _surname;
}

void Person::setSurname(const QString& surname) {
    _surname = surname;
}

unsigned char Person::getAge() const {
    return _age;
}

void Person::setAge(int age) {
    if (age < 0 || age > 135) throw invalid_argument("valid age [0;135]");
    _age = age;
}

unsigned long long Person::getId() const {
    return _id;
}

unsigned long long int Person::getPrimaryNumber() const {
    return _primaryNumber;
}

bool Person::setPrimaryNumber(unsigned long long int nprn) {
    _primaryNumber = nprn;
    if (std::find(_phoneNumbers.begin(), _phoneNumbers.end(), nprn) != _phoneNumbers.end()) {
        return false;
    }
    else {
        _phoneNumbers.push_back(nprn);
        return true;
    }
}

list<unsigned long long int>& Person::peekPhoneNumbers() {
    return _phoneNumbers;
}

bool Person::addPhoneNumber(unsigned long long int newNumber) {
    if (!phoneNumIsNew(newNumber)) return false;
    allNumbers.push_back(newNumber);
    _phoneNumbers.push_back(newNumber);
    return true;
}

bool Person::removePhoneNumber(unsigned long long int number) {
    if (_phoneNumbers.size() == 1) return false;
    _phoneNumbers.remove(number);
    return true;
}

bool Person::phoneNumIsNew(unsigned long long int newNumber) {
    auto phonesIterator = allNumbers.cbegin();
    while (phonesIterator != allNumbers.end()) {
        if (*phonesIterator == newNumber)
            return false;
        phonesIterator++;
    }
    return true;
}

bool Person::numberIsValid(const QString& newNum) {
    static QRegularExpression rx("^\\d{11,13}$");
    return rx.match(newNum).hasMatch();
}
















