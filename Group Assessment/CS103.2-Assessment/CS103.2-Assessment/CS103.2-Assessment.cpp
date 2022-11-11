// CS103.2-Assessment.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

//Structures
struct student
{
    int studIdNo = 0; //ID Number
    string fName, lName, progEn, sign, clas, ask, self, progress; //First name, Last name, Program Enrolled
}studentInfo;

struct teacher
{
    int teaIdNo = 0; //ID Number
    string fiName, laName, position, sign, Date; //First name, Last name, Position
}teacherInfo;

struct others
{
    string choice;
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
        system("cls"); //Clears screen
        admInfoInp();
    }
    else if (choice == stud)
    {
        system("cls"); //Clears screen
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

    line(); //Line function
    cout << "\t\tSCHOOL INFORMATION SYSTEM";
    line(); //Line function
    cout << "\n";

    cout << "Enter Details:\n\n";

    cout << "Enter Admin ID Number: ";
    cin >> teacherInfo.teaIdNo;

    cout << "\n";

    cout << "Enter Last Name: ";
    cin >> teacherInfo.laName;

    cout << "Enter First Name: ";
    cin >> teacherInfo.fiName;

    cout << "Enter Position: ";
    cin >> teacherInfo.position;

    passReg(); //Login Function

    system("cls");//Clears screen

    teaLogin(); //Teacher Login Function
}

//Student Info Input Function
void studInfoInp()
{
    line(); //Line function
    cout << "\t\tSCHOOL INFORMATION SYSTEM";
    line(); //Line function
    cout << "\n";

    cout << "Enter Details:\n\n";

    cout << "Enter Student ID Number: ";
    cin >> studentInfo.studIdNo;

    cout << "\n";

    cout << "Enter Last Name: ";
    cin >> studentInfo.lName;

    cout << "Enter First Name: ";
    cin >> studentInfo.fName;

    cout << "Enter Program: ";
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
    bool exitCondition = false;
    int menu = 0;

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

    while (!exitCondition)
    {
        switch (menu)
        {
        case 1:
            teaStuInf(); //Teachers's Student Info Function
            break;
        case 2:
            teaTeaInf(); //Teacher's Teacher Info Function
            break;
        case 3:

            break;
        case 4:
            TeaRep(); //Teacher's Reports Functions
            break;
        case 5:
            exitCondition = true; //Exits the program
            break;
        default:
            cout << " ERROR ";
        }
        cout << "\nThank you for using our application!\n\n";
        cout << "Program Ended\n";
    }
}

//Student Main Menu Screen
void StuMmScreen()
{
    bool exitCondition = false;
    int menu = 0;

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

            break;
        case 4:
            StuRep(); //Student's Reports Function
            break;
        case 5:
            exitCondition = true; //Exits the program
            break;
        default:
            cout << " ERROR ";
        }
        cout << "\nThank you for using our application!\n\n";
        cout << "Program Ended\n";
    }
}

//Teachers's Student Info Function
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
                
            cout << "Enter Student Information:\n";

            cout << " Enter Student ID Number: ";
            cin >> studentInfo.studIdNo;

            cout << "\n";

            cout << " Enter Last Name: ";
            cin >> studentInfo.lName;

            cout << " Enter First Name: ";
            cin >> studentInfo.fName;

            cout << " Enter Program: ";
            cin >> studentInfo.progEn;
                
            cout << "\n\nGo back? ";
            cin >> yesNo;

            if (yesNo == "yes")
            {
                goto back;
            }
                
            break;

        case 2:

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

//Students' Student Info Function
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

    line(); //Line function
    cout << "\t\tSCHOOL INFORMATION SYSTEM";
    line(); //Line function
    cout << "\n";

}

//Teacher's Reports Functions
void TeaRep()
{
    system("cls"); //Clears screen

    char choice = 0, finishy = 'y', finishn = 'e';

    line(); //Line function
    cout << "\t\tSCHOOL INFORMATION SYSTEM";
    line(); //Line function

    cout << " \n Student first and Last Name:"; cin >> studentInfo.fName; cout << ":"; cin >> studentInfo.lName;
    cout << "\tStudent ID:"; cin >> studentInfo.studIdNo;
    cout << "\n\n";
    cout << "Teacher First and Last Name:"; cin >> teacherInfo.fiName; cout << ":"; cin >> teacherInfo.laName;
    cout << "\tSignature:"; cin >> teacherInfo.sign;

    cout << "Date:";
    cin >> teacherInfo.Date;
    cout << "\n\n";
    cout << "Review student rate rarely/constantly/excellent/ bad/ good:\n";

    cout << " Does Working in class?   ";
    cin >> studentInfo.clas;
    cout << " \n\nDoes asking questions?    ";
    cin >> studentInfo.ask;
    cout << "\n\nGood at selflearning?    ";
    cin >> studentInfo.self;
    cout << "\n\nWhats the Progress at course?    ";
    cin >> studentInfo.progress;

again:
    cout << "y to Display it?\n";
    cout << "e to Exit Program?";
    cin >> choice;

    if (choice == finishy)
    {
        TeachDisplay();
        system("cls"); //Clears screenAA
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
    system("cls"); //Clears screenAA
    char choice = 0, exit = 'e', back = 'b';
    cout << " \n Student Name:" << studentInfo.fName << "Last Name:" << studentInfo.lName << "\tStudent ID:" << studentInfo.studIdNo << endl;
    cout << "\n\n";
    cout << "Teacher Name:" << teacherInfo.fiName << "Last Name:" << teacherInfo.laName << "\tSignature:" << teacherInfo.sign << endl;
    cout << "\nDate:" << teacherInfo.Date << endl;

    cout << " \n\nDoes Working in class |  Does asking questions |  Good at selflearning |  Whats the Progress at course? |" << endl;
    cout << studentInfo.clas << "               |   " << studentInfo.ask << "              |  " << studentInfo.self << "     |     " << studentInfo.progress << "           |    \n ";
redo:
    cout << "\n\n e for Exit?:";
    cout << "\nb for Back to Menu?";
    cin >> choice;

    if (choice == back)
    {
        TeaMmScreen(); // back to Menu for Admin or Teacher 
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

    line(); //Line function
    cout << "\t\tSCHOOL INFORMATION SYSTEM";
    line(); //Line function
    cout << "\n";
}
