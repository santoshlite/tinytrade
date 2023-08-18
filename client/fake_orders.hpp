#pragma once

#include <iostream>
#include <random>
#include <boost/uuid/uuid_generators.hpp>
#include <boost/uuid/uuid_io.hpp>
#include <boost/lexical_cast.hpp>
#include <random>
#include "orders.pb.h"

std::string gen_uuid(){
    std::string uuid_str = boost::lexical_cast<std::string>(boost::uuids::random_generator()());
    return uuid_str;
}

order_types::LimitOrder build_an_order(){
  std::random_device rd;
  std::uniform_int_distribution<int> dist(10000, 10000000);
  order_types::LimitOrder order;
  order.set_order_id(gen_uuid());
  order.set_user_id(1232);
  order.set_stock_id(999999999); // fixed
  order.set_order_type(order_types::OrderType::BUY);
  order.set_num_shares(10000);
  order.set_partial_fill(true);
  order.set_expire_time(1000);
  return order;
}