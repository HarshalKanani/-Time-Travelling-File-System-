#include "Heap1.h"
#include <algorithm>

heap1::heap1(){
    size=0;
    arr.clear();
}
void heap1::insert(File* val){
    arr.push_back(val);
    size++;
    int idx=size-1;
    val->ind_in_heap1=idx;
    while (idx>0){
        int parent=(idx-1)/2;
        if (arr[parent]->total_versions<arr[idx]->total_versions){
            swap(arr[parent], arr[idx]);
            swap(arr[parent]->ind_in_heap1, arr[idx]->ind_in_heap1);
            idx=parent;
        }
        else{
            break;
        }
    }
}
void heap1::check(File* val){
    int idx=val->ind_in_heap1;
    while (idx>0){
        int parent=(idx-1)/2;
        if (arr[parent]->total_versions<arr[idx]->total_versions){
            swap(arr[parent], arr[idx]);
            swap(arr[parent]->ind_in_heap1, arr[idx]->ind_in_heap1);
            idx=parent;
        }
        else{
            break;
        }
    }
}
int heap1::getMax(){
    if (size==0) return -1;
    return arr[0]->total_versions;
}
void heap1::deleteMax(){
    if (size==0) return;
    arr[0]=arr[size-1];
    arr[0]->ind_in_heap1=0;
    arr.pop_back();
    size--;
    int idx=0;
    while (idx<size){
        int left=2*idx+1;
        int right=2*idx+2;
        int largest=idx;
        if (left<size && arr[left]->total_versions>arr[largest]->total_versions) largest=left;
        if (right<size && arr[right]->total_versions>arr[largest]->total_versions) largest=right;
        if (largest!=idx){
            swap(arr[largest], arr[idx]);
            swap(arr[largest]->ind_in_heap1, arr[idx]->ind_in_heap1);
            idx=largest;
        }
        else{
            break;
        }
    }
}
