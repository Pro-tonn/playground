#pragma once

#include <iostream>
#include <exception>
#include <stdexcept>

#include <chrono>
#include <functional>
#include <thread>
#include <atomic>
 

using namespace std;

template<typename T>


class List
{
    private:
        T* _content; 
        int _size;

        T * _returnArray(){
            return _content;
        }

        int _findAllWithout(T value){
            int count = 0;
            for (int i = 0; i < _size; i++){
                if (_content[i] == value){
                    continue;
                }
                count++;
            }
            return count + 1;
        }

    public:
        List(){
            _content = new T[4];
            _size = 0;
        }

        int size() const{
            return this->_size;
        }

        T& operator[] (int value) const{
            return _content[value];
        }

        void items(){ // Maybe change to store in buffer or sstream and later printed
            cout<<"[";
            for (int i = 0; i < _size; i++){
                if (i == _size-1){
                    cout<<_content[i];
                    continue;
                }
                cout<<_content[i]<<", ";
            }
            cout<<"]"<<endl;
        }

        T& at(int value) const{
            if (value < 0 || value > _size){
                throw out_of_range("out of range");
            }

            return _content[value];
        }

        T& begin() const{
            if (_size <= 0)
                throw out_of_range("Empty list");
            return _content[0];
        }

        T& end() const{
            if (_size <= 0)
                throw out_of_range("Empty list");
            return _content[_size-1];
        }

        void append(T value){
            if (_size == 0){
                _content[0] = value;
                _size++;
            }
            else{
                T* temp = new T[_size+1];
                for (int i = 0; i < _size; ++i){
                    temp[i] = _content[i];
                }
                temp[_size] = value;
                _size++;
                delete [] _content;
                _content = temp;
            }
           
        }

        void remove(T value){
            _size = _findAllWithout(value);
            T* temp = new T[_size];
            int index = 0;
            int tSize = 0;

            for (int i = 0; i < _size; i++){
                if (_content[i] == value){
                    continue;
                }
                temp[index] = _content[i];
                tSize ++;
                index++;
            }
            delete [] _content;
            _content = temp;
            _size = tSize;
        }

        void clear(){
            delete[] _content;
            _size = 0;
            _content = new T[4];
        }

        void sort(){
            T temp;
            for(int j=0;j<_size;j++){
                for(int i=0; i<_size-1; i++){
                if(_content[i]>=_content[i+1]){
                    temp=_content[i+1];
                    _content[i+1]=_content[i];
                    _content[i]=temp;
                }
                }
            }
        }


        void bbsort(){ // Bubble sort
            for (int i = 0; i < _size; i++){
                for (int j = 0; j < _size; j++){
                    if (_content[i] < _content[j]){
                        T temp = _content[i];
                        _content[i] = _content[j];
                        _content[j] = temp;
                    }
                }
            }
        }

        void bsort() {
            for (int i = 0; i < _size - 1; i++) {
                bool swapped = false;
                for (int j = 0; j < _size - i - 1; j++) {
                    if (_content[j] > _content[j + 1]) {
                        T temp = _content[j];
                        _content[j] = _content[j + 1];
                        _content[j + 1] = temp;
                        swapped = true;
                    }
                }
                if (!swapped) break; // Stop if no swaps occurred, indicating the array is sorted.
            }
        }

        void ssort() {
            for (int i = 0; i < _size - 1; i++) {
                int minIndex = i;
                for (int j = i + 1; j < _size; j++) {
                    if (_content[j] < _content[minIndex]) {
                        minIndex = j;
                    }
                }
                if (minIndex != i) {
                    T temp = _content[i];
                    _content[i] = _content[minIndex];
                    _content[minIndex] = temp;
                }
            }
        }

        void isort() {
            for (int i = 1; i < _size; i++) {
                T key = _content[i];
                int j = i - 1;
                while (j >= 0 && _content[j] > key) {
                    _content[j + 1] = _content[j];
                    j = j - 1;
                }
                _content[j + 1] = key;
            }
        }

        void merge(T arr[], int l, int m, int r) {
            int n1 = m - l + 1;
            int n2 = r - m;
            T L[n1], R[n2];
            for (int i = 0; i < n1; i++)
                L[i] = arr[l + i];
            for (int j = 0; j < n2; j++)
                R[j] = arr[m + 1 + j];
            int i = 0, j = 0, k = l;
            while (i < n1 && j < n2) {
                if (L[i] <= R[j]) {
                    arr[k] = L[i];
                    i++;
                } else {
                    arr[k] = R[j];
                    j++;
                }
                k++;
            }
            while (i < n1) {
                arr[k] = L[i];
                i++;
                k++;
            }
            while (j < n2) {
                arr[k] = R[j];
                j++;
                k++;
            }
        }

        void mergeSort(T arr[], int l, int r) {
            if (l >= r) return; // Base case
            int m = l + (r - l) / 2; // Find the middle point
            mergeSort(arr, l, m);
            mergeSort(arr, m + 1, r);
            merge(arr, l, m, r); // Merge the sorted halves
        }

        void msort() {
            mergeSort(_content, 0, _size - 1);
        }



        int partition(T arr[], int low, int high) {
            T pivot = arr[high];
            int i = (low - 1);
            for (int j = low; j <= high - 1; j++) {
                if (arr[j] < pivot) {
                    i++;
                    T temp = arr[i];
                    arr[i] = arr[j];
                    arr[j] = temp;
                }
            }
            T temp = arr[i + 1];
            arr[i + 1] = arr[high];
            arr[high] = temp;
            return (i + 1);
        }

        void quickSort(T arr[], int low, int high) {
            if (low < high) {
                int pi = partition(arr, low, high);
                quickSort(arr, low, pi - 1);
                quickSort(arr, pi + 1, high);
            }
        }

        void qsort() {
            quickSort(_content, 0, _size - 1);
        }



};

template<typename T>
void measureTimeElapsed(function<void(vector<T>&)> sortFunction, vector<T>& data) {
    // Start timer
    auto start = chrono::high_resolution_clock::now();

    int prevData = data.size();
    // Call the sorting function
    sortFunction(data);
    
    // Stop timer
    auto stop = chrono::high_resolution_clock::now();

    // Calculate duration
    auto duration = chrono::duration_cast<chrono::microseconds>(stop - start);

    int afterData = data.size();

    cout << "Time taken by function: "
              << duration.count() << " microseconds. The algorithm started with a size of " << prevData<< " and ended with a size of "<<afterData << endl;
}



