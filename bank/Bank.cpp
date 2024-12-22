//
// Created by student on 20.12.2024.
//

#include "Bank.h"


vector<Account*> Bank::getAccounts() {
    ifstream accountsFile(filename);
    nlohmann::json accountsJson;

    if (accountsFile.is_open()) {
        accountsJson = nlohmann::json::parse(accountsFile);
    }
    vector<Account*> accounts;
    for (int i = 0; i < accountsJson.size(); i++) {
        Account* account = new Account();
        account->fromJson(accountsJson[i]);
        accounts.push_back(account);
    }
    return accounts;
}

string Bank::getAddress() {
    return address;
}


string Bank::getName() {
    return name;
}

Bank::Bank(string name, string address) {
    this->name = name;
    this->address = address;
}

string Bank::getId() {
    return id;
}

void Bank::addAccount(Account *account) {

    nlohmann::json data;

    ifstream file(filename);
    if (file.is_open()) {
        file >> data;
        file.close();
    } else {
        data = nlohmann::json::array();
    }

    data.push_back(account->toJson());

    ofstream outfile(filename);
    if (outfile.is_open()) {
        outfile <<  data;
        outfile.close();
    }
}

void Bank::showAccounts() {
    for (int i = 0; i < accounts.size(); i++) {
        accounts[i]->show();
        cout << "*********************************" << endl;
    }
}


// Написати функцію, яка приймає ім'я і віддає тільки Акаунти Користувача з цим ім'ям
void Bank::showFilteredAccounts(string name) {
    for (int i = 0; i < accounts.size(); i++) {
        if (accounts[i]->getApplicant().getName() == name) {
            accounts[i]->show();
            cout << "*********************************" << endl;
        }
    }
}


void Bank::showFilteredAccountsByStatus(string status) {
    for (int i = 0; i < accounts.size(); i++) {
        if (accounts[i]->getStatus() == status) {
            accounts[i]->show();
            cout << "*********************************" << endl;
        }
    }

}
