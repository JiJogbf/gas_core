#pragma once 

/**
 * @brief base class for all elements of this library
*/
namespace gas{
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
        virtual str* to_str(); 
    };
}
