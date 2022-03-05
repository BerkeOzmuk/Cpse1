#include <melody.hpp> 
 
void melody::play( note_player & p ){ 
  p.play( note{659,  250000 } ); 
  p.play( note{622,  250000 } ); 
  p.play( note{659,  250000 } ); 
  p.play( note{622,  250000 } ); 
  p.play( note{659,  250000 } ); 
  p.play( note{494,  250000 } ); 
  p.play( note{587,  250000 } ); 
  p.play( note{523,  250000 } ); 
  p.play( note{440,  500000 } ); 
}