//
//  LibNotEditor.cpp
//  LibNot
//
//  Created by Jean Bresson on 12/02/2019.
//

#include "LibNotEditor.hpp"

void LibNotEditor::openWindow()
{
    // std::cout << "STANDALONE: " << JUCEApplicationBase::isStandaloneApp() << std::endl ;
    // std::cout << "Current thread: " << Thread::getCurrentThread() << std::endl ;
    
    const MessageManagerLock mml;
    //std::cout << "Current MML: " << mml.lockWasGained() << std::endl ;
    
    window.reset (new MainWindow ("Note Editor", this));
}

void LibNotEditor::closeWindow()
{
    const MessageManagerLock mml;
    window = nullptr;
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


