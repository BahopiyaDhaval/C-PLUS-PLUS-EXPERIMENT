 #include <iostream>
#include <string>
using namespace std;


class Employee {
    int empID;
    string name;
    char gender;
    float salary;   


public:
    void getData(int id, string n, char g, float s) {
        empID = id;
        name = n;
        gender = g;
        salary = s;
    }
    void updateSalary(float newSalary) {
        salary = newSalary;
    }


    void display() {
        cout << "Emp ID   : " << empID << endl;
        cout << "Name     : " << name << endl;
        cout << "Gender   : " << gender << endl;
        cout << "Salary   : " << salary << endl;
        cout << "-------------------------" << endl;
    }
};


int main() {
    Employee emp[10];   


    emp[0].getData(101, "Amit",  'M', 25000);
    emp[1].getData(102, "Neha",  'F', 27000);
    emp[2].getData(103, "Rahul", 'M', 23000);
    emp[3].getData(104, "Pooja", 'F', 26000);
    emp[4].getData(105, "Ravi",  'M', 28000);
    emp[5].getData(106, "Kiran", 'F', 24000);
    emp[6].getData(107, "John",  'M', 30000);
    emp[7].getData(108, "Sara",  'F', 32000);
    emp[8].getData(109, "Vijay", 'M', 29000);
    emp[9].getData(110, "Anita", 'F', 31000);


    cout << "=== Employee Details BEFORE Salary Update ===" << endl;
    for (int i = 0; i < 10; i++) {
        emp[i].display();
    }
    float newSal;
    cout << "\nEnter new salary for each employee:\n";
    for (int i = 0; i < 10; i++) {
        cout << "Enter new salary for Emp ID " << (101 + i) << ": ";
        cin >> newSal;
        emp[i].updateSalary(newSal);
    }


    cout << "\n=== Employee Details AFTER Salary Update ===" << endl;
    for (int i = 0; i < 10; i++) {
        emp[i].display();
    }


    return 0;
}
