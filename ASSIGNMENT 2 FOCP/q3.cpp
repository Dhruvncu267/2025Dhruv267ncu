#include <vector>
#include <iostream>
#include <string>
using namespace std;

class Course;
class Faculty;

class Individual {
protected:
    string fullName;
    int yearsOld;
    string uniqueID;
    string contactInfo;

public:
    Individual(string name, int age, string id, string contact) {
        setFullName(name);
        setYearsOld(age);
        uniqueID = id;
        contactInfo = contact;
    }

    virtual ~Individual() {}

    void setFullName(string name) {
        if (!name.empty()) fullName = name;
    }

    void setYearsOld(int age) {
        if (age > 0 && age < 120) yearsOld = age;
    }

    string getFullName() const { return fullName; }
    int getYearsOld() const { return yearsOld; }
    string getID() const { return uniqueID; }
    string getContact() const { return contactInfo; }

    virtual void showDetails() {
        cout << "Name: " << fullName << ", Age: " << yearsOld
             << ", ID: " << uniqueID << ", Contact: " << contactInfo << endl;
    }

    virtual double computePay() { return 0.0; }
};

class Faculty : public Individual {
protected:
    string dept, field, joinedOn;
    int serviceYears;

public:
    Faculty(string name, int age, string id, string contact,
            string department, string specialization, string hiredDate, int years)
        : Individual(name, age, id, contact), dept(department),
          field(specialization), joinedOn(hiredDate), serviceYears(years) {}

    void showDetails() override {
        Individual::showDetails();
        cout << "Department: " << dept << ", Specialization: " << field
             << ", Joined: " << joinedOn << ", Experience: " << serviceYears << " yrs" << endl;
    }

    double computePay() override {
        return 4000 + serviceYears * 100;
    }
};

class JuniorFaculty : public Faculty {
public:
    JuniorFaculty(string name, int age, string id, string contact,
                  string dept, string field, string date, int years)
        : Faculty(name, age, id, contact, dept, field, date, years) {}

    double computePay() override {
        return 4500 + serviceYears * 120;
    }
};

class MidFaculty : public Faculty {
public:
    MidFaculty(string name, int age, string id, string contact,
               string dept, string field, string date, int years)
        : Faculty(name, age, id, contact, dept, field, date, years) {}

    double computePay() override {
        return 6000 + serviceYears * 150;
    }
};

class SeniorFaculty : public Faculty {
public:
    SeniorFaculty(string name, int age, string id, string contact,
                  string dept, string field, string date, int years)
        : Faculty(name, age, id, contact, dept, field, date, years) {}

    double computePay() override {
        return 8000 + serviceYears * 200;
    }
};

class Course {
    string courseID, courseTitle, courseDesc;
    int creditHours;
    Faculty* lecturer;

public:
    Course(string id, string title, int credits, string desc, Faculty* prof)
        : courseID(id), courseTitle(title), courseDesc(desc), lecturer(prof) {
        setCredits(credits);
    }

    void setCredits(int credits) {
        if (credits > 0) creditHours = credits;
    }

    string getCourseID() const { return courseID; }
};

class Learner : public Individual {
protected:
    string enrolledSince, studyProgram;
    double cgpa;
    vector<Course*> enrolledCourses;

public:
    Learner(string name, int age, string id, string contact,
            string enrolledDate, string program, double grade)
        : Individual(name, age, id, contact),
          enrolledSince(enrolledDate), studyProgram(program) {
        updateGPA(grade);
    }

    void updateGPA(double grade) {
        if (grade >= 0.0 && grade <= 10.0) cgpa = grade;
    }

    double getGPA() const { return cgpa; }

    void showDetails() override {
        Individual::showDetails();
        cout << "Enrolled: " << enrolledSince << ", Program: " << studyProgram
             << ", GPA: " << cgpa << endl;
    }

    double computePay() override {
        return 1000.0;
    }

    void registerCourse(Course* c) {
        enrolledCourses.push_back(c);
    }

    void printCourses() {
        cout << fullName << " is registered in: ";
        for (auto* c : enrolledCourses)
            cout << c->getCourseID() << " ";
        cout << endl;
    }
};

class Undergrad : public Learner {
    string majorField, minorField, expectedGrad;

public:
    Undergrad(string name, int age, string id, string contact,
              string enrolled, string prog, double gpa,
              string major, string minor, string grad)
        : Learner(name, age, id, contact, enrolled, prog, gpa),
          majorField(major), minorField(minor), expectedGrad(grad) {}

    void showDetails() override {
        Learner::showDetails();
        cout << "Major: " << majorField << ", Minor: " << minorField
             << ", Graduation: " << expectedGrad << endl;
    }
};

class Postgrad : public Learner {
    string researchTopic, thesisTitle;
    Faculty* supervisor;

public:
    Postgrad(string name, int age, string id, string contact,
             string enrolled, string prog, double gpa,
             string topic, Faculty* prof, string thesis)
        : Learner(name, age, id, contact, enrolled, prog, gpa),
          researchTopic(topic), thesisTitle(thesis), supervisor(prof) {}

    void showDetails() override {
        Learner::showDetails();
        cout << "Research: " << researchTopic << ", Thesis: " << thesisTitle << endl;
        if (supervisor) {
            cout << "Supervisor Info: ";
            supervisor->showDetails();
        }
    }

    void markTA() {
        cout << fullName << " is working as a Teaching Assistant." << endl;
    }

    void markRA() {
        cout << fullName << " is involved in Research." << endl;
    }
};

class Room {
    string roomCode;
    int seatCount;

public:
    Room(string id, int cap) : roomCode(id), seatCount(cap) {}
};

struct Slot {
    string course;
    string timing;
    string room;
};

class Timetable {
    vector<Slot> slots;

public:
    void insertSlot(string courseCode, string time, string roomNo) {
        slots.push_back({courseCode, time, roomNo});
    }
};

class FacultyGroup {
    string deptName, building;
    double funding;
    vector<Faculty*> staff;

public:
    FacultyGroup(string n, string loc, double fund)
        : deptName(n), building(loc), funding(fund) {}

    void assignFaculty(Faculty* f) {
        staff.push_back(f);
    }
};

class Institution {
    vector<FacultyGroup> units;

public:
    void addUnit(FacultyGroup d) {
        units.push_back(d);
    }
};

int main() {
    Undergrad student1("Dhruv", 19, "UG001", "100", "2024", "CSE", 9.5, "CSE", "Math", "2028");
    JuniorFaculty prof1("Dr. Seema", 36, "APS69", "200", "MAL", "Discrete", "2011", 10);
    Postgrad grad1("Ada", 24, "PG006", "300", "2023", "EEE", 8.9, "Automation", &prof1, "Filtering Thesis");

    MidFaculty prof2("Dr. Ansh", 69, "F002", "400", "EEE", "Circuits", "2011", 14);
    SeniorFaculty prof3("Dr. Bhuwan", 95, "F003", "500", "ME", "Casting", "2001", 24);
    Postgrad grad2("Richa", 26, "PG002", "600", "2021", "ME", 8.6, "Autonomous Tech", &prof3, "Self-Control");

    grad1.markTA();
    grad2.markRA();

    Course intro("CSL108", "FOCP-II", 5, "Basics of C++", &prof1);
    student1.registerCourse(&intro);
    grad1.registerCourse(&intro);
    grad2.registerCourse(&intro);

    student1.printCourses();
    grad1.printCourses();
    grad2.printCourses();

    Room r1("RN31", 40);
    Timetable t;
    t.insertSlot("CSL108", "Mon 8:30 AM", "RN31");

    FacultyGroup dept("CSE", "Block 1", 500000);
    dept.assignFaculty(&prof1);
    Institution uni;
    uni.addUnit(dept);

    vector<Individual*> community = { &student1, &grad1, &grad2, &prof1, &prof2, &prof3 };
    for (auto* member : community) {
        member->showDetails();
        cout << "Payment Due: $" << member->computePay() << "\n--------------------------\n";
    }

    return 0;
}
