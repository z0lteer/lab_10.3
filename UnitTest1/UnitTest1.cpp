#include "pch.h"
#include "CppUnitTest.h"
#include "../lab_10.3/10.3.cpp"


using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
    TEST_CLASS(UnitTest1)
    {
    public:

        TEST_METHOD(TestAddPerson)
        {
            Note* people = nullptr;
            int size = 0;


            Note newPerson = { "Doe", "John", "555-6789", {10, 10, 1990} };
            people = new Note[1];
            people[0] = newPerson;
            size = 1;


            Assert::AreEqual(1, size, L"Size should be 1 after adding a person");

            delete[] people;
        }

        TEST_METHOD(TestSortByPhoneNumber)
        {
            Note* people = new Note[3];
            people[0] = { "Ivanov", "Ivan", "555-1234", {1, 1, 1990} };
            people[1] = { "Petrov", "Petr", "555-0123", {2, 2, 1991} };
            people[2] = { "Sidorov", "Sidr", "555-5678", {3, 3, 1992} };
            int size = 3;

            sortByPhoneNumber(people, size);


            Assert::AreEqual(string("555-0123"), people[0].phone_number, L"First phone number should be 555-0123");
            Assert::AreEqual(string("555-1234"), people[1].phone_number, L"Second phone number should be 555-1234");
            Assert::AreEqual(string("555-5678"), people[2].phone_number, L"Third phone number should be 555-5678");

            delete[] people;
        }

        TEST_METHOD(TestDisplayBySurname_Found)
        {
            Note* people = new Note[2];
            people[0] = { "Ivanov", "Ivan", "555-1234", {1, 1, 1990} };
            people[1] = { "Petrov", "Petr", "555-0123", {2, 2, 1991} };
            int size = 2;


            std::ostringstream oss;
            std::streambuf* old_cout = std::cout.rdbuf(oss.rdbuf());

            displayBySurname(people, size, "Ivanov");


            std::cout.rdbuf(old_cout);
            string output = oss.str();

            Assert::IsTrue(output.find("Прізвище: Ivanov") != string::npos, L"Should display information about Ivanov");

            delete[] people;
        }

        TEST_METHOD(TestDisplayBySurname_NotFound)
        {
            Note* people = new Note[1];
            people[0] = { "Ivanov", "Ivan", "555-1234", {1, 1, 1990} };
            int size = 1;


            std::ostringstream oss;
            std::streambuf* old_cout = std::cout.rdbuf(oss.rdbuf());

            displayBySurname(people, size, "Nonexistent");


            std::cout.rdbuf(old_cout);
            string output = oss.str();

            Assert::IsTrue(output.find("Людина з прізвищем Nonexistent не знайдена.") != string::npos, L"Should notify if person not found");

            delete[] people;
        }
    };
}