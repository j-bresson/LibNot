

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"

#include "GUIPanelComponent.hpp"
#include "ScoreComponent.hpp"

class MainComponent   : public Component
{
public:
    
    MainComponent();
    ~MainComponent()= default ;

    void resized() override;

private:
    
    GUIPanelComponent top_panel;
    GUIPanelComponent bottom_panel;
    ScoreComponent main_panel;
    
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MainComponent)
};
