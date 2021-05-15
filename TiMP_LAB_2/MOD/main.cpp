#include <iostream>
#include <cctype>
#include <locale>
#include "modAlphaCipher.h"

using namespace std;

void check(const string& Text, const string& key, const bool destructCipherText=false) {
    try {
        string cipherText;
        string decryptedText;
        modAlphaCipher cipher(key);
        cipherText = cipher.encrypt(Text);
        if (destructCipherText)
            cipherText[1] += 32;
        decryptedText = cipher.decrypt(cipherText);
        cout << "Ключ = " << key << endl;
        cout << Text << endl;
        cout << cipherText << endl;
        cout << decryptedText << endl;
    } catch (const cipher_error &e) {
        cerr << "Ошибка: " << e.what() << endl;
    }
}

int main() {
    check("АВАДАКЕДАВРА", "КЛЮЧ");
    check("АВАДАКЕДАВРА", "Ключ");
    check("АВАДАКЕДАВРА", "");
    check("АВАДАКЕДАВРА", "Клю4");
    check("Авада кедавра", "КЛЮЧ");
    check("123", "КЛЮЧ");
    check("АВАДАКЕДАВРА", "КЛЮЧ", true);
    return 0;
}
