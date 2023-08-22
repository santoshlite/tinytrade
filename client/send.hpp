#include <iostream>
#include <string>
#include "orders.pb.h"

void send(orders::Message m);
unsigned int checksum(const std::string& msg);

unsigned int checksum(const std::string& msg){
        unsigned char result = 0;
        for(int i=0; i < msg.size(); i++){
           result = result + msg[i];
        }
        return result;
}

void send(const orders::Message* m){
        std::string serialized;
        std::cout << "== MESSAGE DETAILS =="<<std::endl;
        std::cout << m->DebugString() << "\n";
        if(m->SerializeToString(&serialized)){
                std::cout << "checksum: " << checksum(serialized) << std::endl;
        } else{
                std::cerr << "Serialization failed" << std::endl;
        }
        
        // gRPC client logic
}