#include <iostream>
using namespace std;
int main() {
   int i , count, age;
   float marks;
   for(i=1; i<150;i++){
       cout<<"enter your age and marks";
       cin>>age>>marks;
       if(age>27 || marks<80){
           cout<<"you are not eligible for the job post"<<endl;
           continue;
       }
       count = count +1;
       if(count > 50){
           cout<<"i am sorry. the job is only open for the firest 50 students to apply";
           break;
       }
       cout<<"you have succesfully applied here"<<endl;
   }
    return 0;
}
