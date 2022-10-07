#include "BinNode.h"
template <typename T> template<typename VST>
void BinNode<T>::travPre(VST& visit){
    switch(rand( )% 2){
        case 1: travPre_I(this, visit); break;
        default : travPre_R(this, visit); break;
    }
}