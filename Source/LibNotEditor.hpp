//
//  LibNotEditor.hpp
//  LibNot - App
//
//  Created by Jean Bresson on 12/02/2019.
//

#ifndef LibNotEditor_hpp
#define LibNotEditor_hpp

#include "../JuceLibraryCode/JuceHeader.h"
#include "Types.h"
#include <string>
#include "MainWindow.hpp"


class LibNotEditor {
    
public:
    
    LibNotEditor() {
    // need to call this once to create a MessageManager
    MessageManager::getInstance();
    }
    
    ~LibNotEditor() = default;

    void openWindow();
    void closeWindow();
    void windowToFront();
    void windowSetName(std::string name);
    
    void registerCloseCallback(lnCloseCallback c) { close_callback = c ; }
    void registerUpdateCallback(lnUpdateCallback c) { update_callback = c ; }
    
    void executeCloseCallback() { if (close_callback) { close_callback( this ); } }
    void executeUpdateCallback(int arg) { if (update_callback) { update_callback( this, arg ); } }
    
private:
    
    std::unique_ptr<MainWindow> window;

    lnUpdateCallback update_callback = NULL;
    lnCloseCallback close_callback = NULL;
    
};


#endif /* LibNotEditor_hpp */
