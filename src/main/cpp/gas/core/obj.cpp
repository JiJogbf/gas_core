#include "obj.hpp"

#include "str.hpp"
#include "ptr.hpp"

namespace gas{
    obj::~obj(){}

    ptr<str> obj::to_str(){
        return ptr<str>(new str("obj: null"));
    }
}
