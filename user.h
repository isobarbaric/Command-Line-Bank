#include <string>
using namespace std;

class User {
    public:
        // username attribute
        string username;

        // constructor
        User(string username, string password) {
            this -> username = username;
            this -> password = password;
        }

        // delegate constructors later on
        User(string username, string password, unsigned balance) {
            this -> username = username;
            this -> password = password;
            this -> balance = balance;
        }

        // getters
        string getUsername();
        string getPassword();
        unsigned getBalance();

        // setters
        string changePassword(string revised_password);
        bool withdraw(unsigned withdrawal);
        bool deposit(unsigned deposit);

    private:
        // password attribute
        string password;

        // balance attribute
        unsigned balance;
};