#include "User.h"

User::User(string a, string b) {
	username = a;
	password = b;
}

string User::getUsername() { return username; }
string User::getPassword() { return password; }

const string alphabetLowercase = "abcdefghijklmnopqrstuvwxyz";
const string alphabetUppercase = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
const string numbers = "0123456789";

const string validUsernameChars = alphabetLowercase + alphabetUppercase + numbers;
bool User::isValidUsername(string username) {
	for (int i = 0; i < username.size(); i++) {
		if (validUsernameChars.find(username[i]) == string::npos) return false;
	}
	return true;
}

const string validPasswordChars = alphabetLowercase + alphabetUppercase + numbers;
bool User::isValidPassword(string password) {
	for (int i = 0; i < password.size(); i++) {
		if (validPasswordChars.find(password[i]) == string::npos) return false;
	}
	return true;
}