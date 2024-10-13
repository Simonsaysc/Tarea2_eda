
#include "image/image.hpp"
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main(int nargs, char** vargs){
    vector<image::Image*> images;
    int choice;
    string filename;

    do{
        cout<<"\n ImagePRO" << endl;
        cout<<"1. Cargar imagen" << endl;
        cout<<"2. Ver binarización" << endl;
        cout<<"3. Ver región" << endl;
        cout<<"4. salir" << endl;
        cout<<"Elije: ";
        cin >> choice;

        switch(choice){
            case 1:{
            cout<<"Ingrese ruta de archivo: ";
            cin >> filename;
            images.push_back(image::Image::readImage(filename));
            cout<<"Imagen cargada. ID: "<< images.size()<<endl;
            break;
            }
            case 2:
            int imageId;
            cout<<"Elija la imagen ";
            cin >> imageId;
            if(imageId >= 1 && imageId <= images.size()){
                images[imageId-1]->show();
            }
            else{
                cout << "ID inválido";
            }
           break;
            case 3:{
            int imageId, regionId;
            cout<<"Elija la imagen";
            cin >> imageId;
            if(imageId >= 1 && imageId <= images.size()){
                image::ListOfRegion lr = images[imageId-1]->getRegions();
                cout<<"Elija región";
                cin>>regionId;
                image::NodeRegion* current = lr.getHead();
                while(current != nullptr){
                    if(current->getData()->getId() == regionId){
                        current->getData()->showRegion();
                        break;
                    }
                    current = current->GetNext();
                }
                if(current == nullptr){
                    cout<<"Región inválida"<<endl;
                }
            }
            else{
                cout<<"Imagen inválida"<<endl;
            }
            break;    
            }
            case 4:{
                cout<<"Adiós"<<endl;
                break;
            }
        }

    }while(choice!=4);
    return 0;
}
