//Autha: Ian Stevens
//Date:: 11/03/2014
#include "database.h"

namespace stvian004 {
	//adding student
    void DataBase::AddStudent(StudentRecord timmy)
    {
        myList.push_back(timmy);
    }
    
    void DataBase::DeleteStudent()
    {
		cout<<"enter the student number\n";
		string Snum;
		cin >> Snum;
		//looping through the list and erasing the right student
        for (std::list<StudentRecord>::iterator it = myList.begin(); it != myList.end(); it++){
			if(!Snum.compare(it->getSnum())){
				  tokenlib::release_token(it->getToken());
				  myList.erase(it);                        
			}
        }
    }
    
    void DataBase::readDataBase( void )
    {
		 
         ifstream in(fileName.c_str());
         istream& is = in;
         //checking to see if we are done with the string stream if we arent sending it to the >> loader
         while(!is.eof()){
				StudentRecord sr;
			    is >> sr;
			    sr.setToken(tokenlib::acquire_token());
			    AddStudent(sr);   
         }
         //getting ride of the last one
         tokenlib::release_token(myList.back().getToken());
		 myList.pop_back();
         in.close();
    }
    
    void DataBase::writeToDataBase( void )
    {
		ofstream myfile;
        myfile.open (fileName.c_str(), ios::trunc);
        //looping through my list and writing all the itterations to the file
        for (std::list<StudentRecord>::iterator it = myList.begin(); it != myList.end(); it++){
             myfile << *it;
        }
        myfile.close();
    }

	
    void DataBase::displayStudentData()
    {
		cout<<"enter the student number\n";
		string Snum;
		cin >> Snum;
		//looping through the list and printing the info
        for (std::list<StudentRecord>::iterator it = myList.begin(); it != myList.end(); it++){
			if(!Snum.compare(it->getSnum())){
				  cout<<it->toString();                        
			}
        }
    }

    void DataBase::gradeStudent()
    {
		cout<<"enter the student number\n";
		string Snum;
		cin >> Snum;
        int total=0;
        for (std::list<StudentRecord>::iterator it = myList.begin(); it != myList.end(); it++){
			if(!Snum.compare(it->getSnum())){
				 string CRecord;
				 CRecord=it->getCRecord();
				 istringstream grade(CRecord);
				 //looping throught the Class Record and adding all the marks to total
				 while(!grade.eof()){     
					   int grade1;     
					   grade>>grade1;
					   total=total+grade1;
				}                      
			}
        }
        cout<<"Ave: ";
        cout<<total/3+"\n";
    }
	//the same as gradeStudent but now we not looking for one student but printing them all out
    void DataBase::DisplayAllStudentData( void )
    {
        for (std::list<StudentRecord>::iterator it = myList.begin(); it != myList.end(); it++){
              int total=0;
              string CRecord;
              CRecord=it->getCRecord();
              istringstream grade(CRecord);
              while(!grade.eof()){     
                     int grade1;     
                     grade>>grade1;
                     total=total+grade1;
              }
              cout<< it-> getSnum();
              cout<<" ave ";
              cout<<total/3;
              cout<<"\n";                 
        }
    }

    void DataBase::FindWinningStudent( void )
    {
        int temp=0;
        string tempp;
        //looping through it and getting every ones grade the same way as gradStudent
        for (std::list<StudentRecord>::iterator it = myList.begin(); it != myList.end(); it++){
             int total=0;
             string CRecord;
             CRecord=it->getCRecord();
             istringstream grade(CRecord);
                             while(!grade.eof()){     
                                            int grade1;     
                                            grade>>grade1;
                                            total=total+grade1;
                             }
                             //checking to see if the current person is better and replace him at the top
                             if(temp<total){
                                    temp=total;
                                    tempp=it->getSnum();        
                             }                
                  }
                  cout<< tempp+"\n";
    }
	//6 specail functions
    DataBase::DataBase(string file_name) : fileName (file_name)  {}

    DataBase::DataBase( void ): fileName ("info.txt"){}

    DataBase::DataBase(const DataBase &rhs): fileName (rhs.fileName), myList (rhs.myList){}

    DataBase::DataBase(DataBase && rhs): fileName (move(rhs.fileName)), myList (move(rhs.myList)){}

    DataBase &DataBase::operator =(const DataBase & rhs)
    {
        if(this != &rhs)
        {
            fileName = rhs.fileName;
            myList = rhs.myList;
        }
        return *this;
    }

    DataBase &DataBase::operator =(DataBase && rhs)
    {
        if(this != &rhs)
        {
            fileName = move(rhs.fileName);
            myList = move(rhs.myList);
        }
        return *this;
    }


    DataBase::~DataBase(){
		while (!myList.empty())
		{
			tokenlib::release_token(myList.back().getToken());
			myList.pop_back();
			
		}
	}


}
