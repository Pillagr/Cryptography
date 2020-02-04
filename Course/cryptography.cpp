#include <iostream>
#include <string>
#include <cmath>
#include <fstream>
#include <vector>

using namespace std;

/** bin_to_str - transforms a binary string into a plaintext string
 * @param bin is a binary string
 * @return string plaintext decoding of bin
 */
string bin_to_str(string bin);
/** str_to_bin - transforms a plaintext string into a binary string
 * @param str is a plaintext string
 * @return string binary encoding of str
 */ 
string str_to_bin(string str);
/** dec_to_bin - transforms a decimal int into a binary string
 * @param dec is an int in decimal notation
 * @return string binary encoding of dec
 */
string dec_to_bin(int dec);

/** bin_to_dec - transforms a binary string into a decimal int
 * @param bin is an binary string
 * @return int decimal decoding of bin
 */
int bin_to_dec(string bin);

//Utility functions
/** mod implements mod with only positive numbers (like python)
 * @param n is the number
 * @param mod is the modulus
 * @return n%mod with no negatives
 */ 
int mod(int n, int mod);
/** lowerize - send uppercase letters to lowercase
 * @param input, overloaded: can accept string, input and output files (path as strings), or istream&
 * @return - a string input returns string output (doesn't print), iofiles writes output to file, istream prints output.
 */ 
string lowerize(string input);
/** lowerize - send uppercase letters to lowercase
 * overloaded: can accept string, input and output files (path as strings), or istream&
 * a string input returns string output (doesn't print), iofiles writes output to file, istream prints output.
 * @param input filename. 
 * @param outfile filename.
 * @return none. writes to file. 
 */ 
void lowerize(string input, string output);
/** lowerize - send uppercase letters to lowercase
 * @param istream overloaded: can accept string, input and output files (path as strings), or istream&
 * @return prints.
 */ 
void lowerize(istream &in=cin);
/** lettercount - returns a vector of the counts for each letter in a string
 * @param - overloaded: can accept string or istream&
 * @return - a vector of the counts for each letter in a string
 */ 
vector<int> lettercount(string sample, int step=0, int pos=0);
/** lettercount - returns a vector of the counts for each letter in a string
 * @param - overloaded: can accept string or istream&
 * @return - a vector of the counts for each letter in a string
 */ 
vector<int> lettercount(istream &in, int step=0, int pos=0);
/** display_lettercount - prints letter wit its count. 
 *@param - vector<int> &count is a vector of counts for each lettter of the alphabet returned by lettercount()
 */
void display_lettercount(vector<int> &count);
/** determinant - returns determinant of a given matrix
 * @param matrix in form of int[cols][rows]
 * @return determinant of the matrix 
 */ 
int determinant(int matrix[2][2]);

int determinant(int matrix[3][3]);

int gcd(int a, int b);
//Vignere cipher
string v_encrypt(string plaintext, string key);

string v_decrypt(string ciphertext, string key);


//Affine Cipher
string aff_encrypt(string plaintext, int a, int b);
void aff_brute_force(string ciphertext);

/** encrypt - uses str_to_bin on message and otp, then adds the result, mod(2), and returns binary string
 *@param - string message is a plaintext message. otp is the cipher used to encode message
 *@return string binary encoding of message
 */
string otp_encrypt(string message, string otp);

/** decrypt - subtracts the binary of otp from ciphertext to get binary of original message, then uses bin_to_str to decode
 * @param - string ciphertext is a binary. otp is the plaintext cipher used to encode message
 * @return string original message
 */
string otp_decrypt(string ciphertext, string otp);

string otp_str_encrypt(string message, string otp);
string otp_str_decrypt(string ciphertext, string otp);

//Feistel Ciphers
/** f_lambda - specific function used to define a feistel round
 * @param key is the key used to execute a feistel round
 * @param r is the right part of the plaintext to be encrypted
 * @param mod modulus of the operation. default to -1 for no mod.
 * @return r as the encrypted int of r.
 */ 
int f_lambda(int key, int r, int mod);
/** feistel_encrypt - Executes a feistel round with an array of two ints
 * @param key is the key used to execute a feistel round
 * @param lr is the key to be encrypted. int[2]
 * @param mod is the modulus of the system. Defaults to 2
 * @return result as the encrypted lr[2].
 */ 
int& feistel_encrypt(int key, int (&lr)[2], int mod=2);
/** feistel_decrypt - Executes a feistel decryption round with an array of two ints
 * @param key is the key used to execute a feistel round
 * @param lr is the key to be decrypted. int[2]
 * @param mod is the modulus of the system. Defaults to 2
 * @return result as the decrypted lr[2].
 */ 
int& feistel_decrypt(int key, int (&lr)[2], int mod=2);

//
bool compare_bins(string A_URL, string B_URL, int block_size);

string double_encrypt(string message, string key1, string key2);
string double_decrypt(string message, string key1, string key2);

string encrypt_cpb(string I_URL, string O_URL, int block_size, string initial_v, string key);
string decrypt_cpb(string I_URL, string O_URL, int block_size, string initial_v, string key);

void run();

/* ************* */
int main( int argc, const char * argv[]) {

    // int c[3][3] = { {6, 1, 1},
    //                 {4, -2, 5},
    //                 {2, 8, 7} }; //-306 %26 = -20 (6)
    // cout << determinant(c); //overload = broken
    //cout << v_encrypt("hello", "zqrst");
    //cout << v_decrypt("gucdh", "zqrst");

    // string msg = "agreencoveredbookappeared";
    // int arr[2] = {4,2};
    // int key = 7;
    // cout << arr[0] << "," << arr[1] << endl;
    // feistel_encrypt(key, arr, 10);
    // cout << arr[0] << "," << arr[1] << endl;
    // feistel_encrypt(key, arr, 10);
    // cout << arr[0] << "," << arr[1] << endl;
    // feistel_encrypt(key, arr, 10);
    // cout << arr[0] << "," << arr[1] << endl;
    // feistel_encrypt(key, arr, 10);
    // cout << arr[0] << "," << arr[1] << endl;

    //cout << bin_to_str("01000011011011110110110101100101001000000100000101101110011001000010000001001101011000010110101101100101001000000100100101110100");
   
    cout << gcd(294, 182);
    return 0;
}

/* *************** */
string bin_to_str(string bin) {
    int count = 0, bit;
    string result;
    for(int i = 0; i < bin.length(); i+=8){
        char ch = bin_to_dec(bin.substr(i, 8));
        result += ch;
    }
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

/* **** UTIL ***** */
int mod(int n, int mod){
    if(n < 0){
        return (mod + n)%mod;
    }
    else return n%mod;
}
string lowerize(string input) {
    string result;
    for(int i = 0; i < input.length(); i++){
        result += tolower(input[i]);
    }
    return result;
}
void lowerize(string input, string output){
    ifstream fp;
    ofstream fp1;
    string result;
    fp.open(input);
    fp1.open(output);
    char ch;
    while(fp >> ch){
        ch = tolower(ch);
        fp1.write((char*)&ch, sizeof(ch));
    }
}
void lowerize(istream &in){
    char ch;
    string result;
    while(in >> ch){
        cout << (char)tolower(ch);
    }
}
vector<int> lettercount(string sample, int step, int pos) {
    vector<int> counts(26, 0);
    for(int x = pos; x < sample.length(); x += step){
        int pb = (int)sample[x] - 97;
        counts[pb]++;
    }
    return counts;
}
vector<int> lettercount(istream &in, int step, int pos) {
    vector<int> counts(26, 0);
    char ch;
    while(in >> ch){
        int pb = (int)ch - 97;
        counts[pb]++;
    }
    return counts;
}
void display_lettercount(vector<int> &count){
    for(int i = 0; i < 26; i++) {
        cout << (char)(i+97) << ": " << count[i] << endl;
    }
}
int determinant(int matrix[2][2]){
    //int d;
    //cout << "1: " << (matrix[0][0] * matrix[1][1]) << "\n 2: " << (matrix[0][1] * matrix[1][0]) << en;
    return ((matrix[0][0] * matrix[1][1]) - (matrix[0][1] * matrix[1][0]));
    // cout << "d: " << d << endl;
    //return d%26;
    //return d;
}
int determinant(int matrix[3][3]){
    int matrixA[2][2] = {{matrix[1][1], matrix[1][2]},
                         {matrix[2][1], matrix[2][2]}},
        matrixB[2][2] = {{matrix[1][0], matrix[1][2]},
                         {matrix[2][0], matrix[2][2]}},
        matrixC[2][2] = {{matrix[1][0], matrix[1][1]},
                         {matrix[2][0], matrix[2][1]}},
        A = matrix[0][0] * determinant(matrixA),
        B = matrix[0][1] * determinant(matrixB),
        C = matrix[0][2] * determinant(matrixC);

        //cout << "A: " << determinant(matrixA) << "--  " << matrixA[0][0] << " " << matrixA[0][1] << " " << matrixA[1][0] << " " << matrixA[1][1]  << endl;
        //cout << "B: " << determinant(matrixB) << "--  " << matrixB[0][0] << " " << matrixB[0][1] << " " << matrixB[1][0] << " " << matrixB[1][1] << endl;
        //cout << "C: " << determinant(matrixC) << "--  " << matrixC[0][0] << " " << matrixC[0][1] << " " << matrixC[1][0] << " " << matrixC[1][1]  << endl;

    return (A - B + C);
}
int gcd(int a, int b){
    int q, r, r2=min(a,b);
    while(true){
        q = a/b;
        r = a-(b*q);
        if(r > 1){
            a = b;
            b = r;
            r2 = r;
        }
        else{
            return r2;
        }
    }
    

    return r2;
}

/* ***** VIGENERE ***** */
string v_encrypt(string plaintext, string key) {
    string result;
    char ch;
    for (int x = 0; x < plaintext.length(); x++){
        int pb = (int)plaintext[x] - 97,
            kb = (int)(key[x%key.length()]) - 97;
        ch = mod((pb + kb), 26) + 97;
        result += ch;
    }
    return result;
}
string v_decrypt(string ciphertext, string key) {
    string result;
    char ch;
    for (int x = 0; x < ciphertext.length(); x++){
        int pb = (int)ciphertext[x] - 97,
            kb = (int)(key[x%key.length()]) - 97;
        ch = (char)(mod(pb - kb, 26) + 97);


        result += ch;
    }
    return result;
}
/* **** AFFINE **** */
string aff_encrypt(string plaintext, int a, int b){
    string result;
    for(int x = 0; x < plaintext.length(); x++) {
        int pb = (int)plaintext[x] - 97;
        result += ((pb*a + b)%26) + 97;
    }
    return result;
}
void aff_brute_force(string ciphertext) { //Make MORE efficient
    for(int a = 1; a < 26; a++){
        for(int b = 1; b < 26; b++){
            string res = aff_encrypt(ciphertext, a, b);
            // for(int x = 0; x < res.length(); x++){ //if a letter is missing or other param
            //     if (res[x] == 'e'){
            //         res = "";
            //     }
            // }
            cout << "A=" << a << " B:" << b << res << endl;
            cout << "-----" << endl;
        }
    }
}

/* ***** OTP ***** */
string otp_str_encrypt(string message, string otp) {

    string result;
    for (int x = 0; x < message.length(); x++){
        int pb = (int)message[x] - 97,
            kb = (int)(otp[x%otp.length()]) - 97;
        
        char ch = (char)((pb + kb)%26 + 97);

        result += ch;
    }
    return result;
}
string otp_str_decrypt(string ciphertext, string otp) {
    string result;
    char ch;
    for (int x = 0; x < ciphertext.length(); x++){
        int pb = (int)ciphertext[x] - 97,
            kb = (int)(otp[x%otp.length()]) - 97;
        ch = (char)(mod(pb - kb, 26) + 97);
        // if (pb >= kb){
        //     ch = (char)((pb - kb)%26 + 97);
        // }
        // else {
        //     ch = (char)((pb - kb + 26) + 97);
        // }

        result += ch;
    }
    return result;
}
string otp_encrypt(string message, string otp) {
    string onetimepad = str_to_bin(otp),
            ciphertext;
    //cout << "OT: " << onetimepad << '\n' << "PT: " << message << endl;
    for(int b = 0; b < message.length(); b++) { //XOR operation 
        int t = (message[b] + onetimepad[b])%2;
        if(t == -1) cout << "y";
        ciphertext.append(to_string(t));
    }
    //cout << "CT: " << ciphertext;
    return ciphertext;
}
string otp_decrypt(string ciphertext, string otp) { //USELESS
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
/* ***** FEISTEL ***** */
int f_lambda(int key, int r, int m=-1){  
    return mod(pow((key + r), 3), m);
}   

int& feistel_encrypt(int key, int (&lr)[2], int m){
    int r = lr[1];
    lr[1] = lr[0] + f_lambda(key, lr[1], m);
    lr[0] = r;
    return *lr;
}
int& feistel_decrypt(int key, int (&lr)[2], int m){
    int l = lr[0];
    lr[0] = lr[1] - f_lambda(key, lr[0], m);
    lr[1] = l;
    return *lr;
}



/* **** FUNCTION ***** */
void encrypt_r() {
    string msg, otp;
    cout << "Please type your full message, end with \"^\" (Will not be included):\n";
    cin.get();
    getline(cin, msg, '^');
    cout << "Please type your OTP cipher, end with \"^\" (It must be the exact same length as the message):\n";
    cin.get();
    getline(cin, otp, '^');
    if(msg.length() == otp.length()) {
        cout << "Begin Message:\n" << otp_encrypt(str_to_bin(msg), otp) << "\n--EOF--\n" << endl;
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
        cout << "Begin Message:" << bin_to_str(otp_decrypt(msg, otp)) << "\n--EOF--\n" << endl;
    }
    else {
        cout << "Message and Cipher lengths do not match. Please try again!\n" << endl;
    }
}
string double_encrypt(string message, string key1, string key2) {
    string ciphertext;
    ciphertext = otp_encrypt(message, key1);
    ciphertext = otp_encrypt(ciphertext, key2);
    return ciphertext;
}
string double_decrypt(string message, string key1, string key2) {
    string plaintext;
    plaintext = otp_decrypt(message, key2);
    plaintext = otp_decrypt(plaintext, key1);
    return plaintext;
}
bool compare_bins(string A_URL, string B_URL, int block_size = 16) { // DOESNT WORK
    ifstream fp, fp1;
    bool same = false;
     //char *a = new char[block_size],
      //    *b = new char[block_size];
    string a, b;
    fp.open(A_URL);
    fp1.open(B_URL);
    cout << "comparing..." << endl;
    if(fp) {
        cout << "A loaded.  ";
    }
    else {
        cout << "A failed" << endl;
        exit(EXIT_FAILURE);
    }
    if(fp1) {
        cout << "B loaded.  " << endl;
    }
    else {
        cout << "B failed" << endl;
        exit(EXIT_FAILURE);
    }
    fp >> a;
    fp1 >> b;
    // cout << "A: " << a << endl;
    // cout << "B: " << b << endl;
    cout << "SAME? " << a.compare(b);
    //cout << "SAME? " << strcmp(a, b);
              
    fp.close();
    fp1.close(); 
    return same;
}




//Cipher Block Chaining: encrypt plaintxt w init_v then with key. Unreliable.
string encrypt_cpb(string I_URL, string O_URL, int block_size, string initial_v, string key) {
    fstream fp;
    string result;
    string temp;
    int count = 0;
    fp.open(I_URL);
    if(fp) {
        char *block = new char[block_size];
        while( fp.read(block, block_size) ) {
            temp = otp_encrypt(str_to_bin(block), initial_v); //XOR with initial_v
            temp = otp_encrypt(temp, key); //XOR with Key
            result.append(temp);
            initial_v = bin_to_str(temp); //next init_v
            count++;
            if(fp.peek() == '^') break;
        }
    }
    else {
        cout << "I-file not opened" << endl;
        exit(EXIT_FAILURE);
    }
    fp.close();
    cout << "E-count: " << count << endl;
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
            
            temp = otp_decrypt(block, key); // decode with key
            temp = otp_decrypt(temp, initial_v); //decode with init_v (previous ciphertext after 1st)
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
     //   Write to file
    fp.open(O_URL);
    if(fp) {
        //fp.write((char*)&result, sizeof(result));
        fp << bin_to_str(result);
        fp << '\n';
    }
    else {
        cout << "O-file not opened" << endl;
        exit(EXIT_FAILURE);
    }
    fp.close();


    cout << "\nD-Count: " << count << endl;
    return bin_to_str(result);
}

void file_run() {
    char ch;
    string i_file, o_file, init_v, key;
    cout << "\nWould you like to encrypt or decrypt a file?    E / D\n";
    cin >> ch;
    if(ch == 'E' || ch == 'e') {
        cout << "Type the full path of the input file (to be encrypted).\n";
        cin >> i_file;
        cout << "Type the full path of the output file.\n";
        cin >> o_file;
        cin.get();
        cout << "Enter the initialization vector, hit [Enter] when done\n";
        getline(cin, init_v, '\n');
        cout << "Enter the secret key, hit [Enter] when done\n";
        getline(cin, key, '\n');
        encrypt_cpb(i_file, o_file, 16, init_v, key);
    }
    else if(ch == 'D' || ch == 'd'){
        cout << "Type the full path of the input file (to be decrypted).\n";
        cin >> i_file;
        cout << "Type the full path of the output file.\n";
        cin >> o_file;
        cin.get();
        cout << "Enter the initialization vector, hit [Enter] when done\n";
        getline(cin, init_v, '\n');
        cout << "Enter the secret key, hit [Enter] when done\n";
        getline(cin, key, '\n');
        
        decrypt_cpb(i_file, o_file, 16, init_v, key);
    }
    else {
        cout << "Error: Please type either \'E\' or \'D\' to Encrypt or Decrypt a message.\n";
        file_run();
    }
}
void msg_run() {
    char ch;
    cout << "\nWould you like to encrypt or decrypt a message?    E / D\n";
    cin >> ch;
    if(ch == 'E' || ch == 'e') {
        encrypt_r();
    }
    else if(ch == 'D' || ch == 'd'){
        decrypt_r();  
    }
    else {
        cout << "Error: Please type either \'E\' or \'D\' to Encrypt or Decrypt a message.\n";
        msg_run();
    }
}
void run() {
    char ch;
    cout << "\nHello! Welcome to the OneTimePad Encryptor. Would you like to work with files or messages?   F / M\n";
    cin >> ch;
    if(ch == 'F' || ch == 'f') {
        file_run();
    }

    else if (ch == 'M' || ch == 'm') {
        msg_run();
    }
    else if (ch == 'Q' || ch == 'q'){
        cout << "\nWould you like to Quit?\n";
        cin >> ch;
        if(ch == 'Q' || ch == 'q'){
            cout << "Bye!";
            exit(EXIT_SUCCESS);
        }
        else{
            run();
        }
    }
    cout << "Would you like to Encrypt or Decrypt another message or file?   Y / N\n";
    cin >> ch;
    if(ch == 'Y' || ch == 'y') {
        run();
    }
    else if (ch == 'Q' || ch == 'q'){
        cout << "\nWould you like to Quit?\n";
        cin >> ch;
        if(ch == 'Q' || ch == 'q'){
            cout << "Bye!";
            exit(EXIT_SUCCESS);
        }
        else{
            run();
        }
    }

    else exit(EXIT_SUCCESS);
}