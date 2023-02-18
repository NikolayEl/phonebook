// Елшин Николай Викторович
/*
 * Дописать программу "Телефонный справочник".
 * - Добавить получение данных при старте программы
 * - добавить сохранения данных при закрытии программы
 * - Добавить меню:
 * + напечатать всех
 * + добавить новую запись
 * + удалить запись
 * + найти запись
 * + сохранить в новый файл
 * + выйти
 */

#include <iostream>
#include <string>

#include "Person.h"
#include "PhoneBook.h"
#include "FileServices.h"

using namespace std;

int main() {

    PhoneBook phoneBook;
    Person person;
    ImportToFile("phone_book.csv",person, phoneBook);

    int answer;
    do {
        answer = 0;
        cout << "Welcome to the main menu of the PhoneBook!" << endl;
        cout << "Menu program" << endl;
        cout << "if you want to print all person    - enter 1" << endl;
        cout << "if you want to add a new person    - enter 2" << endl;
        cout << "if you want to delete the entry    - enter 3" << endl;
        cout << "if you want to search for an entry - enter 4" << endl;
        cout << "if you want to save to a new file  - enter 5" << endl;
        cout << "if you want to exit the program    - enter 6" << endl;
        cout << "You choice: ";
        cin >> answer;

        if (answer == 1) {
            cout << endl << "All persons:" << endl << endl;
            phoneBook.PrintAllPerson();
        }

        if (answer == 2) {
            Person person1;
            cout << endl << "Welcome to the menu item of adding a new person" << endl << endl;
            cout << "Enter the Last name: ";
            cin >> person1.last_name;
            cout << endl << "Enter the first name: ";
            cin >> person1.first_name;
            cout << endl << "Enter the patronymic: ";
            cin >> person1.patronymic;
            cout << endl << "Enter the sex person (M or F): ";
            cin >> person1.sex;
            cout << endl << "Enter your year of birth (XXXX): ";
            cin >> person1.date_of_birth.year;
            cout << endl << "Enter your month of birth (XX): ";
            cin >> person1.date_of_birth.month;
            cout << endl << "Enter your day of birth (XX): ";
            cin >> person1.date_of_birth.day;
            cout << endl << "Enter the telephone: ";
            cin >> person1.tel;

            phoneBook.Add(person1);
            cout << endl;

        }

        if (answer == 3) {
            int answer_delete = 0;
            cout << endl << "Welcome to the menu for deleting a person" << endl << endl;
            cout << "If you want to delete a user by last name, enter 1" << endl;
            cout << "If you want to delete a user by telephone, enter 2" << endl;
            cout << "You choice: ";
            cin >> answer_delete;

            if (answer_delete == 1) {
                string last_name_delete;
                cout << endl << "Enter last name: ";
                cin >> last_name_delete;

                string answer_delete_last_name;
                try {
                    auto result = phoneBook.FindByLastName(last_name_delete);
                    for (auto p: result) {
                        cout << endl <<"Delete this person?" << endl << endl;
                        cout << p.ToString() << endl;
                        cout << "y/n? -  ";
                        cin >> answer_delete_last_name;

                        if(answer_delete_last_name == "y" || answer_delete_last_name == "Y") {
                            phoneBook.DeletePerson(last_name_delete, p.first_name, p.patronymic, p.tel, phoneBook);
                            cout << endl << "Person remove!" << endl << endl;
                        }
                    }
                } catch (...) {
                    cerr << endl << "Person not found" << endl << endl;
                    break;

                }
            }

            if (answer_delete == 2) {
                string last_tel_delete;
                cout << endl << "Enter the person's phone number : ";
                cin >> last_tel_delete;

                string answer_delete_tel;
                try {
                    auto result = phoneBook.FindByTel(last_tel_delete);
                    for (auto p: result) {
                        cout << endl << "Delete this person?" << endl << endl;
                        cout << p.ToString() << endl;
                        cout << "y/n? -  ";
                        cin >> answer_delete_tel;

                        if (answer_delete_tel == "y" || answer_delete_tel == "Y") {
                            phoneBook.DeletePerson(p.last_name, p.first_name, p.patronymic, last_tel_delete, phoneBook);;
                            cout << endl << "Person remove!" << endl << endl;
                        }
                    }
                } catch (...) {
                    cerr << endl << "Person not found" << endl << endl;
                }
            }

            if (answer_delete != 1 && answer_delete != 2) {
                cout << endl <<"You have selected a non-existent menu item!" << endl;
            }

        }

        int answer_search;
        if (answer == 4) {
            cout << endl <<"Welcome to the person search menu" << endl;
            do {
                answer_search = 0;
                cout << "If you searching by last name  - enter 1" << endl;
                cout << "If you searching by first name - enter 2" << endl;
                cout << "If you searching by telephone  - enter 3" << endl;
                cout << "If you ant to exit this menu   - enter 4" << endl;
                cout << "You choice: ";
                cin >> answer_search;

                if (answer_search == 1) {
                    string last_name;
                    cout << endl <<"Enter to the last name: ";
                    cin >> last_name;

                    try {
                        for (auto p: phoneBook.FindByLastName(last_name)) {
                            cout << p.ToString() << endl;
                        }
                    } catch (...) {
                        cerr << endl << "Person not found" << endl << endl;
                    }
                }

                if (answer_search == 2) {
                    string first_name;
                    cout << endl <<"Enter to the last name: ";
                    cin >> first_name;

                    try {
                        for (auto p: phoneBook.FindByFirstName(first_name)) {
                            cout << p.ToString() << endl;
                        }
                    } catch (...) {
                        cerr << endl << "Person not found" << endl << endl;
                    }
                }

                if (answer_search == 3) {
                    string tel;
                    cout << endl <<"Enter to the last name: ";
                    cin >> tel;

                    try {
                        for (auto p: phoneBook.FindByTel(tel)) {
                            cout << p.ToString() << endl;
                        }
                    } catch (...) {
                        cerr << endl << "Person not found" << endl << endl;
                    }
                }

                if (answer_search < 1 || answer_search > 4) {
                    cout << endl << "You have selected a non-existent menu item! Please enter again." << endl;
                }
            } while(answer_search != 4);

            cout << endl << "If ";
        }

        if (answer == 5) {
            string path_new;
            cout << endl << "Enter a name for the new file (in English)" << endl;
            cout << "file name: ";
            cin >> path_new;

            path_new += ".csv";
            ExportToFile(path_new, phoneBook);

        }

        if (answer > 6 || answer < 1) {
            cout << endl << "You have selected a non-existent menu item! Please enter again." << endl;
        }

    } while (answer != 6);


    ExportToFile("phone_book.csv", phoneBook);
    return 0;
}
