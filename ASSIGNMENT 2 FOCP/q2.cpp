#include <vector>
#include <iostream>
#include <string>
using namespace std;

const int MAX_STU = 100;

class Person {
protected:
    string name;
    int age;
    string id;
    long long int contact;

public:
    Person();
    Person(string name, int age, string id, long long int contact);
    virtual ~Person();
    void setPerson(string n, int a, string d, long long int c);
    virtual void displayDetails();
    virtual float calculatePayment() {
        return 0.0;
    }
};

Person::Person() : name("Abhinav Sharma"), age(19), id("24csu800"), contact(8191816969) {}

Person::Person(string name, int age, string id, long long int contact) {
    this->name = !name.empty() ? name : "default";
    this->age = (age > 0 && age <= 100) ? age : 18;
    this->id = id;
    this->contact = contact;
}

void Person::setPerson(string n, int a, string d, long long int c) {
    if (!n.empty()) name = n;
    if (a > 0 && a <= 100) age = a;
    id = d;
    contact = c;
}

void Person::displayDetails() {
    cout << "Name: " << name << "\nAge: " << age << "\nID: " << id << "\nContact: " << contact << endl;
}

Person::~Person() {
    cout << "Person Destructor called\n";
}

class Professor : public Person {
protected:
    string department;
    string specialization;
    string hdate;

public:
    Professor();
    Professor(string name, int age, string id, long long int contact, string department, string specialization, string hdate);
    ~Professor() override;
    void setProfessor(string dep, string spc, string hire);
    void displayDetails() override;
    virtual double calculatePayment() const = 0;
};

Professor::Professor() : Person(), department(""), specialization(""), hdate("") {}

Professor::Professor(string name, int age, string id, long long int contact, string department, string specialization, string hdate)
    : Person(name, age, id, contact), department(department), specialization(specialization), hdate(hdate) {}

void Professor::setProfessor(string dep, string spc, string hire) {
    department = dep;
    specialization = spc;
    hdate = hire;
}

void Professor::displayDetails() {
    Person::displayDetails();
    cout << "Department: " << department << "\nSpecialization: " << specialization << "\nHire Date: " << hdate << endl;
}

Professor::~Professor() {
    cout << "Professor Destructor called\n";
}

class AssistantProfessor : public Professor {
protected:
    bool isTenureTrack;
    string researchArea;

public:
    AssistantProfessor(string name, int age, string id, long long contact, string department, string specialization, string hdate, bool isTenureTrack, string researchArea)
        : Professor(name, age, id, contact, department, specialization, hdate), isTenureTrack(isTenureTrack), researchArea(researchArea) {}

    void displayDetails() override {
        Professor::displayDetails();
        cout << "Tenure Track: " << (isTenureTrack ? "Yes" : "No") << "\nResearch Area: " << researchArea << endl;
    }

    double calculatePayment() const override {
        return 50000.0;
    }
};

class AssociateProfessor : public Professor {
    int publications;
    string domain;

public:
    AssociateProfessor(string name, int age, string id, long long contact, string department, string specialization, string hdate, int publications, string domain)
        : Professor(name, age, id, contact, department, specialization, hdate), publications(publications), domain(domain) {}

    void displayDetails() override {
        Professor::displayDetails();
        cout << "Publications: " << publications << "\nDomain: " << domain << endl;
    }

    double calculatePayment() const override {
        return 60000.0;
    }
};

class FullProfessor : public Professor {
protected:
    bool isTenured;
    int numBooks;

public:
    FullProfessor(string name, int age, string id, long long contact, string department, string specialization, string hdate, bool isTenured, int numBooks)
        : Professor(name, age, id, contact, department, specialization, hdate), isTenured(isTenured), numBooks(numBooks) {}

    void displayDetails() override {
        Professor::displayDetails();
        cout << "Tenured: " << (isTenured ? "Yes" : "No") << "\nBooks Published: " << numBooks << endl;
    }

    double calculatePayment() const override {
        return 70000.0;
    }
};

class Course {
private:
    string code;
    string title;
    int credits;
    string description;
    Professor* instructor;

public:
    Course();
    Course(string code, string title, int credits, string description);
    ~Course();
    void setCourse(string c, string t, int cred, string des);
    void assignInstructor(Professor* prof);
    void dispCourse();
};

Course::Course() : code("AN89"), title("Data Structures"), credits(4), description("Linked list, trees, hash maps"), instructor(nullptr) {}

Course::Course(string code, string title, int credits, string description)
    : code(code), title(title), credits(credits > 0 ? credits : 1), description(description), instructor(nullptr) {}

void Course::setCourse(string c, string t, int cred, string des) {
    code = c;
    title = t;
    credits = (cred > 0) ? cred : 1;
    description = des;
}

void Course::assignInstructor(Professor* prof) {
    instructor = prof;
}

void Course::dispCourse() {
    cout << "Code: " << code << "\nTitle: " << title << "\nCredits: " << credits << "\nDescription: " << description << endl;
    if (instructor) {
        cout << "--- Instructor Info ---\n";
        instructor->displayDetails();
    }
}

Course::~Course() {
    cout << "Course Destructor called\n";
}

class Classroom {
private:
    string roomNumber;
    int capacity;
    string building;

public:
    Classroom() : roomNumber(""), capacity(0), building("") {}
    Classroom(string roomNumber, int capacity, string building) : roomNumber(roomNumber), capacity(capacity), building(building) {}

    void displayClassroom() {
        cout << "Room Number: " << roomNumber << "\nCapacity: " << capacity << "\nBuilding: " << building << endl;
    }
};

class Student : public Person {
private:
    string edate;
    string program;
    float gpa;
    vector<Course*> enrolledCourses;

public:
    Student();
    Student(string name, int age, string id, long long int contact, string edate, string program, float gpa);
    ~Student() override;
    void setStudent(string ed, string p, float gp);
    void displayDetails() override;
    float calculatePayment() override;
    void enrollInCourse(Course* course);
    void listCourses();
};

Student::Student() : Person(), edate(""), program(""), gpa(0.0f) {}

Student::Student(string name, int age, string id, long long int contact, string edate, string program, float gpa)
    : Person(name, age, id, contact), edate(edate), program(program), gpa(gpa) {}

void Student::setStudent(string ed, string p, float gp) {
    edate = ed;
    program = p;
    if (gp >= 0.0 && gp <= 10.0)
        gpa = gp;
}

void Student::displayDetails() {
    Person::displayDetails();
    cout << "Enrollment Date: " << edate << "\nProgram: " << program << "\nGPA: " << gpa << endl;
}

float Student::calculatePayment() {
    return 10000.0f;
}

Student::~Student() {
    cout << "Student Destructor called\n";
}

void Student::enrollInCourse(Course* course) {
    enrolledCourses.push_back(course);
}

void Student::listCourses() {
    for (auto* c : enrolledCourses) {
        c->dispCourse();
    }
}

class UndergraduateStudent : public Student {
    string major;
    string minor;
    string expectedGraduation;

public:
    UndergraduateStudent(string name, int age, string id, long long contact, string edate, string program, float gpa, string major, string minor, string expectedGrad)
        : Student(name, age, id, contact, edate, program, gpa), major(major), minor(minor), expectedGraduation(expectedGrad) {}

    void displayDetails() override {
        Student::displayDetails();
        cout << "Major: " << major << "\nMinor: " << minor << "\nExpected Graduation: " << expectedGraduation << endl;
    }

    float calculatePayment() override {
        return 50000.0f;
    }
};
//aditya
class Department {
private:
    string name;
    string location;
    long long int budget;

public:
    Department();
    Department(string name, string location, long long int budget);
    ~Department();
    void setDepartment(string nm, string loc, long long int bud);
    void dispDepartment();
    string getName() const { return name; }
};

Department::Department() : name("CSE"), location("2nd floor of main building"), budget(1000000000) {}

Department::Department(string name, string location, long long int budget)
    : name(name), location(location), budget(budget) {}

void Department::setDepartment(string nm, string loc, long long int bud) {
    name = nm;
    location = loc;
    budget = bud;
}

void Department::dispDepartment() {
    cout << "Department Name: " << name << "\nLocation: " << location << "\nBudget: " << budget << endl;
}

Department::~Department() {
    cout << "Department Destructor called\n";
}
//aditya
int main() {
    Person* ptr;

    Student s("Dhruv Bhatotia", 19, "CSU267", 9560840922, "03-02-2024", "B.Tech", 9.05);
    AssistantProfessor ap("Dr. Seema Thakran", 36, "APS69", 7015211108, "MAL", "Discrete", "11-09-2011", true, "Probability");

    ptr = &s;
    cout << "\n--- Displaying Student Details via Person Pointer ---\n";
    ptr->displayDetails();

    ptr = &ap;
    cout << "\n--- Displaying Assistant Professor Details via Person Pointer ---\n";
    ptr->displayDetails();

    return 0;
}
