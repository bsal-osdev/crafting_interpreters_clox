//
//  debug.cpp
//  clox
//
//  Created by Bhupesh on 30.08.25.
//

#include "debug.h"
#include <iostream>
#include <iomanip>
#include "value.h"


namespace clox {

static int simpleInstruction(std::string name, int offset) {
    std::cout << name << "\n";
    return offset + 1;
}

static int constantInstruction(std::string name, Chunk &chunk, int offset) {
    
    uint8_t constant = chunk.code[offset + 1];
    std::cout << name << " ";
    std::cout << constant << " ";
    printValue(chunk.constants.values[constant]);
    std::cout << "\n";
    return offset + 2;
}


int disassembleInstruction(Chunk &chunk, int offset){
    
    std::cout << std::setfill('0') << std::setw(4) << offset << " ";
    uint8_t instruction = chunk.code[offset];

    if (offset > 0 && chunk.lines[offset] == chunk.lines[offset - 1]) {
        std::cout << "   | ";
    }
    else {
        std::cout << std::setfill('0') << std::setw(4) << chunk.lines[offset] << " ";
    }

    switch (instruction) {
        case OP_RETURN:
            return simpleInstruction("OP_RETURN", offset);
        case OP_CONSTANT:
            return constantInstruction("OP_CONSTANT", chunk, offset);
        default:
            printf("Unknown opcode %d\n", instruction);
            return offset + 1;
    }
}

void disassembleChunk(Chunk &chunk, std::string name){
    
    std::cout << "=== " << name << " ==\n";
    
    for(int offset = 0; offset < chunk.count;){
        offset = disassembleInstruction(chunk, offset); // increament to offset is done this way to accomodate different size instructions
    }
}

}

