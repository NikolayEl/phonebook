#pragma once

#include <fstream>

#include "PhoneBook.h"

using namespace std;

void ExportToFile(string path, PhoneBook phoneBook) {
    ofstream file;
    file.open(path, ios::trunc);

    if (!file.is_open()) throw 1;

    auto persons = phoneBook.GetAllPersons();
    for (auto p : persons) {
        file << p.last_name << "|" << p.first_name << "|" << p.patronymic << "|" << p.sex << "|" << p.date_of_birth.ToString() << "|" << p.tel << endl;
    }

    file.close();
}
