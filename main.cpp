#include <iostream>
#include <fstream>
#include <string>
#include <user.h>
using namespace std;

struct User {
    string username{}, password{};
    int balance{};
};

// void read_data() {
//     fstream fin, out;
//     fin.open("data.csv", ios::in);
//     if (file.)
// }

int main() {
    // User chad_raccoon = {.username = "isobarbaric", .password = "monkey", .balance = 34};

    User chad_raccoon = {
        .username = "isobarbaric",
        .password = "monkey",
        .balance = 34
    };

    return 0;
}