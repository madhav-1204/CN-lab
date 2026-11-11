// data encryption and data decryption

#include <iostream>
#include <string>
using namespace std;

int main()
{
    string plain, cipher, key;
    int kl;

    cout << "Enter plain text: ";
    getline(cin, plain);

    cout << "Enter the encryption key: ";
    getline(cin, key);

    kl = key.length();

    // Encryption
    for (int i = 0; i < plain.length(); i++)
        cipher += plain[i] ^ kl;

    cout << "Encrypted text is: " << cipher << endl;

    // Decryption
    plain = "";

    for (int i = 0; i < cipher.length(); i++)
        plain += cipher[i] ^ kl;

    cout << "Decrypted text is: " << plain << endl;

    return 0;
}


// Enter plain text: HELLO
// Enter the encryption key: ABC