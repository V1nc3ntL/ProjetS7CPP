 #include "gameMap.hh"
 #include "tiles/tile.hh"
#include "tiles/normalTile.hh"
#include "../../graphics/mapGI.hh"

 /*! \fn  GameMap::GameMap(int w, int h,int* tileTypes) 
  *  \brief Creates a game map as indicated by an array of tile
  *
  *  \param w the map width in px
  *  \param h the map height in px
  *  \param tileTypes an array of int describing a map 
  */
 GameMap::GameMap(int w, int h,int* tileTypes) 
            : width(w),height(h)
            {
                std::pair<int,int> northPosition;
              
                // Serialized access
                for(int i = 0 ; i < w*h ; i++){
                    tiles.push_back(
                            std::make_shared<Tile>(tileTypes[i])
                    );   
                }
                graph = std::make_unique<MapGI>(width,height,*this);
            }

            void GameMap::setGI(MapGI& mGI){
                graph = std::make_unique<MapGI>(mGI); 
            }

            /*! \fn  MapGI GameMap::getGI() const
             *  \brief give the current graphic implementation of the map
             *  \return the graphic implementation
             */
            MapGI GameMap::getGI() const{
                return *graph;
            }

            /*! \fn  std::unique_ptr<MapGI>* GameMap::getPtGi()
             *  \brief give a pointer on an unique pointer to the graphic implementation of the map
             *  \return a pointer to the unique pointer to the graphic implementation
             */
            std::unique_ptr<MapGI>* GameMap::getPtGi(){
                return &graph;
            }

            GameMap::GameMap(const GameMap& cp) : width(cp.width),height(cp.height), tiles(cp.getTiles()) {
                    graph = std::make_unique<MapGI>(cp.getGI());
            }

