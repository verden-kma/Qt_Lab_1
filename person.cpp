//
// Created by Andrew on 20-Apr-20.
//

#include <stdexcept>
#include <string.h>
#include <iostream>
#include <algorithm>
#include "person.h"

using namespace std;
unsigned int Person::_freeID = 0;
const int Person::Properties = 5; // id, name, surname, age, phoneNumbers
list<unsigned long long> Person::allNumbers;

Person::Person(const string& name, const string& surname, int age,
               unsigned long long phoneNumber) : _name(name), _surname(surname), _age(age), _primaryNumber(phoneNumber),  _id(_freeID++) {
    if (age < 0 || age > 135) throw invalid_argument("correct age [0;135]");
    if (!phoneNumIsValid(phoneNumber)) throw invalid_argument("phone number duplicated");
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

const char* Person::infoExtract() const {
    string data;
    data.append("ID: ").append(to_string(_id)).append("\n");
    data.append("Name: ").append(_name).append("\n");
    data.append("Surname: ").append(_surname).append("\n");
    data.append("Age: ").append(to_string(_age)).append("\n");
    for (size_t i = 0; i < _phoneNumbers.size(); i++)
        data.append("Phone number #").append(to_string(i + 1)).append(": ")
                .append(to_string(*next(_phoneNumbers.begin(), i))).append("\n");
    char* result = new char[data.size() + 1];
    strcpy_s(result, data.size() + 1, data.c_str());
    return result;
}

bool operator==(const Person& p1, const Person& p2) {
    return p1.getId() == p2.getId();
}

ostream& operator<<(ostream& os, const Person& p) {
    os << p.getName() << " " << p.getSurname() << " " << to_string(p.getAge()) << " years old";
    return os;
}

const string& Person::getName() const {
    return _name;
}

void Person::setName(const string& name) {
    _name = name;
}

const string& Person::getSurname() const {
    return _surname;
}

void Person::setSurname(const string& surname) {
    _surname = surname;
}

unsigned char Person::getAge() const {
    return _age;
}

void Person::setAge(int age) {
    if (age < 0 || age > 135) throw invalid_argument("valid age [0;135]");
    _age = age;
}

const unsigned long long Person::getId() const {
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

const list<unsigned long long int>& Person::peekPhoneNumbers() const {
    return _phoneNumbers;
}

bool Person::addPhoneNumber(unsigned long long int newNumber) {
    if (!phoneNumIsValid(newNumber)) return false;
    allNumbers.push_back(newNumber);
    _phoneNumbers.push_back(newNumber);
    return true;
}

bool Person::removePhoneNumber(unsigned long long int number) {
    if (_phoneNumbers.size() == 1) return false;
    _phoneNumbers.remove(number);
    return true;
}

bool Person::phoneNumIsValid(unsigned long long int newNumber) {
    auto phonesIterator = allNumbers.cbegin();
    while (phonesIterator != allNumbers.end()) {
        if (*phonesIterator == newNumber)
            return false;
        phonesIterator++;
    }
    return true;
}
