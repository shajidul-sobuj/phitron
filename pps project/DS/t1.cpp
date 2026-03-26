#include <bits/stdc++.h>
using namespace std;

/* ================= STUDENT CLASS ================= */
class Student {
public:
    string id;
    string name;
    vector<string> enrolledCourses;

    Student() {}
    Student(string id, string name) {
        this->id = id;
        this->name = name;
    }
};

/* ================= COURSE CLASS ================= */
class Course {
public:
    string code;
    int capacity;
    string day;
    int startTime;
    int endTime;

    vector<string> enrolledStudents;
    queue<string> waitingList;
    vector<string> prerequisites;   // Tree-like structure

    Course() {}
    Course(string code, int cap, string day, int s, int e) {
        this->code = code;
        capacity = cap;
        this->day = day;
        startTime = s;
        endTime = e;
    }
};

/* ================= GLOBAL HASH TABLES ================= */
unordered_map<string, Student> students;
unordered_map<string, Course> courses;

/* ================= UTILITY FUNCTIONS ================= */

// Check time conflict
bool hasConflict(Student &student, Course &newCourse) {
    for (string c : student.enrolledCourses) {
        Course &existing = courses[c];
        if (existing.day == newCourse.day) {
            if (!(newCourse.endTime <= existing.startTime ||
                  newCourse.startTime >= existing.endTime)) {
                return true;
            }
        }
    }
    return false;
}

// Check prerequisites using DFS
bool checkPrerequisite(string courseCode, Student &student) {
    Course &course = courses[courseCode];

    for (string pre : course.prerequisites) {
        if (find(student.enrolledCourses.begin(),
                 student.enrolledCourses.end(),
                 pre) == student.enrolledCourses.end()) {
            return false;
        }
    }
    return true;
}

/* ================= CORE OPERATIONS ================= */

void addStudent() {
    string id, name;
    cout << "Enter Student ID: ";
    cin >> id;
    cout << "Enter Name: ";
    cin.ignore();
    getline(cin, name);

    students[id] = Student(id, name);
    cout << "Student added successfully!\n";
}

void addCourse() {
    string code, day;
    int cap, s, e;

    cout << "Enter Course Code: ";
    cin >> code;
    cout << "Capacity: ";
    cin >> cap;
    cout << "Day (Mon/Tue/Wed/etc): ";
    cin >> day;
    cout << "Start Time (24h): ";
    cin >> s;
    cout << "End Time (24h): ";
    cin >> e;

    courses[code] = Course(code, cap, day, s, e);
    cout << "Course added successfully!\n";
}

void addPrerequisite() {
    string course, pre;
    cout << "Enter Course Code: ";
    cin >> course;
    cout << "Enter Prerequisite Course Code: ";
    cin >> pre;

    courses[course].prerequisites.push_back(pre);
    cout << "Prerequisite added!\n";
}

void enrollStudent() {
    string sid, code;
    cout << "Student ID: ";
    cin >> sid;
    cout << "Course Code: ";
    cin >> code;

    if (!students.count(sid) || !courses.count(code)) {
        cout << "Invalid student or course!\n";
        return;
    }

    Student &student = students[sid];
    Course &course = courses[code];

    if (!checkPrerequisite(code, student)) {
        cout << "Prerequisite not satisfied!\n";
        return;
    }

    if (hasConflict(student, course)) {
        cout << "Schedule conflict detected!\n";
        return;
    }

    if ((int)course.enrolledStudents.size() < course.capacity) {
        course.enrolledStudents.push_back(sid);
        student.enrolledCourses.push_back(code);
        cout << "Enrollment successful!\n";
    } else {
        course.waitingList.push(sid);
        cout << "Course full. Added to waiting list.\n";
    }
}

void dropCourse() {
    string sid, code;
    cout << "Student ID: ";
    cin >> sid;
    cout << "Course Code: ";
    cin >> code;

    Student &student = students[sid];
    Course &course = courses[code];

    course.enrolledStudents.erase(
        remove(course.enrolledStudents.begin(),
               course.enrolledStudents.end(), sid),
        course.enrolledStudents.end());

    student.enrolledCourses.erase(
        remove(student.enrolledCourses.begin(),
               student.enrolledCourses.end(), code),
        student.enrolledCourses.end());

    if (!course.waitingList.empty()) {
        string next = course.waitingList.front();
        course.waitingList.pop();
        course.enrolledStudents.push_back(next);
        students[next].enrolledCourses.push_back(code);
        cout << "Next student from waiting list enrolled: " << next << "\n";
    }

    cout << "Course dropped successfully!\n";
}

void displayStatus() {
    for (auto &c : courses) {
        cout << "\nCourse: " << c.first << "\nEnrolled: ";
        for (string s : c.second.enrolledStudents)
            cout << s << " ";
        cout << "\nWaiting Queue Size: " << c.second.waitingList.size() << "\n";
    }
}

/* ================= MAIN MENU ================= */
int main() {
    int choice;
    while (true) {
        cout << "\n===== COURSE REGISTRATION PORTAL =====\n";
        cout << "1. Add Student\n";
        cout << "2. Add Course\n";
        cout << "3. Add Prerequisite\n";
        cout << "4. Enroll Student\n";
        cout << "5. Drop Course\n";
        cout << "6. Display Course Status\n";
        cout << "0. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
        case 1: addStudent(); break;
        case 2: addCourse(); break;
        case 3: addPrerequisite(); break;
        case 4: enrollStudent(); break;
        case 5: dropCourse(); break;
        case 6: displayStatus(); break;
        case 0: exit(0);
        default: cout << "Invalid choice!\n";
        }
    }
}
