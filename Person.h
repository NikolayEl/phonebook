#pragma once

#include <string>

#include "Date.h"

using namespace std;

class Person {
public:
    string first_name;
    string last_name;
    string patronymic;
    string sex;
    Date date_of_birth;
    string tel;

    string ToString() {
        string temp = last_name + " " + first_name + " " + patronymic + "\n";
        temp += "sex: " + sex + "\n";
        temp += "Birth day: " + date_of_birth.ToString() + "\n";
        temp += "tel: " + tel + "\n";
        return temp;
    }
};