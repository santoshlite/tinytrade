#include <iostream>
#include <boost/beast/core.hpp>
#include <boost/beast/websocket.hpp>
#include <string>
#include <thread>
#include "fake_orders.hpp"

int main() {
    std::cout << "Welcome to tinytrade!\n";
    for(int i = 0; i < 10; i++){
        string order = build_an_order();
        std::cout << order << "\n";
    }
    return 0;
}

