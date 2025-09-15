// Copyright (c) 2025 Anas Ali Chafai. All rights reserved.
// Contact: anaschafai04gmail.com

#include <iostream>
#include "clsLoginScreen.h"


int main()

{
    bool Loop;
    do
    {
      Loop = clsLoginScreen::ShowLoginScreen();
    } while (Loop);
    
    system("pause>0");
    return 0;

} 
