//
//  memory.h
//  clox
//
//  Created by Bhupesh on 06.09.25.
//

namespace clox {

inline int growCapacity(const int old_cunk_capacity){
    return old_cunk_capacity < 8 ? 8 : old_cunk_capacity * 2;
}

}
