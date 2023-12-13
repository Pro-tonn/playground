#include <iostream>
#include <vector>
#include <set>
#include <map>


using namespace std;

void demofunction(){
  cout<<"demofunction"<<endl;
}

int calculator(int input1, int input2){
  int result = input1 + input2; 
  return result;
}

int subtractor( int x, int input4){
  int result2 = x - input4;
  return result2;
}


void passbyvalue(int x){
  cout << x << endl;
  x = 10;
}

void passbyref(int& y){
  cout << y << endl;
  y = 10;
}

// int main() {
//   string name = "Drake";
    
//   int numbers[6] = {5,4,6,8,9,7};
//   // cout << numbers[5] << endl; 

//   string color[3] = {"red","blue","green"};
//   // cout << color[2] << endl;


//   // for (int i = 0; i < 5; i++){
//   //   cout<<"Hello there!"<<endl;
//   // }


//   // for (int i = 0; i < sizeof(numbers)/sizeof(int); i++){
//   //   cout << numbers[i] <<endl;
//   // }
//   // demofunction();

//   // cout<<calculator(900, 1000000)<<endl; // passing by value
//   // cout<<subtractor(10, 9)<<endl;

//   int mynum = 112; 

//   // passbyvalue(mynum);
//   // cout<<mynum<<endl;
//   // passbyref (mynum);
//   // cout <<mynum<<endl;

//   //int number [10] = {1,2,3,4,5,6,7,8,9,10};
//   vector<string> objects = {"food ", "tv ","water "};
//   vector<int> num = {1, 2, 3};
  
//   cout<<objects.size()<<endl;
  
//   objects.push_back("mouse");

//   for (int i = 0; i < objects.size(); i++){
//     cout<<objects[i];
//   }


//   cout<<objects.size()<<endl;
//   objects.pop_back();

//   cout<<objects.size()<<endl;

// }







// What does this code do
void func(int &i, int &j) {

  int temp = i;
  i = j;
  j = temp;

}

int ffgfgd (int inputa, int inputb){
  int resultg = inputa * inputb;
  return resultg;
}

int main() {
  // // **************************************************************** //
  // // ******************* PRACTICE PROBLEMS ************************** //
  // // **************************************************************** //
  
  // // Data Types -> Strings, Integers, Double, Bool
  // // Data container -> Vectors, Array
  // // Arithmetric: Addition (+), Subtraction (-), Multiplication (*), Division (/)
  
  
  // // create an array of size 5 called myObjects (you can have strings of any choice)
  // string myObjects[5] = {"burger","juice","fries","carrots","banana"};
  
  // // create a vector of numbers 10,20,30,40,50,60,70,80,90
//   vector<int> numberss = {10,20,30,40,50,60,70,80,90};
  
  // // add 100 to your numbers vector (without typing 100 into the original vector)
//   numberss.push_back(100);
  
  // // make a function that takes in two arguments (input) and multiplies both inputs
  
  // cout << ffgfgd (10,2); 
  
  
  
  // int a = 1;
  // int b = 3;

  // func(a, b);

  // cout << "A is " << a << "\n"; // 1
  // cout << "B is " << b << "\n"; // 3
  // cout << numberss.size();
  // cout << numberss[0]<<endl;
  // for (int i = 0; i< numberss.size(); i ++){
  //   cout<<numberss[i] <<endl; 
  // }


//   double demo = 1.5; // Double is similar to a decimal number
//   double demo2 = 10008.10;

//   bool demo3 = true;
  // if 1 + 2 = 3 true cout ("math is real")
  //   if false cout ("math is fake");

//   if (1+2 == 3) {
//     cout << "math is real"; 
//   }
//   else {
//     cout << "math is fake";
//   }

//   vector<int> test = {2,8,9,1};
//   set<int> demo = {2,8,9,1};

    // for (auto i : test){
    //     cout << i <<endl;
    // }

    // for (auto i : demo){
    //     cout << i <<endl;
    // }

    // demo.insert(3);
  
    // for (auto i : demo){
    //     cout << i <<endl;
    // }
  
}
