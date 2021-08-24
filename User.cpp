#include "User.h"

User::User(string a, string b) {
	username = a;
	password = b;
}

string User::getUsername() { return username; }
string User::getPassword() { return password; }

const int invalidUsernameCharCount = 1;
const char invalidUsernameChars[invalidUsernameCharCount] = { ' ' };
bool User::isValidUsername(string username) {
	for (int i = 0; i < invalidUsernameCharCount; i++) {
		if (username.find(invalidUsernameChars[i]) != string::npos) return false;
	}
	return true;
}

const int invalidPasswordCharCount = 1;
const char invalidPasswordChars[invalidPasswordCharCount] = { ' ' };
bool User::isValidPassword(string password) {
	for (int i = 0; i < invalidPasswordCharCount; i++) {
		if (password.find(invalidPasswordChars[i]) != string::npos) return false;
	}
	return true;
}