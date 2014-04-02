/*
 * SignalFilter.cpp
 *
 *  Created on: Mar 23, 2014
 *      Author: CarlosJose
 */

#ifndef File_SignalFilter
#define File_SignalFilter

#include <deque>
#include <complex>
#include <vector>

using namespace std;
struct SignalFilter
{
	typedef complex<double> CD;
	typedef long long Long;
	int FRONT_FRAMES;
	int MIDDLE_FRAMES;
	int BACK_FRAMES;
	int unProcessedFrames;
	void (*treatSignal)(CD *CV,const int SZ) ;
	static void doNothing(CD *CV, const int SZ){}
	SignalFilter(void (*process)(CD *CV,const int SZ) = doNothing){
		FRONT_FRAMES = 256;
		MIDDLE_FRAMES = 512;
		BACK_FRAMES = 256;
		unProcessedFrames = 0;
		this->treatSignal = process;
	}
	struct Fourier
	{
		typedef vector<complex<double> > VCD;
		 
		#define MAXN 1000000
		static void four1(double *data, Long nn) {
			Long n, mmax, m, j, istep, i;
			double wtemp, wr, wpr, wpi, wi, theta;
			double tempr, tempi;

			// reverse-binary reindexing
			n = nn << 1;
			j = 1;
			for (i = 1; i < n; i += 2) {
				if (j > i) {
					swap(data[j - 1], data[i - 1]);
					swap(data[j], data[i]);
				}
				m = nn;
				while (m >= 2 && j > m) {
					j -= m;
					m >>= 1;
				}
				j += m;
			};
			// here begins the Danielson-Lanczos section
			mmax = 2;
			while (n > mmax) {
				istep = mmax << 1;
				theta = -(2 * M_PI / mmax);
				wtemp = sin(0.5 * theta);
				wpr = -2.0 * wtemp * wtemp;
				wpi = sin(theta);
				wr = 1.0;
				wi = 0.0;
				for (m = 1; m < mmax; m += 2) {
					for (i = m; i <= n; i += istep) {
						j = i + mmax;
						tempr = wr * data[j - 1] - wi * data[j];
						tempi = wr * data[j] + wi * data[j - 1];
						data[j - 1] = data[i - 1] - tempr;
						data[j] = data[i] - tempi;
						data[i - 1] += tempr;
						data[i] += tempi;
					}
					wtemp = wr;
					wr += wr * wpr - wi * wpi;
					wi += wi * wpr + wtemp * wpi;
				}
				mmax = istep;
			}
		}
		static void _FFT(CD *V, Long &N)
		{
			 while(N ^ (N & -N))
			 {
				 V[N].real(0);
				 V[N].imag(0);
				 N++;
			 }
			 double *A_T = new double[2*N + 10];
	//			double A_T[6*MAXN];
			 for(int i = 0; i < N; ++i)
			 {
				 A_T[i+i] = V[i].real();
				 A_T[i+i+1]=V[i].imag();
             }
			 four1(A_T,N);
			 for(int i = 0; i < N; ++i)
			 {
				 V[i].real(A_T[i+i]);
				 V[i].imag(A_T[i+i+1]);
			 }
			 delete[] A_T;
		}
		static void _IFFT(CD *V , Long &N)
		{
			 for(int i = 0; i < N; ++i)
				 V[i].imag(V[i].imag() * -1);
			 _FFT(V , N);
			 for(int i = 0; i < N; ++i)
			 {
				 V[i].imag(V[i].imag() * -1);
				 V[i] *= 1.0/double(N);
			 }
		}
		static void doNothing(CD *CV, const int SZ){}
		static vector<double> FFT(vector<double> V , void (*process)(CD *CV,const int SZ) = doNothing)
		{
			Long SZ = V.size();
			CD *CV = new CD[2 * V.size()];
			for(int i = 0; i < (int)V.size(); ++i)
				CV[i].real(V[i]), CV[i].imag(0);
			_FFT(CV , SZ);
			process(CV,SZ);
			_IFFT(CV , SZ);
			for(int i = 0; i < (int)V.size(); ++i)
				V[i] = CV[i].real();
			delete[] CV;
			return V;
		}
	};
	
	deque<float> beingProcessed;
	deque<float> toExit;
	
	float front(){
		if(toExit.size() == 0)return 0;
		return toExit.front();
	}
	float pop(){
		float ret = front();
		if(toExit.size() == 0)return ret;
		toExit.pop_front();
		return ret;
	}
	
	void push(double magnitude)
	{
		beingProcessed.push_back(magnitude);
		if((int)beingProcessed.size() > FRONT_FRAMES + MIDDLE_FRAMES + BACK_FRAMES)
			beingProcessed.pop_front();
		unProcessedFrames++;
		if(beingProcessed.size() != FRONT_FRAMES + MIDDLE_FRAMES + BACK_FRAMES)return;
		if(unProcessedFrames >= MIDDLE_FRAMES + BACK_FRAMES)
		{
			vector<double> D = getProcessedSignal(treatSignal);
			for(int i = 0; i < D.size(); ++i){
				toExit.push_back(D[i]);
				unProcessedFrames--;
			}
		}
	}
	
	vector<double> getProcessedSignal(void (*process)(CD *CV,const int SZ) = doNothing)
	{
		vector<double> V(beingProcessed.begin(),beingProcessed.end());
		V = Fourier::FFT(V,process);
		return vector<double>(V.begin()+FRONT_FRAMES , V.begin() + FRONT_FRAMES + MIDDLE_FRAMES);
	}
};

#endif
