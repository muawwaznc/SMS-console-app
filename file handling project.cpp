#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <conio.h>
#include <sstream>
#include <string>
using namespace std;

// Prototypes
void main_header();
void user_option();
void join_society();
void society_profile();
void about_society();
void alumni();
void leave_society();
void head_login();
void head_option();
void list_of_candidate();
void approve_mem();
void priority_mem();
void list_of_members();
void list_of_heads();
void remove_mem();
void change_head();
void clr_scr();
void file_reading();
string seperate_record(string line, int entity);
void file_writing();
// Prototypes end

// variables and arrays
//  below are the variables for new members who want to join
string m_name[1000];
string m_fname[1000];
string m_dept[1000];
string m_password[1000];
float m_aggr[1000];

string sorted_m_name[1000];
string sorted_m_fname[1000];
string sorted_m_dept[1000];
string sorted_m_password[1000];
float sorted_m_aggr[1000];

// end

//  below are the variables used for name and dept. of approved members.
string member[1000];

string mem_dept[1000];

int mem_count = 0;

int appr_mem; // It is used to approve candidates.
// end

//  below are the variables for name and designation of heads.
string head[5];

string head_dept[5];
// end

//  below are the variables that are use in the block of remove head.
int head_no;
string head_name;
// end

//  below are the variables that are used in the block of leave member.
string remove_member, remove_dept;
// end

string leave_name;
string leave_password;
// it is used when a new member wants to leave;

char user = ' '; // it is used for recognizing the user

char opt; // it is used for entering option from the option menu for both user

string user_name, user_pass; // it is the ID and password of admin user
// ID = head & password = head

int join = 0; // this is used as a count variable for joining the society
// variables and arrays end

main()
{
    file_reading();
    while (user != 'q')
    {
        main_header();

        if (user == 'm')
        {
            while (opt != '6')
            {
                user_option();

                if (opt == '1')
                {
                    join_society();
                }
                else if (opt == '2')
                {
                    society_profile();
                }
                else if (opt == '3')
                {
                    about_society();
                }
                else if (opt == '4')
                {
                    alumni();
                }
                else if (opt == '5')
                {
                    leave_society();
                }
                else if (opt == '6')
                {
                    break;
                }
                else
                {
                    cout << "You enter an invalid option";
                    clr_scr();
                }
            }
        }

        else if (user == 'a')
        {
            head_login();
            if (user_name == "head" && user_pass == "head")
            {
                while (opt != '7')
                {
                    head_option();

                    if (opt == '1')
                    {
                        list_of_candidate();
                    }
                    else if (opt == '2')
                    {
                        priority_mem();
                    }
                    else if (opt == '3')
                    {
                        list_of_members();
                    }
                    else if (opt == '4')
                    {
                        list_of_heads();
                    }
                    else if (opt == '5')
                    {
                        remove_mem();
                    }
                    else if (opt == '6')
                    {
                        change_head();
                    }
                    else if (opt == '7')
                    {
                        break;
                    }
                    else
                    {
                        cout << "You choose an invalid option" << endl;

                        cout << endl
                             << endl;
                        cout << "Press any key to continue" << endl;
                        getche();
                    }
                }
            }
            else
            {
                cout << "You enter an invalid username or password" << endl;

                cout << endl
                     << endl;
                cout << "Press any key to continue" << endl;
                getche();
            }
        }

        else if (user == 'q')
        {
            system("CLS");
            cout << endl
                 << endl;
            cout << "Thanks for using our management system" << endl;
            file_writing();
            break;
        }

        else
        {
            cout << endl
                 << endl;
            cout << "You choose an invalid option" << endl;
        }
    }
}

void file_reading()
{
    fstream file;
    string line;
    file.open("candidate_record.txt", ios::in);
    for (join; !(file.eof()); join++)
    {
        getline(file, line);
        m_name[join] = seperate_record(line, 1);
        m_fname[join] = seperate_record(line, 2);
        m_dept[join] = seperate_record(line, 3);
        m_aggr[join] = stof(seperate_record(line, 4));
        m_password[join] = seperate_record(line, 5);
    }
    file.close();

    file.open("member_record.txt", ios::in);
    for (int i = 0; !(file.eof()); i++)
    {
        getline(file, line);
        member[i] = seperate_record(line, 1);
        mem_dept[i] = seperate_record(line, 2);
        mem_count = mem_count + 1;
    }
    file.close();

    file.open("heads_record.txt", ios::in);
    for (int i = 0; !(file.eof()); i++)
    {
        getline(file, line);
        head[i] = seperate_record(line, 1);
        head_dept[i] = seperate_record(line, 2);
    }
    file.close();
}

string seperate_record(string line, int entity_no)
{
    int comma_count = 1;
    string entity;
    for (int i = 0; i < line.length(); i++)
    {
        if (line[i] == ',')
        {
            comma_count = comma_count + 1;
        }
        else if (comma_count == entity_no)
        {
            entity = entity + line[i];
        }
    }
    return entity;
}

void main_header()
{
    system("CLS");
    cout << "*******************************************************" << endl;
    cout << "***                                                 ***" << endl;
    cout << "***            Society Management System            ***" << endl;
    cout << "***                                                 ***" << endl;
    cout << "*******************************************************" << endl;

    cout << "Press 'a' for admin" << endl;
    cout << "Press 'm' for member" << endl;
    cout << "Press 'q' for quit" << endl;
    user = getche();
}

void user_option()
{
    system("CLS");
    cout << "*******************************************************" << endl;
    cout << "***                                                 ***" << endl;
    cout << "***            Society Management System            ***" << endl;
    cout << "***            Member Login  >>  Options            ***" << endl;
    cout << "*******************************************************" << endl;

    cout << endl
         << endl;

    cout << "Select option" << endl;
    cout << "1.	Join society" << endl;
    cout << "2.	Society profile" << endl;
    cout << "3.	About society" << endl;
    cout << "4.	Alumni of society" << endl;
    cout << "5.	Leave society" << endl;
    cout << "6.      Quit" << endl;
    opt = getch();
}

void join_society()
{
    system("CLS");
    cout << "*******************************************************" << endl;
    cout << "***                                                 ***" << endl;
    cout << "***            Society Management System            ***" << endl;
    cout << "***         Member Login  >>>  Join Society         ***" << endl;
    cout << "*******************************************************" << endl;

    cout << endl
         << endl;

    if (join < 1000)
    {

        cout << "Enter your name: ";
        cin.ignore();
        getline(cin, m_name[join]);
        cout << "Enter your father name: ";
        cin.ignore();
        getline(cin, m_fname[join]);
        cout << "Enter your department: ";
        cin.ignore();
        getline(cin, m_dept[join]);
        cout << "Enter your aggrigate: ";
        cin >> m_aggr[join];
        cout << "Enter Password: ";
        cin.ignore();
        getline(cin, m_password[join]);
        join++;
    }

    clr_scr();
}

void society_profile()
{
    system("CLS");
    cout << "*******************************************************" << endl;
    cout << "***                                                 ***" << endl;
    cout << "***            Society Management System            ***" << endl;
    cout << "***        Member Login  >>  Society Profile        ***" << endl;
    cout << "*******************************************************" << endl;

    cout << endl
         << endl;

    cout << "Designation      \t \t \t        Name" << endl;

    cout << endl;

    cout << "President        \t \t \t        M. Ahmed" << endl;

    cout << "Vice president   \t \t \t        Uzma Ali" << endl;

    cout << "Secertory        \t \t \t        Hafsa" << endl;

    for (int i = 0; i < 5; i++)
    {
        cout << head_dept[i] << "\t \t \t        " << head[i] << endl;
    }
    clr_scr();
}

void about_society()
{
    system("CLS");
    cout << "*******************************************************" << endl;
    cout << "***                                                 ***" << endl;
    cout << "***            Society Management System            ***" << endl;
    cout << "***         Member Login  >>  About Society         ***" << endl;
    cout << "*******************************************************" << endl;

    cout << endl
         << endl;

    cout << "Introduction: " << endl;
    cout << "             It is the largest media society of UET-Lahore. It founded in. \n";
    cout << "2004. Its purpose is to educate new skills to the students and it posted   \n";
    cout << "all the news about UET on social media. " << endl;

    clr_scr();
}

void alumni()
{
    system("CLS");
    cout << "*******************************************************" << endl;
    cout << "***                                                 ***" << endl;
    cout << "***            Society Management System            ***" << endl;
    cout << "***      Member Login  >>>  Alumni of Society       ***" << endl;
    cout << "*******************************************************" << endl;

    cout << endl
         << endl;

    cout << "Asif Khokhar     (2020 - 21)  " << endl;
    cout << "Anum Mansoor     (2019 - 20)  " << endl;
    cout << "Adeel Ramzan     (2018 - 19)  " << endl;
    cout << "Tayyab Hameed    (2017 - 18)  " << endl;
    cout << "Asad Shehbaz     (2016 - 17)  " << endl;
    cout << "Salika Maryam    (2015 - 16)  " << endl;
    cout << "Rubeena Sajid    (2014 - 15)  " << endl;
    cout << "Adan Farroq      (2013 - 14)  " << endl;
    cout << "Fezan Ali        (2012 - 13)  " << endl;
    cout << "Hamza ch         (2011 - 12)  " << endl;
    cout << "Fatima Aslam     (2010 - 11)  " << endl;
    cout << "Umar Farooq      (2009 - 10)  " << endl;
    cout << "Hasseb Akmal     (2008 - 09)  " << endl;
    cout << "Maaz Saleem      (2007 - 08)  " << endl;
    cout << "Zoya Naveed      (2006 - 07)  " << endl;
    cout << "Asmaa Ali        (2005 - 06)  " << endl;
    cout << "Areej Fatima     (2004 - 05)  " << endl;

    clr_scr();
}

void leave_society()
{
    system("CLS");
    cout << "*******************************************************" << endl;
    cout << "***                                                 ***" << endl;
    cout << "***            Society Management System            ***" << endl;
    cout << "***        Member Login  >>>  Leave Society         ***" << endl;
    cout << "*******************************************************" << endl;

    cout << endl
         << endl;

    if (join > 0)
    {
        cout << "Enter your name: ";
        cin.ignore();
        getline(cin, leave_name);
        cout << "Enter Password: ";
        cin.ignore();
        getline(cin, leave_password);
        for (int i = 0; i < join; i++)
        {
            if (leave_name == m_name[i] && leave_password == m_password[i])
            {
                cout << m_name[i] << " removed";
                for (int j = i; j < join; j++)
                {
                    m_name[j] = m_name[j + 1];
                    m_fname[j] = m_fname[j + 1];
                    m_dept[j] = m_dept[j + 1];
                    m_aggr[j] = m_aggr[j + 1];
                    m_password[j] = m_password[j + 1];
                    if (j == join - 1)
                    {
                        m_name[j] = " ";
                        m_fname[j] = " ";
                        m_dept[j] = " ";
                        m_aggr[j] = 0;
                        m_password[j] = " ";
                    }
                    join = join - 1;
                }
            }
        }
    }
    else
    {
        cout << "You are not a member yet" << endl;
    }
    clr_scr();
}

void head_login()
{
    system("CLS");
    cout << "*******************************************************" << endl;
    cout << "***                                                 ***" << endl;
    cout << "***            Society Management System            ***" << endl;
    cout << "***                   Admin Login                   ***" << endl;
    cout << "*******************************************************" << endl;

    cout << endl
         << endl;

    cout << "Enter ID : ";
    cin >> user_name;

    cout << "Enter password : ";
    cin >> user_pass;
}

void head_option()
{
    system("CLS");
    cout << "*******************************************************" << endl;
    cout << "***                                                 ***" << endl;
    cout << "***            Society Management System            ***" << endl;
    cout << "***            Admin Login  >>>  Options            ***" << endl;
    cout << "*******************************************************" << endl;

    cout << endl
         << endl;
    cout << "Select option" << endl;
    cout << "1.	Approve candidates" << endl;
    cout << "2.      Candidates on the basis of priority" << endl;
    cout << "3.	List of members" << endl;
    cout << "4.	List of heads" << endl;
    cout << "5.	Remove member" << endl;
    cout << "6.      Change head" << endl;
    cout << "7.      Quit" << endl;
    opt = getch();
}

void list_of_candidate()
{
    system("CLS");
    cout << "*******************************************************" << endl;
    cout << "***                                                 ***" << endl;
    cout << "***            Society Management System            ***" << endl;
    cout << "***       Admin Login  >>  Approve Candidate        ***" << endl;
    cout << "*******************************************************" << endl;

    cout << endl
         << endl;

    if (join == 0)
    {
        cout << "There is no record yet. " << endl;
    }
    else if (join > 0)
    {
        cout << "Sr."
             << "   "
             << "Name"
             << "\t \t"
             << "Department"
             << "\t \t"
             << "Aggrigate" << endl
             << endl;
        for (int i = 0; i < join; i++)
        {
            cout << i + 1 << "-"
                 << "    " << m_name[i] << "\t \t" << m_dept[i] << "\t \t \t" << m_aggr[i] << endl;
        }
        cout << endl;
        approve_mem();
    }
    clr_scr();
}

void approve_mem()
{
    cout << "Enter the number of student: ";
    cin >> appr_mem;
    for (int i = 0; i <= appr_mem; i++)
    {
        if (i == appr_mem - 1)
        {
            member[mem_count] = m_name[i];
            mem_dept[mem_count] = m_dept[i];
            mem_count++;

            for (int j = i; j < join; j++)
            {
                m_name[j] = m_name[j + 1];
                m_fname[j] = m_fname[j + 1];
                m_dept[j] = m_dept[j + 1];
                m_aggr[j] = m_aggr[j + 1];
                m_password[join] = m_password[j + 1];
            }
            join = join - 1;
        }
    }
}

void priority_mem()
{
    system("CLS");
    cout << "*******************************************************" << endl;
    cout << "***                                                 ***" << endl;
    cout << "***            Society Management System            ***" << endl;
    cout << "***   Admin Login  >>  Priority List of candidate   ***" << endl;
    cout << "*******************************************************" << endl;

    cout << endl
         << endl;

    if (join == 0 || join == 1)
    {
        cout << "There is no record yet. ";
    }
    else if (join > 1)
    {
        for (int i = 0; i < join; i++)
        {
            sorted_m_name[i] = m_name[i];
            sorted_m_fname[i] = m_fname[i];
            sorted_m_dept[i] = m_dept[i];
            sorted_m_aggr[i] = m_aggr[i];
            sorted_m_password[i] = m_password[i];
        }
        for (int i = 0; i < join; i++)
        {
            for (int j = i + 1; j < join; j++)
            {
                if (sorted_m_aggr[i] < sorted_m_aggr[j])
                {
                    string temp_name, temp_dept;
                    float temp_aggr;

                    temp_name = sorted_m_name[j];
                    sorted_m_name[j] = sorted_m_name[i];
                    sorted_m_name[i] = temp_name;

                    temp_dept = sorted_m_dept[j];
                    sorted_m_dept[j] = sorted_m_dept[i];
                    sorted_m_dept[i] = temp_dept;

                    temp_aggr = sorted_m_aggr[j];
                    sorted_m_aggr[j] = sorted_m_aggr[i];
                    sorted_m_aggr[i] = temp_aggr;
                }
            }
        }
        cout << "Name"
             << "\t \t"
             << "Department"
             << "\t \t"
             << "Aggrigate" << endl
             << endl;
        for (int i = 0; i < join; i++)
        {
            cout << sorted_m_name[i] << "\t \t" << sorted_m_dept[i] << "\t \t \t" << sorted_m_aggr[i] << endl;
        }
    }

    clr_scr();
}

void list_of_members()
{
    system("CLS");
    cout << "*******************************************************" << endl;
    cout << "***                                                 ***" << endl;
    cout << "***            Society Management System            ***" << endl;
    cout << "***        Admin Login  >>>  List of members        ***" << endl;
    cout << "*******************************************************" << endl;

    cout << endl
         << endl;

    cout << "Name"
         << "\t \t \t"
         << "Department" << endl
         << endl;
    for (int i = 0; i < mem_count; i++)
    {
        cout << member[i] << "\t \t" << mem_dept[i] << endl;
    }

    clr_scr();
}

void list_of_heads()
{
    system("CLS");
    cout << "*******************************************************" << endl;
    cout << "***                                                 ***" << endl;
    cout << "***            Society Management System            ***" << endl;
    cout << "***         Admin Login  >>>  List of Heads         ***" << endl;
    cout << "*******************************************************" << endl;

    cout << endl
         << endl;

    cout << "Name          \t \t \t    designation" << endl;
    cout << endl;

    for (int i = 0; i < 5; i++)
    {
        cout << head[i] << "     \t \t \t    " << head_dept[i] << endl;
    }

    clr_scr();
}

void remove_mem()
{
    system("CLS");

    cout << "*******************************************************" << endl;
    cout << "***                                                 ***" << endl;
    cout << "***            Society Management System            ***" << endl;
    cout << "***         Admin Login  >>>  Remove Member         ***" << endl;
    cout << "*******************************************************" << endl;

    cout << endl
         << endl;

    cout << "Sr.  "
         << "Name      \t      Departmant" << endl;
    cout << endl;

    for (int i = 0; i < mem_count; i++)
    {
        cout << i + 1 << "-   " << member[i] << "\t \t \t" << mem_dept[i] << endl;
    }

    cout << endl;

    cout << "Enter the name: ";
    cin.ignore();
    getline(cin, remove_member);
    cout << "Enter his/her department: ";
    cin.ignore();
    getline(cin, remove_dept);

    for (int i = 0; i < mem_count; i++)
    {
        if (remove_member == member[i] && remove_dept == mem_dept[i])
        {
            cout << endl
                 << member[i] << " is removed.";

            for (int j = i; j < mem_count; j++)
            {
                member[j] = member[j + 1];
                mem_dept[j] = mem_dept[j + 1];
            }
            mem_count = mem_count - 1;
        }
    }

    clr_scr();
}

void change_head()
{
    system("CLS");

    cout << "*******************************************************" << endl;
    cout << "***                                                 ***" << endl;
    cout << "***            Society Management System            ***" << endl;
    cout << "***          Admin Login  >>>  Change Head          ***" << endl;
    cout << "*******************************************************" << endl;

    cout << endl
         << endl;

    for (int i = 0; i < 5; i++)
    {
        cout << i + 1 << "- " << head[i] << "     \t \t \t    " << head_dept[i] << endl;
    }

    cout << endl;

    cout << "Enter the index of head you want to change... ";
    cin >> head_no;
    if (head_no > 5 || head_no < 1)
    {
        cout << "Enter valid option...";
    }
    else
    {
        cout << "Enter the new head name: ";
        cin.ignore();
        getline(cin, head_name);

        for (int i = 0; i < 5; i++)
        {
            if (head_no == i + 1)
            {
                head[i] = head_name;
                cout << "the new " << head_dept[i] << " is " << head[i] << endl;
            }
        }
    }
    clr_scr();
}

void clr_scr()
{
    cout << endl
         << endl;
    cout << "Press any key to continue" << endl;
    getche();
}

void file_writing()
{
    fstream file;
    string comma = ",";
    file.open("candidate_record.txt", ios::out);
    for (int i = 0; i < join; i++)
    {
        file << m_name[i];
        file << comma;
        file << m_fname[i];
        file << comma;
        file << m_dept[i];
        file << comma;
        file << m_aggr[i];
        file << comma;
        file << m_password[i];
        if (i < join - 1)
        {
            file << endl;
        }
    }
    file.close();

    file.open("member_record.txt", ios::out);
    for (int i = 0; i < mem_count; i++)
    {
        file << member[i];
        file << comma;
        file << mem_dept[i];
        if (i < mem_count - 1)
        {
            file << endl;
        }
    }
    file.close();

    file.open("heads_record.txt", ios::out);
    for (int i = 0; i < 5; i++)
    {
        file << head[i];
        file << comma;
        file << head_dept[i];
        if (i < 4)
        {
            file << endl;
        }
    }
    file.close();
}