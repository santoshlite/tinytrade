#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <filesystem>
#include <ios>
#include "send.hpp"
#include "orders.pb.h"

int main() {
    std::cout << "Welcome to tinytrade client!\n";

    std::ifstream fin;

    fin.open("../../client/fake_data.csv", std::ios::in);

    if (!fin.is_open()) {
        std::cerr << "Error opening file." << std::endl;
    }

    std::vector<std::string> row;
    std::string line, word;
    while (getline(fin, line)) {
        row.clear();
        word.clear();
        std::stringstream iss(line);
        while(getline(iss, word, ',')){
            row.push_back(word);
        }
        orders::Message m;
        m.set_order_id(static_cast<uint32_t>(std::stoul(row[0])));
        m.set_user_id(static_cast<uint32_t>(std::stoul(row[1])));
        m.set_stock_id(static_cast<uint32_t>(std::stoul(row[2])));
        m.set_event_type(static_cast<uint32_t>(std::stoul(row[3])));
        m.set_num_shares(static_cast<uint32_t>(std::stoul(row[4])));
        m.set_unit_price(static_cast<uint32_t>(std::stoul(row[5])));
        m.set_order_type(stoi(row[6]));
        send(m);
    }
        /*
        row.clear();
        getline(fin, line);
        std::stringstream s(line);
        while (getline(s, word, ',')){
            row.push_back(word);
        }
        std::cout << "ROW: " << row[0] << std::endl;
        orders::Message m;
        m.set_order_id(stoi(row[0]));
        m.set_user_id(stoi(row[1]));
        m.set_order_id(stoi(row[2]));
        m.set_user_id(stoi(row[3]));
        m.set_stock_id(stoi(row[4]));
        m.set_event_type(stoi(row[5]));
        m.set_unit_price(stoi(row[6]));
        m.set_num_shares(stoi(row[7]));
        m.set_order_type(stoi(row[8]));
        send(m);
        */
    fin.close();
    return 0;
}

