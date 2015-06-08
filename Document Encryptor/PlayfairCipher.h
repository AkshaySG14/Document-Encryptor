//
//  PlayfairCipher.h
//  Text Encryptor
//
//  Created by Akshay Subramaniam on 7/5/15.
//  Copyright (c) 2015 Incultus. All rights reserved.
//

#ifndef __Text_Encryptor__PlayfairCipher__
#define __Text_Encryptor__PlayfairCipher__

#include <stdio.h>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <sstream>
#include <iostream>
#include <array>
#include <Cipher.h>

using namespace std;

class PlayfairCipher : public Cipher {
public:
    // Class constructor.
    PlayfairCipher(std::string message, bool encrypt);
protected:
    void getCipherText();
    void getPlainText();
private:
    bool checkRectHorizontal(int, int, int, int);
    bool checkRectVertical(int, int, int, int);
    bool checkRow(int, int);
    bool checkColumn(int, int);
    int findRow(std::string);
    int findColumn(std::string);
    void breakUpText();
    std::string shiftRow(int, int, bool);
    std::string shiftColumn(int, int, bool);
    std::string switchRectVert(int, int);
    std::string switchRectHori(int, int);
};

#endif /* defined(__Text_Encryptor__PlayfairCipher__) */
