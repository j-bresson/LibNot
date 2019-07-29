/*
  ==============================================================================

    This file was auto-generated!

  ==============================================================================
*/

#include "MainComponent.hpp"

//==============================================================================
MainComponent::MainComponent()
{
    // getLookAndFeel().setColour (ResizableWindow::ColourIds backgroundColourId, Colours::lightgrey) ;
    addAndMakeVisible (top_panel);
    addAndMakeVisible (main_panel);
    addAndMakeVisible (bottom_panel);
    setSize (600, 400);
}


void MainComponent::resized ()
{
    auto area = getLocalBounds();
    auto topPanelHeight = 30;
    auto bottomPanelHeight = 30;
    top_panel.setBounds (area.removeFromTop (topPanelHeight));
    bottom_panel.setBounds (area.removeFromBottom (bottomPanelHeight));
    main_panel.setBounds(area);
}
