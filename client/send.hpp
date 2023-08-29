#include <iostream>
#include <string>
#include <grpc/grpc.h>
#include <grpcpp/create_channel.h>
#include <grpcpp/security/credentials.h>
#include "schema.pb.h"
#include "schema.grpc.pb.h"

void send(schema::ClientOrder m);
unsigned int checksum(const std::string& msg);

class Client final {
        public:
         Client(const std::shared_ptr<grpc::Channel>& channel)
                : stub_(schema::Router::NewStub(channel)){}

          void OrderRouter() {
                grpc::ClientContext context;
          }

        private: 
          std::unique_ptr<schema::Router::Stub> stub_;
};

unsigned int checksum(const std::string& msg){
        unsigned char result = 0;
        for(int i=0; i < msg.size(); i++){
           result = result + msg[i];
        }
        return result;
}

void send(const schema::ClientOrder* order){
        std::string serialized;
        std::cout << order->DebugString() << "\n";
        if(order->SerializeToString(&serialized)){
                uint checksumVal = checksum(serialized);
        } else{
                std::cerr << "Serialization failed" << std::endl;
        }

        grpc::CreateChannel("localhost:50051", grpc::InsecureChannelCredentials());


        
        // gRPC client logic
}
