#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <algorithm>
#include "User.h"
#include "json.hpp"

using std::cout;
using std::cin;
using std::endl;
using std::string;
using nlohmann::json;

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

User signUp() {
	string username = getUsername();
	string password = getPassword();
	return User(username, password);
}

int signIn(User* users, int userCount) {
	string username = getUserInput("username: ");
	string password = getUserInput("password: ");

	for (int i = 0; i < userCount; i++) {
		User user = users[i];
		if (user.getUsername() == username && user.getPassword() == password) return i;
	}

	cout << "Incorrect username or password. Try again." << endl;;
	return signIn(users, userCount);
}

json readJsonFile(string filepath) {
	std::ifstream in(filepath);
	json j;
	in >> j;
	return j;
}

User* getUsers(int* userCount) {
	json jsonData = readJsonFile("data.json");
	json usersJson = jsonData.at("users");
	const int length = usersJson.size();
	*userCount = length;

	User* users = (User*)malloc(length * sizeof(User));
	for (int i = 0; i < length; i++) {
		users[i] = User(usersJson[i].at("username"), usersJson[i].at("password"));
	}
	return users;
}

int main() {
	int userCount;
	User* users = getUsers(&userCount);

	cout << "Choose option" << endl << "1: Sign in" << endl << "2: Sign up" << endl;
	string option = getUserInput("Option: ");
	if (option == "1") {
		int userIndex = signIn(users, userCount);
		User user = users[userIndex];
		cout << "Signed in to account with" << endl << "username: " << user.getUsername() << endl << "password: " << user.getPassword() << endl;
	}
	else if (option == "2") {
		User newUser = signUp();
		cout << "New user created with" << endl << "username: " << newUser.getUsername() << endl << "password: " << newUser.getPassword() << endl;
	}
	else {
		cout << "Invalid option. Try again.";
	}

	return 0;
}