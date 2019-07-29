/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic startup code for a JUCE application.

  ==============================================================================
*/

#include "../JuceLibraryCode/JuceHeader.h"
#include "LibNotEditor.hpp"
#include "Score.hpp"
#include <iostream>

//==============================================================================
class LibNotApplication  : public JUCEApplication
{
public:
    //==============================================================================
    LibNotApplication() {}

    const String getApplicationName() override       { return ProjectInfo::projectName; }
    const String getApplicationVersion() override    { return ProjectInfo::versionString; }
    bool moreThanOneInstanceAllowed() override       { return true; }

    //==============================================================================
    void initialise (const String& commandLine) override
    {
        std::cout << "--- begin initialize" << std::endl;
        
        // s will then come from OM / external host environment
        
        // auto s = std::make_shared<Score>() ;
        // initializeTestScore(*s.get());
        
        score = std::make_shared<Score>();
        editor = std::make_shared<LibNotEditor>();

        initializeTestScore( score );
        
        std::cout << "--- score initialized" << std::endl;
        
        editor->setScore( score );
        
        std::cout << "--- Score passed to editor" << std::endl;
        
        editor->openWindow();
        
        std::cout << "--- end initialize" << std::endl;
    }

    void shutdown() override
    {
        // Add your application's shutdown code here..
        editor.get()->closeWindow();
        
        // mainWindow = nullptr; // (deletes our window)
    }

    //==============================================================================
    void systemRequestedQuit() override
    {
        // This is called when the app is being asked to quit: you can ignore this
        // request and let the app carry on running, or call quit() to allow the app to close.
        quit();
    }

    void anotherInstanceStarted (const String& commandLine) override
    {
        // When another instance of the app is launched while this one is running,
        // this method is invoked, and the commandLine parameter tells you what
        // the other instance's command-line arguments were.
    }

private:

    std::shared_ptr<LibNotEditor> editor ;
    std::shared_ptr<Score> score ;
    
    
    void initializeTestScore(std::shared_ptr<Score>& s) const
    {
        auto c1 = std::make_shared<Chord>("A") ;
        auto c2 = std::make_shared<Chord>("B") ;
        auto c3 = std::make_shared<Chord>("C") ;
        
        c1->addNote(6000);
        c1->addNote(6500);
        c1->addNote(6700);
        c1->setDate(0);
        
        c2->addNote(7000);
        c2->addNote(7500);
        c1->setDate(1000);
        
        c3->addNote(5200);
        c3->addNote(5800);
        c3->addNote(6100);
        c3->setDate(1800);
        
        s->addChord( c1 );
        s->addChord( c2 );
        s->addChord( c3 );
        
        std::cout << "....... chords added in Score" << std::endl;
        
        s->print();
        
    };
    
    
};

//==============================================================================
// This macro generates the main() routine that launches the app.
START_JUCE_APPLICATION (LibNotApplication)



