#include <iostream>
#include <sys/socket.h>
#include <unistd.h>
#include <cstring>
#include <netinet/in.h>
#include <thread>

using namespace std;

void handle_client(int newSocket)
{
    char buffer[1024] = {0};
    int valRead = read(newSocket, buffer, 1024);
    if (valRead > 0)
    {
        cout << "Thread [ " << this_thread::get_id() << " ] received: " << buffer << endl;
        send(newSocket, buffer, valRead, 0);
    }

    close(newSocket);
}

int main()
{
    int server_fd = socket(AF_INET, SOCK_STREAM, 0);

    sockaddr_in address;

    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(8080);

    bind(server_fd, (struct sockaddr *)&address, sizeof(address));

    listen(server_fd, 10);

    while (true)
    {
        int addresslen = sizeof(address);
        int newSocket = accept(server_fd, (struct sockaddr *)&address, (socklen_t *)&addresslen);

        if (newSocket >= 0)
        {
            thread(handle_client, newSocket).detach();
        }
    }
    close(server_fd);
    return 0;
}