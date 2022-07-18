template <typename T>
void List<T>::sort(ListNodePosi<T> p, int n){
    switch (rand() % 4){
        case 1: insertionSort(p, n);break;//插入
        case 2: selectionSort(p, n);break;//选择
        case 3: mergeSort(p, n);break;//归并
        case 4: radixSort(p, n);break;//基数
    }
}