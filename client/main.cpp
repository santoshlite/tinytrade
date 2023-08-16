#include <iostream>
#include <boost/beast/core.hpp>
#include <boost/beast/websocket.hpp>
#include <string>
#include <thread>
#include "fake_orders.hpp"
#include "order.pb.h"

int main() {
    std::cout << "Welcome to tinytrade client!\n";
    tutorial::Person p;
    for(int i = 0; i < 10; i++){
        std::cout << gen_uuid();
    }
    return 0;
}

