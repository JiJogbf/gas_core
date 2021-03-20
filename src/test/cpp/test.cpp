#include <iostream>

#include <gas\core\str.hpp>
#include <gas\core\obj.hpp>

struct foo: public gas::obj{
    foo(){
        
    }
    ~foo() override {

    }

    void act(){
        gas::str* s = to_str();
        std::cout << "working: " << s->content() << std::endl;
        delete s;
    }
};

int main(int argc, char** argv){
    foo o;
    o.act();
    return 0;
}