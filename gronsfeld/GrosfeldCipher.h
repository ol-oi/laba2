#ifndef GROSFELD_CIPHER_H
#define GROSFELD_CIPHER_H

#include <string>

class GrosfeldCipher {
public:
    GrosfeldCipher(const std::string& key);
    std::string encrypt(const std::string& text);
    std::string decrypt(const std::string& text);
    bool isValidKey(const std::string& key) const; // Метод для проверки ключа

private:
    std::string key;
    const std::string alphabet = "АБВГДЕЁЖЗИЙКЛМНОПРСТУФХЦЧШЩЪЫЬЭЮЯ"; // Русский алфавит
    int getKeyCharIndex(char c);
};

#endif // GROSFELD_CIPHER_H
