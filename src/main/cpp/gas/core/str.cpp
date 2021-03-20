#include "str.hpp"

#include <cstring>

namespace gas{
namespace core{

str::str(): str(nullptr){}

str::str(char_p buffer, u64 cap): _buffer(buffer), _cap(cap) {}

str::str(char_cp cstr): _buffer(nullptr), _cap(0){
    if(cstr != nullptr){
        u64 sz = strlen(cstr);
        if(sz <= 0){
            sz = 0;
            _cap = sz;
            _buffer = new char_t[sz + 1];
            memset(_buffer, 0, _cap);
        }else{
            _cap = sz;
            _buffer = new char_t[sz + 1];
            memset(_buffer, 0, _cap);
            strcpy(_buffer, cstr);
        }
    }
}

str::str(char c, u64 count): str(new char[count], count + 1){
    memset(_buffer, 0, _cap);
    memset(_buffer, c, _cap - 1);
}

str::str(const str& s): str(s._buffer){}

str::~str(){
    delete[] _buffer;
    _cap = 0;
}

str& str::operator=(const str& s){
    if(this != &s){
        delete[] _buffer;
        _cap = 0;   
        u64 sz = strlen(s._buffer);
        _cap = sz;
        _buffer = new char_t[sz + 1];
        memset(_buffer, 0, _cap);
        strcpy(_buffer, s._buffer);
    }
    return *this;
}

str& str::operator+=(const str& appendable){
    u64 new_sz = length() + appendable.length();
    if(_cap < new_sz){
        _cap = new_sz;
        char_p buffer = new char[_cap + 1];
        memset(buffer, 0, _cap + 1);
        strcpy(buffer, _buffer);
        delete _buffer;
        _buffer = buffer;
    }
    strcat(_buffer, appendable._buffer);
    return *this;
}

str& str::replace(i64 index, const str& s){
    strncpy(_buffer + index, s._buffer, s.length());
    return *this;
}

str& str::replace(const str& s){
    replace(0, s);
    return *this;
}

ptr<str> str::to_str(){
    return ptr<str>(new str(*this));
}

char_cp str::content()const{
    if(_buffer == nullptr){
        return "";
    }else{
        return _buffer;
    }
}

u64 str::length() const{
    if(_buffer != nullptr){
        return strlen(_buffer);
    }else{
        return 0;
    }
}

u64 str::cap() const{
    return _cap;
}

// 

bool operator==(const str& left,const str& right){
    return strcmp(left.content(), right.content()) == 0;
}

bool operator!=(const str& left, const str& right){
    return !(left == right);
}

    bool operator<(const str& lhs, const str& rhs){ 
    return strcmp(lhs.content(),rhs.content()) < 0; 
}

bool operator>(const str& lhs, const str& rhs){ 
    return strcmp(lhs.content(),rhs.content()) > 0; 
}

bool operator>=(const str& lhs, const str& rhs){ 
    return strcmp(lhs.content(),rhs.content()) >= 0; 
}

bool operator<=(const str& lhs, const str& rhs){ 
    return strcmp(lhs.content(),rhs.content()) <= 0; 
}

str operator+(const str& first, const str& second){
    u64 tmp_cap = first.length() + second.length();
    char_p tmp_buffer = new char[tmp_cap];
    strcpy(tmp_buffer, first._buffer);
    strcat(tmp_buffer, second._buffer);
    str s(tmp_buffer, tmp_cap);
    return s;
}

}
}