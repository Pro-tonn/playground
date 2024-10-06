#include <iostream>
#include <thread>
#include <vector>
#include <mutex>

using namespace std;

// Function to be executed by each thread
void print_message(int thread_id, mutex& mtx) {
    lock_guard<mutex> lock(mtx);  // Lock the mutex for the duration of this block
    cout << "Hello from thread " << thread_id << endl;
}

int main() {
    const int num_threads = 100;
    vector<thread> threads;  
    mutex mtx;  

    // Create and start threads
    for (int i = 0; i < num_threads; ++i) {
        threads.emplace_back(print_message, i, ref(mtx));
    }

    // Join threads to the main thread (wait for all to finish)
    for (auto& thread : threads) {
        thread.join();
    }

    cout << "All threads have finished execution." << endl;
    return 0;
}
