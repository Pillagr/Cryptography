#include "Binary.h"


string Binary::bin_to_str(string bin) {
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
string Binary::str_to_bin(string str) {
    string binary;
    for(int bit : str) {
        binary.append(dec_to_bin(bit));
    }
    return binary;
}
string Binary::dec_to_bin(int dec) {
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
int Binary::bin_to_dec(string bin) {
    int decimal = 0;
    for(int p = 0; p < 8; p++) {
        int place = pow(2, (7-p) );
        if(bin[p] == '1') {
            decimal += place;
        }
    }

    return decimal;
}
string Binary::encrypt(string message, string otp) {
    string plaintext = str_to_bin(message),
            onetimepad = str_to_bin(otp),
            ciphertext;
    for(int b = 0; b < plaintext.length(); b++) {
        int t = (plaintext[b] + onetimepad[b])%2;
        ciphertext.append(to_string(t));
    }
    return ciphertext;
}
string Binary::decrypt(string ciphertext, string otp) {
    string onetimepad = str_to_bin(otp),
            plainbinary,
            plaintext;
    for(int b = 0; b < ciphertext.length(); b++) {
        int t = (ciphertext[b] + onetimepad[b])%2;
        plainbinary.append(to_string(t));
    }
    plaintext = bin_to_str(plainbinary);
    return plaintext;
}