/*! \file tileGI.cc
 *  \brief The tiles graphic implementation
 *  \author Vincent Lefebvre
 *  \version 0.1
 *  \date 20/12/16
 */

#include "tileGI.hh"
#include "../gameLogic/map/tiles/tile.hh"
#include "colors.hh"

/*! \fn TileGI::TileGI()
 *  \brief Creates an empty graphic implementation
 *  The implementation must be set after construction !
 */
TileGI::TileGI() {}

/*! \fn TileGI::~TileGI()
 *  \brief Destroys a tile graphic implementation
 *
 */
TileGI::~TileGI() {}
#include <iostream>
int TileGI::leftClickAction() {
  std::cout << "\nTile at X : " << northPosition.first
            << " Y : " << northPosition.second << " clicked";
  tile->select();
  return rtCode;

}
int TileGI::rightClickAction() {
  setQuadColor(outsideTile, Colors::TileColor::white);
  std::cout << "\nTile at X : " << northPosition.first
            << " Y : " << northPosition.second << " clicked";
  // setQuadColor(insideTile,sf::Color::Red);
  return 0;
}

/*! \fn void TileGI::getOutsideTile(sf::VertexArray square, int squareSize,int
 * outlineSize) \brief Creates an isometric tile on a quad Vertex Array
 *  \param squareSize   the square size before isometric transformation
 *  \param outlineSize  the size in pixel of the tile outline
 *  \return
 */

void TileGI::getOutsideTile(int squareSize, int outlineSize) {
  outsideTile[0].position =
      sf::Vector2f(northPosition.first, northPosition.second);
  outsideTile[1].position = sf::Vector2f(northPosition.first + squareSize,
                                         northPosition.second + squareSize / 2);
  outsideTile[2].position =
      sf::Vector2f(northPosition.first, northPosition.second + squareSize);
  outsideTile[3].position = sf::Vector2f(northPosition.first - squareSize,
                                         northPosition.second + squareSize / 2);
}

/*! \fn void TileGI::getInsideTile(sf::VertexArray square, int squareSize,int
 * outlineSize) \brief Creates an isometric tile on a quad Vertex Array
 *  \param squareSize   the square size before isometric transformation
 *  \param outlineSize  the size in pixel of the tile outline
 *  \return
 */

void TileGI::getInsideTile(int squareSize, int outlineSize) {

  insideTile[0].position =
      sf::Vector2f(northPosition.first, northPosition.second + outlineSize);
  insideTile[1].position = sf::Vector2f(
      outsideTile[1].position.x - outlineSize * 2, outsideTile[1].position.y);
  insideTile[2].position = sf::Vector2f(
      northPosition.first, northPosition.second + squareSize - outlineSize);
  insideTile[3].position =
      sf::Vector2f(northPosition.first - squareSize + outlineSize * 2,
                   northPosition.second + squareSize / 2);
}

/*! \fn TileGI::TileGI(std::shared_ptr<Tile>,std::pair<int, int> northPosition,  int squareSize, int outlineSize, int rtCode)
 *  \brief Creates a tile Graphics from a tile, a position and tile parameters
 *  \param tile tile that is displayed
 *  \param northPosition the position of the tile upper corner
 *  \param squareSize the size of the non isometric square in px
 *  \param outlineSize the size of the square outline in px
 *  \param rtCode the code that the tile returns when clicked on
 */
TileGI::TileGI(std::shared_ptr<Tile> tile, std::pair<int, int> northPosition,
               int squareSize, int outlineSize, int rtCode)
    : insideTile(sf::Quads, 4), outsideTile(sf::Quads, 4),
      northPosition(northPosition), tile(tile),
      rtCode(rtCode) {
  getOutsideTile(squareSize, outlineSize);

  setQuadColor(outsideTile, Colors::TileColor::ashes);

  getInsideTile(squareSize, outlineSize);

  setQuadColor(insideTile, Colors::getTileColor(tile->getTileType()));
}

void TileGI::setQuadColor(sf::VertexArray &theQuad,
                          Colors::TileColor theColor) {
  sf::Color tmp;

  for (int i = 0; i < 4; i++) {
    tmp = sf::Color(theColor);
    // tmp.a =255;
    theQuad[i].color = tmp;
  }
}
namespace triangle{
// Get a triangle Area
float area(int x1, int y1, int x2, int y2, int x3, int y3)
{ 
   return abs((x1*(y2-y3) + x2*(y3-y1)+ x3*(y1-y2))/2.0); 
} 

// Courtesy of stack overflow
// Check if a point is inside a triangle
bool isInside(
  int x1, 
  int y1,
  int x2,
  int y2,
  int x3,
  int y3, 
  int x, 
  int y) 
{    
   /* Calculate area of triangle ABC */
   float A = area (x1, y1, x2, y2, x3, y3); 
  
   /* Calculate area of triangle PBC */   
   float A1 = area (x, y, x2, y2, x3, y3); 
  
   /* Calculate area of triangle PAC */   
   float A2 = area (x1, y1, x, y, x3, y3); 
  
   /* Calculate area of triangle PAB */    
   float A3 = area (x1, y1, x2, y2, x, y); 
    
   /* Check if sum of A1, A2 and A3 is same as A */ 
   return (A == A1 + A2 + A3); 
} 

}
/*! \fn bool TileGI::isUnder(int mouse.first,int mouse.second)
 *  \brief Checks that a graphic implementation is under a clicked pixel
 *
 *  \param mouse the mouse XY position when clicked in pixel
 *  \return a boolean
 */

bool TileGI::isUnder(std::pair<int, int> mouse) {
  
  bool rt = false;

  // Inside X
  if ((mouse.first < outsideTile[1].position.x && mouse.first > outsideTile[3].position.x)
      // Inside Y
      &&
      (mouse.second < outsideTile[2].position.y && mouse.second > outsideTile[0].position.y)
      
  ){
    // Right side of the tile
    if(mouse.first > outsideTile[0].position.x){
       rt = triangle::isInside(
        outsideTile[0].position.x,
        outsideTile[0].position.y,
        outsideTile[1].position.x,
        outsideTile[1].position.y,
        outsideTile[2].position.x,
        outsideTile[2].position.y,
        mouse.first,
        mouse.second);
    }
    else{
      rt = triangle::isInside(
        outsideTile[0].position.x,
        outsideTile[0].position.y,
        outsideTile[2].position.x,
        outsideTile[2].position.y,
        outsideTile[3].position.x,
        outsideTile[3].position.y,
        mouse.first,
        mouse.second);
    }
      
    }
  


  return rt;
}
