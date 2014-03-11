#ifndef DATABASE_H
#define DATABASE_H
#include <fstream>
#include <iostream>
#include <sstream>
#include "studentrecord.h"
#include "tokenlib.h"
#include <list>
#include <iterator>
#include <string>
//Autha: Ian Stevens
//Date:: 11/03/2014
#include <vector>
namespace stvian004 {
using namespace std;
class DataBase
{
 public:
    void writeToDataBase( void );
    void readDataBase( void );
    void AddStudent(StudentRecord);
    void DeleteStudent();
    void displayStudentData( );
    void gradeStudent(  );
    void DisplayAllStudentData( void );
    void FindWinningStudent(void);

	//6 specail functions

    DataBase(string file_name);

    DataBase(void);

    DataBase(const DataBase & rhs);

    DataBase(DataBase && rhs);

    DataBase &operator =(const DataBase &rhs);

    DataBase &operator =(DataBase && rhs);

    ~DataBase();

    private:
        string fileName;
        list<StudentRecord> myList;
    };
}
#endif // DATABASE_H
