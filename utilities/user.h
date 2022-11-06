#include <string>
using namespace std;

// make password and balance private attributes eventually
class User {
    // private:
    //     // password attribute
    //     string password;

    //     // balance attribute
    //     int balance;

    public:
        // username attribute
        string username;

        // password attribute
        string password;

        // balance attribute
        int balance;

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
        // string getPassword();
        // int getBalance();

        // setters
        void changePassword(string revised_password);
        bool withdraw(int withdrawal);
        void deposit(int deposit);

        // other
        static User parse(string input_data);
};