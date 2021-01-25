/*! \file main.cc
 *  \brief File containing the main
 *  \author Karim El-Kharroubi --- Vincent LEFEBVRE
 *  \version 0.1
 *  \date 16/12/2020
 */


 /*! \fn main
  *  \brief The functin from which it all begins
  *! \return int true or false depending on the execution
  */
 
#include "headersLocation.hh"

#include <iostream>
#include <vector>

#include MAP_H
#include TILE_H
#include NORMAL_TILE_H 
#include BOARD_GI_H
#include EVENT_TREATMENT_H
#include MAIN_MENU_GI_H
#include USR_INTERFACE_H
#include APP_STATES_H
#include MAIN_EVENTS_H

int main(void){

    // Get screen size
    int curW = 	    sf::VideoMode::getDesktopMode().width,
    curH = 	    sf::VideoMode::getDesktopMode().height,
    // An int to store the return code of a clickable object
    rtCode = NOTHING,
    // An int to know in which state the application currently is
    currentState = MAIN_MENU;

    // Creates a window  
    sf::RenderWindow window(sf::VideoMode( curW, curH, sf::Style::Fullscreen)
         , "DYSTOPIA");

  std::shared_ptr<Clickable> clicked ;

  // Only one UI at the time
  std::unique_ptr<usrInterface> currentUI = std::make_unique<MainMenuGI>(curW,curH);

  std::unique_ptr<Game> curGame;

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
          curW = window.getSize().x;
          curH = window.getSize().y;

          rtCode = NOTHING;
          
            switch(event.type){

                case sf::Event::KeyPressed:
                  treatKeyPressed(event,window);
                  break;    

                case sf::Event::MouseButtonPressed :
                    clicked = currentUI->getClickedOn(
                      std::pair<int,int>(sf::Mouse::getPosition (window).x ,
                      sf::Mouse::getPosition(window).y)
                       );
                       
                    if(clicked)   
                       rtCode = checkButtonPressed(clicked);
                  break;
                case sf::Event::Closed :
                    window.close();
                  break;
                default:  
                  break;
            }
         if(rtCode != NOTHING)
           decode(rtCode,window,&currentUI,&currentState,&curGame);
        }
        window.clear();
        window.draw(*currentUI);
        window.display();
    }
    
    return 0;
}
