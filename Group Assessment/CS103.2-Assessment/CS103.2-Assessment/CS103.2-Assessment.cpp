// CS103.2-Assessment.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <iomanip>
#include <stdio.h>
using namespace std;

//Structures
struct student
{
    int studIdNo = 0; //ID Number
    string GradeA, GradeB, GradeC, GradeD;
    string Monday = "12:30pm - 4:30pm";
    string Tuesday = "12:30pm - 4:30pm";
    string Wednesday = "Self Study - No Class";
    string Thursday = "12:30pm - 4:30pm";
    string Friday = "12:30pm - 4:30pm";
    string fName, lName, progEn, sign, clas, ask, self, progress, semester, course, Date, TeaName, email, NUmber; //First name, Last name, Program Enrolled
    char exprnc[1000];
}studentInfo;

struct teacher
{
    int teaIdNo = 0; //ID Number
    string fiName, laName, position, sign; //First name, Last name, Position
    string subA, subB, subC, subD, subE, subF;
    string lvlA, lvlB, lvlC, lvlD, lvlE, lvlF;
}teacherInfo;

struct others
{
    string choice, Date;
    double pin = 0, tries = 0;
}otherInp;

//Prototype
void line();
void admInfoInp();
void studInfoInp();
void passReg();
void teaLogin();
void stuLogin();
void TeaMmScreen();
void StuMmScreen();
void teaStuInf();
void stuStuInf();
void teaTeaInf();
void StuTeaInf();
void TeaRep();
void TeachDisplay();
void StuRep();
void StudDisplay();
void TeaClasSched(); 
void StuClaSched(); 
void StuTeaDsply();


//Main Function
int main()
{
    string goBack, yes = "yes", yes2 = "Yes";
    char choice = 0, admin = 'A', stud = 'B';

    line(); //Line function
    cout << "\t\tSCHOOL INFORMATION SYSTEM";
    line(); //Line function

    back:
    
    cout << "\n";
    cout << "Press capital (A) for Admin.\nPress capital (B) for Student.\n";
    cout << "Press small (e) to terminate/exit program.\n";
    cout << "Input here: ";
    cin >> choice;

    if (choice == admin)
    {
        admInfoInp();
    }
    else if (choice == stud)
    {
        studInfoInp();
    }
    else if (choice == 'e')
    {
        cout << "\n\nProgram Ended";
        return 0;
    }
    else
    {
        cout << "Invalid Input! Please Try Again! ";
        cout << "\n\n";
        goto back; //Goes to back
    }
}

//Line Function
void line()
{
    cout << "\n";
    for (int i = 0; i < 80; i++)
    {
        cout << "-";
    }
    cout << "\n";
}

//Admin Info Input Function
void admInfoInp()
{
    system("cls"); //Clears screen

    line(); //Line function
    cout << "\t\tSCHOOL INFORMATION SYSTEM";
    line(); //Line function
    cout << "\n";

    cout << "Enter Details:\n\n";

    cout << " Enter Admin ID Number: ";
    cin >> teacherInfo.teaIdNo;

    cout << "\n";

    cout << " Enter Last Name: ";
    cin >> teacherInfo.laName;

    cout << " Enter First Name: ";
    cin >> teacherInfo.fiName;

    cout << " Enter Position: ";
    cin >> teacherInfo.position;

    passReg(); //Login Function

    system("cls");//Clears screen

    teaLogin(); //Teacher Login Function
}

//Student Info Input Function
void studInfoInp()
{
    system("cls"); //Clears screen

    line(); //Line function
    cout << "\t\tSCHOOL INFORMATION SYSTEM";
    line(); //Line function
    cout << "\n";

    cout << "Enter Details:\n\n";

    cout << " Enter Student ID Number: ";
    cin >> studentInfo.studIdNo;

    cout << "\n";

    cout << " Enter Last Name: ";
    cin >> studentInfo.lName;

    cout << " Enter First Name: ";
    cin >> studentInfo.fName;

    cout << " Enter Program: ";
    cin >> studentInfo.progEn;

    passReg(); //Login Function

    system("cls");//Clears screen

    stuLogin(); //Student Login Function
}

//Password Registration Function
void passReg()
{
    system("cls");//Clears screen

    line(); //Line function
    cout << "\tSCHOOL INFORMATION SYSTEM";
    line(); //Line function
    cout << "\n";

    cout << "\nEnter pin number to be used through out your stay at the university: ";
    cin >> otherInp.pin;
}

//Teacher Login Function
void teaLogin()
{
    float password;
    string yesNo;
    string yes = "yes";

    system("cls");//Clears screen

    line(); //Line function
    cout << "\tSCHOOL INFORMATION SYSTEM";
    line(); //Line function
    cout << "\n";

    cout << "Welcome, " << teacherInfo.fiName << " " << teacherInfo.laName << "!\n\n";

    cout << "Enter pin to login: ";
    cin >> password;

    while (password != otherInp.pin && otherInp.tries < 2)
    {
        cout << "Try again, enter pin to login: ";
        cin >> password;
        otherInp.tries++;
    }

    if (password == otherInp.pin)
    {
        TeaMmScreen(); //Teacher Main Menu Screen
    }
    else
    {
        cout << "\nGo back to password registration (yes/no)? ";
        cin >> yesNo;

        if (yesNo == yes)
        {
            passReg(); //Password Registration Function
            teaLogin(); //Teacher Login Function
        }
        else
        {
            teaLogin(); //Teacher Login Function
        }
    }
}

//Student Login Function
void stuLogin()
{
    float password;
    string yesNo;
    string yes = "yes";

    system("cls");//Clears screen

    line(); //Line function
    cout << "\tSCHOOL INFORMATION SYSTEM";
    line(); //Line function
    cout << "\n";

    cout << "Welcome, " << studentInfo.fName << " " << studentInfo.lName << "!\n\n";

    cout << "Enter pin to login: ";
    cin >> password;

    while (password != otherInp.pin && otherInp.tries < 2)
    {
        cout << "Try again, enter pin to login: ";
        cin >> password;
        otherInp.tries++;
    }

    if (password == otherInp.pin)
    {
        StuMmScreen(); //Student Main Menu Screen
    }
    else
    {
        cout << "Go back to password registration (yes/no)? ";
        cin >> yesNo;

        if (yesNo == yes)
        {
            passReg(); //Password Registration Function
            stuLogin(); //Calls Student Login Function
        }
        else
        {
            stuLogin(); //Student Login Function
        }
    }

}

//Teacher Main Menu Screen
void TeaMmScreen()
{

    int menu = 0;

here:

    system("cls");//Clears screen

    line(); //Line function
    cout << "\t\tSCHOOL INFORMATION SYSTEM";
    line(); //Line function
    cout << "\n";

    cout << "Welcome, " << teacherInfo.fiName << " " << teacherInfo.laName << "!\n\n";

    cout << "MAIN MENU\n\n";

    cout << "1. Student Information\n";
    cout << "2. Teacher Information\n";
    cout << "3. Class Schedule Information\n";
    cout << "4. Reports\n";
    cout << "5. Exit Program\n\n";
    cout << "Enter menu number: ";
    cin >> menu;

        switch (menu)
        {
        case 1:
            teaStuInf(); //Teachers's Student Info Function
            break;
        case 2:
            teaTeaInf(); //Teacher's Teacher Info Function
            break;
        case 3:
            TeaClasSched(); //Teacher's Class Schedule
            break;
        case 4:
            TeaRep(); //Teacher's Reports Functions
            break;
        case 5:
            cout << "\nThank you for using our application!\n\n";
            cout << "Program Ended\n";

            exit(0);
            break;
        default:
            cout << " ERROR ";
            goto here;
        }
       
    
}

//Student Main Menu Screen
void StuMmScreen()
{
    bool exitCondition = false;
    int menu = 0;

here:

    system("cls");//Clears screen

    line(); //Line function
    cout << "\tSCHOOL INFORMATION SYSTEM";
    line(); //Line function
    cout << "\n";

    cout << "Welcome, " << studentInfo.fName << " " << studentInfo.lName << "!\n\n";

    cout << "MAIN MENU\n\n";

    cout << "1. Student Information\n";
    cout << "2. Teacher Information\n";
    cout << "3. Class Schedule Information\n";
    cout << "4. Reports\n";
    cout << "5. Exit Program\n\n";
    cout << "Enter menu number: ";
    cin >> menu;

    while (!exitCondition)
    {
        switch (menu)
        {
        case 1:
            stuStuInf(); //Students' Student Info Function
            break;
        case 2:
            StuTeaInf(); //Student's Teacher Info Function
            break;
        case 3:
            StuClaSched(); //Student's Class Schedule
            break;
        case 4:
            StuRep(); //Student's Reports Function
            break;
        case 5:
            exitCondition = true; //Exits the program
            break;
        default:
            cout << " ERROR ";
            goto here;
        }
        cout << "\nThank you for using our application!\n\n";
        cout << "Program Ended\n";
    }
}

//Teacher's Student Info Function
void teaStuInf()
{
    int choice;
    string yesNo;

    bool exitCondition = false;

back:

    system("cls"); //Clears screen

    line(); //Line function
    cout << "\t\tSCHOOL INFORMATION SYSTEM";
    line(); //Line function
    cout << "\n";

    cout << "1. Input Students' Information\n";
    cout << "2. Output Students' Information\n";
    cout << "3. Return to Main Menu\n";
    cout << "4. Exit Program\n\n";
    cin >> choice;

    while (!exitCondition)
    {
        switch (choice)
        {
        case 1:
            system("cls"); //Clears screen

            line(); //Line function
            cout << "\tSCHOOL INFORMATION SYSTEM";
            line(); //Line function
            cout << "\n";

        here:

            cout << "Enter Student Information:\n";

            cout << "\n Enter Student ID Number: ";
            cin >> studentInfo.studIdNo;

            cout << "\n";

            cout << " Enter Last Name: ";
            cin >> studentInfo.lName;

            cout << " Enter First Name: ";
            cin >> studentInfo.fName;

            cout << " Enter Program: ";
            cin >> studentInfo.progEn;

            cout << "\n\nGo back (yes/ no)? ";
            cin >> yesNo;

            if (yesNo == "yes")
            {
                goto back;
            }
            else
            {
                cout << "Add another (yes/no)? " << "\n";
                goto here;
            }

            break;

        case 2:
            system("cls"); //Clears screen

            line(); //Line function
            cout << "\tSCHOOL INFORMATION SYSTEM";
            line(); //Line function
            cout << "\n";

            cout << "Student Information:\n";

            cout << " Student ID Number: " << studentInfo.studIdNo << "\n";

            cout << " Enter Last Name: " << studentInfo.lName << "\n";

            cout << " Enter First Name: " << studentInfo.fName << "\n";

            cout << " Enter Program: " << studentInfo.progEn << "\n";


            cout << "\n\nGo back (yes/no)? ";
            cin >> yesNo;

            if (yesNo == "yes")
            {
                goto back;
            }

            break;

        case 3:
            TeaMmScreen(); //Teacher Main Menu Screen
            break;

        case 4:
            exitCondition = true; //Exits the program
            break;

        default:
            cout << " ERROR ";
        }
        cout << "\nThank you for using our application!\n\n";
        cout << "Program Ended\n";
    }
}

//Student's Student Info Function
void stuStuInf()
{
    string yesNo;
    string yes = "yes";

    system("cls"); //Clears screen

    line(); //Line function
    cout << "\t\tSCHOOL INFORMATION SYSTEM";
    line(); //Line function
    cout << "\n";

    cout << "Your Information: \n\n";
    cout << " Student ID Number: " << studentInfo.studIdNo << endl;
    cout << " Last Name: " << studentInfo.lName << endl;
    cout << " First Name: " << studentInfo.fName << endl;
    cout << " Program: " << studentInfo.progEn << endl;

    cout << "\nGo back to Main Menu (yes/no)? ";
    cin >> yesNo;

    if (yesNo == yes)
    {
        StuMmScreen(); //Student Main Menu Screen
    }
    else
    {
        stuStuInf(); //Students' Student Info Function
    }

}

//Teacher's Teacher Info Function
void teaTeaInf()
{
    string yesNo;
    string yes = "yes";

    system("cls");//Clears screen

    line(); //Line function
    cout << "\t\tSCHOOL INFORMATION SYSTEM";
    line(); //Line function
    cout << "\n";

    cout << "Your Information: \n\n";
    cout << " Admin ID Number: " << teacherInfo.teaIdNo << endl;
    cout << " Last Name: " << teacherInfo.laName << endl;
    cout << " First Name: " << teacherInfo.fiName << endl;
    cout << " Your Position: " << teacherInfo.position << endl;

    cout << "\nGo back to Main Menu (yes/no)? ";
    cin >> yesNo;

    if (yesNo == yes)
    {
        TeaMmScreen(); //Teacher Main Menu Screen
    }
    else
    {
        teaTeaInf(); //Teacher's Teacher Info Function
    }
}

//Student's Teacher Info Function
void StuTeaInf()
{
    system("cls"); //Clears screen

    char choice = 0, term = 'e', back = 'b', Disply = 'd';

    line(); //Line function
    cout << "\t\tSCHOOL INFORMATION SYSTEM";
    line(); //Line function
    cout << "\n";

    cout << "STUDENT REPORT\n";
    cout << "\n";

    cout << " \n Student Name:" << studentInfo.fName << " \tLast Name:" << studentInfo.lName << "\t\tStudent ID:" << studentInfo.studIdNo << endl;
    cout << "\n Semester: ";
    cin >> studentInfo.semester;
    cout << "\n Date: ";
    cin >> studentInfo.Date;
    cout << "\n What Course: ";
    cin >> studentInfo.course;
    cout << "\n Tutor's Name: ";
    cin >> studentInfo.TeaName;
    cout << "\n Phone/  Telephone Number: ";
    cin >> studentInfo.NUmber;
    cout << "\n Enter Email: ";
    cin >> studentInfo.email;

    cout << "\n Describe Overall experience of 3 years during your studies in Campus: \n";
    cin >> studentInfo.exprnc;

redo:

    cout << "\n\n Press d for Display all ";
    cout << "\n Press b to return to Menu ";
    cout << "\n Press e to Exit ";
    cin >> choice;

    if (choice == back)
    {
        StuMmScreen(); // back to Menu for Admin or Teacher 
    }
    else if (choice == term)
    {
        cout << "Terminating....";
        exit(0);
    }
    else if (choice == Disply)
    {
        StudDisplay();// goes to Display All the input in student display function
    }
    else {
        cout << "Wrong letter, Please Try again";
        goto redo;
    }
}

// Display function after inputting on StuTeaInf()
void StuTeaDsply() 
{
    system("cls");//clear screen
    char choice = 0, Dsply = 'd', term = 't', backm = 'b';

    cout << "\n\n";
    cout << "\nSubjects:             " << "Math " << " " << right << setw(10) << setprecision(2) << fixed << " English" << " " << right << setw(10) << setprecision(2) << fixed << " Science" << " " << right << setw(10) << setprecision(2) << fixed << " PED " << " " << right << setw(10) << setprecision(2) << fixed << " Chemistry " << " " << right << setw(10) << setprecision(2) << fixed << "Computer Programming " << " " << right << setw(10) << setprecision(2) << fixed << endl;
    cout << "\nNames of the Teacher: " << teacherInfo.subA << right << setw(10) << setprecision(2) << fixed << teacherInfo.subB << right << setw(10) << setprecision(2) << fixed << teacherInfo.subC << right << setw(10) << setprecision(2) << fixed << teacherInfo.subD << right << setw(10) << setprecision(2) << fixed << teacherInfo.subE << right << setw(10) << setprecision(2) << fixed << teacherInfo.subF << endl;
    cout << "\nLevels:               " << teacherInfo.lvlA << right << setw(10) << setprecision(2) << fixed << teacherInfo.lvlB << right << setw(10) << setprecision(2) << fixed << teacherInfo.lvlC << right << setw(10) << setprecision(2) << fixed << teacherInfo.lvlD << right << setw(10) << setprecision(2) << fixed << teacherInfo.lvlE << right << setw(10) << setprecision(2) << fixed << teacherInfo.lvlF << endl;
    cout << "\n\n";

again:

    cout << "Press t to shutdown: \n";
    cout << "Press b to go back to Menu:";
    cin >> choice;

    if (choice == term)
    {
        exit(0);
    }
    else if (choice == backm)
    {
        StuMmScreen();
    }
    else {
        cout << "Wrong letter, Please Try Again:";
        goto again;
    }
}

//Teacher's Reports Functions
void TeaRep()
{
    system("cls"); //Clears screen

    char choice = 0, finishy = 'y', finishn = 'e';

    line(); //Line function
    cout << "\t\tSCHOOL INFORMATION SYSTEM";
    line(); //Line function

    cout << "Report: \n";

    cout << "\nStudent: ";
    cout << "\n First Name: ";
    cin >> studentInfo.fName;
    cout << " Last Name: ";
    cin >> studentInfo.lName;
    cout << " Student ID: ";
    cin >> studentInfo.studIdNo;

    cout << "\n\n";
    cout << "Teacher: ";
    cout << "\n First Name: ";
    cin >> teacherInfo.fiName;
    cout << " Last Name: ";
    cin >> teacherInfo.laName;
    cout << " Admin ID Number: ";
    cin >> teacherInfo.teaIdNo;
    cout << " Signature: ";
    cin >> teacherInfo.sign;

    cout << "\n Date: ";
    cin >> otherInp.Date;
    cout << "\n\n";

    cout << "Student Rating (poor/ weak/ average/ good/ excellent)";

    cout << "\n Does work in class? ";
    cin >> studentInfo.clas;

    cout << " Does ask questions? ";
    cin >> studentInfo.ask;

    cout << " Self-learning? ";
    cin >> studentInfo.self;

    cout << " Progress at course? ";
    cin >> studentInfo.progress;

    cout << "\n\n";

again:

    cout << "Press y to Display Report \n";
    cout << "Press e to Exit Program ";
    cin >> choice;

    if (choice == finishy)
    {
        TeachDisplay();
        system("cls"); //Clears screen
    }
    else if (choice == finishn)
    {
        cout << "Terminating....";
        cout << "\nPress (space bar)";

        system("pause");
    }
    else {
        cout << "wrong choice!";
        goto again;
    }
}

//Teacher's Reports Display Functions
void TeachDisplay()
{
    system("cls"); //Clears screen

    char choice = 0, exit = 'e', back = 'b';

    line(); //Line function
    cout << "\t\tSCHOOL INFORMATION SYSTEM";
    line(); //Line function

    cout << "\nTeacher's Report Display: \n\n";

    cout << "Student: ";
    cout << "\n Fisrt Name: " << studentInfo.fName << "\n Last Name: " << studentInfo.lName << "\n Student ID: " << studentInfo.studIdNo << endl;
    cout << "\n\n";

    cout << "Teacher: ";
    cout << "\n First Name: " << teacherInfo.fiName << "\n Last Name: " << teacherInfo.laName << "\n Admin ID Number: " << teacherInfo.teaIdNo << "\n Signature: " << teacherInfo.sign << endl;

    cout << "\nDate:" << otherInp.Date << endl;


    cout << " \n\n| Does work in class?  | Does ask questions?  |    Self-learning?    |  Progress at course? |" << endl;
    cout << "|" << setw(22) << studentInfo.clas << "|" << setw(22) << studentInfo.ask << "|" << setw(22) << studentInfo.self << "|" << setw(22) << studentInfo.progress << "|\n";

redo:

    cout << "\n\nPress e to Exit ";
    cout << "\nPress b to return to Menu ";
    cin >> choice;

    if (choice == back)
    {
        TeaMmScreen(); // Teacher's Main Menu Screen
    }
    else if (choice == exit)
    {
        cout << "Terminating....";
        cout << "\nPress (space bar)";

        system("pause");
    }
    else {
        cout << "Wrong letter, Please Try again";
        goto redo;
    }
}

//Student's Reports Function
void StuRep()
{
    system("cls"); //Clears screen

    char choice = 0, term = 'e', back = 'b', Disply = 'd';

    line(); //Line function
    cout << "\t\tSCHOOL INFORMATION SYSTEM";
    line(); //Line function
    cout << "\n";

    cout << "Student's Report: \n";
    cout << "\n";

    cout << " \n Student Name:" << studentInfo.fName << " \tLast Name:" << studentInfo.lName << "\t\tStudent ID:" << studentInfo.studIdNo << endl;
    cout << "\n Semester: ";
    cin >> studentInfo.semester;
    cout << "\n Date: ";
    cin >> studentInfo.Date;
    cout << "\n What Course: ";
    cin >> studentInfo.course;
    cout << "\n Tutor's Name: ";
    cin >> studentInfo.TeaName;
    cout << " \n Phone/ Telephone Number: ";
    cin >> studentInfo.NUmber;
    cout << "\n Enter Email: ";
    cin >> studentInfo.email;

    cout << "\nDescribe Overall experience of 3 years during your studies in Campus (Press zero (0) and enter if done): \n";
    cin.getline(studentInfo.exprnc, 1000, '0');

redo:

    cout << "\n\n Press e to Exit?:";
    cout << "\n Press b to return to Menu?";
    cout << "\n Press d to display all: ";
    cin >> choice;

    if (choice == back)
    {
        StuMmScreen(); // back to Menu for Admin or Teacher 
    }
    else if (choice == term)
    {
        cout << "Terminating....";
        exit(0);
    }
    else if (choice == Disply)
    {
        StudDisplay();// goes to Display All the input in student display function
    }
    else
    {
        cout << "Wrong letter, Please Try again";
        goto redo;
    }
}
 

void StudDisplay()
{ 
    system("cls"); //Clears screen
    char choice = 0, back = 'b', term = 'e', Login = 'L';

    line(); //Line function
    cout << "\t\tSCHOOL INFORMATION SYSTEM";
    line(); //Line function
    cout << "\n";

    cout << "Student's Report: \n";
    cout << "\n";

    cout << " \n Student Name: " << studentInfo.fName << " \t Last Name: " << studentInfo.lName << "\t\tStudent ID: " << studentInfo.studIdNo << endl;
    cout << "\n Semester: " << studentInfo.semester << "\t Date: " << studentInfo.Date << endl;
    cout << "\n Course: " << studentInfo.course << "\t Tutor Name: " << studentInfo.TeaName << endl;
    cout << " \n Phone/ Telephone Number: " << studentInfo.NUmber << endl;
    cout << "\n Email: " << studentInfo.email << endl;

    cout << "\n Describe Overall experience of 3 years during your studies in Campus: \n";
    cout << " " << studentInfo.exprnc;

redo:

    cout << "\n\n Press e to Exit ";
    cout << "\n Press b to return to Menu ";
    cout << "\n Press capital ( L ) for to login as an Admin ";

    cin >> choice;
    if (choice == back)
    {
        StuMmScreen(); // back to Menu for Admin or Teacher 
    }
    else if (choice == term)
    {
        cout << "Terminating....";
        exit(0);

    }
    else if (choice == Login)
    {
        admInfoInp();
    }
    else {
        cout << "Wrong letter, Please Try again";
        goto redo;
    }
}

//Teacher's Class Schedule Function
void TeaClasSched()
{
    system("cls"); //Clears screen

    char choice = 0, term = 'e', back = 'b';

    line(); //Line function
    cout << "\t\tSCHOOL INFORMATION SYSTEM";
    line(); //Line function
    cout << "\n";

    cout << "Admin TimeTable\n";
    cout << "\n";

    cout << "Monday" << " " << right << setw(20) << setprecision(2) << fixed << " " << "Tuesday" << right << setw(20) << setprecision(2) << fixed << " " << "Wednesday" << right << setw(20) << setprecision(2) << fixed << " " << "Thursday" << right << setw(20) << setprecision(2) << fixed << " " << "Friday" << endl;
    cout << studentInfo.Monday << right << setw(10) << setprecision(2) << fixed << "|" << studentInfo.Tuesday << right << setw(10) << setprecision(2) << fixed << "|" << studentInfo.Wednesday << right << setw(10) << setprecision(2) << fixed << "|" << studentInfo.Thursday << right << setw(10) << setprecision(2) << fixed << "|" << studentInfo.Friday << endl;

redo:

    cout << "\n\n Press e to Exit ";
    cout << "\n Press b to return to Menu ";
    cin >> choice;

    if (choice == back)
    {
        TeaMmScreen(); //Teacher's Main Menu Function
    }
    else if (choice == term)
    {
        cout << "Terminating....";
        exit(0);
    }
    else 
    {
        cout << "Wrong letter, Please Try again";
        goto redo;
    }
}

//Student's Class Schedule Function
void StuClaSched()
{
    system("cls"); //Clears screen

    char choice = 0, term = 'e', back = 'b';

    line(); //Line function
    cout << "\t\tSCHOOL INFORMATION SYSTEM";
    line(); //Line function
    cout << "\n";

    cout << "Student TimeTable\n";
    cout << "\n";

    cout << "Monday" << " " << right << setw(20) << setprecision(2) << fixed << " " << "Tuesday" << right << setw(20) << setprecision(2) << fixed << " " << "Wednesday" << right << setw(20) << setprecision(2) << fixed << " " << "Thursday" << right << setw(20) << setprecision(2) << fixed << " " << "Friday" << endl;
    cout << studentInfo.Monday << right << setw(27) << setprecision(2) << fixed << studentInfo.Tuesday << right << setw(32) << setprecision(2) << fixed << studentInfo.Wednesday << right << setw(24) << setprecision(2) << fixed << studentInfo.Thursday << right << setw(28) << setprecision(2) << fixed << studentInfo.Friday << endl;
redo:
    cout << "\n\n Press e to Exit ";
    cout << "\n Press b to return to Menu?";
    cin >> choice;

    if (choice == back)
    {
        StuMmScreen(); // Student's Main Menu Function
    }
    else if (choice == term)
    {
        cout << "Terminating....";
        exit(0);
    }
    else {
        cout << "Wrong letter, Please Try again";
        goto redo;
    }
}

