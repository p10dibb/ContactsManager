#include "user.h"


user::user() {
	password = "";
	name = "";

}
user::~user() {

}

void user::setPassword(string p) {

	this->password = p;

}

void user::userSet_Password() {
	int cont = 0, pos = 0;
	string pWord = "";

	while (cont != 2)
	{
		cout << "Please input your password. include at least one uppercase and one number." << endl;
		cin >> pWord;

		while (pos < pWord.length() && cont < 1) {
			if (pWord[pos] <= 90 && pWord[pos] >= 65) {
				cont++;
			}
			pos++;
		}
		pos = 0;
		while (pos < pWord.length() && cont < 2) {
			if (pWord[pos] >= 48 && pWord[pos] <= 57) {
				cont++;
			}
			pos++;
		}
		pos = 0;
		if (cont < 2) {
			cont = 0;
		}
	}


	this->setPassword(pWord);

}

string user::getPassword() {

	return password;

}

void user::setName(string n) {
	this->name = n;

}
string user::getName() {
	return name;

}


string user::encrypt_password() {
	string temp = "";
	temp = this->password;
	for (int i = 0; i < temp.length(); i++) {
		temp[i] = temp[i] - 5;
	}

	return temp;
}
string user::dycrypt_password() {
	string temp = "";
	for (int i = 0; i < temp.length(); i++) {
		temp[i] = temp[i] + 5;
	}

	return temp;

}



int user::Login() {
	string input = "";

	while (input != this->getPassword()) {
		cout << "hit -1 to exit\n" << this->getName() << ", please enter your password" << endl;
		cin >> input;
		if (input == "-1") {
			return 0;
		}
		if (input != this->getPassword()) {
			cout << "incorect password";
		}
	}
	cout << "Password Correct" << endl;
	this->menu();

	return 0;
}



void user::add_inOrder(node<contact>* n) {

	node<contact> *pNew = nullptr;
	node<contact> *pCur = nullptr;
	node<contact> *pTemp = nullptr;

	pNew = new(node<contact>);
	
	pNew->setData(n->getData());

	pCur = this->pTop;



	if (pNew != nullptr) {
		if (pCur != nullptr) {

			while (pCur->getPNext() != nullptr&& pNew->getData()>pCur->getPNext()->getData()) {
				pCur = pCur->getPNext();

			}

			//pTemp = pCur->getPNext();

			if (pCur->getData() > pNew->getData()) {
				pNew->setPNext(pCur);
				pTop = pNew;
			}
			else {
				pNew->setPNext(pCur->getPNext());
				pCur->setPNext(pNew);
			}
		}
		else {
			pTop = pNew;
		}
	}



}



void user::display_All() {
	node<contact> *pCur = nullptr;

	pCur = pTop;

	while (pCur != nullptr) {
		cout << pCur->getData();
		pCur = pCur->getPNext();
		cout << "--------------------------------------" << endl;
	}
}


node<contact>* user::Create_new_Contact() {

	node<contact> *pNew = nullptr;

	contact newContact;

	newContact.set_All();

	return this->makeNode(newContact);


}



int user::menu() {
	int choice = -1;

	cout << "1.Display All" << endl;
	cout << "2.Add contact" << endl;
	cout << "0.Exit" << endl;

	//while (choice < 0 || choice > 4) {

		while (choice != 0){
		cin >> choice;

		switch (choice) 
		{
		case 0:
			cout << "Exiting..." << endl;
			break;
		case 1:
			this->display_All();
			break;
		case 2:
			this->add_inOrder(this->Create_new_Contact());
			break;
		default:
			cout << "Not a valid choice" << endl;

		}

	}
	return choice;
}

//awfully made
void  user::clear_list() {

	this->pTop = nullptr;

}