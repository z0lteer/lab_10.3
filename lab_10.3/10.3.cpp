
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
    cout << "������ �������: ";
    cin >> newPerson.surname;
    cout << "������ ��'�: ";
    cin >> newPerson.name;
    cout << "������ ����� ��������: ";
    cin >> newPerson.phone_number;
    cout << "������ ���� ���������� (����, �����, ��): ";
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
    cout << "����� ����������� �� ������� ��������.\n";
}


void displayBySurname(Note* people, int size, const string& surname) {
    bool found = false;
    for (int i = 0; i < size; ++i) {
        if (people[i].surname == surname) {
            cout << "�������: " << people[i].surname
                << ", ��'�: " << people[i].name
                << ", ����� ��������: " << people[i].phone_number
                << ", ���� ����������: " << people[i].birthday[0] << "."
                << people[i].birthday[1] << "." << people[i].birthday[2] << "\n";
            found = true;
            break;
        }
    }
    if (!found) {
        cout << "������ � �������� " << surname << " �� ��������.\n";
    }
}


void displayMenu() {
    cout << "\n--- ���� ---\n";
    cout << "1. ������ ��� ��� ������\n";
    cout << "2. ³���������� �� ������� ��������\n";
    cout << "3. ����� �� ��������\n";
    cout << "4. �����\n";
    cout << "������� �����: ";
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
            cout << "������ ������� ��� ������: ";
            cin >> surname;
            displayBySurname(people, size, surname);
            break;
        }
        case 4:
            running = false;
            break;
        default:
            cout << "������� ����. ��������� �� ���.\n";
        }
    }

    delete[] people;
    return 0;
}
