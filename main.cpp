#include <iostream>
#include <boost/beast/core.hpp>
#include <boost/beast/websocket.hpp>
#include <string>
#include <thread>
#include "fake_orders.hpp"

int main() {
    std::cout << "Welcome to tinytrade!\n";
    std::cout << "A dark pool exchange.\n";

    int a = num();
    printf("a = %d\n", a);
    /*
    for (int i = 0; i < 100; i++) {
        cout << "order # " + std::to_string(i) << "\n";
    }
    */
    return 0;
}

