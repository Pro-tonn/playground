#include <iostream>
#include "list.h"
#include <vector>
#include <ctime>


using namespace std;


void measureTimeElapsed(function<void()> sortFunction) {
    auto start = chrono::system_clock::now();
    auto start_time = chrono::system_clock::to_time_t(start);

    // Call the sorting function
    sortFunction();

    auto stop = chrono::system_clock::now();
    auto stop_time = chrono::system_clock::to_time_t(stop);

    // Prepare for formatted output
    char start_str[100];
    char stop_str[100];
    strftime(start_str, sizeof(start_str), "%F %T", localtime(&start_time));
    strftime(stop_str, sizeof(stop_str), "%F %T", localtime(&stop_time));

    // Calculate duration in different units
    auto duration_microseconds = chrono::duration_cast<chrono::microseconds>(stop - start);
    auto duration_milliseconds = chrono::duration_cast<chrono::milliseconds>(stop - start);
    auto duration_seconds = chrono::duration_cast<chrono::seconds>(stop - start);




    // Print duration in various units
    cout << "Time taken by function: "
         << duration_seconds.count() << " seconds ("
         << duration_milliseconds.count() << " milliseconds, "
         << duration_microseconds.count() << " microseconds)." << endl;
}

void tmeasureTimeElapsed(function<void()> sortFunction) {
    atomic<bool> finished{false};

    // Timer thread for reporting elapsed time
    thread timer([&finished]() {
        auto start = chrono::high_resolution_clock::now();
        while (!finished) {
            this_thread::sleep_for(chrono::seconds(2)); // Check every 2 seconds
            auto now = chrono::high_resolution_clock::now();
            auto elapsed = chrono::duration_cast<chrono::seconds>(now - start).count();
            if (!finished) {
                cout << "Elapsed time: " << elapsed << " seconds" << endl;
            }
        }
    });

    // Sorting thread
    thread sorter([&]() {
        sortFunction();
        finished = true; // Signal the timer thread to finish
    });

    // Wait for the sorting to finish
    sorter.join();
    // Ensure the timer thread exits
    timer.join();

    // Final report
    cout << "Sorting completed." << endl;
}

int main()
{

    List<int> test;


    // // append random number in the list
    for (int i = 0; i < 100000; i++){
        test.append(rand() % 100);
    }



    // test.items();
    // cout<<"\n\n";
    measureTimeElapsed([&]() { test.qsort(); });
    // cout<<"\n\n";
    // test.items();
    // cout<<"\n\n";
    // cout<<test.size()<<endl;


// IncognitoZach algo - 100000 - 40 seconds
// Bbsort algo - 100000 - 16 seconds
// bsort algo - 100000 - 23 seconds
// ssort algo - 100000 - 7 seconds
// isort algo - 100000 - 4 seconds
// msort algo - 100000 - 0 seconds
// qsort algo - 100000 - 0 seconds
}
