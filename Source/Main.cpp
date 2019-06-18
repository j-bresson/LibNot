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
        // s will then come from OM / external host environment
        std::shared_ptr<Score> s = std::make_shared<Score>( makeTestScore() ) ;
        
        std::cout << "SCORE CREATED" << std::endl;
        
        editor.setScore( *s.get() );
        
        std::cout << "SCORE SET TO EDITOR" << std::endl;
        
        // mainWindow.reset (new MainWindow (getApplicationName()));
        // editor.reset (new LibNotEditor());
        editor.openWindow();
        
        std::cout << "WINDOW OPEN / END INITIALIZE" << std::endl;
    }

    void shutdown() override
    {
        // Add your application's shutdown code here..
        editor.closeWindow();
        
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

    LibNotEditor editor;
    
    
    Score makeTestScore()
    {
        
        Score s;
        Chord c1("A"), c2("B"), c3("C");
        std::cout << "CHORDS CREATED" << std::endl;
        c1.addNote(6000);
        c1.addNote(6500);
        c1.addNote(6700);
        c1.setDate(0);
        
        c2.addNote(7000);
        c2.addNote(7500);
        c1.setDate(1000);
        
        c3.addNote(5200);
        c3.addNote(5800);
        c3.addNote(6100);
        c3.setDate(1800);
        
        std::cout << "CHORDS SET" << std::endl;
        
        s.addChord( c1 );
        s.addChord( c2 );
        s.addChord( c3 );
        std::cout << "CHORDS ADDED" << std::endl;
        
        s.print();
        return s;
        
    };
    
    
};

//==============================================================================
// This macro generates the main() routine that launches the app.
START_JUCE_APPLICATION (LibNotApplication)



