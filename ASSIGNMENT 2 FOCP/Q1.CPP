#include <vector>
#include <iostream>
using namespace std;

const int MAX_ENTRIES = 100;

class Individual {
protected:
    string fullName;
    int yearsOld;
    string userID;
    long long phoneNumber;

public:
    Individual();
    Individual(string name, int age, string uid, long long contact);
    virtual ~Individual();
    
    void updateInfo(string n, int a, string id, long long contact);
    virtual void showDetails();
    virtual float computePayment() {
        return 0.0f;
    }
};

Individual::Individual() : fullName("Abhinav Sharma"), yearsOld(19), userID("24csu800"), phoneNumber(8191816969) {}

Individual::Individual(string name, int age, string uid, long long contact) {
    if (!name.empty()) fullName = name;
    if (age > 0 && age <= 100) yearsOld = age;
    userID = uid;
    phoneNumber = contact;
}

void Individual::updateInfo(string n, int a, string id, long long contact) {
    if (!n.empty()) fullName = n;
    if (a > 0 && a <= 100) yearsOld = a;
    userID = id;
    phoneNumber = contact;
}

void Individual::showDetails() {
    cout << "Name : " << fullName << endl;
    cout << "Age : " << yearsOld << endl;
    cout << "ID : " << userID << endl;
    cout << "Contact : " << phoneNumber << endl;
}

Individual::~Individual() {
    cout << "Individual Destructor Triggered...\n";
}

class Learner : public Individual {
private:
    string enrollDate;
    string degree;
    float gradePoint;

public:
    Learner();
    Learner(string name, int age, string uid, long long contact, string eDate, string program, float gpa);
    ~Learner();

    void setAcademicInfo(string eDate, string prog, float gpa);
    void showDetails() override;
    float computePayment() override {
        return 1000000000.0f;
    }
};

Learner::Learner() : Individual(), enrollDate(""), degree(""), gradePoint(0.0f) {}

Learner::Learner(string name, int age, string uid, long long contact, string eDate, string program, float gpa)
    : Individual(name, age, uid, contact), enrollDate(eDate), degree(program), gradePoint(gpa) {}

void Learner::setAcademicInfo(string eDate, string prog, float gpa) {
    enrollDate = eDate;
    degree = prog;
    if (gpa >= 0.0f && gpa <= 10.0f) gradePoint = gpa;
}

void Learner::showDetails() {
    Individual::showDetails();
    cout << "Enrollment Date : " << enrollDate << endl;
    cout << "Program : " << degree << endl;
    cout << "GPA : " << gradePoint << endl;
}

Learner::~Learner() {
    cout << "Learner Destructor Triggered...\n";
}

class Educator : public Individual {
private:
    string dept;
    string field;
    string joiningDate;

public:
    Educator();
    Educator(string name, int age, string uid, long long contact, string dept, string spec, string hDate);
    ~Educator();

    void setFacultyInfo(string dept, string spec, string hDate);
    void showDetails() override;

    float computePayment() override {
        return 5000000.0f;
    }
};

Educator::Educator() : Individual(), dept(""), field(""), joiningDate("") {}

Educator::Educator(string name, int age, string uid, long long contact, string dept, string spec, string hDate)
    : Individual(name, age, uid, contact), dept(dept), field(spec), joiningDate(hDate) {}

void Educator::setFacultyInfo(string dept, string spec, string hDate) {
    this->dept = dept;
    field = spec;
    joiningDate = hDate;
}

void Educator::showDetails() {
    Individual::showDetails();
    cout << "Department : " << dept << endl;
    cout << "Specialization : " << field << endl;
    cout << "Hire Date : " << joiningDate << endl;
}

Educator::~Educator() {
    cout << "Educator Destructor Triggered...\n";
}

class Module {
private:
    string courseCode;
    string courseTitle;
    int creditValue;
    string summary;

public:
    Module();
    Module(string code, string title, int credits, string desc);
    ~Module();

    void setModule(string c, string t, int cr, string desc);
    void displayModule();
};

Module::Module() : courseCode("CSL108"), courseTitle("FOCP"), creditValue(5), summary("Basic C++, classes , oops etc ") {}

Module::Module(string code, string title, int credits, string desc) {
    courseCode = code;
    courseTitle = title;
    if (credits > 0) creditValue = credits;
    summary = desc;
}

void Module::setModule(string c, string t, int cr, string desc) {
    courseCode = c;
    courseTitle = t;
    if (cr > 0) creditValue = cr;
    summary = desc;
}

void Module::displayModule() {
    cout << "Course Code : " << courseCode << endl;
    cout << "Title : " << courseTitle << endl;
    cout << "Credits : " << creditValue << endl;
    cout << "Description : " << summary << endl;
}

Module::~Module() {
    cout << "Module Destructor Triggered...\n";
}


class Division {
private:
    string deptName;
    string addr;
    long long funds;

public:
    Division();
    Division(string n, string loc, long long b);
    ~Division();

    void setDivision(string name, string location, long long budget);
    void showDivision();
};

Division::Division() : deptName("CSE"), addr("2nd floor, Main Building"), funds(927902482047) {}

Division::Division(string n, string loc, long long b) : deptName(n), addr(loc), funds(b) {}

void Division::setDivision(string name, string location, long long budget) {
    deptName = name;
    addr = location;
    funds = budget;
}

void Division::showDivision() {
    cout << "Department Name : " << deptName << endl;
    cout << "Location : " << addr << endl;
    cout << "Budget : " << funds << endl;
}

Division::~Division() {
    cout << "Division Destructor Triggered...\n";
}
//aditya 
class MarksLedger {
private:
    vector<string> courseList;
    vector<string> studentList;
    vector<double> scores;

public:
    void recordGrade(const string& cid, const string& sid, double grade) {
        courseList.push_back(cid);
        studentList.push_back(sid);
        scores.push_back(grade);
    }

    double averageGrade(const string& cid) {
        double total = 0;
        int count = 0;
        for (size_t i = 0; i < courseList.size(); ++i) {
            if (courseList[i] == cid) {
                total += scores[i];
                count++;
            }
        }
        return (count > 0) ? total / count : 0.0;
    }

    double maxGrade(const string& cid) {
        double high = -1.0;
        for (size_t i = 0; i < courseList.size(); ++i) {
            if (courseList[i] == cid && scores[i] > high) {
                high = scores[i];
            }
        }
        return (high >= 0) ? high : 0.0;
    }

    vector<string> failedStudents(const string& cid) {
        vector<string> failed;
        for (size_t i = 0; i < courseList.size(); ++i) {
            if (courseList[i] == cid && scores[i] < 50.0) {
                failed.push_back(studentList[i]);
            }
        }
        return failed;
    }
};

class RegistrationManager {
private:
    vector<string> enrolledCourses;
    vector<string> enrolledStudents;

public:
    void registerStudent(const string& cid, const string& sid) {
        for (size_t i = 0; i < enrolledCourses.size(); ++i) {
            if (enrolledCourses[i] == cid && enrolledStudents[i] == sid)
                return;
        }
        enrolledCourses.push_back(cid);
        enrolledStudents.push_back(sid);
    }

    void removeStudent(const string& cid, const string& sid) {
        for (size_t i = 0; i < enrolledCourses.size(); ++i) {
            if (enrolledCourses[i] == cid && enrolledStudents[i] == sid) {
                enrolledCourses.erase(enrolledCourses.begin() + i);
                enrolledStudents.erase(enrolledStudents.begin() + i);
                return;
            }
        }
    }

    int totalEnrollment(const string& cid) const {
        int count = 0;
        for (const auto& course : enrolledCourses) {
            if (course == cid) count++;
        }
        return count;
    }
};
// aditya 
int main() {
    Individual* ref;

    Learner stud("Dhruv Bhatotia", 19, "CSU267", 9560840922, "03-02-2024", "B.Tech", 9.05);
    Educator prof("Dr. Seema Thakran", 36, "APS69", 7015211108, "MAL", "Discrete", "11-09-2011");

    ref = &stud;
    cout << "\n--- Student Info via Base Pointer ---\n";
    ref->showDetails();

    ref = &prof;
    cout << "\n--- Professor Info via Base Pointer ---\n";
    ref->showDetails();

    return 0;
}
