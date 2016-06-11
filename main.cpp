#include <iostream>
#include "nbody.ispc.h"
#include "timing.h"
#include "nbody.h"
using std::cout; using std::endl;
void generateRandom(float* x,float* y, float* z, const int N);

#define EXECUTE(f) \
std::fill_n(fx,N,0);\
std::fill_n(fy,N,0);\
std::fill_n(fz,N,0);\
{\
reset_and_start_timer();\
f(N,x,y,z,fx,fy,fz);\
float dt=get_elapsed_mcycles();\
for(int i=0;i<4;i++){\
cout<<"x: "<<x[i]<<"\ty: "<<y[i]<<"\tz: "<<z[i];\
cout<<"\tfx: "<<x[i]<<"\tfy: "<<fy[i]<<"\tfz: "<<fz[i];\
cout<<endl;\
}\
cout<<"\n\n Elapsed Mcycles: "<<dt<<endl;\
}

int main() {
  constexpr int N = 4e3;
  float* x = new float[N];
  float* y = new float[N];
  float* z = new float[N];
  float* fx = new float[N];
  float* fy = new float[N];
  float* fz = new float[N];
  generateRandom(x,y,z,N);

  cout<<"Native g++ function:\n";
  EXECUTE(nbody_cxx);
  cout<<"ISPC kernel:\n";
  EXECUTE(ispc::nbody);

  delete []x; delete []y; delete []z;
  delete []fx; delete []fy; delete []fz;
}

#include <random>
void generateRandom(float* x,float* y, float* z, const int N){
  std::default_random_engine mt(0);
  std::uniform_real_distribution<float> ran(-1,1);
  for(int i=0;i<N;i++){
    x[i]=ran(mt);
    y[i]=ran(mt);
    z[i]=ran(mt);
  }
}


