#include "BinNode.h"

template <typename T> template <typename VST>
void BinNode<T>::travIn(VST& visit){
    switch(rand() % 5){
        case 1: travIn_I1(this, visit); break;//µü´ú°æ1
        case 2: travIn_I2(this, visit); break;//2
        case 3: travIn_I3(this, visit); break;//3
        case 4: travIn_I4(this, visit); break;//4
        default: travIn_R(this, visit); break;//µÝ¹é
    }
}