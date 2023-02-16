#pragma once

#include <vector>

#include "Person.h"

class PhoneBook {
private:
    vector<Person> persons;

public:
    void Add(const Person& person) {
        persons.push_back(person);
    }

    vector<Person> FindByLastName(const string& last_name) {
        vector<Person> temp;
        for (const Person& person : persons) {
            if (person.last_name == last_name) {
                temp.push_back(person);
            }
        }

        if (temp.empty()) throw -1;

        return temp;
    }

    vector<Person> FindByFirstName(const string& first_name) {
        vector<Person> temp;
        for (const Person& person : persons) {
            if (person.first_name == first_name) {
                temp.push_back(person);
            }
        }

        if (temp.empty()) throw -1;

        return temp;
    }

    vector<Person> FindByTel(string tel) {
        vector<Person> temp;
        for (const Person& person : persons) {
            if (person.tel == tel) {
                temp.push_back(person);
            }
        }

        if (temp.empty()) throw -1;

        return temp;
    }

    vector<Person> GetAllPersons() {
        return persons;
    }
};
