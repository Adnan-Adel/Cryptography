#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
  int key;
  string input_file_path;
  string output_file_path;

  cout << "Enter encrypted text file path: ";
  cin >> input_file_path;
  cout << "Enter Decryption Key: ";
  cin >> key;

  string my_txt;
  ifstream encrypted_txt(input_file_path);

  if(!encrypted_txt.is_open())
  {
    cout << "ERROR!, Could not open the file!" << endl;
    exit(-1);
  }
  
  cout << "Enter name of output file: ";
  cin >> output_file_path;
  ofstream plain_txt(output_file_path);
  while(getline(encrypted_txt, my_txt))
  {
    // Cesar Cipher Decryption Algorithm
    for(char& c : my_txt)
    {
      if(int(c) >= 97 && int(c) <= 122)
      {
        // Decrypt lower case characters
        int val= c - 'a';
        val= (val - key + 26) % 26;
        c = 'a' + val;
      }
      else if(int(c) >= 65 && int(c) <= 90)
      {
        // Decrypt upper case characters
        int val= c - 'A';
        val= (val - key + 26) % 26;
        c = 'A' + val;
      }
      else if(int(c) >= 48 && int(c) <= 57)
      {
        // Decrypt digits
        int val= c - '0';
        val= (val - key + 10) % 10;
        c = '0' + val;
      }
      else
      {
        // Ignore special characters
      }
      plain_txt << c;
    }
  }

  // close file
  plain_txt.close();
  encrypted_txt.close();

  return 0;
}
