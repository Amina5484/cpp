#include<iostream>
using namespace std;
	void reverseArray( int arr[],int start,int end){
		if(start>=end)
		return;
		int temp=arr[start];
		arr[start]=arr[end];
		arr[end]=temp;
		reverseArray(arr,start+1,end-1);
	}
	void printArray(int arr[],int size){
		for(int i=0;i<size;i++)
		cout<<arr[i]<<"  "<<endl;
		cout<<endl;
	}
	int main(){
		int arr[]={1,2,3};
		printArray(arr,3);
		reverseArray(arr,0,2);
		cout<<"Reversed array is :"<<endl;
		printArray(arr,3);
		return 0;
	}
