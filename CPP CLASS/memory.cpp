#include <iostream>

using namespace std;

class Sample {
public:
    int* data;

    Sample() {
        data = new int[10]; // Allocate memory for an array of 10 integers
        for (int i = 0; i < 10; ++i) {
            data[i] = i;
        }
    }

    void display() {
        for (int i = 0; i < 10; ++i) {
            cout << data[i] << " ";
        }
        cout << endl;
    }

    // Destructor is missing here, which should deallocate 'data'
};

int main() {
    Sample* sample = new Sample();
    sample->display();
    // Memory allocated to 'sample' and 'sample->data' is never freed
    return 0; // Memory leak here
}


// class Sample {
// public:
//     int* data;

//     Sample() {
//         data = new int[10]; // Allocate memory for an array of 10 integers
//         for (int i = 0; i < 10; ++i) {
//             data[i] = i;
//         }
//     }

//     void display() {
//         for (int i = 0; i < 10; ++i) {
//             cout << data[i] << " ";
//         }
//         cout << endl;
//     }

//     ~Sample() {
//         delete[] data; // Free the allocated array
//     }
// };

// int main() {
//     Sample* sample = new Sample();
//     sample->display();
//     delete sample; // Free the allocated object
//     return 0; // No memory leak here
// }
