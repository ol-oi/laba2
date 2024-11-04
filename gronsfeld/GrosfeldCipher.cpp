#include "GrosfeldCipher.h"
#include <cctype>

GrosfeldCipher::GrosfeldCipher(const std::string& key) : key(key) {}

int GrosfeldCipher::getKeyCharIndex(char c) {
    return alphabet.find(c);
}

bool GrosfeldCipher::isValidKey(const std::string& key) const {
    for (char c : key) {
        if (!isupper(c) || alphabet.find(c) == std::string::npos) { // Проверка на заглавные русские буквы
            return false;
        }
    }
    return true;
}

std::string GrosfeldCipher::encrypt(const std::string& text) {
    std::string encryptedText;
    int keyLength = key.length();
    int keyIndex = 0;

    for (char c : text) {
        if (isalpha(c) && isupper(c)) {
            int shift = getKeyCharIndex(key[keyIndex % keyLength]);
            int originalIndex = alphabet.find(c);
            int newIndex = (originalIndex + shift) % alphabet.length();
            encryptedText += alphabet[newIndex];
            keyIndex++;
        } else {
            encryptedText += c; // Не изменяем символы, которые не являются буквами
        }
    }

    return encryptedText;
}

std::string GrosfeldCipher::decrypt(const std::string& text) {
    std::string decryptedText;
    int keyLength = key.length();
    int keyIndex = 0;

    for (char c : text) {
        if (isalpha(c) && isupper(c)) {
            int shift = getKeyCharIndex(key[keyIndex % keyLength]);
            int originalIndex = alphabet.find(c);
            int newIndex = (originalIndex - shift + alphabet.length()) % alphabet.length();
            decryptedText += alphabet[newIndex];
            keyIndex++;
        } else {
            decryptedText += c; // Не изменяем символы, которые не являются буквами
        }
    }

    return decryptedText;
}
