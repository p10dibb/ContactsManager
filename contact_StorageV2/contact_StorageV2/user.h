
#include "contact.h"
#include "nodeTemplate.h"

using namespace::linke_list;
class user : public linked_list<contact> {

public:
	user();
	~user();

	int menu();//main menu

	void display_All();//prints out all contacts to screen
	void add_inOrder(node<contact>* n); //adds in order based on name "first Last" orientation

	string encrypt_password();
	string dycrypt_password();

	void setPassword(string p);
	void userSet_Password();
	string getPassword();
	node<contact>* Create_new_Contact();

	void setName(string n);
	string getName();


	int Login();

	void  clear_list();

private:
	string name;
	string password;


};

void display_everything(linked_list<user> h);

linked_list<user> load_all();