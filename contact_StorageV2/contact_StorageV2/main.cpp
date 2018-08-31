#include "user.h"

int main() {

	appWrapper();



}
//in proggress
//make a temporary user using temp as well as make functions that parse and return header and body stuff then make it so the temp gets added to the array of users
void appWrapper() {
	linked_list<user> list;
	int i = 1,choice=-1;
	node<user> *pCur;

	list=load_all();

	pCur = list.get_pTop();

	if (pCur != nullptr) {
		cout << "who are you?" << endl;
		while (pCur != nullptr) {
			cout << i<<". ";
			i++;
			cout << pCur->getData().getName() << endl;
			pCur = pCur->getPNext();

		}
	}
	i--;

	//gets input of who u are until it is a valid
	while (choice<1 || choice>i) {
		cin >> choice;
	}
	pCur = list.get_pTop();


	for (int j = 0; j < choice-1; j++) {
		pCur = pCur->getPNext();
	}
	pCur->getData().Login();

}

void display_everything(linked_list<user> h) {

	node<user> *pCur;

	pCur = h.get_pTop();

	if (pCur != nullptr) {

		while (pCur != nullptr) {
	
			cout << "user: " << pCur->getData().getName() << endl;
			pCur->getData().display_All();

			pCur = pCur->getPNext();
		}
	}

}


void parse_user_head(string s,string r[2]) {

	int length = s.length();
	string name = "", password = "";
	int count = 0;
	string ret[2];


	for (int i = 1; i < length; i++) {
		if (s[i] != ',') {
			if (count == 0) {
				name = name + s[i];
			}
			else {
				password = password + s[i];
			}
		}
		else {
			count++;
		}
	}
	
	r[0] = name;
	r[1] = password;



}



//$Ryan,Ngo,friend,626-720-3022,ryanyngo@gmail.com
void parse_user_contact(string s,string r[5]) {
	string ret[5] = { "","","","","" };
	int count = 0;
	int length = s.length();

	for (int i = 1; i < length; i++) {
		if (s[i] != ',') {
			
				ret[count]=ret[count] + s[i];
		
			
			
		}
		else {
			count++;
		}
	}
	


	for (int i = 0; i < 5; i++) {
		r[i] = ret[i];

}


}


linked_list<user> load_all() {

	fstream infile;
	string input = "";
	linked_list<user> all;
	node<user> *temp;
	string temp_head[2] = { "" }, temp_contact[5] = { "" };
	user set;
	contact setter;
	node<contact> temp_node;

	infile.open("read.csv");




	while (!infile.eof()) {

		getline(infile, input, '\n');

		if (input[0] == '-') {
			temp = new(node<user>);


			temp->setData(set); 
			all.add_at_end(temp);
			set.clear_list();
		}

		//make a temporary user using temp as well as make functions that parse and return header and body stuff then make it so the temp gets added to the array of users
		else if (input[0] == '!') {

			parse_user_head(input, temp_head);


			set.setName(temp_head[0]);
			set.setPassword(temp_head[1]);


		}


		//		$Timmy, Turner, odd, 111 - 222 - 3333, oddParent@gmail.com

		else if (input[0] == '$') {
			parse_user_contact(input, temp_contact);

			setter.set_firstName(temp_contact[0]);
			setter.set_LastName(temp_contact[1]);
			setter.set_relation(temp_contact[2]);
			setter.set_phoneNumber(temp_contact[3]);
			setter.set_email(temp_contact[4]);

			temp_node.setData(setter);
			set.add_inOrder(&temp_node);
		}

	}

	return all;

}