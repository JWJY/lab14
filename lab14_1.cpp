#include <iostream>
#include <cmath>
using namespace std;

void stat(const double[],int,double[]);

int main(){
    double A[] = {1.2,3.5,6.9,7.8,12.5,0.5};
    int N = sizeof(A)/sizeof(A[0]);
    double B[6];
    stat(A,N,B);
    cout << "Arithmetic Mean = " << B[0];
    cout << "\nStandard Deviation = " << B[1];
    cout << "\nGeometric Mean = " << B[2];
    cout << "\nHarmonic Mean = " << B[3];
    cout << "\nMax = " << B[4];
    cout << "\nMin = " << B[5];
    return 0;
}

void stat(const double a[], int n, double b[]){
    double max = a[0], min = a[0];
    double sum = 0, sum_SD = 0, mean, SD, sum_GM = 1, GM, sum_HM = 0, HM;
    for(int i=0 ; i<n ; i++){
        sum += a[i];
        sum_SD += pow(a[i],2);
        sum_GM *= a[i];
        sum_HM += (1/a[i]);
        if(a[i]>max) max = a[i];
        if(a[i]<min) min = a[i];
    }
    mean = (sum/n);
    SD = sqrt((sum_SD/n) - pow(mean,2));
    GM = pow(sum_GM,1.0/n);
    HM = (n/sum_HM);
    b[0] = mean;
    b[1] = SD;
    b[2] = GM;
    b[3] = HM;
    b[4] = max;
    b[5] = min;
}