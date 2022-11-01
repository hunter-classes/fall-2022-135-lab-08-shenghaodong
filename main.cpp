#include <iostream>
#include "imageio.h"
#include "funcs.h"

int main(){
  invert("inImage.pgm");
  invertHalf("inImage.pgm");
  whiteBox("inImage.pgm");
  whiteOutline("inImage.pgm");
  scale("inImage.pgm");
  pixelate("inImage.pgm");
  return 0;
}

