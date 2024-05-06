#include<bits/stdc++.h>
using namespace std;

string decode(string cipher, int key)
{
    for(int i = 0; i < cipher.size(); i++){
        cipher[i] = (cipher[i] - 'a' - key + 26) % 26 + 'a';
    }
    return cipher;
}

string encode(string plainText, int key)
{
    for(int i = 0; i < plainText.size(); i++) {
        plainText[i] = (plainText[i] - 'a' + key) % 26 + 'a';
    }
    return plainText;
}

int main()
{
    string cipher;
    cipher = "odroboewscdrolocdcwkbdmyxdbkmdzvkdpybwyeddrobo";
    for(int i = 1; i < 26 ; i++){
        cout << "Key = " << i << " Decoded Text: " << decode(cipher, i) << endl;
    }
    
    // Here key 10 will give the correct plain text
    string plainText = decode(cipher, 10);
    cout << "Decoded Text - " << plainText << endl;
    // Encoding with key 10 the plain text will give the cipher text back
    cout << "Encoded Text - " << encode(plainText, 10) << endl;
    return 0;
}
