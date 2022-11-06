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
            this -> balance = 0;
        }

        // delegate constructors later on
        User(string username, string password, int balance) {
            this -> username = username;
            this -> password = password;
            this -> balance = balance;
        }

        // getters (getUsername not necessary as it is public)
        string getPassword();
        int getBalance();

        // setters
        string changePassword(string revised_password);
        bool withdraw(int withdrawal);
        bool deposit(int deposit);

    private:
        // password attribute
        string password;

        // balance attribute
        int balance;
};