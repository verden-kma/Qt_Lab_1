#ifndef PROJECTOOP_SECUREOFFICE_H
#define PROJECTOOP_SECUREOFFICE_H


#include <vector>
#include <QVariant>
#include "Models/Person.h"

class Office {
public:
    Office() = default;
    ~Office();

    explicit Office(const std::vector<Person *>& people);

    void addPerson(Person*);

    const std::list<Person*> findByID(const QVariant); // had to be optional, but empty list has a wider support

    const std::list<Person*> findByName(const QVariant);

    const std::list<Person*> findBySurname(const QVariant);

    const std::list<Person*> findByAge(const QVariant);

    const std::list<Person*> findByPhoneNumber(const QVariant);

    using FilterFunc = const std::list<Person*> (Office::* const) (const QVariant);

    std::vector<Person*>& peekPeople();

    bool remove(const Person*);

    bool remove(uint);

    void clearShellow();

    friend std::ostream& operator<<(std::ostream&, const Office&);

private:
    std::vector<Person*> _people;
};


#endif //PROJECTOOP_SECUREOFFICE_H
