//
//  MainWindow.cpp
//  LibNot - App
//
//  Created by Jean Bresson on 12/02/2019.
//

#include "MainWindow.hpp"
#include "LibNotEditor.hpp"

// called when the user close this window with the standard button.
void MainWindow::closeButtonPressed()
{
    // the editor controls all actions, including actually destroying this window
    editor->closeWindow();
    // exit main loop
    JUCEApplication::getInstance()->systemRequestedQuit();
}

