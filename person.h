//
// Created by Andrew on 20-Apr-20.
//

#ifndef PROJECTOOP_PERSON_H
#define PROJECTOOP_PERSON_H

#include <string>
#include <list>
class QString;

class Person {
public:
    static const int Properties;
    Person(const std::string& name, const std::string& surname, int age, unsigned long long phoneNumber);

    unsigned long long getId() const;

    bool hasPhoneNumber(unsigned long long number) const;

    const std::string& getName() const;

    void setName(const std::string& name);

    const std::string& getSurname() const;

    void setSurname(const std::string& surname);

    unsigned char getAge() const;

    void setAge(int age);

    unsigned long long int getPrimaryNumber() const;

    /**
     * @brief setPrimaryNumber
     * @param nprn new prime number
     * @return true if passed number is new, false if it is present in phoneNumberList
     */
    bool setPrimaryNumber(unsigned long long int nprn);

    bool addPhoneNumber(unsigned long long int newNumber);

    bool removePhoneNumber(unsigned long long int number);

    std::list<unsigned long long int>& peekPhoneNumbers();

    const char* infoExtract() const;

    static bool numberIsValid(const QString&);

private:
    static unsigned int _freeID;
    static std::list<unsigned long long> allNumbers;

    static bool phoneNumIsNew(unsigned long long int newNumber);

    unsigned int _id;
    std::string _name;
    std::string _surname;
    unsigned char _age;
    unsigned long long _primaryNumber;

    std::list<unsigned long long> _phoneNumbers;
};

bool operator==(const Person&, const Person&);
std::ostream& operator<<(std::ostream&, const Person&);

#endif //PROJECTOOP_PERSON_H
