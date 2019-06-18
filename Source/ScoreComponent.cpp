


#include <vector>

#include "ScoreComponent.hpp"
#include "LibNotEditor.hpp"
#include "Score.hpp"


void ScoreComponent::paint (Graphics& g)
{
    const LibNotEditor &ed = LibNotEditor::getLibNotEditor( this );
    float u = fontSizeToUnit( ed.getFontSize() );
    std::shared_ptr<Score> s = ed.getScore() ;
    
    g.fillAll ( Colours::white ) ;
    g.setFont ( Font("Bravura",0,0).withPointHeight( ed.getFontSize() ) );
    g.setColour (Colours::black);
    g.drawText ("Hello World!", getLocalBounds(), Justification::centred, true);
    
    draw_staff( g , 0 , 0 , 0.0 , getLocalBounds().getWidth() , getLocalBounds().getHeight() , u , ed.getStaff() );
    
    for (int i = 0; i < s.get()->getNumChords(); i++)
    {
            // g.drawText( s.get()->getChord(i).print(), (1+i)*200, 40, 400 , 20 , Justification::left);
        g.drawText( String::fromUTF8("\uE0A4") , (1+i)*200, 40, 400 , 20 , Justification::left ) ;
        
    }
}



/*======================
 * UTILITY FUNCTIONS
 *======================*/

float adjust_line_pos( int y,  float pos, float unit )
{
    if ( unit > 5 ) return y + roundf(pos) ;
    else return y + pos ;
}

inline float line_to_ypos (int line, float shift, float unit)
{
    return (shift - line) * unit ;
}


const std::vector<int> staff_lines ( const staff_t staff )
{
    std::vector<int> lines;
    
    switch (staff) {
        case F:
            lines = { -5, -4, -3, -2, -1 } ;
            break;
        case G:
            lines = { 1, 2, 3, 4, 5 };
            break;
        case GG:
            lines = { 1, 2, 3, 4, 5, 8, 9, 10, 11, 12 };
            break;
        case FF:
            lines = { -12, -11, -10, -9, -8, -5, -4, -3, -2, -1 } ;
            break;
        case GF:
            lines = { -5, -4, -3, -2, -1, 1, 2, 3, 4, 5 } ;
            break;
        case GFF:
            lines = {-12, -11, -10, -9, -8, -5, -4, -3, -2, -1, 1, 2, 3, 4, 5 } ;
            break;
        case GGF:
            lines = {-5, -4, -3, -2, -1, 1, 2, 3, 4, 5, 8, 9, 10, 11, 12 } ;
            break;
        case GGFF:
            lines = {-12, -11, -10, -9, -8, -5, -4, -3, -2, -1, 1, 2, 3, 4, 5, 8, 9, 10, 11, 12 } ;
            break;
        case EMPTY:
            lines = { 0 } ;
            break;
        case LINE:
            lines = { 0 } ;
            break;
    }
    return lines ;
}


// determines where to position line #0
float calculate_staff_line_shift ( staff_t staff )
{
    // 4 is an arbitrary top margin in units (line-h)
    return 10 + staff_lines( staff ).back();
}



void ScoreComponent::draw_staff (Graphics& g, int x, int y, float y_u, int w, int h, float unit, staff_t staff )
{
    float shift = y_u + calculate_staff_line_shift( staff ) ;
    
    float ypos;
    for (float line : staff_lines( staff ) )
    {
        ypos = adjust_line_pos( line_to_ypos(line,shift,unit), y, unit ) ;
        g.drawLine(x,ypos,x+w,ypos,1.0);
    }
}

