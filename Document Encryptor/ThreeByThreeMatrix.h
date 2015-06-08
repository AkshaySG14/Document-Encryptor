//
//  Matrix.h
//  Text Encryptor
//
//  Created by Akshay Subramaniam on 14/5/15.
//  Copyright (c) 2015 Incultus. All rights reserved.
//

#ifndef __Text_Encryptor__Matrix__
#define __Text_Encryptor__Matrix__

#include <stdio.h>
#include <ThreeByOneMatrix.h>
#include <iostream>
#include <vector>

using namespace std;

class ThreeByThreeMatrix {
public:
    // Class constructor.
    ThreeByThreeMatrix(int[3][3]);
    ThreeByOneMatrix multiply(ThreeByOneMatrix);
    ThreeByThreeMatrix invert();
    int getItem(int, int);
private:
    // Actual matrix.
    int items[3][3];
    std::vector<int> getMinorMatrix(int row, int column);
    std::vector<std::vector<std::vector<int>>> getMatrixOfMinors();
};

#endif /* defined(__Text_Encryptor__Matrix__) */
