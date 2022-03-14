#ifndef INTEGERSET_HPP
#define INTEGERSET_HPP

#include <iostream>
#include <array>



class integerSet{
private:
    std::array<int, 10> intSet = {};

    int size = 0;

public:
    void add(int value);
    void remove(int value);

    bool contains(int value);
    
    friend std::ostream & operator<<( std::ostream & lhs, const integerSet & rhs){
        for( int i = 0; i < rhs.size; i++ ){
            lhs << rhs.intSet[i] << ", ";
        }
        return lhs;
    };
};

#endif