/*
  ==============================================================================

    This file was auto-generated!

  ==============================================================================
*/

#include "ScoreComponent.hpp"


void ScoreComponent::paint (Graphics& g)
{
    g.fillAll (Colours::white) ;
    g.setFont ( Font ( "Bravura" , 64, 0) );
    g.setColour (Colours::black);
    g.drawText ("Hello World!", getLocalBounds(), Justification::centred, true);
}

