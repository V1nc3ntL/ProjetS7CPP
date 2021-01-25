/*! \file tileGI.hh
 *  \brief The file containing the tile class for graphic representation
 *  \author Vincent Lefebvre
 *  \version 0.1
 *  \date 20/12/16
 */

#ifndef __TILE_GRAPHIC_IMP_HH__
#define __TILE_GRAPHIC_IMP_HH__
#include "../events/clickable.hh"
#include "colors.hh"
#include <SFML/Graphics.hpp>
#include <iostream>
#include <memory>


class Tile;

class TileGI : public sf::Drawable, public  Clickable {

public:
  ~TileGI();
  TileGI();
  TileGI(std::pair<int, int> northPosition, int squareSize, int outlineSize);
  TileGI(const std::shared_ptr<Tile> tile, std::pair<int, int> northPosition,
         int squareSize, int outlineSize,int rtCode);
/*
  TileGI(const std::shared_ptr<Tile> tile, std::pair<int, int> northPosition,
         int squareSize, int outlineSize)
      : TileGI(tile, northPosition, squareSize, outlineSize,
               Colors::TileColor::ashes){};*/

  virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const {
    target.draw(outsideTile);
    target.draw(insideTile);
  }

  virtual int leftClickAction();
  virtual int rightClickAction();
  
  std::pair<int,int>leftAngle()const{
    return std::make_pair<int,int>(insideTile[3].position.x,insideTile[3].position.y);
  }
  
  bool isUnder(std::pair<int , int >mouse);

private:

  void setQuadColor(sf::VertexArray &theQuad, Colors::TileColor theColor);

  void getOutsideTile(int squareSize, int outlineSize);

  void getInsideTile(int squareSize, int outlineSize);

  sf::VertexArray insideTile;

  sf::VertexArray outsideTile;

  std::pair<int, int> northPosition;

  Colors::TileColor color;

  std::shared_ptr<Tile> tile;

  int rtCode;
};
#endif
