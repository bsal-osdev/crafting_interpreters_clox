//
//  chunk.cpp
//  clox
//
//  Created by Bhupesh on 17.08.25.
//

#include "chunk.h"
#include "memory.h"
#include <iostream>
namespace clox {

void initChunk(Chunk &chunk){
    chunk.count = 0;
    chunk.capacity = 0;
    initValueVec(chunk.constants);
}

void writeChunk(Chunk &chunk, uint8_t byte, int32_t line){
    
    if(chunk.capacity < chunk.count + 1){
        auto old_chunk_capacity = chunk.capacity;
        chunk.capacity = growCapacity(old_chunk_capacity);
        chunk.code.resize(chunk.capacity);
        chunk.lines.resize(chunk.capacity);
    }
    
    chunk.code[chunk.count] = byte;
    chunk.lines[chunk.count] = line;
    chunk.count++;
}


int addConstant(Chunk &chunk, Value value){

    writeValueVec(chunk.constants, value);
    std::cout << chunk.constants.capacity << " " << chunk.constants.count << "\n";
    return chunk.constants.count - 1;
}

}
