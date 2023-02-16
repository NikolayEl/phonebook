#pragma once

#include <string>

using namespace std;

class Date {
public:
    int year;
    int month;
    int day;

    string ToString() {
        return to_string(day) + "." + to_string(month) + "." + to_string(year);
    }
};
