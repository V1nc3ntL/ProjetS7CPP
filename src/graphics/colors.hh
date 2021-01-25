/*! \file colors.hh
 *  \brief The enum and various color used
 *  \author Vincent Lefebvre Karim El Kharroubi
 *  \version 0.1
 *  \date 21/01/05
 */
#ifndef __COLORS_HH__
#define __COLORS_HH__

#include <SFML/Graphics.hpp>
// Forward declaration to access the enum inside the struct
enum TileColor : short;

struct Colors
{
    enum TileColor { 
       ashes = (sf::Uint32) 0x4712128,
        mud = (sf::Uint32) 0x8e3d2b, 
        sand = (sf::Uint32) 0xc48b07,
        white = (sf::Uint32) 0xffffff    };
    
    static constexpr int NB_COLORS = 4 ;
    static constexpr TileColor colors[NB_COLORS] = {ashes,mud,sand,white} ;
   
    static  TileColor getTileColor(int i){
       return TileColor(i);
    }
    
};

#endif