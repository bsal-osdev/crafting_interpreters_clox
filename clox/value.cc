//
//  value.cc
//  clox
//
//  Created by Bhupesh on 06.09.25.
//

#include <iostream>
#include "value.h"
#include "memory.h"

namespace clox {

void initValueVec(ValueVec &vec){
    vec.count = 0;
    vec.capacity = 0;
}

void writeValueVec(ValueVec &vec, Value value){
    
    if(vec.capacity < vec.count + 1){
        auto old_vec_capacity = vec.capacity;
        vec.capacity = growCapacity(old_vec_capacity);
        vec.values.resize(vec.capacity);
    }
    
    vec.values[vec.count] = value;
    vec.count++;
}

void printValue(Value value){
    std::cout << value ;
}

}
