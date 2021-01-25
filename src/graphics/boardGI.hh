#/*! \file boardGI.hh
 *  \brief the board graphic implementation, containing a map and units
 *  \author Vincent Lefebvre 
 *  \version 0.1
 *  \date 21/01/24
 */

#ifndef __BOARD_GRAPHIC_IMP_HH__
#define __BOARD_GRAPHIC_IMP_HH__

#include "mapGI.hh"
#include "spriteButtonGI.hh"
#include EVENTS_H
#include USR_INTERFACE_H
#include GAME_H
#include GAME_GI_H
#include ACTIONS_H

static constexpr int END_TURN_BUTTON_SIZE = 150;
static constexpr int TURN_TEXT_HEIGHT = 50;

    class BoardGI : public  usrInterface {
        public :
        /*Creates a board from a game
        */
       // BoardGI(MapGI map) : theMap(map){};


        BoardGI(int &windowWidth, int &windowHeight, std::unique_ptr<Game>* game) :
            _game(**game),
            gGI (windowWidth,windowHeight,game),
           
            nextTurnButton(std::make_pair<int,int>(windowWidth-END_TURN_BUTTON_SIZE-MARGIN,
                windowHeight-END_TURN_BUTTON_SIZE-MARGIN), "hourGlass.png",actions::END_TURN),
            turn( 
                std::make_pair<int,int>( windowWidth-END_TURN_BUTTON_SIZE,windowHeight-END_TURN_BUTTON_SIZE-TURN_TEXT_HEIGHT-MARGIN),
                END_TURN_BUTTON_SIZE-TURN_TEXT_HEIGHT-15,TURN_TEXT_HEIGHT,
                (*game)->getTurnStr(),actions::END_TURN,MARGIN)
            {};
        
         std::shared_ptr<Clickable> getClickedOn(std::pair<int,int>mouse) const{
             std::shared_ptr<Clickable> tmp;
             
             if( nextTurnButton.isUnder(mouse))
                tmp = std::make_shared<SpriteButtonGI>(nextTurnButton);
             else
                tmp = gGI.getClickedOn(mouse);

            return tmp;
         }

        virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const {
            target.draw(gGI);
            target.draw(nextTurnButton);
            target.draw(turn);
        }


        
        private :
            
            Game _game;
            GameGI gGI;
            SpriteButtonGI nextTurnButton;
            ButtonGI turn;
            
            
    };
#endif