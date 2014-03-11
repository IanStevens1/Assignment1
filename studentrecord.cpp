#include "studentrecord.h"
//Autha: Ian Stevens
//Date:: 11/03/2014
namespace stvian004 {


	istream& operator>>(istream& is, StudentRecord & sr)
	{
		vector <string> tokens;
		string r;
		//getting the 1st 4 components and putting them into a vecto
		while(tokens.size() != 4){
			    getline(is, r, ',');
				tokens.push_back(r);
		}
		//setting the veribals for this student
		sr.Name=tokens[0];
		sr.Surname=tokens[1];
		sr.Snum=tokens[2];
		sr.CRecord=tokens[3];
		return is;
	}
	

	ostream& operator<<(ostream& os, const StudentRecord& sr)
	{
		//returning a toString as a string stream
		string tostring =sr.Name+","+sr.Surname+"," +sr.Snum +"," +sr.CRecord+",";
		os << tostring;
		return os;
	}

	//the group of specail functions
    StudentRecord::StudentRecord(string name, string sname, string Snum, string CRecord, int (t)): Name (name), Surname (sname), Snum (Snum), CRecord (CRecord), Token(t){}

    StudentRecord::StudentRecord( void ): Name("a"), Surname("b"), Snum("001"), CRecord("0 0 0"){}

    StudentRecord::StudentRecord(const StudentRecord &rhs): Name (rhs.Name), Surname (rhs.Surname), Snum (rhs.Snum), CRecord(rhs.CRecord), Token(rhs.Token){}

    StudentRecord::StudentRecord(StudentRecord && rhs): Name (move(rhs.Name)), Surname (move(rhs.Surname)), Snum (move(rhs.Snum)), CRecord((move(rhs.CRecord))),Token(move(rhs.Token)){}

    StudentRecord &StudentRecord::operator =(const StudentRecord & rhs)
    {
        if(this != &rhs)
        {
            Name = rhs.Name;
            Surname = rhs.Surname;
            Snum = rhs.Snum;
            CRecord = rhs.CRecord;
            Token = rhs.Token;
        }
        return *this;
    }
    //move assignment
    StudentRecord &StudentRecord::operator =(StudentRecord && rhs)
    {
        if(this != &rhs)
        {
            Name = move(rhs.Name);
            Surname = move(rhs.Surname);
            Snum = move(rhs.Snum);
            CRecord = move(rhs.CRecord);
            Token = rhs.Token;
        }
        return *this;
    }

    //destructor
    StudentRecord::~StudentRecord(){
		
	}
    //the getter and setters i needed to write my program
    void StudentRecord::setName(string x){
          Name = x;
    }
    int StudentRecord::getToken()
    {
		return Token;
	}
	void StudentRecord::setToken ( int tok )
    {
		Token = tok;
	}
    string StudentRecord::getName(){
          return Name;
    }
    string StudentRecord::getSnum(){
          return Snum;
    }
    string StudentRecord::toString(){
          return Name+","+Surname+","+Snum+","+CRecord+",";
    }
    string StudentRecord::getCRecord(){
           return CRecord;
    }

    string StudentRecord::getSurname( void)
    {
        return Surname;
    }

}
