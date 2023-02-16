#pragma once

#include <vector>

#include "Person.h"

class PhoneBook {
public:
    vector<Person> persons;

    void Add(Person person) {
        persons.push_back(person);
    }

    vector<Person> FindByLastName(string last_name) {
        vector<Person> temp;
        for (const Person& person : persons) {
            if (person.last_name == last_name) {
                temp.push_back(person);
            }
        }

        if (temp.empty()) throw -1;

        return temp;
    }

    Person FindByFirstName(string first_name) {
        Person temp;
        return temp;
    }

    Person FindByTel(string tel) {
        Person temp;
        return temp;
    }
};
