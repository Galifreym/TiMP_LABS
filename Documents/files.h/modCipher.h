#pragma once
#include <vector>
#include <string>
#include <map>
/** @file
* @author Табаев Н.А.
* @version 2.0
* @date 28.05.2021
*/
using namespace std;
/** @brief Шифрование методом маршрутной перестановки
 * @details Ключ устанавливается конструктором
 * Для шифрования и расшифрования используется метод encryption и transcript.
 * @warning Реализация только для английского языка!
 * @warning Ключ только целое значение!
 */
class modCipher {
    // Описание класса
private:
    int key; ///< Ключ
    /** @brief Проверка ключа на валидность
    * @param [in] s - Ключ. Не должен быть пустым, должен быть целым значением
    *@param [in] Text - Открытый текст. Должен быть англоязычным.
    *@return Ключ, прошедший проверку
    * @throw cipher_error, если ключ пустой, если ключ содержит символы, не являющиеся целочисленными цифрами, если ключ превышает длину вводимого текста
    */
    inline int getValidKey(int key, const string & Text);
    /** @brief Проверка открытого текста на валидность
    * @param [in] s - открытый текст, должен содержать в себе только англоязычные символы.
    *@return Открытый текст, прошедший проверку
    * @throw cipher_error, если текст пустой, если текст содержит символы, не являющиеся англоязычными
    */
    inline string getValidOpenText(std::string & s);
    /** @brief Проверка зашифрованного текста на валидность
    * @param [in] s - зашифрованный текст, должен содержать в себе только англоязычные символы.
    * @param [in] open_text - открытый текст, должен содержать в себе только англоязычные символы.
    *@return Зашифрованный текст, прошедший проверку
    * @throw cipher_error, если текст пустой, если текст содержит некоректные символы, если текст неверно зашифрован
    */
    inline string getValidCipherText( std::string & s,  string & open_text);
public:
    modCipher() = delete;///< Запрет конструктора без параметров
    /** @brief Конструктор присваивания ключа
    * @param [in] skey - ключ
    * @param [in] text - открытый текст, требуется для проверки ключа в конструкторе на валидность
    * @details Установка ключа
    */
    modCipher(int skey, const string text);
    /**
    * @brief Зашифровывание
    * @param [in] text Открытый текст. Не должен быть пустой строкой,
    *@details При помощи двумерного массива происходит маршрутная перестановка ( считывание: слева-направо, сверху-вниз и запись: сверх-вниз, справа-налево)
    * @return Зашифрованная строка
    * @throw cipher_error, если текст пустой
    */
    string encryption(string text);
    /**
    * @brief Расшифрование
    * @param [in] text Зашифрованный текст. Должен быть символами английского алфавита
    * @details При помощи двумерного массива происходит маршрутная перестановка ( считывание: справа-налево, сверху-вниз и запись: сверху-вниз, слева-направо)
    * @return Расшифрованная строка
    * @throw cipher_error, если в тексте присутствуют посторонние символы.
    */
    string transcript(string text, string open_text);
};
/** @brief Класс-исключение
 * @details Производный класс от класса std::invalid_argument.
 * В данном классе перегружены конструкторы с параметрами. При перегрузке указан вызов конструктора базового класса с параметром.
 */
class cipher_error: public std::invalid_argument
{
public:
    explicit cipher_error (const std::string& what_arg):
        std::invalid_argument(what_arg) {} ///< Вызов конструктора базового класса с параметром
    explicit cipher_error (const char* what_arg):
        std::invalid_argument(what_arg) {} ///< Вызов конструктора базового класса с параметром
};