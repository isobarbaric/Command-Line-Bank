#include "user.h"

// getters

// string User::getPassword() {
//     return password;
// }

// int User::getBalance() {
//     return balance;
// }

// setters

string User::changePassword(string revised_password) {
    password = revised_password;
}

bool User::withdraw(int withdrawal) {
    if (withdrawal > balance) {
        return false;
    }
    balance -= withdrawal;
    return true;
}

bool User::deposit(int deposit) {
    balance += deposit;
}
