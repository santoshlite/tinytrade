#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <filesystem>
#include <ios>
#include <google/protobuf/arena.h>
#include "send.hpp"
#include "orders.pb.h"

int main() {
    std::cout << "Welcome to tinytrade client!\n";

    std::ifstream fin;

    fin.open("../../client/fake_data.csv", std::ios::in);

    if (!fin.is_open()) {
        std::cerr << "Error opening file." << std::endl;
    }
    
    google::protobuf::Arena arena;
    std::vector<std::string> row;
    std::string line, word;
    while (getline(fin, line)) {
        row.clear();
        word.clear();
        std::stringstream iss(line);
        while(getline(iss, word, ',')){
            row.push_back(word);
        }
        orders::Message* arena_message = google::protobuf::Arena::CreateMessage<orders::Message>(&arena);
        arena_message->set_order_id(static_cast<uint32_t>(std::stoul(row[0])));
        arena_message->set_user_id(static_cast<uint32_t>(std::stoul(row[1])));
        arena_message->set_stock_id(static_cast<uint32_t>(std::stoul(row[2])));
        arena_message->set_event_type(static_cast<uint32_t>(std::stoul(row[3])));
        arena_message->set_num_shares(static_cast<uint32_t>(std::stoul(row[4])));
        arena_message->set_unit_price(static_cast<uint32_t>(std::stoul(row[5])));
        arena_message->set_order_type(stoi(row[6]));
        if(arena_message->IsInitialized()){
            send(arena_message);
        }
    }

    fin.close();
    return 0;
}

