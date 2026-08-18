#include<iostream>
#include<math.h>
using namespace std;
float convert(float a){
    float result = a/57.29;
    return result;

}
float height(float a, float b){
    float result = a*b;
    cout<<" result: "<<result;
}

int main(){
    float angle;
    cout<<"ENTER AN ANGLE"<<endl;
    cin>>angle;
    
    
    
    float a = convert(angle);
    float tan_value;
     tan_value =  tan(a);
     float base_value;
     cout<<"ENTER VALUE OF BASE : "<<endl;
     cin>>base_value;
     height(base_value,tan_value);
     

     


    


}



