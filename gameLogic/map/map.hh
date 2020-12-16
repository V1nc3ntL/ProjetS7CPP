/*! \file map.hh
 *  \brief A class to describe a map in the game
 *  \author Vincent Lefebvre 
 *  \version 0.1
 *  \date 20/12/16
 */
#ifndef __MAP_HH__
#define __MAP_HH__

#include <vector>
#include "tiles/tile.hh"
    
    typedef std::vector<std::vector<std::vector<Tile>>> tiles   ;  /*! Here for better Code readability */

    class Map {
            /*! \fn Map(int d, int w, int h)
             *  \brief Map Constructor with depth,height and width as integers
             */
            
            Map(int d, int w, int h) : depth(d),width(w),height(h){

            };
            /*! \fn getDepth
             *  \brief getter to get the depth of a map
             *! \return int the depth of the map
             */
            int getDepth(){return depth;};
            /*! \fn getWidth
             *  \brief getter to get the width of a map
             *! \return int the width of the map
             */
            int getWidth(){return width;};
            /*! \fn getHeight
             *  \brief getter to get the height of a map
             *! \return int the width of the map
             */
            int getHeight(){return height;};
        private :
            
            int depth;
            int width;
            int height;

            tiles map;
    };
#endif