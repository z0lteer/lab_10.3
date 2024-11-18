
#include <iostream>
#include <string>
#include <algorithm>
#include <Windows.h> 
using namespace std;


struct Note {
    string surname;
    string name;
    string phone_number;
    int birthday[3];
};


void addPerson(Note*& people, int& size) {
    Note newPerson;
    cout << "Введіть прізвище: ";
    cin >> newPerson.surname;
    cout << "Введіть ім'я: ";
    cin >> newPerson.name;
    cout << "Введіть номер телефону: ";
    cin >> newPerson.phone_number;
    cout << "Введіть день народження (день, місяць, рік): ";
    cin >> newPerson.birthday[0] >> newPerson.birthday[1] >> newPerson.birthday[2];

    Note* temp = new Note[size + 1];
    for (int i = 0; i < size; ++i) {
        temp[i] = people[i];
    }
    temp[size] = newPerson;
    delete[] people;
    people = temp;
    size++;
}


void sortByPhoneNumber(Note* people, int size) {
    sort(people, people + size, [](const Note& a, const Note& b) {
        return a.phone_number < b.phone_number;
        });
    cout << "Масив відсортовано за номером телефону.\n";
}


void displayBySurname(Note* people, int size, const string& surname) {
    bool found = false;
    for (int i = 0; i < size; ++i) {
        if (people[i].surname == surname) {
            cout << "Прізвище: " << people[i].surname
                << ", Ім'я: " << people[i].name
                << ", Номер телефону: " << people[i].phone_number
                << ", День народження: " << people[i].birthday[0] << "."
                << people[i].birthday[1] << "." << people[i].birthday[2] << "\n";
            found = true;
            break;
        }
    }
    if (!found) {
        cout << "Людина з прізвищем " << surname << " не знайдена.\n";
    }
}


void displayMenu() {
    cout << "\n--- Меню ---\n";
    cout << "1. Додати дані про людину\n";
    cout << "2. Відсортувати за номером телефону\n";
    cout << "3. Пошук за прізвищем\n";
    cout << "4. Вийти\n";
    cout << "Виберіть опцію: ";
}


int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    Note* people = nullptr;
    int size = 0;
    bool running = true;

    while (running) {
        displayMenu();
        int choice;
        cin >> choice;

        switch (choice) {
        case 1:
            addPerson(people, size);
            break;
        case 2:
            sortByPhoneNumber(people, size);
            break;
        case 3: {
            string surname;
            cout << "Введіть прізвище для пошуку: ";
            cin >> surname;
            displayBySurname(people, size, surname);
            break;
        }
        case 4:
            running = false;
            break;
        default:
            cout << "Невірний вибір. Спробуйте ще раз.\n";
        }
    }

    delete[] people;
    return 0;
}
