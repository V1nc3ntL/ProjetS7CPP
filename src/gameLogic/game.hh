/*! \file game.hh
 *  \brief Class to describe a game
 *  \author Vincent Lefebvre Karim El-Kharroubi
 *  \version 0.1
 *  \date 21/01/25
 */
#ifndef __GAME_HH__
#define __GAME_HH__
#include <iostream>
#include <sstream>  
#include "../app/headersLocation.hh"
#include LOCALIZATION_H
#include UNIT_H
#include MAP_H

    class Game{
        public :
        

            Game(GameMap& map) : map(map){};
            Game(GameMap& map,std::vector<Unit>& units) : 
                map(map),
                units(units){};   

            GameMap& getMap(){return map;}

            void nextTurn(){
                for(Unit u: units)
                    u.updateMovements();
                curTurn++;
            }

            int getTurn()const{return curTurn;}
            
            friend std::ostream& operator<<(std::ostream& os,const Game& s){
                os << s.toString();
                return os;
            }
            
            std::vector<Unit> getUnits()const{return units;} 
            
            std::string getTurnStr()const{
                std::stringstream oss;
                oss << curTurn;
                return oss.str();
            }

            std::string toString()const{
                std::stringstream oss;
                oss << "\n" << localization::turn  << curTurn;
                    for(Unit u: units)
                        oss << "\t" << u.toString();

                return oss.str();
            }
        private:
            //unit
       
            int curTurn = 0;
            
            GameMap map;

            std::vector<Unit> units;
    };

#endif