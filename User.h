#include <iostream>

using std::string;

class User {
private:
	string username;
	string password;

public:
	User(string username, string password);
	string getUsername();
	string getPassword();
	static bool isValidUsername(string username);
	static bool isValidPassword(string password);
};