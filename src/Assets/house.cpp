#include <iostream>
#include "../../include/assets.hpp"


float wall[158][3] = {{0.1, 0., 0.5},
                    {0.,0.,0.},{1.,0.,0.},{2.,0.,0.},{3.,0.,0.},{4.,0.,0.},{5.,0.,0.},{6.,0.,0.},{7.,0.,0.},{8.,0.,0.},{9.,0.,0.},{10.,0.,0.},{11.,0.,0.},{12.,0.,0.},
                    {0.,1.,0.},{1.,1.,0.},{2.,1.,0.},{3.,1.,0.},{4.,1.,0.},{5.,1.,0.},{6.,1.,0.},{7.,1.,0.},{8.,1.,0.},{9.,1.,0.},{10.,1.,0.},{11.,1.,0.},{12.,1.,0.},
                    {0.,2.,0.},{1.,2.,0.},{2.,2.,0.},{3.,2.,0.},{4.,2.,0.},{5.,2.,0.},{6.,2.,0.},{7.,2.,0.},{8.,2.,0.},{9.,2.,0.},{10.,2.,0.},{11.,2.,0.},{12.,2.,0.},
                    {0.,3.,0.},{1.,3.,0.},{2.,3.,0.},{3.,3.,0.},{4.,3.,0.},{5.,3.,0.},{6.,3.,0.},{7.,3.,0.},{8.,3.,0.},{9.,3.,0.},{10.,3.,0.},{11.,3.,0.},{12.,3.,0.},
                    {0.,4.,0.},{1.,4.,0.},{2.,4.,0.},{3.,4.,0.},{4.,4.,0.},{5.,4.,0.},{6.,4.,0.},{7.,4.,0.},{8.,4.,0.},{9.,4.,0.},{10.,4.,0.},{11.,4.,0.},{12.,4.,0.},
                    {0.,5.,0.},{1.,5.,0.},{2.,5.,0.},{3.,5.,0.},{4.,5.,0.},{5.,5.,0.},{6.,5.,0.},{7.,5.,0.},{8.,5.,0.},{9.,5.,0.},{10.,5.,0.},{11.,5.,0.},{12.,5.,0.},
                    {0.,6.,0.},{1.,6.,0.},{2.,6.,0.},{3.,6.,0.},{4.,6.,0.},{5.,6.,0.},{6.,6.,0.},{7.,6.,0.},{8.,6.,0.},{9.,6.,0.},{10.,6.,0.},{11.,6.,0.},{12.,6.,0.},
                    {0.,7.,0.},{1.,7.,0.},{2.,7.,0.},{3.,7.,0.},{4.,7.,0.},{5.,7.,0.},{6.,7.,0.},{7.,7.,0.},{8.,7.,0.},{9.,7.,0.},{10.,7.,0.},{11.,7.,0.},{12.,7.,0.},
                    {0.,8.,0.},{1.,8.,0.},{2.,8.,0.},{3.,8.,0.},{4.,8.,0.},{5.,8.,0.},{6.,8.,0.},{7.,8.,0.},{8.,8.,0.},{9.,8.,0.},{10.,8.,0.},{11.,8.,0.},{12.,8.,0.},
                    {0.,9.,0.},{1.,9.,0.},{2.,9.,0.},{3.,9.,0.},{4.,9.,0.},{5.,9.,0.},{6.,9.,0.},{7.,9.,0.},{8.,9.,0.},{9.,9.,0.},{10.,9.,0.},{11.,9.,0.},{12.,9.,0.},
                    {0.,10.,0.},{1.,10.,0.},{2.,10.,0.},{3.,10.,0.},{4.,10.,0.},{5.,10.,0.},{6.,10.,0.},{7.,10.,0.},{8.,10.,0.},{9.,10.,0.},{10.,10.,0.},{11.,10.,0.},{12.,10.,0.},
                    {0.,11.,0.},{1.,11.,0.},{2.,11.,0.},{3.,11.,0.},{4.,11.,0.},{5.,11.,0.},{6.,11.,0.},{7.,11.,0.},{8.,11.,0.},{9.,11.,0.},{10.,11.,0.},{11.,11.,0.},{12.,11.,0.},
                    {-1.,-1.,-1.}};



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
		
		
float plant[8][3] = {{0.,0.6,0.1},
		{2.,3.,2.},{2.,4.,2.},{2.,5.,2.},{2.,6.,2.},{2.,7.,3.},
		{1.,5.,1.},
		{-1.,-1.,-1.}};
