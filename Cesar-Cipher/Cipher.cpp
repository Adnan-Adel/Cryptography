#include "Cipher.h"

Cipher::Cipher(int key)
{
    this->key = key;
}

char Cipher::encryptChar(char c)
{
    if (c >= 'a' && c <= 'z')
    {
        return 'a' + (c - 'a' + key) % 26;
    }
    else if (c >= 'A' && c <= 'Z')
    {
        return 'A' + (c - 'A' + key) % 26;
    }
    else if (c >= '0' && c <= '9')
    {
        return '0' + (c - '0' + key) % 10;
    }
    else
    {
        return c;  // Special characters remain unchanged
    }
}

char Cipher::decryptChar(char c)
{
    if (c >= 'a' && c <= 'z')
    {
        return 'a' + (c - 'a' - key + 26) % 26;
    }
    else if (c >= 'A' && c <= 'Z')
    {
        return 'A' + (c - 'A' - key + 26) % 26;
    }
    else if (c >= '0' && c <= '9')
    {
        return '0' + (c - '0' - key + 10) % 10;
    }
    else
    {
        return c;  // Special characters remain unchanged
    }
}

void Cipher::encryptFile(const std::string& input_file_path, const std::string& output_file_path)
{
    std::ifstream plain_txt(input_file_path);
    if (!plain_txt.is_open())
    {
        std::cerr << "ERROR! Could not open the file!" << std::endl;
        exit(-1);
    }

    std::ofstream encrypted_txt(output_file_path);
    std::string line;
    while (getline(plain_txt, line))
    {
        for (char& c : line)
        {
            encrypted_txt << encryptChar(c);
        }
        encrypted_txt << std::endl;
    }

    plain_txt.close();
    encrypted_txt.close();
}

void Cipher::decryptFile(const std::string& input_file_path, const std::string& output_file_path)
{
    std::ifstream encrypted_txt(input_file_path);
    if (!encrypted_txt.is_open())
    {
        std::cerr << "ERROR! Could not open the file!" << std::endl;
        exit(-1);
    }

    std::ofstream plain_txt(output_file_path);
    std::string line;
    while (getline(encrypted_txt, line))
    {
        for (char& c : line)
        {
            plain_txt << decryptChar(c);
        }
        plain_txt << std::endl;
    }

    encrypted_txt.close();
    plain_txt.close();
}

