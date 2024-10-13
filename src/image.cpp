#include "image/image.hpp"
#include "image/noderegion.hpp"
#include "image/point2D.hpp"
#include "image/listofpoint2d.hpp"
#include "image/region.hpp"
#include "image/nodepoint2d.hpp"
#include <fstream>
#include <iostream>
#include <cassert>
#include <cstring>
#include <stack>

namespace image{

    Image::Image(): width(0), height(0), th_value(120), data(nullptr){

    }

    Image::Image(int w, int h): width(w), height(h), th_value(120),  data(nullptr){

    }

    Image::Image(int w, int h, uchar* _data): width(w), height(h), th_value(120), data(_data){
       threshold();
    }

    void Image::threshold(){
        if (data != nullptr) {
            for(int i = 0; i < height*width; i++){            
                if (static_cast<int>(data[i]) < th_value){
                    data[i] = static_cast<char>(0);
                }
                else{
                    data[i] = static_cast<char>(1);                    
                }
            }
        }
    }
    int Image::getValue(int row, int col){
        int pos = row*width + col;
        return static_cast<int>(data[pos]);
    }

    void Image::show(){
        std::cout << "----------------------" << std::endl;
        std::cout << "size [ (w: " << width << ") x   ( h:" << height << ")]" <<  std::endl;        
        std::cout << "---------------------" << std::endl;
        for(int i = 0 ; i < height ; i++ ){
            for(int j = 0; j < width; j++ ){
                //std::cout<< getValue(i,j) << " "; 
                if (getValue(i,j) == 0) {
                    std::cout<<" ";
                }
                else{
                    std::cout<<"*";
                }
            }
            std::cout<<std::endl;
        }
    }

    Image::~Image(){

    }

    Image* Image::readImage(std::string &path){

        Image* im = nullptr;
        std::ifstream fin(path, std::ios::binary);
        char info[54];
        // read the 54-byte header
        fin.read(info, 54);
        // extract image height and width from header
        int width = *(int*)&info[18];
        int height = *(int*)&info[22];
        short int planes = *(short int*)&info[26];
        short int bits = *(short int*)&info[28];
        int imagesize = *(int*)&info[34];
        int numcolors = *(int*)&info[46];
        assert(info[0]=='B' && info[1] =='M');
        assert(bits == 8);
        // std::cout<< "planes " << planes << std::endl;
        // std::cout<< "bits " << bits << std::endl;
        // std::cout<< "imagesize " << imagesize << std::endl;
        // std::cout<< "numcolors " << numcolors << std::endl;
        // std::cout<< info[0] << info[1] << std::endl;
        //reading colortable
        char  colors[numcolors*4];
        fin.read(colors, numcolors*4);        
        if (imagesize == height * width) {            
            char* data = new char[imagesize];
            //read the pixel values
            fin.read(data, imagesize); 
            fin.close();
            char* ordered_data = new char[imagesize];
            //copy data in in a proper order            
            std::cout<< "----------------" <<std::endl;
            for(int i = 0; i < height ; i++){
                std::memcpy(ordered_data + width*i, data + width*(height - 1 - i ), width);
            }                    
            delete[]  data;            
            im = new Image(width, height, reinterpret_cast<uchar*>(ordered_data));        
        }
        assert(im != nullptr);
        return im;
    }

    ListOfRegion Image::getRegions(){
        ListOfRegion regions;// lista para guardar las regiones encontradas
        bool **visitados = new bool*[height]; //matriz para maracar los pixeles vistados

        //inicializar la matriz visitados en false
        for (int i= 0; i<height;i++){
            visitados[i] = new bool[width]();
        }

        int regionId = 1; //id de la primera región

        //recorrer cada pixel
        for(int i=0; i<height; i++){
            for(int j = 0; j< width; j++){
                if(getValue(i,j)==1 && !visitados[i][j]){
                    //si se encuentra un pixel no visitado que pertenece a la región
                    Region* region = new Region(regionId, region->getPoints());
                    exploreRegion(i,j,visitados, *region);//explorar región
                    regions.Insert(region);//agregar la region a la lista
                    regionId++;//incrementar el idx para la sgte region
                }
        }
    }
    //liberar memoria visitados
    for(int i =0; i<height;i++){
        delete[] visitados[i];
    }
    delete[] visitados;
    return regions; //devolver lista de regiones


    }
    void Image::exploreRegion(int row, int col, bool** visitados, Region& region){
        std::stack<std::pair<int, int>> stack;
        stack.push({row, col});
        visitados[row][col] = true;
        region.addPoint(row, col);//agregar el primer punto

        //direcciones de movimiento
        int direcciones[4][2]={{-1,0},{1,0},{0,-1},{0,1}};

        while(!stack.empty()){
            auto [r,c] = stack.top();
            stack.pop();

            //revisar direcciones adyacentes
            for(int i = 0; i<4;i++){
                int newRow = r+ direcciones[i][0];
                int newCol = c+ direcciones[i][1];

                if (newRow>=0 && newRow < height && newCol >=0 && newCol<width){
                    if(getValue(newRow, newCol) == 1 && !visitados[newRow][newCol]){
                        visitados[newRow][newCol] = true;
                        region.addPoint(newRow, newCol);
                        stack.push({newRow, newCol});
                    }
                }
            }

        }

    }


}

