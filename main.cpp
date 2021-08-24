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

json readJsonFile(string filepath) {
	std::ifstream in(filepath);
	json j;
	in >> j;
	return j;
}

User* getUsers(int* userCount) {
	json jsonData = readJsonFile("test.json");
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

	// User user = signUp();
	// cout << user.getUsername() << ' ' << user.getPassword() << endl;
	return 0;
}