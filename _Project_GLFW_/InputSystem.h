#pragma once
#include "WindowComponent.h"
#include <list>


class Window;


namespace Input
{

    bool getKey(const int& keycode);
    bool getMouseKey(const int& keycode);
    void Update();
   
    void FillStates(bool iskeyboardkey, const int& allkeycode, std::list<int>& keyboardkeys, std::list<int>& releasedkeyboardkeys);
    void FillCurrents(bool iskeyboard, const int& allkeycodes, std::list<int>& currents);
    bool getStates(bool isMouse,bool ispressed ,const int& keycodes);

    const  int NUM_KEYCODES = 348;
    const  int NUM_MOUSEKEYCODES = 5;
}