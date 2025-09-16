//
//  main.cpp
//  clox
//
//  Created by Bhupesh on 30.08.25.
//

#include <iostream>
#include "chunk.h"
#include "debug.h"
#include "vm.h"

int main(int argc, const char * argv[]) {
    
    clox::VM vm;
    clox::initVM(vm);
    clox::Chunk chunk;
    clox::initChunk(chunk);

    int constant = clox::addConstant(chunk, 1.2);
    clox::writeChunk(chunk, clox::OP_CONSTANT, 343);

    constant = clox::addConstant(chunk, 3.4);
    clox::writeChunk(chunk, clox::OP_CONSTANT, 123);

    clox::writeChunk(chunk, clox::OP_ADD, 123);

    constant = addConstant(chunk, 5.6);
    clox::writeChunk(chunk, clox::OP_CONSTANT, 123);

    // clox::writeChunk(chunk, clox::OP_CONSTANT, 123);

    clox::writeChunk(chunk, clox::OP_DIVIDE, 123);

    clox::writeChunk(chunk, clox::OP_NEGATE, 123);

    clox::writeChunk(chunk, clox::OP_RETURN, 123);
    clox::disassembleChunk(chunk, "test_chunk");

    clox::InterpretResult result = clox::interpret(vm, chunk);
    
    return 0;
}
