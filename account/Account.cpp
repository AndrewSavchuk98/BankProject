//
// Created by student on 20.12.2024.
//

#include "Account.h"

#include <iomanip>

#include "../utils/DateUtil.h"
#include "../utils/UUID.h"

Account::Account() {

}

Account::Account(User applicant) {
    this->id = uuid::generate_uuid_v4();
    this->applicant = applicant;
    DateUtil date = DateUtil();
    this->date = date.getDate();
    this->status = "new";
}

User Account::getApplicant() {
    return applicant;
}

string Account::getDate() {
    return date;
}

string Account::getStatus() {
    return status;
}

string Account::getId() {
    return id;
}

void Account::setStatus(string status) {
    this->status = status;
}

void Account::show() {
    cout << "ID: " << id << endl;
    cout << "Status: " << status << endl;
    cout << "Date: " << date << endl;
    cout << "USER: " << applicant.getName() << endl;
}

nlohmann::json Account::toJson() {
    return nlohmann::json{
        {"id", id},
        {"applicant", applicant.toJson()},
        {"date", date},
        {"status", status}
    };
}

Account Account::fromJson(const nlohmann::json& json) {
    Account account;  // Create a new Account object

    // Deserialize the fields from JSON
    account.id = json["id"].get<int>();  // Assuming id is of type int
    User user;
    account.applicant = user.fromJson(json["applicant"]);
    account.date = json["date"].get<std::string>();  // Assuming date is a string
    account.status = json["status"].get<std::string>();  // Assuming status is a string

    return account;  // Return the populated Account object
}





