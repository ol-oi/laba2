#include <iostream>
#include <string>
#include "GrosfeldCipher.h"

using namespace std;

int main() {
    string key;
    string text;
    char choice;

    cout << "Выберите действие:\n";
    cout << "1 - Зашифровать текст\n";
    cout << "2 - Расшифровать текст\n";
    cout << "Введите ваш выбор (1 или 2): ";
    cin >> choice;
    cin.ignore(); // Очищаем буфер ввода

    cout << "Введите ключ (только заглавные буквы русского алфавита): ";
    getline(cin, key);

    GrosfeldCipher cipher(key);

    if (!cipher.isValidKey(key)) {
        cout << "Ключ должен содержать только заглавные буквы русского алфавита." << endl;
        return 1; // Завершение программы с ошибкой
    }

    cout << "Введите текст: ";
    getline(cin, text);

    if (choice == '1') {
        string encryptedText = cipher.encrypt(text);
        cout << "Зашифрованный текст: " << encryptedText << endl;
    } 
    else if (choice == '2') {
        string decryptedText = cipher.decrypt(text);
        cout << "Расшифрованный текст: " << decryptedText << endl;
    } 
    else {
        cout << "Неверный выбор." << endl;
    }

    return 0;
}
