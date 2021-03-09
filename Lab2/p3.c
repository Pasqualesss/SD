#include <stdio.h>
#include <stdlib.h>

void MergeSort(int *v,int n);
void Merge(int *A,int *L,int leftCount,int *R,int rightCount);

int main(){
    int v[]={5,7,1,4,6,9,123,6,10,12,5,78}, len, i;
    len = sizeof(v)/sizeof(v[0]);
    MergeSort(v,len);
    for(i=0;i<len;i++){
        printf("%d ", v[i]);
    }
    printf("\n");
    return 0;
}

void MergeSort(int *v,int n) {
	int middle,i, v_left[1000], v_right[1000];
	if(n < 2){
        return;
    }
	middle = n/2;
	for(i = 0;i<middle;i++){
        v_left[i] = v[i];
    }
	for(i = middle;i<n;i++){
        v_right[i-middle] = v[i];
    }
	MergeSort(v_left,middle);
	MergeSort(v_right,n-middle);
	Merge(v,v_left,middle,v_right,n-middle);
}

void Merge(int *v,int *v_left,int left,int *v_right,int right){
	int left_idx=0,right_idx=0,k=0;
	while(left_idx < left && right_idx < right){
		if(v_left[left_idx]  < v_right[right_idx]){
            v[k++] = v_left[left_idx++];
        }
		else{
            v[k++] = v_right[right_idx++];
        }
	}
	while(left_idx < left){
        v[k++] = v_left[left_idx++];
    }
	while(right_idx < right){
        v[k++] = v_right[right_idx++];
    }
}