/*! \file effect.hh
 *  \brief A virtual class representing an effect
 *  \author Vincent Lefebvre 
 *  \version 0.1
 *  \date 20/12/16
 */

#ifndef __EFFECT_HH__
#define __EFFECT_HH__

    class Effect {
        enum class EffectAdjective:Char{NEUTRAL = -1,DETRIMENTAL, BENEFICIAL};
        public :
            virtual std::string getName() = 0;
            EffectAdjective getEffectAdjective(){return adjective};
        private :
            EffectAdjective adjective;
    };
#endif