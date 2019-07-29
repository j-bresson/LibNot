//
//  LibNotEditor.cpp
//  LibNot
//

#include "LibNotEditor.hpp"

void LibNotEditor::openWindow()
{
    // std::cout << "STANDALONE: " << JUCEApplicationBase::isStandaloneApp() << std::endl ;
    // std::cout << "Current thread: " << Thread::getCurrentThread() << std::endl ;
    
    const MessageManagerLock mml;
    //std::cout << "Current MML: " << mml.lockWasGained() << std::endl ;
    
    window = std::make_shared< MainWindow > ( "LibNot Editor" ) ;
    window->setEditor( this );
}

/*
 void LibNotEditor::openWindow(std::shared_ptr<LibNotEditor> &owner)
{
    const MessageManagerLock mml;
    window = std::make_shared< MainWindow > ( "LibNot Editor" ) ;
    window.get()->setEditor( owner );
}
 */


void LibNotEditor::closeWindow()
{
    const MessageManagerLock mml;
    window.reset() ;  // will actually free the shared_ptr and close the Juce Window...
    executeCloseCallback();
}

void LibNotEditor::windowToFront()
{
    const MessageManagerLock mml;
    window->toFront(true);
}

void LibNotEditor::windowSetName(std::string name)
{
    const MessageManagerLock mml;
    window->setName(name);
}


