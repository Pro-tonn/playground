#include <iostream>
using namespace std;

struct Node{
    int data;
    Node *pNext;
};

Node *lastNode(Node *pHead){
    Node *pTemp = pHead;
    while (pTemp->pNext != NULL){
        pTemp = pTemp->pNext;
    }
    return pTemp;
}

bool isEmpty(Node *pHead){
    if (pHead == NULL){
        return true;
    }
    return false;
}



void append( Node *&pHead, int userInput)
{
    Node *newNode = new Node;
    newNode->data = userInput;
    newNode->pNext = NULL;
    Node *pTemp = pHead;

    if (pHead == NULL){
        pHead = newNode;
        return;
    }


    pTemp = lastNode(pHead);
    pTemp->pNext = newNode;

}



void display(Node *data){
    while (data != NULL){
        cout << data->data <<endl;
        data = data->pNext;
    }
}

int main(){
    Node *pHead = NULL;
    append(pHead, 1);
    append(pHead, 2);
    append(pHead, 3);
    append(pHead, 4);
    append(pHead, 5);
    display(pHead);
    return 0;
}