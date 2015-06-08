//
//  Decryptor.h
//  Document Encryptor
//
//  Created by Akshay Subramaniam on 1/6/15.
//  Copyright (c) 2015 Incultus. All rights reserved.
//

#ifndef __Document_Encryptor__Decryptor__
#define __Document_Encryptor__Decryptor__

#include <stdio.h>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string.h>
#include "PlayfairCipher.h"
#include "HillCipher.h"
#include "ColumnarTransposition.h"

using namespace std;

class Decryptor {
public:
    // Class constructor.
    Decryptor(std::string plainText);
    std::string givePlainText();
private:
    // Int that tells the class what kind of cipher is to be used to decrypt the message.
    int type;
    // String that holds the plain text.
    std::string plainText;
    
    void decrypt(std::string);
    void playfairCipher(std::string);
    void hillCipher(std::string);
    void rowTransposition(std::string);
};

#endif /* defined(__Document_Encryptor__Decryptor__) */
