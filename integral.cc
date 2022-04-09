#include <iostream>
#include <cmath>
#include <fstream>
#define INT_RES 60
//INT_RES jest ewidentnie do dopasowania, optymalnie ~1000, wtedy dostajemy ~30 s na obliczenie
//prawdopodobnie można zmniejszyć do nawet INT_RES=20, ale taki 20 kąt to nawet nie jest koło :(

double under_integral(double m, double M, double l0x, double l0y, double rho,double phi, double z){
    double DELl02 = l0x*l0x+l0y*l0y;
    double DELr2 = (rho*rho+DELl02+z*z-2*rho*sqrt(DELl02)*cos(phi));
    return rho*m*M*(1/DELr2/DELr2-5/DELr2);
}

void linspace(double array[INT_RES], double min, double max){
    double dx = (max-min)/INT_RES;
    array[0] = min;
    for (int i=1 ; i<INT_RES ; i++){
        array[i] = array[i-1]+dx;
    }
    return;
}

double integral(double R, double Z, double m, double M, double l0x, double l0y){
    double rho[INT_RES];
    double zlin[INT_RES];
    double phi[INT_RES];
    linspace(rho,0,R);
    linspace(zlin,-Z/2,Z/2);
    linspace(phi,0,2*M_PI);
    double drho = rho[1]-rho[0];
    double dz = zlin[1]-zlin[0];
    double dphi = phi[1]-phi[0];
    double result = 0;

    for (double r : rho){
        for (double z : zlin){
            for (double p : phi){
                result += under_integral(m, M, l0x, l0y, r, p, z)*drho*dz*dphi;
            }
        }
    }

    return result;
}

int main(int argc, char** argv){


    double R = atof(argv[1]);
    double Z = atof(argv[2]);
    double m = atof(argv[3]);
    double M = atof(argv[4]);
    double l0x = atof(argv[5]);
    double l0y = atof(argv[6]);
    

    std::ofstream File("can.txt");
    File << integral(R,Z,m,M,l0x,l0y);
    File.close();


    return 0;   
}
