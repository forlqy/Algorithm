#include "BinNode.h"
template <typename T> template<typename VST>
void BinNode<T>::travPost(VST& visit){
    switch (rand()%2) {
    case 1: travPost_I(this, visit); break;//µü´ú°æ
    default : travPost_R(this, visit); break;//µÝ¹é°æ
    }
}