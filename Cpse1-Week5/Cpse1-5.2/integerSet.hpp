#ifndef INTEGERSET_HPP
#define INTEGERSET_HPP

#include <iostream>
#include <array>

template<typename T, int arrSize>

class integerSet{
private:
    std::array<T, arrSize> intSet = {};

    int size = 0;

public:
    void add(T value){

        if(!contains(value) && size != 10){
            intSet[size] = value;
            size++;
        }
        for( int i = 0; i <= size - 1; i++){
            std::cout << intSet[i] << ' ';
        }

    std::cout << "size: " << size << '\n';
    std::cout << '\n';
    }

    void remove(T value){
        bool isRemoved = false;
        for( int i = 0; i <= size - 1; i++){
            if(intSet[i] == value){
                size--;
                isRemoved = true;
            }
            if(isRemoved){
                intSet[i] = intSet[i + 1];
            }
        }

        for( int i = 0; i <= size - 1; i++){
            std::cout << intSet[i] << ' ';
        }

        std::cout << "size: " << size << '\n';

        std::cout << '\n';
    }

    bool contains(T value){
        for( int i = 0; i <= size - 1; i++){
            if(intSet[i] == value){
                return true;
            }
        }
        return false;
    }

    friend std::ostream & operator<<( std::ostream & lhs, const integerSet & rhs){
        for( int i = 0; i < rhs.size; i++ ){
            lhs << rhs.intSet[i] << ", ";
        }
        return lhs;
    };
};

#endif