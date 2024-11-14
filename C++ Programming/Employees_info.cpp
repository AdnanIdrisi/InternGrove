#include <iostream>
#include <vector>
#include <string>
#include <limits>
using namespace std;

// Base class for Employee
class Employee {
protected:
    string name;
    int id;

public:
    Employee(const string& name, int id) : name(name), id(id) {}

    // Virtual function to calculate salary
    virtual double calculateSalary() const = 0;

    // Virtual function to display employee information
    virtual void displayInfo() const {
        cout << "Employee Name: " << name << endl;
        cout << "Employee ID: " << id << endl;
    }

    // Virtual destructor
    virtual ~Employee() {}
};

// Derived class for FullTimeEmployee
class FullTimeEmployee : public Employee {
private:
    double monthlySalary;

public:
    FullTimeEmployee(const string& name, int id, double monthlySalary)
        : Employee(name, id), monthlySalary(monthlySalary) {}

    // Override calculateSalary for full-time employees
    double calculateSalary() const override {
        return monthlySalary;
    }

    // Override displayInfo to include salary information
    void displayInfo() const override {
        Employee::displayInfo();
        cout << "Employment Type: Full-Time" << endl;
        cout << "Monthly Salary: $" << calculateSalary() << endl;
    }
};

// Derived class for PartTimeEmployee
class PartTimeEmployee : public Employee {
private:
    double hourlyRate;
    int hoursWorked;

public:
    PartTimeEmployee(const string& name, int id, double hourlyRate, int hoursWorked)
        : Employee(name, id), hourlyRate(hourlyRate), hoursWorked(hoursWorked) {}

    // Override calculateSalary for part-time employees
    double calculateSalary() const override {
        return hourlyRate * hoursWorked;
    }

    // Override displayInfo to include hourly rate and hours worked
    void displayInfo() const override {
        Employee::displayInfo();
        cout << "Employment Type: Part-Time" << endl;
        cout << "Hourly Rate: $" << hourlyRate << endl;
        cout << "Hours Worked: " << hoursWorked << endl;
        cout << "Total Salary: $" << calculateSalary() << endl;
    }
};

// Function prototypes
void addFullTimeEmployee(vector<Employee*>& employees);
void addPartTimeEmployee(vector<Employee*>& employees);
void displayAllEmployees(const vector<Employee*>& employees);
void calculateTotalSalaries(const vector<Employee*>& employees);

// Main function
int main() {
    vector<Employee*> employees;
    int choice;

    do {
        // Display the menu
        cout << "\n--- Employee Management System ---" << endl;
        cout << "1. Add Full-Time Employee" << endl;
        cout << "2. Add Part-Time Employee" << endl;
        cout << "3. Display All Employees" << endl;
        cout << "4. Calculate Total Salaries" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice (1-5): ";
        cin >> choice;

        // Clear the input buffer to prevent any issues with getline
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        // Perform the selected operation
        switch (choice) {
            case 1:
                addFullTimeEmployee(employees);
                break;
            case 2:
                addPartTimeEmployee(employees);
                break;
            case 3:
                displayAllEmployees(employees);
                break;
            case 4:
                calculateTotalSalaries(employees);
                break;
            case 5:
                cout << "Exiting the program." << endl;
                break;
            default:
                cout << "Invalid choice. Please select a valid option (1-5)." << endl;
                break;
        }
    } while (choice != 5);

    // Clean up dynamically allocated memory
    for (auto emp : employees) {
        delete emp;
    }

    return 0;
}

// Function to add a full-time employee
void addFullTimeEmployee(vector<Employee*>& employees) {
    string name;
    int id;
    double monthlySalary;

    cout << "Enter Full-Time Employee Name: ";
    getline(cin, name); // Use getline to allow multi-word names
    cout << "Enter Employee ID: ";
    cin >> id;
    cout << "Enter Monthly Salary: ";
    cin >> monthlySalary;

    employees.push_back(new FullTimeEmployee(name, id, monthlySalary));
    cout << "Full-Time Employee added successfully!" << endl;
}

// Function to add a part-time employee
void addPartTimeEmployee(vector<Employee*>& employees) {
    string name;
    int id;
    double hourlyRate;
    int hoursWorked;

    cout << "Enter Part-Time Employee Name: ";
    getline(cin, name); // Use getline to allow multi-word names
    cout << "Enter Employee ID: ";
    cin >> id;
    cout << "Enter Hourly Rate: ";
    cin >> hourlyRate;
    cout << "Enter Hours Worked: ";
    cin >> hoursWorked;

    employees.push_back(new PartTimeEmployee(name, id, hourlyRate, hoursWorked));
    cout << "Part-Time Employee added successfully!" << endl;
}

// Function to display all employees
void displayAllEmployees(const vector<Employee*>& employees) {
    if (employees.empty()) {
        cout << "No employees to display." << endl;
        return;
    }

    for (const auto& emp : employees) {
        emp->displayInfo();
        cout << "---------------------------------" << endl;
    }
}

// Function to calculate total salaries of all employees
void calculateTotalSalaries(const vector<Employee*>& employees) {
    if (employees.empty()) {
        cout << "No employees to calculate salaries for." << endl;
        return;
    }

    double totalSalaries = 0.0;
    for (const auto& emp : employees) {
        totalSalaries += emp->calculateSalary();
    }

    cout << "Total Salaries of All Employees: $" << totalSalaries << endl;
}

