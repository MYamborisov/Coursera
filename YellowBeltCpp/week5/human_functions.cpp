#include <iostream>
#include <string>
#include <vector>

using namespace std;

void Presentation(const string& job, const string& name) {
    cout << job << ": " << name;
}

class Human {
public:
    Human(const string& job, const string& name) : Job(job), Name(name) {}
    virtual void Walk(const string& destination) const {
        Presentation(Job, Name);
        cout << " walks to: " << destination << endl;
    }
    string GetName() const {
        return Name;
    }
    string GetJob() const {
        return Job;
    }
protected:
    const string Job;
    const string Name;
};

class Student : public Human {
public:
    Student(const string& name, const string& favouriteSong) : Human("Student", name), FavouriteSong(favouriteSong) {}

    void Learn() const {
        Presentation(Job, Name);
        cout << " learns" << endl;
    }

    void Walk(const string& destination) const override {
        Presentation(Job, Name);
        cout << " walks to: " << destination << endl;
        Presentation(Job, Name);
        cout << " sings a song: " << FavouriteSong << endl;
    }

    void SingSong() const {
        Presentation(Job, Name);
        cout << " sings a song: " << FavouriteSong << endl;
    }

private:
    const string FavouriteSong;
};


class Teacher : public Human {
public:
    Teacher(const string& name, const string& subject) : Human("Teacher", name), Subject(subject) {}
    
    void Teach() {
        Presentation(Job, Name);
        cout << " teaches: " << Subject << endl;
    }

private:
    const string Subject;
};


class Policeman : public Human{
public:
    Policeman(const string& name) : Human("Policeman", name) {}

    void Check(const Human& human) {
        Presentation(Job, Name);
        cout << " checks " << human.GetJob() << ". " << human.GetJob() << "'s name is: " << human.GetName() << endl;
    }
};


void VisitPlaces(const Human& human, const vector<string>& places) {
    for (const auto& place : places) {
        human.Walk(place);
    }
}


int main() {
    Teacher t("Jim", "Math");
    Student s("Ann", "We will rock you");
    Policeman p("Bob");

    VisitPlaces(t, {"Moscow", "London"});
    p.Check(s);
    VisitPlaces(s, {"Moscow", "London"});
    return 0;
}