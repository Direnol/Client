#include "Client.h"
Client::Client(char *ip, uint16_t port)
{
    addr.sin_family = AF_INET;
    addr.sin_port = htons(port);
    addr.sin_addr.s_addr = inet_addr(ip);
    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (connect(sock, (sockaddr *) &addr, sizeof(addr)) < 0) {
        perror(nullptr);
        exit(errno);
    }
    work = true;
    std::cout << "Client connect to " << ip << ':' << port << std::endl;
}

Client::~Client()
{
}
void Client::SendMsg()
{
    std::string buf;
    buf.reserve(BUF_SIZE);
    while (work) {
        std::cout << "Enter message" << std::endl;
        std::getline(std::cin, buf);
        if (buf == "@EQXUIITT@") break;
        if (send(this->sock, buf.data(), buf.size(), 0) < 0) {
            if (errno == EBADF) break;
            perror(nullptr);
            work = false;
        }
    }

}
void Client::Disconnect()
{
    std::cout << "Client is finished" << std::endl;
    this->work = false;
    close(this->sock);
}


