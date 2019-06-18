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
    
    window.reset (new MainWindow ("LibNot Editor"));
    window.get()->setEditor( *this );    // std::make_shared<LibNotEditor>(this) );
}


void LibNotEditor::closeWindow()
{
    const MessageManagerLock mml;
    delete window.get();  // will actually close the Juce Window...
    // window.reset(); // window = nullptr;
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


