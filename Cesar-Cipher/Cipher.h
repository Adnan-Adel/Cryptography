#ifndef CIPHER_H
#define CIPHER_H

#include <iostream>
#include <string>
#include <fstream>

class Cipher
{
private:
    int key;

    // Helper methods for encryption and decryption
    char encryptChar(char c);
    char decryptChar(char c);

public:
    Cipher(int key);
    void encryptFile(const std::string& input_file_path, const std::string& output_file_path);
    void decryptFile(const std::string& input_file_path, const std::string& output_file_path);

};

#endif // CIPHER_H

