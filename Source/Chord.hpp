//
//  Chord.hpp
//  LibNot


#ifndef Chord_hpp
#define Chord_hpp

#include <vector>
#include <iostream>
#include <string>
#include <sstream>

/*
class Note {
    
public:
    
    Note( int pitch ) : pitch {pitch} {} ;
    ~Note() = default ;

private :
    
        int pitch = 6000 ;  // pitch in midicents (6000=C3)
        int dur = 1000 ;    // Duration in ms
        int vel = 100 ;     // MIDI velocity [0-127]
        int offset = 0 ;    // Offset / parent chord in ms
        int channel = 1 ;   // MIDI channel [1-16]
};
 */


/*
 * CHORD is the main object in a musical sequence
 * Holds a list of notes and a date/offset
 */

class Chord {
    
public:
   
//    Chord() = default;
//    ~Chord() = default;
    Chord(const std::string name ) : name (name) {
        std::cout << "Chord created " << this->name << "(" << this->n << ")" << std::endl;
    } ;
    
    ~Chord() {
        std::cout << "Chord deleted " << this->name << "(" << this->n << ")" << std::endl;
    } ;
    
    Chord(const Chord& c) {
        pitches = c.pitches;
        date = c.date;
        name = c.name;
        n = c.n + 1;
        std::cout << "Chord copied " << c.name << "(" << c.n << ")"<< " => " << this->name << "(" << this->n << ")"<< std::endl;
    } ;

    void setDate ( const int newDate ) { date = newDate; } ;
    const int getDate () const { return date; } ;
    
    void addNote (const int pitch) { pitches.push_back(pitch); } ;
    
    const std::string print () const
    {
        std::stringstream ss;
        ss << name << "(" << n << ")" ;
        return ss.str();
    } ;
    
private :
    
    int date = 0 ;
    std::string name = "";
    int n = 0;
    std::vector<int> pitches;
    
};

#endif /* Chord_hpp */
