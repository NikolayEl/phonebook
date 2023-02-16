#include <iostream>
#include <string>

#include "Person.h"
#include "PhoneBook.h"
#include "FileServices.h"

using namespace std;

int main() {
    Person person1;
    person1.last_name = "S";
    person1.first_name = "A";
    person1.patronymic = "N";
    person1.sex = 'M';
    person1.date_of_birth.year = 1;
    person1.date_of_birth.month = 1;
    person1.date_of_birth.day = 1;
    person1.tel = "1234567890";

    Person person2;
    person2.last_name = "S";
    person2.first_name = "A";
    person2.patronymic = "N";
    person2.sex = 'M';
    person2.date_of_birth.year = 1;
    person2.date_of_birth.month = 1;
    person2.date_of_birth.day = 1;
    person2.tel = "1234567890";

    PhoneBook phoneBook;
    phoneBook.Add(person1);
    phoneBook.Add(person2);

    /*try {
        auto result = phoneBook.FindByLastName("S");
        for (auto person : result) {
            cout << person.ToString();
        }
    } catch (...) {
        cerr << "Person not found" << endl;
    }*/

    try {
        ExportToFile("phone_book.csv", phoneBook);
    } catch (...) {
        cerr << "File not opened" << endl;
    }


    return 0;
}
