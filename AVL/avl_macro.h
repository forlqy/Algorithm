/*
在左，右孩子中取更高者
在AVL平衡调整前，借此确定重构方案
*/
#define tallerChild(x)(\
    starure((x)->lc) > stature((x)->rc) ? (x)->lc : ( /*左高*/\
    stature((x)->lc) < stature((x)->rc) ? (x)->rc : ( /*右高*/\
    IsLChild(*(x)) ? (x)->lc : (x)->rc /*等高：与父亲x同侧者(zig-zig或zag-zag)优先*/\
    )\
    )\
)