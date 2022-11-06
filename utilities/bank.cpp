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

void Bank::add_user(string username, string password, int balance) {
    // add to vector of customers
    customers.push_back(User(username, password, balance));

    // write to csv file
    ofstream acc_db;
    acc_db.open("utilities/data.csv", std::ios_base::app);
    acc_db << "\n" << username << ", " << password << ", " << balance;
    acc_db.close();
}

bool Bank::create_account() {
    cout << "Creating a new account for you:\n";
    string a, b;

    while (true) {
        cout << "=> Enter your desired username: ";
        cin >> a;
        bool username_taken = false;

        // verify username doesn't exist already
        for (int i = 0; i < customers.size(); i++) {
            if (customers[i].username == a) {
                username_taken = true;
            }
        }

        if (username_taken) {
            cout << "This username belongs to another user. Please choose another username.\n";
            continue;
        }

        cout << "=> Enter your desired password: ";

        // set terminal to raw mode
        system("stty raw");

        char c;
        bool firstTime = true;
        while ((c = getchar()) != 13) {
            if (firstTime) {
                firstTime = false;
                continue;
            }
            b += c;
            cout << '*';
        }
        cout << '\n';

        // reset terminal to normal cooked mode
        system("stty cooked");

        char deposit_choice;
        cout << "\n=> Would you like to deposit any money into your account right now? Press Y/y for yes and N/n for no.\n";
        cin >> deposit_choice; // introduce error checking for invalid input

        int balance = 0;
        if (deposit_choice == 'Y' || deposit_choice == 'y') {
            cout << "=> How much money would you like to deposit in your account? ";
            cin >> balance;
        }

        add_user(a, b, balance);

        // success method
        cout << "\n....Success! Thank you for choosing us!\n";

        break;
    }

    // temporarily returning true
    return true;
}

vector<User> Bank::load_users() {
    ifstream acc_db;
    acc_db.open("utilities/data.csv");
    vector<User> account_holders;
    string current_user;
    getline(acc_db, current_user);
    string previous_user;
    while(current_user.length() > 0) {
        previous_user = current_user;
        getline(acc_db, current_user);
        if (previous_user == current_user) {
            break;
        }
        account_holders.push_back(User::parse(current_user));
    }
    acc_db.close();
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