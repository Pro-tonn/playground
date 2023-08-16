#pragma once

#include <iostream>
#include <exception>
#include <stdexcept>

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


};




