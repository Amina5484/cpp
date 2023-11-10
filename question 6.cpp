//Find the largest and smallest number in an unsorted integer array.
#include<iostream>
using namespace std;
int main(){
	int n;
	cout<<"enter array size"<<endl;
	cin>>n;
	if (n<=0){
		cout<<"invalide size of array"<<endl;
		return 1;
	}
	int arr[n];
	cout<<"enter  "<<n<<"  integer:"<<endl;
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	int largest=arr[0];
	int smallest=arr[0];
	for(int i=1;i<n;i++){
		if(arr[i]>largest){
			largest=arr[i];
		}
		if(arr[i]<smallest){
			smallest=arr[i];
		}
	}
	cout<<"the largest element is    "<< largest<<endl
	;cout<<"the smallest element is   "<< smallest<<endl;
	return 0;	
}