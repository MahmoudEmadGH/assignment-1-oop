#include "Image_class.h"
#include<string>
using namespace std;
string n;
Image pic;
void infrared(Image &photo);  
void frame(Image &photo);     
void menu();
void save_Image();
void load_Image();

void load_Image(){
    cout<<"Please enter the name of the photo: "<<endl;
    cin.ignore();
    while(1){
       // cin.ignore();
        //getline(cin,n);
       try {
     getline(cin,n);
     bool u = pic.loadNewImage("photos/" + n);

     if (u) {
         cout << "image uploaded successfully" << endl;
         //menu();
         break;
     }
 }
 catch (const invalid_argument& e) {
     cout << "please enter a correct name: " << endl;
 }
 }  
} 
void save_Image(){
    cout<<"please choose a saving method"<<endl;
    cout<<"1)save image - 2)save as new image"<<endl;
    string savingMethod;
    cin>>savingMethod;
    if(savingMethod=="1"){
        pic.saveImage(n);
    }
    else if(savingMethod=="2"){
        cout<<"please enter the name of the new image(with extention):"<<endl;
        string newImage;
        cin>>newImage;
        pic.saveImage(newImage);
        cout<<"here you are!"<<endl;
    }
    

}
//  void menu(){
//     string option;
    
//     cout<<"please choose the option number:"<<endl;
//     cout<<"1)load a new image"<<endl;
//     cout<<"2)choose a filter"<<endl;
//     cout<<"3)save the image"<<endl;
//     cout<<"4)exit"<<endl;
//     cin>>option;
//     if(option=="1"){load_Image();}
//     else if(option=="2"){
//         cout<<"please choose the filter number"<<endl;
//         cout<<"1)infrared - 2)add frame - 3)invert image - 4)darken and lighten - 5)grey scale - 6)black and white - 7)flip image - 8)rotate image"<<endl;
//         string filterOption;
//         //cin>>filterOption;
//         while(1){
//      cin>>filterOption;
//      if(filterOption=="1"){
//          infrared(pic);break;
//      }
//      else if(filterOption=="2"){
//         frame(pic);break;
//      }
//      else{cout<<"please choose a correct filter number: "<<endl;}
//     } 

//     }
//     else if(option=="3"){
//         save_Image();
//     }
//      else if(option=="4"){
//           //menu();
//           return;
//     }
     
    
// }
void frame(Image &photo){    
    cout<<"choose a frame: "<<endl;
    cout<<"1)simple - 2)mixed"<<endl<<"please enter the frame number:"<<endl;
     double percent=2.0/100;
    percent*=photo.width;
    string f ;
    while(1){
    cin>>f;
    if(f=="1"){
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
    //save_Image();
    // photo.saveImage("new photo.jpg");
    // cout<<"here you are!";
     //menu();                      //55555555
    break;

    }
    else if(f=="2"){
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
        // menu();             //555555
    //save_Image();
    // photo.saveImage("new photo.jpg");
    // cout<<"here you are!";
    break;
}
else{cout<<"please enter a correct frame number: "<<endl;}
    }
}
void infrared(Image &photo){    
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

   // save_Image();
     //menu();          555555
    // photo.saveImage("new photo.jpg");
    // cout<<"here you are!"<<endl;
}



int main(){
    
    cout<<"Please enter the name of the photo: "<<endl;
   // cin.ignore();
    while(1){
       // cin.ignore();
        //getline(cin,n);
       try {
     getline(cin,n);
     bool u = pic.loadNewImage("photos/" + n);

     if (u) {
         cout << "image uploaded successfully" << endl;
         //menu();
         break;
     }
 }
 catch (const invalid_argument& e) {
     cout << "please enter a correct name: " << endl;
 }
 }  
 
 string option;
    while(1){
    cout<<"please choose the option number:"<<endl;
    cout<<"1)load a new image"<<endl;
    cout<<"2)choose a filter"<<endl;
    cout<<"3)save the image"<<endl;
    cout<<"4)exit"<<endl;
    cin>>option;
    if(option=="1"){load_Image();}
    else if(option=="2"){
        cout<<"please choose the filter number"<<endl;
        cout<<"1)infrared - 2)add frame - 3)invert image - 4)darken and lighten - 5)grey scale - 6)black and white - 7)flip image - 8)rotate image"<<endl;
        string filterOption;
        //cin>>filterOption;
        while(1){
     cin>>filterOption;
     if(filterOption=="1"){
         infrared(pic);break;
     }
     else if(filterOption=="2"){
        frame(pic);break;
     }
     else{cout<<"please choose a correct filter number: "<<endl;}
    } 

    }
    else if(option=="3"){
        save_Image();
    }
    else if(option=="4"){ return 0;}
    else{cout<<"please select a correct option";}
}
} 
    

    
