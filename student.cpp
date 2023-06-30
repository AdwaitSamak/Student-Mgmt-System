#include <iostream>
#include <bits/stdc++.h>
using namespace std;
class student
{
private:
    int rollno;
    string name;
    int age;

public:
    student(int rollno = 0, string name = "NULL", int age = 0)
    { // overloaded constructor
        this->rollno = rollno;
        this->name = name;
        this->age = age;
    }
    void setrollno(int r);
    int getrollno();
    void setname(string s);
    string getname();
    void setage(int a);
    int getage();
    void display();
};
// Member functions below
void student::setrollno(int r)
{
    rollno = r;
}
int student::getrollno()
{
    return rollno;
}
void student::setname(string s)
{
    name = s;
}
string student::getname()
{
    return name;
}
void student::setage(int a)
{
    age = a;
}
int student::getage()
{
    return age;
}
void student::display()
{
    cout << "Rollno->" << rollno << endl;
    cout << "Name->" << name << endl;
    cout << "Age->" << age << endl;
}

void searchStudent(vector<student> &students)
{
    int rollno;
    cout << "Enter Rollno to be searched: ";
    cin >> rollno;

    for (int i = 0; i < students.size(); i++)
    {
        if (students[i].getrollno() == rollno)
        {
            cout << "Student Found!!!" << endl;
            students[i].display();
            return;
        }
    }
}

void displayall(vector<student> &students)
{
    if (students.empty())
    {
        cout << "No Students Found!!!" << endl;
        return;
    }
    for (int i = 0; i < students.size(); i++)
    {
        cout<<"Student "<<i+1<<endl;
        students[i].display();
        cout << endl;
    }
}

void addStudent(vector<student> &students)
{
    int rollno, age;
    string name;
    cout << "Enter Roll no: ";
    cin >> rollno;
    cout << "Enter Name: ";
    cin >> name;
    cout << "Enter Age: ";
    cin >> age;

    for (int i = 0; i < students.size(); i++)
    {
        if (students[i].getrollno() == rollno)
        {
            cout << "Student already exists!!" << endl;
            return;
        }
    }
    student s(rollno, name, age); // created object and called constructor which sets the details
    students.push_back(s);        // pushed object to vector
}

void deleteStudent(vector<student> &students)
{
    string name;
    cout << "Enter name for which record is to be deleted: ";
    cin >> name;
    for (int i = 0; i < students.size(); i++)
    {
        if (students[i].getname() == name)
        {
            students.erase(students.begin() + i);
            cout << "Student Record Deleted Successfully!!" << endl;
        }
    }
}

void updateStudent(vector<student> &students)
{
    string name;
    bool found = false;
    int choice;
    cout << "Enter name for which record is to be updated: ";
    cin >> name;

    for (int i = 0; i < students.size(); i++)
    {
        if (students[i].getname() == name)
        {
            found = true;
            cout << "Student Found!!" << endl;
            cout << "1. Update Rollno" << endl;
            cout << "2. Update Name" << endl;
            cout << "3. Update Age" << endl;
            cout << "4. Update All" << endl;
            cout << "Enter choice: ";
            cin >> choice;

            switch (choice)
            {
            case 1:
            {
                int rn;
                cout << "Enter new Rollno: ";
                cin >> rn;
                students[i].setrollno(rn);
                break;
            }

            case 2:
            {
                string name;
                cout << "Enter new name: ";
                cin >> name;
                students[i].setname(name);
                break;
            }

            case 3:
            {
                int age;
                cout << "Enter new age: ";
                cin >> age;
                students[i].setage(age);
                break;
            }

            case 4:
            {
                int roll, age;
                string name;
                cout << "Enter new rollno, name and age: ";
                cin >> roll >> name >> age;
                students[i].setrollno(roll);
                students[i].setname(name);
                students[i].setage(age);
                break;
            }

            default:
                cout << "Invalid Number!!" << endl;
            }
        }
    }
    if (found == false)
    {
        cout << "Record Not Found!!!" << endl;
        return;
    }
}

int main()
{
    vector<student> students; // vector of student details
    char choice;
    int option;
    do
    {
        cout << "-------Student Management System-------"<<endl;
        cout << "---------------------------------------"<<endl;
        cout << "1. Add New Student" << endl;
        cout << "2. Display All Students" << endl;
        cout << "3. Search Student Data" << endl;
        cout << "4. Update Student Data" << endl;
        cout << "5. Delete Student Data" << endl;
        cout << "6. Exit" << endl;
        cout << "Enter Choice: ";
        cin >> option;

        switch (option)
        {
        case 1:
            addStudent(students);
            break;
        case 2:
            displayall(students);
            break;
        case 3:
            searchStudent(students);
            break;
        case 4:
            updateStudent(students);
            break;
        case 5:
            deleteStudent(students);
            break;
        case 6:
            exit(1);
        default:
            cout << "Invalid Number!!" << endl;
        }

        cout << "Do You Want To Continue? (Y/N): ";
        cin >> choice;
    } while (choice == 'y' || choice == 'Y');

    return 0;
}