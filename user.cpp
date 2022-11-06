#include "user.h"

// getters

string User::getUsername() {
    return username;
}

string User::getPassword() {
    return password;
}

unsigned User::getBalance() {
    return balance;
}

// setters

string User::changePassword(string revised_password) {
    password = revised_password;
}

bool User::withdraw(unsigned withdrawal) {
    if (withdrawal > balance) {
        return false;
    }
    balance -= withdrawal;
    return true;
}

bool User::deposit(unsigned deposit) {
    balance += deposit;
}
