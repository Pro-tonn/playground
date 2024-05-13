#include <iostream>
#include <vector>
using namespace std;

class Node {
private:
    int size;

public:
    int data;
    Node* pNext;

    // Constructor with no parameters
    Node() {
        this->data = 0; // Initialize data to a default value (you can choose any default value)
        this->pNext = NULL;
        this->size = 0; // Initialize size to 0
    }

    // Constructor that takes a vector of integers
    Node(vector<int> data) {
        this->data = data[0]; // Initialize data with the first element of the vector
        this->pNext = NULL;
        this->size = 1; // Initialize size to 1

        Node* pTemp = this;

        for (int i = 1; i < data.size(); i++) {
            pTemp->pNext = new Node(data[i]); // Create a new node with the data[i] value
            pTemp = pTemp->pNext;
            size++;
        }
    }

    // Constructor that takes an integer
    Node(int data) {
        this->data = data;
        this->pNext = NULL;
        this->size = 1; // Initialize size to 1
    }

    // Append a new node with data to the end of the list
    void append(int data) {
        Node* newNode = new Node(data);
        Node* pTemp = this;

        while (pTemp->pNext != NULL) {
            pTemp = pTemp->pNext;
        }

        pTemp->pNext = newNode;
        size++;
    }

    // Get the size of the list
    int getSize() const { // Make the function const
        return this->size;
    }

    // Display the list
    const void display(){
        Node *pTemp = this;
        cout<<"{";
        while (pTemp != NULL){
            cout<<pTemp->data;
            string delimiter = (pTemp->pNext == NULL) ? "" : ", ";
            cout<<delimiter;
            pTemp = pTemp->pNext;
        }
        cout<<"}";
        cout<<endl;
    }

    // Destructor to free memory
    ~Node() {
        if (pNext != NULL) {
            delete pNext;
        }
    }
};


int main(){
    int x = 1;
    Node pHead = 1;
    pHead.append(2);
    pHead.append(3);
    pHead.append(4);
    // pHead.append(5);
    pHead.append(6);
    pHead.append(7);
    pHead.append(8);
    pHead.append(9);
    pHead.append(10);
    pHead.display();
    
    cout<< "The size is "<< pHead.getSize()<<endl; 



    // Vector to Linked List
    vector<int> myData = {1,2 ,3 , 4,5 ,6};
    Node LLvector(myData);
    cout<<"This LL vector is: "<<LLvector.getSize()<<endl;
    LLvector.display();



}
