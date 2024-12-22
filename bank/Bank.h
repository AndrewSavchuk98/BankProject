//
// Created by student on 20.12.2024.
//

#ifndef BANK_H
#define BANK_H
#include <iostream>
#include <vector>
#include <fstream>

#include "../account/Account.h"


using namespace std;
class Bank {
private:
    string id;
    string name;
    string address;
    vector<Account*> accounts;
    const string filename = "../accounts.json";
public:
    Bank(string name, string address);

    string getId();
    string getName();
    string getAddress();

    vector<Account*> getAccounts();
    void addAccount(Account *account);
    void showAccounts();

    void showFilteredAccounts(string name);

    void showFilteredAccountsByStatus(string status);

};



#endif //BANK_H
