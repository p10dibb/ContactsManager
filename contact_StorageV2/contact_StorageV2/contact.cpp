#include "contact.h"


contact::contact() {
	first_Name = "";
	Last_Name = "";
	relation = "";
	phone_number = "";
	email = "";


}

contact::~contact() {

}

void contact::userSet_LastName() {

	string input = "";

	cout << "input Last Name:";
	cin >> input;

	if (input[0] >= 97 && input[0] <= 122) {
		input[0] = input[0] - 32;
	}

	this->set_LastName(input);

}

void contact::userSet_firstName() {
	string input = "";

	cout << "input First Name:";
	cin >> input;
	if (input[0] >= 97 && input[0] <= 122) {
		input[0] = input[0] - 32;
	}

	this->set_firstName(input);
}

void contact::userSet_relation() {

	string input = "";

	cout << "input relationship with the :";
	cin >> input;

	this->set_relation(input);
}

void contact::userSet_phoneNumber() {
	string input = "";


	while (input.length() != 10) {
		cout << "input Phone number:";
		cin >> input;
	}


//	puts phone number xxx-xxx-xxxx format
	for (int i = 0; i < 3; i++) {
		phone_number = phone_number + input[i];
	}
	phone_number = phone_number + '-';
	for (int i = 3; i < 6; i++) {
		phone_number = phone_number + input[i];
	}
	phone_number = phone_number + '-';
	for (int i = 6; i < 10; i++) {
		phone_number = phone_number + input[i];
	}


}

void contact::userSet_email() {
	string input = "";
	int done = -1;



	while (done != 1) {
		cout << "input Email:";
		cin >> input;

		done = -1;

	//	checks if it contains '@'
		for (int i = 0; i < input.length() - 1; i++) {
			if (input[i] == '@') {
				done++;
			}
		}

		//checks for '.com' at the end

		 //truth statement if the email ends with ".com" , ".edu" , or ".gov"
		bool com = input[input.length() - 1] == 'm' && input[input.length() - 2] == 'o'&&input[input.length() - 3] == 'c'&& input[input.length() - 4] == '.';
		bool edu = input[input.length() - 1] == 'u' && input[input.length() - 2] == 'd'&&input[input.length() - 3] == 'e'&& input[input.length() - 4] == '.';
		bool gov = input[input.length() - 1] == 'v' && input[input.length() - 2] == 'o'&&input[input.length() - 3] == 'g'&& input[input.length() - 4] == '.';

		//if the email has ".com", ".edu", or ".gov" then it knows it is a valid email
		if (com || edu || gov) {
			done++;

		}

	}
	email = input;

}


//not done 
void contact::addInfo() {}


string contact::get_LastName() {
	return Last_Name;
}

string contact::get_firstName() {
	return first_Name;
}

string contact::get_relation() {
	return relation;
}

string contact::get_phoneNumber() {
	return phone_number;
}

string contact::get_email() {
	return email;


}

void contact::set_All() {
	this->userSet_firstName();
	this->userSet_LastName();
	this->userSet_relation();
	this->userSet_phoneNumber();
	this->userSet_email();

}

void contact::set_LastName(string a) {
	this->Last_Name = a;
}

void contact::set_firstName(string a) {
	this->first_Name = a;
}

void contact::set_relation(string a) {
	this->relation = a;
}

void contact::set_phoneNumber(string a) {
	this->phone_number = a;
}

void contact::set_email(string a) {
	this->email = a;
}

bool  operator == (contact &lhs, contact &rhs) {
	string l = lhs.get_firstName() + lhs.get_LastName();
	string r = rhs.get_firstName() + rhs.get_LastName();


	return l == r;

}

bool  operator < (contact &lhs, contact &rhs) {
	string l = lhs.get_firstName() + lhs.get_LastName();
	string r = rhs.get_firstName() + rhs.get_LastName();


	return l < r;

}

bool  operator > (contact &lhs, contact &rhs) {
	string l = lhs.get_firstName() + lhs.get_LastName();
	string r = rhs.get_firstName() + rhs.get_LastName();


	return l > r;

}


std::ostream & operator << (std::ostream &lhs, contact &rhs) {
	cout << rhs.get_firstName() << " " << rhs.get_LastName() << endl;
	cout << rhs.get_relation() << endl;
	cout << rhs.get_phoneNumber() << endl;
	cout << rhs.get_email() << endl;
	return lhs;
}

//first name, last name, relation, phone number, email
std::fstream & operator << (std::fstream &lhs, contact &rhs) {
	lhs << rhs.get_firstName() << "," << rhs.get_LastName() << "," << rhs.get_relation() << "," << rhs.get_phoneNumber() << "," << rhs.get_email();
	return lhs;

}

std::fstream & operator >> (std::fstream &lhs, contact &rhs) {
	string info = "";



	getline(lhs, info, ',');
	rhs.set_firstName(info);
	getline(lhs, info, ',');
	rhs.set_LastName(info);
	getline(lhs, info, ',');
	rhs.set_relation(info);
	getline(lhs, info, ',');
	rhs.set_phoneNumber(info);
	getline(lhs, info, '\n');
	rhs.set_email(info);




	return lhs;

}

//bool  operator == (contact &lhs, contact &rhs) {
//	string l = lhs.get_firstName() + lhs.get_LastName();
//	string r = rhs.get_firstName() + rhs.get_LastName();
//
//
//	return l == r;
//
//}

