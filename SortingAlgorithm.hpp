#pragma once

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

namespace SortLibrary {
template<typename T> 
void BubbleSort(vector<T> &v){
	for(int i=0; i<v.size()-1; i++){ //quanti giri ho fatto
		for(int j=0; j<v.size()-i-1; j++) { //si riduce perchè parte dx già ordinata
			if(v[j]>v[j+1])
				swap(v[j],v[j+1]);
		}
	}
}

template<typename T> 
void heapify(vector<T> &v, int n, int i){
	int largest=i;
	int left=2*i+1;
	int right=2*i+2;
	if (left<n && v[left]>v[largest]){
		largest=left;
	}
	if (right<n && v[right]>v[largest]){
		largest=right;
	}
	if (largest!=i){
	   swap(v[largest], v[i]);
	   heapify(v, n, largest);
	}
	
	
}

template<typename T> 
void HeapSort(vector<T> &v){
	for(int i=v.size()/2-1; i>=0; i--){
		heapify(v, v.size(), i);
		
	}
	for(int i=v.size()-1; i>0; i--){
		swap(v[0], v[i]);
		heapify(v, i, 0); 
	}		
}   


