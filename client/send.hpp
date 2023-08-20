#include <iostream>
#include <string>
#include "orders.pb.h"

void send(orders::Message m);

void send(orders::Message m){
        std::cout << "== MESSAGE DETAILS =="<<"\n";
        std::cout << "ORDER ID: " << m.order_id() << "\n";
        std::cout << "USER ID: " << m.user_id() << "\n";
        std::cout << "STOCK ID: " << m.stock_id() << "\n";
        std::cout << "EVENT TYPE: " << m.event_type() << "\n";
        std::cout << "UNIT PRICE: " << m.unit_price() << "\n";
        std::cout << "NUM SHARES: " << m.num_shares() << "\n";
        std::cout << "ORDER TYPE: " << m.order_type() << "\n";
}