//
//  value.h
//  clox
//
//  Created by Bhupesh on 06.09.25.
//

#ifndef clox_value_h
#define clox_value_h

#include <vector>

namespace clox {
using Value = double;

typedef struct{
    int count;
    int capacity;
    std::vector<Value> values;
}ValueVec;

void initValueVec(ValueVec &vec);
void writeValueVec(ValueVec &vec, Value value);
void printValue(Value value);

}

#endif
