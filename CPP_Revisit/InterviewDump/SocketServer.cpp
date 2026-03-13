#include <iostream>
#include <sys/socket.h>
#include <cstring>
#include <netinet/in.h>
#include <unistd.h>

using namespace std;

int main()
{
    // creating socket
    int server_fd = socket(AF_INET, SOCK_STREAM, 0);

    // bind the socket to an ip address (family, address, port)
    sockaddr_in address;
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(8080);

    // bind it
    bind(server_fd, (struct sockaddr *)&address, sizeof(address));

    // listen to incoming connection
    listen(server_fd, 3);
    cout << "Server listening on port 8080...!!!" << endl;

    int addrlen = sizeof(address);
    int newSocket = accept(server_fd, (struct sockaddr *)&address, (socklen_t *)&addrlen);

    // read and send data
    char buffer[1024] = {0};
    read(newSocket, buffer, 1024);
    cout << "Client says: " << buffer << endl;

    const char *hello = "Hello from Server";
    // send data to client
    send(newSocket, hello, strlen(hello), 0);

    // close the socket
    close(newSocket);
    close(server_fd);
    return 0;
}
