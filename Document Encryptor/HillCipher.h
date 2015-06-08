//
//  HillCipher.h
//  Text Encryptor
//
//  Created by Akshay Subramaniam on 11/5/15.
//  Copyright (c) 2015 Incultus. All rights reserved.
//

#ifndef __Text_Encryptor__HillCipher__
#define __Text_Encryptor__HillCipher__

#include <stdio.h>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <array>
#include <Cipher.h>
#include <ThreeByThreeMatrix.h>
#include <ThreeByOneMatrix.h>

using namespace std;

class HillCipher : public Cipher {
public:
    // Class constructor.
    HillCipher(std::string, bool);
protected:
    void getCipherText();
    void getPlainText();
private:
    std::string plainTextMatrix[3][3];
    std::string cipherTextMatrix[3][3];
    std::string getCipherMessage(std::vector<std::vector<int>>);
    std::vector<std::string> getBrokenMessage();
    std::vector<int> getMessageMatrix(std::string);
};

#endif /* defined(__Text_Encryptor__HillCipher__) */
