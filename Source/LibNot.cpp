
/*!
 *  @file       libNot.cpp
 *  @brief      Library for score display and editing
 *  @author     Jean Bresson & Rama Gottfried
 *  @date       10/05/2017
 */

#include "LibNot.hpp"

#include "LibNotEditor.hpp"
#include <string>

const char* libNotInfo()
{
    return "libNot v.0.0";
}

void* libNotNewEditor()
{
    return new LibNotEditor();
}

void libNotFreeEditor(void* libNot_editor)
{
    delete static_cast<LibNotEditor*>(libNot_editor);
    // libNot_editor = nullptr;
}

void libNotOpenWindow(void* libNot_editor)
{
    static_cast<LibNotEditor*>(libNot_editor)->openWindow();
}

void libNotCloseWindow(void* libNot_editor)
{
    static_cast<LibNotEditor*>(libNot_editor)->closeWindow();
}

void libNotWindowToFront(void* libNot_editor)
{
    static_cast<LibNotEditor*>(libNot_editor)->windowToFront();
}

void libNotWindowSetName(void* libNot_editor, char *name)
{
    static_cast<LibNotEditor*>(libNot_editor)->windowSetName(std::string(name));
}

void libNotRegisterCloseCallback(void* libNot_editor, lnCloseCallback callback)
{
    static_cast<LibNotEditor*>(libNot_editor)->registerCloseCallback(callback);
}

void libNotRegisterUpdateCallback(void* libNot_editor, lnUpdateCallback callback)
{
    static_cast<LibNotEditor*>(libNot_editor)->registerUpdateCallback(callback);
}



/*
int libNotGetScore(void* libNot_handler)
{
    return static_cast<libNotHandler*>(libNot_handler)->libNotAPI_getNumSymbols();
}

void libNotSetScore(void* libNot_handler, t_osc_bndl_s *bundle)
{
    static_cast<libNotHandler*>(libNot_handler)->libNotAPI_setSymbols( OdotBundle_s(bundle) );
}
*/

