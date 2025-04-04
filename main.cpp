#include "test_runner.h"
#include <iostream>
#include <stdexcept>
#include <string>
#include "date.h"
#include "database.h"
#include <algorithm>
#include "condition_parser.h"

using namespace std;

string ParseEvent(istream& is) {
    string str;
    getline(is, str);
    int count = 0;
    for (size_t i = 0; i < str.size(); i++)
    {
        if (str[i] == ' ') {
            count++;
        }
        else {
            break;
        }
    }
    str.erase(0, count);
    return str;
}

void TestAll();

int main() {
    //TestAll();

    Database db;

    for (string line; getline(cin, line); ) {
        istringstream is(line);

        string command;
        is >> command;
        if (command == "Add") {
            const auto date = ParseDate(is);
            const auto event = ParseEvent(is);
            db.Add(date, event);
        }
        else if (command == "Print") {
            db.Print(cout);
        }
        else if (command == "Del") {
            auto condition = ParseCondition(is);
            //Это булевский метод, который проверяет дату и событие
            auto predicate = [condition](const Date& date, const string& event) {
                return condition->Evaluate(date, event);
            };
            int count = db.RemoveIf(predicate);
            cout << "Removed " << count << " entries" << endl;
        }
        else if (command == "Find") {
            auto condition = ParseCondition(is);
            auto predicate = [condition](const Date& date, const string& event) {
                return condition->Evaluate(date, event);
            };

            const auto entries = db.FindIf(predicate);
            for (const auto& entry : entries) {
                cout << entry << endl;
            }
            cout << "Found " << entries.size() << " entries" << endl;
        }
        else if (command == "Last") {
            try {
                cout << db.Last(ParseDate(is)) << endl;
            }
            catch (invalid_argument&) {
                cout << "No entries" << endl;
            }
        }
        else if (command.empty()) {
            continue;
        }
        else {
            throw logic_error("Unknown command: " + command);
        }
    }

    return 0;
}
