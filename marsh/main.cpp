#include <iostream>
#include <cctype>
#include <string>
#include "encrypt.cpp"
#include "decrypt.cpp"

bool is_valid_columns(const std::string& input) {
    if (input.empty()) return false; // Пустое поле
    for (char c : input) {
        if (!isdigit(c)) return false; // Не число
    }
    return true; // Ввод валиден
}

int main() {
    std::string text;
    std::string columns_input;
    int columns;
    int choice;

    std::cout << "Выберите действие:\n1. Шифрование\n2. Расшифрование\n";
    std::cin >> choice;
    std::cin.ignore(); // Игнорируем символ новой строки после выбора

    std::cout << "Введите текст: ";
    std::getline(std::cin, text);

    // Проверка на пустой текст
    if (text.empty()) {
        std::cout << "Ошибка: текст не может быть пустым для шифрования/расшифрования.\n";
        return 1; // Завершаем программу с ошибкой
    }

    // Запрос количества столбцов с проверкой
    while (true) {
        std::cout << "Введите количество столбцов: ";
        std::getline(std::cin, columns_input);
        
        if (is_valid_columns(columns_input)) {
            columns = std::stoi(columns_input);
            if (columns > 0) break; // Убедимся, что количество столбцов положительное
            else std::cout << "Количество столбцов должно быть больше 0\n";
        } else {
            std::cout << "Ошибка: введите положительное целое число\n";
        }
    }

    if (choice == 1) {
        std::string encrypted_text = encrypt(text, columns);
        std::cout << "Зашифрованный текст: " << encrypted_text << std::endl;
    } else if (choice == 2) {
        std::string decrypted_text = decrypt(text, columns);
        std::cout << "Расшифрованный текст: " << decrypted_text << std::endl;
    } else {
        std::cout << "Неверный выбор действия\n";
    }

    return 0;
}
