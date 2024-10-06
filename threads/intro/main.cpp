#include <iostream>
#include <thread>
#include <vector>

using namespace std;  

// Function to be executed by each thread
void print_message(int thread_id) {
    cout << "Hello from thread " << thread_id << endl;
}

int main() {
    const int num_threads = 100;  // Number of threads to create
    vector<thread> threads;  // Vector to hold thread objects


    for (int i = 0; i < num_threads; ++i) {
        threads.emplace_back(print_message, i);
    }


    // for (auto& thread : threads) {
    //     thread.join();
    // }

    cout << "All threads have finished execution." << endl;
    return 0;
}
