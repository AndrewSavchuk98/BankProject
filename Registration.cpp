//
// Created by student on 15.12.2024.
//

#include "Registration.h"

#include <fstream>

void Registration::registerUser(User user) {

    bool isValidEmail = validateEmail(user.getEmail());
    bool isPhoneValid = validatePhone(user.getPhone());
    if (isValidEmail && isPhoneValid) {
        saveToFile(user);
    }
    else
    {
        cout << "bad params" << endl;
    }
}

bool Registration::validateEmail(string email) {
    const regex pattern
       ("(\\w+)(\\.|_)?(\\w*)@(\\w+)(\\.(\\w+))+");
    return regex_match(email, pattern);
}

bool Registration::validatePhone(string phone) {
    if (phone.length() > 10) {
        return true;
    }
    return false;
}

void Registration::saveToFile(User user) {
    // Шлях до файлу з користувачами
    const std::string filePath = "../user.json";

    nlohmann::json data; // Тут зберігатимуться всі користувачі

    // 1. Спробуємо зчитати існуючий файл
    {
        std::ifstream inFile(filePath);
        if (inFile.is_open())
        {
            try
            {
                // Зчитуємо вміст у змінну data
                inFile >> data;
            }
            catch (const std::exception& e)
            {
                // Якщо при парсингу виникла помилка, виведемо повідомлення й ініціалізуємо порожній масив
                std::cerr << "Error parsing JSON file. Reason: " << e.what() << std::endl;
                data = nlohmann::json::array();
            }
            inFile.close();
        }
        else
        {
            // Якщо файл не відкрився, вважаємо, що його поки немає, й ініціалізуємо порожній масив
            data = nlohmann::json::array();
        }
    }

    // 2. Якщо зчитані дані не є масивом, ініціалізуємо порожній масив
    if (!data.is_array())
    {
        data = nlohmann::json::array();
    }

    // 3. Додаємо нового користувача в масив
    data.push_back(user.toJson());

    // 4. Записуємо оновлені дані у файл
    {
        std::ofstream outFile(filePath);
        if (outFile.is_open())
        {
            // Записуємо з відступами (pretty print)
            outFile << data.dump(4);
            outFile.close();
            std::cout << "User data appended to " << filePath << std::endl;
        }
        else
        {
            std::cerr << "Error opening file for writing: " << filePath << std::endl;
        }
    }
}
