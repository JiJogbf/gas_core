#pragma once

#include "types.hpp"
#include "obj.hpp"

/**
 * @brief string type implementation
*/
namespace gas{
    class str: public obj{
    private:
        char_p _buffer;
        u64    _cap;

        /**
         * @brief ctor with specified buffer and 
         *  caption
        */
        str(char_p buffer, u64 cap);
    public:       
        /**
         * @brief default ctor
        */
        str();
        
        /**
         * @brief ctor with c_str
        */
        str(char_cp cstr);

        /**
         * @brief ctor with c_str
        */
        str(char c, u64 count);

        /**
         * @brief copy ctor
        */
        str(const str& s);

        /**
         * @brief dtor
        */
        ~str();

        /**
         * @brief assignment operator overloading
        */
        str& operator=(const str& s);
        
        /**
         * @brief assignment operator overloading
        */
        str& operator+=(const str& appendable);

        /**
         * @brief concatination operation
        */
        friend str operator+(const str& first, const str& second);

        /**
         * @brief replacing part of string 
         * 
         * @param index position where start replacing
         * @param s text to place at index
        */
        str& replace(i64 index, const str& s);

        /**
         * @brief replacing part of string from begining
         * 
         * @param s text to place at index
        */
        str& replace(const str& s);

        /**
         * @brief converting this object to string
         * 
         * for this class will return simple copy of 
         * this object.
        */
        str* to_str() override;

        /**
         * @brief access to string buffer in object 
        */
        char_cp content()const;

        /**
         * @brief access to length of content
        */
        u64 length() const;       

        /**
         * @brief capacity
        */
        u64 cap() const;
    };    

    /**
     * @brief equal  
    */
    bool operator==(const str& left,const str& right);

    /**
     * @brief not equal
    */
    bool operator!=(const str& left, const str& right);

    /**
     * @brief left less than right
    */
    bool operator<(const str& lhs, const str& rhs);
    
    /**
     * @brief left greater than right
    */
    bool operator>(const str& lhs, const str& rhs);    
    
    /**
     * @brief left less or equal right
    */
    bool operator>=(const str& lhs, const str& rhs);
 
    /**
     * @brief left greater or equal right
    */
    bool operator<=(const str& lhs, const str& rhs);
}