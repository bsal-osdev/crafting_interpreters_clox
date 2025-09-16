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
    std::cout << "stack push value " << *vm.stack_top << "\n";
    vm.stack_top++;
}

static Value pop(VM& vm){
    vm.stack_top--;
    Value val = *vm.stack_top;
    std::cout << "stack top value " << val << "\n";
    return val;
}

static InterpretResult run(VM &vm){
    
    
    while(vm.ip_index < vm.chunk.count){

        std::cout <<"VM: " << vm.ip_index << " " << vm.chunk.count << "\n";
        /*
#ifdef DEBUG_TRACE_EXECUTION
        std::cout << "      wrwwq    ";
        for (Value* slot = vm.stack.data(); slot < vm.stack_top; slot++) {
            std::cout << "[ ";
            printValue(*slot);
            std::cout << " ]";
        }
        std::cout << "\n";
#endif
         */
        uint8_t instruction = vm.chunk.code[vm.ip_index++];
        switch (instruction) {
            case OP_RETURN:{
                printValue(pop(vm));
                break;
            }
            case OP_CONSTANT:{
                Value constant = vm.chunk.constants.values[vm.const_index++];
                push(vm, constant);
                printValue(constant);
                break;
            }
            case OP_ADD:{
                auto output = pop(vm) + pop(vm);
                push(vm, output);
                break;
            }
            case OP_SUBTRACT: {
                auto b = pop(vm);
                auto a = pop(vm);
                auto result = a -b;
                push(vm, result);
                break;
            }
            case OP_MULTIPLY: {
                auto result = pop(vm) * pop(vm);
                push(vm, result);
                break;
            }
            case OP_DIVIDE: {
                auto b = pop(vm);
                auto a = pop(vm);
                auto result = a /b;
                push(vm, result);
                break;
            }
            case OP_NEGATE: {
                auto result = - 1 * pop(vm);
                push(vm, result);
                break;
            }
            default:{
                break;
                
            }
        }

    }
    return InterpretResult::INTERPRET_OK;
}
InterpretResult interpret(VM& vm, Chunk& chunk){
    vm.chunk = chunk;
    vm.ip_index = 0;
    vm.const_index = 0;
    return run(vm);
}


void initVM(VM &vm){
    resetStack(vm);
}

}
