#include "bank.h"
#include <fstream>
using namespace std;

void Bank::simulate() {
    cout << "\n----------------------------------------------------------------\n";
    cout << "Welcome to the bank! Here are your options:\n- To create a new account, please type in 'n'.\n- To quit, please type in 'esc'.\n- To log in to your existing account, please press 'l'";
    cout << "\n----------------------------------------------------------------\n";

    bool goodInput = false;
    while (!goodInput) {
        string choice;
        cout << "Your choice: ";
        cin >> choice;
        if (choice[0] == 'n') {
            goodInput = true;
            create_account();
        } else if (choice == "esc") {
            return;
        } else if (choice[0] == 'l') {
            goodInput = true;
            login_portal();
        }
    }
}

bool Bank::create_account() {
    cout << "creating a new account";

    // temporarily returning true
    return true;
}

vector<User> Bank::load_users() {
    ifstream acc_db;
    acc_db.open("data.csv");
    vector<User> account_holders;
    string current_user;

    bool firstLine = true;
    if (acc_db.is_open()) { // always check whether the file is open
        while(getline(acc_db, current_user)) {
            if (firstLine) {
                firstLine = false;
                continue;
            }
            getline(acc_db, current_user);
            account_holders.push_back(User::parse(current_user));
        }
    }
    return account_holders;
}

bool Bank::process_login(string username, string password) {
    for (int i = 0; i < customers.size(); i++) {
        if (customers[i].username == username) {
            return customers[i].password == password;
        }
    }
    return false;
}

void Bank::login_portal() {
    bool goodInput = true;
    string user, pass;

    cout << "=> Enter username here: ";
    cin >> user;

    if (user == "EXIT") {
        return;
    }

    cout << "=> Enter password here: ";
    pass = "";

    // set terminal to raw mode
    system("stty raw");

    char c;
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
    if (process_login(user, pass)) {
        cout << "\n....Success!\n";
    } else {
        cout << "\nInvalid credentials. Try again.\n";
    }
}