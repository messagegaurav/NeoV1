#include <iostream>
#include <arpa/inet.h>
#include <cstring>
#include <unistd.h>
#include <sys/socket.h>

using namespace std;

int main()
{
    int sock = socket(AF_INET, SOCK_STREAM, 0);

    sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(8080);

    // converting ip address from text to binary format
    inet_pton(AF_INET, "127.0.0.1", &server_addr.sin_addr.s_addr);

    // connect to the server

    connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr));

    // send read data
    const char *text = "KMG Client saying HELOOOOOOOOOOOOOO";
    send(sock, text, strlen(text), 0);

    // read data
    char buffer[1024] = {0};
    read(sock, buffer, 1024);
    cout << "Data received from Server: " << buffer << endl;

    // close the socket
    close(sock);
    return 0;
}