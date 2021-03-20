#include <iostream>

#include <gas\core\str.hpp>
#include <gas\core\obj.hpp>
#include <gas\core\ptr.hpp>

int main(int argc, char** argv){
    using namespace gas::core;
    ptr<str> s(new str("hello world!"));
    std::cout << s->content() << std::endl;
    return 0;
}