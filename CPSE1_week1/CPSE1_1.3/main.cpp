#include "hwlib.hpp"
#include <string.h>

extern "C" void uart_put_char( char c ){
   hwlib::cout << c;
}

extern "C" void print_asciz( const char * s );

extern "C" void application();

extern "C" void toggleCase( char s){
   if(s >= 65 && s <= 90){
      s = tolower(s);
   }
   else if(s >= 97 && s <= 122){
      s = toupper(s);
   }
}


int main( void ){	
   
   namespace target = hwlib::target;   
    
   // wait for the PC console to start
   hwlib::wait_ms( 2000 );

   application();
}