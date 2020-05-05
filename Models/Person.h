#ifndef PROJECTOOP_PERSON_H
#define PROJECTOOP_PERSON_H

#include <list>
#include <QString>

class Person {
public:
    static const int Properties;

    Person(const QString& name, const QString& surname, int age, unsigned long long phoneNumber);

    unsigned long long getId() const;

    bool hasPhoneNumber(unsigned long long number) const;

    const QString& getName() const;

    void setName(const QString& name);

    const QString& getSurname() const;

    void setSurname(const QString& surname);

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

    //const char* infoExtract() const;

    static bool numberIsValid(const QString&);

private:
    static unsigned int _freeID;
    static std::list<unsigned long long> allNumbers;

    static bool phoneNumIsNew(unsigned long long int newNumber);

    unsigned int _id;
    QString _name;
    QString _surname;
    unsigned char _age;
    unsigned long long _primaryNumber;

    std::list<unsigned long long> _phoneNumbers;
};

bool operator==(const Person&, const Person&);
std::ostream& operator<<(std::ostream&, const Person&);

#endif //PROJECTOOP_PERSON_H
