#include <iostream>
#include <string>
#include <cmath>

using namespace std; 

#ifndef BINARY_H
#define BINARY_H

class Binary {


public:
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

};

#endif