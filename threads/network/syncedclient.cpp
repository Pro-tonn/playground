#include <iostream>
#include <cstring>
#include <unistd.h>
#include <arpa/inet.h>
#include <thread>
#include <vector>
#include <mutex>

using namespace std;

mutex cout_mutex;  // Mutex for synchronizing access to cout

void run_client(int id) {
    int sock = 0;
    struct sockaddr_in serv_addr;

    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        {
            lock_guard<mutex> lock(cout_mutex);
            cout << "Socket creation error for client " << id << endl;
        }
        return;
    }

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(12345);

    if (inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr) <= 0) {
        {
            lock_guard<mutex> lock(cout_mutex);
            cout << "Invalid address/ Address not supported for client " << id << endl;
        }
        return;
    }

    if (connect(sock, (struct sockaddr*)&serv_addr, sizeof(serv_addr)) < 0) {
        {
            lock_guard<mutex> lock(cout_mutex);
            cout << "Connection Failed for client " << id << endl;
        }
        return;
    }

    string message = "Hello from client " + to_string(id) + "\n";
    send(sock, message.c_str(), message.length(), 0);

    char buffer[1024] = {0};
    read(sock, buffer, 1024);

    {
        lock_guard<mutex> lock(cout_mutex);
        cout << "Client " << id << " received: " << buffer << endl;
    }

    close(sock);
}

int main() {
    const int num_clients = 100;
    vector<thread> clients;

    for (int i = 1; i <= num_clients; ++i) { // Start from 1 instead of 0
        clients.emplace_back(run_client, i);
    }

    for (auto& client : clients) {
        client.join();
    }

    return 0;
}
