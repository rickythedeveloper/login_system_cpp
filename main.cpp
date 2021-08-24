#include <iostream>
#include "User.h"

using std::cout;
using std::cin;
using std::endl;
using std::string;

string getUserInput(string question) {
	cout << question << ' ';
	string answer;
	std::getline(cin, answer);
	return answer;
}

string getUsername() {
	string username = getUserInput("Username:");
	if (User::isValidUsername(username)) return username;
	cout << "Invalid username. Try again." << endl;
	return getUsername();
}

string getPassword() {
	string password = getUserInput("Password:");
	if (!User::isValidPassword(password)) {
		cout << "Invalid password. Try again." << endl;
		return getPassword();
	}

	string passwordAgain = getUserInput("Confirm password:");
	if (password == passwordAgain) {
		return password;
	}
	else {
		cout << "Passwords did not match. Please try again." << endl;
		return getPassword();
	}
}

User signUpFlow() {
	string username = getUsername();
	string password = getPassword();
	return User(username, password);
}

int main() {
	User user = signUpFlow();
	cout << user.getUsername() << ' ' << user.getPassword() << endl;
	return 0;
}