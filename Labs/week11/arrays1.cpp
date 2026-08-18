#include <iostream>
using namespace std;
int max(int product1, int product2){
    return product1,product2;
}
int main() {
int arr[]={-4,-5,6,7,-1};
int n = 5;
int max,max1,max2,max3,min,min1,min2;
 max1 = min;
 max2 = min;
 max3=min;
 min1 = max;
 min2 = max;


for(int i = 0; i<n; i++){
    if(arr[i]>max1){
        max3 = max2;
        max2 = max1;
        max1 = arr[i];
    }
    else if(arr[i]>max2){
       max3 = max2;
        max2= arr[i];

    }
    else if(arr[i]>max3){
        max3=arr[i];
    }
    if(arr[i]<min1){
        min2 = min1;
        min1 = arr[i];
        
    }
    else if(arr[i]<min2){
        min2 = arr[i];
    }

}

int product1 = max1 * max2 * max3;
int product2 = min1 * min2 * max1;
cout<<product1<< " "<<endl;


    return 0;
}