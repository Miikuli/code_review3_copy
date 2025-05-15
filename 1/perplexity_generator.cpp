#include <iostream>
#include <string>
#include <random>
#include <ctime>

std::string generatePassword(int length, int level) {
    const std::string lower = "abcdefghijklmnopqrstuvwxyz";
    const std::string upper = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    const std::string digits = "0123456789";
    const std::string symbols = "!@#$%^&*()-_=+[]{}|;:,.<>?";

    std::string chars;
    if (level == 1) {
        chars = lower;
    } else if (level == 2) {
        chars = lower + upper + digits;
    } else if (level == 3) {
        chars = lower + upper + digits + symbols;
    } else {
        return "";
    }

    std::string password;
    std::mt19937 rng(static_cast<unsigned int>(std::time(nullptr)));
    std::uniform_int_distribution<> dist(0, chars.size() - 1);

    for (int i = 0; i < length; ++i) {
        password += chars[dist(rng)];
    }

    return password;
}

int main() {
    int level;
    int length;

    std::cout << "Выберите уровень сложности пароля (1 - низкий, 2 - средний, 3 - высокий): ";
    std::cin >> level;

    std::cout << "Введите длину пароля: ";
    std::cin >> length;

    std::string password = generatePassword(length, level);
    std::cout << "Сгенерированный пароль: " << password << std::endl;

    return 0;
}
