/*! \file tile.hh
 *  \brief The file containing the standard (i.e without effects) tiles
 *  \author Vincent Lefebvre 
 *  \version 0.1
 *  \date 20/12/16
 */
 #ifndef __NORMAL_TILE_HH__
 #define __NORMAL_TILE_HH__
 
class NormalTile : public Tile {
    public :
       bool getTileType(){return 0;};  
}
 #endif
