#include <iostream>
#include <thread>
#include <mutex>
#include <cstring>
#include <unistd.h>
#include <arpa/inet.h>

using namespace std;

#define PORT 8080
#define MAX_CLIENTS 5

mutex mtx;  // Mutex to protect shared resources

// Function to handle each client in a separate thread
void handle_client(int new_socket) {
    char buffer[1024] = {0};
    string welcome_msg = "Welcome to the server!\n";

    // Send welcome message to client
    send(new_socket, welcome_msg.c_str(), welcome_msg.length(), 0);

    // Read message from client
    int valread = read(new_socket, buffer, 1024);

    // Protecting critical section with mutex
    mtx.lock();
    cout << "Client message: " << buffer << endl;
    mtx.unlock();

    // Send acknowledgment to client
    string reply = "Message received!\n";
    send(new_socket, reply.c_str(), reply.length(), 0);

    // Close the socket for this client
    close(new_socket);
}

int main() {
    int server_fd, new_socket;
    struct sockaddr_in address;
    int opt = 1;
    int addrlen = sizeof(address);

    // Creating socket file descriptor
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("Socket failed");
        exit(EXIT_FAILURE);
    }

    // Forcefully attaching socket to the port 8080
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))) {
        perror("setsockopt");
        exit(EXIT_FAILURE);
    }

    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    // Binding the socket to the port
    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0) {
        perror("Bind failed");
        exit(EXIT_FAILURE);
    }

    // Listen for up to MAX_CLIENTS connections
    if (listen(server_fd, MAX_CLIENTS) < 0) {
        perror("Listen");
        exit(EXIT_FAILURE);
    }

    cout << "Server is listening on port " << PORT << endl;

    while (true) {
        // Accept incoming client connections
        if ((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen)) < 0) {
            perror("Accept");
            exit(EXIT_FAILURE);
        }

        cout << "New client connected!" << endl;

        // Create a new thread for each client connection
        thread client_thread(handle_client, new_socket);
        client_thread.detach();  // Detach the thread so it runs independently
    }

    return 0;
}
