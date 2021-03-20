#include <iostream>

#include <gas\core\obj.hpp>

struct foo: public gas::obj{
    foo(){
        
    }
    ~foo() override {

    }

    void act(){
        std::cout << "working" << std::endl;
    }
};

int main(int argc, char** argv){
    foo o;
    o.act();
    return 0;
}