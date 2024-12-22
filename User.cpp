//
// Created by student on 15.12.2024.
//

#include "User.h"
#include <nlohmann/json.hpp>

string User::getId() {
    return id;
}

string User::getName() {
    return name;
}

string User::getEmail() {
    return email;
}

string User::getPhone() {
    return phone;
}

string User::getRole() {
    return role;
}

string User::getUserType() {
    return userType;
}

void User::setId(string id) {
   this->id = id;
}

void User::setEmail(string email) {
    this->email = email;
}

void User::setName(string name) {
    this->name = name;
}

void User::setPhone(string phone) {
    this->phone = phone;
}

void User::setRole(string role) {
    this->role = role;
}
void User::setUserType(string userType) {
    this->userType = userType;
}
string User::getPassword() {
    return password;
}

void User::setPassword(string password) {
    this->password = password;
}

nlohmann::json User::toJson() const {
    return nlohmann::json{
        {"id",        id},
        {"name",      name},
        {"email",     email},
        {"phone",     phone},
        {"userType",  userType},
        {"role",      role},
        {"password",  password},
        {"created",   created}
    };
}

User User::fromJson(const nlohmann::json& json) {
    User user;  // Create a new User object

    // Deserialize the fields from JSON
    user.id = json["id"].get<int>();            // Assuming 'id' is an int
    user.name = json["name"].get<std::string>(); // Assuming 'name' is a string
    user.email = json["email"].get<std::string>(); // Assuming 'email' is a string
    user.phone = json["phone"].get<std::string>(); // Assuming 'phone' is a string
    user.userType = json["userType"].get<std::string>(); // Assuming 'userType' is a string
    user.role = json["role"].get<std::string>(); // Assuming 'role' is a string
    user.password = json["password"].get<std::string>(); // Assuming 'password' is a string
    user.created = json["created"].get<std::string>(); // Assuming 'created' is a string (could be a date)

    return user;  // Return the populated User object
}

User::User() {

}

User::User( string name, string email, string phone, string userType, string role) {
    this->id = uuid::generate_uuid_v4();
    this->name = name;
    this->email = email;
    this->phone = phone;
    this->userType = userType;
    this->role = role;
    DateUtil d = DateUtil();
    this->created = d.getDate();
}



