/*! \file tile.hh
 *  \brief The file containing the tile class for inheritance
 *  \author Vincent Lefebvre 
 *  \version 0.1
 *  \date 20/12/16
 */



#ifndef __TILE_HH__
#define __TILE_HH__

#include "../../../graphics/tileGI.hh"

class Tile {

    private :
        
        std::unique_ptr<TileGI> graph;
        int tileType; 
        bool selected = false;
        std::string description;

    public :
        virtual int getTileType(){return tileType;};
        
        Tile(const Tile& cp) :  tileType(cp.tileType)
        {
         //   graph = std::make_unique<TileGI>(cp.getGI());
        };

        Tile(int tileType) : tileType(tileType) {};

        /*! \fn Tile()
         *  \brief Default tile constructor
         *
         *     This constructor serves for debug and for ensuring that Tile are well formed
         */
        Tile() : graph() ,tileType(2){};

        /*! \fn void setGI(TileGI theImp)
         *  \brief Compose the given graphic Implementation
         *
         *  \param theImp an implementation of the TileGI
         */
        
        void setGI(TileGI & theImp){graph = std::make_unique<TileGI>(theImp);};
        TileGI getGI() const{return *graph;};
        
        void select(){
            std::cout << "Im selected";
            selected = true;
        }
        
        bool isSelected(){
            return selected;
        }
        std::string toString()const{
            return description;
        }
};
 #endif
