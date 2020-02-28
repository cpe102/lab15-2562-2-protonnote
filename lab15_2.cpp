#include<iostream>
#include<cstdlib>
#include<ctime>
#include <iomanip>
using namespace std;

void randData(double *,int,int);

void findColSum(const double *,double *,int,int);

void showData(double *,int,int);

int main(){
	srand(time(0));
	const int N = 7, M = 7;
	double data[N][M] = {};
	double result[M] = {};
	double *dPtr = data[0];
	randData(dPtr,N,M);
	showData(dPtr,N,M);
	
	cout << "---------------------------------------------\n";
	
	findColSum(dPtr,result,N,M); 
	showData(result,1,M);
}

//Write definition of randData(), showData() and findColSum()
void randData(double *dPtr,int N,int M){
	double x =0;
	for(int i =0;i<M*N;i++){
		double x = rand()%100/(double)100;
		setprecision(2);
		*(dPtr+i) = x;	
		}
}

void findColSum(const double *dPtr,double *result,int N,int M){
	
	for(int j = 0 ; j < N ; j++){
		double sum = 0;
		for(int i = 0 ; i < 7 ; i++){
		 	sum += *((dPtr+i*N)+j);
		}
		result[j] = sum;
	}
}

void showData(double *dPtr,int N,int M){
	for(int i = 0 ; i < M*N ; i++ ){
		if(i%M == 0){ 
			cout << "\n";
		}
		cout << setw(6) << left << *(dPtr+i) ;
	}
	cout << endl;
}
