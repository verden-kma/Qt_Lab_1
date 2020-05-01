//
// Created by Andrew on 20-Apr-20.
//

#ifndef PROJECTOOP_SECUREOFFICE_H
#define PROJECTOOP_SECUREOFFICE_H


#include <vector>
#include "person.h"

using BigInt = unsigned long long;

class Office {
public:
    Office() = default;
    ~Office();

    explicit Office(const std::vector<Person *>& people);

    void addPerson(Person*);

    const std::list<Person*> findByID(unsigned int id) const; // had to be optional, but empty list has wider support

    const std::list<Person*> findByName(const std::string&) const;

    const std::list<Person*> findBySurname(const std::string&) const;

    const std::list<Person*> findByPhoneNumber(BigInt number) const;

    const std::list<Person*> findByAge(int age) const;

    std::vector<Person*> getPeople() const;

    const std::vector<Person*>& peekPeople() const;

    bool remove(const Person*);

    friend std::ostream& operator<<(std::ostream&, const Office&);

private:
    std::vector<Person*> _people;
};


#endif //PROJECTOOP_SECUREOFFICE_H
