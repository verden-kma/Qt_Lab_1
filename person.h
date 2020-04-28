//
// Created by Andrew on 20-Apr-20.
//

#ifndef PROJECTOOP_PERSON_H
#define PROJECTOOP_PERSON_H

#include <string>
#include <list>

class Person {
public:
    static const int Properties;
    Person(const std::string& name, const std::string& surname, int age, unsigned long long phoneNumber);

    const unsigned long long getId() const;

    bool hasPhoneNumber(unsigned long long number) const;

    const std::string& getName() const;

    void setName(const std::string& name);

    const std::string& getSurname() const;

    void setSurname(const std::string& surname);

    unsigned char getAge() const;

    void setAge(int age);

    bool addPhoneNumber(unsigned long long int newNumber);

    const std::list<unsigned long long int>& getPhoneNumbers() const;

    const char* infoExtract() const;

private:
    static unsigned int _freeID;
    static std::list<unsigned long long> allNumbers;

    static bool phoneNumIsValid(unsigned long long int newNumber);

    std::string _name;
    std::string _surname;
    unsigned char _age;
    unsigned int _id;

    std::list<unsigned long long> _phoneNumbers;
};

bool operator==(const Person&, const Person&);
std::ostream& operator<<(std::ostream&, const Person&);

#endif //PROJECTOOP_PERSON_H
