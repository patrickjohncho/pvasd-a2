// Programmer: Patrick Cho
// Class: Project V: Advanced Software Development
// Date: 9/13/2024
// Project: Assignment 2
// Filename: source.cpp
// Description: This file contains the source code for Assignment 2

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>

using namespace std;

#define PRE_RELEASE

#ifdef PRE_RELEASE
    const string VERSION = "Pre-Release";
    const string FILE_PATH = "StudentData_Emails.txt";
    struct STUDENT_DATA {
        string firstName;
        string lastName;
        string email;
    };
#else
    const string VERSION = "Standard";
    const string FILE_PATH = "StudentData.txt";
    struct STUDENT_DATA {
        string firstName;
        string lastName;
    };
#endif

//Function to read the student data file
vector<STUDENT_DATA> readStudentData(const string& fileName) {
    vector<STUDENT_DATA> studentData;

    ifstream file(fileName);

    if (file.is_open()) {
        string line;
        
        while (getline(file, line)) {
            stringstream ss(line);
            string firstName, lastName;
            STUDENT_DATA currStudent;
            //Read line to comma delimiter into firstName var
            if (getline(file, lastName, ',')) {
                currStudent.lastName = lastName;
                //Read line to newline into lastName var
                if (getline(file, firstName)) {
                    currStudent.firstName = firstName;

                    #ifdef PRE_RELEASE
                        string email;
                        if (getline(file, email, ',')) {
                            currStudent.email = email;
                        }
                    #endif

                    //Add to vector
                    studentData.push_back(currStudent);
                }
            }
        }
        file.close();
    }
    else {
        cout << "Error: Could not open file";
        return studentData;
    }
   
    return studentData;
}

int main() {
    cout << "Version: " << VERSION << endl;
    vector<STUDENT_DATA> studentData = readStudentData(FILE_PATH);

    #ifdef _DEBUG
        #ifdef PRE_RELEASE
            for (int i = 0; i < studentData.size(); i++) cout << studentData[i].firstName << ' ' << studentData[i].lastName << ', ' << studentData[i].email << endl;
        #else
            for (int i = 0; i < studentData.size(); i++) cout << studentData[i].firstName << ' ' << studentData[i].lastName << endl;
        #endif
    #endif
    
	return 1;
}