#pragma once 

#include "ptr.hpp"

/**
 * @brief base class for all elements of this library
*/
namespace gas{
namespace core{

class str;

class obj{
public:
    /**
     * @brief dtor
    */
    virtual ~obj() = 0;

    /**
     * @brief converting this object 
     * to string representation
    */
    virtual ptr<str> to_str(); 
};

}
}
