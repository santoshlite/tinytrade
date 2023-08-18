#include <iostream>
#include <string>
#include <thread>
#include "fake_orders.hpp"
#include "orders.pb.h"

int main() {
    std::cout << "Welcome to tinytrade client!\n";
    for(int i = 0; i < 10; i++){
        std::cout << gen_uuid() << "\n";
    }
    return 0;
}

