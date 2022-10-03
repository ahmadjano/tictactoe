#include <iostream>
#include "server.cpp"
#include "client.cpp"

class tictactoe
{
private:
    
public:
    tictactoe();
    ~tictactoe();
    void prompt();
};

tictactoe::tictactoe()
{
}

tictactoe::~tictactoe()
{
}

void tictactoe::prompt()
{
    std::cout << "Welcome to TicTacToe version 1.0.0" << std::endl;
    std::cout << "Written by Ahmad & Bruno with c++" << std::endl << std::endl;

    char input;

    do
    {
        std::cout << "Choose an option (1-2):" << std::endl;
        std::cout << "1. Start a new game." << std::endl;
        std::cout << "2. Connect to an existing game." << std::endl;
        std::cin >> input;
    }
    while (input != '1' && input != '2');
    
    if (input == '1')
    {
        Server server;
        server.start();
    }
    else
    {
        std::string input;
        //do
        {
            std::cout << "Enter the IP address of the host: " << std::endl;
            std::cin >> input;
        } //while ();
        
        Client client;
        client.connectTo(input);

    }
}
