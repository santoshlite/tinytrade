#include <iostream>
#include <boost/beast/core.hpp>
#include <boost/beast/websocket.hpp>
#include <string>
#include <thread>
#include "fake_orders.hpp"

int main() {
    std::cout << "Welcome to tinytrade!\n";

    string a = gen_uuid();
    cout << "order id: " << a << endl;
    return 0;
}

