#pragma once

#include <iostream>
#include <random>
#include <string>
#include <boost/uuid/uuid_generators.hpp>
#include <boost/uuid/uuid_io.hpp>
#include <boost/lexical_cast.hpp>
#include "orders.pb.h"

std::string gen_uuid();
order_types::LimitOrder build_an_order();

std::string gen_uuid(){
    std::string uuid_str = boost::lexical_cast<std::string>(boost::uuids::random_generator()());
    return uuid_str;
}

order_types::LimitOrder build_an_order(){
  std::random_device rd;
  std::mt19937 generator(rd()); 
  std::uniform_int_distribution<int> dist(10000, 10000000);
  std::uniform_real_distribution<double> price_dist(9.85, 10.25); // fake price
  order_types::LimitOrder order; 
  order.set_order_id(gen_uuid());
  order.set_user_id(dist(generator)%10000);
  order.set_stock_id(999999999); // fixed
  double price = std::round(price_dist(generator)*100)/100;
  order.set_unit_price(price);
  if (dist(generator)%2 == 0) {
        order.set_order_type(order_types::OrderType::BUY);
  } else {
        order.set_order_type(order_types::OrderType::SELL);
  }
  order.set_num_shares(dist(generator)%10000000+10000);
  order.set_partial_fill(dist(generator)%2);
  order.set_expire_time(dist(generator)%1440+10);
  return order;
}