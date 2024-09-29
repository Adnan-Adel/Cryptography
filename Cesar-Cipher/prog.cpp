#include <iostream>
#include "Cipher.h"

using namespace std;

int main()
{
    int key;
    string input_file_path, output_file_path;
    int choice;

    cout << "Enter the Encryption/Decryption Key: ";
    cin >> key;

    Cipher cipher(key);

    cout << "Choose an option: " << endl;
    cout << "1. Encrypt File" << endl;
    cout << "2. Decrypt File" << endl;
    cout << "Enter choice: ";
    cin >> choice;

    if (choice == 1)
    {
        cout << "Enter plain text file path: ";
        cin >> input_file_path;
        cout << "Enter name of output encrypted file: ";
        cin >> output_file_path;
        cipher.encryptFile(input_file_path, output_file_path);
        cout << "File encrypted successfully!" << endl;
    }
    else if (choice == 2)
    {
        cout << "Enter encrypted file path: ";
        cin >> input_file_path;
        cout << "Enter name of output plain text file: ";
        cin >> output_file_path;
        cipher.decryptFile(input_file_path, output_file_path);
        cout << "File decrypted successfully!" << endl;
    }
    else
    {
        cout << "Invalid option!" << endl;
    }

    return 0;
}

