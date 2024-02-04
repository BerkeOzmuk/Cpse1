#include "hwlib.hpp"

extern "C" void uart_put_char(char c){
   hwlib::cout << c;
}

extern "C" void lz_decompressor();

int main( void ){	
   namespace target = hwlib::target;

   // Wait for the PC-console to start
   hwlib::wait_ms(2000);

   lz_decompressor();
}