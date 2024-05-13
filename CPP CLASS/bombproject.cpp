#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// Function prototypes
bool checkPhase1(const string& input);
bool checkPhase2(const string& input);
bool checkPhase3(const string& input);

// Encrypt or decrypt the secret
string xorEncryptDecrypt(const string& input, char key) {
    string output = input;
    for (size_t i = 0; i < input.size(); i++) {
        output[i] = input[i] ^ key;
    }
    return output;
}

// Key for XOR encryption
const char secretKey = 'X';

// Encrypted version of the secret
const string encryptedSecret = xorEncryptDecrypt("echo", secretKey);

bool phase1() {
    cout << "PHASE 1: There is a hidden phrase somewhere in this program. Can you find it?" << endl;
    cout << "Hint: Try examining the program's binary with some tool!" << endl;

    string phraseInput;
    cout << "Enter the hidden phrase you found: ";
    getline(cin, phraseInput);

    if (checkPhase1(phraseInput)) {
        cout << "Correct! Proceed to Phase 2." << endl;
        return true;
    } else {
        cout << "Incorrect! Access to bomb code denied. The program will now exit." << endl;
        return false;
    }
}

bool phase2() {
    cout << "PHASE 2: Enter the bomb code to diffuse: ";
    string userInput;
    cin >> userInput;

    if (checkPhase2(userInput)) {
        cout << "Correct! Proceed to Phase 3." << endl;
        return true;
    } else {
        cout << "Incorrect code! Bomb exploded." << endl;
        return false;
    }
}

bool phase3() {
    cout << "PHASE 3: Solve this riddle to stop the countdown:" << endl;
    cout << "I speak without a mouth and hear without ears. I have no body, but I come alive with wind. What am I?" << endl;

    string answer;
    cin.ignore();  // Clears the newline character in the buffer after cin >>
    getline(cin, answer);

    if (checkPhase3(answer)) {
        cout << "Correct! The bomb is diffused." << endl;
        return true;
    } else {
        cout << "Incorrect answer! The countdown accelerates." << endl;
        return false;
    }
}

bool checkPhase1(const string& input) {
    return input == "UnlockTheSecretsOfTheUniverse";
}

bool checkPhase2(const string& input) {
    vector<char> code(input.begin(), input.end());
    reverse(code.begin(), code.end());
    return string(code.begin(), code.end()) == "8765";
}

bool checkPhase3(const string& input) {
    string temp = input;
    transform(temp.begin(), temp.end(), temp.begin(), ::tolower);
    string secret = xorEncryptDecrypt(encryptedSecret, secretKey);
    return temp == secret;
}

int main() {
    if (phase1()) {
        if (phase2()) {
            phase3();
        }
    }
    return 0;
}
