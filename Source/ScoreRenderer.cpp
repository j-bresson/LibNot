//
//  ScoreRenderer.cpp
//  LibNot - App
//
//  Created by Jean Bresson on 19/06/2019.
//


#include "ScoreRenderer.hpp"

void ScoreRenderer::setFontSize ( const float size ) {
    
    font_size = size ;
    unit = fontSizeToUnit(size) ;
    
}

const std::map<score_symbol_t,String> ScoreRenderer::score_symbols_map =
{
    { F_KEY , String::fromUTF8("\uE062") },
    { G_KEY , String::fromUTF8("\uE050") }
} ;

// Staff lines position in relative units
// By convention line 0 is the (virtual) line of a C3
const std::map<staff_t, const staff_info> ScoreRenderer::staves_map =
{
    { G,     {{ 1, 2, 3, 4, 5 }, {G_KEY}, {2}}},
    { F,     {{ -5, -4, -3, -2, -1 }, {F_KEY}, {-2}}},
    { GG,    {{ 1, 2, 3, 4, 5, 8, 9, 10, 11, 12 }, {G_KEY,G_KEY}, {2,9}}},
    { FF,    {{ -12, -11, -10, -9, -8, -5, -4, -3, -2, -1 }, {F_KEY,F_KEY}, {-9,-2}}},
    { GF,    {{ -5, -4, -3, -2, -1, 1, 2, 3, 4, 5 }, {F_KEY,G_KEY}, {-2,2}}},
    { GFF,   {{ -12, -11, -10, -9, -8, -5, -4, -3, -2, -1, 1, 2, 3, 4, 5 }, {G_KEY,F_KEY,F_KEY}, {-9,-2,2}}},
    { GGF,   {{ -5, -4, -3, -2, -1, 1, 2, 3, 4, 5, 8, 9, 10, 11, 12 }, {G_KEY,G_KEY,F_KEY}, {-2,2,9}}},
    { GGFF,  {{ -12, -11, -10, -9, -8, -5, -4, -3, -2, -1, 1, 2, 3, 4, 5, 8, 9, 10, 11, 12 }, {F_KEY,F_KEY,G_KEY,G_KEY}, {-9,-2,2,9}}},
    { LINE,  {{0}, {}, {}}},
    { EMPTY, {{0}, {}, {}}},
} ;
        

// Maybe not necessary: Jucve might handle this (?)
const float ScoreRenderer::adjustLinePos( const float pos ) const
{
    if ( unit > 5 ) return roundf(pos) ;
    else return pos ;
}


void ScoreRenderer::initDraw(Graphics& g)
{
    g.fillAll ( Colours::white ) ;
    g.setFont ( Font("Bravura",0,0).withPointHeight( font_size ) );
    g.setColour (Colours::black);
}

void ScoreRenderer::drawStaff (Graphics& g, int x, int y, float y_u, int w, int h, staff_t staff ) const
{
    const staff_info staff_i = staves_map.at(staff);
    std::vector<float> lines = std::get<0>(staff_i);
    std::vector<score_symbol_t> keys = std::get<1>(staff_i);
    std::vector<float> key_pos = std::get<2>(staff_i);
    
    float line0_u = y_u + lines.back() ;
    float line_pix;
    
    for ( float line_u : lines )
    {
        line_pix = adjustLinePos( (line0_u - line_u) * unit ) ;
        g.drawLine(x,line_pix,x+w,line_pix,.13*unit);
    }
    
    for ( int k = 0; k < keys.size() && k < key_pos.size() ; k++ )
    {
        line_pix = adjustLinePos( (line0_u - key_pos.at(k) ) * unit ) ;
        g.drawSingleLineText( score_symbols_map.at(keys.at(k)) , 4 * unit , line_pix );
    }
}



void ScoreRenderer::drawChord (Graphics& g, const Chord& c, int x, int y, float y_u, staff_t staff ) const
{
    g.drawText( String::fromUTF8("\uE0A4") , 50+ c.getDate() * .2, 80, 400 , 20 , Justification::left ) ;
    //g.setFont ( Font("Arial",0,0).withPointHeight( font_size ) );
    g.drawText( c.print(), 30 + c.getDate()* .2 , 40, 400 , 20 , Justification::left);
}
