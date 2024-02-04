#include "note_player_pc.hpp"

void note_player_pc::play(const note & n){
    std::ofstream myFile;
    myFile.open("song.hpp", std::ofstream::app);
    myFile << "  p.play( note{" << n.frequency << ",  "<< n.duration << " } ); \n";
    myFile.close();
}
