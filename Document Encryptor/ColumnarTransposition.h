//
//  ColumnarTransposition.h
//  Document Encryptor
//
//  Created by Akshay Subramaniam on 25/5/15.
//  Copyright (c) 2015 Incultus. All rights reserved.
//

#ifndef __Document_Encryptor__ColumnarTransposition__
#define __Document_Encryptor__ColumnarTransposition__

#include <stdio.h>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <array>
#include <Cipher.h>
#include <ThreeByThreeMatrix.h>
#include <ThreeByOneMatrix.h>

using namespace std;

class ColumnarTransposition : public Cipher {
public:
    // Constructor for class.
    ColumnarTransposition(std::string, bool, bool);
protected:
    void getCipherText();
    void getPlainText();
private:
    // Boolean that determines the purpose of the class.
    bool single;
    std::vector<std::vector<std::string>> getPlainMessageMatrix(std::string assortedMessage);
    std::vector<std::vector<std::string>> getCipherMessageMatrix(std::string assortedMessage);
    std::vector<std::string> getMessageAssorted();
    std::string getCipherTextPart(std::vector<std::vector<std::string>> messageMatrix);
    std::string getPlainTextPart(std::vector<std::vector<std::string>> messageMatrix);
};

#endif /* defined(__Document_Encryptor__ColumnarTransposition__) */
