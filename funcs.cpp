#include <iostream>
#include "imageio.h"

void invert(std::string inputFile){
  std::string input = inputFile;
  int img[MAX_H][MAX_W];
  int h, w;
  readImage(input, img, h, w);
  int out[MAX_H][MAX_W];

  for(int row = 0; row < h; row++) {
    for(int col = 0; col < w; col++) {
      out[row][col] = img[row][col];
    }
  }
  
  for(int row = 0; row < h; row++) {
    for(int col = 0; col < w; col++) {
      out[row][col] = 255 - out[row][col];
    }
  }

  writeImage("taskA.pgm",out, h, w);
}

void invertHalf(std::string inputFile){
  std::string input = inputFile;
  int img[MAX_H][MAX_W];
  int h, w;
  readImage(input, img, h, w);
  int out[MAX_H][MAX_W];

  for(int row = 0; row < h; row++) {
    for(int col = 0; col < w; col++) {
      out[row][col] = img[row][col];
    }
  }
  
  for(int row = 0; row < h; row++) {
    for(int col = w/2; col < w; col++) {
      out[row][col] = 255 - out[row][col];
    }
  }

  writeImage("taskB.pgm",out, h, w);
}

void whiteBox(std::string inputFile){
  std::string input = inputFile;
  int img[MAX_H][MAX_W];
  int h, w;
  readImage(input, img, h, w);
  int out[MAX_H][MAX_W];

  for(int row = 0; row < h; row++) {
    for(int col = 0; col < w; col++) {
      out[row][col] = img[row][col];
    }
  }
  
  for(int row = h/4; row < (h/4)*3; row++) {
    for(int col = w/4; col < (w/4)*3; col++) {
      out[row][col] = 255;
    }
  }

  writeImage("taskC.pgm",out, h, w);
}

void whiteOutline(std::string inputFile){
  std::string input = inputFile;
  int img[MAX_H][MAX_W];
  int h, w;
  readImage(input, img, h, w);
  int out[MAX_H][MAX_W];

  for(int row = 0; row < h; row++) {
    for(int col = 0; col < w; col++) {
      out[row][col] = img[row][col];
    }
  }
  
  for(int row = h/4; row < (h/4)*3; row++) {
    for(int col = w/4; col < (w/4)*3; col++) {
      if(row == h/4 || row == (h/4)*3 - 1 || col == w/4 || col == (w/4)*3 - 1){
        out[row][col] = 255;
      }
    }
  }

  writeImage("taskD.pgm",out, h, w);
}

void scale(std::string inputFile){

  std::string input = inputFile;
  int img[MAX_H][MAX_W];
  int h, w;
  readImage(input, img, h, w);

  int out[MAX_H][MAX_W];
  for(int row = 0; row < (h * 2); row++) {
    for(int col = 0; col < (w * 2); col++) {
      out[row][col] = img[row][col];
    }
  }
  writeImage("taskE.pgm",out, h * 2, w * 2);
  std::string input2 = "taskE.pgm";
  int img2[MAX_H][MAX_W];
  int x, y;
  readImage(input2, img2, x, y);
  int out2[MAX_H][MAX_W];
  for(int row = 0; row < x; row++) {
    for(int col = 0; col < y; col++) {
            out2[row][col] = img2[row/2][col/2];
            out2[row][col + 1] = img2[row/2][col/2];
            out2[row + 1][col] = img2[row/2][col/2];
            out2[row + 1][col + 1] = img2[row/2][col/2];
    }
  }
  writeImage("taskE.pgm",out2, x, y);
}

void pixelate(std::string inputFile){

  std::string input = inputFile;
  int img[MAX_H][MAX_W];
  int h, w;
  readImage(input, img, h, w);

  int out[MAX_H][MAX_W];
  for(int row = 0; row < (h); row++) {
    for(int col = 0; col < (w); col++) {
      out[row][col] = img[row][col];
    }
  }

  int average;
  for(int row = 0; row < h; row+=2) {
    for(int col = 0; col < w; col+=2) {
        int average = out[row][col] + out[row][col + 1] + out[row + 1][col] + out[row + 1][col + 1];
        average = (int)average/4;
        out[row][col] = average;
        out[row][col + 1] = average;
        out[row + 1][col] = average;
        out[row + 1][col + 1] = average;
        average = 0;
    }
  }
  writeImage("taskF.pgm",out, h, w);
}
