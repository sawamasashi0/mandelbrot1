#include <iostream>
#include <fstream>
#include <vector>
#include <math.h>
#include <algorithm>
#include <string>
#include <map>
#include <iomanip>
#include <sstream>
#include <ctime>
#include <chrono>
#include <unistd.h>

#define rep(i,N) for(int i=0; i<(int)N;i++)
using namespace std;


int main(int argc,char *argv[]){
    int zoom=420;
    rep(l,zoom){
        double length=4*pow(0.96,l);
        ostringstream ss;
        ss << setw(3) << setfill('0') <<l+1;
        string name(ss.str());
        string file_o="/nfs/home/masashi/colloid/data/2020.07.15/man_"+name+".dat";
        double L=int(pow(1.013,l+1))*100;

     //   double length=0.00000005;
        int num=500;
     //   int L=15000;
        double a, b;
    //    double cx=-0.2477;
        double cx=-0.109293575;
    //    double cy=0.7477;
        double cy= 0.895245185;
        vector<int> image(num*num);
    //    string file_o="/nfs/home/masashi/colloid/data/2020.07.15/mandelbrot.dat";
        rep(i,num){
            a=length/num*i-length/2.0+cx;
            rep(j,num){
                b=length/num*j-length/2.0+cy;
                double x=0;
                double y=0;
                rep(k,L){
                    double _x=pow(x,2.0)-pow(y,2.0)+a;
                    double _y=2.0*x*y+b;
                    x=_x;
                    y=_y;
                    image.at(i*num+j)++;
                    if(pow(x,2)+pow(y,2)>100){
                        break;
                    }
                }
            }
        }
        ofstream file_o1(file_o.c_str());
        rep(i,num){
            rep(j,num){
                file_o1<<fixed <<setprecision(18)<<length/num*i-length/2.0+cx<<" "<<length/num*j-length/2.0+cy<<" "<<image.at(i*num+j)<<endl;
            }
        }
    }

    return 0;
}

