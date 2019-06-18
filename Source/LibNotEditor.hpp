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
    
    const std::shared_ptr<Score> getScore( ) const { return score; } ;
    void setScore(Score &s) { score = std::make_shared<Score>(s) ; } ;

    const float getFontSize() const { return font_size ; } ;
    const staff_t getStaff() const { return staff ; } ;
    
    // A static method to get the Editor from any Juce::Component in the editor window
    static const LibNotEditor& getLibNotEditor(Component *c)
    {
        return ((MainWindow*) c->getTopLevelComponent())->getEditor() ;
    }

private:
    
    std::shared_ptr<MainWindow> window;
    std::shared_ptr<Score> score;
    
    float font_size = 24.0;
    staff_t staff = GF;
    
    lnUpdateCallback update_callback = NULL;
    lnCloseCallback close_callback = NULL;
    
};


#endif /* LibNotEditor_hpp */
