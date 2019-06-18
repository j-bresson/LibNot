//
//  MainWindow.hpp
//  LibNot - App
//
//  Created by Jean Bresson on 12/02/2019.
//

#ifndef MainWindow_hpp
#define MainWindow_hpp

#include "../JuceLibraryCode/JuceHeader.h"
#include "MainComponent.hpp"

// MainWindow has a non-owning reference to the LibNot editor
class LibNotEditor ;

/*
 This class implements the desktop window that contains an instance of
 our MainComponent class.
 */

/* Note: Be careful if you override any DocumentWindow methods - the base
 class uses a lot of them, so by overriding you might break its functionality.
 It's best to do all your work in your content component instead, but if
 you really have to override any DocumentWindow methods, make sure your
 subclass also calls the superclass's method.
 */

class MainWindow : public DocumentWindow {
    
public:
    MainWindow (String name)  : DocumentWindow (name,
                                        Desktop::getInstance().getDefaultLookAndFeel().findColour(ResizableWindow::backgroundColourId),
                                        DocumentWindow::allButtons)
    {
        setUsingNativeTitleBar (true);
        setContentOwned (new MainComponent(), true);

        setResizable (true, true);
        centreWithSize (getWidth(), getHeight());
        
        setVisible (true);
    }
    
    void closeButtonPressed() override ;
    
    
    // const std::shared_ptr<LibNotEditor> getEditor() { return editor; } ;
    const LibNotEditor &getEditor() { return *editor.get(); } ;
    void setEditor(LibNotEditor &ed) { editor = std::make_shared<LibNotEditor>(ed) ; } ;
    
private:
    
    std::shared_ptr<LibNotEditor> editor;
    
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MainWindow)
    
};

#endif
