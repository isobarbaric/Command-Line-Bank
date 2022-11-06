#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "user.h"
using namespace std;

// methods to be implemented
bool login(string username, string password);
bool create_account();

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
    fstream fin;
    fin.open("data.csv", ios::in);
    vector<User> account_holders;
    // while (getline(file, ID, ',')) {
        // cout << "ID: " << ID << " " ; 

        // getline(file, nome, ',') ;
        // cout << "User: " << nome << " " ;

        // getline(file, idade, ',') ;
        // cout << "Idade: " << idade << " "  ; 

        // getline(file, genero);
        // cout << "Sexo: " <<  genero<< " "  ;
        // account_holders.push_back(parse(idk))
    // }
    return account_holders;
}

int main() {
    // read_data();
    // User chad_raccoon("isobarbaric", "monkey");
    // cout << chad_raccoon.username;
    User test = parse("gracie_howard, 1234xyz, 530");
    cout << test.getPassword();
    // cout << test.username << " " << test.getPassword() << " " << test.getBalance();

    return 0;
}