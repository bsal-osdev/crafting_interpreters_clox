//
//  vm.cc
//  clox
//
//  Created by Bhupesh on 12.09.25.
//
#include "vm.h"
#include <iostream>
#define DEBUG_TRACE_EXECUTION

namespace clox {

static void resetStack(VM& vm){
    vm.stack_top = vm.stack.data();
}

static void push(VM& vm, Value &value){
    *vm.stack_top = value;
    vm.stack_top++;
}

static Value pop(VM& vm){
    vm.stack_top--;
    Value val = *vm.stack_top;
    return val;
}

static InterpretResult run(VM &vm){

#ifdef DEBUG_TRACE_EXECUTION
    std::cout << "          ";
    for (Value* slot = vm.stack.data(); slot < vm.stack_top; slot++) {
      std::cout << "[ ";
      printValue(*slot);
      std::cout << " ]";
    }
    std::cout << "\n";
#endif

    for(;;){
        
        uint8_t instruction = vm.chunk.code[vm.ip_index];
        switch (instruction) {
            case OP_RETURN:{
                printValue(pop(vm));
                return InterpretResult::INTERPRET_OK;
            }
            case OP_CONSTANT:{
                Value constant = vm.chunk.constants.values[vm.ip_index];
                push(vm, constant);
                printValue(constant);
            }
                return InterpretResult::INTERPRET_OK;
            default:{
                    return InterpretResult::INTERPRET_OK;
                }
        }
        
    }
    
}


InterpretResult interpret(VM& vm, Chunk& chunk){
    vm.chunk = chunk;
    vm.ip_index = 0;
    return run(vm);
}




}
