#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <algorithm>
#include <iomanip>
#include <sstream>
#include <exception>

using namespace std;

void Check_and_Write(stringstream& stream, int& value, const char& symbol, string str) {
    if (!(stream >> value) or stream.peek() != symbol) {
        throw runtime_error("Wrong date format: " + str);
    }
    stream.ignore(1);
}

class Date {
public:
    Date() {
        year = 0;
        month = 0;
        day = 0;
    }
    Date(const int& y, const int& m, const int& d) {
        if (m > 12 or m < 1) {
            throw runtime_error("Month value is invalid: " + to_string(m));
        }
        else if (d > 31 or d < 1) {
            throw runtime_error("Day value is invalid: " + to_string(d));
        }
        year = y;
        month = m;
        day = d;
    }
    int GetYear() const {
        return year;
    }
    int GetMonth() const {
        return month;
    }
    int GetDay() const {
        return day;
    }
private:
    int year;
    int month;
    int day;
};

bool operator<(const Date& lhs, const Date& rhs) {
    if (lhs.GetYear() == rhs.GetYear()) {
        if (lhs.GetMonth() == rhs.GetMonth()) {
            return lhs.GetDay() < rhs.GetDay();
        }
        return lhs.GetMonth() < rhs.GetMonth();
    }
    return lhs.GetYear() < rhs.GetYear();
}

Date String_to_Date(const string& string) {
    int year, month, day;
    stringstream ss;
    ss << string;
    Check_and_Write(ss, year, '-', string);
    Check_and_Write(ss, month, '-', string);
    if (!(ss >> day) or ss.peek() != EOF) {
        throw runtime_error("Wrong date format: " + string);
    }
    return {year, month, day};
}

class Database {
public:
    void AddEvent(const Date& date, const string& event) {
            dbase[date].insert(event);
    }
    bool DeleteEvent(const Date& date, const string& event) {
        if (dbase.count(date) > 0) {
            if (dbase[date].count(event) > 0) {
                dbase[date].erase(event);
                if (dbase[date].size() == 0) {
                    dbase.erase(date);
                }
                return true;
            }
        }
        return false;
    }
    int  DeleteDate(const Date& date) {
        int result;
        result = dbase[date].size();
        dbase.erase(date);
        return result;
    }

    void Find(const Date& date) const {
        if (dbase.count(date) > 0) {
            for (const auto& now : dbase.at(date)) {
                cout << now << endl;
            }
        }
    }

    void Print() const {
        cout << setfill('0');
        for (const auto& date : dbase) {
            for (const auto& event : dbase.at(date.first)) {
                cout << setw(4) << date.first.GetYear() << "-"
                     << setw(2) << date.first.GetMonth() << "-"
                     << setw(2) << date.first.GetDay() << " "
                     << event << endl;
            }
        }
    }
private:
    map<Date, set<string>> dbase;
};

int main() {
    Database db;

    string command;
    while (getline(cin, command)) {
        string cmd;
        stringstream ss;
        ss << command;
        ss >> cmd;
        try {
            if (cmd == "Add") {
                string event, date_str;
                ss >> date_str >> event;
                Date date = String_to_Date(date_str);
                db.AddEvent(date, event);
            }
            else if (cmd == "Del") {
                string event, date_str;
                ss >> date_str >> event;
                Date date = String_to_Date(date_str);
                if (event.size() == 0) {
                    cout << "Deleted " << db.DeleteDate(date) << " events" << endl;
                }
                else {
                    if (db.DeleteEvent(date, event)) {
                        cout << "Deleted successfully" << endl;
                    }
                    else {
                        cout << "Event not found" << endl;
                    }
                }
            }
            else if (cmd == "Find") {
                string date_str;
                ss >> date_str;
                Date date = String_to_Date(date_str);
                db.Find(date);
            }
            else if (cmd == "Print") {
                db.Print();
            }
            else if (cmd.size() != 0){
                throw runtime_error("Unknown command: " + cmd);
            }
        }
        catch (runtime_error& ex) {
            cout << ex.what() << endl;
            return 0;
        }
    }
    return 0;
}
