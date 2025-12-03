#include <iostream>
#include <random>
#include <string>

std::string generate(int length) {
    const std::string chars =
        "abcdefghijklmnopqrstuvwxyz"
        "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
        "0123456789"
        "!@#$%^&*()";

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dist(0, chars.size() - 1);

    std::string password;
    for (int i = 0; i < length; i++) {
        password += chars[dist(gen)];
    }
    return password;
}

int main() {
    while (true) {
        std::cout << "=============================\n";
        std::cout << "      PASSWORD GENERATOR\n";
        std::cout << "=============================\n";
        std::cout << "1. Generate password\n";
        std::cout << "2. Exit\n";
        std::cout << "Choose an option: ";

        int choice;
        std::cin >> choice;

        if (choice == 1) {
            int length;
            std::cout << "Enter password length: ";
            std::cin >> length;

            std::string password = generate(length);
            std::cout << "\nGenerated password: " << password << "\n\n";
        }
        else if (choice == 2) {
            std::cout << "Exiting...\n";
            break;
        }
        else {
            std::cout << "Invalid option!\n\n";
        }
    }
}
