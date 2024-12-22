//
// Created by student on 15.12.2024.
//

#ifndef USER_H
#define USER_H

#include <iostream>
#include <nlohmann/json.hpp>

#include "utils/UUID.h"
#include "utils/DateUtil.h"

using namespace std;

class User {
private:
    string id;
    string name;
    string email;
    string phone;
    string userType; // admin, client
    string role;
    string password;
    string created;
public:

    User();

    User(string name, string email, string phone, string userType, string role);

    string getId();
    string getName();
    string getEmail();
    string getPhone();
    string getUserType();
    string getRole();
    string getPassword();

    void setId(string id);
    void setName(string name);
    void setEmail(string email);
    void setPhone(string phone);
    void setUserType(string userType);
    void setRole(string role);
    void setPassword(string password);

    // A method to convert this class instance to a nlohmann::json object
    nlohmann::json toJson() const;

    User fromJson(const nlohmann::json &json);
};



#endif //USER_H
