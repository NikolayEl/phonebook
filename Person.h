#pragma once

#include <fstream>
#include <string>

#include "PhoneBook.h"
#include "Person.h"

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

string SubString (string& source, char delimiter) {
    int position = source.find(delimiter);
    string result = source.substr(0,position);
    source = source.substr(position + 1);

    return result;
}

void ImportToFile(string path, Person& person, PhoneBook& phoneBook) {
    ifstream file_open;
    file_open.open(path);
    if (file_open.is_open() ) {
    //    cout << "File open!" << endl;

        string line;
        while (getline(file_open, line)) {
            string temp_line = line;

            int position;
            position = temp_line.find('|', 0);
            person.last_name = temp_line.substr(0, position);
            temp_line = temp_line.substr(position + 1);

            position = temp_line.find('|', 0);
            person.first_name = temp_line.substr(0, position);
            temp_line = temp_line.substr(position + 1);

            position = temp_line.find('|', 0);
            person.patronymic = temp_line.substr(0, position);
            temp_line = temp_line.substr(position + 1);

            position = temp_line.find('|', 0);
            person.sex = temp_line.substr(0, position);
            temp_line = temp_line.substr(position + 1);

            position = temp_line.find('.', 0);
            person.date_of_birth.year = stoi(temp_line.substr(0, position));
            temp_line = temp_line.substr(position + 1);

            position = temp_line.find('.', 0);
            person.date_of_birth.month = stoi(temp_line.substr(0, position));
            temp_line = temp_line.substr(position + 1);

            position = temp_line.find('.', 0);
            person.date_of_birth.day = stoi(temp_line.substr(0, position));
            temp_line = temp_line.substr(position + 1);

            position = temp_line.find('|', 0);
            person.tel = temp_line.substr(position + 1);

            phoneBook.Add(person);

        }
    } else {
        cout << "Error. File not open!" << endl;
    }
    file_open.close();
}
