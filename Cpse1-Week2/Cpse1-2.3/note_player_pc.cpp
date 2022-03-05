#include "note_player_pc.hpp"



void note_player_pc::play(const note & n){
    hwlib::cout << n.frequency << ":" << n.duration << '\n';
}