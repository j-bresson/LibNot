//
//  ScoreRenderer.hpp
//  LibNot - App
//
//  Created by Jean Bresson on 19/06/2019.
//

#ifndef ScoreRenderer_hpp
#define ScoreRenderer_hpp

#include "../JuceLibraryCode/JuceHeader.h"

#include "Types.h"
#include "Chord.hpp"

#include <vector>
#include <string>
#include <map>


typedef enum { F_KEY, G_KEY } score_symbol_t ;

typedef std::tuple<const std::vector<float>,const std::vector<score_symbol_t>,const std::vector<float>> staff_info ;

class ScoreRenderer {
    
public:
    
    //ScoreRenderer () {} ;
    //~ScoreRenderer () {} ;

    void setFontSize ( const float size ) ;
    
    void initDraw(Graphics& g) ;
    void drawStaff (Graphics& g, int x, int y, float y_u, int w, int h, staff_t staff ) const ;
    void drawChord (Graphics& g, const Chord& c, int x, int y, float y_u, staff_t staff ) const ;
    
private:
    
    // The global font size of rendering
    float font_size = 24.0 ;
    // A "unit" is the size (in pixels) that separates two lines of a standard staff
    float unit = 6.0 ;
    
    static const float fontSizeToUnit( const float font_size ) { return font_size * .25 ; }
    static const float unitToFontSize( const float unit ) { return unit * 4 ; }
    
    static const std::map<score_symbol_t,String> score_symbols_map ;

    // pairing staffs to tuples of lines,key_symbbols,key_positions (all vectors)
    static const std::map< staff_t , const staff_info > staves_map ;

    
    const float positionOfStaffLine0 ( const staff_t staff ) const ;
    const float adjustLinePos( const float pos ) const ;
    
};

#endif /* ScoreRenderer_hpp */
