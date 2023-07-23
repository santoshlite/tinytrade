#include <iostream>
#include <queue>

#ifndef CLASSES
#define CLASSES

class Order {
public:
    long customer_id;
    long stock_id;
    char order_type; // B, S, or C
    char order_class; // M, L, or S
    double unit_price;
    int num_shares;
    bool partial_fill_allowed;
    int expire_time; // in minutes
};

// USE LOCK FREE QUEUE later
class OrderBook {  
    public:
        long stock_id;
        std::queue<Order> buy_market_orders;
        std::queue<Order> sell_market_orders;
        std::queue<Order> buy_limit_orders;
        std::queue<Order> sell_limit_orders;
        std::queue<Order> cancel_limit_orders;
};

#endif