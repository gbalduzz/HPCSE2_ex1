export void nbody(const uniform int N, const uniform float x[], const uniform float y[], const uniform  float z[], uniform float fx[], uniform  float fy[], uniform float fz[])
{
  //compute forces in units of G for m[i]=0
  float * vfx = new float[N];
  float * vfy = new float[N];
  float * vfz = new float[N];

for(uniform int i=0;i<N;i++){
  foreach(j=i+1 ... N){
    const float dx= x[j]-x[i];
    const float dy= y[j]-y[i];
    const float dz= z[j]-z[i];
    const float r3= pow(dx*dx+dy*dy+dz*dz,3./2.);

    const float dfx= dx/r3;
    vfx[i]+= dfx;
    vfx[j]-= dfx;

    const float dfy= dy/r3;
    vfy[i]+= dfy;
    vfy[j]-= dfy;

    const float dfz= dz/r3;
    vfz[i]+= dfz;
    vfz[j]-= dfz;
  }
  }
  foreach(i=0 ... N){
    fx[i]=reduce_add(vfx[i]);
    fy[i]=reduce_add(vfy[i]);
    fz[i]=reduce_add(vfz[i]);
  }
  delete[] vfx;delete[] vfy;delete[] vfz;
}
