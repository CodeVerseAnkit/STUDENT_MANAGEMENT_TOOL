#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct Student
{
	int roll;
	string name;
	string course;
};

vector<Student> students;

void addStudent()
{
	Student s;
	cout << "Enter roll number: ";
	cin >> s.roll;
	cin.ignore(); // to avoid newline issues
	cout << "Enter name: ";
	getline(cin, s.name);
	cout << "Enter course: ";
	getline(cin, s.course);
	students.push_back(s);
	cout << "Student added successfully!\n";
}

void displayStudents()
{
	if (students.empty())
	{
		cout << "No students to display.\n";
		return;
	}
	cout << "\n--- Student List ---\n";
	for (const auto &s : students)
	{
		cout << "Roll: " << s.roll << ", Name: " << s.name << ", Course: " << s.course << endl;
	}
}

void searchStudent()
{
	int roll;
	cout << "Enter roll number to search: ";
	cin >> roll;
	for (const auto &s : students)
	{
		if (s.roll == roll)
		{
			cout << "Student found: " << s.name << ", Course: " << s.course << endl;
			return;
		}
	}
	cout << "Student not found.\n";
}

void deleteStudent()
{
	int roll;
	cout << "Enter roll number to delete: ";
	cin >> roll;
	for (auto it = students.begin(); it != students.end(); ++it)
	{
		if (it->roll == roll)
		{
			students.erase(it);
			cout << "Student deleted successfully.\n";
			return;
		}
	}
	cout << "Student not found.\n";
}

int main()
{
	int choice;
	do
	{
		cout << "\n--- Student Management System ---\n";
		cout << "1. Add Student\n";
		cout << "2. Display Students\n";
		cout << "3. Search Student\n";
		cout << "4. Delete Student\n";
		cout << "5. Exit\n";
		cout << "Enter your choice: ";
		cin >> choice;

		switch (choice)
		{
		case 1:
			addStudent();
			break;
		case 2:
			displayStudents();
			break;
		case 3:
			searchStudent();
			break;
		case 4:
			deleteStudent();
			break;
		case 5:
			cout << "Exiting...\n";
			break;
		default:
			cout << "Invalid choice. Try again.\n";
		}
	} while (choice != 5);

	return 0;
}