#include <iostream>
#include <thread>
#include <mutex>

using namespace std;


int counter = 0;

mutex mtx;


void increment(int numIncrements) {
    for (int i = 0; i < numIncrements; ++i) {
        mtx.lock(); 
        ++counter;  
        mtx.unlock(); 
    }
}

int main() {
    const int numIncrements = 100000;


    thread t1(increment, numIncrements);
    thread t2(increment, numIncrements);


    t1.join();
    t2.join();


    cout << "Final counter value: " << counter << endl;

    return 0;
}
