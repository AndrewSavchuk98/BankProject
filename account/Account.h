//
// Created by student on 20.12.2024.
//

#ifndef ACCOUNT_H
#define ACCOUNT_H
#include "../User.h"
#include <iostream>
#include "nlohmann/json.hpp"

using namespace std;

class Account {
private:
    string id;
    User applicant;
    string date;
    string status;
    double balance = 0;

public:
    Account();

    Account(User applicant);

    string getId();

    string getStatus();

    void setStatus(string status);

    string getDate();

    User getApplicant();

    void show();

    nlohmann::json toJson();

    // getBalance  // return balance

    double getBalance();
    
    void addToBalance(double amount);

    void minusFromBalance(double amount);
    // void addToBalance(double amount)
    // Додавати до  balance
    //

    // void minusFromBalance(double amount) 
    // Віднімати від balance, але баланс не може бути меншим 0

};


#endif //ACCOUNT_H
