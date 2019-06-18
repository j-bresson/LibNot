/*
  ==============================================================================

    This file was auto-generated!

  ==============================================================================
*/

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"
#include "Types.h"

class ScoreComponent   : public Component {

public:

    ScoreComponent() = default;
    ~ScoreComponent() = default;

    void paint (Graphics&) override;
    
    static const float fontSizeToUnit( const float font_size ) { return font_size * .25 ; }
    static const float unitToFontSize( const float unit ) { return unit * 4 ; }

private:
    
    void draw_staff (Graphics& g, int x, int y, float y_u, int w, int h, float unit, staff_t staff);
    
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (ScoreComponent)
    
};
