#ifndef COS_SIN_H
#define COS_SIN_H

constexpr double pow( double g, int n ){
   double result = 1;
   while( n > 0 ){
       result *= g;
       --n;
   }
   return result;
}

constexpr double fac( int n ){
   double result = 1;
   while( n > 0 ){
       result *= n;
       --n;
   }
   return result;
}

constexpr double sin( double a ){
   return 
      a 
      - pow( a, 3 ) / fac( 3 ) 
      + pow( a, 5 ) / fac( 5 ) 
      - pow( a, 7 ) / fac( 7 )
      + pow( a, 9 ) / fac( 9 ) 
      - pow( a, 11 ) / fac( 11 ) 
      + pow( a, 13 ) / fac( 13 );
}

constexpr double cos( double a ){
   return sin( 1.57 - a );
}

constexpr double radians_from_degrees( int degrees ){
   return 2 * 3.14 * ( degrees / 360.0 );
}

constexpr int scaled_sine_from_degrees( int degrees ){
   return 30 * ( 2.2 + sin( radians_from_degrees( degrees )) );
}

constexpr int scaled_cos_from_degrees( int degrees ){
   return 30 + ( 25 * cos( radians_from_degrees( degrees - 180 )));
}

   

#endif