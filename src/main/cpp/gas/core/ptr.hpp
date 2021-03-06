#ifndef GAS_PTR_T_HPP_27012021_235423
#define GAS_PTR_T_HPP_27012021_235423

#include "types.hpp"

namespace gas{
namespace core{

/**
 * @brief simple smart pointer 
 *  generic implementation
*/
template<class T>
class ptr{
private:
    T*  _value;
    i64 _ref_count;
public:
    /**
     * @brief ctor
    */
    ptr(T* value);
    
    /**
     * @brief ctor for copy, wich 
     *  will increase reference count in 
     *  every object
    */
    ptr(const ptr<T>& value);

    /**
     * dtor
    */
    ~ptr();

    /**
     * assignment operator for smart ptr
    */
    ptr<T>& operator=(ptr<T>& p);

    /**
     * dereference operator implementation 
    */
    T& operator*();

    /**
     * member access operator
    */
    T* operator->();
};

template<class T>
ptr<T> make_ptr(T* p);

}
}

#include "ptr_impl.hpp"

#endif 
