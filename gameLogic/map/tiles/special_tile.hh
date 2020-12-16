/*! \file tile.hh
 *  \brief The file containing the tile class for graphic representation
 *  \author Vincent Lefebvre 
 *  \version 0.1
 *  \date 20/12/16
 */
 #ifndef __SPECIAL_TILE_HH__
 #define __SPECIAL_TILE_HH__
 
class SpecialTile : public Tile {
    public :
       bool getTileType(){return 0;};  
       radiatingEffect getEffect(){return effect;}
    private :
        radiatingEffect effect;
}
 #endif
