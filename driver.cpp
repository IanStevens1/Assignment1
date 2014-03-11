//Autha: Ian Stevens
//Date:: 11/03/2014
#include <iostream>
#include <fstream>
#include "cmdline_parser.h"
#include "studentrecord.h"
#include "database.h"
#include "tokenlib.h"
using namespace stvian004;

void clear(void) { cout << string(100,'\n'); }

void AddStudent(DataBase &database)
{
	//gettting the students infomation
    cout<< "enter the students name\n";
    string name;
    cin>>name;
    cout<< "enter the students Surname\n";
    string Sname;
    cin>>Sname;
    cout<< "enter the students student number\n";
    string Snum;
    cin>>Snum;
    cout<< "enter the students class record\n";
    string CRecord;
    //getting the CRecord to work with the spaces 
    getline(cin, CRecord);
    getline(cin, CRecord);
    StudentRecord student(name, Sname, Snum, CRecord, tokenlib::acquire_token());
    //sending the student to be added to the database
    database.AddStudent(student);
}
//all the next methods are just calling a database class
void DeleteStudent(DataBase &database)
{
    database.DeleteStudent();

}

void ReadDatabase(DataBase &database)
{
    database.readDataBase();
}

void SaveDatabase(DataBase &database)
{
    database.writeToDataBase();
}

void displayStudentData(DataBase &database)
{
    database.DisplayAllStudentData();
}

void GradeStudent(DataBase &database)
{
    database.gradeStudent();

}

void DisplayAllStudentData(DataBase &database)
{
    database.DisplayAllStudentData();
}

void FindWinningStudent(DataBase &database)
{
    database.FindWinningStudent();
}


int main(int argc, char* argv[])
{
    using namespace std;
    {

		//getting the cmdline to accept a file name
        cmdline_parser parser;

        if(!parser.process_cmdline(argc, argv))
        {
            std::cerr << "Couldn't process command line arguments" << endl;
            return 1;
        }
        if(parser.should_print_help())
            { parser.print_help(std::cout);	}
        string file_name = parser.get_filename();
        cout << "Using file located at "+ file_name << endl;
        cout << "-----------------------------------------" << endl;
        //making a database with the file name you entered
        DataBase b(file_name);
        char i;
        //printing out the menu
		cout<< "1. add student \n2. delete given student \n3. read database\n4. save database\n5. display given student data\n6. grade student\n7.display all student data\n8. find winnning sudent\nq. quit\n";
		cin>> i;
		while(i!= 'q')
		{
			switch (i)
			{
				   case '1':
								   AddStudent(b);
								   break;
				   case '2':
								   DeleteStudent(b);
								   break;
				   case '3':
								   ReadDatabase(b);
								   break;
				   case '4':
								   SaveDatabase(b);
								   break;
				   case '5':
								   displayStudentData(b);
								   break;
				   case '6':
								   GradeStudent(b);
								   break;
				   case '7':
								   DisplayAllStudentData(b);
								   break;
				   case '8':
								   FindWinningStudent(b);
								   break;
			}
			cout<< "1. add student \n2. delete given student \n3. read database\n4. save database\n5. display given student data\n6. grade student\n7.display all student data\n8. find winnning sudent\nq. quit\n";
			cin>>i;
		}
	}
	StudentRecord::print_counts(std::cout, "StudentRecord");
	tokenlib::final_token_check();
	return 0;
}
