#pragma once

#include <vector>

#include "Person.h"

class PhoneBook {
private:
    vector<Person> persons;

public:
    void Add(Person person) {
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

        if (temp.empty()) throw -2;

        return temp;
    }

    vector<Person> FindByTel(string tel) {
        vector<Person> temp;
        for (const Person& person : persons) {
            if (person.tel == tel) {
                temp.push_back(person);
            }
        }

        if (temp.empty()) throw -3;

        return temp;
    }

    vector<Person> GetAllPersons() {
        return persons;
    }

    void PrintAllPerson () {
        PhoneBook phoneBook;
        for (auto person : persons) {
            cout << person.ToString() << endl;
        }
    }

    void DeletePerson(string last_name, string first_name, string patronimic, string tel, PhoneBook& phoneBook) {
        vector<Person> temp;
        int i = 0;
        for(auto p: persons) {
            if (p.last_name != last_name || p.first_name != first_name || p.patronymic != patronimic || p.tel != tel) {
                temp.push_back(p);
            }
        }
        phoneBook.persons.clear();
        phoneBook.persons = temp;

        if (temp.empty()) throw -4;
    }

};
