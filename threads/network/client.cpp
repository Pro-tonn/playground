#include <iostream>
#include <cstring>
#include <unistd.h>
#include <arpa/inet.h>
#include <thread>
#include <vector>

using namespace std;

void run_client(int id) {
    int sock = 0;
    struct sockaddr_in serv_addr;

    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        cout << "Socket creation error" << endl;
        return;
    }

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(12345);

    if (inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr) <= 0) {
        cout << "Invalid address/ Address not supported" << endl;
        return;
    }



    if (connect(sock, (struct sockaddr*)&serv_addr, sizeof(serv_addr)) < 0) {
        cout << "Connection Failed" << endl;
        return;
    }

    string message = "Hello from client " + to_string(id) + "\n";
    send(sock, message.c_str(), message.length(), 0);

    char buffer[1024] = {0};
    read(sock, buffer, 1024);
    cout << "Client " << id << " received: " << buffer << endl;

    close(sock);
}

int main() {
    const int num_clients = 100;
    vector<thread> clients;

    for (int i = 0; i < num_clients; ++i) {
        clients.emplace_back(run_client, i);
    }

    for (auto& client : clients) {
        client.join();
    }

    return 0;
}
