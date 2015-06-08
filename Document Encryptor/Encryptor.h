//
//  Encryptor.h
//  Text Encryptor
//
//  Created by Akshay Subramaniam on 6/5/15.
//  Copyright (c) 2015 Incultus. All rights reserved.
//

#ifndef __Text_Encryptor__Encryptor__
#define __Text_Encryptor__Encryptor__

#include <stdio.h>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string.h>
#include "PlayfairCipher.h"
#include "HillCipher.h"
#include "ColumnarTransposition.h"

using namespace std;

class Encryptor {
public:
    // Constructor for class.
    Encryptor(int type, std::string plainText);
    std::string giveCipherText();
private:
    // Type of cipher, 1 being playfair, etc.
    int type;
    // All texts of the class.
    std::string message, plainText, cipherText;
    
    void encrypt();
    void playfairCipher();
    void hillCipher();
    void colTransposition();
    void playfairCol();
    void hillCol();
};

#endif /* defined(__Text_Encryptor__Encryptor__) */
