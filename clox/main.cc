//
//  main.cpp
//  clox
//
//  Created by Bhupesh on 30.08.25.
//

#include <iostream>
#include "chunk.h"
#include "debug.h"

int main(int argc, const char * argv[]) {
    
    clox::Chunk chunk;
    clox::initChunk(chunk);
    int constant = clox::addConstant(chunk, 1.2);
    clox::writeChunk(chunk, clox::OP_CONSTANT, 343);
    clox::writeChunk(chunk, constant, 4343);
    clox::writeChunk(chunk, clox::OP_RETURN, 4343);
    clox::disassembleChunk(chunk, "test chunk");
    return 0;
}
