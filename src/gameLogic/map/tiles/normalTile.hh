/*! \file normalTile.hh
 *  \brief The file containing the standard (i.e without effects) tiles
 *  \author Vincent Lefebvre 
 *  \version 0.1
 *  \date 20/12/16
 */
 #ifndef __NORMAL_TILE_HH__
 #define __NORMAL_TILE_HH__


class NormalTile : public Tile {
    
    public:
        // Inherited attribute cannot be initialized through
        // the initialization list in a derived class
        NormalTile(int tileType) {
            tileType = tileType;
        };

        NormalTile() : NormalTile(0){};
        ~NormalTile() {};

        int getTileType(){return 0;}; 

       

};

 #endif
