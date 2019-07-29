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
#include "Score.hpp"

// : std::enable_shared_from_this<LibNotEditor>

class LibNotEditor  {
    
public:
    
    LibNotEditor() {
        // need to call this once to create a MessageManager
        MessageManager::getInstance();
    }
    
    ~LibNotEditor() = default;
    
    void openWindow();
    // void openWindow( std::shared_ptr<LibNotEditor> &owner );
    void closeWindow();
    void windowToFront();
    void windowSetName(std::string name);
    
    void registerCloseCallback(lnCloseCallback c) { close_callback = c ; }
    void registerUpdateCallback(lnUpdateCallback c) { update_callback = c ; }
    
    void executeCloseCallback() { if (close_callback) { close_callback( this ); } }
    void executeUpdateCallback(int arg) { if (update_callback) { update_callback( this, arg ); } }
    
    const std::shared_ptr<Score> getScore( ) const { return score; } ;
    void setScore(std::shared_ptr<Score> s) { score = s ; } ;

    const float getFontSize() const { return font_size ; } ;
    const staff_t getStaff() const { return staff ; } ;
    
    // A static method to get the Editor from any Juce::Component in the editor window
    static const LibNotEditor & getLibNotEditor( const Component *c )
    {
        return ((MainWindow*) c->getTopLevelComponent())->getEditor() ;
    }

private:
    
    std::shared_ptr<MainWindow> window = nullptr;
    std::shared_ptr<Score> score = nullptr ;
    
    float font_size = 24.0;
    staff_t staff = GF;
    
    lnUpdateCallback update_callback = NULL;
    lnCloseCallback close_callback = NULL;
    
};


#endif /* LibNotEditor_hpp */
