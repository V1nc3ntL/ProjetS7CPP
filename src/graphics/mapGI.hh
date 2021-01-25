/*! \file mapGI.hh
 *  \brief The graphic implementation of a map
 *  \author Vincent Lefebvre
 *  \version 0.1
 *  \date 20/12/16
 */
#ifndef __MAP_GRAPHIC_IMP_HH__
#define __MAP_GRAPHIC_IMP_HH__

#include "../gameLogic/map/tiles/tile.hh"
#include <iostream>
#include <vector>
#include "buttonGI.hh"
// Forward declaration
class GameMap;


class MapGI : public sf::Drawable {

public:
  /*! \fn MapGI::MapGI()
   *  \brief Creates an empty graphic implementation
   *  The implementation must be set after construction !
   */
  MapGI(){};
  /*! \fn MapGI::~MapGI()
   *  \brief Destroys a map graphic implementation
   *
   */
  ~MapGI(){};

  /*! \fn MapGI(int & windowWidth,int & windowHeight, GameMap & map)
   *  \brief Creates graphic from a gameMap and a Window size
   *
   *  \param windowWidth the width of the window where the map is displayed
   *  \param windowHeight the height of the window where the map is displayed
   *  \param map the gameMap to obtain
   */
  MapGI(int & windowWidth, int & windowHeight, GameMap & map);
  
  /*! \fn    void createMapGraphs(std::pair<int,int> & northPosition,std::vector<std::shared_ptr<Tile>>::iterator it );
   *  \brief Creates the sub-graphic implementation
   *  \param northPosition the northern corner position of the map
   *  \param it an iterator on a vector of shared pointer to the game Logic tile
   */
  void createMapGraphs(std::pair<int, int> &northPosition,
                       std::vector<std::shared_ptr<Tile>>::iterator it);
  /*! \fn std::shared_ptr<Clickable> getClickedOn(int mouse.first,int mouse.second)
   *  \brief Retrieve the clicked tile from the map
   *
   *  \param mouse the pair of the click xy coordinates
   *  \return
   */
  std::shared_ptr<TileGI> getClickedOn(std::pair<int,int>mouse) const;

  virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const {
    std::vector<TileGI>::const_iterator it;
    for (it = tls.begin(); it < tls.end(); it++)
      target.draw(*it);
  }
TileGI  getTileAt(std::pair<int,int> pos);
  std::vector<TileGI> getTiles()const{return tls;} 
    int getSquareSize() const;
private:
  int width, height, sqH, sqW, outline = 5;
  int squareSize;
  std::vector<TileGI> tls;
  int lastSelected = -1;

};
#endif