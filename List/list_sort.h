template <typename T>
void List<T>::sort(ListNodePosi<T> p, int n){
    switch (rand() % 4){
        case 1: insertionSort(p, n);break;//����
        case 2: selectionSort(p, n);break;//ѡ��
        case 3: mergeSort(p, n);break;//�鲢
        case 4: radixSort(p, n);break;//����
    }
}