//
//  chunk.h
//  my_crafting_interpreter
//
//  Created by Bhupesh on 17.08.25.
//

#ifndef CLOX_CHUNK_H
#define CLOX_CHUNK_H

#include <vector>
#include "value.h"

namespace clox{

typedef enum{
    OP_RETURN,
    OP_CONSTANT,
    OP_NEGATE,
    OP_ADD,
    OP_SUBTRACT,
    OP_MULTIPLY,
    OP_DIVIDE,
    
}OpCode; // ToDo: Use enum class instead and write better writeChunk function


typedef struct{
    int count;
    int capacity;
    std::vector<uint8_t> code;
    std::vector<int32_t> lines;
    ValueVec constants;
}Chunk;

void initChunk(Chunk &chunk);
void writeChunk(Chunk &chunk, uint8_t byte, int32_t line);
int addConstant(Chunk &chunk, Value value);

}
#endif
