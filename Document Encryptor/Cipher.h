//
//  Cipher.h
//  Text Encryptor
//
//  Created by Akshay Subramaniam on 11/5/15.
//  Copyright (c) 2015 Incultus. All rights reserved.
//

#ifndef __Text_Encryptor__Cipher__
#define __Text_Encryptor__Cipher__

#include <stdio.h>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <sstream>
#include <iostream>
#include <array>

using namespace std;

class Cipher {
public:
    // Class constructor.
    Cipher(std::string);
    
    // Methods that give different texts.
    std::string giveCipherText();
    std::string givePlainText();
protected:
    // Actual strings of the texts.
    std::string message, cipherText = "", plainText = "";
    // Matrix of the ciphers.
    std::string matrix[10][9];
    
    // These are abstract methods that are implemented by the ciphers themselves.
    virtual void getCipherText() = 0;
    virtual void getPlainText() = 0;
private:
    // Method that creates the matrix.
    void initializeMatrix();
};
#endif /* defined(__Text_Encryptor__Cipher__) */
