#/*! \file infoTextGI.hh
 *  \brief the board graphic implementation, containing a map and units
 *  \author Vincent Lefebvre 
 *  \version 0.1
 *  \date 21/01/24
 */

#ifndef __INFO_TXT_HH__
#define __INFO_TXT_HH__

#include "mapGI.hh"
#include "spriteButtonGI.hh"
#include USR_INTERFACE_H
#include PLAY_EVENTS_H
#include GAME_H

constexpr int END_TURN_BUTTON_SIZE = 150;
constexpr int TURN_TEXT_HEIGHT = 50;

    class infoTextGI : public  sf::Drawable {
        public :


        BoardGI(int &windowWidth, int &windowHeight, std::unique_ptr<Game>* game) :
            theMap (windowWidth,windowHeight,(*game)->getMap()),
            nextTurnButton(windowWidth-END_TURN_BUTTON_SIZE-MARGIN,
                windowHeight-END_TURN_BUTTON_SIZE-MARGIN, "hourGlass.png",actions::END_TURN),
            turn( windowWidth-END_TURN_BUTTON_SIZE,
                windowHeight-END_TURN_BUTTON_SIZE-TURN_TEXT_HEIGHT-MARGIN,
                END_TURN_BUTTON_SIZE-TURN_TEXT_HEIGHT-15,TURN_TEXT_HEIGHT,(*game)->getTurnStr(),actions::END_TURN,MARGIN) ,game(**game)
            {};
        
         std::shared_ptr<Clickable> getClickedOn(std::pair<int,int>mouse) const{
             std::shared_ptr<Clickable> tmp;
             
             if( nextTurnButton.isUnder(mouse))
                tmp = std::make_shared<SpriteButtonGI>(nextTurnButton);
             else
                tmp = theMap.getClickedOn(mouse);

            return tmp;
         }

        virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const {
            target.draw(theMap);
            target.draw(nextTurnButton);
            target.draw(turn);
        }


        
        private :
            MapGI theMap;
            sf::Text
            
            Game game;
            
    };
#endif