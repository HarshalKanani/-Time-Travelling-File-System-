#include "Heap2.h"
#include <algorithm>

heap2::heap2(){
    size=0;
    arr.clear();
}
void heap2::insert(File* val){
    arr.push_back(val);
    size++;
    int idx=size-1;
    val->ind_in_heap2=idx;
    arr[idx]->ind_in_heap2=idx;
    while (idx>0){
        int parent=(idx-1)/2;
        if (arr[parent]->last_updated<arr[idx]->last_updated){
            swap(arr[parent], arr[idx]);
            swap(arr[parent]->ind_in_heap2, arr[idx]->ind_in_heap2);
            idx=parent;
        }
        else{
            break;
        }
    }
}
void heap2::check(File* val){
    int idx=val->ind_in_heap2;
    while (idx>0){
        int parent=(idx-1)/2;
        if (arr[parent]->last_updated<arr[idx]->last_updated){
            swap(arr[parent], arr[idx]);
            swap(arr[parent]->ind_in_heap2, arr[idx]->ind_in_heap2);
            idx=parent;
        }
        else{
            break;
        }
    }
}
time_t heap2::getMax(){
    if (size==0) return -1;
    return arr[0]->last_updated;
}
void heap2::deleteMax(){
    if (size==0) return;
    arr[0]=arr[size-1];
    arr[0]->ind_in_heap2=0;
    arr.pop_back();
    size--;
    int idx=0;
    while (idx<size){
        int left=2*idx+1;
        int right=2*idx+2;
        int largest=idx;
        if (left<size && arr[left]->last_updated>arr[largest]->last_updated) largest=left;
        if (right<size && arr[right]->last_updated>arr[largest]->last_updated) largest=right;
        if (largest!=idx){
            swap(arr[largest], arr[idx]);
            swap(arr[largest]->ind_in_heap2, arr[idx]->ind_in_heap2);
            idx=largest;
        }
        else{
            break;
        }
    }
}
