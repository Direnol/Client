#include <csignal>
#include "Client.h"

Client *client = nullptr;
void closeClient(int sig)
{
    client->Disconnect();
    client->~Client();
}

int main(int argc, char **argv)
{
    if (argc != 3) {
        fprintf(stderr, "Use \"%s ip port\"\n", argv[0]);
        return EXIT_FAILURE;
    }
    signal(SIGINT, closeClient);
    client = new Client(argv[1], static_cast<uint16_t>(atoi(argv[2])));
    client->SendMsg();
    delete(client);
    return 0;
}

