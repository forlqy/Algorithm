template <typename T>
ListNodePosi<T> List<T>::selectMax(ListNodePosi<T> p, int n){//从起始于位置p的n个元素中选出最大者
    ListNodePosi<T> max = p;//最大者暂定为首节点p
    for (ListNodePosi<T> cur = p; 1 < n; n--)
      if (!lt((cur = cur->succ)->data, max->data))//若当前元素不小于max,则
        max = cur;//更新最大元素位置记录
    return max;//返回最大节点位置
}