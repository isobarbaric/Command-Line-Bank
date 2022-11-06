#include "user.h"
#include <vector>
using namespace std;

// getters

// string User::getPassword() {
//     return password;
// }

// int User::getBalance() {
//     return balance;
// }

// setters

void User::changePassword(string revised_password) {
    password = revised_password;
}

bool User::withdraw(int withdrawal) {
    if (withdrawal > balance) {
        return false;
    }
    balance -= withdrawal;
    return true;
}

void User::deposit(int deposit) {
    balance += deposit;
}

// split by delimiters
User User::parse(string input_data) {
    vector<string> info;

    size_t pos = 0;
    string token;
    while ((pos = input_data.find(", ")) != std::string::npos) {
        token = input_data.substr(0, pos);
        info.push_back(token);
        input_data.erase(0, pos + 2);
    }
    info.push_back(input_data);

    int balance = atoi(info[2].c_str());
    return User(info[0], info[1], balance);
}
