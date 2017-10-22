#ifndef CLIENT_CLIENT_H
#define CLIENT_CLIENT_H

#include <unistd.h>
#include <iostream>
#include <netinet/in.h>
#include <arpa/inet.h>

#define BUF_SIZE 512

class Client {
private:
    int sock;
    sockaddr_in addr;
    bool work;
public:
    Client(char *ip, uint16_t port);
    void SendMsg();
    void Disconnect();
    ~Client();

};

#endif //CLIENT_CLIENT_H
