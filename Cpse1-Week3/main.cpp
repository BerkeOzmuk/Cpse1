#include "hwlib.hpp"

#include <array>
#include "clock.hpp"


int main( void ){	
   
   WDT->WDT_MR = WDT_MR_WDDIS;
   // wait for the PC console to start
   hwlib::wait_ms( 2000 );  

   hwlib::cout << "Clock demo\n\n";
   
   constexpr auto sinus = lookup< 360, int >( scaled_sine_from_degrees );
   constexpr auto cosinus = lookup< 360, int >( scaled_cos_from_degrees );

   auto scl = hwlib::target::pin_oc( hwlib::target::pins::scl );
   auto sda = hwlib::target::pin_oc( hwlib::target::pins::sda );
   auto i2c_bus = hwlib::i2c_bus_bit_banged_scl_sda( scl, sda );

   auto bigHand = hwlib::target::pin_in_out( hwlib::target::pins::d25 );
   auto smallHand = hwlib::target::pin_in_out( hwlib::target::pins::d23 );

   auto oled = hwlib::glcd_oled( i2c_bus, 0x3c );
   
   clock Clock( oled, bigHand, smallHand );

   Clock.run( sinus, cosinus );
  
}