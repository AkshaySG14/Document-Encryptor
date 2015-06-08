//
//  ThreeByOneMatrix.h
//  Text Encryptor
//
//  Created by Akshay Subramaniam on 16/5/15.
//  Copyright (c) 2015 Incultus. All rights reserved.
//

#ifndef __Text_Encryptor__ThreeByOneMatrix__
#define __Text_Encryptor__ThreeByOneMatrix__

#include <stdio.h>
#include <vector>

class ThreeByOneMatrix {
public:
    // Class constructor.
    ThreeByOneMatrix(int[3][1]);
    void modulo();
    int getItem(int);
    std::vector<std::vector<int>> getMatrix();
private:
    // Actual matrix.
    int items[3][1];

};
#endif /* defined(__Text_Encryptor__ThreeByOneMatrix__) */
