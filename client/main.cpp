#include <iostream>
#include <string>
#include <thread>
#include "fake_orders.hpp"
#include "build/order.pb.h"

int main() {
    tutorial::Person p;
    p.set_name("jolly");
    std::cout << "Welcome to tinytrade client!\n";
    for(int i = 0; i < 10; i++){
        std::cout << p.name();
        std::cout << gen_uuid();
    }
    return 0;
}

