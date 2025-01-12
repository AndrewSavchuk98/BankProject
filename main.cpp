#include <iostream>

#include "Registration.h"
#include "User.h"
#include "account/Account.h"
#include "bank/Bank.h"
#include <nlohmann/json.hpp>

using namespace std;

int main() {
    cout << "Hello"<<endl;

    cout << "Welcome to the Bank! " << endl;
    cout << "Choose what do you want to do \n1. Login\n2. Register ";
    int choice;
    cin >> choice;
   
    User* user;

    switch (choice) {
        case 1:
            //Todo create login
           // break;
        case 2:
            cout << "Enter your name: ";
            string name;
            cin >> name;

            cout << "Enter your email: ";
            string email;
            cin >> email;

            cout << "Enter your phone: ";
            string phone;
            cin >> phone;
            
            cout << "Enter your password: ";
            string password;
            cin >> password;

            while (true)
            {
          

                cout << "Enter Confirm password: ";
                string confpassword;
                cin >> confpassword;
                if (password == confpassword) {

                    user = new User(name, email, phone, "client", "admin");
                    user->setPassword(password);
                    Registration r;
                    r.registerUser(*user);

                    break;
                }
                else
                {
                    cout << "Try again confirm password" << endl;
                }
            }
            break;
    }

    Bank bank("Privates", "Kiev");

    Account* userAccount = new Account(*user);

    userAccount->show();
    bank.addAccount(userAccount);

    userAccount->addToBalance(200.0);
    userAccount->addToBalance(300.0);
    userAccount->addToBalance(-300.0);
    cout << "Balance: " << userAccount->getBalance() << endl;
    userAccount->minusFromBalance(250.0);
    userAccount->minusFromBalance(550.0);
    cout << "Balance: " << userAccount->getBalance() << endl;


    delete userAccount;
    delete user;


    return 0;
}
