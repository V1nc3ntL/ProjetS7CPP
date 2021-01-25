/*! \file graphicImp.hh
 *  \brief The interface that every graphic implementation must follow
 *  \author Karim El-Kharroubi --- Vincent LEFEBVRE
 *  \version 0.1
 *  \date 21/01/04
 */


class GI{
    public:
        virtual ~GI();
        virtual setGI(GI& gI)=0;
}