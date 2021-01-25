/*! \file eventTreatment.hh
 *  \brief File containing the treatment associated with events
 *  \author Karim El-Kharroubi --- Vincent LEFEBVRE
 *  \version 0.1
 *  \date 16/12/2020
 */
#ifndef __EVENTTREATMENT_HH__
#define __EVENTTREATMENT_HH__

#include <iostream>
#include <vector>
#include "../app/headersLocation.hh"


#include APP_STATES_H
#include USR_INTERFACE_H
#include MAP_H
#include GAME_H
#include BOARD_GI_H
#include "actions.hh"



int tab[DEFAULT_SIZE*DEFAULT_SIZE] ;
 //= {0,1,2,3,0,1,2,3,0,1,2,3,0,1,2,3};

/*! \fn void static mainMenuDecode(int clickedRt,sf::RenderWindow & window, std::unique_ptr<usrInterface> usrInt )
 *  \brief Do the action provided by a clickable object
 *  \param clickedRt the int returned by a clickable object
 *  \param window reference on the application unique window
 *  \param[out] usrInt an unique pointer on the current user interface
 *  \param[out] appState the current application state
 */
void static mainMenuDecode(int clickedRt,sf::RenderWindow & window,
    std::unique_ptr<usrInterface>* usrInt, int * appState,
    std::unique_ptr<Game>* theGame ){

  int curW = window.getSize().y, curH = window.getSize().x;

  if(clickedRt == actions::QUIT)
    window.close();

  else if(clickedRt == actions::NEW_GAME ){

    GameMap defaultMap(DEFAULT_SIZE,DEFAULT_SIZE,tab);
    std::vector<Unit> defaultUnits;
    
    Unit robot1(std::string("Nono"),45,0,std::make_pair<int,int>(4,1));
    Unit robot2(std::string("Drauwid"),45,0,std::make_pair<int,int>(2,1));
    Unit robotMstr(std::string("C3-PLO"),45,1,std::make_pair<int,int>(3,0));
    
    defaultUnits.push_back(robot1);
    defaultUnits.push_back(robot2);
    defaultUnits.push_back(robotMstr);

    (*theGame).reset(new Game(defaultMap,defaultUnits));

    usrInt->reset(new BoardGI(curH,curW,theGame));
    
    *appState = PLAYING;
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
 
  if(clickedRt == actions::END_TURN)
     (*theGame)->nextTurn();

  std::cout << **theGame;

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

#endif