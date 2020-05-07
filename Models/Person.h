#ifndef PROJECTOOP_PERSON_H
#define PROJECTOOP_PERSON_H

#include <unordered_set>
#include <list>
#include <QString>

class Person {
public:
    static const int Properties;

    Person(const QString& name, const QString& surname, int age, unsigned long long phoneNumber);

    ~Person();

    uint getId() const;

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
    bool setPrimaryNumber(qulonglong nprn);

    bool addPhoneNumber(qulonglong newNumber);

    bool removePhoneNumber(qulonglong number);

    std::list<qulonglong>& peekPhoneNumbers();

    //const char* infoExtract() const;

    static bool numberIsValid(const QString&);

private:
    static uint _freeID;
    static std::unordered_set<qulonglong> allNumbers;

    static bool phoneNumIsNew(qulonglong newNumber);

    uint _id;
    QString _name;
    QString _surname;
    unsigned char _age;
    qulonglong _primaryNumber;

    std::list<qulonglong> _phoneNumbers;
};

bool operator==(const Person&, const Person&);
std::ostream& operator<<(std::ostream&, const Person&);

#endif //PROJECTOOP_PERSON_H
