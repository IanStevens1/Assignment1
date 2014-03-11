//Autha: Ian Stevens
//Date:: 11/03/2014
#ifndef STUDENTRECORD_H
#define STUDENTRECORD_H
#include "counter.h"
#include <iostream>
#include <vector>
#include <sstream>
using namespace std;
namespace stvian004 {

    class StudentRecord : public sjp::counter<StudentRecord>
    {
    public:
		int getToken ( void );
        void setToken ( int );
        void setName(string);
        string getName( void );
        string getSurname( void );
        string getSnum( void );
        string getCRecord( void );
        string toString( void );


 
        StudentRecord(string name, string sname, string Snum, string CRecord, int t);
        //<<
		friend ostream& operator<<( ostream& os, const StudentRecord& sr);
        //>>
		friend istream& operator>>(istream& is, StudentRecord & sr);

        StudentRecord(void);

        StudentRecord(const StudentRecord & rhs);

        StudentRecord(StudentRecord && rhs);

        StudentRecord &operator =(const StudentRecord &rhs);

        StudentRecord &operator =(StudentRecord && rhs);

        ~StudentRecord();



    private:
        string Name;
        string Surname;
        string Snum;
        string CRecord;
        int Token;
    };
}
#endif // STUDENTRECORD_H
