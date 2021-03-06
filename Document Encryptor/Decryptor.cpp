//
//  Decryptor.cpp
//  Document Encryptor
//
//  Created by Akshay Subramaniam on 1/6/15.
//  Copyright (c) 2015 Incultus. All rights reserved.
//

#include "Decryptor.h"

// Sets the message, so that it may be decrypted.
Decryptor::Decryptor(std::string message) {
    decrypt(message);
}

// A somewhat complex method that fully decrypts the message, without knowing what the cipher used to encrypt it is. This is accomplished by checking the spacing of the message, which gives away the type of cipher that was used to encrypt the message. Additionally, the method is recursive, to fully decrypt the message should the user have encrypted the file multiple times, or used a combination of encryptions.
void Decryptor::decrypt(std::string message) {
    // Creates a placeholder message, so that the original message is untampered with.
    std::string newMessage = message;
    // Checks if there is a space every three spaces. If there is not, the loop will break.
    for (int i = 0; i < newMessage.length();
         i ++) {
        // If the position has no remainder when divided by three, and is not zero, it is the position that the method is trying to find.
        if (i % 3 == 0 && i != 0) {
            // If no space, breaks.
            if (newMessage[i] != ' ')
                break;
            else {
            // Else, the method erases the space, and moves one space forward, to avoid repeating over the space.
                newMessage.erase(i, 1);
                ++ i;
            }
        }
        // If the end of the loop is successfully reached, the method will decrypt via the according cipher (in this case the playfair cipher).
        if (i >= newMessage.length() - 1) {
            playfairCipher(newMessage);
            decrypt(plainText);
            return;
        }
    }
    //Same as playfair, but for the hill cipher.
    newMessage = message;
    for (int i = 0; i < newMessage.length(); i ++) {
        if (i % 2 == 0 && i != 0) {
            if (newMessage[i] != ' ') {
                break;
            }
            else {
                newMessage.erase(i, 1);
                ++ i;
            }
        }
        if (i >= newMessage.length() - 1) {
            hillCipher(newMessage);
            decrypt(plainText);
            return;
        }
    }
    //Same as the previous two, except for the columnar transposition cipher.
    newMessage = message;
    for (int i = 0; i < newMessage.length(); i ++) {
        if (i % 4 == 0 && i != 0) {
            if (newMessage[i] != ' ')
                break;
            else {
                newMessage.erase(i, 1);
                ++ i;
            }
        }
        if (i >= newMessage.length() - 1) {
            rowTransposition(newMessage);
            decrypt(plainText);
            return;
        }
    }
}

// Decrypts the playfair cipher by launching its respective class.
void Decryptor::playfairCipher(std::string message) {
    PlayfairCipher decryptCipher(message, false);
    plainText = decryptCipher.givePlainText();
}

// Decrypts the hill cipher by launching its respective class.
void Decryptor::hillCipher(std::string message) {
    HillCipher decryptCipher(message, false);
    plainText = decryptCipher.givePlainText();
}

// Decrypts the columnar transposition cipher by launching its respective class. Note that it is decrypted twice.
void Decryptor::rowTransposition(std::string message) {
    ColumnarTransposition decryptCipher(message, false, false);
    plainText = decryptCipher.givePlainText();
    ColumnarTransposition decryptCipher2(plainText, false, true);
    plainText = decryptCipher2.givePlainText();
}

//Gives the plain text to the textencryptor class.
std::string Decryptor::givePlainText() {
    return plainText;
}
