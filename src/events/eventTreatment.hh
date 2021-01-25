/*! \file eventTreatment.hh
 *  \brief File containing the treatment associated with events
 *  \author Karim El-Kharroubi --- Vincent LEFEBVRE
 *  \version 0.1
 *  \date 16/12/2020
 */

#include <iostream>
#include <vector>
#include "../app/headersLocation.hh"

#include "mainMenuEventTreatment.hh"
#include "playEventTreatment.hh"

#include APP_STATES_H
#include USR_INTERFACE_H

static constexpr int NOTHING = -1;

/*! \fn int static checkButtonPressed(std::shared_ptr<Clickable> clicked )
 *  \brief Check if a mouse click is on the left or the right button
 *
 *  \param clicked a shared pointer on a clickable object
 *  \return the return code of the clickable object
 */

int static checkButtonPressed(std::shared_ptr<Clickable> clicked ){
            int rt = NOTHING;
            
            if( sf::Mouse::isButtonPressed(sf::Mouse::Left))
                    rt =   clicked->leftClickAction(); 
                    
            else if (sf::Mouse::isButtonPressed(sf::Mouse::Right))
                    rt = clicked->rightClickAction();
            
             std::cout << "RT is " << rt << std::endl;

            return rt;
}

/*! \fn void static  treatKeyPressed(sf::Event & event,sf::RenderWindow & window )
 *  \brief Check the key pressed
 *
 *  \param event reference on the event triggering the function
 *  \param window reference on the application unique window
 */
void static  treatKeyPressed(sf::Event & event,sf::RenderWindow & window ){
                    switch(event.key.code){
                      case sf::Keyboard::Escape:
                        window.close();
                      default:
                        break;
                    }
}

/*! \fn void static mainMenuDecode(int clickedRt,sf::RenderWindow & window, std::unique_ptr<usrInterface> usrInt )
 *  \brief Do the action provided by a clickable object
 *  \param clickedRt the int returned by a clickable object
 *  \param window reference on the application unique window
 *  \param usrInt an unique pointer on the current user interface
 *  \param[out] appState the current application state
 */
void static playingDecode(
    int clickedRt,
    sf::RenderWindow & window,
    std::unique_ptr<usrInterface>* usrInt,
    int * appState,std::unique_ptr<Game>* theGame){
 
    int curW = window.getSize().y,curH = window.getSize().x;
 
  if(clickedRt == END_TURN)
     (*theGame)->nextTurn();
  else{
    // Check if is overlayed 
    // When clicked on it
  }

   usrInt->reset(new BoardGI(curH,curW,theGame));
}

/*! \fn decode(int clickedRt,sf;;RenderWindow & window, std::unique_ptr<usrInterface* usrInt)
 *  \brief Decode a given return code to process it following the application state
 *  \param clickedRt the int returned by a clickable object
 *  \param window reference on the application unique window
 *  \param usrInt an unique pointer on the current user interface
 *  \param currentState the application state
 *  \param game the launched game if any is
 */
void decode(int clickedRt,sf::RenderWindow & window, std::unique_ptr<usrInterface>* usrInt,
        int* currentState,
        std::unique_ptr<Game>* gamePt 
      ){
        
          switch(*currentState){
            case MAIN_MENU:
              mainMenuDecode(clickedRt,window,usrInt,currentState,gamePt);
              break;
            case PLAYING:
              playingDecode(clickedRt,window,usrInt,currentState,gamePt
              );
              break;
        
      }

      }