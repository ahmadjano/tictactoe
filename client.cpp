#include <iostream>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

class Client
{
private:
    int clientSocket;
public:
    Client();
    ~Client();
    bool connectTo(std::string input);
};

Client::Client()
{
    this->clientSocket = socket(AF_INET, SOCK_STREAM, 0);
}

Client::~Client()
{
}

bool Client::connectTo(std::string input)
{
    std::cout << "Connecting to " << input;
    sockaddr_in address;
    address.sin_family = AF_INET;
    address.sin_port = htons(54321);
    
    // Convert input string address to s_addr type.
    inet_pton(AF_INET, input.c_str(), &(address.sin_addr));

    // Connect to the server.
    connect(this->clientSocket, (sockaddr*)&address, sizeof(address));

    return true;
}