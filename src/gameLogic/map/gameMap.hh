/*! \file gameMap.hh
 *  \brief A class to describe a gameMap in the game
 *  \author Vincent Lefebvre 
 *  \version 0.1
 *  \date 20/12/16
 */
#ifndef __GAME_MAP_HH__
#define __GAME_MAP_HH__

#include <vector>
#include <memory>

class MapGI;
class Tile;

// Taille standard à la compilation
constexpr int DEFAULT_SIZE= 8;

// Les liaisons structurées ne peuvent pas être constexpr
// On utilise les macros

    class GameMap {
        public :
            /*! \fn gameMap(int d, int w,int*  tileTypes)
             *  \brief gameMap Constructor with height and width as integers
             */   
            GameMap(int w, int h,int* tileTypes) ;


            void setGI(MapGI& mGI);

            /*! \fn  GameMap& getGI()
             *  \brief give the current graphic implementation of the map
             *  \return the graphic implementation
             */
            MapGI getGI() const;

            /*! \fn  GameMap& getPtGi()
             *  \brief give a pointer on an unique pointer to the graphic implementation of the map
             *  \return a pointer to the unique pointer to the graphic implementation
             */
            std::unique_ptr<MapGI>* getPtGi();

            GameMap(const GameMap& cp) ;


             /*! \fn getWidth
             *  \brief getter to get the depth of a gameMap
             *! \return int the depth of the gameMap
             */
            int getWidth()const{return width;};
            
            /*! \fn getHeight
             *  \brief getter to get the height of a gameMap
             *! \return int the width of the gameMap
             */
            int getHeight()const{return height;};

                       
            /*! \fn getTiles
             *  \brief getter to get the Tiles of a gameMap
             *! \return std::vector<std::shared_ptr<Tile>> the tiles of the map
             */

            std::vector<std::shared_ptr<Tile>> getTiles() const{
                return tiles;
            }


        private :
            
            int width = DEFAULT_SIZE;
            int height = DEFAULT_SIZE;
            int selected = -1;
            std::vector<std::shared_ptr<Tile>> tiles ;  
            std::unique_ptr<MapGI> graph;          
    };
#endif