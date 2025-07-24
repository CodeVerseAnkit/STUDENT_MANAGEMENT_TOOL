#include <iostream>
#include <vector>
#include <string>
using namespace std;

/* <= STUDENT MANAGEMENT SYSTEM =>
 Author: Ankit
 Date: 23_7_2025
 Project: Student Management System
 Description: It is a simple student management system project
 */

// ---> UI
void menu()
{
	cout << "  <---------- STUDENT MANAGEMENT SYSTEM ---------->\n              ~~~~~~~~~~~~~~~~~~~~~~~~~\n                       📒📒📒\n"
		 << endl;
	cout << "  1. ADD STUDENT                  2. VIEW STUDENT\n  3. SEARCH STUDENT               4. DELETE STUDENT\n  5. EDIT STUDENT                 6. ABOUT\n  7. EXIT\n _______________________📒________________________\n"
		 << endl;
}
// ---> struct for students different type of information
struct student
{
	int roll_no;
	string name;
	string course;
	long long mobile_no;
	double fees;
};
// ---> vector to store students data
vector<student> students; //<=
// ---> back button to handle user wrong input
void back_button()
{
	char yes;
	do
	{
		cout << "   Type (y) to back: ";
		cin >> yes;
		if (yes == 'y' || yes == 'Y')
		{
			break;
		}
	} while (yes != 'y' || yes != 'Y');
	cout << endl;
}
// ---> Check for duplicate roll no
bool duplicate_roll(int roll)
{
	for (const auto &s : students)
	{
		if (s.roll_no == roll)
		{
			return true;
		}
	}
	return false;
}
void about(); // only declaration and the Explaination is below the main function

// ---> 1. Add Student
void add_student()
{
	student s; // store input from user
	cout << "       😊WELCOME TO STUDENT MANAGEMENT SYSTEM😊\n       ----------------------------------------\n"
		 << endl;
	cout << "     To add students 👩‍🎓 \n     First fulfill this student's details📒\n"
		 << endl; // details fill by user to add student
	cout << "   Enter Student Roll no. : ";
	cin >> s.roll_no;
	cout << "   Enter Student Name: ";
	cin.ignore();
	getline(cin, s.name);
	cout << "   Enter Student Course: ";
	cin >> s.course;
	cout << "   Enter Student Mobile no.: ";
	cin >> s.mobile_no;
	cout << "   Enter Student Fees: ";
	cin >> s.fees;
	students.push_back(s); // stored in vector
	// saving processing message
	cout << "\n   Saving... \n   Saving... \n   Saving... \n";
	cout << "\n     Student added successfully 📝\n"
		 << endl;

	char user;
	do // it provide feature if user wants to add student without going to back to the menu
	{
		cout << "   Do you want to add more students(y/n) : ";
		cin >> user;
		if (user == 'y' || user == 'Y')
		{ // details fill by user of student
			cout << "\n   Enter Student Roll no. : ";
			cin >> s.roll_no;
			if (duplicate_roll(s.roll_no))
			{
				cout << "\n   This roll no. already exit\n   Enter unique Rollno.🖋\n"
					 << endl;
				continue;
			}
			cout << "   Enter Student Name: ";
			cin.ignore();
			getline(cin, s.name);
			cout << "   Enter Student Course: ";
			cin >> s.course;
			cout << "   Enter Student Mobile no.: ";
			cin >> s.mobile_no;
			cout << "   Enter Student Fees: ";
			cin >> s.fees;
			students.push_back(s); // store in vector
			// processing message
			cout << "\n   Saving... \n   Saving... \n   Saving... \n";
			cout << "\n     Student added successfully 📝\n"
				 << endl;
		}
		if (user == 'n' || user == 'N')
		{
			break; // exit loop
		}
	} while (user != 'n' || user != 'N');

	back_button(); // back to the menu
}
// ---> 2. View Student
void display_student()
{
	if (!students.empty())
	{
		cout << "       😊WELCOME TO STUDENT MANAGEMENT SYSTEM😊\n       ----------------------------------------\n"
			 << endl;
		cout << "   Here are the details of Students:-\n " << endl;
		cout << "  ROLL NO.   NAME     COURSE    MOBILE NO.    FEES\n  --------   ----     ------    ----------    ----\n";
		for (auto i : students)
		{ // print all details of student stores in vector
			cout << "   " << i.roll_no << "      " << i.name << "    " << i.course << "       " << i.mobile_no << "    " << i.fees << endl;
		}
		cout << "\n  -------------------------------------------------\n"
			 << endl;
	}
	else
	{
		cout << "       😊WELCOME TO STUDENT MANAGEMENT SYSTEM😊\n       ----------------------------------------\n"
			 << endl; // if the vector is empty
		cout << "   Sorry there are no ddetails here🥲\n"
			 << endl;
	}
	back_button(); // back to main menu
}
// ---> 3. Search Student
void search_student()
{
	int roll; // store roll no given by user for temporary
	cout << "\n   📒SEARCH STUDENT... \n\n   Enter Roll No. : ";
	cin >> roll;
	bool found = false; // it is used in case of printing message if vector is empty
	for (const auto &s : students)
	{ // this loop search for roll no
		if (s.roll_no == roll)
		{ // processing message
			cout << "\n   Searching🔍...\n   Searching🔍...\n   Searching🔍..." << endl;
			// print details
			cout << "\n   Student Details:\n\n   Roll No. : " << s.roll_no << "\n   Name: " << s.name << "\n   Course: " << s.course << "\n   Mobile No. : " << s.mobile_no << "\n   Fees: " << s.fees << endl;
			found = true; // roll no found
			break;		  // exit loop
		}
	}
	if (!found)
	{
		cout << "\n   Searching🔍...\n   Searching🔍...\n   Searching🔍...\n"
			 << endl;
		// if the vector is empty
		cout << "   Student Not Found🥲 \n"
			 << endl;
	}
	char user;
	do // it prove feature, if user wants to search more student without going to back menu
	{
		cout << "\n   Do you want to search more(y/n) : ";
		cin >> user;

		if (user == 'y' || user == 'Y')
		{
			cout << "\n   Enter Roll No. : ";
			cin >> roll;
			bool found = false;
			for (const auto &s : students)
			{ // search for roll no
				if (s.roll_no == roll)
				{ // processing message
					cout << "\n   Searching🔍...\n   Searching🔍...\n   Searching🔍..." << endl;
					// print details
					cout << "\n   Student Details:\n\n   Roll No. : " << s.roll_no << "\n   Name: " << s.name << "\n   Course: " << s.course << "\n   Mobile No. : " << s.mobile_no << "\n   Fees: " << s.fees << endl;
					found = true;
					break;
				}
			}
			if (!found)
			{
				cout << "\n   Searching🔍...\n   Searching🔍...\n   Searching🔍...\n"
					 << endl;
				// if the vector is empty
				cout << "   Student Not Found🥲 \n"
					 << endl;
			}
		}
		if (user == 'n' || user == 'N')
		{
			break; // exit loop
		}

	} while (user != 'n' || user != 'N');
	back_button(); // back to the main menu
}
// ---> 4. Delete student

void delete_student()
{
	int roll; // store roll no
	cout << "    ❌TO DELETE STUDENT FROM DATA COLLECTION...\n\n   Enter Student Roll No. : ";
	cin >> roll;
	// processing message
	cout << "\n   Searching for student... \n   Searching for student... \n   Searching for student... \n"
		 << endl;
	bool found = false; // helps in checking for vector is empty or not

	for (auto it = students.begin(); it < students.end(); ++it)
	{ // iterate
		if (it->roll_no == roll)
		{ // processing message
			cout << "   Deleting... \n   Deleting... \n   Deleting... \n"
				 << endl;
			students.erase(it); // erase student data
			cout << "   Student Deleted Successfully ☑️" << endl;
			found = true; // it means roll no founded
			break;		  // exit loop
		}
	}
	if (!found)
	{ // print message if vector is empty
		cout << "   Student Not Found🥲 " << endl;
	}
	char user;
	do // it prove feature, if user wants to delete more student without going to back menu
	{
		cout << "\n   Do you want to delete more student(y/n) : ";
		cin >> user;
		if (user == 'y' || user == 'Y')
		{
			cout << "\n   Enter Student Roll No. : ";
			cin >> roll;
			// processing message
			cout << "\n   Searching for student... \n   Searching for student... \n   Searching for student... \n"
				 << endl;
			bool found = false;

			for (auto it = students.begin(); it < students.end(); ++it)
			{
				if (it->roll_no == roll)
				{
					cout << "   Deleting... \n   Deleting... \n   Deleting... \n"
						 << endl;
					students.erase(it);
					cout << "   Student Deleted Successfully ☑️" << endl;
					// student deleted successfully
					found = true;
					break; // exit loop
				}
			}
			if (!found)
			{ // if vector is empty
				cout << "   Student Not Found🥲 " << endl;
			}
		}
		if (user == 'n' || user == 'N')
		{
			break; // exit loop
		}

	} while (user != 'n' || user != 'N');
	back_button(); // back to main menu
}
// ---> 5. Edit student
void edit_student()
{
	int student_roll, roll;	  // store roll no
	string student_name;	  // store name
	string student_course;	  // store course
	long long student_mobile; // store mobile no.
	double student_fees;	  // student fees
	cout << "     TO EDIT STUDENT DETAILS🖋:\n   ENTER Roll No. : ";
	cin >> roll;
	bool found = false; // useful
	for (auto it = students.begin(); it < students.end(); ++it)
	{ // this loop search for roll no
		if (it->roll_no == roll)
		{ // if roll no matched then this print
			// old details
			cout << "\n   Roll no. : " << it->roll_no << "\n   Name: " << it->name << "\n   Course: " << it->course << "\n   Mobile no. : " << it->mobile_no << "\n   Fees: " << it->fees << endl;
			// new details fill by user
			cout << "\n   Enter new Roll no. : ";
			cin >> student_roll;
			it->roll_no = student_roll;
			cout << "   Enter New Name: ";
			cin.ignore();
			getline(cin, student_name);
			it->name = student_name;
			cout << "   Enter New Course: ";
			cin >> student_course;
			it->course = student_course;
			cout << "   Enter New Mobile No. : ";
			cin >> student_mobile;
			it->mobile_no = student_mobile;
			cout << "   Enter New Fees: ";
			cin >> student_fees;
			it->fees = student_fees;
			// processing message
			cout << "\n   Updating... \n   Updating... \n   Updating... \n   New details updated successfully✅\n"
				 << endl;
			// new details
			cout << "   New details: " << endl;
			cout << "\n   Roll no. : " << it->roll_no << "\n   Name: " << it->name << "\n   Course: " << it->course << "\n   Mobile no. : " << it->mobile_no << "\n   Fees: " << it->fees << endl;
			found = true;
			break;
		}
	}
	if (!found)
	{ // if student not found
		cout << "   Student Not Found🥲 " << endl;
	}
	char user;
	do
	{ // this loop use to ask user for if user waant to edit more
		cout << "\n   Do you want to edit more student (y/n) : ";
		cin >> user;
		if (user == 'y' || user == 'Y')
		{
			cout << "\n   ENTER Roll No. : ";
			cin >> roll;
			bool found = false; // useful
			for (auto it = students.begin(); it < students.end(); ++it)
			{ // this loop search for roll no
				if (it->roll_no == roll)
				{	// if roll no matched then this print
					// old details
					found = true;
					cout << "\n   Roll no. : " << it->roll_no << "\n   Name: " << it->name << "\n   Course: " << it->course << "\n   Mobile no. : " << it->mobile_no << "\n   Fees: " << it->fees << endl;
					// new details fill by user
					cout << "\n   Enter new Roll no. : ";
					cin >> student_roll;
					if (duplicate_roll(student_roll))
					{
						cout << "\n   This roll no. already exit\n   Enter unique Rollno.🖋\n"
							 << endl;
						continue;
					}
					it->roll_no = student_roll;
					cout << "   Enter New Name: ";
					cin.ignore();
					getline(cin, student_name);
					it->name = student_name;
					cout << "   Enter New Course: ";
					cin >> student_course;
					it->course = student_course;
					cout << "   Enter New Mobile No. : ";
					cin >> student_mobile;
					it->mobile_no = student_mobile;
					cout << "   Enter New Fees: ";
					cin >> student_fees;
					it->fees = student_fees;
					// processing message
					cout << "\n   Updating... \n   Updating... \n   Updating... \n   New details updated successfully✅\n"
						 << endl;
					// new details
					cout << "   New details: " << endl;
					cout << "\n   Roll no. : " << it->roll_no << "\n   Name: " << it->name << "\n   Course: " << it->course << "\n   Mobile no. : " << it->mobile_no << "\n   Fees: " << it->fees << endl;

					break;
				}
			}
			if (!found)
			{ // if student not found
				cout << "   Student Not Found🥲 " << endl;
			}
		}
		if (user == 'n' || user == 'N')
		{
			break; // loop exit conditions
		}
	} while (user != 'n' || user != 'N');
	back_button(); // back button
}
// ---> Main menu
int main()
{
	int input;
	do
	{
		menu();
		do
		{ // this loop print a message if user give input that are not available.
			cout << "   Your Input: ";
			cin >> input;
			cout << endl;
			if (input <= 0 || input > 7)
			{
				cout << " Please give available input\n"
					 << endl;
			}
		} while (input <= 0 || input > 7); // -----> switch cases
		switch (input)
		{
		case 1:
			add_student();
			break;
		case 2:
			display_student();
			break;
		case 3:
			search_student();
			break;
		case 4:
			delete_student();
			break;
		case 5:
			edit_student();
			break;
		case 6:
			about();
			break;
		case 7:
			cout << "                🙏THANKS FOR VISITING 🙏\n                -------------------------\n"
				 << endl;
			cout << "   Exiting... \n   Exiting... \n   Exiting... \n"
				 << endl;
			break;
		default:
			cout << " Please give available input\n"
				 << endl;
		}

	} while (input != 7);
	return 0;
}
// ---> 6.About This Project👨‍💻
void about()
{ // just some details about this project
	cout << "  <---------- STUDENT MANAGEMENT SYSTEM ---------->\n              ~~~~~~~~~~~~~~~~~~~~~~~~~\n                       📒📒📒\n"
		 << endl;
	cout << "   Author: Ankit\n   Date : 23_7_2025 \n   Project : Student Management System\n   Description : It is a simple and console based\n   student management system project👨‍💻\n " << endl;
	cout << "                🙏THANKS FOR VISITING 🙏\n                -------------------------\n"
		 << endl;
	back_button();
}