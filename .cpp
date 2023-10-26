#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Course {
private:
    string courseName;
public:
    Course(const string& name) : courseName(name) {}

    Course(const Course& other) : courseName(other.courseName) {}

    ~Course() {}

    string getCourseName() const {
        return courseName;
    }

    friend ostream& operator<<(ostream& os, const Course& course) {
        os << "Course Name: " << course.courseName;
        return os;
    }
};

class Student {
private:
    string studentName;
    int age;
    vector<Course> courses;
public:
    Student(const string& name, const int age, const vector<Course>& courses) : studentName(name), age(age), courses(courses) {}

    Student(const Student& other) : studentName(other.studentName), age(other.age), courses(other.courses) {}

    ~Student() {}

    string getStudentName() const {
        return studentName;
    }

    friend ostream& operator<<(ostream& os, const Student& student) {
        os << "Student's name: " << student.studentName << ", age: " << student.age << endl;
        os << "Courses: " << endl;
        for (const auto& course : student.courses) {
            os << course << endl;
        }
        return os;
    }

    void enrollCourse(const Course& course) {
        courses.push_back(course);
    }

    void dropCourse(const string& courseName) {
        for (auto it = courses.begin(); it != courses.end(); ++it) {
            if (it->getCourseName() == courseName) {
                courses.erase(it);
                break;
            }
        }
    }

    void displayCourses() {
        cout << "Courses enrolled by " << studentName << ":" << endl;
        for (const auto& course : courses) {
            cout << course << endl;
        }
    }
};

class University {
private:
    vector<Student> students;
public:
    University() {}

    University(const vector<Student>& students) : students(students) {}

    University(const University& other) : students(other.students) {}

    ~University() {}

    void admitStudent(const Student& student) {
        students.push_back(student);
    }

    void expelStudent(const string& studentName) {
        for (auto it = students.begin(); it != students.end(); ++it) {
            if (it->getStudentName() == studentName) {
                students.erase(it);
                break;
            }
        }
    }

    void displayStudents() {
        cout << "List of students: " << endl;
        for (const auto& student : students) {
            cout << student << endl;
        }
    }
};

int main() {
    Course c1("Mathematics");
    Course c2("Physics");
    Course c3("Biology");

    vector<Course> courses = {c1, c2};

    Student s1("John Doe", 20, courses);
    s1.enrollCourse(c3);

    Student s2("Jane Smith", 22, {c2, c3});

    University myUniversity;
    myUniversity.admitStudent(s1);
    myUniversity.admitStudent(s2);

    myUniversity.displayStudents();

    s1.displayCourses();
    s2.dropCourse("Physics");
    s2.displayCourses();

    return 0;
}