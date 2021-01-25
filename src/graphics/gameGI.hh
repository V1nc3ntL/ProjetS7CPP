/*! \file gameGI.hh
 *  \brief A game graphical interface, dysplaying units,map, and an overlay for the current case
 *  \author Vincent Lefebvre 
 *  \version 0.1
 *  \date 21/01/25
 */
#ifndef __GAMEGI_HH__
#define __GAMEGI_HH__
#include "unitGI.hh"

    class GameGI : public sf::Drawable{
        
        private: 
            
            MapGI theMap;
            
            std::vector<Unit> units;

            std::vector<UnitGI> unitsGI;
          
        public : 

           GameGI(int& windowWidth, int& windowHeight , std::unique_ptr<Game>*& game) :
           theMap(windowWidth,windowHeight,(*game)->getMap()),
           units((*game)->getUnits()){
                for(Unit u : units){
                    unitsGI.push_back(UnitGI(u,theMap));
                 }
           }
             std::shared_ptr<TileGI> getClickedOn(std::pair<int,int>mouse) const{
                 return theMap.getClickedOn(mouse);
             }

             virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const {
                 target.draw(theMap);
                 for(UnitGI u : unitsGI){
                    target.draw(u);
                 }
                 
             }

    };

#endif