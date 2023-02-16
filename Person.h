#pragma once

#include <string>

#include "Date.h"

using namespace std;

class Person {
public:
    string first_name;
    string last_name;
    string patronymic;
    char sex;
    Date date_of_birth;
    string tel;
};