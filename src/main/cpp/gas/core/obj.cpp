#include "obj.hpp"

#include "str.hpp"

namespace gas{
    obj::~obj(){}

    str* obj::to_str(){
        return new str("obj: null");
    }
}
