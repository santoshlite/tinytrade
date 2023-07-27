#include <iostream>
#include <random>
#include <vector>
#include "classes.hpp"
using namespace std;

Order build_an_order(string message){
  Order order;
  order.order_id = 1;
  order.customer_id = 1;
  order.stock_id = 1;
  order.order_type = 'B';
  order.order_class = 'M';
  order.unit_price = 2.0;
  order.num_shares = 1;
  order.partial_fill_allowed = true;
  order.expire_time = 1;
  order.timestamp = 1;
  return order;
}


int num(){
  return 1;
}