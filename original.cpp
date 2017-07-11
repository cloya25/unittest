

//Author: Gordon Griesel
//Date: July 8, 2017
//Purpose: Framework for coding exam
//
// Modified by Cesar Loya
//  // original vec.cpp file 
//
//See instructions to produce a unit-test for the vecNormalize function.
//
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

//type defines
typedef double Flt;
typedef Flt Vec[2];

//prototype
Flt vecNormalize(Vec v);

//Array of vector values
const Flt arr[] = {
    1.00,   0.00,
    1.00,   1.00,
    -1.20,   2.50,
    99.99,  99.99,
    2.22,  -1.22
};

int main(int argc, char *argv[])
{
    //Program to analyze a vector normalization process.
    printf("\n3350 programming exam               \n");
    printf("Cesar Loya <--your name goes there\n");
    printf("Display of normalized vectors.        \n\n");
    printf("     ----------------  --------------------------  \n");
    printf("     known input:      actual output:              \n");
    printf("     X        Y        length    X        Y        \n");
    printf("     -------  -------  --------  -------  -------  \n");
    for (int i=0; i<5; i++) {
        Vec ki = { arr[i*2+0], arr[i*2+1] };
        Vec ao = { ki[0], ki[1] };
        Flt ret = vecNormalize(ao);
        printf("%3i  %7.4lf  %7.4lf  %8.4lf  %7.4lf  %7.4lf\n",
                i+1, ki[0], ki[1], ret, ao[0], ao[1] );
    }
    printf("\nProgram complete.\n\n");
    return 0;
}

Flt vecNormalize(Vec v)
{
    //----------------------------
    //Do not modify this function.
    //----------------------------
    //Normalize a 2-dimensional vector.
    //Calculate the vector dot product with itself...
    Flt dot = v[0]*v[0] + v[1]*v[1];
    //Check for degenerative vector...
    if (dot == 0.0) {
        //set an arbitrary vector of length 1.0
        v[0] = 1.0;
        v[1] = 0.0;
        return 0.0;
    }
    //Vector has a magnitude, so continue.
    Flt len = sqrt(dot);
    Flt oolen = 1.0 / len;
    v[0] *= oolen;
    v[1] *= oolen;
    return len;
}

