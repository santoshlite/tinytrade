#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <ios>
#include "send.hpp"
#include "orders.pb.h"

int main() {
    std::cout << "Welcome to tinytrade client!\n";
    std::fstream fin;

    fin.open("fake_data.csv", std::ios::in);

    std::vector<std::vector<std::string>> rows;
    std::vector<std::string> row;
    std::string line, word, temp;
    while (fin >> temp) {
        row.clear();
        getline(fin, line);
        std::stringstream s(line);
        while (getline(s, word, ',')){
            row.push_back(word);
        }

        orders::Message m;
        m.set_order_id(stoi(row[0]));
        //m.set_user_id(row[1]);
        //m.order_id = row[0];
        //m.user_id = row[1];
        //m.stock_id = row[2];
        //m.event_type = row[3];
        //m.unit_price = row[4];
        //m.num_shares = row[5];
        //m.order_type = row[6];

        send(m);

    }

    return 0;
}

