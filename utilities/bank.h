#include <iostream>
#include <string>
#include <vector>
#include "user.h"
using namespace std;

class Bank {

    public:
        vector<User> customers;

        // constructor
        Bank() {
            customers = load_users();
            // cout << "len(customers) = " << customers.size() << '\n';
        }

        void simulate();

    private:
        vector<User> load_users();
        void login_portal();
        bool process_login(string username, string password);

        // methods to be implemented
        bool create_account();
        void add_user(string username, string password, int balance);

};