//
//  vm.h
//  clox
//
//  Created by Bhupesh on 12.09.25.
//

#ifndef clox_vm_h
#define clox_vm_h

#include "chunk.h"
#include <array>
namespace clox {

constexpr size_t STACK_MAX = 256;

typedef struct{
    Chunk chunk;
    int32_t ip_index;
    int32_t const_index;
    std::array<Value, STACK_MAX> stack;
    Value *stack_top;
}VM;

enum class InterpretResult
{
    INTERPRET_OK,
    INTERPRET_COMPILER_ERROR,
    INTERPRET_RUNTIME_ERROR
};

void initVM(VM &vm);
void freeVM();

InterpretResult interpret(VM& vm, Chunk& chunk);

}

#endif
