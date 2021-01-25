
/*! \file actions.hh
 *  \brief A namespace acting as an enum for constexpr int
 *  \author Vincent Lefebvre 
 *  \version 0.1
 *  \date 21/01/25
 */
#ifndef __ACTIONS_HH__
#define __ACTIONS_HH__

namespace actions{
static constexpr int NOTHING = -1;
constexpr int NEW_GAME = 1;
constexpr int QUIT = 0;

constexpr int END_TURN = DEFAULT_SIZE*DEFAULT_SIZE+1;
}
#endif
