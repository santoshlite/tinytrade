#pragma once

#include <iostream>
#include <deque>
#include <queue>
#include <string>

using namespace std;

class Order {
public:
    string order_id;
    long customer_id;
    long stock_id;
    char order_type; // B, S, or C
    double unit_price;
    int num_shares;
    bool partial_fill_allowed;
    int expire_time; // in minutes
    time_t timestamp;
};


class buy_comparator {
    public:
       bool operator()(Order a, Order b){
           if(a.unit_price > b.unit_price){
               return true;
           }
           return false;
      }
};

class sell_comparator {
    public:
       bool operator()(Order a, Order b){
           if(a.unit_price < b.unit_price){
               return true;
           }
           return false;
      }
};

// USE MUTEX for the queues
class OrderBook {  
    public:
        long stock_id;
        priority_queue<Order, deque<Order>, buy_comparator> buy_limit_orders;
        priority_queue<Order, deque<Order>, sell_comparator> sell_limit_orders;
        std::queue<Order> cancel_limit_orders;
};

class OrderResult {  
    public:
        long order_id;
        long customer_id;
        time_t timestamp;
        int status_code;
        std::string status_message;
        long num_shares_filled;
};