#include <iostream>
#include <string>
#include <modShifr.h>

void check(string Text, int key) {
    string cipherText;
    string decryptedText;
    modShifr cipher(key, Text);
    cipherText = cipher.encryption(Text);
    decryptedText = cipher.transcript(cipherText, Text);
    cout << "Ключ = " << key << endl;
    cout << Text << endl;
    cout << cipherText << endl;
    cout << decryptedText << endl;
}

int main() {
    try {
    //check("ProgrammingLanguages", 1);
    check("ProgrammingLanguages", 6);
    //check("приветжизнь", 4);
    //check("  ", 2);
    } catch(const cipher_error & e) {
        cerr << "Ошибка: " << e.what() << endl;
    }
    return 0;
}