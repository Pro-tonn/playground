#include <iostream>
#include <thread>
#include <mutex>

using namespace std;


mutex mtx1;
mutex mtx2;

void threadFunc1() {

    mtx1.lock();
    cout << "Thread 1: locked mtx1" << endl;


    this_thread::sleep_for(chrono::milliseconds(100));


    cout << "Thread 1: waiting for mtx2" << endl;
    mtx2.lock();
    cout << "Thread 1: locked mtx2" << endl;


    mtx2.unlock();
    mtx1.unlock();
}

void threadFunc2() {

    mtx2.lock();
    cout << "Thread 2: locked mtx2" << endl;


    this_thread::sleep_for(chrono::milliseconds(100));


    cout << "Thread 2: waiting for mtx1" << endl;
    mtx1.lock();
    cout << "Thread 2: locked mtx1" << endl;


    mtx1.unlock();
    mtx2.unlock();
}

int main() {

    thread t1(threadFunc1);
    thread t2(threadFunc2);


    t1.join();
    t2.join();

    return 0;
}
