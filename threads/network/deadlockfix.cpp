#include <iostream>
#include <thread>
#include <mutex>

using namespace std;


mutex mtx1;
mutex mtx2;

void threadFunc1() {

    lock(mtx1, mtx2);

    lock_guard<mutex> lock1(mtx1, adopt_lock);
    lock_guard<mutex> lock2(mtx2, adopt_lock);

    cout << "Thread 1: locked mtx1 and mtx2" << endl;

    this_thread::sleep_for(chrono::milliseconds(100));


}

void threadFunc2() {

    lock(mtx1, mtx2);

    lock_guard<mutex> lock1(mtx1, adopt_lock);
    lock_guard<mutex> lock2(mtx2, adopt_lock);

    cout << "Thread 2: locked mtx1 and mtx2" << endl;


    this_thread::sleep_for(chrono::milliseconds(100));


}

int main() {

    thread t1(threadFunc1);
    thread t2(threadFunc2);

    t1.join();
    t2.join();

    return 0;
}
