#include <iostream>
#include <string>
#include <chrono>
#include <grpc/grpc.h>
#include <grpcpp/security/server_credentials.h>
#include <grpcpp/server.h>
#include <grpcpp/server_builder.h>
#include <grpcpp/server_context.h>
#include "schema.pb.h"
#include "schema.grpc.pb.h"


class RouterImpl final : public schema::Router::Service { 
     public:
        grpc::Status OrderRouter(grpc::ServerContext* context,
                        grpc::ServerReaderWriter<schema::ServerResponse, schema::ClientOrder>* stream) 
        override {
                schema::ClientOrder order;
                while (stream->Read(&order)) {
                schema::ServerResponse response;
                response.set_order_id(order.order_id());
                response.set_status(0);
                response.set_remaining_shares(order.num_shares());
                auto currentTime = std::chrono::high_resolution_clock::now();
                auto currentTimeMicros = time_point_cast<std::chrono::microseconds>(currentTime).time_since_epoch().count();
                response.set_timestamp(static_cast<uint64_t>(currentTimeMicros));
                stream->Write(response);
                }
                return grpc::Status::OK;
    }
};

void RunServer() {
  std::string server_address("0.0.0.0:50051");
  RouterImpl service;
  grpc::ServerBuilder builder;
  builder.AddListeningPort(server_address, grpc::InsecureServerCredentials());
  builder.RegisterService(&service);
  std::unique_ptr<grpc::Server> server(builder.BuildAndStart());
  std::cout << "Server listening on " << server_address << std::endl;
  server->Wait();
};

int main() {
    std::cout << "Welcome to tinytrade!!\n";
    RunServer();
    return 0;
}

