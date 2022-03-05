#ifndef _NOTE_PLAYER_PC_HPP
#define _NOTE_PLAYER_PC_HPP

#include "note_player.hpp"
#include "hwlib.hpp"

class note_player_pc: public note_player{
public: 
    void play(const note & n) override;
};

#endif

