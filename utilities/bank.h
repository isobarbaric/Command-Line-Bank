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
        }

        Bank(vector<User> account_holders) {
            customers = account_holders;
        }

        void simulate();

    private:

        vector<User> load_users();
        void login_portal();
        bool process_login(string username, string password);

        // methods to be implemented
        bool create_account();

};