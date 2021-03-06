
//
//  PlayfairCipher.cpp
//  Text Encryptor
//
//  Created by Akshay Subramaniam on 7/5/15.
//  Copyright (c) 2015 Incultus. All rights reserved.
//

#include "PlayfairCipher.h"

// Same as other ciphers.
PlayfairCipher::PlayfairCipher(std::string message, bool encrypt) : Cipher(message) {
    if (encrypt)
        breakUpText();
    else
        getPlainText();
}

// Breaks up the text into bits of two, so that the cipher can work properly.
void PlayfairCipher::breakUpText() {
    // Creates duplicate message.
    std::string newText = message;
    
    for (int i = 0; i < message.size(); i ++) {
        // If the two letters are the same, adds an x between them.
        if (message[i] == message[i + 1]) {
            // Gets the position of the new 'x'.
            int position = i + newText.length() - message.length();
            // Inserts the new x after the first letter, and before the second. Basically concantenates all letters before the x, the x itsef, and all letters after the x.
            newText = newText.substr(0, position + 1) + "x" + newText.substr(position + 1, newText.length());
        }
    }
    
    message = newText;
    
    // Adds an asterisk if the message length is not divisible by two, meaning there is a lone character at the end.
    if (message.length() % 2 != 0)
        message = message + "*";
    
    getCipherText();
}

// Same as the other ciphers.
void PlayfairCipher::getCipherText() {
    // Creates the list that contains each two-length string.
    std::vector<std::string> blockList;
    for (int i = 0; i < message.length(); i += 2)
        blockList.push_back(message.substr(i, 2));
    
    // This shifts the letters depending on their orientation (check how the cipher works to figure this one out).
    for (std::vector<std::string>::iterator iterator = blockList.begin(); iterator != blockList.end(); ++iterator) {
        // Gets the first and second (last) letter of each message bit.
        std::string fLetter = iterator->substr(0, 1);
        std::string lLetter = iterator->substr(1, 1);
        // Finds the row and column of each letter in the superclass cipher, and sets them to variables.
        int fRow = findRow(fLetter);
        int fColumn = findColumn(fLetter);
        int lRow = findRow(lLetter);
        int lColumn = findColumn(lLetter);
        
        // Checks if the letters are on the same row, and if so sets the encrypted letters to the right position of the original letters. If on the edge, the encrypted letter will be the first letter in that row.
        if (checkRow(fRow, lRow)) {
            fLetter = shiftRow(fRow, fColumn, true);
            lLetter = shiftRow(lRow, lColumn, true);
        }
        // Checks if the letters are on the same column, and if so sets the encrypted letters to the bottom position of the original letters. if on the edge, the encrypted letter will be the first letter in that column.
        else if (checkColumn(fColumn, lColumn)) {
            fLetter = shiftColumn(fRow, fColumn, true);
            lLetter = shiftColumn(lRow, lColumn, true);
        }
        // Checks if the letters would form a horizontal rectangle when connected via an outline. If so, the encrypted letters will be in the same rows, but on opposite corners.
        else if (checkRectHorizontal(fRow, fColumn, lRow, lColumn)) {
            fLetter = switchRectHori(fRow, lColumn);
            lLetter = switchRectHori(lRow, fColumn);
        }
        // Same as the previous check.
        else if (checkRectVertical(fRow, fColumn, lRow, lColumn)) {
            fLetter = switchRectVert(fColumn, lRow);
            lLetter = switchRectVert(lColumn, fRow);
        }
        // Adds the now-encrypted letters to the cipher text.
        cipherText = cipherText + fLetter + lLetter;
    }
    
    // Creates a space every three characters for identification purposes.
    int count = 0;
    for (int i = 0; i < cipherText.length(); ++ i)
        if ((i - count) % 3 == 0 && i != 0) {
            cipherText.insert(i, " ");
            ++ count;
            ++ i;
        }

}

// Virtually the same as getCipherText(), but reverses the actual process of encryption to decrypt.
void PlayfairCipher::getPlainText() {
    std::vector<std::string> blockList;
    
    for (int i = 0; i < message.length(); i += 2)
        blockList.push_back(message.substr(i, 2));
    
    for (std::vector<std::string>::iterator iterator = blockList.begin(); iterator != blockList.end(); ++iterator) {
        std::string fLetter = iterator->substr(0, 1);
        std::string lLetter = iterator->substr(1, 1);
        int fRow = findRow(fLetter);
        int fColumn = findColumn(fLetter);
        int lRow = findRow(lLetter);
        int lColumn = findColumn(lLetter);
        
        // Same as encryption version but shifts to the left.
        if (checkRow(fRow, lRow)) {
            fLetter = shiftRow(fRow, fColumn, false);
            lLetter = shiftRow(lRow, lColumn, false);
        }
        
        // Same as encryption version but shifts up.
        else if (checkColumn(fColumn, lColumn)) {
            fLetter = shiftColumn(fRow, fColumn, false);
            lLetter = shiftColumn(lRow, lColumn, false);
        }
        // These two methods are the exact same as the encryption version, but will decrypt.
        else if (checkRectHorizontal(fRow, fColumn, lRow, lColumn)) {
            fLetter = switchRectHori(fRow, lColumn);
            lLetter = switchRectHori(lRow, fColumn);
        }
        else if (checkRectVertical(fRow, fColumn, lRow, lColumn)) {
            fLetter = switchRectVert(fColumn, lRow);
            lLetter = switchRectVert(lColumn, fRow);
        }
        // Same but for the plain text.
        plainText = plainText + fLetter + lLetter;
    }
    
    // Removes the extra characters to make the plain text legible.
    // Finds the asterisk and deletes all characters after that asterisk.
    if (plainText.substr(plainText.length() - 1, 1) == "*")
        plainText = plainText.substr(0, plainText.length() - 1);
    
    // Finds any x's between two identical characters and deletes them.
    for (int i = 0; i < plainText.length(); i ++)
        if (i + 2 < plainText.length() - 1 && plainText.substr(i, 1) == plainText.substr(i + 2, 1) && plainText.substr(i + 1, 1) == "x")
            // Concantenates two substrings, one before and one after the x to form the new string.
            plainText = plainText.substr(0, i + 1) + plainText.substr(i + 2);
}

// Finds the row of the character by finding the identical character in the superclass matrix and returning the row.
int PlayfairCipher::findRow(std::string target) {
    for (int x = 0; x < 10; x ++)
        for (int y = 0; y < 9; y ++)
            if (target == matrix[x][y]) {
                return x;
            }
    return -1;
}

// Same as previous method but for the column.
int PlayfairCipher::findColumn(std::string target) {
    for (int x = 0; x < 10; x ++)
        for (int y = 0; y < 9; y ++) {
            if (target == matrix[x][y])
                return y;
        }
    return -1;
}

// Checks if the two characters are of the same row.
bool PlayfairCipher::checkRow(int fRow, int lRow) {
    return fRow == lRow;
}

// Same but for column.
bool PlayfairCipher::checkColumn(int fCol, int lCol) {
    return fCol == lCol;
}

// Checks if the two characters are farther apart horizontally than vertically, meaning a horizontal rectangle would encompass them.
bool PlayfairCipher::checkRectHorizontal(int fRow, int fCol, int lRow, int lCol) {
    return abs(fRow - lRow) <= abs(fCol - lCol);
}

// Same but if the characters are farther apart vertically.
bool PlayfairCipher::checkRectVertical(int fRow, int fCol, int lRow, int lCol) {
    return abs(fRow - lRow) > abs(fCol - lCol);
}

// Returns the character that is to the right of the message bit character.
std::string PlayfairCipher::shiftRow(int row, int column, bool encrypt) {
    if (encrypt) {
        // If the character is NOT at the edge of the matrix.
        if (column != 8)
            return matrix[row][column + 1];
        else
            // If the character IS at the edge, sets it to the first character in the same row.
            return matrix[row][0];
    }
    else {
        // Same but for the decryption version.
        // Moves character left.
        if (column != 0)
            return matrix[row][column - 1];
        else
            // Sets to the last character in the same row.
            return matrix[row][8];
    }
}

// Virtually the same as the row method.
std::string PlayfairCipher::shiftColumn(int row, int column, bool encrypt) {
    if (encrypt) {
        if (row != 9)
            // Moves character up.
            return matrix[row + 1][column];
        else
            // First character of the same column.
            return matrix[0][column];
    }
    else {
        if (row != 0) {
            // Moves character down.
            return matrix[row - 1][column];
        }
        else
            // Last character of the same column.
            return matrix[9][column];
    }
}

// Essentially sets the encrypted letter to the character that occupies the same row as the first letter, and the same column as the second letter.
std::string PlayfairCipher::switchRectHori(int tRow, int sCol) {
    return matrix[tRow][sCol];
}

// Inverse of the previous method, same row as second, same column as first.
std::string PlayfairCipher::switchRectVert(int tCol, int sRow) {
    return matrix[sRow][tCol];
}