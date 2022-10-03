#include <iostream>
#include <sys/socket.h>
#include <netinet/in.h> // Used to initialize address structs (sockaddr_in)
#include <unistd.h> // Used to close sockets with close().

class Server
{
private:

    int listeningSocket;
    sockaddr_in address;
public:
    Server();
    ~Server();
    bool start();
    void stop();
};

Server::Server()
{
    this->listeningSocket = socket(AF_INET, SOCK_STREAM, 0);
    // AF_INET being IPv4.
}

bool Server::start()
{
    std::cout << "Starting new tictactoe server..." << std::endl;
    
    sockaddr_in address;
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(54321);
    
    if (listeningSocket < 0)
    {
        std::cerr << "Error occured whilst attempting to create a listening socket!" << std::endl;
        return false;
    }
    
    // Bind the listening socket to any IP address on port 54321
    if(bind(listeningSocket, (sockaddr*)&address, sizeof(address)) < 0)
    {
        std::cerr << "Failed binding listening socket!" << std::endl;
        return false;
    }

    // Start listening
    listen(listeningSocket, 10);

    std::cout << "Server listening for connections..." << std::endl;

    // Start acception a connection from the client
    if (accept(listeningSocket, (sockaddr*)&address, (socklen_t*)sizeof(address)) < 0)
    {
        std::cerr << "Failed preparing to accept connections!";
        return false;
    }

    std::cout << "All good!" << std::endl;
}

void Server::stop()
{
    close(this->listeningSocket);
    shutdown(this->listeningSocket, SHUT_RDWR);
}

Server::~Server()
{
}
