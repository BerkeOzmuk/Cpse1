#ifndef CLOCK_H
#define CLOCK_H

#include "hwlib.hpp"
#include "cos_sin.hpp"
#include "lookup.hpp"

class clock{
private: 
    int seconds = 0;
    int minutes = 0;
    int hours = 0;

    hwlib::window &oled;
    hwlib::xy vertex = {67, 30};
    hwlib::color white = {0xFF, 0xFF, 0xFF};

    hwlib::pin_in_out & bigHand;
    hwlib::pin_in_out & smallHand;

    int currentTime = hwlib::now_us() / 1000000;
    int previousTime = 0;

public:
    clock(hwlib::window & oled, hwlib::pin_in_out & bigHand, hwlib::pin_in_out & smallHand):
    oled(oled),
    bigHand(bigHand),
    smallHand(smallHand)
    {}

    void drawClock( const auto & sin, const auto & cos ){
        oled.clear();

        for(unsigned int i = 0; i < 360; i+= 30){
            hwlib::circle( hwlib::xy( sin.get( i ), cos.get( i ) ),  2, white ).draw(oled);
        }
        hwlib::circle( vertex, 3.5, white).draw(oled);

        hwlib::line( vertex, hwlib::xy( sin.get( minutes * 6) , cos.get( minutes * 6 ) ) , white ).draw( oled );
        hwlib::line( vertex, hwlib::xy( sin.get( seconds * 6), cos.get( seconds * 6 ) ), white ).draw( oled );
        hwlib::line( vertex, hwlib::xy( sin.get( hours * 30) , cos.get( hours * 30 ) ), white ).draw( oled );


        oled.flush();
        
    }

    void run( const auto & sin, const auto & cos ){
        for(;;){
            currentTime = hwlib::now_us() / 1000000;

            if(currentTime >= previousTime + 1){
                seconds++;
                previousTime += 1;
            }

            if(bigHand.read()){
                if(hours > 11){
                    hours = 0;
                }
                hours++;                
            }
            
            else if(smallHand.read()){
                if(minutes > 59){
                    minutes = 0;
                }
                minutes++;                
            }

            if(seconds > 59){
                seconds = 0;
                minutes++;
            }

            if(minutes > 59){
                minutes = 0;
                hours++;
            }
            
            if(hours > 11){
                hours = 0;
            }    
            hwlib::cout << seconds << '\n';

            drawClock( sin, cos );        
        }
        
    }

};

#endif