#include <iostream>
using namespace std;
int main() {
  int arr[10]={10,20,30,40,50};
  int n=5,i;
  //now for  traversal i.e. visiting or checking  of element within data str exactly //once.
  cout<<"array";
  for(i=0;i<n;i++)
  cout<<arr[i]<<"";
  //now for insertion i.e. to insert data element in collectin of data.
  for(i=n;i>2;i--)
  arr[i]=arr[i-1];
  arr[2]=25;
  n++;
  cout<<"after insertion:";
  for(i=0;i<n;i++)
  cout<<arr[i]<<"";
  //now for deletion
  for(i=3;i<n-1;i++)
  arr[i]=arr[i+1];
  n--;
  cout<<"after deletion";
  for(i=0;i<n;i++)
  cout<< arr[i]<<"";
  //now for search
  int key=40;
  for(i=0;i<n;i++){
      if(arr[i]==key){
          cout<<"element found at index"<<i;
          break;
      }
  }
  return 0;
}
      
  
  
  
  
