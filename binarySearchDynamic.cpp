#include<bits/stdc++.h>
#include "binarySearchDynamic.h"

DBinarySearch::DBinarySearch(){
    N = 1;
    maxLayer = 1;//number of layer 
	base = 0;// the index of base laye
	ptr = new int*[1];
	ptr[0] = new int[1];

	isDelete = new bool*[1];
	isDelete[0] = new bool[1];

	isFull = new bool[1];
	numDelete = new int[1];
}

bool DBinarySearch::insert(int n){
	if(find(n) != -1)return false;
	N++;
	if(isFull[0] != 1){
		ptr[0] = new int[1];
		ptr[0][0] = n;
		isFull[0] = 1;
		isDelete[0][0] = 0;
	}
	else {
		isFull[0] = 0;
		bool* inserted_del;// = (bool*) malloc(1*sizeof(bool));
		inserted_del = new bool[1];
		inserted_del[0] = 0;
		merge(&n, ptr[0], inserted_del,isDelete[0], 0);
	}	
	return true;
}

void DBinarySearch::merge(int* l0, int* l1, bool* del_0 ,bool* del_1, int layer){
	int size = len(layer);
	int* result = new int[2*size];
	bool* res_del = new bool[2*size];
	int p0 = size-1, p1 = size-1, pr = (2*size) -1;

	while((p0 >= 0) || (p1 >= 0)){
		if(p0 < 0){
			while(p1 >= 0){
				result[pr] = l1[p1];
				res_del[pr] = del_1[p1];
				p1--;
				pr--;
			}
			break;
		} else if(p1 < 0){
			while(p0 >= 0){
				result[pr] = l0[p0];
				res_del[pr] = del_0[p0];
				p0--;
				pr--;
			}
			break;
		} else if(l0[p0] >= l1[p1]){
			result[pr] = l0[p0];
			res_del[pr] = del_0[p0];
			p0--;
		} else if(l1[p1] >= l0[p0]){
			result[pr] = l1[p1];
			res_del[pr] = del_1[p1];
			p1--;
		}
		pr--;
	}
	
	if(base*2 >= (maxLayer-1)/2)resize(2*maxLayer);
	if(layer!=0){
		isFull[layer-1] = 0;
		for(int i=0;i<len(layer-1);i++){
			isDelete[layer-1][i] = 0;
		}
	}
	isFull[layer]=0;
	for(int i=0;i<len(layer);i++){
		isDelete[layer][i] = 0;
	}
	push(result, res_del, layer);
}


void DBinarySearch::resize(int sizeLayer){

	bool *new_isFull = new bool[sizeLayer];

	int **new_ptr = new int*[sizeLayer];
	bool **new_isDelete = new bool*[sizeLayer];

	for(int i=0;i<=base;i++){
		new_ptr[i] = new int(*ptr[i]);
		new_isDelete[i] = new bool(*isDelete[i]);
		new_isFull[i] = isFull[i];
	}

	ptr = new_ptr;
	isDelete = new_isDelete;
	isFull = new_isFull;

	maxLayer = sizeLayer;
}

void DBinarySearch::push(int* list, bool* res_del, int layer){
	if(isFull[layer+1] == 0){
	   	ptr[layer+1] = list;
		isDelete[layer+1] = res_del;
		
		isFull[layer] = 0;
		
		isFull[layer+1] = 1;
		base = max(base, layer + 1);	
	}
	else {
		merge(ptr[layer+1], list, isDelete[layer+1], res_del, layer+1);
	}
	
}


int DBinarySearch::search(int target, int layer){
	int size = 1<<layer;
	if(layer > base){
		return -1;
	}
	int l=0, r=size-1, m;
	while(r>=l){
		m = (l+r) /2;
		if(ptr[layer][m] > target){
			r = m-1;
		} 
		else if(ptr[layer][m] < target){
			l = m+1;
		}
		else {
			if(isDelete[layer][m] == 0 && isFull[layer] == 1){
				return (1<<layer) + m - 1;
			}
			else {
				if(layer == base)
					return -1;
				else{
					break;
				}
			}
		} 	
	}

	return search(target, layer+1);	
}



bool DBinarySearch::remove(int target){
	int index_target = find(target);
	if(index_target == -1) {
		return 0;
	}
	int layer_target = int(log2(index_target+1));
	int pos_target = index_target - (1<<layer_target) + 1;
	int size = len(layer_target);
	N--;
	isDelete[layer_target][pos_target] = 1;
	numDelete[layer_target]++;	
	
	if(numDelete[layer_target] == (size/2)){
		int* tidy = new int[size/2];
		bool* t_del = new bool[size/2];
		int p_tidy = 0;
		for(int i=0;i<size/2;i++){
			t_del[i] = 0;
		}
		for(int i=0;i<size;i++){
			if(!isDelete[i]){
				tidy[p_tidy] = ptr[layer_target][i];
				isDelete[i] = 0; // update state

			}
		}
		if(isFull[layer_target-1]){
			merge(tidy, ptr[layer_target-1],t_del, isDelete[layer_target-1],layer_target-1);
		}
		else {
			// pull up the layer to upper one layer
			if (layer_target == base){
				base--;
			}
			ptr[layer_target-1] = tidy;
			isDelete[layer_target-1] = t_del;
			isFull[layer_target-1] = 1;
			isFull[layer_target] = 0;
		}
//		delete[] tidy;
//		delete[] t_del;	
	}
	
	return 1;
}


void DBinarySearch::print_element(){;	
	for(int i=0;i<=base;i++){
		for(int j=0;j<(1<<i);j++){
			if(!isFull[i])printf("-");
			else 
				if(isDelete[i][j]){
					printf("-");
					continue;
				}
				else{
					printf("%d ", ptr[i][j]);
				}
		}
		std::cout<<std::endl;
	}
}

