//
//  ThreeByOneMatrix.cpp
//  Text Encryptor
//
//  Created by Akshay Subramaniam on 16/5/15.
//  Copyright (c) 2015 Incultus. All rights reserved.
//

#include "ThreeByOneMatrix.h"
#include <iostream>
using namespace std;
// Matrix that holds a 3x1 array. Used for multiplication involving the arrays.
// Creates matrix from a given array.
ThreeByOneMatrix::ThreeByOneMatrix(int items[3][1]) {
    for (int x = 0; x < 3; x ++)
        this->items[x][0] = items[x][0];
}

// Modulos every matrix value by 90.
void ThreeByOneMatrix::modulo() {
    int moduloItems[3][1];
    for (int x = 0; x < 3; x ++) {
        items[x][0] = items[x][0] % 90;
    }
    // Returns the new matrix.
    return ThreeByOneMatrix(moduloItems);
}

// Gets the specific item using the row given (only row is needed.
int ThreeByOneMatrix::getItem(int row) {
    return items[row][0];
}

// Returns the matrix itself in the form of a vector.
std::vector<std::vector<int>> ThreeByOneMatrix::getMatrix() {
    std::vector<std::vector<int>> returnMatrix;
    returnMatrix.resize(3);
    for (int x = 0; x < 3; x ++) {
        returnMatrix[x].resize(1);
        returnMatrix[x][0] = items[x][0];
    }
    return returnMatrix;
}
