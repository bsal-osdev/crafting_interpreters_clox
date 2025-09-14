//
//  debug.h
//  clox
//
//  Created by Bhupesh on 30.08.25.
//

#ifndef CLOX_DEBUG_H
#define CLOX_DEBUG_H
#include <string>
#include "chunk.h"
#include "memory.h"

namespace clox {

void disassembleChunk(Chunk &chunk, std::string name);
int disassembleInstruction(Chunk &chunk, int offset);

}
#endif
