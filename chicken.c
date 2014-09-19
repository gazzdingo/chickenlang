#include<stdlib.h>
#include<stdio.h>
#include "cw1.h"
#include "chicken.h"


 void drawChicken(int offsetX, int offsetY){
    #pragma pack(push)  // push current alignment to stack
    #pragma pack(1)     // set alignment to 1 byte boundary
    typedef struct
    {
        unsigned short int Type; /* Magic identifier */
        unsigned int Size; /* File size in bytes */
        unsigned short int Reserved1;
        unsigned short int Reserved2;
        unsigned int Offset; /* Offset to data (in B)*/
    }HEADER; /* -- 14 Bytes -- */

    typedef struct
    {
        unsigned int Size; /* Header size in bytes */
        int Width;
        int Height; /* Width / Height of image */
        unsigned short int Planes; /* Number of colour planes */
        unsigned short int Bits; /* Bits per pixel */
        unsigned int Compression; /* Compression type */
        unsigned int ImageSize; /* Image size in bytes */
        int xResolution;
        int yResolution;/* Pixels per meter */
        unsigned int Colors; /* Number of colors */
        unsigned int ImportantColors;/* Important colors */
    }INFOHEADER; /* -- 40 Bytes -- */

    typedef struct
    {
        //unsigned char Alpha;
        unsigned char Blue;
        unsigned char Green;
        unsigned char Red;
    }PIXEL; /*---- 24 bytes----*/
    #pragma pack(pop)   // restore original alignment from stack


      //make instance of all three structures
        HEADER data;
        INFOHEADER data2;
        PIXEL pixel;

        //declare file read pointer
        FILE *file;

        //declare fileout read pointer
        //FILE *fileout; //declare file printed file pointer


        if( !(file = fopen( "img.bmp","r"))){
            printf("no file found in location");

        }




        //read HEADER data into data
        fread(&data,sizeof(HEADER),1,file);
        //read IB+NFOHEADER data into data2
        fread(&data2,sizeof(INFOHEADER),1,file);

        if(data2.Bits != 24){
            printf("the BMP file has to be 24 bits per pixel");
        }
        //Print PIXEL data
        fseek(file, data.Offset, 0);
        //Allocate space for pixelarray
        PIXEL **pixelarray;
        int r=0,c=0,rows=data2.Height,collumns=data2.Width;
        pixelarray= malloc(rows*sizeof(PIXEL *));

        int pixelnum=1;


          // read pixel data from image
        //printf("\nPixel %10d: %02X %02X %02X",0xFF,0xFF,0xFF);
            for( r=0; r<rows; r++ )
            {
            pixelarray[r]=malloc(collumns*sizeof(PIXEL));
                for( c=0; c<collumns; c++ )     // read pixel data from image
                {
                    fread(&pixelarray[r][c] , 1, sizeof(PIXEL), file);
                    pixelnum++;

                }
            }

            r=0;c=0;
            for(r =0; r < rows;r++){
             for(c =0; c < collumns;c++){
                  putPixel((r+1)+offsetX,(c+1)+offsetY,pixelarray[r][c].Red,pixelarray[r][c].Green,pixelarray[r][c].Blue);


             }

            }


        int picOffset = 1;


        //fill pixel array with pixel structs



        free(pixelarray);

        fclose(file);  //close the files prior to exiting
}

// void clearImg(){
// int   r=0,c=0;
//    for(r =0; r < *row;r++){
//     for(c =0; c < *col;c++){
//          putPixel(r+1,c+1,0x00,0x00,0x00);
//
//     }
//
//    }
// }
