#include <iostream>
#include "../../include/assets.hpp"

float pot[62][3] = {{0.5 ,0.3, 0.3},
		{1.,0.,0.},{2.,0.,0.},{3.,0.,0.},{0.,0.,1.},{0.,0.,2.},{0.,0.,3.},{4.,0.,1.},{4.,0.,2.},{4.,0.,3.},{1.,0.,4.},{2.,0.,4.},{3.,0.,4.},
		{1.,1.,-1.},{2.,1.,-1.},{3.,1.,-1.},{-1.,1.,1.},{-1.,1.,2.},{-1.,1.,3.},{5.,1.,1.},{5.,1.,2.},{5.,1.,3.},{1.,1.,5.},{2.,1.,5.},{3.,1.,5.},{0.,1.,0.},{0.,1.,4.},{4.,1.,4.},{4.,1.,0.},
		{1.,2.,-1.},{2.,2.,-1.},{3.,2.,-1.},{-1.,2.,1.},{-1.,2.,2.},{-1.,2.,3.},{5.,2.,1.},{5.,2.,2.},{5.,2.,3.},{1.,2.,5.},{2.,2.,5.},{3.,2.,5.},{0.,2.,0.},{0.,2.,4.},{4.,2.,4.},{4.,2.,0.},
		{1.,3.,-1.},{2.,3.,-1.},{3.,3.,-1.},{-1.,3.,1.},{-1.,3.,2.},{-1.,3.,3.},{5.,3.,1.},{5.,3.,2.},{5.,3.,3.},{1.,3.,5.},{2.,3.,5.},{3.,3.,5.},{0.,3.,0.},{0.,3.,4.},{4.,3.,4.},{4.,3.,0.},
		{-1.,-1.,-1.}};
		
float dirt[23][3] = {{0.2 ,0.08, 0.08},
		{1.,2.,0.},{2.,2.,0.},{3.,2.,0.},{0.,2.,1.},{0.,2.,2.},{0.,2.,3.},{4.,2.,1.},{4.,2.,2.},{4.,2.,3.},{1.,2.,4.},{2.,2.,4.},{3.,2.,4.},
		{1.,2.,2.},{2.,2.,2.},{3.,2.,2.},{1.,2.,1.},{2.,2.,1.},{3.,2.,1.},{1.,2.,3.},{2.,2.,3.},{3.,2.,3.},
		{-1.,-1.,-1.}};
		
float plant1[8][3] = {{0.,0.6,0.1},
		{2.,3.,2.},{2.,4.,2.},{2.,5.,2.},{2.,6.,2.},{2.,7.,3.},
		{1.,5.,1.},
		{-1.,-1.,-1.}};

float plant2[100][3] = {{0.,0.6,0.1},
		{2.,3.,2.},{2.,4.,2.},{2.,5.,2.},{2.,6.,2.},{2.,7.,2.},{2.,8.,2.},{2.,9.,2.},{2.,10.,2.},{2.,11.,2.},{2.,12.,2.},{2.,13.,2.},{2.,14.,2.},{2.,15.,2.},
		{1.,16.,3.},{1.,17.,3.},{1.,18.,3.},{1.,19.,3.},{1.,20.,3.},{1.,21.,3.},
		{2.,8.,3.},{2.,9.,4.},{2.,9.,5.},{2.,9.,6.},{2.,9.,7.},{2.,8.,8.},{2.,8.,9.},{2.,7.,10.},{1.,9.,4.},{1.,9.,5.},{1.,9.,6.},{1.,9.,7.},{1.,8.,8.},{1.,8.,9.},{2.,9.,5.},{2.,9.,6.},{2.,9.,7.},{2.,8.,8.},{2.,8.,9.},{0.,8.,5.},{0.,8.,6.},{0.,8.,7.},{0.,7.,8.},{0.,7.,9.},
		{2.,10.,2.},{2.,11.,1.},{2.,11.,0.},{2.,11.,-1.},{2.,11.,-2.},{2.,10.,-3.},{2.,10.,-4.},{2.,9.,-5.},{1.,11.,1.},{1.,11.,0.},{1.,11.,-1.},{1.,11.,-2.},{1.,10.,-3.},{1.,10.,-4.},{2.,11.,0.},{2.,11.,-1.},{2.,11.,-2.},{2.,10.,-3.},{2.,10.,-4.},{0.,10.,0.},{0.,10.,-1.},{0.,10.,-2.},{0.,9.,-3.},{0.,9.,-4.},
		{1.,16.,3.},{0.,16.,3.},{-1.,16.,3.},{-2.,16.,3.},{-3.,15.,3.},{0.,16.,4.},{-1.,16.,4.},{-2.,16.,4.},{-3.,15.,4.},{0.,16.,2.},{-1.,16.,2.},{-2.,16.,2.},
		{-1.,-1.,-1.}};

float flower[20][3] = {{.8,.1,.2},
		{1.,22,3},{1,22,2},{1,23,1},{1,24,0},{1,24,-1},
		{1,22,4},{1,23,5},{1,24,6},{1,25,6},
		{2,22,3},{3,23,3},{4,24,3},{4,24,2},
		{-1.,-1.,-1.}};
