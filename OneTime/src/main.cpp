#include <iostream>
#include <string>
#include <cmath>
#include <fstream>
//#include "Binary.h"

using namespace std;

//bin_to_str - transforms a binary string into a plaintext string
//@param - string bin is a binary string
//@return string plaintext decoding of bin
string bin_to_str(string bin);

 //str_to_bin - transforms a plaintext string into a binary string
//@param - string str is a plaintext string
//@return string binary encoding of str
string str_to_bin(string str);

 //dec_to_bin - transforms a decimal int into a binary string
//@param - int dec is an int in decimal notation
//@return string binary encoding of dec
string dec_to_bin(int dec);

 //bin_to_dec - transforms a binary string into a decimal int
//@param - string bin is an binary string
//@return int decimal decoding of bin
int bin_to_dec(string bin);

 //encrypt - uses str_to_bin on message and otp, then adds the result, mod(2), and returns binary string
//@param - string message is a plaintext message. otp is the cipher used to encode message
//@return string binary encoding of message
string encrypt(string message, string otp);

 //decrypt - subtracts the binary of otp from ciphertext to get binary of original message, then uses bin_to_str to decode
//@param - string ciphertext is a binary. otp is the plaintext cipher used to encode message
//@return string original message
string decrypt(string ciphertext, string otp);

string double_encrypt(string message, string key1, string key2);
string double_decrypt(string message, string key1, string key2);

string encrypt_cpb(string I_URL, string O_URL, int block_size, string initial_v, string key);
string decrypt_cpb(string I_URL, string O_URL, int block_size, string initial_v, string key);

void run();

/* ************* */
int main( int argc, const char * argv[]) {
    string init_v = "Disenfranchiseds",
            key =   "GeorgetownSoccer",
            message = "Hellohellohello1",
            a = "Hi my name is Sachin\nI am a student at georgetown\nblah blah blah blah blah blah\nblah blah blah blah blah blahblah blah blah blah";
    //cout << key.length() << ' ' << init_v.length();
    encrypt_cpb("file2.txt", "file3.txt", 16, init_v, key);
    decrypt_cpb("file3.txt", "file4.txt", 16, init_v, key);
    return 0;
}

/* *************** */

string bin_to_str(string bin) {
    int count = 0;
    string str,
            result;
    for(int bit : bin) {
        bit -=48; //ASCII numbers for ints begin at 48
        str.append(to_string(bit));
        count++;

        if(count%8 == 0) {
            char ch = bin_to_dec(str);
            result.insert( result.end() , (char)bin_to_dec(str) );
            str.clear();
        }
    }
    cout << endl;
    return result;
}
string str_to_bin(string str) {
    string binary;
    for(int bit : str) {
        binary.append(dec_to_bin(bit));
    }
    return binary;
}
string dec_to_bin(int dec) {
    string binary;
    for(int p = 0; p < 8; p++) {
        int place = pow(2, (7-p) );
        if (dec >= place) {
            binary.append("1");
            dec -= place;
        }
        else {
            binary.append("0");
        }
    }
    return binary;
    
}
int bin_to_dec(string bin) {
    int decimal = 0;
    for(int p = 0; p < 8; p++) {
        int place = pow(2, (7-p) );
        if(bin[p] == '1') {
            decimal += place;
        }
    }

    return decimal;
}
string encrypt(string message, string otp) {
    string onetimepad = str_to_bin(otp),
            ciphertext;
    for(int b = 0; b < message.length(); b++) { //XOR operation 
        int t = (message[b] + onetimepad[b])%2;
        ciphertext.append(to_string(t));
    }
    return ciphertext;
}
string decrypt(string ciphertext, string otp) {
    string onetimepad = str_to_bin(otp),
            plainbinary,
            plaintext;
    for(int b = 0; b < ciphertext.length(); b++) {
        int t = (ciphertext[b] + onetimepad[b])%2;
        plainbinary.append(to_string(t));
    }
    //plaintext = bin_to_str(plainbinary);
    return plainbinary;
}
void encrypt_r() {
    string msg, otp;
    cout << "Please type your full message, end with \"^\" (Will not be included):\n";
    cin.get();
    getline(cin, msg, '^');
    cout << "Please type your OTP cipher, end with \"^\" (It must be the exact same length as the message):\n";
    cin.get();
    getline(cin, otp, '^');
    if(msg.length() == otp.length()) {
        cout << "Begin Message:\n" << encrypt(str_to_bin(msg), otp) << "\n--EOF--\n" << endl;
    }
    else {
        cout << "Message and Cipher lengths do not match. Please try again!" << endl;
        encrypt_r();
    }
}
void decrypt_r() {
    string msg, otp;
    cout << "Please type the full ciphertext, end with \"^\" (Will not be included):\n";
    cin.get();
    getline(cin, msg, '^');
    cout << "Please type your OTP cipher, end with \"^\" (It must be the exact same length as the message):\n";
    cin.get();
    getline(cin, otp, '^');
    if(msg.length()/8 == otp.length()) {
        cout << "Begin Message:" << bin_to_str(decrypt(msg, otp)) << "\n--EOF--\n" << endl;
    }
    else {
        cout << "Message and Cipher lengths do not match. Please try again!\n" << endl;
    }
}


string double_encrypt(string message, string key1, string key2) {
    string ciphertext;
    ciphertext = encrypt(message, key1);
    ciphertext = encrypt(ciphertext, key2);
    return ciphertext;
}
string double_decrypt(string message, string key1, string key2) {
    string plaintext;
    plaintext = decrypt(message, key2);
    plaintext = decrypt(plaintext, key1);
    return plaintext;
}

//Cipher Block Chaining: encrypt plaintxt w init_v then with key. 
string encrypt_cpb(string I_URL, string O_URL, int block_size, string initial_v, string key) {
    fstream fp;
    string result;
    string temp;

    fp.open(I_URL);
    if(fp) {
        char *block = new char[block_size];
        while( fp.read(block, block_size) ) {
            temp = encrypt(str_to_bin(block), initial_v); //XOR with initial_v
            temp = encrypt(temp, key); //XOR with Key
            result.append(temp);
            initial_v = bin_to_str(temp); //next init_v
            if(fp.peek() == '^') break;
        }
    }
    else {
        cout << "I-file not opened" << endl;
        exit(EXIT_FAILURE);
    }
    fp.close();
 // //   Write to file
    fp.open(O_URL);
    if(fp) {
        //fp.write((char*)&result, sizeof(result));
        fp << result;
    }
    else {
        cout << "O-file not opened" << endl;
        exit(EXIT_FAILURE);
    }
    fp.close();

    return result;
}
string decrypt_cpb(string I_URL, string O_URL, int block_size, string initial_v, string key) {
    fstream fp;
    string result,
            ciphertext,
            temp;
    int count = 0;
    fp.open(I_URL);
    if(fp) {
        char *block = new char[block_size*8];
        while( fp.read(block, block_size*8) ) {
            
            temp = decrypt(block, key); // decode with key
            temp = decrypt(temp, initial_v); //decode with init_v (previous ciphertext after 1st)
            result.append(temp);
            initial_v = bin_to_str(block); //set block as next init_v
            count++;
            if(fp.peek() == '^') break;
        }
    }
    else {
        cout << "I-file not opened" << endl;
        exit(EXIT_FAILURE);
    }
    fp.close();
// //   Write to file
    fp.open(O_URL);
    if(fp) {
        //fp.write((char*)&result, sizeof(result));
        fp << bin_to_str(result);
    }
    else {
        cout << "O-file not opened" << endl;
        exit(EXIT_FAILURE);
    }
    fp.close();


    cout << "\n" << count << endl;
    return bin_to_str(result);
}

void run() {
    char ch;
    cout << "\nHello! Welcome to the OneTimePad Encryptor.\nWould you like to encrypt or decrypt a message?    E / D\n";
    cin >> ch;
    if(ch == 'E' || ch == 'e') {
        encrypt_r();
    }
    else if(ch == 'D' || ch == 'd'){
        decrypt_r();  
    }
    else {
        cout << "Error: Please type either \'E\' or \'D\' to Encrypt or Decrypt a message.\n";
        run();
    }
    cout << "Would you like to Encrypt or Decrypt another message?   Y / N\n";
    cin >> ch;
    if(ch == 'Y' || ch == 'y') {
        run();
    }
    else exit(EXIT_SUCCESS);
}