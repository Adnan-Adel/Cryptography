#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
  int key;
  string input_file_path;
  string output_file_path;

  cout << "Enter plain text file path: ";
  cin >> input_file_path;
  cout << "Enter Encryption Key: ";
  cin >> key;

  string my_txt;
  ifstream plain_txt(input_file_path);

  if(!plain_txt.is_open())
  {
    cout << "ERROR!, Could not open the file!" << endl;
    exit(-1);
  }
  
  cout << "Enter name of output file: ";
  cin >> output_file_path;
  ofstream encrypted_txt(output_file_path);
  while(getline(plain_txt, my_txt))
  {
    // Cesar Cipher Encryption Algorithm
    for(char& c : my_txt)
    {
      if(int(c) >= 97 && int(c) <= 122)
      {
        // Encrypt lower case characters
        int val= c - 'a';
        val= (val + key) % 26;
        c = 'a' + val;
        encrypted_txt << c;

      }
      else if(int(c) >= 65 && int(c) <= 90)
      {
        // Encrypt upper case characters
        int val= c - 'A';
        val= (val + key) % 26;
        c = 'A' + val;
        encrypted_txt << c;
      }
      else if(int(c) >= 48 && int(c) <= 57)
      {
        // Encrypt digits
        int val= c - '0';
        val= (val + key) % 10;
        c = '0' + val;
        encrypted_txt << c;
      }
      else
      {
        // Ignore special characters
        encrypted_txt << c;
      }
    }
  }

  // close file
  plain_txt.close();
  encrypted_txt.close();

  return 0;
}
