


#include <vector>

#include "ScoreComponent.hpp"
#include "LibNotEditor.hpp"
#include "Score.hpp"


void ScoreComponent::paint (Graphics& g)
{
    const LibNotEditor& ed = LibNotEditor::getLibNotEditor( this ) ;  
    sr.setFontSize( ed.getFontSize() );
    std::shared_ptr<Score> s = ed.getScore() ;
    
    sr.initDraw( g );
    sr.drawStaff( g , 0 , 0 , 10 , getLocalBounds().getWidth() , getLocalBounds().getHeight() , ed.getStaff() );
    
    for (int i = 0; i < s->getNumChords(); i++)
    {
        sr.drawChord( g , * s->getChord(i).get() , 0 , 0, 10 , ed.getStaff() );
    }
    
    // g.drawText ("Hello World!", getLocalBounds(), Justification::centred, true);
    
}


