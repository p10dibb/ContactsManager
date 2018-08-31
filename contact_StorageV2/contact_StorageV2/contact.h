#include "contacts_header.h"


class contact {
public:
	contact();
	~contact();


	//prompts user for input
	void set_All();
	void userSet_LastName();
	void userSet_firstName();
	void userSet_relation();
	void userSet_phoneNumber();
	void userSet_email();
	void addInfo();


	void set_LastName(string a);
	void set_firstName(string a);
	void set_relation(string a);
	void set_phoneNumber(string a);
	void set_email(string a);

	string get_LastName();
	string get_firstName();
	string get_relation();
	string get_phoneNumber();
	string get_email();



private:



	string first_Name;
	string Last_Name;
	string relation;
	string phone_number;
	string email;
	//	vector<string> other_info;


};




std::ostream & operator << (std::ostream &lhs, contact &rhs);
std::fstream & operator << (std::fstream &lhs, contact &rhs);
std::fstream & operator >> (std::fstream &lhs, contact &rhs);



bool  operator == (contact &lhs, contact &rhs);
bool  operator < (contact &lhs, contact &rhs);
bool operator > (contact &lhs, contact &rhs);