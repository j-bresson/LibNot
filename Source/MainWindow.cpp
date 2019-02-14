//
//  MainWindow.cpp
//  LibNot - App
//
//  Created by Jean Bresson on 12/02/2019.
//

#include "MainWindow.hpp"
#include "LibNotEditor.hpp"

void MainWindow::closeButtonPressed()
{
    // This is called when the user tries to close this window. Here, we'll just
    // ask the app to quit when this happens, but you can change this to do
    // whatever you need.
    // JUCEApplication::getInstance()->systemRequestedQuit();
    
    editor->closeWindow();
}
