#include<bits/stdc++.h>
using namespace std;

void printArray(int* a , int size){
    for(int i = 0; i<size; i++){
        cout << a[i] << " " ;
    }
    cout << endl;
}

void mergeTwoSortedArrays(int* arr1 , int size1, int* arr2, int size2){

    int i = 0, j = 0, k = 0;
    int* mergedArray = new int[size1+size2];
   
    while(i<size1 && j<size2){
        if(arr1[i]<arr2[j]){
            mergedArray[k++] = arr1[i++];
        }else{
            mergedArray[k++] = arr2[j++];
        }
    }

    while(i<size1){
        mergedArray[k++] = arr1[i++];
    }

    while(j<size2){
        mergedArray[k++] = arr2[j++];
    }

    i = 0, j = 0;
    for(int iter = 0; iter<size1; iter++){
        arr1[i++] = mergedArray[iter]; 
    }

    for(int iter = size1; iter<size1+size2; iter++){
        arr2[j++] = mergedArray[iter]; 
    }

}

void mergeSort(int* a, int n){
    
    if(n<=1) return ;

    int mid = n/2; 
    mergeSort(a,mid);
    mergeSort(a+mid,n-mid);
    mergeTwoSortedArrays(a,mid,a+mid,n-mid);
    
    return ;

}

int main(){

    int n;
    cin>>n;

    int* a = new int[n];
    for(int i = 0; i<n; i++){
        cin>>a[i];
    }

    mergeSort(a,n);
    printArray(a,n);
}