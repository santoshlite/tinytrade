#include <iostream>
#include <random>
#include <boost/uuid/uuid.hpp>
#include <boost/uuid/uuid_generators.hpp>
#include <boost/uuid/uuid_io.hpp>
#include <boost/lexical_cast.hpp>
#include "classes.hpp"
using namespace std;
namespace boost_uuid = boost::uuids;

Order build_an_order(string message){
  Order order;
  char order_type_options[3] = {'B', 'S', 'C'};
  char order_class_options[3] = {'M', 'L'};
  bool partial_fill_allowed_options[2] = {true, false};

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


string gen_uuid(){
    string uuid_str = boost::lexical_cast<std::string>(boost::uuids::random_generator()());
    return uuid_str;
}