namespace gas{

template<class T>
ptr<T>::ptr(T* value): _value(value), _ref_count(1){}

template<class T>
ptr<T>::ptr(const ptr<T>& value): _value(value._value), _ref_count(value._ref_count + 1){}

template<class T>
ptr<T>::~ptr(){
    if(_ref_count > 0){
        _ref_count--;
    }
    if(_ref_count == 0){
        delete _value;
    }
    _value = nullptr;
}

template<class T>
ptr<T>& ptr<T>::operator=(ptr<T>& p){
    if(this != &p){
        _ref_count = ++p._ref_count;
        _value = p._value;
    }
    return *this;
}

template<class T>
T& ptr<T>::operator*(){
    return *_value;
}

template<class T>
T* ptr<T>::operator->(){
    return _value;
}

// template<class T>
// str* ptr<T>::to_str(){
//     // @todo: as soon as posible we
//     // should make formated string construction
//     return new str("");
// }

template<class T>
ptr<T> make_ptr(T* p){
    return ptr<T>(p);
}

}