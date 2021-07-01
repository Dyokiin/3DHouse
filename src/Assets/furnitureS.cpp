#include "../../include/assets.hpp"

float stool[][3] = {{.2,.1,.1},
{0.,1.,0.},{0.,2.,0.},{0.,3.,0.},{0.,4.,0.},{0.,5.,0.},{0.,6.,0.},{0.,7.,0.},{0.,8.,0.},{0.,9.,0.},{0.,10.,0.},{0.,11.,0.},{0.,12.,0.},{0.,13.,0.},{0.,14.,0.},{0.,15.,0.},
{5.,1.,0.},{5.,2.,0.},{5.,3.,0.},{5.,4.,0.},{5.,5.,0.},{5.,6.,0.},{5.,7.,0.},{5.,8.,0.},{5.,9.,0.},{5.,10.,0.},{5.,11.,0.},{5.,12.,0.},{5,13.,0.},{5.,14.,0.},{5.,15.,0.},
{0.,1.,5.},{0.,2.,5.},{0.,3.,5.},{0.,4.,5.},{0.,5.,5.},{0.,6.,5.},{0.,7.,5.},{0.,8.,5.},{0.,9.,5.},{0.,10.,5.},{0.,11.,5.},{0.,12.,5.},{0.,13.,5.},{0.,14.,5.},{0.,15.,5.},
{5.,1.,5.},{5.,2.,5.},{5.,3.,5.},{5.,4.,5.},{5.,5.,5.},{5.,6.,5.},{5.,7.,5.},{5.,8.,5.},{5.,9.,5.},{5.,10.,5.},{5.,11.,5.},{5.,12.,5.},{5.,13.,5.},{5.,14.,5.},{5.,15.,5.},
{1,15,-1},{2,15,-1},{3,15,-1},{4,15,-1},
{1,15,6},{2,15,6},{3,15,6},{4,15,6},
{6,15,1},{6,15,2},{6,15,3},{6,15,4},
{-1,15,1},{-1,15,2},{-1,15,3},{-1,15,4},
                    {-1,-1,-1}};

float etagS[352][3] = {{.3,.2,.2},
{0.,0.,0.},{0.,1.,0.},{0.,2.,0.},{0.,3.,0.},{0.,4.,0.},{0.,5.,0.},{0.,6.,0.},{0.,7.,0.},{0.,8.,0.},{0.,9.,0.},{0.,10.,0.},{0.,11.,0.},{0.,12.,0.},{0.,13.,0.},{0.,14.,0.},{0.,15.,0.},{0.,16.,0.},{0.,17.,0.},{0.,18.,0.},{0.,19.,0.},{0.,20.,0.},{0.,21.,0.},{0.,22.,0.},{0.,23.,0.},{0.,24.,0.},{0.,25.,0.},{0.,26.,0.},{0.,27.,0.},{0.,28.,0.},{0.,29.,0.},{0.,30.,0.},{0.,31.,0.},{0.,32.,0.},{0.,33.,0.},{0.,34.,0.},{0.,35.,0.},{0.,36.,0.},{0.,37.,0.},{0.,38.,0.},{0.,39.,0.},{0.,40.,0.},{0.,41.,0.},{0.,42.,0.},{0.,43.,0.},{0.,44.,0.},{0.,45.,0.},{0.,46.,0.},{0.,47.,0.},{0.,48.,0.},{0.,49.,0.},{0.,50.,0.},{0.,51.,0.},{0.,52.,0.},{0.,53.,0.},{0.,54.,0.},{0.,55.,0.},{0.,56.,0.},{0.,57.,0.},{0.,58.,0.},{0.,59.,0.},{0.,60.,0.},{0.,61.,0.},{0.,62.,0.},{0.,63.,0.},{0.,64.,0.},{0.,65.,0.},{0.,66.,0.},{0.,67.,0.},{0.,68.,0.},{0.,69.,0.},
{1.,0.,0.},{1.,1.,0.},{1.,2.,0.},{1.,3.,0.},{1.,4.,0.},{1.,5.,0.},{1.,6.,0.},{1.,7.,0.},{1.,8.,0.},{1.,9.,0.},{1.,10.,0.},{1.,11.,0.},{1.,12.,0.},{1.,13.,0.},{1.,14.,0.},{1.,15.,0.},{1.,16.,0.},{1.,17.,0.},{1.,18.,0.},{1.,19.,0.},{1.,20.,0.},{1.,21.,0.},{1.,22.,0.},{1.,23.,0.},{1.,24.,0.},{1.,25.,0.},{1.,26.,0.},{1.,27.,0.},{1.,28.,0.},{1.,29.,0.},{1.,30.,0.},{1.,31.,0.},{1.,32.,0.},{1.,33.,0.},{1.,34.,0.},{1.,35.,0.},{1.,36.,0.},{1.,37.,0.},{1.,38.,0.},{1.,39.,0.},{1.,40.,0.},{1.,41.,0.},{1.,42.,0.},{1.,43.,0.},{1.,44.,0.},{1.,45.,0.},{1.,46.,0.},{1.,47.,0.},{1.,48.,0.},{1.,49.,0.},{1.,50.,0.},{1.,51.,0.},{1.,52.,0.},{1.,53.,0.},{1.,54.,0.},{1.,55.,0.},{1.,56.,0.},{1.,57.,0.},{1.,58.,0.},{1.,59.,0.},{1.,60.,0.},{1.,61.,0.},{1.,62.,0.},{1.,63.,0.},{1.,64.,0.},{1.,65.,0.},{1.,66.,0.},{1.,67.,0.},{1.,68.,0.},{1.,69.,0.},
{2.,0.,0.},{2.,1.,0.},{2.,2.,0.},{2.,3.,0.},{2.,4.,0.},{2.,5.,0.},{2.,6.,0.},{2.,7.,0.},{2.,8.,0.},{2.,9.,0.},{2.,10.,0.},{2.,11.,0.},{2.,12.,0.},{2.,13.,0.},{2.,14.,0.},{2.,15.,0.},{2.,16.,0.},{2.,17.,0.},{2.,18.,0.},{2.,19.,0.},{2.,20.,0.},{2.,21.,0.},{2.,22.,0.},{2.,23.,0.},{2.,24.,0.},{2.,25.,0.},{2.,26.,0.},{2.,27.,0.},{2.,28.,0.},{2.,29.,0.},{2.,30.,0.},{2.,31.,0.},{2.,32.,0.},{2.,33.,0.},{2.,34.,0.},{2.,35.,0.},{2.,36.,0.},{2.,37.,0.},{2.,38.,0.},{2.,39.,0.},{2.,40.,0.},{2.,41.,0.},{2.,42.,0.},{2.,43.,0.},{2.,44.,0.},{2.,45.,0.},{2.,46.,0.},{2.,47.,0.},{2.,48.,0.},{2.,49.,0.},{2.,50.,0.},{2.,51.,0.},{2.,52.,0.},{2.,53.,0.},{2.,54.,0.},{2.,55.,0.},{2.,56.,0.},{2.,57.,0.},{2.,58.,0.},{2.,59.,0.},{2.,60.,0.},{2.,61.,0.},{2.,62.,0.},{2.,63.,0.},{2.,64.,0.},{2.,65.,0.},{2.,66.,0.},{2.,67.,0.},{2.,68.,0.},{2.,69.,0.},
{3.,0.,0.},{3.,1.,0.},{3.,2.,0.},{3.,3.,0.},{3.,4.,0.},{3.,5.,0.},{3.,6.,0.},{3.,7.,0.},{3.,8.,0.},{3.,9.,0.},{3.,10.,0.},{3.,11.,0.},{3.,12.,0.},{3.,13.,0.},{3.,14.,0.},{3.,15.,0.},{3.,16.,0.},{3.,17.,0.},{3.,18.,0.},{3.,19.,0.},{3.,20.,0.},{3.,21.,0.},{3.,22.,0.},{3.,23.,0.},{3.,24.,0.},{3.,25.,0.},{3.,26.,0.},{3.,27.,0.},{3.,28.,0.},{3.,29.,0.},{3.,30.,0.},{3.,31.,0.},{3.,32.,0.},{3.,33.,0.},{3.,34.,0.},{3.,35.,0.},{3.,36.,0.},{3.,37.,0.},{3.,38.,0.},{3.,39.,0.},{3.,40.,0.},{3.,41.,0.},{3.,42.,0.},{3.,43.,0.},{3.,44.,0.},{3.,45.,0.},{3.,46.,0.},{3.,47.,0.},{3.,48.,0.},{3.,49.,0.},{3.,50.,0.},{3.,51.,0.},{3.,52.,0.},{3.,53.,0.},{3.,54.,0.},{3.,55.,0.},{3.,56.,0.},{3.,57.,0.},{3.,58.,0.},{3.,59.,0.},{3.,60.,0.},{3.,61.,0.},{3.,62.,0.},{3.,63.,0.},{3.,64.,0.},{3.,65.,0.},{3.,66.,0.},{3.,67.,0.},{3.,68.,0.},{3.,69.,0.},
{4.,0.,0.},{4.,1.,0.},{4.,2.,0.},{4.,3.,0.},{4.,4.,0.},{4.,5.,0.},{4.,6.,0.},{4.,7.,0.},{4.,8.,0.},{4.,9.,0.},{4.,10.,0.},{4.,11.,0.},{4.,12.,0.},{4.,13.,0.},{4.,14.,0.},{4.,15.,0.},{4.,16.,0.},{4.,17.,0.},{4.,18.,0.},{4.,19.,0.},{4.,20.,0.},{4.,21.,0.},{4.,22.,0.},{4.,23.,0.},{4.,24.,0.},{4.,25.,0.},{4.,26.,0.},{4.,27.,0.},{4.,28.,0.},{4.,29.,0.},{4.,30.,0.},{4.,31.,0.},{4.,32.,0.},{4.,33.,0.},{4.,34.,0.},{4.,35.,0.},{4.,36.,0.},{4.,37.,0.},{4.,38.,0.},{4.,39.,0.},{4.,40.,0.},{4.,41.,0.},{4.,42.,0.},{4.,43.,0.},{4.,44.,0.},{4.,45.,0.},{4.,46.,0.},{4.,47.,0.},{4.,48.,0.},{4.,49.,0.},{4.,50.,0.},{4.,51.,0.},{4.,52.,0.},{4.,53.,0.},{4.,54.,0.},{4.,55.,0.},{4.,56.,0.},{4.,57.,0.},{4.,58.,0.},{4.,59.,0.},{4.,60.,0.},{4.,61.,0.},{4.,62.,0.},{4.,63.,0.},{4.,64.,0.},{4.,65.,0.},{4.,66.,0.},{4.,67.,0.},{4.,68.,0.},{4.,69.,0.},
    {-1,-1,-1}};

float etagC[197][3] = {{.3,.2,.2},
{0.,0.,1.},{0.,0.,2.},{0.,0.,3.},{0.,0.,4.},{0.,0.,5.},{0.,0.,6.},{0.,0.,7.},{0.,0.,8.},{0.,0.,9.},{0.,0.,10.},{0.,0.,11.},{0.,0.,12.},{0.,0.,13.},{0.,0.,14.},{0.,0.,15.},{0.,0.,16.},{0.,0.,17.},{0.,0.,18.},{0.,0.,19.},{0.,0.,20.},{0.,0.,21.},{0.,0.,22.},{0.,0.,23.},{0.,0.,24.},{0.,0.,25.},{0.,0.,26.},{0.,0.,27.},{0.,0.,28.},{0.,0.,29.},{0.,0.,30.},{0.,0.,31.},{0.,0.,32.},{0.,0.,33.},{0.,0.,34.},{0.,0.,35.},{0.,0.,36.},{0.,0.,37.},{0.,0.,38.},{0.,0.,39.},
{1.,0.,1.},{1.,0.,2.},{1.,0.,3.},{1.,0.,4.},{1.,0.,5.},{1.,0.,6.},{1.,0.,7.},{1.,0.,8.},{1.,0.,9.},{1.,0.,10.},{1.,0.,11.},{1.,0.,12.},{1.,0.,13.},{1.,0.,14.},{1.,0.,15.},{1.,0.,16.},{1.,0.,17.},{1.,0.,18.},{1.,0.,19.},{1.,0.,20.},{1.,0.,21.},{1.,0.,22.},{1.,0.,23.},{1.,0.,24.},{1.,0.,25.},{1.,0.,26.},{1.,0.,27.},{1.,0.,28.},{1.,0.,29.},{1.,0.,30.},{1.,0.,31.},{1.,0.,32.},{1.,0.,33.},{1.,0.,34.},{1.,0.,35.},{1.,0.,36.},{1.,0.,37.},{1.,0.,38.},{1.,0.,39.},
{2.,0.,1.},{2.,0.,2.},{2.,0.,3.},{2.,0.,4.},{2.,0.,5.},{2.,0.,6.},{2.,0.,7.},{2.,0.,8.},{2.,0.,9.},{2.,0.,10.},{2.,0.,11.},{2.,0.,12.},{2.,0.,13.},{2.,0.,14.},{2.,0.,15.},{2.,0.,16.},{2.,0.,17.},{2.,0.,18.},{2.,0.,19.},{2.,0.,20.},{2.,0.,21.},{2.,0.,22.},{2.,0.,23.},{2.,0.,24.},{2.,0.,25.},{2.,0.,26.},{2.,0.,27.},{2.,0.,28.},{2.,0.,29.},{2.,0.,30.},{2.,0.,31.},{2.,0.,32.},{2.,0.,33.},{2.,0.,34.},{2.,0.,35.},{2.,0.,36.},{2.,0.,37.},{2.,0.,38.},{2.,0.,39.},
{3.,0.,1.},{3.,0.,2.},{3.,0.,3.},{3.,0.,4.},{3.,0.,5.},{3.,0.,6.},{3.,0.,7.},{3.,0.,8.},{3.,0.,9.},{3.,0.,10.},{3.,0.,11.},{3.,0.,12.},{3.,0.,13.},{3.,0.,14.},{3.,0.,15.},{3.,0.,16.},{3.,0.,17.},{3.,0.,18.},{3.,0.,19.},{3.,0.,20.},{3.,0.,21.},{3.,0.,22.},{3.,0.,23.},{3.,0.,24.},{3.,0.,25.},{3.,0.,26.},{3.,0.,27.},{3.,0.,28.},{3.,0.,29.},{3.,0.,30.},{3.,0.,31.},{3.,0.,32.},{3.,0.,33.},{3.,0.,34.},{3.,0.,35.},{3.,0.,36.},{3.,0.,37.},{3.,0.,38.},{3.,0.,39.},
{4.,0.,1.},{4.,0.,2.},{4.,0.,3.},{4.,0.,4.},{4.,0.,5.},{4.,0.,6.},{4.,0.,7.},{4.,0.,8.},{4.,0.,9.},{4.,0.,10.},{4.,0.,11.},{4.,0.,12.},{4.,0.,13.},{4.,0.,14.},{4.,0.,15.},{4.,0.,16.},{4.,0.,17.},{4.,0.,18.},{4.,0.,19.},{4.,0.,20.},{4.,0.,21.},{4.,0.,22.},{4.,0.,23.},{4.,0.,24.},{4.,0.,25.},{4.,0.,26.},{4.,0.,27.},{4.,0.,28.},{4.,0.,29.},{4.,0.,30.},{4.,0.,31.},{4.,0.,32.},{4.,0.,33.},{4.,0.,34.},{4.,0.,35.},{4.,0.,36.},{4.,0.,37.},{4.,0.,38.},{4.,0.,39.},
    {-1,-1,-1}};