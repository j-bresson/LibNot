/*
  ==============================================================================

    This file was auto-generated!

  ==============================================================================
*/

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"
#include "Types.h"
#include "ScoreRenderer.hpp"

class ScoreComponent   : public Component {

public:

    ScoreComponent() = default;
    ~ScoreComponent() = default;

    void paint (Graphics&) override;
    
private:
    
    ScoreRenderer sr;
    
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (ScoreComponent)
    
};
