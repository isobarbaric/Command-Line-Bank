#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "user.h"

using namespace std;

vector<User> account_holders;

// split by delimiters
User parse(string input_data) {
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

vector<User> read_data() {
    ifstream acc_db;
    acc_db.open("data.csv");
    vector<User> account_holders;
    string current_user;
    if (acc_db.is_open()) { // always check whether the file is open
        while(getline(acc_db, current_user)) {
            getline(acc_db, current_user);
            account_holders.push_back(parse(current_user));
        }
    }
    return account_holders;
}

bool login(string username, string password) {
    for (int i = 0; i < account_holders.size(); i++) {
        if (account_holders[i].username == username) {
            return account_holders[i].password == password;
        }
    }
    return false;
}

// methods to be implemented
bool create_account();

int main() {
    account_holders = read_data();

    // logging in
    while (true) {
        cout << "Welcome to the bank! Please login below or type EXIT to quit.\n";
        string user, pass;
        cout << "Enter username here: ";
        cin >> user;

        if (user == "EXIT") {
            return 0;
        }

        cout << "Enter password here: ";
        pass = "";
        char c;

        // set terminal to raw mode
        system("stty raw");

        bool firstTime = true;
        while ((c = getchar()) != 13) {
            if (firstTime) {
                firstTime = false;
                continue;
            }
            pass += c;
            cout << '*';
        }
        cout << '\n';

        // reset terminal to normal cooked mode
        system("stty cooked");

        // attempt to login
        if (login(user, pass)) {
            cout << "\n\n....Success!\n\n";
        } else {
            cout << "\n\nInvalid credentials. Try again.\n\n";
        }
    }

    // cout << login("nate_ellison", "abcd1234");

    return 0;
}