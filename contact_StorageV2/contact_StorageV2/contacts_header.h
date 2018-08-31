#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using namespace::std;
/*
a contavt storage program.

goals:
.create linked list template
.create a contact that is editable and has a vector style "contact info"
.to store a contacts list and make it accisable later
.add multiple users with password requirements to access
.add password encryption
.add admin option
.store users in an equally balanced BST


*/


//std::fstream & operator << (std::fstream &lhs, contact &rhs);
int main();


void appWrapper();



void parse_user_head(string s,string r[2]);
void parse_user_contact(string s, string r[5]);



