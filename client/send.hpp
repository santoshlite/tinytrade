#include <iostream>
#include <string>
#include "orders.pb.h"

void send(orders::Message m);

void send(orders::Message* m){
        std::cout << "== MESSAGE DETAILS =="<<"\n";
        std::cout << m->DebugString() << "\n";
}