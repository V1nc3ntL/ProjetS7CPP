/*! \file eventTreatment.hh
 *  \brief File containing the main menu events
 *  \author Karim El-Kharroubi --- Vincent LEFEBVRE
 *  \version 0.1
 *  \date 16/12/2020
 */


#ifndef __MAINMENUEVENTTREATMENT_HH__
#define __MAINMENUEVENTTREATMENT_HH__

#include "../app/headersLocation.hh"
#include USR_INTERFACE_H
#include BOARD_GI_H
#include APP_STATES_H
#include UNIT_H
static constexpr int QUIT = 0;
static constexpr int NEW_GAME = 1;

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

  if(clickedRt == QUIT)
    window.close();

  else if(clickedRt == NEW_GAME ){

    GameMap defaultMap(DEFAULT_SIZE,DEFAULT_SIZE,tab);
    
    Unit robot1(std::string("Nono"),45,0,std::make_pair<int,int>(4,0));
    Unit robot2(std::string("C3PELO"),45,1,std::make_pair<int,int>(2,0));
    
    std::vector<Unit> defaultUnits;

    defaultUnits.push_back(robot1);
    
    defaultUnits.push_back(robot2);

    (*theGame).reset(new Game(defaultMap,defaultUnits));

    std::cout << **theGame;
    
    usrInt->reset(new BoardGI(curH,curW,theGame));
    
    *appState = PLAYING;
  }
}



#endif