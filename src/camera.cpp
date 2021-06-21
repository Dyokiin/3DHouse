#include <GL/glew.h>
#include <GL/glut.h>
#include <GL/glu.h>
#include <GL/gl.h>

#include <iostream>

#include "../include/spline.h"

void cameraSpline(){
    std::vector<double> X, Y;
    X = {0,10, 15};
    Y = {0,14,2};
    tk::spline s(X,Y);			// X needs to be strictly increasing
    // double value=s(1.3);		// interpolated value at 1.3
    // double deriv=s.deriv(1,1.3);	// 1st order derivative at 1.3
    std::vector<double> solutions = s.solve(2.5);	// solves s(x)=0.0
    for(double x=0; x<3; x+=0.01){
        glVertex3f(x, 4., s.solve(x)[0]);
    }
    
}