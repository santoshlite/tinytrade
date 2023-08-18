#include <iostream>
#include <string>
#include <thread>
#include "fake_orders.hpp"
#include "orders.pb.h"

int main() {
    std::cout << "Welcome to tinytrade client!\n";
    for(int i = 0; i < 10; i++){
        order_types::LimitOrder dummy_order = build_an_order();
        std::cout << "== ORDER DETAILS =="<<"\n";
        std::cout << "ORDER ID: " << dummy_order.order_id() << "\n";
        std::cout << "USER ID: " << dummy_order.user_id() << "\n";
        std::cout << "ORDER TYPE: " << dummy_order.order_type() << "\n";
        std::cout << "UNIT PRICE: " << dummy_order.unit_price() << "\n";
        std::cout << "NUM SHARES: " << dummy_order.num_shares() << "\n";
        std::cout << "PARTIAL FILLS: " << dummy_order.partial_fill() << "\n";
        std::cout << "EXPIRE TIME: " << dummy_order.expire_time() << "\n";
    }
    return 0;
}

