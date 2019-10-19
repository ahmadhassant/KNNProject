#include "stat.h"
using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::IO;


class Mat {
public:
	Mat(long ,long );
	~Mat();
	float get( long ROW, long COLMN); 
	void set (long ROW,long COLMN, float ); 
	long Row();
	long RowCountOfaClass(int cls);
	int NumberOfClasses();
	long Col();
	void Normalize();
	void ZNormalize();
	void Noise(float R);
	void getCol(float Column[], long m);
	float * getColOfClass(long &n,long m,int cls);
	float getMedianOfClass(long c, int cls);
	twovalues getQuartileOfClass(long c, int cls);
	void getRow(float FV[], long m);
	float * getRow(long m);

	void getRowofMedianOfClass(float FV[], long m, int cls);
	void getRowaverageofMedianOfClass(float FV[], long m, int cls);
	void getRowaverageofQuartilesOfClass(float FVQ1[], float FVQ2[],long m, int cls);
	//char ** classes;
	long * classint;
	long * NumRowPerClass;//arrAY CONTAINING THE NUMBER OF RECORDS FOR EACH CLASS 
	void UpdateNumRowPerClass();
	long NumClasses;
	float *weights;
	float *Max; //the maximum virtual fv, each cel is the max for each col
	float *Min; //the minimum virtual fv, each cel is the min for each col
	void setMaxes();
	float *Norms;//eucledian norms 
	float *ShiftedNorms;//eucledian norms after shifting fvs by subtracting from min Virtual Fv.
	void UpdateNorms();
	void UpdateNorms(int);//update specific norm based on distance
	void UpdateShiftedNorms();
	void UpdateClasses();//this update classes to make them starting from 0 to max class
	
private: 
	long num_row;//number of examples 
	long num_col;//number of features
	float * val;//value of feature in row clo 
};


Mat::Mat(long nrow, long ncol){
	//initialize matrix
	  num_row=nrow;
	  num_col=ncol;
	val =new float [num_row * num_col];
	classint = new long[num_row];
	weights = new float[num_col];
	Max = new float[num_col];//Maximum virtual FV
	Min = new float[num_col];//min virtual FV

	//this->setMaxes(); 
	Norms = new float[num_row];
	ShiftedNorms = new float[num_row];
	//UpdateClasses();
	NumRowPerClass = 0;//new long[NumClasses];
/*	classes=new char*[num_row];
	for (int i=0;i<num_row;i++)
		classes[i]=new char[10];*/
	return;
}
float Mat::get(long row, long col){
	//return a value in the matrix given the feature vector number and the feature number
	return val[row * this->num_col + col];
}
long Mat::Row(){
	//return the number of feature vectors (rows)
	return num_row;
	
}
int Mat::NumberOfClasses(){
	float MaxV=_MND;
	for (long r=0;r<num_row;r++){
		float cl=this->classint[r];
		if (cl > MaxV)
			MaxV=cl;
	}
	int _max=(int)	(MaxV +1) ;
	return _max;
}
//update classes to be from 0 to max number of classes, this is to ease some operations
void Mat::UpdateClasses (){
	long MaxV= -1;
	
	for (long r=0;r<num_row;r++){
		long cl=this->classint[r];
		if (cl > MaxV)
			MaxV=cl;	
	}
	MaxV++;
	
	long *arrayClasses=new long [MaxV];
	for (long i=0;i<MaxV;i++){
		arrayClasses[i]= -1;
	}
	for (long r=0;r<num_row;r++){
		long cl=this->classint[r];
		arrayClasses[cl]= cl;
	}

	long *NewArrayClasses=new long [MaxV];
	for (long i=0;i<MaxV;i++){
		NewArrayClasses[i]= -1;
	}
	long ctr=0;
	for (long i=0;i<MaxV;i++){
		if (arrayClasses[i]!= -1){
			NewArrayClasses[ctr]= arrayClasses[i];
			ctr++;
		}
	}
	NumClasses=ctr;
//updat classes based on new array
	for (long r=0;r<num_row;r++){
		long cl=this->classint[r];
		long i;
		for (i=0;i<MaxV;i++){
			if (NewArrayClasses[i]==cl)
				break;
		}
		this->classint[r]= i;
	}


	delete []arrayClasses;
	delete []NewArrayClasses;
	
}
//count the number of rows for each class and update NumRowPerClass
void Mat::UpdateNumRowPerClass (){
	
	NumRowPerClass=new long [NumClasses];
	
	for (long r=0;r<NumClasses;r++){
		NumRowPerClass[r]=0;
	}

	for (long r=0;r<num_row;r++){
		long cl=this->classint[r];
		NumRowPerClass[cl]++;
	}

}
long Mat::RowCountOfaClass(int cls){
	//return the number of feature vectors of a given class
	long count =0;
	for(long i=0;i<num_row;i++){
		if (this->classint[i]==cls)
			count++;
	}
	
	return count;
}
long Mat::Col(){
	//return the numbers of features (colmns) 
	return num_col;
}
void Mat::set(long row, long col, float v){
	//set value v in row,col 
	val[row* this->num_col +col]=v;
	return;
 }
void Mat::getCol(float C[],long m){
	//return the all values of a given feature (col)
	for (long i=0;i<num_row;i++)
		C[i]=val[i * this->num_col +m];
	return;
}
float * Mat::getColOfClass(long &n,long m,int cls){
	//return the number of vetors for a given class and all the values of a given feature (col)
	n=this->RowCountOfaClass(cls);
	if (n==0)
		return 0;
	float *C;
	C=new float [n];
	int index=0;
	for (long i=0;i<num_row;i++)
		if (this->classint[i]==cls){
			C[index++]=val[i * this->num_col +m];
		}
	return C;
}
float Mat::getMedianOfClass(long m,int cls){
	//return the median of a givin class of a given feature 
	long n=this->RowCountOfaClass(cls);
	if (n==0){
		return _MXD;
	}
	float *C=new float [n];
	long index=0;
	for (long i=0;i<num_row;i++){
		if (this->classint[i]==cls){
			C[index++]=val[i * this->num_col +m];
		}
	}
	float median=Median1(C,n);
	delete [] C;
	C=0;
	return median;
}
void Mat::getRowofMedianOfClass(float FV[],long m,int cls){
	//return the row of the median of a givin class of a given feature 
	long n=this->RowCountOfaClass(cls);
	if (n==0){
		for (long j=0;j<num_col;j++){ 
			FV[j]=_MXD;
		}
		return ;
	}

	float median =this->getMedianOfClass(m,cls);
	for (long i=0;i<num_row;i++){
		if (this->get(i,m) == median){
			for (long j=0;j<num_col;j++){ 
				FV[j]=this->get(i,j);
			}
			i=num_row;
			break;
		}
	}
}

void Mat::getRowaverageofMedianOfClass(float FV[],long m,int cls){
	//return the average row of the median of a givin class of a given feature 
	long n=this->RowCountOfaClass(cls);
	if (n==0){
		for (long j=0;j<num_col;j++){ 
			FV[j]=_MXD;
		}
		return ;
	}
	//initialize fv
		for (long j=0;j<num_col;j++)
			FV[j]=0.0;


	float median =this->getMedianOfClass(m,cls);
	float countermed=0.0;
	for (long i=0;i<num_row;i++){
		if (this->get(i,m) == median){
			countermed++;
			for (int j=0;j<num_col;j++){ 
				FV[j]+=this->get(i,j);
			}
		//	i=num_row;
		//	break;
		}
	}
	//average
		for (long j=0;j<num_col;j++)
				FV[j]=FV[j]/countermed;
}
void Mat::getRowaverageofQuartilesOfClass(float FVQ1[], float FVQ2[],long m,int cls){
	//return the average row of the quartiles of a givin class of a given feature 
	long n=this->RowCountOfaClass(cls);
	if (n==0){
		for (long j=0;j<num_col;j++){ 
			FVQ1[j]=_MXD;
			FVQ2[j]=_MXD;
		}
		return ;
	}
	//initialize fv
	for (long j=0;j<num_col;j++){
			FVQ1[j]=0.0;
			FVQ2[j]=0.0;
	}
	twovalues Qr=this->getQuartileOfClass(m,cls);
	float counterQr1=0.0;
	float counterQr2=0.0;
	for (long i=0;i<num_row;i++){
		if (this->get(i,m) == Qr.v1){
			counterQr1++;
			for (long j=0;j<num_col;j++)
				FVQ1[j]+=this->get(i,j);
		}
		if (this->get(i,m) == Qr.v2){
			counterQr2++;
			for (long j=0;j<num_col;j++) 
				FVQ2[j]+=this->get(i,j);
		}

	}
		
	//average
		for (long j=0;j<num_col;j++){
			FVQ1[j]=FVQ1[j]/counterQr1;
			FVQ2[j]=FVQ2[j]/counterQr2;
		}
		return ;
}

twovalues Mat::getQuartileOfClass(long m,int cls){
	//return the 1st and 3rd quartiles of a given feature  of a given class 
	long n=this->RowCountOfaClass(cls);
	if (n==0){
		twovalues tv; tv.v1=_MXD; tv.v2=_MXD;
		return tv;
	}
	float *C=new float [n];
	long index=0;
	for (long i=0;i<num_row;i++){
		if (this->classint[i]==cls){
			C[index++]=val[i * this->num_col +m];
		}
	}
	twovalues qr=quartiles(C,n);
	delete [] C;
	C=0;
	return qr;
}

void Mat::getRow(float R[],long n){
	//return a feature vetor given its index
	for (long i=0;i<num_col;i++)
		R[i]=val[i  + n * num_col];
	return;
}
float * Mat::getRow(long n){
	//return a feature vetor given its index
	float *fv= new float [num_col];
	for (long i=0;i<num_col;i++)
		fv[i]=val[i  + n * num_col];
	return fv;
}

void Mat::setMaxes(){
	//fill max and min valuess for each col to Virtual Min and Max FVs

		for (long c=0;c<num_col;c++){
			float v=this->get(0,c);
			Min[c]=Max[c]=v;
		 for (long r=1;r<num_row;r++){
			 float vv=this->get(r,c);
			if (Max[c] < vv)
				Max[c]= vv;
			if (Min[c] > vv)
				Min[c]= vv;
		}
	}


}

void Mat::Normalize(){
	//normalize all data by dividing on the max value for each col 
	float * MX=new float [num_col];
	float * MN=new float [num_col];
	for (long c=0;c<num_col;c++){
		MX[c]=this->get(0,c);
		MN[c]=this->get(0,c);
		for (long r=1;r<num_row;r++){
			if (MX[c] < this->get(r,c))
				MX[c]= this->get(r,c);
			if (MN[c] > this->get(r,c))
				MN[c]= this->get(r,c);
		}
	}
	for (long c=0;c<num_col;c++){
		
		for (long r=0;r<num_row;r++){
			float newval;
			//if (MX[c]!=0)
				newval=(this->get(r,c)-MN[c])/(MX[c]-MN[c]);
			//else
			//	newval=0;
			this->set(r,c,newval);
		}
	}

	delete []MX;
	MX=0;
	delete []MN;
	MN=0;
	return;
}
void Mat::ZNormalize () {
	//znormalize all data by subtracting from mean and dividing on the stdev for each col 
	float * MEANS = new float[num_col];
	float * STDEVS = new float[num_col];
	for (long c = 0;c < num_col;c++)
		MEANS[c] = 0.0;
	//clacl sum of each column for mean 
	for (long c = 0;c < num_col;c++) {
		for (long r = 0;r < num_row;r++) {
			MEANS[c]+= this->get(r, c);
		}
	}
	//clac mean
	for (long c = 0;c < num_col;c++)
		MEANS[c] = MEANS[c]/ (float)num_row;
	//clac stdev
	for (long c = 0;c < num_col;c++) {
		float sumdiff = 0.0;
		for (long r = 0;r < num_row;r++) {
			float diff = this->get(r, c) - MEANS[c];
			sumdiff += diff * diff;
		}
		STDEVS[c] = Math::Sqrt(sumdiff / (float)(num_row - 1));
	}
	//z-normalize data based on (v-mean)/stdev
	for (long c = 0;c < num_col;c++) {

		for (long r = 0;r < num_row;r++) {
			float newval;
			
			if (STDEVS[c]!=0)
				newval = (this->get(r, c) - MEANS[c]) / STDEVS[c];
			else
				newval=0;
			this->set(r, c, newval);
		}
	}

	delete[]MEANS;
	MEANS = 0;
	delete[]STDEVS;
	STDEVS = 0;
	return;
}
void Mat::Noise(float R){
	//Add noise
	float * MX=new float [num_col];
	float * MN=new float [num_col];
	for (long c=0;c<num_col;c++){
		MX[c]=this->get(0,c);
		MN[c]=this->get(0,c);
		for (long r=1;r<num_row;r++){
			if (MX[c] < this->get(r,c))
				MX[c]= this->get(r,c);
			if (MN[c] > this->get(r,c))
				MN[c]= this->get(r,c);
		}
	}


	
	long NoisedExample = R * num_row;
	long * Example=new long [NoisedExample];
	Random^ rnd1 = gcnew Random(5000);
	for (long n=0;n<NoisedExample;n++)
		Example[n]=rnd1->Next(0,num_row);
	for (long c=0;c<num_col;c++)
		for (long h=0;h<NoisedExample;h++)
		 this->set(Example[h],c,rnd1->Next(MN[c],MX[c]));


	delete []MX;
	MX=0;
	delete []MN;
	MN=0;
	delete []Example;
	return;
}
Mat::~Mat(){
	//destruction
	//if (this->Row()>0){
	if (val) {
		delete[] val;
		val = 0;
	}
		if (classint) {
			delete [] classint;
			classint=0;
		}
		if (weights) {
			delete [] weights; 
			weights=0;
		}
		if (Max){
			delete [] Max; 
			Max=0;
		}
		if (Min){
			delete [] Min; 
			Min=0;
		}
		if (Norms) {
			delete [] Norms; 
			Norms=0;
		}
		if (ShiftedNorms) {
			delete[] ShiftedNorms;
			ShiftedNorms = 0;
		}

		if (NumRowPerClass){
			delete [] NumRowPerClass; 
			NumRowPerClass=0;
		}

		
		//Mat=classint;
	/*	for (int i=0;i<num_row;i++)
			delete classes[i];
		delete classes;*/
}

void Mat::UpdateNorms(){
//update ED norms
	for (long r=0;r<num_row;r++){
		float sum=0.0;
		for (long c=0;c<num_col;c++){
			float newval=this->get(r,c);
			sum=sum+(newval*newval);
		}
		sum=Math::Sqrt(sum);
		Norms[r]=sum;
	}
}
//update specific norm
void Mat::UpdateNorms(int normType){
	switch (normType){
		case 2: //manhattan
			for (long r=0;r<num_row;r++){
				float sum=0.0;
				for (long c=0;c<num_col;c++){
					float newval=this->get(r,c);
					sum=sum+Math::Abs(newval);
				}
				Norms[r]=sum;
			}
			break;
		case 4: //Hassanat
			for (long r=0;r<num_row;r++){
				float sum=0.0;
				float z=0.0;
				for (long c=0;c<num_col;c++){
					float v=this->get(r,c);
					(Math::Min(z,v)<0) ? 
					sum+= 1.0 -
					(1+ Math::Min(z,v)+ Math::Abs(Math::Min(z,v)))/
					(1+ Math::Max(z,v)+ Math::Abs(Math::Min(z,v)))
	 				: 
					sum+= 1.0 -(1+ Math::Min(z,v))/(1+ Math::Max(z,v));
				}
				Norms[r]=sum;
			}
			break;
		case 8: //ADR norm
			for (long r=0;r<num_row;r++){
				float sum=0.0;
				for (long c=0;c<num_col;c++){
					float newval=this->get(r,c);
					sum=sum+ Math::Abs(newval)/(1+Math::Abs(newval));
				}
				Norms[r]=sum;
			}
			break;

		default:
			UpdateNorms();//eucleadian norm

	}
}
void Mat::UpdateShiftedNorms(){
//update shifted ED norms
//	if (!ShiftedNorms)
//		ShiftedNorms=new float[num_row];
	for (long r=0;r<num_row;r++){
		float sum=0.0;
		for (long c=0;c<num_col;c++){
			float newval=this->get(r,c);
			newval=newval-Min[c];
			sum=sum+(newval*newval);
		}
		sum=Math::Sqrt(sum);
		ShiftedNorms[r]=sum;
	}
}

//return eucledian distance between 2 fv
float ED(float *fv1, float *fv2, long col){
	float D=0.0;
	for (long c=0;c<col;c++)
		D += Math::Pow(fv1[c]-fv2[c],2.0);
	return Math::Sqrt(D);
}
//return eucledian norm of a fv
float ENorm(float *fv, long col){
	float D=0.0;
	for (long c=0;c<col;c++)
		D+=fv[c]*fv[c];
	return Math::Sqrt(D);
}

//return Manhattan distance between 2 fvs
float Manh(float *fv1, float *fv2, long col){
	float D=0.0;
	for (long c=0;c<col;c++)
		D += Math::Abs(fv1[c]-fv2[c]);
	return D;
}



//new distnce based on absoult dif/eps+dif
float ADR(float * fv1,float *fv2, long col){
	float D=0.0;
	for (long c=0;c<col;c++){
		float adr=Math::Abs(fv1[c]-fv2[c]);
		D += adr/(2.0+adr);
	}
	return D;
}
inline float Hassanat(float *fv1, float *fv2, long col){
  float D=0.0;
  for (long c=0;c<col;c++){
	(Math::Min(fv1[c],fv2[c])<0) ? 
	 D+= 1.0 -
	 (1+ Math::Min(fv1[c],fv2[c])+ Math::Abs(Math::Min(fv1[c],fv2[c])))/
	 (1+ Math::Max(fv1[c],fv2[c])+ Math::Abs(Math::Min(fv1[c],fv2[c])))
	 	 : D+= 1.0 -(1+ Math::Min(fv1[c],fv2[c]))/
					 (1+ Math::Max(fv1[c],fv2[c]));
				}
  return D;

}
//return Enhanced Hassanat with Exp distance between 2 fvs {1-1/exp(abs(Ai-Bi)}
float ExpDistance(float *fv1, float *fv2, long col) {
	float D = 0.0;
	for (long c = 0;c < col;c++)
		D += 1- 1/Math::Exp(Math::Abs(fv1[c] - fv2[c]));
	return D;
}
//any distance based on d type 
float Distance(float *fv1, float *fv2, long col, int Dtype){
		float D=0;
	switch (Dtype){
		case 2: //manhattan
			D=Manh(fv1,fv2,col);
			break;
		case 4: //Hassanat
			D=Hassanat(fv1,fv2,col);
			break;
		case 8: //ADR
			D=ADR(fv1,fv2,col);
			break;
		case 9: //exp
			D = ExpDistance(fv1, fv2, col);
			break;

		default: //ED
			D=ED(fv1,fv2,col);
			break;
	}
	
	return D;
}
//return weighted eucledian distance between 2 fv
float WED(float *fv1, float *fv2, float *wts, long col){
	float D=0.0;
	for (long c=0;c<col;c++)
		D += Math::Pow(fv1[c]-fv2[c],2.0)/wts[c];
	return Math::Sqrt(D);
}
// A Brute Force method to return max distance and indexes of the farthest  two points
float bruteForceFar(Mat *P, long *ip1, long *ip2)
{
	long row=P->Row(), col=P->Col();
    float max = 0;
    for (long i = 0; i < row; i++)
		for (long j = i+1; j < row; j++){
			float *fv1=P->getRow(i),  *fv2=P->getRow(j);
			float D=ED(fv1,fv2,col);
			if (D > max){
                max = D;
				*ip1=i; *ip2=j;
			}
			delete []fv1; delete []fv2;
		}
    return max;
}
// A Brute Force method to return max distance and indexes of the farthest  two points
//give array of indexs of F
float bruteForceFar(Mat *P, long *FVindexs, long FVnum, long *ip1, long *ip2, long *iterations)
{
	*iterations=0;
	long row=FVnum, col=P->Col();
    float max = 0;
    for (long i = 0; i < row; i++)
		for (long j = i+1; j < row; j++){
			float *fv1=P->getRow(FVindexs[i]);
			float *fv2=P->getRow(FVindexs[j]);
			float D=ED(fv1,fv2,col);
			if (D > max){
                max = D;
				*ip1=FVindexs[i]; *ip2=FVindexs[j];
			}
			delete []fv1; delete []fv2;
			*iterations+=1;
		}
    return max;
}
// Fast O(n) method to return max distance and indexes of the farthest  two points
//give array of indexs of F
float FastFar1(Mat *P, long *FVindexs, long FVnum, long *ip1, long *ip2, long *iterations)//O(n)
{//this method is based on finding the two virtual min and max vectors of data set , then 
	//compare all fvs with these 2 extreme points to find the nearest for each 
	//then the distance is claculated  between those 2 points, and their index is returned  
	long row=FVnum, col=P->Col();
	*iterations=0;
	float *fv=P->getRow(FVindexs[0]);
	float minmin = ED(fv,P->Min,col);
	float minmax = ED(fv,P->Max,col);
	delete [] fv;
	long indexofMinNN=FVindexs[0];
	long indexofMaxNN=FVindexs[0];
	for (long i = 1; i < row; i++){
			fv=P->getRow(FVindexs[i]);
			float D=ED(fv,P->Min,col);
			if (D < minmin){
                minmin = D;
				indexofMinNN=FVindexs[i];
			}
			D=ED(fv,P->Max,col);
			if (D < minmax){
                minmax = D;
				indexofMaxNN=FVindexs[i];
			}

			delete []fv;
		}
	*iterations+=1;
		*ip1=indexofMinNN; *ip2=indexofMaxNN;
			float *fv1=P->getRow(indexofMinNN);
			float *fv2=P->getRow(indexofMaxNN);
			float maxdistance=ED(fv1,fv2,col);
			delete []fv1; delete []fv2;
    return maxdistance;
}
float FastFar2(Mat *P, long *FVindexs, long FVnum, long *ip1, long *ip2, long *iterations)//O(n)
{//v2  this method is based on finding the two virtual min and max vectors of data set , then 
	//compare all fvs with these 2 extreme points to find the nearest for each 
	//then the distance is claculated  between those 2 points, and their index is returned  
	//difer from 1 by dividing max / min aand min /max to forster nearest and farthest conceept at both ends
	long row=FVnum, col=P->Col();
	*iterations=0;
	float *fv=P->getRow(FVindexs[0]);
	float D1=ED(fv,P->Min,col);
	float D2=ED(fv,P->Max,col);
	float D;
	float minmin = D1/D2;
	float minmax = D2/D1;
	delete [] fv;
	long indexofMinNN=FVindexs[0];
	long indexofMaxNN=FVindexs[0];
	for (long i = 1; i < row; i++){
			fv=P->getRow(FVindexs[i]);
			D1=ED(fv,P->Min,col);
			D2=ED(fv,P->Max,col);
			D=D1/D2;
			delete []fv;
			if ( D < minmin){
                minmin = D;
				indexofMinNN=FVindexs[i];
			}
			D=D2/D1;
			if (D < minmax){
                minmax = D;
				indexofMaxNN=FVindexs[i];
			}

			
		}
	*iterations+=1;
		*ip1=indexofMinNN; *ip2=indexofMaxNN;
			float *fv1=P->getRow(indexofMinNN);
			float *fv2=P->getRow(indexofMaxNN);
			float maxdistance=ED(fv1,fv2,col);
			delete []fv1; delete []fv2;
    return maxdistance;
}
float FastFar3(Mat *P, long *FVindexs, long FVnum, long *ip1, long *ip2, long *iterations)//O(2nlog(n))
{//v3  this method is based on finding the two virtual min and max vectors of data set , then 
	//compare all fvs with these 2 extreme points to find the nearest for each 
	//then the distance is claculated  between those 2 points, and their index is returned  
	long row=FVnum, col=P->Col();
	*iterations=0;
	ArrayList ^ ExtreemePoints=gcnew ArrayList();
	float * Dminmin=new float [row];
	float * Dminmax=new float [row];
		for (long i = 0; i < row; i++){
			float *fv=P->getRow(FVindexs[i]);
			float D1=ED(fv,P->Min,col);
			float D2=ED(fv,P->Max,col);
			Dminmin[i]=D1/D2;
			Dminmax[i]=D2/D1;
			delete []fv;
		}
		*iterations+=1;
		int k=Math::Log(row,2);
	while(k){
		float min=Dminmin[0];
		long index=0;
		for (long i=1;i<row;i++)
			if (Dminmin[i]<min){
				min=Dminmin[i];
				index=i;
			}
		Dminmin[index]=999999999999999999999999.0;
		ExtreemePoints->Add(FVindexs[index]);
		k--;
		}
	k=Math::Log(row,2);
	while(k){
		float min=Dminmax[0];
		long index=0;
		for (long i=1;i<row;i++)
			if (Dminmax[i]<min){
				min=Dminmax[i];
				index=i;
			}
		Dminmax[index]=999999999999999999999999.0;
		ExtreemePoints->Add(FVindexs[index]);
		k--;
		}
//now brute force on number of points
    float max = 0;
    for (long i = 0; i < ExtreemePoints->Count; i++)
		for (long j = i+1; j < ExtreemePoints->Count; j++){
			long index1=safe_cast <long> (ExtreemePoints[i]);
			long index2=safe_cast <long> (ExtreemePoints[j]);
			float *fv1=P->getRow(index1);
			float *fv2=P->getRow(index2);
			float D=ED(fv1,fv2,col);
			if (D > max){
                max = D;
				*ip1=index1; *ip2=index2;
			}
			delete []fv1; delete []fv2;
			*iterations+=1;
		}
    return max;


}
float FastFar4(Mat *P, long *FVindexs, long FVnum, long *ip1, long *ip2, long *iterations)
{//v4  calc distance between points of min and max norms
	float * norm1=new float [P->Row()], *norm2=new float [P->Row()];
	*iterations=0;
	for (long i=0;i<P->Row();i++){
		norm1[i]=norm2[i]=P->Norms[i];
	}
	*iterations+=1;
	long row=FVnum, col=P->Col();
	ArrayList ^ ExtreemePoints=gcnew ArrayList();
	int k=Math::Log(row,2);
	while(k){
		long index=0;
		float min=norm1[FVindexs[index]];
		for (long i=1;i<row;i++)
			if (norm1[FVindexs[i]]<min){
				min=norm1[FVindexs[i]];
				index=i;
			}
		norm1[index]=999999999999999999999999.0;
		ExtreemePoints->Add(FVindexs[index]);
		k--;
		}

	k=Math::Log(row,2);
	while(k){
		long index=0;
		float max=norm2[FVindexs[index]];
		for (long i=1;i<row;i++)
			if (norm2[FVindexs[i]]>max){
				max=norm2[FVindexs[i]];
				index=i;
			}
		norm2[index]=-999999999999999999999999.0;
		ExtreemePoints->Add(FVindexs[index]);
		k--;
		}

delete []norm1; delete [] norm2;
//now brute force on 2logn points
    float max = 0;
    for (long i = 0; i < ExtreemePoints->Count; i++)
		for (long j = i+1; j < ExtreemePoints->Count; j++){
			long index1=safe_cast <long> (ExtreemePoints[i]);
			long index2=safe_cast <long> (ExtreemePoints[j]);
			float *fv1=P->getRow(index1);
			float *fv2=P->getRow(index2);
			float D=ED(fv1,fv2,col);
			if (D > max){
                max = D;
				*ip1=index1; *ip2=index2;
			}
			delete []fv1; delete []fv2;
			*iterations+=1;
		}
    return max;


}
//return weight distance between 2 fv
float weight(float *fv1, float *fv2, long col){
	float W=0.0;
	for (long c=0;c<col;c++)
		W += 1/(1+Math::Abs(fv1[c]-fv2[c]));
	return W;
} 
//count features that > a reference feature vector which is nn to virtual min 
long CountMins(float *fv, float *ref, long col){
	long ctr=0;
	for (long c=0;c<col;c++)
		if (fv[c]<=ref[c])
			ctr++;
	return ctr;
} 
//count features that > a reference feature vector which is nn to virtual max 
long CountMaxs(float *fv, float *ref, long col){
	long ctr=0;
	for (long c=0;c<col;c++)
		if (fv[c]>=ref[c])
			ctr++;
	return ctr;
} 

float FastFar5(Mat *P, long *FVindexs, long FVnum, long *ip1, long *ip2, long *iterations )
{//v5  this method is based on finding the two virtual min and max vectors of data set , then 
	//wieght each vector based on its similarity to both ends using 1/(1+|Ai-Bi|)
	//then take the vectors of the max weights pf both ends and do BF   
	long row=FVnum, col=P->Col();
	*iterations=0; 
	ArrayList ^ ExtreemePoints=gcnew ArrayList();
	float * Dminmin=new float [row];//store weights of simialrities to min vector
	float * Dminmax=new float [row];//store weights of simialrities to max vector
		for (long i = 0; i < row; i++){
			float *fv=P->getRow(FVindexs[i]);
			float W1=weight(fv,P->Min,col);
			float W2=weight(fv,P->Max,col);
			Dminmin[i]=W1;
			Dminmax[i]=W2;
			delete []fv;
		}
		*iterations+=1;
		//now it is maximization problem
		int k=Math::Log(row,2);
	while(k){
		float max=Dminmin[0];
		long index=0;
		for (long i=1;i<row;i++)
			if (Dminmin[i]>max){
				max=Dminmin[i];
				index=i;
			}
			
		Dminmin[index]=-999999999999999999999999.0;
		//Dminmin[index]= -DBL_MAX;
		ExtreemePoints->Add(FVindexs[index]);
		k--;
		}
	k=Math::Log(row,2);
	while(k){
		float max=Dminmax[0];
		long index=0;
		for (long i=1;i<row;i++)
			if (Dminmax[i]>max ){
				max=Dminmax[i];
				index=i;
			}
		Dminmax[index]= -999999999999999999999999.0;
		ExtreemePoints->Add(FVindexs[index]);
		k--;
		}
//now brute force on 2log(n) points \later we need both ends only to comaper not within each ean
    float max = 0;
    for (long i = 0; i < ExtreemePoints->Count; i++)
		for (long j = i+1; j < ExtreemePoints->Count; j++){
			long index1=safe_cast <long> (ExtreemePoints[i]);
			long index2=safe_cast <long> (ExtreemePoints[j]);
			float *fv1=P->getRow(index1);
			float *fv2=P->getRow(index2);
			float D=ED(fv1,fv2,col);
			if (D > max){
                max = D;
				*ip1=index1; *ip2=index2;
			}
			delete []fv1; delete []fv2;
			*iterations+=1;
		}
    return max;


}
float FastFar6(Mat *P, long *FVindexs, long FVnum, long *ip1, long *ip2, long *iterations )
{//v6 Hassanat  this method is based on finding the two virtual min and max vectors of data set , then 
	//wieght each vector based on its similarity to both ends using Hassanat distance
	//then store the vectors of the min Distances of both ends and to do BF on them  
	long row=FVnum, col=P->Col();
	*iterations=0; 
	ArrayList ^ ExtreemePoints=gcnew ArrayList();
	float * Dminmin=new float [row];//store simialrities to min vector
	float * Dminmax=new float [row];//store simialrities to max vector
		for (long i = 0; i < row; i++){
			float *fv=P->getRow(FVindexs[i]);
			float D1=Hassanat(fv,P->Min,col);
			float D2=Hassanat(fv,P->Max,col);
			Dminmin[i]=D1;
			Dminmax[i]=D2;
			delete []fv;
		}
		//now it is minimization problem
		int k=Math::Log(row,2);
	while(k){
		float min=Dminmin[0];
		long index=0;
		for (long i=1;i<row;i++)
			if (Dminmin[i]<min){
				min=Dminmin[i];
				index=i;
			}
			
		Dminmin[index]=999999999999999999999999.0;
		//Dminmin[index]= -DBL_MAX;
		ExtreemePoints->Add(FVindexs[index]);
		k--;
		}
	k=Math::Log(row,2);
	while(k){
		float min=Dminmax[0];
		long index=0;
		for (long i=1;i<row;i++)
			if (Dminmax[i]< min ){
				min=Dminmax[i];
				index=i;
			}
		Dminmax[index]= 999999999999999999999999.0;
		ExtreemePoints->Add(FVindexs[index]);
		k--;
		}
//now brute force on 2log(n) points \later we need both ends only to comaper not within each ean
    float max = 0;
    for (long i = 0; i < ExtreemePoints->Count; i++)
		for (long j = i+1; j < ExtreemePoints->Count; j++){
			long index1=safe_cast <long> (ExtreemePoints[i]);
			long index2=safe_cast <long> (ExtreemePoints[j]);
			float *fv1=P->getRow(index1);
			float *fv2=P->getRow(index2);
			float D=ED(fv1,fv2,col);
			if (D > max){
                max = D;
				*ip1=index1; *ip2=index2;
			}
			delete []fv1; delete []fv2;
			*iterations+=1;
		}
    return max;


}
float FastFar7(Mat *P, long *FVindexs, long FVnum, long *ip1, long *ip2, long *iterations )
{//v7 weight/Hassanat  this method is based on finding the two virtual min and max vectors of data set , then 
	//wieght each vector based on its similarity to both ends using 1/(1+|Ai-Bi|)
	//then take the vectors of the max weights and min Hassanat D of both ends and do BF   
	long row=FVnum, col=P->Col();
	*iterations=0; 
	ArrayList ^ ExtreemePoints=gcnew ArrayList();
	float * Dminmin=new float [row];//store weights of simialrities to min vector
	float * Dminmax=new float [row];//store weights of simialrities to max vector
		for (long i = 0; i < row; i++){
			float *fv=P->getRow(FVindexs[i]);
			float W1=weight(fv,P->Min,col);
			float D1=Hassanat(fv,P->Min,col);
			float W2=weight(fv,P->Max,col);
			float D2=Hassanat(fv,P->Max,col);
			Dminmin[i]=W1/(1+Math::Log(1+D1,2));
			Dminmax[i]=W2/(1+Math::Log(1+D2,2));
			delete []fv;
		}
		*iterations+=1;
		//now it is maximization problem
		int k=Math::Log(row,2);
	while(k){
		float max=Dminmin[0];
		long index=0;
		for (long i=1;i<row;i++)
			if (Dminmin[i]>max){
				max=Dminmin[i];
				index=i;
			}
			
		Dminmin[index]=-999999999999999999999999.0;
		//Dminmin[index]= -DBL_MAX;
		ExtreemePoints->Add(FVindexs[index]);
		k--;
		}
	k=Math::Log(row,2);
	while(k){
		float max=Dminmax[0];
		long index=0;
		for (long i=1;i<row;i++)
			if (Dminmax[i]>max ){
				max=Dminmax[i];
				index=i;
			}
		Dminmax[index]= -999999999999999999999999.0;
		ExtreemePoints->Add(FVindexs[index]);
		k--;
		}
//noe brute force on 2log(n) points \later we need both ends only to comaper not within each ean
    float max = 0;
    for (long i = 0; i < ExtreemePoints->Count; i++)
		for (long j = i+1; j < ExtreemePoints->Count; j++){
			long index1=safe_cast <long> (ExtreemePoints[i]);
			long index2=safe_cast <long> (ExtreemePoints[j]);
			float *fv1=P->getRow(index1);
			float *fv2=P->getRow(index2);
			float D=ED(fv1,fv2,col);
			if (D > max){
                max = D;
				*ip1=index1; *ip2=index2;
			}
			delete []fv1; delete []fv2;
			*iterations+=1;
		}
    return max;
}
float FastFar8(Mat *P, long *FVindexs, long FVnum, long *ip1, long *ip2, long *iterations )
{//Shifted norms  calc distance between points of min and max norm/norms are created after shifting examples 
	//by subtracting min FV from all Fvs
	*iterations=0; 
	float * norm1=new float [P->Row()], *norm2=new float [P->Row()];
	for (long i=0;i<P->Row();i++){
		norm1[i]=norm2[i]=P->ShiftedNorms[i];
	}
	*iterations+=1;
	long row=FVnum, col=P->Col();
	ArrayList ^ ExtreemePoints=gcnew ArrayList();
	int k=Math::Log(row,2);
	while(k){
		long index=0;
		float min=norm1[FVindexs[index]];
		for (long i=1;i<row;i++)
			if (norm1[FVindexs[i]]<min){
				min=norm1[FVindexs[i]];
				index=i;
			}
		norm1[index]=999999999999999999999999.0;
		ExtreemePoints->Add(FVindexs[index]);
		k--;
		
	}


	k=Math::Log(row,2);
	while(k){
		long index=0;
		float max=norm2[FVindexs[index]];
		for (long i=1;i<row;i++)
			if (norm2[FVindexs[i]]>max){
				max=norm2[FVindexs[i]];
				index=i;
			}
		norm2[index]=-999999999999999999999999.0;
		ExtreemePoints->Add(FVindexs[index]);
		k--;
		
	}

delete []norm1; delete [] norm2;
//now brute force on 2logn points
    float max = 0;
    for (long i = 0; i < ExtreemePoints->Count; i++)
		for (long j = i+1; j < ExtreemePoints->Count; j++){
			long index1=safe_cast <long> (ExtreemePoints[i]);
			long index2=safe_cast <long> (ExtreemePoints[j]);
			float *fv1=P->getRow(index1);
			float *fv2=P->getRow(index2);
			float D=ED(fv1,fv2,col);
			if (D > max){
                max = D;
				*ip1=index1; *ip2=index2;
			}
			delete []fv1; delete []fv2;
			*iterations+=1;
		}
    return max;
}
float FastFar9(Mat *P, long *FVindexs, long FVnum, long *ip1, long *ip2, long *iterations )
{// weight/Eudcledian this method is based on finding the two virtual min and max vectors of data set , then 
	//wieght each vector based on its similarity to both ends using 1/(1+|Ai-Bi|)
	//then take the vectors of the max weights and min Eucledian D of both ends and do BF   
	long row=FVnum, col=P->Col();
	*iterations=0; 
	ArrayList ^ ExtreemePoints=gcnew ArrayList();
	float * Dminmin=new float [row];//store weights of simialrities to min vector
	float * Dminmax=new float [row];//store weights of simialrities to max vector
		for (long i = 0; i < row; i++){
			float *fv=P->getRow(FVindexs[i]);
			float W1=weight(fv,P->Min,col);
			float D1=ED(fv,P->Min,col);
			float W2=weight(fv,P->Max,col);
			float D2=ED(fv,P->Max,col);
			Dminmin[i]=W1/(1+Math::Log(1+D1,2));
			Dminmax[i]=W2/(1+Math::Log(1+D2,2));
			delete []fv;
		}
		*iterations+=1;
		//now it is maximization problem
		int k=Math::Log(row,2);
	while(k){
		float max=Dminmin[0];
		long index=0;
		for (long i=1;i<row;i++)
			if (Dminmin[i]>max){
				max=Dminmin[i];
				index=i;
			}
			
		Dminmin[index]=-999999999999999999999999.0;
		//Dminmin[index]= -DBL_MAX;
		ExtreemePoints->Add(FVindexs[index]);
		k--;
		}
	k=Math::Log(row,2);
	while(k){
		float max=Dminmax[0];
		long index=0;
		for (long i=1;i<row;i++)
			if (Dminmax[i]>max ){
				max=Dminmax[i];
				index=i;
			}
		Dminmax[index]= -999999999999999999999999.0;
		ExtreemePoints->Add(FVindexs[index]);
		k--;
		}
//noe brute force on 2log(n) points \later we need both ends only to comaper not within each ean
    float max = 0;
    for (long i = 0; i < ExtreemePoints->Count; i++)
		for (long j = i+1; j < ExtreemePoints->Count; j++){
			long index1=safe_cast <long> (ExtreemePoints[i]);
			long index2=safe_cast <long> (ExtreemePoints[j]);
			float *fv1=P->getRow(index1);
			float *fv2=P->getRow(index2);
			float D=ED(fv1,fv2,col);
			if (D > max){
                max = D;
				*ip1=index1; *ip2=index2;
			}
			delete []fv1; delete []fv2;
			*iterations+=1;
		}
    return max;
}

float FastFar10(Mat *P, long *FVindexs, long FVnum, long *ip1, long *ip2, long *iterations )//hopefuly exact O(nm)
{//min and max zones: this method is based on finding the two virtual min and max vectors of data set , then 
	//compare all fvs with these 2 extreme points to find the nearest for each pmin and pmax
	//then all fvs having a value in any dimension < the value in the same dimension of Pmin are added to the min pool 
	//and all fvs having a value in any dimension > the value in the same dimension of PMax are added to the max pool
	//then bf alg is applied on Pmin and Pmax
	*iterations=0; 
	long row=FVnum, col=P->Col();
	float *fv=P->getRow(FVindexs[0]);
	float minmin = ED(fv,P->Min,col);
	float minmax = ED(fv,P->Max,col);
//	float minmin = Hassanat(fv,P->Min,col);
//	float minmax = Hassanat(fv,P->Max,col);
	delete [] fv;
	long indexofMinNN=FVindexs[0];
	long indexofMaxNN=FVindexs[0];
	for (long i = 1; i < row; i++){
			fv=P->getRow(FVindexs[i]);
			float D=ED(fv,P->Min,col);
	//		float D=Hassanat(fv,P->Min,col);
			if (D < minmin){
                minmin = D;
				indexofMinNN=FVindexs[i];
			}
			D=ED(fv,P->Max,col);
		//	D=Hassanat(fv,P->Max,col);
			if (D < minmax){
                minmax = D;
				indexofMaxNN=FVindexs[i];
			}
			delete []fv;
		}
	*iterations+=1;
//we got indexofMinNN and indexofMaxNN

	ArrayList ^ ExtreemePointsMin=gcnew ArrayList();
	ArrayList ^ ExtreemePointsMax=gcnew ArrayList();
	ExtreemePointsMin->Add(indexofMinNN);
	ExtreemePointsMax->Add(indexofMaxNN);
//	ExtreemePointsUndecided->Add(indexofMaxNN);
//now find thos fv that has a feature < of the same feature of indexofMinNN point
	float *Refmin=P->getRow(indexofMinNN);
	float *Refmax=P->getRow(indexofMaxNN);
	for (long i=0;i<row;i++){
		fv=P->getRow(FVindexs[i]);
		float D1=ED(fv,P->Min,col);
		float D2=ED(fv,P->Max,col);
	//	float D1=Hassanat(fv,P->Min,col);
	//	float D2=Hassanat(fv,P->Max,col);
		long ctrmin=CountMins(fv,Refmin,col);
		long ctrmax=CountMaxs(fv,Refmax,col);
	/*	if (ctrmin>ctrmax)
			ExtreemePointsMin->Add(FVindexs[i]);
		else if (ctrmax>ctrmin) 
			ExtreemePointsMax->Add(FVindexs[i]);
		else {*/
		if (ctrmin>0 && D1<=D2)
			ExtreemePointsMin->Add(FVindexs[i]);
		if (ctrmax>0 && D2<D1)
			ExtreemePointsMax->Add(FVindexs[i]);
		//ÕáÍ åÇáÎÑÇÈíØ
		/*	if (ctrmin>0 || ctrmax>0){
				ExtreemePointsMin->Add(FVindexs[i]);
				ExtreemePointsMax->Add(FVindexs[i]);
			}*/ 
	//	}
		delete []fv;
	}
	delete []Refmin;
	delete []Refmax;
	*iterations+=1;
//now brute force on number of points
    float max = -1;
	for (long i = 0; i < ExtreemePointsMin->Count; i++){
		long index1=safe_cast <long> (ExtreemePointsMin[i]);
		float *fv1=P->getRow(index1);
		for (long j = 0; j < ExtreemePointsMax->Count; j++){	
			long index2=safe_cast <long> (ExtreemePointsMax[j]);
			float *fv2=P->getRow(index2);
			float D=ED(fv1,fv2,col);
			if (D > max){
                max = D;
				*ip1=index1; *ip2=index2;
			}
			delete []fv2;
		}
		delete []fv1;
		*iterations+=1;
	}
    return max;
}
float FastFar11(Mat *P, long *FVindexs, long FVnum, long *ip1, long *ip2, long *iterations )//hopefuly exact O(nm)
{// min and max zones with weight similarity: this method is based on finding the two virtual min and max vectors of data set , then 
	//compare all fvs with these 2 extreme points to find the most similar for each pmin and pmax
	//then all fvs having a value in any dimension < the value in the same dimension of Pmin are added to the min pool 
	//and all fvs having a value in any dimension > the value in the same dimension of PMax are added to the max pool
	//then bf alg is applied on Pmin and Pmax, add to the ifs similarity wetght 
	*iterations=0; 
	long row=FVnum, col=P->Col();
	float *fv=P->getRow(FVindexs[0]);
	float minmin = weight(fv,P->Min,col);
	float minmax = weight(fv,P->Max,col);
	*iterations+=1; *iterations+=1;
//	float minmin = Hassanat(fv,P->Min,col);
//	float minmax = Hassanat(fv,P->Max,col);
	delete [] fv;
	long indexofMinNN=FVindexs[0];
	long indexofMaxNN=FVindexs[0];
	for (long i = 1; i < row; i++){
			fv=P->getRow(FVindexs[i]);
			float w=weight(fv,P->Min,col);
	//		float D=Hassanat(fv,P->Min,col);
			if (w > minmin){
                minmin = w;
				indexofMinNN=FVindexs[i];
			}
			w=weight(fv,P->Max,col);
		//	D=Hassanat(fv,P->Max,col);
			if (w > minmax){
                minmax = w;
				indexofMaxNN=FVindexs[i];
			}
			delete []fv;
		}
	*iterations+=1;
//we got indexofMinNN and indexofMaxNN

	ArrayList ^ ExtreemePointsMin=gcnew ArrayList();
	ArrayList ^ ExtreemePointsMax=gcnew ArrayList();
	ExtreemePointsMin->Add(indexofMinNN);
	ExtreemePointsMax->Add(indexofMaxNN);
//	ExtreemePointsUndecided->Add(indexofMaxNN);
//now find thos fv that has a feature < of the same feature of indexofMinNN point
	float *Refmin=P->getRow(indexofMinNN);
	float *Refmax=P->getRow(indexofMaxNN);
	for (long i=0;i<row;i++){
		fv=P->getRow(FVindexs[i]);
		float w1=weight(fv,P->Min,col);
		float w2=weight(fv,P->Max,col);
		long ctrmin=CountMins(fv,Refmin,col);
		long ctrmax=CountMaxs(fv,Refmax,col);

		if (ctrmin>0 && w1>=w2)
			ExtreemePointsMin->Add(FVindexs[i]);
		if (ctrmax>0 && w2>=w1)
			ExtreemePointsMax->Add(FVindexs[i]);

		delete []fv;
	}
	delete []Refmin;
	delete []Refmax;
	*iterations+=1;

//now brute force on number of points
    float max = -1;
	for (long i = 0; i < ExtreemePointsMin->Count; i++){
		long index1=safe_cast <long> (ExtreemePointsMin[i]);
		float *fv1=P->getRow(index1);
		for (long j = 0; j < ExtreemePointsMax->Count; j++){	
			long index2=safe_cast <long> (ExtreemePointsMax[j]);
			float *fv2=P->getRow(index2);
			float D=ED(fv1,fv2,col);
			if (D > max){
                max = D;
				*ip1=index1; *ip2=index2;
			}
			delete []fv2;
		}
		delete []fv1;
		*iterations+=1;
	}
    return max;
}

//return weights based on difference between 2 fv ideally the extreme min and max fvs
float *Fweight(float *fv1, float *fv2, long col){
	float sum=0.0;
	for (long c=0;c<col;c++)
		sum += Math::Abs(fv1[c]-fv2[c]);
	float *W=new float [col];
	for (long c=0;c<col;c++)
		W[c]= Math::Abs(fv1[c]-fv2[c])/sum;

	return W;
}
//count*weight features that > a reference feature vector which is nn to virtual min 
float CountMinsW(float *fv, float *ref, float *wts, long col){
	float ctr=0.0;
	for (long c=0;c<col;c++)
		if (fv[c]<=ref[c])
			ctr+=wts[c];
	return ctr;
} 
//count features*weights that > a reference feature vector which is nn to virtual max 
float CountMaxsW(float *fv, float *ref, float *wts, long col){
	float ctr=0.0;
	for (long c=0;c<col;c++)
		if (fv[c]>=ref[c])
			ctr+=wts[c];
	return ctr;
}
float FastFar12(Mat *P, long *FVindexs, long FVnum, long *ip1, long *ip2, long *iterations)//hopefuly exact O(nm)
{//min and max zones weighted ED: this method is based on finding the two virtual min and max vectors of data set , then 
	//compare all fvs with these 2 extreme points to find the nearest for each pmin and pmax
	//then all fvs having a value in any dimension < the value in the same dimension of Pmin are added to the min pool 
	//and all fvs having a value in any dimension > the value in the same dimension of PMax are added to the max pool
	//then bf alg is applied on Pmin and Pmax
	*iterations=0;
	long row=FVnum, col=P->Col();
	float *fv=P->getRow(FVindexs[0]);
//	float minmin = ED(fv,P->Min,col);
//	float minmax = ED(fv,P->Max,col);
	float minmin = weight(fv,P->Min,col);
	*iterations+=1;
	float minmax = weight(fv,P->Max,col);
	*iterations+=1;
	delete [] fv;
	long indexofMinNN=FVindexs[0];
	long indexofMaxNN=FVindexs[0];
	for (long i = 1; i < row; i++){
			fv=P->getRow(FVindexs[i]);
	//		float D=ED(fv,P->Min,col);
			float D=weight(fv,P->Min,col);
			if (D > minmin){
                minmin = D;
				indexofMinNN=FVindexs[i];
			}
		//	D=ED(fv,P->Max,col);
			D=weight(fv,P->Max,col);
			if (D > minmax){
                minmax = D;
				indexofMaxNN=FVindexs[i];
			}
			delete []fv;
	}
	*iterations+=1;
//we got indexofMinNN and indexofMaxNN

	ArrayList ^ ExtreemePointsMin=gcnew ArrayList();
	ArrayList ^ ExtreemePointsMax=gcnew ArrayList();
	ExtreemePointsMin->Add(indexofMinNN);
	ExtreemePointsMax->Add(indexofMaxNN);
//	ExtreemePointsUndecided->Add(indexofMaxNN);
//now find thos fv that has a feature < of the same feature of indexofMinNN point
	long ZoneFnum=col/6;
//	if (ZoneFnum>1)
//		ZoneFnum--;
	float *Refmin=P->getRow(indexofMinNN);
	float *Refmax=P->getRow(indexofMaxNN);
	float *FWeights=Fweight(P->Min,P->Max,col);
	for (long i=0;i<row;i++){
		fv=P->getRow(FVindexs[i]);
		float WD1=WED(fv, P->Min, FWeights, col);
		float WD2=WED(fv, P->Max, FWeights, col);
		float D1=ED(fv, P->Min, col);
		float D2=ED(fv, P->Max, col);
		long ctrmin=CountMins(fv,Refmin, col);
		long ctrmax=CountMaxs(fv,Refmax, col);
		
		if (ctrmin>ZoneFnum && (WD1<WD2 || D1<D2))
			ExtreemePointsMin->Add(FVindexs[i]);
		if (ctrmax>ZoneFnum && (WD2<WD1 || D2<D1))
			ExtreemePointsMax->Add(FVindexs[i]);

		delete []fv;
	}
	*iterations+=1;
//Filter ExtreemePoints arrays
//	int n=2*Math::Log(row,2);
/*	int n=200;
	long ctr=0;
	long count=ExtreemePointsMin->Count;
	if (count > n){
	  for (long i=0;i<count;i++){
		long index1=safe_cast <long> (ExtreemePointsMin[i]);
		fv=P->getRow(index1);
		long ctrmin=CountMins(fv,Refmin, col);
			
		if (ctrmin<2 ){
			ExtreemePointsMin[i]=-1;
			ctr++;
		}

		delete []fv;
		if ((count-ctr)<=n)
			break;
	  }
	}

	ctr=0;
	count=ExtreemePointsMax->Count;
	if (count > n){
	  for (long i=0;i<count;i++){
		long index1=safe_cast <long> (ExtreemePointsMax[i]);
		fv=P->getRow(index1);
		long ctrmax=CountMaxs(fv,Refmax, col);
			
		if (ctrmax<2 ){
			ExtreemePointsMax[i]=-1;
			ctr++;
		}

		delete []fv;
		if ((count-ctr)<=n)
			break;
	  }
	}
*/
	delete []Refmin;
	delete []Refmax; 
	delete []FWeights;

//now brute force on number of points
    float max = -1;
	long c1=ExtreemePointsMin->Count;
	long c2=ExtreemePointsMax->Count;
	long c3=row;

	for (long i = 0; i < ExtreemePointsMin->Count; i++){
		long index1=safe_cast <long> (ExtreemePointsMin[i]);
		//if (index1== -1)
		//	continue;

		float *fv1=P->getRow(index1);
		for (long j = 0; j < ExtreemePointsMax->Count; j++){	
			long index2=safe_cast <long> (ExtreemePointsMax[j]);
		//	if (index2== -1)
		//	continue;

			float *fv2=P->getRow(index2);
			float D=ED(fv1,fv2,col);
			if (D > max){
                max = D;
				*ip1=index1; *ip2=index2;
			}
			delete []fv2;
		}
		delete []fv1;
		*iterations+=1;
	}
    return max;
}
float FastFar13(Mat *P, long *FVindexs, long FVnum, long *ip1, long *ip2, int DistanceType)//hopefuly exact O(nm)
{//incremental search, select random point, find the farthest point to it, then take that point and find the furthest, keep iteration until no enhancement
//or hill climbing approach
	//select random point 
	Random ^rnd=gcnew Random();
	long row=FVnum, col=P->Col();
	long RandomRow=rnd->Next(0,row);
	*ip1=FVindexs[RandomRow];
	//*iterations=0; 
//find ip2 the furthest point to the random one ip1
	float *fv1=P->getRow(*ip1);
	float MaxDist=0;
	for (long i = 0; i < row; i++){
			float *fv2=P->getRow(FVindexs[i]);
			float D=Distance(fv1,fv2,col, DistanceType);
			if (D > MaxDist){
                MaxDist = D;
				*ip2=FVindexs[i];
			}
			delete []fv2;
	}
	delete []fv1;
	//*iterations+=1;
//now repeatedly (hill climbing) find if there is any point farther than D(ip1,1p2)
bool cont=true;
while (cont){
	float *fv2=P->getRow(*ip2);
	long ip3=0;
	float MaxDist2=0;
	for (long i = 0; i < row; i++){
			float *fv3=P->getRow(FVindexs[i]);
			float D=Distance(fv2,fv3,col,DistanceType);
			if (D > MaxDist2){
                MaxDist2 = D;
				ip3=FVindexs[i];
			}
			delete []fv3;
	}
	//*iterations+=1;
	if (MaxDist2> MaxDist){
		*ip1=*ip2;
		*ip2=ip3;
		MaxDist=MaxDist2;
	}
	else
		cont=false;

	delete []fv2;
}

    return MaxDist;
}
float FastFar14(Mat *P, long *FVindexs, long FVnum, long *ip1, long *ip2, long *iterations )//hopefuly exact O(nm)
{//incremental search, select random point, find the farthest point to it, then take that point and find the furthest, keep iteration until no enhancement
//hill climbing with but the initial seed to be the one with max dist fromone of the extreeme points
	
	long row=FVnum, col=P->Col();
	*iterations=0; 
//find the max point to the extreme min
	*ip1=FVindexs[0];
	float MaxDist=0;
	for (long i = 1; i < row; i++){
		float *fv=P->getRow(FVindexs[i]);
		float D=ED(fv, P->Min, col);
		if (D > MaxDist){
                MaxDist = D;
				*ip1=FVindexs[i];
			}
		delete []fv;
	}
	*iterations+=1;
	
//find ip2 the furthest point to the furthest point from exterem min (ip1)
	
	float *fv1=P->getRow(*ip1);
	MaxDist=0;
	for (long i = 0; i < row; i++){
			float *fv2=P->getRow(FVindexs[i]);
			float D=ED(fv1,fv2,col);
			if (D > MaxDist){
                MaxDist = D;
				*ip2=FVindexs[i];
			}
			delete []fv2;
	}
	delete []fv1;
	*iterations+=1;
//now repeatedly (hill climbing) find if there is any point farther than D(ip1,1p2)
bool cont=true;
while (cont){
	float *fv2=P->getRow(*ip2);
	long ip3=0;
	float MaxDist2=0;
	for (long i = 0; i < row; i++){
			float *fv3=P->getRow(FVindexs[i]);
			float D=ED(fv2,fv3,col);
			if (D > MaxDist2){
                MaxDist2 = D;
				ip3=FVindexs[i];
			}
			delete []fv3;
	}
	*iterations+=1;
	if (MaxDist2> MaxDist){
		*ip1=*ip2;
		*ip2=ip3;
		MaxDist=MaxDist2;
	}
	else
		cont=false;

	delete []fv2;
}

    return MaxDist;
}
float FastFar15(Mat *P, long *FVindexs, long FVnum, long *ip1, long *ip2, long *iterations)//hopefuly exact O(nm)
{//incremental search, select random point, find the farthest point to it, then take that point and find the furthest, keep iteration until no enhancement
//or Tabiu search hill climbing with memory to store visted and equal distance points.
	//select random point 
	*iterations=0; 
	Random ^rnd=gcnew Random();
	long row=FVnum, col=P->Col();
	long RandomRow=rnd->Next(0,row);
	*ip1=FVindexs[RandomRow];
	
//find ip2 the furthest point to the random one ip1
	float *fv1=P->getRow(*ip1);
	float MaxDist=0;
	long indexi=RandomRow;
	bool *visited=new bool[row];
	for (long i = 0; i < row; i++)
		visited[i]=false;
	*iterations+=1;
	visited[indexi]=true;
	for (long i = 0; i < row; i++){
			float *fv2=P->getRow(FVindexs[i]);
			float D=ED(fv1,fv2,col);
			if (D > MaxDist){
                MaxDist = D;
				*ip2=FVindexs[i];
				indexi=i;
			}
			delete []fv2;
	}
	delete []fv1;
	visited[indexi]=true;
	*iterations+=1;
//now repeatedly (hill climbing) find if there is any point farther than D(ip1,1p2)
bool cont=true;
while (cont){
	float *fv2=P->getRow(*ip2);
	long ip3=0;
	float MaxDist2=0;
	for (long i = 0; i < row; i++){
			float *fv3=P->getRow(FVindexs[i]);
			float D=ED(fv2,fv3,col);
			if (D > MaxDist2){
                MaxDist2 = D;
				ip3=FVindexs[i];
				indexi=i;
			}
			delete []fv3;
	}
	*iterations+=1;
	if (MaxDist2>= MaxDist && !visited[indexi]){
		*ip1=*ip2;
		*ip2=ip3;
		MaxDist=MaxDist2;
		visited[indexi]=true;;
	}
	else
		cont=false;

	delete []fv2;
}
	delete []visited;
    return MaxDist;
}
float FastFar16(Mat *P, long *FVindexs, long FVnum, long *ip1, long *ip2, long *iterations)//hopefuly exact O(nm)
{//incremental search, select random point, find the farthest point to it, then take that point and find the furthest, keep iteration until no enhancement
//or Tabu search hill climbing with memory tos tore visted and equal distance points with queue.
//	we need a queue of equal points so we push the 1st furthest point to Q then pop inside wile loop 
	//if we find further point we swap as usual and add it to the Q 
	//if we found same distance we add to Q, 
	//we pop from QL and carry on if >= is added to Q and we keep track of the points 

	//select random point 
	*iterations=0;
	Random ^rnd=gcnew Random();
	long row=FVnum, col=P->Col();
	long RandomRow=rnd->Next(0,row);
	*ip1=FVindexs[RandomRow];
	bool *visited=new bool[row];
	for (long i = 0; i < row; i++)
		visited[i]=false;
	visited[RandomRow]=true;
	*iterations+=1;
//find ip2 the furthest point to the random one ip1
	float *fv1=P->getRow(*ip1);
	float MaxDist=0;
	long indexi=RandomRow;
	//calc all distances from ip1
	float *distances= new float[row];
	for (long i = 0; i < row; i++){
			float *fv2=P->getRow(FVindexs[i]);
			distances[i]=ED(fv1,fv2,col);
			if (distances[i]>MaxDist){
				MaxDist=distances[i];
				indexi=i;
			}
			delete []fv2;
	}
	*iterations+=1;
	*ip2=FVindexs[indexi];
	QL= new queueLong();
	QL->push(indexi);
	
	distances[indexi]=0;
	//add all equal distances pairs to the Q
	for (long i = 0; i < row; i++){
		if (distances[i] == MaxDist){
			//*ip2=FVindexs[i];
			QL->push(i);
		}
	}
	*iterations+=1;
	delete []distances;


//now repeatedly (tabu ) find if there is any point farther than points in the Q D(ip1,1p2)
	//change the qu to save pair of points++++++++++++++
	//QL->push(*ip2);

while (!QL->empty()){
//	QnodeLong *TempPair=QL->pop();
	//*ip1=TempPair->ip1;
//	long ip3=TempPair->ip2;
	long ip3=QL->pop();
	if (visited[ip3])
		continue;
	visited[ip3]=true;
//	delete TempPair;
	float *fv2=P->getRow(FVindexs[ip3]);
	float *distances= new float[row];
	indexi=-1;
	for (long i = 0; i < row; i++){
			if (visited[i])
				continue;
			float *fv3=P->getRow(FVindexs[i]);
			distances[i]=ED(fv2,fv3,col);
			if (distances[i] > MaxDist){
                MaxDist = distances[i];
				indexi=i;
			}
			delete []fv3;
	}
	*iterations+=1;
	if (indexi!= -1){
		*ip1=FVindexs[ip3];
		*ip2=FVindexs[indexi];
		QL->push(indexi);
		distances[indexi]=0;
		for (long i = 0; i < row; i++){
			if (visited[i])
				continue;

			if (distances[i] == MaxDist){
				ip3=FVindexs[i];
				QL->push(i);
			}
		}
		*iterations+=1;
	}
	delete []distances;
	
}//if empty
	delete []visited;
	delete QL;
    return MaxDist;
}
float FastFar17(Mat *P, long *FVindexs, long FVnum, long *ip1, long *ip2, long *iterations)//hopefuly exact O(nm)
{//incremental search, select 5 random points, find the farthest point to it, then take that point and find the furthest, keep iteration until no enhancement
//or Tabu search hill climbing with memory to store visted and equal distance points with queue.
//	we need a queue of equal points so we push the 1st furthest point to Q then pop inside wile loop 
	//if we find further point we swap as usual and add it to the Q 
	//we pop from QL and carry on if > is added to Q and we keep track of the points 

	//select random point 
	*iterations=0;
	Random ^rnd=gcnew Random();
	long row=FVnum, col=P->Col();
	long RandomRow; float MaxDist=0;
	bool *visited=new bool[row];
	for (long i = 0; i < row; i++)
		visited[i]=false;
	*iterations+=1;
	QL= new queueLong();
	int const beamsize=20;
	long indexi;
//find ip2 the furthest point to the random one ip1
for (int j=0;j<beamsize;j++){
	RandomRow=rnd->Next(0,row);
	visited[RandomRow]=true;
	*ip1=FVindexs[RandomRow];
	float *fv1=P->getRow(*ip1);
	MaxDist=0;
	indexi=RandomRow;
	//calc all distances from ip1
	for (long i = 0; i < row; i++){
			float *fv2=P->getRow(FVindexs[i]);
			float D=ED(fv1,fv2,col);
			if (D>MaxDist){
				MaxDist=D;
				indexi=i;
			}
			delete []fv2;
	}
	*ip2=FVindexs[indexi];
	QL->push(indexi);
	*iterations+=1;
}


//now repeatedly (tabu+beam ) find if there is any point farther than points in the Q D(ip1,1p2)
	//change the qu to save pair of points++++++++++++++
	//QL->push(*ip2);

while (!QL->empty()){

	long ip3=QL->pop();
	if (visited[ip3])
		continue;
	visited[ip3]=true;
	float *fv2=P->getRow(FVindexs[ip3]);
	indexi=-1;
	for (long i = 0; i < row; i++){
			if (visited[i])
				continue;
			float *fv3=P->getRow(FVindexs[i]);
			float D=ED(fv2,fv3,col);
			if (D > MaxDist){
                MaxDist = D;
				indexi=i;
			}
			delete []fv3;
	}
	if (indexi!= -1){
		*ip1=FVindexs[ip3];
		*ip2=FVindexs[indexi];
		QL->push(indexi);
	}
	*iterations+=1;
}//if empty
	delete []visited;
	delete QL;
    return MaxDist;
}

float FastFar18(Mat *P, long *FVindexs, long FVnum, long *ip1, long *ip2, long *iterations)//hopefuly exact O(nm)
{//incremental search, select random point, find the farthest point to it, then take that point and find the furthest, keep iteration until no enhancement
//or Tabu search hill climbing with memory tos tore visted and equal distance points with queue.
//	we need a queue of equal points so we push the 1st furthest point to Q then pop inside wile loop 
	//if we find further point we swap as usual and add it to the Q 
	//if we found same distance we add to Q, 
	//we pop from QL and carry on if >= is added to Q and we keep track of the points 

	//select random point 
	*iterations=0;
	Random ^rnd=gcnew Random();
	long row=FVnum, col=P->Col();
	long RandomRow=rnd->Next(0,row);
	*ip1=FVindexs[RandomRow];
	bool *visited=new bool[row];
	for (long i = 0; i < row; i++)
		visited[i]=false;
	visited[RandomRow]=true;
	*iterations+=1;
//find ip2 the furthest point to the random one ip1
	float *fv1=P->getRow(*ip1);
	float MaxDist=0;
	long indexi=RandomRow;
	//calc all distances from ip1
	float *distances= new float[row];
	for (long i = 0; i < row; i++){
			float *fv2=P->getRow(FVindexs[i]);
			distances[i]=ED(fv1,fv2,col);
			if (distances[i]>MaxDist){
				MaxDist=distances[i];
				indexi=i;
			}
			delete []fv2;
	}

	*iterations+=1;
	*ip2=FVindexs[indexi];
	QL= new queueLong();
	QL->push(indexi);
	distances[indexi]=0;
	//add all equal distances pairs to the Q
	for (long i = 0; i < row; i++){
		if (distances[i] == MaxDist){
			//*ip2=FVindexs[i];
			QL->push(i);
		}
	}
	//*iterations+=1;
	delete []distances;


//now repeatedly (tabu ) find if there is any point farther than points in the Q D(ip1,1p2)
	//change the qu to save pair of points++++++++++++++
	//QL->push(*ip2);

while (!QL->empty()){
//	QnodeLong *TempPair=QL->pop();
	//*ip1=TempPair->ip1;
//	long ip3=TempPair->ip2;
	long ip3=QL->pop();
	if (visited[ip3])
		continue;
	visited[ip3]=true;
//	delete TempPair;
	float *fv2=P->getRow(FVindexs[ip3]);
	float *distances= new float[row];
	indexi=-1;
	for (long i = 0; i < row; i++){
			if (visited[i])
				continue;
			float *fv3=P->getRow(FVindexs[i]);
			distances[i]=ED(fv2,fv3,col);
			if (distances[i] > MaxDist){
                MaxDist = distances[i];
				indexi=i;
			}
			delete []fv3;
	}
	*iterations+=1;
	if (indexi!= -1){
		*ip1=FVindexs[ip3];
		*ip2=FVindexs[indexi];
		QL->push(indexi);
		distances[indexi]=0;
		for (long i = 0; i < row; i++){
			if (visited[i])
				continue;

			if (distances[i] == MaxDist){
				ip3=FVindexs[i];
				QL->push(i);
			}
		}
		*iterations+=1;
	}
	delete []distances;
	
}//if empty
	delete []visited;
	delete QL;
    return MaxDist;
}
//=================== End Farhest points 

float *Range;



//===================
static Mat *TrainMat;
static Mat *TestMat;
static long col;
static long row;

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////Tree 1 ///////////////////////////////

//====================binary tree



class Tree
      {
      public:
			Tree(float *Norms, long n); //constructor set initial of tree
			Tree(Mat *Trainmat, long cls, long m); //2nd constructor set initial of tree for a given class cls only
			~Tree(){
				Clear(Root);
				delete []Norms;
			}
			void Clear(BTreeNode*);
			void BuildTree(BTreeNode *);
			BTreeNode *GetNode(BTreeNode *, float);
			BTreeNode *GetNode(BTreeNode *, float, long);
			BTreeNode *GetExamples(float norm){
			
				return GetNode(Root, norm);
			}
			BTreeNode *GetExamples(float norm, long numex){
			
				return GetNode(Root, norm, numex);
			}
			long depth(BTreeNode *p);
			void displayTreeUpDown(BTreeNode * ,int ,int ,int );
			void display();
			void TraversBreadth();
			void updatestats(BTreeNode *);
	  private:
			BTreeNode * Root;
			float *Norms;
public: //tree statistics
	long NumberofNodes;
	long sumsizeofAllnodes; //the total of examples in all nodes, we need this for space complecity
	long NumberofLeaves;
	long sumsizeofLeaves; //the total of examples in all leaves, should be equal to training set size
	long maxsizeofLeaf; //the max number of example in a leaf
	long minsizeofLeaf; //the max number of example in a leaf normaly 1
	float AvrgsizeofLeaves; //the average of examples in all leaves
	long maxDepth;//tree depth
	

        };
Tree::Tree(float *Norms1, long n){
	//create the tree here
	Root= new BTreeNode;
	Root->size=n;
	Root->ExamplesIndx=new long[n];
	Norms= new float [n];
	for (long i=0;i<n;i++){
		Norms[i]=Norms1[i];
		Root->ExamplesIndx[i]=i;
	}
	Root->MaxNorm=MaxofArr(Norms1,n);
	Root->MinNorm=minofArr(Norms1,n);
	Root->left=NULL;
	Root->right=NULL;
	Root->level=1;

//initialize tree stats
	NumberofNodes=0;
	sumsizeofAllnodes=0;
	NumberofLeaves=0;
	sumsizeofLeaves=0; 
	maxsizeofLeaf=0; 
	minsizeofLeaf=LONG_MAX; 
	AvrgsizeofLeaves=0; 
	maxDepth=0;

	//caryy on for the rest of the tree 
	BuildTree(Root);
	updatestats(Root);
	AvrgsizeofLeaves=(float) sumsizeofLeaves/ (float)NumberofLeaves;
}
//2nd constructor set initial of tree for a given class cls only 
Tree::Tree (Mat *Trainmat, long cls, long m){
//clas the class that we want to creat its tree 
//m is the number of examples of that class 
	//create the tree here
	Root= new BTreeNode;
	Root->size=m;
	Root->ExamplesIndx=new long[m];
	long rows=Trainmat->Row();
	Norms= new float [rows];
	long indxm=0;
	for (long i=0;i<rows;i++){
		Norms[i]=Trainmat->Norms[i];
		if (Trainmat->classint[i]==cls){
			Root->ExamplesIndx[indxm]=i;
			indxm++;
		}
	}
	Root->MaxNorm=MaxofArr(Norms,m);
	Root->MinNorm=minofArr(Norms,m);
	Root->left=NULL;
	Root->right=NULL;
	Root->level=1;

//initialize tree stats
	NumberofNodes=0;
	sumsizeofAllnodes=0;
	NumberofLeaves=0;
	sumsizeofLeaves=0; 
	maxsizeofLeaf=0; 
	minsizeofLeaf=LONG_MAX; 
	AvrgsizeofLeaves=0; 
	maxDepth=0;

	//caryy on for the rest of the tree 
	BuildTree(Root);
	updatestats(Root);
	AvrgsizeofLeaves=(float) sumsizeofLeaves/ (float)NumberofLeaves;
}
void Tree::BuildTree(BTreeNode *node){
	Application::DoEvents();
	ArrayList ^LeftArr=gcnew ArrayList;
	ArrayList ^RigtArr=gcnew ArrayList;
	for (long i=0;i<node->size;i++){
		float scale=(Norms[node->ExamplesIndx[i]]-node->MinNorm)/
			         (node->MaxNorm - node->MinNorm);
		scale=Math::Round(scale);
		if (scale==0)
			LeftArr->Add(node->ExamplesIndx[i]);
		else
			RigtArr->Add(node->ExamplesIndx[i]);

	}
	if (LeftArr->Count ==0 || RigtArr->Count ==0)
		return;
//work for left child
	node->left=new BTreeNode;
	node->left->size =LeftArr->Count;
	node->left->ExamplesIndx=new long[node->left->size];
	for (long i=0;i<node->left->size;i++)
		node->left->ExamplesIndx[i]=safe_cast <long> (LeftArr[i]);

	float * newnorms=new float [node->left->size];
	for (long i=0;i<node->left->size;i++)
		newnorms[i]=Norms[node->left->ExamplesIndx[i]];

	node->left->MaxNorm=MaxofArr(newnorms,node->left->size);
	node->left->MinNorm=minofArr(newnorms,node->left->size);
	node->left->left=NULL;
	node->left->right=NULL;
	node->left->level=node->level+1;
	delete []newnorms; newnorms=NULL;

//work for right child
	node->right=new BTreeNode;
	node->right->size =RigtArr->Count;
	node->right->ExamplesIndx=new long[node->right->size];
	for (long i=0;i<node->right->size;i++)
		node->right->ExamplesIndx[i]=safe_cast <long> (RigtArr[i]);

	newnorms=new float [node->right->size];
	for (long i=0;i<node->right->size;i++)
		newnorms[i]=Norms[node->right->ExamplesIndx[i]];

	node->right->MaxNorm=MaxofArr(newnorms,node->right->size);
	node->right->MinNorm=minofArr(newnorms,node->right->size);
	node->right->left=NULL;
	node->right->right=NULL;
	node->right->level=node->level+1;
	delete []newnorms; newnorms=NULL;

	BuildTree(node->left);
	BuildTree(node->right);
}
BTreeNode * Tree::GetNode(BTreeNode *node, float Norm){

		float scale=(Norm - node->MinNorm)/
			         (node->MaxNorm - node->MinNorm);
		scale=Math::Round(scale);
		if (scale==0 && node->left)
			return GetNode(node->left, Norm);
		else if (scale==1 && node->right)
			return GetNode(node->right, Norm);
		else
			return node;

}
BTreeNode * Tree::GetNode(BTreeNode *node, float Norm, long numex){ 
	//return node of at least numex examples
		BTreeNode *tempNode=node;
		float scale=(Norm - node->MinNorm)/
			         (node->MaxNorm - node->MinNorm);
		scale=Math::Round(scale);
		if (node->size <= numex)
			return node;

		if (scale==0 && node->left)
			return GetNode(node->left, Norm, numex);
		else if (scale==1 && node->right)
			return GetNode(node->right,Norm, numex);
		else
			return node;

}
void Tree::Clear(BTreeNode * n)
{
    if (n->left != NULL)
        Clear(n->left );
    if (n->right != NULL)
        Clear(n->right );
	delete [] n->ExamplesIndx; n->ExamplesIndx= NULL;
    delete n;
    n = NULL;
}
//////////// this is to print the tree
long Tree::depth(BTreeNode *p){
    if(p==NULL) return 0;
    long l=depth(p->left);
    long r=depth(p->right);
    if(l>=r)
        return l+1;
    else
        return r+1;
}

void gotoxy(int x,int y)
{
	FILE *outfile;
	outfile= fopen("DrawTree.txt", "a");
	fprintf(outfile,"[%d;%d]",y,x);
//	fprintf(outfile,"%c[%d;%df",0x1B,y,x);
	 fclose (outfile);
}
void coutRoot(BTreeNode * root, bool endline)
{
	FILE *outfile;
	outfile= fopen("DrawTree.txt", "a");
	if (endline)
		fprintf(outfile,"\n");
	fprintf(outfile,"[%d",root->size);
	if (!(root->left==NULL && root->right==NULL)){
			fprintf(outfile,"(%d,",(long) root->MinNorm);
			fprintf(outfile,"%d)",(long)root->MaxNorm);
	}
	if (root->left==NULL && root->right==NULL){
		long i;
		fprintf(outfile,"(");
		for (i=0;i<root->size-1;i++){
			fprintf(outfile,"%d,", root->ExamplesIndx[i]);
		}
		fprintf(outfile,"%d)", root->ExamplesIndx[i]);//to ;
		fprintf(outfile,"-Leaf");
	}
	fprintf(outfile,"] ",root->size);
	fclose (outfile);
}
void coutRoot(DTreeNode * root, bool endline,int numclasses)
{
	FILE *outfile;
	outfile= fopen("DrawDTree.txt", "a");
	if (endline)
		fprintf(outfile,"\n");
	fprintf(outfile,"[%d",root->size);
	if (!(root->left==NULL && root->right==NULL)){
			fprintf(outfile,"(%d,",(long) root->MinNorm);
			fprintf(outfile,"%d)",(long)root->MaxNorm);
	}
	if (root->left==NULL && root->right==NULL){
		long i;
		fprintf(outfile,"(");
		for (i=0;i<root->size-1;i++){
			fprintf(outfile,"%d,",(long) root->ExamplesIndx[i]);
		}
		fprintf(outfile,"%d)",(long) root->ExamplesIndx[i]);//to print the last index without comma,
		fprintf(outfile,"-Leaf");
	}
	fprintf(outfile,"] ",root->size);
//print accumilated class probabilties for each clas
	fprintf(outfile,"{");
	for (int c=0;c<numclasses;c++)
		fprintf(outfile,"%f ", Math::Round(root->Classint[c], 2.0));
	fprintf(outfile,"}");
	fclose (outfile);
}
void Tree::displayTreeUpDown (BTreeNode * root,int x,int y,int px=0){
	if(root==NULL) return;
	gotoxy(x,y);
	int a=abs(px-x)/2;

	//cout<<root->size;
	coutRoot(root, true);
	displayTreeUpDown(root->left ,x-a,y+1,x);
	displayTreeUpDown(root->right,x+a,y+1,x);
}
void Tree::display (){
	displayTreeUpDown(Root,Math::Pow (2,depth(Root)),1,1);
}
void Tree::TraversBreadth (){
	BTreeNode * temp_node=Root;
	if (temp_node==NULL)
		return;
	long CurrentLevel=temp_node->level;
	bool newline=false;
	Q= new queue();
    while (temp_node!=NULL)
    {
        coutRoot(temp_node, newline);//print
 
        /*Enqueue left child */
        if (temp_node->left!= NULL )
            Q->push(temp_node->left);
 
        /*Enqueue right child */
        if (temp_node->right!=NULL)
            Q->push(temp_node->right);
 
        /*Dequeue node and make it temp_node*/
        temp_node = Q->pop();
		if (temp_node!=NULL)
			if (temp_node->level!=CurrentLevel){
				CurrentLevel=temp_node->level;
				newline=true;
			}
			else
				newline=false;
	}
	delete Q;
	return;
}

//update tree stats
void Tree::updatestats(BTreeNode * node){
	if (node==NULL)
		return;
	NumberofNodes++;
	sumsizeofAllnodes+=node->size;
	if (node->level > maxDepth)
		maxDepth=node->level;
	if (node->left==NULL && node->right==NULL){
		NumberofLeaves++;
		sumsizeofLeaves+=node->size; 
		if (node->size > maxsizeofLeaf)
			maxsizeofLeaf=node->size;
		if (node->size < minsizeofLeaf)
			minsizeofLeaf=node->size;  
	}
	updatestats(node->left);
	updatestats(node->right);
}

////========================================   end tree 1   ==================================================================
//=============================Tree2 ==================
//  /\
// /\ /\
//tree2 which is based on segmenting the points in trainmat to a binary tree based on 
//the distances from 2 random points

class Tree2RndPnts
      {
      public:
			Tree2RndPnts(Mat * mat, int DistanceType); //constructor set initial of tree
			~Tree2RndPnts(){
				Clear(Root);
				//delete []Norms;
			}
			void Clear(BTreeNode*);
			void BuildTree(Mat *mat, BTreeNode *, int dtype);
			BTreeNode *GetNode(BTreeNode *, Mat *TrainMat, Mat *TestMat, long TestExampleNdx, int dtype);
			BTreeNode *GetNode(BTreeNode *, Mat *TrainMat, Mat *TestMat, long TestExampleNdx, int dtype, long);
			BTreeNode *GetExamples(Mat *TrainMat, Mat *TestMat, long TestExampleNdx, int dtype){//helper function
			
				return GetNode(Root, TrainMat, TestMat, TestExampleNdx, dtype);
			}
			BTreeNode *GetExamples(Mat *TrainMat, Mat *TestMat, long TestExampleNdx, int dtype, long numex){
			
				return GetNode(Root, TrainMat, TestMat, TestExampleNdx, dtype, numex);
			}
			long depth(BTreeNode *p);
			void displayTreeUpDown(BTreeNode * ,int ,int ,int );
			void display();
			void TraversBreadth();
			void updatestats(BTreeNode *);
	  private:
			BTreeNode * Root;
			//float *Norms;
public: //tree statistics
	long NumberofNodes;
	long sumsizeofAllnodes; //the total of examples in all nodes, we need this for space complecity
	long NumberofLeaves;
	long sumsizeofLeaves; //the total of examples in all leaves, should be equal to training set size
	long maxsizeofLeaf; //the max number of example in a leaf
	long minsizeofLeaf; //the max number of example in a leaf normaly 1
	float AvrgsizeofLeaves; //the average of examples in all leaves
	long maxDepth;//tree depth
	

        };
Tree2RndPnts::Tree2RndPnts(Mat *mat ,int dtype){
	//create the tree here
	Root= new BTreeNode;
	long n=mat->Row();
	Root->size=n;
	Root->ExamplesIndx=new long[n];
	//Norms= new float [n];
	for (long i=0;i<n;i++){
	//	Norms[i]=Norms1[i];
		Root->ExamplesIndx[i]=i;
	}
	//Random ^rnd=gcnew Random();
	long ip1=0;
	long ip2=n-1;
	//this is a new edition just to make sure that the left child got the minimum
	Root->MinNorm=Root->ExamplesIndx[ip1];
	Root->MaxNorm=Root->ExamplesIndx[ip2];
	Root->left=NULL;
	Root->right=NULL;
	Root->level=1;

//initialize tree stats
	NumberofNodes=0;
	sumsizeofAllnodes=0;
	NumberofLeaves=0;
	sumsizeofLeaves=0; 
	maxsizeofLeaf=0; 
	minsizeofLeaf=LONG_MAX; 
	AvrgsizeofLeaves=0; 
	maxDepth=0;

	//caryy on for the rest of the tree 
	BuildTree(mat, Root, dtype);
	updatestats(Root);
	AvrgsizeofLeaves=(float) sumsizeofLeaves/ (float)NumberofLeaves;
}
void Tree2RndPnts::BuildTree(Mat *mat, BTreeNode *node, int Dtype){
	Application::DoEvents();
	ArrayList ^LeftArr=gcnew ArrayList;
	ArrayList ^RigtArr=gcnew ArrayList;
	float *fv1=mat->getRow((long) node->MinNorm);
	float *fv2=mat->getRow((long) node->MaxNorm);
	long col=mat->Col();
	for (long i=0;i<node->size;i++ ){
		float *fv=mat->getRow(node->ExamplesIndx[i]);
		float D1=Distance(fv,fv1,col,Dtype);
		float D2=Distance(fv,fv2,col,Dtype);
		if (D1<D2)
			LeftArr->Add(node->ExamplesIndx[i]);
		else
			RigtArr->Add(node->ExamplesIndx[i]);
		delete fv;
	}
	if (LeftArr->Count ==0 || RigtArr->Count ==0)
		return;
//work for left child
	node->left=new BTreeNode;
	node->left->size =LeftArr->Count;
	node->left->ExamplesIndx=new long[node->left->size];
	for (long i=0;i<node->left->size;i++)
		node->left->ExamplesIndx[i]=safe_cast <long> (LeftArr[i]);

	//float * newnorms=new float [node->left->size];
	//for (long i=0;i<node->left->size;i++)
		//newnorms[i]=Norms[node->left->ExamplesIndx[i]];
	//Random ^rnd=gcnew Random();
	long ip1=0;
	long ip2=node->left->size-1;
	node->left->MinNorm=node->left->ExamplesIndx[ip1];//index of random point 1
	node->left->MaxNorm=node->left->ExamplesIndx[ip2];//index of random point 2

	node->left->left=NULL;
	node->left->right=NULL;
	node->left->level=node->level+1;

//work for right child
	node->right=new BTreeNode;
	node->right->size =RigtArr->Count;
	node->right->ExamplesIndx=new long[node->right->size];
	for (long i=0;i<node->right->size;i++)
		node->right->ExamplesIndx[i]=safe_cast <long> (RigtArr[i]);

	//newnorms=new float [node->right->size];
	//for (long i=0;i<node->right->size;i++)
		//newnorms[i]=Norms[node->right->ExamplesIndx[i]];
	ip1=0;
	ip2=node->right->size-1;
	node->right->MinNorm = node->right->ExamplesIndx[ip1];//index of random point 1
	node->right->MaxNorm = node->right->ExamplesIndx[ip2];//index of random point 2

	node->right->left=NULL;
	node->right->right=NULL;
	node->right->level=node->level+1;
	delete []fv1; fv1=NULL;
	delete []fv2; fv2=NULL;

	BuildTree(mat, node->left , Dtype);
	BuildTree(mat, node->right, Dtype);
}
BTreeNode * Tree2RndPnts::GetNode(BTreeNode *node, Mat *TrainMat, Mat *TestMat, long TestExampleNdx, int dtype){
	long col=TrainMat->Col();
	float *Testfv=TestMat->getRow(TestExampleNdx);
	float *Minfv =TrainMat->getRow((long) node->MinNorm);
	float *Maxfv =TrainMat->getRow((long) node->MaxNorm);
	float D1=Distance(Testfv,Minfv,col,dtype);
	float D2=Distance(Testfv,Maxfv,col,dtype);
		delete []Testfv;
		delete []Minfv;
		delete []Maxfv;

	if (D1<D2 && node->left)
			return GetNode(node->left, TrainMat, TestMat, TestExampleNdx, dtype);
	
		else if (D2<=D1 && node->right)
			return GetNode(node->right,TrainMat, TestMat, TestExampleNdx, dtype);
		else
			return node;

}
BTreeNode * Tree2RndPnts::GetNode(BTreeNode *node, Mat *TrainMat, Mat *TestMat, long TestExampleNdx, int dtype, long numex){ 
	//return node of at least numex examples
		if (node->size <= numex)
			return node;
		
	long col=TrainMat->Col();
	float *Testfv=TestMat->getRow(TestExampleNdx);
	float *Minfv =TrainMat->getRow((long) node->MinNorm);
	float *Maxfv =TrainMat->getRow((long) node->MaxNorm);
	float D1=Distance(Testfv,Minfv,col,dtype);
	float D2=Distance(Testfv,Maxfv,col,dtype);
		delete []Testfv;
		delete []Minfv;
		delete []Maxfv;

		if (D1<D2 && node->left)
			return GetNode(node->left, TrainMat, TestMat, TestExampleNdx, dtype,numex);
		else if (D2<=D1 && node->right)
			return GetNode(node->right,TrainMat, TestMat, TestExampleNdx, dtype,numex);
		else
			return node;
}
void Tree2RndPnts::Clear(BTreeNode * n)
{
    if (n->left != NULL)
        Clear(n->left );
    if (n->right != NULL)
        Clear(n->right );
	delete [] n->ExamplesIndx; n->ExamplesIndx= NULL;
    delete n;
    n = NULL;
}
//////////// this is to print the tree
long Tree2RndPnts::depth(BTreeNode *p){
    if(p==NULL) return 0;
    long l=depth(p->left);
    long r=depth(p->right);
    if(l>=r)
        return l+1;
    else
        return r+1;
}


void Tree2RndPnts::displayTreeUpDown (BTreeNode * root,int x,int y,int px=0){
	if(root==NULL) return;
	gotoxy(x,y);
	int a=abs(px-x)/2;

	//cout<<root->size;
	coutRoot(root, true);
	displayTreeUpDown(root->left ,x-a,y+1,x);
	displayTreeUpDown(root->right,x+a,y+1,x);
}
void Tree2RndPnts::display (){
	displayTreeUpDown(Root,Math::Pow (2,depth(Root)),1,1);
}
void Tree2RndPnts::TraversBreadth (){
	BTreeNode * temp_node=Root;
	if (temp_node==NULL)
		return;
	long CurrentLevel=temp_node->level;
	bool newline=false;
	Q= new queue();
    while (temp_node!=NULL)
    {
        coutRoot(temp_node, newline);//print
 
        /*Enqueue left child */
        if (temp_node->left!= NULL )
            Q->push(temp_node->left);
 
        /*Enqueue right child */
        if (temp_node->right!=NULL)
            Q->push(temp_node->right);
 
        /*Dequeue node and make it temp_node*/
        temp_node = Q->pop();
		if (temp_node!=NULL)
			if (temp_node->level!=CurrentLevel){
				CurrentLevel=temp_node->level;
				newline=true;
			}
			else
				newline=false;
	}
	delete Q;
	return;
}

//update tree stats
void Tree2RndPnts::updatestats(BTreeNode * node){
	if (node==NULL)
		return;
	NumberofNodes++;
	sumsizeofAllnodes+=node->size;
	if (node->level > maxDepth)
		maxDepth=node->level;
	if (node->left==NULL && node->right==NULL){
		NumberofLeaves++;
		sumsizeofLeaves+=node->size; 
		if (node->size > maxsizeofLeaf)
			maxsizeofLeaf=node->size;
		if (node->size < minsizeofLeaf)
			minsizeofLeaf=node->size;  
	}
	updatestats(node->left);
	updatestats(node->right);
}
//=============================end Tree 2 =========================================================================

//=============================Tree4 ==================
//  /\
// /\ /\
//tree4  is based on segmenting the points in train mat to a binary search tree based on 
//their distances from 2 local extrem points p1 and p2, 
//those are the closest points in a node to the 2 extreme global points min and max fvs in mat respictivly 
struct twolongpoints{
	long P1;
	long P2;
};
//function to return the two extreme local points as twolongpoints
twolongpoints LocalExtremPoints(Mat *P, long *FVindexs, long FVnum, int DistanceType){
	twolongpoints temp;
	
//this method is based on finding the two virtual min and max vectors of data set , then 
	//compare all fvs with these 2 extreme points to find the nearest for each 
	long row=FVnum, col=P->Col();

	float * minminArr=new float[row];
	float * minmaxArr=new float[row];
	for (long i = 0; i < row; i++){
			float *fv=P->getRow(FVindexs[i]);
			minminArr[i]=Distance(fv,P->Min,col,DistanceType);
			minmaxArr[i]=Distance(fv,P->Max,col,DistanceType);
			delete []fv;
		}
	
	float minmin = minminArr[0];
	long indexofMinNN=FVindexs[0];
	long ii=0;
	for (long i = 1; i < row; i++){
			if (minminArr[i] < minmin){
                minmin = minminArr[i];
				indexofMinNN=FVindexs[i];
				ii=i;
			}
	}

	minmaxArr[ii]=1.79769e+308;//to prevent douplication if the point was the closest to both global extreme points
	float minmax = minmaxArr[0];
	long indexofMaxNN=FVindexs[0];
	for (long i = 1; i < row; i++){
			if (minmaxArr[i] < minmax){
                minmax = minmaxArr[i];
				indexofMaxNN=FVindexs[i];
			}
		}

	temp.P1=indexofMinNN;  temp.P2=indexofMaxNN;
	delete [] minminArr; 
	delete [] minmaxArr;

	return temp;
}

//function to return the two random examples belonging to the min and the maximum class within a list of points
twolongpoints LocalRandPMinMaxCls(Mat *P, long *FVindexs, long row) {
	twolongpoints temp;

	if (row == 1) {
		temp.P1 = FVindexs[0]; temp.P2 = FVindexs[0];
		return temp;
	}
	temp.P1 = FVindexs[0]; temp.P2 = FVindexs[1];
	long minClass = P->classint[temp.P1];
	long maxClass = P->classint[temp.P2];

	for (long i = 0; i < row; i++) {
		if (P->classint[FVindexs[i]] < minClass) {
			minClass = P->classint[FVindexs[i]];
			temp.P1 = FVindexs[i];
		}
		if (P->classint[FVindexs[i]] > maxClass) {
			maxClass = P->classint[FVindexs[i]];
			temp.P2 = FVindexs[i];
		}

	}


	return temp;
}

class Tree2PclosesttoExtreme
      {
      public:
			Tree2PclosesttoExtreme(Mat * mat, int DistanceType); //constructor set initial of tree
			~Tree2PclosesttoExtreme(){
				Clear(Root);
				//delete []Norms;
			}
			void Clear(BTreeNode*);
			void BuildTree(Mat *mat, BTreeNode *, int dtype);
			BTreeNode *GetNode(BTreeNode *, Mat *TrainMat, Mat *TestMat, long TestExampleNdx, int dtype);
			BTreeNode *GetNode(BTreeNode *, Mat *TrainMat, Mat *TestMat, long TestExampleNdx, int dtype, long);
			BTreeNode *GetExamples(Mat *TrainMat, Mat *TestMat, long TestExampleNdx, int dtype){//helper function
			
				return GetNode(Root, TrainMat, TestMat, TestExampleNdx, dtype);
			}
			BTreeNode *GetExamples(Mat *TrainMat, Mat *TestMat, long TestExampleNdx, int dtype, long numex){
			
				return GetNode(Root, TrainMat, TestMat, TestExampleNdx, dtype, numex);
			}
			long depth(BTreeNode *p);
			void displayTreeUpDown(BTreeNode * ,int ,int ,int );
			void display();
			void TraversBreadth();
			void updatestats(BTreeNode *);
	  private:
			BTreeNode * Root;
			//float *Norms;
public: //tree statistics
	long NumberofNodes;
	long sumsizeofAllnodes; //the total of examples in all nodes, we need this for space complecity
	long NumberofLeaves;
	long sumsizeofLeaves; //the total of examples in all leaves, should be equal to training set size
	long maxsizeofLeaf; //the max number of example in a leaf
	long minsizeofLeaf; //the max number of example in a leaf normaly 1
	float AvrgsizeofLeaves; //the average of examples in all leaves
	long maxDepth;//tree depth
	

        };
Tree2PclosesttoExtreme::Tree2PclosesttoExtreme(Mat *mat ,int dtype){
	//create the tree here
	Root= new BTreeNode;
	long n=mat->Row();
	Root->size=n;
	Root->ExamplesIndx=new long[n];
	//Norms= new float [n];
	for (long i=0;i<n;i++){
	//	Norms[i]=Norms1[i];
		Root->ExamplesIndx[i]=i;
	}
	//find the 2 local extreme points
	twolongpoints localpoints;
	localpoints = LocalExtremPoints(mat,Root->ExamplesIndx,Root->size,dtype);

	Root->MinNorm=localpoints.P1;//this is not min norm it is the point closest to extrem global min from the node points
	Root->MaxNorm=localpoints.P2;//this is not max norm it is the point closest to extrem global max from the node points
	Root->left=NULL;
	Root->right=NULL;
	Root->level=1;

//initialize tree stats
	NumberofNodes=0;
	sumsizeofAllnodes=0;
	NumberofLeaves=0;
	sumsizeofLeaves=0; 
	maxsizeofLeaf=0; 
	minsizeofLeaf=LONG_MAX; 
	AvrgsizeofLeaves=0; 
	maxDepth=0;

	//caryy on for the rest of the tree 
	BuildTree(mat, Root, dtype);
	updatestats(Root);
	AvrgsizeofLeaves=(float) sumsizeofLeaves/ (float)NumberofLeaves;
}
void Tree2PclosesttoExtreme::BuildTree(Mat *mat, BTreeNode *node, int Dtype){
	Application::DoEvents();
	ArrayList ^LeftArr=gcnew ArrayList;
	ArrayList ^RigtArr=gcnew ArrayList;
	float *fv1=mat->getRow((long) node->MinNorm);
	float *fv2=mat->getRow((long) node->MaxNorm);
	long col=mat->Col();
	for (long i=0;i<node->size;i++ ){
		float *fv=mat->getRow(node->ExamplesIndx[i]);
		float D1=Distance(fv,fv1,col,Dtype);
		float D2=Distance(fv,fv2,col,Dtype);
		if (D1<D2)
			LeftArr->Add(node->ExamplesIndx[i]);
		else
			RigtArr->Add(node->ExamplesIndx[i]);
		delete fv;
	}
	if (LeftArr->Count ==0 || RigtArr->Count ==0)
		return;
//work for left child LLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLefTTTTTTTTTTTTTTTTTTT
	node->left=new BTreeNode;
	node->left->size =LeftArr->Count;
	node->left->ExamplesIndx=new long[node->left->size];
	for (long i=0;i<node->left->size;i++)
		node->left->ExamplesIndx[i]=safe_cast <long> (LeftArr[i]);

	//find the 2 local extreme points for left child
	twolongpoints localpoints;
	localpoints = LocalExtremPoints(mat,node->left->ExamplesIndx,node->left->size,Dtype);
	node->left->MinNorm=localpoints.P1;//index of local extrem min 
	node->left->MaxNorm=localpoints.P2;//index of local extrem max

	node->left->left=NULL;
	node->left->right=NULL;
	node->left->level=node->level+1;

//work for right child  RRRRRRRRRRRRRRRRRRighTTTTTTTTTTTTTTTTTTTTTTTT
	node->right=new BTreeNode;
	node->right->size =RigtArr->Count;
	node->right->ExamplesIndx=new long[node->right->size];
	for (long i=0;i<node->right->size;i++)
		node->right->ExamplesIndx[i]=safe_cast <long> (RigtArr[i]);

	//find the 2 local extreme points for right child
	
	localpoints = LocalExtremPoints(mat,node->right->ExamplesIndx,node->right->size,Dtype);
	node->right->MinNorm=localpoints.P1;//index of local extrem min 
	node->right->MaxNorm=localpoints.P2;//index of local extrem max


	node->right->left=NULL;
	node->right->right=NULL;
	node->right->level=node->level+1;
	delete []fv1; fv1=NULL;
	delete []fv2; fv2=NULL;

	BuildTree(mat, node->left , Dtype);
	BuildTree(mat, node->right, Dtype);
}
BTreeNode * Tree2PclosesttoExtreme::GetNode(BTreeNode *node, Mat *TrainMat, Mat *TestMat, long TestExampleNdx, int dtype){
	long col=TrainMat->Col();
	float *Testfv=TestMat->getRow(TestExampleNdx);
	float *Minfv =TrainMat->getRow((long) node->MinNorm);
	float *Maxfv =TrainMat->getRow((long) node->MaxNorm);
	float D1=Distance(Testfv,Minfv,col,dtype);
	float D2=Distance(Testfv,Maxfv,col,dtype);
		delete []Testfv;
		delete []Minfv;
		delete []Maxfv;

	if (D1<D2 && node->left)
			return GetNode(node->left, TrainMat, TestMat, TestExampleNdx, dtype);
	
		else if (D2<=D1 && node->right)
			return GetNode(node->right,TrainMat, TestMat, TestExampleNdx, dtype);
		else
			return node;

}
BTreeNode * Tree2PclosesttoExtreme::GetNode(BTreeNode *node, Mat *TrainMat, Mat *TestMat, long TestExampleNdx, int dtype, long numex){ 
	//return node of at least numex examples
		if (node->size <= numex)
			return node;
		
	long col=TrainMat->Col();
	float *Testfv=TestMat->getRow(TestExampleNdx);
	float *Minfv =TrainMat->getRow((long) node->MinNorm);
	float *Maxfv =TrainMat->getRow((long) node->MaxNorm);
	float D1=Distance(Testfv,Minfv,col,dtype);
	float D2=Distance(Testfv,Maxfv,col,dtype);
		delete []Testfv;
		delete []Minfv;
		delete []Maxfv;

		if (D1<D2 && node->left)
			return GetNode(node->left, TrainMat, TestMat, TestExampleNdx, dtype,numex);
		else if (D2<=D1 && node->right)
			return GetNode(node->right,TrainMat, TestMat, TestExampleNdx, dtype,numex);
		else
			return node;
}
void Tree2PclosesttoExtreme::Clear(BTreeNode * n)
{
    if (n->left != NULL)
        Clear(n->left );
    if (n->right != NULL)
        Clear(n->right );
	delete [] n->ExamplesIndx; n->ExamplesIndx= NULL;
    delete n;
    n = NULL;
}
//////////// this is to print the tree
long Tree2PclosesttoExtreme::depth(BTreeNode *p){
    if(p==NULL) return 0;
    long l=depth(p->left);
    long r=depth(p->right);
    if(l>=r)
        return l+1;
    else
        return r+1;
}


void Tree2PclosesttoExtreme::displayTreeUpDown (BTreeNode * root,int x,int y,int px=0){
	if(root==NULL) return;
	gotoxy(x,y);
	int a=abs(px-x)/2;

	//cout<<root->size;
	coutRoot(root, true);
	displayTreeUpDown(root->left ,x-a,y+1,x);
	displayTreeUpDown(root->right,x+a,y+1,x);
}
void Tree2PclosesttoExtreme::display (){
	displayTreeUpDown(Root,Math::Pow (2,depth(Root)),1,1);
}
void Tree2PclosesttoExtreme::TraversBreadth (){
	BTreeNode * temp_node=Root;
	if (temp_node==NULL)
		return;
	long CurrentLevel=temp_node->level;
	bool newline=false;
	Q= new queue();
    while (temp_node!=NULL)
    {
        coutRoot(temp_node, newline);//print
 
        /*Enqueue left child */
        if (temp_node->left!= NULL )
            Q->push(temp_node->left);
 
        /*Enqueue right child */
        if (temp_node->right!=NULL)
            Q->push(temp_node->right);
 
        /*Dequeue node and make it temp_node*/
        temp_node = Q->pop();
		if (temp_node!=NULL)
			if (temp_node->level!=CurrentLevel){
				CurrentLevel=temp_node->level;
				newline=true;
			}
			else
				newline=false;
	}
	delete Q;
	return;
}

//update tree stats
void Tree2PclosesttoExtreme::updatestats(BTreeNode * node){
	if (node==NULL)
		return;
	NumberofNodes++;
	sumsizeofAllnodes+=node->size;
	if (node->level > maxDepth)
		maxDepth=node->level;
	if (node->left==NULL && node->right==NULL){
		NumberofLeaves++;
		sumsizeofLeaves+=node->size; 
		if (node->size > maxsizeofLeaf)
			maxsizeofLeaf=node->size;
		if (node->size < minsizeofLeaf)
			minsizeofLeaf=node->size;  
	}
	updatestats(node->left);
	updatestats(node->right);
}
//=============================end Tree 4 =========================================================================

//***********************************************************************************************
//=============================Tree5 ==================
//  /\
// /\ /\
//tree5  is based on sorting the points from train mat in a binary search tree based on 
//their distances from the 2 local furthest points p1 and p2 in a node
//the furthest poiints will be calculated using A2 algorithm FastFar13

class Tree2FurthestPoints
      {
      public:
			Tree2FurthestPoints(Mat * mat, int DistanceType); //constructor set initial of tree
			~Tree2FurthestPoints(){
				Clear(Root);
				//delete []Norms;
			}
			void Clear(BTreeNode*);
			void BuildTree(Mat *mat, BTreeNode *, int dtype);
			BTreeNode *GetNode(BTreeNode *, Mat *TrainMat, Mat *TestMat, long TestExampleNdx, int dtype);
			BTreeNode *GetNode(BTreeNode *, Mat *TrainMat, Mat *TestMat, long TestExampleNdx, int dtype, long);
			BTreeNode *GetExamples(Mat *TrainMat, Mat *TestMat, long TestExampleNdx, int dtype){//helper function
			
				return GetNode(Root, TrainMat, TestMat, TestExampleNdx, dtype);
			}
			BTreeNode *GetExamples(Mat *TrainMat, Mat *TestMat, long TestExampleNdx, int dtype, long numex){
			
				return GetNode(Root, TrainMat, TestMat, TestExampleNdx, dtype, numex);
			}
			long depth(BTreeNode *p);
			void displayTreeUpDown(BTreeNode * ,int ,int ,int );
			void display();
			void TraversBreadth();
			void updatestats(BTreeNode *);
	  private:
			BTreeNode * Root;
			//float *Norms;
public: //tree statistics
	long NumberofNodes;
	long sumsizeofAllnodes; //the total of examples in all nodes, we need this for space complecity
	long NumberofLeaves;
	long sumsizeofLeaves; //the total of examples in all leaves, should be equal to training set size
	long maxsizeofLeaf; //the max number of example in a leaf
	long minsizeofLeaf; //the max number of example in a leaf normaly 1
	float AvrgsizeofLeaves; //the average of examples in all leaves
	long maxDepth;//tree depth
	

        };
Tree2FurthestPoints::Tree2FurthestPoints(Mat *mat ,int dtype){
	//create the tree here
	Root= new BTreeNode;
	long n=mat->Row();
	Root->size=n;
	Root->ExamplesIndx=new long[n];
	//Norms= new float [n];
	for (long i=0;i<n;i++){
	//	Norms[i]=Norms1[i];
		Root->ExamplesIndx[i]=i;
	}
	//find the 2 local furthest points
	//twolongpoints localpoints;
	
	//localpoints = LocalExtremPoints(mat,Root->ExamplesIndx,Root->size,dtype);
	long P1=0,P2=0;
	float diametere=FastFar13(mat,Root->ExamplesIndx,Root->size,&P1,&P2,dtype);
//swap p1 and p2 to let the on of the minimum norm to the left so the tre becomes better 
		long temp;
	if (mat->Norms[P1] > mat->Norms[P2]){
		temp=P1;
		P1=P2;
		P2=temp;
	}

//end swap
	Root->MinNorm=P1;//this is not min norm it is the 1st point of the furthest pair of examples in a node 
	Root->MaxNorm=P2;//this is not min norm it is the 2nd point of the furthest pair of examples in a node 
	Root->left=NULL;
	Root->right=NULL;
	Root->level=1;

//initialize tree stats
	NumberofNodes=0;
	sumsizeofAllnodes=0;
	NumberofLeaves=0;
	sumsizeofLeaves=0; 
	maxsizeofLeaf=0; 
	minsizeofLeaf=LONG_MAX; 
	AvrgsizeofLeaves=0; 
	maxDepth=0;

	//caryy on for the rest of the tree 
	BuildTree(mat, Root, dtype);
	updatestats(Root);
	AvrgsizeofLeaves=(float) sumsizeofLeaves/ (float)NumberofLeaves;
}
void Tree2FurthestPoints::BuildTree(Mat *mat, BTreeNode *node, int Dtype){
	Application::DoEvents();
	//ArrayList ^LeftArr=gcnew ArrayList;
	//ArrayList ^RigtArr=gcnew ArrayList;
	LinkedList *LeftArr = new LinkedList();
	LinkedList *RigtArr = new LinkedList();


	float *fv1=mat->getRow((long) node->MinNorm);
	float *fv2=mat->getRow((long) node->MaxNorm);
	long col=mat->Col();
	for (long i=0;i<node->size;i++ ){
		float *fv=mat->getRow(node->ExamplesIndx[i]);
		float D1=Distance(fv,fv1,col,Dtype);
		float D2=Distance(fv,fv2,col,Dtype);
		if (D1<D2)
			LeftArr->add (node->ExamplesIndx[i]);
		else
			RigtArr->add(node->ExamplesIndx[i]);
		delete fv;
	}
	// update linked list indexes
	if (LeftArr->Count > 0)
		LeftArr->update();
	if (RigtArr->Count > 0)
		RigtArr->update();
	if (LeftArr->Count == 0 || RigtArr->Count == 0) {
		if (LeftArr->Count > 0)
			delete LeftArr;
		if (RigtArr->Count > 0)
			delete RigtArr;
		return;
	}
		
//work for left child LLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLefTTTTTTTTTTTTTTTTTTT
	node->left=new BTreeNode;
	node->left->size =LeftArr->Count;
	node->left->ExamplesIndx=new long[node->left->size];
	for (long i=0;i<node->left->size;i++)
		node->left->ExamplesIndx[i] = LeftArr->Data[i];
		//node->left->ExamplesIndx[i]=safe_cast <long> (LeftArr[i]);

	//find the 2 local furthest points for left child
	//twolongpoints localpoints;
	//localpoints = LocalExtremPoints(mat,node->left->ExamplesIndx,node->left->size,Dtype);

	long P1=0,P2=0;
	float diametere=FastFar13(mat,node->left->ExamplesIndx,node->left->size,&P1,&P2,Dtype);
//swap p1 and p2 to let the on of the minimum norm to the left so the tre becomes better 
		long temp;
	if (mat->Norms[P1] > mat->Norms[P2]){
		temp=P1;
		P1=P2;
		P2=temp;
	}

	node->left->MinNorm=P1;//index of local 1st furthest point 
	node->left->MaxNorm=P2;//index of local 2nd furthest point
	node->left->left=NULL;
	node->left->right=NULL;
	node->left->level=node->level+1;

//work for right child  RRRRRRRRRRRRRRRRRRighTTTTTTTTTTTTTTTTTTTTTTTT
	node->right=new BTreeNode;
	node->right->size =RigtArr->Count;
	node->right->ExamplesIndx=new long[node->right->size];
	for (long i=0;i<node->right->size;i++)
		node->right->ExamplesIndx[i]=RigtArr->Data[i];

	//find the 2 local furthest points for right child
	//localpoints = LocalExtremPoints(mat,node->right->ExamplesIndx,node->right->size,Dtype);
	diametere=FastFar13(mat,node->right->ExamplesIndx,node->right->size,&P1,&P2,Dtype);
//swap p1 and p2 to let the on of the minimum norm to the left so the tre becomes better 
		temp;
	if (mat->Norms[P1] > mat->Norms[P2]){
		temp=P1;
		P1=P2;
		P2=temp;
	}
	
	node->right->MinNorm=P1;//index of local 1st furthest point
	node->right->MaxNorm=P2;//index of local 2nd furthest point

	node->right->left=NULL;
	node->right->right=NULL;
	node->right->level=node->level+1;
	delete []fv1; fv1=NULL;
	delete []fv2; fv2=NULL;
	if (LeftArr->Count > 0)
		delete LeftArr;
	if (RigtArr->Count > 0)
		delete RigtArr;

	BuildTree(mat, node->left , Dtype);
	BuildTree(mat, node->right, Dtype);
}
BTreeNode * Tree2FurthestPoints::GetNode(BTreeNode *node, Mat *TrainMat, Mat *TestMat, long TestExampleNdx, int dtype){
	long col=TrainMat->Col();
	float *Testfv=TestMat->getRow(TestExampleNdx);
	float *Minfv =TrainMat->getRow((long) node->MinNorm);
	float *Maxfv =TrainMat->getRow((long) node->MaxNorm);
	float D1=Distance(Testfv,Minfv,col,dtype);
	float D2=Distance(Testfv,Maxfv,col,dtype);
		delete []Testfv;
		delete []Minfv;
		delete []Maxfv;

	if (D1<D2 && node->left)
			return GetNode(node->left, TrainMat, TestMat, TestExampleNdx, dtype);
	
		else if (D2<=D1 && node->right)
			return GetNode(node->right,TrainMat, TestMat, TestExampleNdx, dtype);
		else
			return node;

}
BTreeNode * Tree2FurthestPoints::GetNode(BTreeNode *node, Mat *TrainMat, Mat *TestMat, long TestExampleNdx, int dtype, long numex){ 
	//return node of at least numex examples
		if (node->size <= numex)
			return node;
		
	long col=TrainMat->Col();
	float *Testfv=TestMat->getRow(TestExampleNdx);
	float *Minfv =TrainMat->getRow((long) node->MinNorm);
	float *Maxfv =TrainMat->getRow((long) node->MaxNorm);
	float D1=Distance(Testfv,Minfv,col,dtype);
	float D2=Distance(Testfv,Maxfv,col,dtype);
		delete []Testfv;
		delete []Minfv;
		delete []Maxfv;

		if (D1<D2 && node->left)
			return GetNode(node->left, TrainMat, TestMat, TestExampleNdx, dtype,numex);
		else if (D2<=D1 && node->right)
			return GetNode(node->right,TrainMat, TestMat, TestExampleNdx, dtype,numex);
		else
			return node;
}
void Tree2FurthestPoints::Clear(BTreeNode * n)
{
    if (n->left != NULL)
        Clear(n->left );
    if (n->right != NULL)
        Clear(n->right );
	delete [] n->ExamplesIndx; n->ExamplesIndx= NULL;
    delete n;
    n = NULL;
}
//////////// this is to print the tree
long Tree2FurthestPoints::depth(BTreeNode *p){
    if(p==NULL) return 0;
    long l=depth(p->left);
    long r=depth(p->right);
    if(l>=r)
        return l+1;
    else
        return r+1;
}


void Tree2FurthestPoints::displayTreeUpDown (BTreeNode * root,int x,int y,int px=0){
	if(root==NULL) return;
	gotoxy(x,y);
	int a=abs(px-x)/2;

	//cout<<root->size;
	coutRoot(root, true);
	displayTreeUpDown(root->left ,x-a,y+1,x);
	displayTreeUpDown(root->right,x+a,y+1,x);
}
void Tree2FurthestPoints::display (){
	displayTreeUpDown(Root,Math::Pow (2,depth(Root)),1,1);
}
void Tree2FurthestPoints::TraversBreadth (){
	BTreeNode * temp_node=Root;
	if (temp_node==NULL)
		return;
	long CurrentLevel=temp_node->level;
	bool newline=false;
	Q= new queue();
    while (temp_node!=NULL)
    {
        coutRoot(temp_node, newline);//print
 
        /*Enqueue left child */
        if (temp_node->left!= NULL )
            Q->push(temp_node->left);
 
        /*Enqueue right child */
        if (temp_node->right!=NULL)
            Q->push(temp_node->right);
 
        /*Dequeue node and make it temp_node*/
        temp_node = Q->pop();
		if (temp_node!=NULL)
			if (temp_node->level!=CurrentLevel){
				CurrentLevel=temp_node->level;
				newline=true;
			}
			else
				newline=false;
	}
	delete Q;
	return;
}

//update tree stats
void Tree2FurthestPoints::updatestats(BTreeNode * node){
	if (node==NULL)
		return;
	NumberofNodes++;
	sumsizeofAllnodes+=node->size;
	if (node->level > maxDepth)
		maxDepth=node->level;
	if (node->left==NULL && node->right==NULL){
		NumberofLeaves++;
		sumsizeofLeaves+=node->size; 
		if (node->size > maxsizeofLeaf)
			maxsizeofLeaf=node->size;
		if (node->size < minsizeofLeaf)
			minsizeofLeaf=node->size;  
	}
	updatestats(node->left);
	updatestats(node->right);
}



//=============================end Tree 5 =========================================================================


//************************************************************************************************




//============================= start Tree3==================
//  /\
// /\ /\
//tree2 which is based on segmenting the points in trainmat to a binary tree based on 
//the distances from 2 random points

class Tree2MnMxNorms
      {
      public:
			Tree2MnMxNorms(Mat * mat, int DistanceType); //constructor set initial of tree
			~Tree2MnMxNorms(){
				Clear(Root);
				//delete []Norms;
			}
			void Clear(BTreeNode*);
			void BuildTree(Mat *mat, BTreeNode *, int dtype);
			BTreeNode *GetNode(BTreeNode *, Mat *TrainMat, Mat *TestMat, long TestExampleNdx, int dtype);
			BTreeNode *GetNode(BTreeNode *, Mat *TrainMat, Mat *TestMat, long TestExampleNdx, int dtype, long);
			BTreeNode *GetExamples(Mat *TrainMat, Mat *TestMat, long TestExampleNdx, int dtype){//helper function
			
				return GetNode(Root, TrainMat, TestMat, TestExampleNdx, dtype);
			}
			BTreeNode *GetExamples(Mat *TrainMat, Mat *TestMat, long TestExampleNdx, int dtype, long numex){
			
				return GetNode(Root, TrainMat, TestMat, TestExampleNdx, dtype, numex);
			}
			long depth(BTreeNode *p);
			void displayTreeUpDown(BTreeNode * ,int ,int ,int );
			void display();
			void TraversBreadth();
			void updatestats(BTreeNode *);
	  private:
			BTreeNode * Root;
			//float *Norms;
public: //tree statistics
	long NumberofNodes;
	long sumsizeofAllnodes; //the total of examples in all nodes, we need this for space complecity
	long NumberofLeaves;
	long sumsizeofLeaves; //the total of examples in all leaves, should be equal to training set size
	long maxsizeofLeaf; //the max number of example in a leaf
	long minsizeofLeaf; //the max number of example in a leaf normaly 1
	float AvrgsizeofLeaves; //the average of examples in all leaves
	long maxDepth;//tree depth
	

        };
Tree2MnMxNorms::Tree2MnMxNorms(Mat *mat ,int dtype){
	//create the tree here
	Root= new BTreeNode;
	long n=mat->Row();
	Root->size=n;
	Root->ExamplesIndx=new long[n];
	//Norms= new float [n];
	for (long i=0;i<n;i++){
	//	Norms[i]=Norms1[i];
		Root->ExamplesIndx[i]=i;
	}
	//Random ^rnd=gcnew Random();
	
	//long ip2=n-1;
	//find the point of the min norm
	long ip1=Root->ExamplesIndx[0];
	float min=mat->Norms[Root->ExamplesIndx[0]];
	for (long i=1;i<n;i++)
			if (mat->Norms[Root->ExamplesIndx[i]]<min){
				min=mat->Norms[Root->ExamplesIndx[i]];
				ip1=Root->ExamplesIndx[i];
			}
	Root->MinNorm=ip1;
	//find the point of the max norm
	long ip2=Root->ExamplesIndx[0];
	float max=mat->Norms[Root->ExamplesIndx[0]];
	for (long i=1;i<n;i++)
			if (mat->Norms[Root->ExamplesIndx[i]]>max){
				max=mat->Norms[Root->ExamplesIndx[i]];
				ip2=Root->ExamplesIndx[i];
			}
	Root->MaxNorm=ip2;
	Root->left=NULL;
	Root->right=NULL;
	Root->level=1;

//initialize tree stats
	NumberofNodes=0;
	sumsizeofAllnodes=0;
	NumberofLeaves=0;
	sumsizeofLeaves=0; 
	maxsizeofLeaf=0; 
	minsizeofLeaf=LONG_MAX; 
	AvrgsizeofLeaves=0; 
	maxDepth=0;

	//caryy on for the rest of the tree 
	BuildTree(mat, Root, dtype);
	updatestats(Root);
	AvrgsizeofLeaves=(float) sumsizeofLeaves/ (float)NumberofLeaves;
}
void Tree2MnMxNorms::BuildTree(Mat *mat, BTreeNode *node, int Dtype){
	Application::DoEvents();
	ArrayList ^LeftArr=gcnew ArrayList;
	ArrayList ^RigtArr=gcnew ArrayList;
	float *fv1=mat->getRow((long) node->MinNorm);
	float *fv2=mat->getRow((long) node->MaxNorm);
	long col=mat->Col();
	for (long i=0;i<node->size;i++ ){
		float *fv=mat->getRow(node->ExamplesIndx[i]);
		float D1=Distance(fv,fv1,col,Dtype);
		float D2=Distance(fv,fv2,col,Dtype);
		if (D1<D2)
			LeftArr->Add(node->ExamplesIndx[i]);
		else
			RigtArr->Add(node->ExamplesIndx[i]);
		delete fv;
	}
	if (LeftArr->Count ==0 || RigtArr->Count ==0)
		return;
//work for left child
	node->left=new BTreeNode;
	node->left->size =LeftArr->Count;
	node->left->ExamplesIndx=new long[node->left->size];
	for (long i=0;i<node->left->size;i++)
		node->left->ExamplesIndx[i]=safe_cast <long> (LeftArr[i]);

	//float * newnorms=new float [node->left->size];
	//for (long i=0;i<node->left->size;i++)
		//newnorms[i]=Norms[node->left->ExamplesIndx[i]];
	//Random ^rnd=gcnew Random();



	long ip1=node->left->ExamplesIndx[0];
	long ip2=node->left->ExamplesIndx[0];
	float min=mat->Norms[node->left->ExamplesIndx[0]];
	float max=mat->Norms[node->left->ExamplesIndx[0]];
	for (long i=1;i<node->left->size;i++){
			if (mat->Norms[node->left->ExamplesIndx[i]]<min){
				min=mat->Norms[node->left->ExamplesIndx[i]];
				ip1=node->left->ExamplesIndx[i];
			}
			if (mat->Norms[node->left->ExamplesIndx[i]]>max){
				max=mat->Norms[node->left->ExamplesIndx[i]];
				ip2=node->left->ExamplesIndx[i];
			}

	}
	node->left->MinNorm=ip1;//index of point 1 of min norm
	node->left->MaxNorm=ip2;//index of point 2 of max norm

	node->left->left=NULL;
	node->left->right=NULL;
	node->left->level=node->level+1;

//work for right child
	node->right=new BTreeNode;
	node->right->size =RigtArr->Count;
	node->right->ExamplesIndx=new long[node->right->size];
	for (long i=0;i<node->right->size;i++)
		node->right->ExamplesIndx[i]=safe_cast <long> (RigtArr[i]);

	//newnorms=new float [node->right->size];
	//for (long i=0;i<node->right->size;i++)
		//newnorms[i]=Norms[node->right->ExamplesIndx[i]];
	 ip1=node->right->ExamplesIndx[0];
	 ip2=node->right->ExamplesIndx[0];
	 min=mat->Norms[node->right->ExamplesIndx[0]];
	 max=mat->Norms[node->right->ExamplesIndx[0]];
	for (long i=1;i<node->right->size;i++){
			if (mat->Norms[node->right->ExamplesIndx[i]]<min){
				min=mat->Norms[node->right->ExamplesIndx[i]];
				ip1=node->right->ExamplesIndx[i];
			}
			if (mat->Norms[node->right->ExamplesIndx[i]]>max){
				max=mat->Norms[node->right->ExamplesIndx[i]];
				ip2=node->right->ExamplesIndx[i];
			}

	}
	node->right->MinNorm = ip1;//index of point 1 of min norm
	node->right->MaxNorm = ip2;//index of point 2 of max norm

	node->right->left=NULL;
	node->right->right=NULL;
	node->right->level=node->level+1;
	delete []fv1; fv1=NULL;
	delete []fv2; fv2=NULL;

	BuildTree(mat, node->left , Dtype);
	BuildTree(mat, node->right, Dtype);
}
BTreeNode * Tree2MnMxNorms::GetNode(BTreeNode *node, Mat *TrainMat, Mat *TestMat, long TestExampleNdx, int dtype){
	long col=TrainMat->Col();
	float *Testfv=TestMat->getRow(TestExampleNdx);
	float *Minfv =TrainMat->getRow((long) node->MinNorm);
	float *Maxfv =TrainMat->getRow((long) node->MaxNorm);
	float D1=Distance(Testfv,Minfv,col,dtype);
	float D2=Distance(Testfv,Maxfv,col,dtype);
		delete []Testfv;
		delete []Minfv;
		delete []Maxfv;

	if (D1<D2 && node->left)
			return GetNode(node->left, TrainMat, TestMat, TestExampleNdx, dtype);
	
		else if (D2<=D1 && node->right)
			return GetNode(node->right,TrainMat, TestMat, TestExampleNdx, dtype);
		else
			return node;

}
BTreeNode * Tree2MnMxNorms::GetNode(BTreeNode *node, Mat *TrainMat, Mat *TestMat, long TestExampleNdx, int dtype, long numex){ 
	//return node of at least numex examples
		if (node->size <= numex)
			return node;
		
	long col=TrainMat->Col();
	float *Testfv=TestMat->getRow(TestExampleNdx);
	float *Minfv =TrainMat->getRow((long) node->MinNorm);
	float *Maxfv =TrainMat->getRow((long) node->MaxNorm);
	float D1=Distance(Testfv,Minfv,col,dtype);
	float D2=Distance(Testfv,Maxfv,col,dtype);
		delete []Testfv;
		delete []Minfv;
		delete []Maxfv;

		if (D1<D2 && node->left)
			return GetNode(node->left, TrainMat, TestMat, TestExampleNdx, dtype,numex);
		else if (D2<=D1 && node->right)
			return GetNode(node->right,TrainMat, TestMat, TestExampleNdx, dtype,numex);
		else
			return node;
}
void Tree2MnMxNorms::Clear(BTreeNode * n)
{
    if (n->left != NULL)
        Clear(n->left );
    if (n->right != NULL)
        Clear(n->right );
	delete [] n->ExamplesIndx; n->ExamplesIndx= NULL;
    delete n;
    n = NULL;
}
//////////// this is to print the tree
long Tree2MnMxNorms::depth(BTreeNode *p){
    if(p==NULL) return 0;
    long l=depth(p->left);
    long r=depth(p->right);
    if(l>=r)
        return l+1;
    else
        return r+1;
}


void Tree2MnMxNorms::displayTreeUpDown (BTreeNode * root,int x,int y,int px=0){
	if(root==NULL) return;
	gotoxy(x,y);
	int a=abs(px-x)/2;

	//cout<<root->size;
	coutRoot(root, true);
	displayTreeUpDown(root->left ,x-a,y+1,x);
	displayTreeUpDown(root->right,x+a,y+1,x);
}
void Tree2MnMxNorms::display (){
	displayTreeUpDown(Root,Math::Pow (2,depth(Root)),1,1);
}
void Tree2MnMxNorms::TraversBreadth (){
	BTreeNode * temp_node=Root;
	if (temp_node==NULL)
		return;
	long CurrentLevel=temp_node->level;
	bool newline=false;
	Q= new queue();
    while (temp_node!=NULL)
    {
        coutRoot(temp_node, newline);//print
 
        /*Enqueue left child */
        if (temp_node->left!= NULL )
            Q->push(temp_node->left);
 
        /*Enqueue right child */
        if (temp_node->right!=NULL)
            Q->push(temp_node->right);
 
        /*Dequeue node and make it temp_node*/
        temp_node = Q->pop();
		if (temp_node!=NULL)
			if (temp_node->level!=CurrentLevel){
				CurrentLevel=temp_node->level;
				newline=true;
			}
			else
				newline=false;
	}
	delete Q;
	return;
}

//update tree stats
void Tree2MnMxNorms::updatestats(BTreeNode * node){
	if (node==NULL)
		return;
	NumberofNodes++;
	sumsizeofAllnodes+=node->size;
	if (node->level > maxDepth)
		maxDepth=node->level;
	if (node->left==NULL && node->right==NULL){
		NumberofLeaves++;
		sumsizeofLeaves+=node->size; 
		if (node->size > maxsizeofLeaf)
			maxsizeofLeaf=node->size;
		if (node->size < minsizeofLeaf)
			minsizeofLeaf=node->size;  
	}
	updatestats(node->left);
	updatestats(node->right);
}
//=============================end Tree 3 =========================================================================

//Decission trees $$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$
///////////////////////////////////////////////////////////////////////////////////////////////////

//=============================Furthest point DT ==================
//  /\
// /\ /\
//Furthest point DT  is based on sorting the points from train mat in a binary search tree based on 
//their distances from the 2 local furthest points p1 and p2 in a node
//the furthest poiints will be calculated using A2 algorithm FastFar13
//This BST is converted to a decsion tree by storing the parobability of each class in each node, 
//when testing and example these probabilities are consider to decide the class of the example without using KNN

class DT2FurthestPoints
      {
      public:
			DT2FurthestPoints(Mat * mat, int DistanceType, int wtype); //constructor set initial of tree
			~DT2FurthestPoints(){
				Clear(Root);
				//delete []Norms;
			}
			void Clear(DTreeNode*);
			void BuildTree(Mat *mat, DTreeNode *, int dtype, int wtype);
			DTreeNode *GetNode(DTreeNode *, Mat *TrainMat, Mat *TestMat, long TestExampleNdx, int dtype);
			DTreeNode *GetNode(DTreeNode *, Mat *TrainMat, Mat *TestMat, long TestExampleNdx, int dtype, long);
			DTreeNode *GetExamples(Mat *TrainMat, Mat *TestMat, long TestExampleNdx, int dtype){//helper function
			
				return GetNode(Root, TrainMat, TestMat, TestExampleNdx, dtype);
			}
			DTreeNode *GetExamples(Mat *TrainMat, Mat *TestMat, long TestExampleNdx, int dtype, long numex){
			
				return GetNode(Root, TrainMat, TestMat, TestExampleNdx, dtype, numex);
			}
			long depth(DTreeNode *p);
			void displayTreeUpDown(DTreeNode * ,int ,int ,int );
			void display();
			void TraversBreadth();
			void updatestats(DTreeNode *);
	  private:
			DTreeNode * Root;
			//float *Norms;
public: //Dtree statistics
	long NumberofNodes;
	long sumsizeofAllnodes; //the total of examples in all nodes, we need this for space complecity
	long NumberofLeaves;
	long sumsizeofLeaves; //the total of examples in all leaves, should be equal to training set size
	long maxsizeofLeaf; //the max number of example in a leaf
	long minsizeofLeaf; //the max number of example in a leaf normaly 1
	float AvrgsizeofLeaves; //the average of examples in all leaves
	long maxDepth;//tree depth
	int numclasses;
	

        };
DT2FurthestPoints::DT2FurthestPoints(Mat *mat ,int dtype, int wtype){
	//create the Dtree here
	Root= new DTreeNode;
	long n=mat->Row();
	Root->size=n;
	Root->ExamplesIndx=new long[n];
	//Norms= new float [n];
	for (long i=0;i<n;i++){
	//	Norms[i]=Norms1[i];
		Root->ExamplesIndx[i]=i;
	}
	//long numClasses=mat
	//find the 2 local furthest points
	//twolongpoints localpoints;
	
	//localpoints = LocalExtremPoints(mat,Root->ExamplesIndx,Root->size,dtype);
	long P1=0,P2=0;
	float diametere=FastFar13(mat,Root->ExamplesIndx,Root->size,&P1,&P2,dtype);
	/*
//swap p1 and p2 to let the on of the minimum norm to the left so the tre becomes better 
		long temp;
	if (mat->Norms[P1] > mat->Norms[P2]){
		temp=P1;
		P1=P2;
		P2=temp;
	}
	*/
	//sawp p1 p2 to let p1 with the minimum class and p2 with the maximum class so as to regularize the DT
	long temp;
	if (mat->classint[P1] > mat->classint[P2]) {
		temp = P1;
		P1 = P2;
		P2 = temp;
	}


	//initialize the classes probability array
	numclasses=mat->NumberOfClasses();
	Root->Classint=new float[numclasses];
	for (int c=0;c<numclasses;c++)
		Root->Classint[c]=0.0;
	for (long c=0;c<n;c++)
		Root->Classint[mat->classint[c]]++;
	for (int c=0;c<numclasses;c++)
		Root->Classint[c]=Root->Classint[c]/(float) n;//calc probabilities

//end swap
	Root->MinNorm=P1;//this is not min norm it is the 1st point of the furthest pair of examples in a node 
	Root->MaxNorm=P2;//this is not min norm it is the 2nd point of the furthest pair of examples in a node 
	Root->left=NULL;
	Root->right=NULL;
	Root->level=1;

//initialize tree stats
	NumberofNodes=0;
	sumsizeofAllnodes=0;
	NumberofLeaves=0;
	sumsizeofLeaves=0; 
	maxsizeofLeaf=0; 
	minsizeofLeaf=LONG_MAX; 
	AvrgsizeofLeaves=0; 
	maxDepth=0;

	//caryy on for the rest of the tree 
	BuildTree(mat, Root, dtype, wtype);
	updatestats(Root);
	AvrgsizeofLeaves=(float) sumsizeofLeaves/ (float)NumberofLeaves;
}
void DT2FurthestPoints::BuildTree(Mat *mat, DTreeNode *node, int Dtype, int wtype){
	Application::DoEvents();
	//check to see if the all classes from the same class? if yes no need to creat more children=> return

	//ArrayList ^LeftArr=gcnew ArrayList;
	//ArrayList ^RigtArr=gcnew ArrayList;
	LinkedList *LeftArr=new LinkedList();
	LinkedList *RigtArr=new LinkedList();

	float *fv1=mat->getRow((long) node->MinNorm);//P1
	float *fv2=mat->getRow((long) node->MaxNorm);//P2
	long col=mat->Col();
	for (long i=0;i<node->size;i++ ){
		float *fv=mat->getRow(node->ExamplesIndx[i]);
		float D1=Distance(fv,fv1,col,Dtype);
		float D2=Distance(fv,fv2,col,Dtype);
		if (D1<D2)
			LeftArr->add (node->ExamplesIndx[i]);
		else
			RigtArr->add (node->ExamplesIndx[i]);
		delete fv;
	}
	// update linked list indexes
	if (LeftArr->Count > 0)
		LeftArr->update(); 
	if (RigtArr->Count > 0)
		RigtArr->update();

	if (LeftArr->Count ==0 || RigtArr->Count ==0){
		if (LeftArr->Count >0)
			delete LeftArr;
		if (RigtArr->Count >0)
			delete RigtArr;
		return;
	}

//work for left child LLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLefTTTTTTTTTTTTTTTTTTT
	node->left=new DTreeNode;
	node->left->size =LeftArr->Count;
	node->left->level=node->level+1;
	node->left->ExamplesIndx=new long[node->left->size];
	for (long i=0;i<node->left->size;i++)
		node->left->ExamplesIndx[i]=LeftArr->Data[i];
	//	node->left->ExamplesIndx[i]=safe_cast <long> (LeftArr[i]);

	//find the 2 local furthest points for left child
	//twolongpoints localpoints;
	//localpoints = LocalExtremPoints(mat,node->left->ExamplesIndx,node->left->size,Dtype);

	long P1=0,P2=0;
	float diametere=FastFar13(mat,node->left->ExamplesIndx,node->left->size,&P1,&P2,Dtype);
/*swap p1 and p2 to let the on of the minimum norm to the left so the tre becomes better 
		long temp;
	if (mat->Norms[P1] > mat->Norms[P2]){
		temp=P1;
		P1=P2;
		P2=temp;
	}*/
	//sawp p1 p2 to let p1 with the minimum class and p2 with the maximum class so as to regularize the DT
	long temp;
	if (mat->classint[P1] > mat->classint[P2]) {
		temp = P1;
		P1 = P2;
		P2 = temp;
	}


	node->left->MinNorm=P1;//index of local 1st furthest point 
	node->left->MaxNorm=P2;//index of local 2nd furthest point
	//initialize the classes histogram for the left node
	node->left->Classint=new float[numclasses];
	for (int c=0;c<numclasses;c++)
		node->left->Classint[c]=0.0;
	for (long c=0;c<node->left->size;c++)
		node->left->Classint[mat->classint[node->left->ExamplesIndx[c]]]++;//histogram
	bool LeftMulticlasses=false; //check for single class =>pruen the tree
	if (Nonzeros(node->left->Classint,numclasses)>1)
		LeftMulticlasses=true;
	if (wtype==4){//no pruning if chosen
		LeftMulticlasses=true;
	}

	for (int c=0;c<numclasses;c++)
		node->left->Classint[c]=node->left->Classint[c]/(float) node->left->size;//calc probabilities
	//weigt if any node->left->level
	if (wtype==1)
		for (int c=0;c<numclasses;c++)
			node->left->Classint[c]=node->left->Classint[c]* node->left->level;//weighted probabilities
	if (wtype==2)
		for (int c=0;c<numclasses;c++)
			node->left->Classint[c]=node->left->Classint[c]* Math::Pow(2.0,node->left->level);//weighted probabilities
if (wtype!=3)//3 means that there is no accumilation for probability just he probability of the leaf node
	for (int c=0;c<numclasses;c++)
		node->left->Classint[c]=node->left->Classint[c]+node->Classint [c] ;//accumilated probabilities

	node->left->left=NULL;
	node->left->right=NULL;
	

//work for right child  RRRRRRRRRRRRRRRRRRighTTTTTTTTTTTTTTTTTTTTTTTT
	node->right=new DTreeNode;
	node->right->size =RigtArr->Count;
	node->right->level=node->level+1;
	node->right->ExamplesIndx=new long[node->right->size];
	for (long i=0;i<node->right->size;i++)
		node->right->ExamplesIndx[i]=RigtArr->Data[i];
	//	node->right->ExamplesIndx[i]=safe_cast <long> (RigtArr[i]);

	//find the 2 local furthest points for right child
	//localpoints = LocalExtremPoints(mat,node->right->ExamplesIndx,node->right->size,Dtype);
	diametere=FastFar13(mat,node->right->ExamplesIndx,node->right->size,&P1,&P2,Dtype);
/*swap p1 and p2 to let the on of the minimum norm to the left so the tre becomes better 
	if (mat->Norms[P1] > mat->Norms[P2]){
		temp=P1;
		P1=P2;
		P2=temp;
	}*/
	//sawp p1 p2 to let p1 with the minimum class and p2 with the maximum class so as to regularize the DT
	//long temp;
	if (mat->classint[P1] > mat->classint[P2]) {
		temp = P1;
		P1 = P2;
		P2 = temp;
	}


	node->right->MinNorm=P1;//index of local 1st furthest point
	node->right->MaxNorm=P2;//index of local 2nd furthest point
	//initialize the classes histogram right node
	node->right->Classint=new float[numclasses];
	for (int c=0;c<numclasses;c++)
		node->right->Classint[c]=0.0;
	for (long c=0;c<node->right->size;c++)
		node->right->Classint[mat->classint[node->right->ExamplesIndx[c]]]++;
	bool RightMulticlasses=false; //check for single class =>pruen the tree
	if (Nonzeros(node->right->Classint,numclasses)>1)
		RightMulticlasses=true;
	if (wtype==4){
		RightMulticlasses=true;
	}
	for (int c=0;c<numclasses;c++)
		node->right->Classint[c]=node->right->Classint[c]/(float) node->right->size;//calc probabilities
	//weigt if any 
	if (wtype==1)
		for (int c=0;c<numclasses;c++)
			node->right->Classint[c]=node->right->Classint[c]* node->right->level;//weighted probabilities
	if (wtype==2)
		for (int c=0;c<numclasses;c++)
			node->right->Classint[c]=node->right->Classint[c]* Math::Pow(2.0,node->right->level);//weighted probabilities
if (wtype!=3)//3 means that there is no accumilation for probability just he probability of the leaf node
	for (int c=0;c<numclasses;c++)
		node->right->Classint[c]=node->right->Classint[c]+node->Classint [c] ;//accumilated probabilities

	node->right->left=NULL;
	node->right->right=NULL;
	
	delete []fv1; fv1=NULL;
	delete []fv2; fv2=NULL;

	if (LeftArr->Count > 0)
		delete LeftArr;
	if (RigtArr->Count > 0)
		delete RigtArr;




if (LeftMulticlasses)
	BuildTree(mat, node->left , Dtype, wtype);
if (RightMulticlasses)
	BuildTree(mat, node->right, Dtype, wtype);
}
DTreeNode * DT2FurthestPoints::GetNode(DTreeNode *node, Mat *TrainMat, Mat *TestMat, long TestExampleNdx, int dtype){
	//this retrieve a leaf node based on a tst example 
	long col=TrainMat->Col();
	float *Testfv=TestMat->getRow(TestExampleNdx);
	float *Minfv =TrainMat->getRow((long) node->MinNorm);
	float *Maxfv =TrainMat->getRow((long) node->MaxNorm);
	float D1=Distance(Testfv,Minfv,col,dtype);
	float D2=Distance(Testfv,Maxfv,col,dtype);
		delete []Testfv;
		delete []Minfv;
		delete []Maxfv;

	if (D1<D2 && node->left)
			return GetNode(node->left, TrainMat, TestMat, TestExampleNdx, dtype);
	
		else if (D2<=D1 && node->right)
			return GetNode(node->right,TrainMat, TestMat, TestExampleNdx, dtype);
		else
			return node;
 
}
DTreeNode * DT2FurthestPoints::GetNode(DTreeNode *node, Mat *TrainMat, Mat *TestMat, long TestExampleNdx, int dtype, long numex){ 
	//return node of at least numex examples
		if (node->size <= numex)
			return node;
		
	long col=TrainMat->Col();
	float *Testfv=TestMat->getRow(TestExampleNdx);
	float *Minfv =TrainMat->getRow((long) node->MinNorm);
	float *Maxfv =TrainMat->getRow((long) node->MaxNorm);
	float D1=Distance(Testfv,Minfv,col,dtype);
	float D2=Distance(Testfv,Maxfv,col,dtype);
		delete []Testfv;
		delete []Minfv;
		delete []Maxfv;

		if (D1<D2 && node->left)
			return GetNode(node->left, TrainMat, TestMat, TestExampleNdx, dtype,numex);
		else if (D2<=D1 && node->right)
			return GetNode(node->right,TrainMat, TestMat, TestExampleNdx, dtype,numex);
		else
			return node;
}
void DT2FurthestPoints::Clear(DTreeNode * n)
{
    if (n->left != NULL)
        Clear(n->left );
    if (n->right != NULL)
        Clear(n->right );
	delete [] n->ExamplesIndx; n->ExamplesIndx= NULL;
	delete [] n->Classint ; n->Classint= NULL;
    delete n;
    n = NULL;
}
//////////// this is to print the tree
long DT2FurthestPoints::depth(DTreeNode *p){
    if(p==NULL) return 0;
    long l=depth(p->left);
    long r=depth(p->right);
    if(l>=r)
        return l+1;
    else
        return r+1;
}


void DT2FurthestPoints::displayTreeUpDown (DTreeNode * root,int x,int y,int px=0){
	if(root==NULL) return;
	gotoxy(x,y);
	int a=abs(px-x)/2;

	//cout<<root->size;
	coutRoot(root, true, numclasses);
	displayTreeUpDown(root->left ,x-a,y+1,x);
	displayTreeUpDown(root->right,x+a,y+1,x);
}
void DT2FurthestPoints::display (){
	displayTreeUpDown(Root,Math::Pow (2,depth(Root)),1,1);
}
void DT2FurthestPoints::TraversBreadth (){
	DTreeNode * temp_node=Root;
	if (temp_node==NULL)
		return;
	long CurrentLevel=temp_node->level;
	bool newline=false;
	DTQ= new DTqueue();
    while (temp_node!=NULL)
    {
        coutRoot(temp_node, newline, numclasses);//print
 
        /*Enqueue left child */
        if (temp_node->left!= NULL )
            DTQ->push(temp_node->left);
 
        /*Enqueue right child */
        if (temp_node->right!=NULL)
            DTQ->push(temp_node->right);
 
        /*Dequeue node and make it temp_node*/
        temp_node = DTQ->pop();
		if (temp_node!=NULL)
			if (temp_node->level!=CurrentLevel){
				CurrentLevel=temp_node->level;
				newline=true;
			}
			else
				newline=false;
	}
	delete DTQ;
	return;
}

//update tree stats
void DT2FurthestPoints::updatestats(DTreeNode * node){
	if (node==NULL)
		return;
	NumberofNodes++;
	sumsizeofAllnodes+=node->size;
	if (node->level > maxDepth)
		maxDepth=node->level;
	if (node->left==NULL && node->right==NULL){
		NumberofLeaves++;
		sumsizeofLeaves+=node->size; 
		if (node->size > maxsizeofLeaf)
			maxsizeofLeaf=node->size;
		if (node->size < minsizeofLeaf)
			minsizeofLeaf=node->size;  
	}
	updatestats(node->left);
	updatestats(node->right);
}



//=============================end DT Tree  =========================================================================


//************************************************************************************************

// random min max Decission tree $$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$
///////////////////////////////////////////////////////////////////////////////////////////////////

//=============================random min max Decission tree ==================
//  /\
// /\ /\
2 random  points DT  is based on sorting the points from train mat in a binary search tree based on 
//their distances from 2 random points p1=> from the minimum class and p2 => from the maximum class within a node
//the the example of the minimmum class and that with the maximum class will be found for each node, the similar examples to P1 goes to left and to the right otherwise.
//This BST is converted to a decsion tree by storing the parobability of each class in each node, 
//when testing any example these probabilities are considered to decide the class of the example without using KNN

class DTRandPMinMaxClass
{
public:
	DTRandPMinMaxClass(Mat * mat, int DistanceType, int wtype); //constructor set initial of tree
	~DTRandPMinMaxClass() {
		Clear(Root);
		//delete []Norms;
	}
	void Clear(DTreeNode*);
	void BuildTree(Mat *mat, DTreeNode *, int dtype, int wtype);
	DTreeNode *GetNode(DTreeNode *, Mat *TrainMat, Mat *TestMat, long TestExampleNdx, int dtype);
	DTreeNode *GetNode(DTreeNode *, Mat *TrainMat, Mat *TestMat, long TestExampleNdx, int dtype, long);
	DTreeNode *GetExamples(Mat *TrainMat, Mat *TestMat, long TestExampleNdx, int dtype) {//helper function

		return GetNode(Root, TrainMat, TestMat, TestExampleNdx, dtype);
	}
	DTreeNode *GetExamples(Mat *TrainMat, Mat *TestMat, long TestExampleNdx, int dtype, long numex) {

		return GetNode(Root, TrainMat, TestMat, TestExampleNdx, dtype, numex);
	}
	long depth(DTreeNode *p);
	void displayTreeUpDown(DTreeNode *, int, int, int);
	void display();
	void TraversBreadth();
	void updatestats(DTreeNode *);
private:
	DTreeNode * Root;
	//float *Norms;
public: //Dtree statistics
	long NumberofNodes;
	long sumsizeofAllnodes; //the total of examples in all nodes, we need this for space complecity
	long NumberofLeaves;
	long sumsizeofLeaves; //the total of examples in all leaves, should be equal to training set size
	long maxsizeofLeaf; //the max number of example in a leaf
	long minsizeofLeaf; //the max number of example in a leaf normaly 1
	float AvrgsizeofLeaves; //the average of examples in all leaves
	long maxDepth;//tree depth
	int numclasses;


};
DTRandPMinMaxClass::DTRandPMinMaxClass(Mat *mat, int dtype, int wtype) {
	//create the Dtree here
	Root = new DTreeNode;
	long n = mat->Row();
	Root->size = n;
	Root->ExamplesIndx = new long[n];
	//Norms= new float [n];
	for (long i = 0;i < n;i++) {
		//	Norms[i]=Norms1[i];
		Root->ExamplesIndx[i] = i;
	}
	//long numClasses=mat
	//find the 2 local random  points
	

	twolongpoints P= LocalRandPMinMaxCls(mat,Root->ExamplesIndx,Root->size);
	long P1 = P.P1, P2 = P.P2;

	//float diametere = FastFar13(mat, Root->ExamplesIndx, Root->size, &P1, &P2, dtype);
	//swap p1 and p2 to let the on of the minimum norm to the left so the tre becomes better 
	/*long temp;
	if (mat->Norms[P1] > mat->Norms[P2]) {
		temp = P1;
		P1 = P2;
		P2 = temp;
	}
	*/
	//initialize the classes probability array
	numclasses = mat->NumberOfClasses();
	Root->Classint = new float[numclasses];
	for (int c = 0;c < numclasses;c++)
		Root->Classint[c] = 0.0;
	for (long c = 0;c < n;c++)
		Root->Classint[mat->classint[c]]++;
	for (int c = 0;c < numclasses;c++)
		Root->Classint[c] = Root->Classint[c] / (float)n;//calc probabilities

//end swap
	Root->MinNorm = P1;//this is not min norm it is the 1st point of the minimum class in  a node 
	Root->MaxNorm = P2;//this is not min norm it is the ist point of the maximum class in a node 
	Root->left = NULL;
	Root->right = NULL;
	Root->level = 1;

	//initialize tree stats
	NumberofNodes = 0;
	sumsizeofAllnodes = 0;
	NumberofLeaves = 0;
	sumsizeofLeaves = 0;
	maxsizeofLeaf = 0;
	minsizeofLeaf = LONG_MAX;
	AvrgsizeofLeaves = 0;
	maxDepth = 0;

	//caryy on for the rest of the tree 
	BuildTree(mat, Root, dtype, wtype);
	updatestats(Root);
	AvrgsizeofLeaves = (float)sumsizeofLeaves / (float)NumberofLeaves;
}
void DTRandPMinMaxClass::BuildTree(Mat *mat, DTreeNode *node, int Dtype, int wtype) {
	Application::DoEvents();
	//check to see if the all classes from the same class? if yes no need to creat more children=> return

	//ArrayList ^LeftArr=gcnew ArrayList;
	//ArrayList ^RigtArr=gcnew ArrayList;
	LinkedList *LeftArr = new LinkedList();
	LinkedList *RigtArr = new LinkedList();

	float *fv1 = mat->getRow((long)node->MinNorm);//P1
	float *fv2 = mat->getRow((long)node->MaxNorm);//P2
	long col = mat->Col();
	for (long i = 0;i < node->size;i++) {
		float *fv = mat->getRow(node->ExamplesIndx[i]);
		float D1 = Distance(fv, fv1, col, Dtype);
		float D2 = Distance(fv, fv2, col, Dtype);
		if (D1 < D2)
			LeftArr->add(node->ExamplesIndx[i]);
		else
			RigtArr->add(node->ExamplesIndx[i]);
		delete fv;
	}
	// update linked list indexes
	if (LeftArr->Count > 0)
		LeftArr->update();
	if (RigtArr->Count > 0)
		RigtArr->update();

	if (LeftArr->Count == 0 || RigtArr->Count == 0) {
		if (LeftArr->Count > 0)
			delete LeftArr;
		if (RigtArr->Count > 0)
			delete RigtArr;
		return;
	}

	//work for left child LLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLefTTTTTTTTTTTTTTTTTTT
	node->left = new DTreeNode;
	node->left->size = LeftArr->Count;
	node->left->level = node->level + 1;
	node->left->ExamplesIndx = new long[node->left->size];
	for (long i = 0;i < node->left->size;i++)
		node->left->ExamplesIndx[i] = LeftArr->Data[i];
	//	node->left->ExamplesIndx[i]=safe_cast <long> (LeftArr[i]);

	//find the 2 local random points of the min and max classes of the left child

	twolongpoints P = LocalRandPMinMaxCls(mat, node->left->ExamplesIndx, node->left->size);
	long P1 = P.P1, P2 = P.P2;

	node->left->MinNorm = P1;//index of local 1st random point of min class
	node->left->MaxNorm = P2;//index of local 2nd random point of max class within the current node.
	//initialize the classes histogram for the left node
	node->left->Classint = new float[numclasses];
	for (int c = 0;c < numclasses;c++)
		node->left->Classint[c] = 0.0;
	for (long c = 0;c < node->left->size;c++)
		node->left->Classint[mat->classint[node->left->ExamplesIndx[c]]]++;//histogram
	bool LeftMulticlasses = false; //check for single class =>pruen the tree
	if (Nonzeros(node->left->Classint, numclasses) > 1)
		LeftMulticlasses = true;
	if (wtype == 4) {//no pruning if chosen
		LeftMulticlasses = true;
	}

	for (int c = 0;c < numclasses;c++)
		node->left->Classint[c] = node->left->Classint[c] / (float)node->left->size;//calc probabilities
	//weigt if any node->left->level
	if (wtype == 1)
		for (int c = 0;c < numclasses;c++)
			node->left->Classint[c] = node->left->Classint[c] * node->left->level;//weighted probabilities
	if (wtype == 2)
		for (int c = 0;c < numclasses;c++)
			node->left->Classint[c] = node->left->Classint[c] * Math::Pow(2.0, node->left->level);//weighted probabilities
	if (wtype != 3)//3 means that there is no accumilation for probability just he probability of the leaf node
		for (int c = 0;c < numclasses;c++)
			node->left->Classint[c] = node->left->Classint[c] + node->Classint[c];//accumilated probabilities

	node->left->left = NULL;
	node->left->right = NULL;


	//work for right child  RRRRRRRRRRRRRRRRRRighTTTTTTTTTTTTTTTTTTTTTTTT
	node->right = new DTreeNode;
	node->right->size = RigtArr->Count;
	node->right->level = node->level + 1;
	node->right->ExamplesIndx = new long[node->right->size];
	for (long i = 0;i < node->right->size;i++)
		node->right->ExamplesIndx[i] = RigtArr->Data[i];
	//	node->right->ExamplesIndx[i]=safe_cast <long> (RigtArr[i]);

	//find the 2 local random points of the min and max classes of the left child

	P = LocalRandPMinMaxCls(mat, node->right->ExamplesIndx, node->right->size);
	P1 = P.P1, P2 = P.P2;

	node->right->MinNorm = P1;//index of local 1st furthest point
	node->right->MaxNorm = P2;//index of local 2nd furthest point
	//initialize the classes histogram right node
	node->right->Classint = new float[numclasses];
	for (int c = 0;c < numclasses;c++)
		node->right->Classint[c] = 0.0;
	for (long c = 0;c < node->right->size;c++)
		node->right->Classint[mat->classint[node->right->ExamplesIndx[c]]]++;
	bool RightMulticlasses = false; //check for single class =>pruen the tree
	if (Nonzeros(node->right->Classint, numclasses) > 1)
		RightMulticlasses = true;
	if (wtype == 4) {
		RightMulticlasses = true;
	}
	for (int c = 0;c < numclasses;c++)
		node->right->Classint[c] = node->right->Classint[c] / (float)node->right->size;//calc probabilities
	//weigt if any 
	if (wtype == 1)
		for (int c = 0;c < numclasses;c++)
			node->right->Classint[c] = node->right->Classint[c] * node->right->level;//weighted probabilities
	if (wtype == 2)
		for (int c = 0;c < numclasses;c++)
			node->right->Classint[c] = node->right->Classint[c] * Math::Pow(2.0, node->right->level);//weighted probabilities
	if (wtype != 3)//3 means that there is no accumilation for probability just he probability of the leaf node
		for (int c = 0;c < numclasses;c++)
			node->right->Classint[c] = node->right->Classint[c] + node->Classint[c];//accumilated probabilities

	node->right->left = NULL;
	node->right->right = NULL;

	delete[]fv1; fv1 = NULL;
	delete[]fv2; fv2 = NULL;

	if (LeftArr->Count > 0)
		delete LeftArr;
	if (RigtArr->Count > 0)
		delete RigtArr;




	if (LeftMulticlasses)
		BuildTree(mat, node->left, Dtype, wtype);
	if (RightMulticlasses)
		BuildTree(mat, node->right, Dtype, wtype);
}
DTreeNode * DTRandPMinMaxClass::GetNode(DTreeNode *node, Mat *TrainMat, Mat *TestMat, long TestExampleNdx, int dtype) {
	//this retrieve a leaf node based on a tst example 
	long col = TrainMat->Col();
	float *Testfv = TestMat->getRow(TestExampleNdx);
	float *Minfv = TrainMat->getRow((long)node->MinNorm);
	float *Maxfv = TrainMat->getRow((long)node->MaxNorm);
	float D1 = Distance(Testfv, Minfv, col, dtype);
	float D2 = Distance(Testfv, Maxfv, col, dtype);
	delete[]Testfv;
	delete[]Minfv;
	delete[]Maxfv;

	if (D1 < D2 && node->left)
		return GetNode(node->left, TrainMat, TestMat, TestExampleNdx, dtype);

	else if (D2 <= D1 && node->right)
		return GetNode(node->right, TrainMat, TestMat, TestExampleNdx, dtype);
	else
		return node;

}
DTreeNode * DTRandPMinMaxClass::GetNode(DTreeNode *node, Mat *TrainMat, Mat *TestMat, long TestExampleNdx, int dtype, long numex) {
	//return node of at least numex examples
	if (node->size <= numex)
		return node;

	long col = TrainMat->Col();
	float *Testfv = TestMat->getRow(TestExampleNdx);
	float *Minfv = TrainMat->getRow((long)node->MinNorm);
	float *Maxfv = TrainMat->getRow((long)node->MaxNorm);
	float D1 = Distance(Testfv, Minfv, col, dtype);
	float D2 = Distance(Testfv, Maxfv, col, dtype);
	delete[]Testfv;
	delete[]Minfv;
	delete[]Maxfv;

	if (D1 < D2 && node->left)
		return GetNode(node->left, TrainMat, TestMat, TestExampleNdx, dtype, numex);
	else if (D2 <= D1 && node->right)
		return GetNode(node->right, TrainMat, TestMat, TestExampleNdx, dtype, numex);
	else
		return node;
}
void DTRandPMinMaxClass::Clear(DTreeNode * n)
{
	if (n->left != NULL)
		Clear(n->left);
	if (n->right != NULL)
		Clear(n->right);
	delete[] n->ExamplesIndx; n->ExamplesIndx = NULL;
	delete[] n->Classint; n->Classint = NULL;
	delete n;
	n = NULL;
}
//////////// this is to print the tree
long DTRandPMinMaxClass::depth(DTreeNode *p) {
	if (p == NULL) return 0;
	long l = depth(p->left);
	long r = depth(p->right);
	if (l >= r)
		return l + 1;
	else
		return r + 1;
}


void DTRandPMinMaxClass::displayTreeUpDown(DTreeNode * root, int x, int y, int px = 0) {
	if (root == NULL) return;
	gotoxy(x, y);
	int a = abs(px - x) / 2;

	//cout<<root->size;
	coutRoot(root, true, numclasses);
	displayTreeUpDown(root->left, x - a, y + 1, x);
	displayTreeUpDown(root->right, x + a, y + 1, x);
}
void DTRandPMinMaxClass::display() {
	displayTreeUpDown(Root, Math::Pow(2, depth(Root)), 1, 1);
}
void DTRandPMinMaxClass::TraversBreadth() {
	DTreeNode * temp_node = Root;
	if (temp_node == NULL)
		return;
	long CurrentLevel = temp_node->level;
	bool newline = false;
	DTQ = new DTqueue();
	DTQ->push(temp_node);
	while (!DTQ->empty())
	{
		/*Dequeue node and make it temp_node*/
		temp_node = DTQ->pop();
		if (temp_node != NULL)
			if (temp_node->level != CurrentLevel) {
				CurrentLevel = temp_node->level;
				newline = true;
			}
			else
				newline = false;
		coutRoot(temp_node, newline, numclasses);//print

		/*Enqueue left child */
		if (temp_node->left != NULL)
			DTQ->push(temp_node->left);

		/*Enqueue right child */
		if (temp_node->right != NULL)
			DTQ->push(temp_node->right);

		
	}
	
	delete DTQ;
	return;
}

//update tree stats
void DTRandPMinMaxClass::updatestats(DTreeNode * node) {
	if (node == NULL)
		return;
	NumberofNodes++;
	sumsizeofAllnodes += node->size;
	if (node->level > maxDepth)
		maxDepth = node->level;
	if (node->left == NULL && node->right == NULL) {
		NumberofLeaves++;
		sumsizeofLeaves += node->size;
		if (node->size > maxsizeofLeaf)
			maxsizeofLeaf = node->size;
		if (node->size < minsizeofLeaf)
			minsizeofLeaf = node->size;
	}
	updatestats(node->left);
	updatestats(node->right);
}



//=============================end Tree random min max DT =========================================================================


//************************************************************************************************