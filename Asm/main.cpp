#include <iostream>
using namespace std;


// int main() {
//     int a = 5;
//     int b = 10;
//     int sum = a + b;

//     cout << "Sum: " << sum << endl;

// }


// int main() {
//     int num1 = 10;
//     int num2 = 20;

//     int sum = num1 + num2;
//     cout << "Sum: " << sum << endl;

//     int product = num1 * num2;
//     cout << "Product: " << product << endl;

//     int quotient = num2 / num1;
//     cout << "Quotient: " << quotient << endl;

//     int remainder = num2 % num1;
//     cout << "Remainder: " << remainder << endl;

//     return 0;
// }


// int main() {
//     double length, width, area;

//     cout << "Enter length of the rectangle: ";
//     cin >> length;

//     cout << "Enter width of the rectangle: ";
//     cin >> width;

//     area = length * width;

//     cout << "Area of the rectangle with length " << length << " and width " << width << " is " << area << endl;

//     return 0;
// }


// int main(){
    
//     const int N = 1000000000;
//     long long sum = 0;

//     for (int i = 1; i <= N; ++i) {
//         sum += i;
//     }

//     cout << "Sum: " << sum << endl;

//     return 0;
// }


int main() {
    const long long N = 1000000000;
    long long sum = N * (N + 1) / 2;

    cout << "Sum: " << sum << endl;

    return 0;
}


// 10 seconds for python