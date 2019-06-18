//
//  Score.hpp
//  LibNot
//

#ifndef Score_hpp
#define Score_hpp

#include "Chord.hpp"
#include "RhythmTree.hpp"

#include <iostream>
#include <vector>

class Score {
    
public:
    
    Score() {
        std::cout << "SCORE CREATED " << this << std::endl;
    } ;
    
    ~Score() {
        std::cout << "SCORE DELETED " << this << std::endl;
    } ;
    
    Score(const Score& s) {
        chords = s.chords;
        std::cout << "SCORE COPIED " << &s << " => " << this << std::endl;
    } ;
    
    void reset() { chords.clear(); };
    
    void addChord( const Chord c ) { chords.push_back(c) ; };
    
    void print ()
    {
        std::cout << "==== SCORE: ====" << std::endl;
        for ( auto c : chords )
        {
            std::cout << c.print() << " ";
            std::cout << std::endl ;
        }
        std::cout << "================" << std::endl;
    }
    
    unsigned long getNumChords () const { return chords.size() ; }
    const Chord &getChord (int i) const { return chords.at(i) ; }
    

private:

    std::vector<Chord> chords;
    RhythmTree tree;
    
};

#endif /* Score_hpp */
