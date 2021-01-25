/*! \file mapGI.cc
 *  \brief The maps graphic implementation
 *  \author Vincent Lefebvre
 *  \version 0.1
 *  \date 20/12/16
 */

#include "mapGI.hh"
#include "../gameLogic/map/gameMap.hh"

/*! \fn MapGI::MapGI(int & windowWidth,int & windowHeight, GameMap & map)
 *  \brief Creates a map centered on the window
 *
 *  \param windowWidth the window width
 *  \param windowHeight the window height
 */
MapGI::MapGI(int & windowWidth, int & windowHeight, GameMap &map)
    : width(windowWidth), height(windowHeight), sqH(map.getHeight()),
      sqW(map.getWidth()), squareSize(getSquareSize()) {
  std::vector<std::shared_ptr<Tile>> tmp = map.getTiles();

  std::vector<std::shared_ptr<Tile>>::iterator it = tmp.begin();

  std::pair<int, int> northPosition(windowWidth / 2,
                                    windowHeight / 2 - squareSize / 2 * sqH);

  createMapGraphs(northPosition, it);
}
/*! \fn MapGI::createMapGraphs(std::pair<int, int> &northPosition, std::vector<std::shared_ptr<Tile>>::iterator it)
 *  \brief Creates a graphic representation of a map from an iterator on a
 * vector of tile beyond the northPosition
 *
 *  \param std::pair<int,int>& a reference to a pair of int representing the
 * north corner of the map to be created \param
 * std::vector<std::shared_ptr<Tile>>::iterator an iterator initialized on the
 * first tile
 */

void MapGI::createMapGraphs(std::pair<int, int> &northPosition,
                            std::vector<std::shared_ptr<Tile>>::iterator it) {

  std::pair<int, int> nPL = northPosition;

  std::pair<int, int> max(sqH, sqW);

  int i = 0, j = 0;

  if (sqH > sqW)
    std::swap(max.first, max.second);

  for (j = 0; j < max.first; j++) {
    northPosition = nPL;
    for (i = 0; i < max.second; i++) {
      tls.push_back(TileGI(*it++, northPosition, squareSize, outline,j*max.second+i));
      northPosition.first -= squareSize - outline;
      northPosition.second += squareSize / 2 - outline / 2;
    }
    nPL.first += squareSize - outline;
    ;
    nPL.second += squareSize / 2 - outline / 2;
    northPosition = nPL;
  }
}

int MapGI::getSquareSize() const {
  return (sqH > sqW ? height / sqH - outline - MARGIN
                    : height / sqW - outline - MARGIN);
}


TileGI  MapGI::getTileAt(std::pair<int,int> pos){
  return tls[pos.first*sqW+pos.second];

}
std::shared_ptr<TileGI> MapGI::getClickedOn(std::pair<int,int>mouse) const {

    std::shared_ptr<TileGI> tmp;

    for (TileGI t : tls)
      if (t.isUnder(mouse)) {
        tmp = std::make_shared<TileGI>(t);
        break;
      }
    return tmp;
  }
