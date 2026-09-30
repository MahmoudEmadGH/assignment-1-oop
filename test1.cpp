#include "Image_class.h"
#include<string>
using namespace std;
void frame(Image photo){
    cout<<"choose a frame: "<<endl;
    cout<<"1)simple - 2)mixed"<<endl<<"please enter the frame number:"<<endl;
     double percent=2.0/100;
    percent*=photo.width;
    int f ;
    while(1){
    cin>>f;
    if(f==1){
        for(int i=0;i<photo.width;i++){
            for(int j=0;j<photo.height;j++){
                if((j<percent)||(j>=photo.height-percent)||(i<percent)||(i>=photo.width-percent)){
                    for(int k=0;k<3;k++){
                if(k==0) photo(i,j,k)=92;
                if(k==1) photo(i,j,k)=64;
                if(k==2) photo(i,j,k)=45;
              }
                }
            }
        }
   
    photo.saveImage("new photo.jpg");
    cout<<"here you are!";
    break;

    }
    else if(f==2){
       float separateWidthP=photo.width*(0.01);
       int separateWidth=(int)separateWidthP;
        for(int i=0;i<photo.width;i++){
            for(int j=0;j<photo.height;j++){
                if((j<percent)||(j>=photo.height-percent)){
                    if(i%(separateWidth*2)<separateWidth&&((j>=0&&j<percent)||(j>=photo.height-percent&&j<photo.height)))
                    {
                    for(int k=0;k<3;k++){
                if(k==0) photo(i,j,k)=92;
                if(k==1) photo(i,j,k)=64;
                if(k==2) photo(i,j,k)=45;
                   }
                 }
                 else{
                    for(int k=0;k<3;k++){
                if(k==0) photo(i,j,k)=212;
                if(k==1) photo(i,j,k)=175;
                if(k==2) photo(i,j,k)=55;
              }

                 }
                }
            }
        }
         
        for(int i=0;i<photo.width;i++){
            for(int j=percent;j<photo.height-percent;j++){
                if((i<percent)||(i>=photo.width-percent)){
                    if(j%(separateWidth*2)<separateWidth&&((i>=0&&i<percent)||(i>=photo.width-percent&&i<photo.width))
                    ){
                    for(int k=0;k<3;k++){
                if(k==0) photo(i,j,k)=92;
                if(k==1) photo(i,j,k)=64;
                if(k==2) photo(i,j,k)=45;
                   }
                 }
                 else{
                    for(int k=0;k<3;k++){
                if(k==0) photo(i,j,k)=212;
                if(k==1) photo(i,j,k)=175;
                if(k==2) photo(i,j,k)=55;
              }

                 }
                }
            }
        }

    photo.saveImage("new photo.jpg");
    cout<<"here you are!";
    break;
}
else{cout<<"please enter a correct frame number: "<<endl;}
    }
}
void infrared(Image photo){
    for(int i=0;i<photo.width;i++){
        for(int j=0;j<photo.height;j++){
            float avg=0;
            int s0=255,s1=255,s2=255;
            int e0=255,e1=0,e2=0;
            for(int k=0;k<3;k++){
                avg+=photo(i,j,k);
            }
            avg/=3;
            for(int k=0;k<3;k++){
                if(k==0){photo(i,j,k)=s0-(abs(e0-s0)*(avg/255));}
                else if(k==1){photo(i,j,k)=s1-(abs(e1-s1)*(avg/255));}
                else if(k==2){photo(i,j,k)=s2-(abs(e2-s2)*(avg/255));}
            }
        }
    }

    
    photo.saveImage("new photo.jpg");
    cout<<"here you are!"<<endl;
}

int main(){
    cout<<"Please enter the name of the photo: "<<endl;
    string n;
    Image pic;
    
    while(1){
     try {
     getline(cin,n);
     bool u = pic.loadNewImage("photos/" + n);

     if (u) {
         cout << "image uploaded successfully" << endl;
         break;
     }
 }
 catch (const invalid_argument& e) {
     cout << "please enter a correct name: " << endl;
 }
 }  

    cout<<"which filter do you want? "<<endl;
    cout<<"1)add frame - 2)infrared  "<<endl<<"please enter the filter number: "<<endl;
     int numFilter;
     
     while(1){
     cin>>numFilter;
     if(numFilter==1){
         frame(pic);break;
     }
     else if(numFilter==2){
        infrared(pic);break;
     }
     else{cout<<"please choose a correct filter number: "<<endl;}
    } 
}