#include "integerSet.hpp"

bool integerSet::contains(int value){
    for( int i = 0; i <= size - 1; i++){
        if(intSet[i] == value){
            return true;
        }
    }
    return false;
}

void integerSet::add(int value){ 
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

void integerSet::remove(int value){
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