#include <stdio.h>
#include "cs1300bmp.h"
#include <iostream>
#include <fstream>
#include "Filter.h"

using namespace std;

#include "rdtsc.h"

//
// Forward declare the functions
//
Filter * readFilter(string filename);
double applyFilter(Filter *filter, cs1300bmp *input, cs1300bmp *output);

int
main(int argc, char **argv)
{

  if ( argc < 2) {
    fprintf(stderr,"Usage: %s filter inputfile1 inputfile2 .... \n", argv[0]);
  }

  //
  // Convert to C++ strings to simplify manipulation
  //
  string filtername = argv[1];

  //
  // remove any ".filter" in the filtername
  //
  string filterOutputName = filtername;
  string::size_type loc = filterOutputName.find(".filter");
  if (loc != string::npos) {
    //
    // Remove the ".filter" name, which should occur on all the provided filters
    //
    filterOutputName = filtername.substr(0, loc);
  }

  Filter *filter = readFilter(filtername);

  double sum = 0.0;
  int samples = 0;

  for (int inNum = 2; inNum < argc; inNum++) {
    string inputFilename = argv[inNum];
    string outputFilename = "filtered-" + filterOutputName + "-" + inputFilename;
    struct cs1300bmp *input = new struct cs1300bmp;
    struct cs1300bmp *output = new struct cs1300bmp;
    int ok = cs1300bmp_readfile( (char *) inputFilename.c_str(), input);

    if ( ok ) {
      double sample = applyFilter(filter, input, output);
      sum += sample;
      samples++;
      cs1300bmp_writefile((char *) outputFilename.c_str(), output);
    }
    delete input;
    delete output;
  }
  fprintf(stdout, "Average cycles per sample is %f\n", sum / samples);

}

struct Filter *
readFilter(string filename)
{
  ifstream input(filename.c_str());

  if ( ! input.bad() ) {
    int size = 0;
    input >> size;
    Filter *filter = new Filter(size);
    int div;
    input >> div;
    filter -> setDivisor(div);
    for (int i=0; i < size; i++) {
      for (int j=0; j < size; j++) {
	int value;
	input >> value;
	filter -> set(i,j,value);
      }
    }
    return filter;
  } else {
    cerr << "Bad input in readFilter:" << filename << endl;
    exit(-1);
  }
}


double
applyFilter(struct Filter *filter, cs1300bmp *input, cs1300bmp *output)
{

  long long cycStart, cycStop;

  cycStart = rdtscll();

  output -> width = input -> width;
  output -> height = input -> height;

  //int size = filter->getSize(); //less calls to this now
  //int size = 3;
  int wid = (input -> width) - 1; // less calls to this now too
  int hei = (input -> height) - 1; // and this
  int divs = filter -> getDivisor(); // and this
 
  // Create Filter Array
  int *filt;
  filt = new int[3 * 3];
  for (int i = 0; i < 3; i++) { // size here, switch i,j
    for (int j = 0; j < 3; j++) { // size here, switch i,j
       filt[ i * 3 + j ] = filter -> get(i, j);
    }
  }
    
    // Unroll planes
    for(int row = 1; row < hei; row++) { //hei here, ++,  switch row and col
      for(int col = 1; col < wid; col++) { //wid here, ++, switch row and col
        // --- Plane 0
        int * out = &(output -> color[0][row][col]); // changed this to a pointer less calls now
        int temp = ((input-> color[0][row-1][col-1] * filt[0]) + 
               (input-> color[0][row][col-1] * filt[3]) +
               (input-> color[0][row-1][col] * filt[1]) +
               (input-> color[0][row][col] * filt[4]) +
               (input-> color[0][row-1][col+1] * filt[2]) +
               (input-> color[0][row+1][col-1] * filt[6]) +
               (input-> color[0][row+1][col] * filt[7]) +
               (input-> color[0][row][col+1] * filt[5]) +
               (input-> color[0][row+1][col+1] * filt[8]))/divs; // unrolled i and j, include /divs
          
        *out = temp;
          
        if ( temp  < 0 ) { //out
          *out = 0; //out
        }

        if ( temp > 255 ) { //out
          *out = 255; //out
        }
        // --- Plane 1
        out = &(output -> color[1][row][col]); // changed this to a pointer less calls now
        temp = ((input-> color[1][row-1][col-1] * filt[0]) + 
               (input-> color[1][row][col-1] * filt[3]) +
               (input-> color[1][row-1][col] * filt[1]) +
               (input-> color[1][row][col] * filt[4]) +
               (input-> color[1][row-1][col+1] * filt[2]) +
               (input-> color[1][row+1][col-1] * filt[6]) +
               (input-> color[1][row+1][col] * filt[7]) +
               (input-> color[1][row][col+1] * filt[5]) +
               (input-> color[1][row+1][col+1] * filt[8]))/divs; // unrolled i and j, include /divs
          
        *out = temp;
          
        if ( temp  < 0 ) { //out
          *out = 0; //out
        }

        if ( temp > 255 ) { //out
          *out = 255; //out
        }
        // --- Plane 2
        out = &(output -> color[2][row][col]); // changed this to a pointer less calls now
        temp = ((input-> color[2][row-1][col-1] * filt[0]) + 
               (input-> color[2][row][col-1] * filt[3]) +
               (input-> color[2][row-1][col] * filt[1]) +
               (input-> color[2][row][col] * filt[4]) +
               (input-> color[2][row-1][col+1] * filt[2]) +
               (input-> color[2][row+1][col-1] * filt[6]) +
               (input-> color[2][row+1][col] * filt[7]) +
               (input-> color[2][row][col+1] * filt[5]) +
               (input-> color[2][row+1][col+1] * filt[8]))/divs; // unrolled i and j, include /divs
          
        *out = temp;
          
        if ( temp  < 0 ) { //out
          *out = 0; //out
        }

        if ( temp > 255 ) { //out
          *out = 255; //out
        }
        // end of plane unroll
      }
    }

  cycStop = rdtscll();
  double diff = cycStop - cycStart;
  double diffPerPixel = diff / (output -> width * output -> height);
  fprintf(stderr, "Took %f cycles to process, or %f cycles per pixel\n",
 diff, diff / (output -> width * output -> height));
  return diffPerPixel;
}
