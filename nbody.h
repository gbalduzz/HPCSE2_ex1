#pragma once

#include <cmath>
void nbody_cxx(const  int N, const  float x[], const  float y[], const   float z[],  float fx[],   float fy[],  float fz[])
{
  //compute forces in units of G for m[i]=0
  /*const  int size = sizeof(float)*N;
  memset(vfx, 0, size);
  memset(vfy, 0, size);
  memset(vfz, 0, size);*/

  for( int i=0;i<N;i++){
    for(int j=i+1; j<N; j++){
      const float dx= x[j]-x[i];
      const float dy= y[j]-y[i];
      const float dz= z[j]-z[i];
      const float r3= std::pow(dx*dx+dy*dy+dz*dz,3./2.);

      const float dfx= dx/r3;
      fx[i]+= dfx;
      fx[j]-= dfx;

      const float dfy= dy/r3;
      fy[i]+= dfy;
      fy[j]-= dfy;

      const float dfz= dz/r3;
      fz[i]+= dfz;
      fz[j]-= dfz;
    }
  }
}
