#include <iostream>
#include <time.h>
#include <iomanip>
#include <cmath>


using namespace std;
#define IA 16807
#define IM 2147483647
#define AM (1.0/IM)
#define IQ 127773
#define IR 2836
#define MASK 123459876

typedef struct Ran0
{
  float ran0(long *idum)
  {
    long k;
    float ans;

    *idum ^= MASK;
    k=(*idum)/IQ;
    *idum=IA*(*idum-k*IQ)-IR*k;

    if (*idum < 0) *idum += IM;
    ans=AM*(*idum);
    *idum ^= MASK;

    return ans;
  }

  void line()
  {
    for(int i=1;i<30;i++)
    cout<<"--";
    cout<<"\n";
  }
}R0;


int main (void)
{
  R0 n;
  long seed= 123456789;
  long *idum=&seed;
  float X[10000], Y[10000];
  float r,Npond=0,Nbox=0,Apond,Abox=4;

  //Guardando en dos arreglos numeros random
  for (int i=0; i<10000; i++)
  {
    X[i]=n.ran0(idum);
  }

  for (int i=0; i<10000; i++)
  {
    Y[i]=n.ran0(idum);
  }

  //Hacer pitagoras
  for(int i=0; i<10000; i++)
  {
    r= sqrt( pow(X[i],2) + pow(Y[i],2) );
    if(r<1)
    {
      Npond++;
    }
    else
    {
      Nbox++;
    }

  }

  Apond= Npond/(Npond+Nbox)*Abox;
  printf("%f\n",Apond);

  return 0;
}
