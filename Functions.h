#include "Matrix.h"
#include "clustering.h"
using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::IO;
//defintions and vars
Mat *TrainOut;
Mat *TrainOut1;
Mat **TrainOut2;
Mat **TrainOut3;
int ClassCount;
int NumberofRuns;
void testfunction (void){
	long cls=3;int col=4;
	TrainOut2= new Mat*[cls];
	for (long i=0;i<cls;i++){
		TrainOut2[i]= new Mat(2*col,col);
	}

	for (long i=0;i<cls;i++)
	{delete TrainOut2[i]; TrainOut2[i]=0;}
	delete TrainOut2; TrainOut2=0;
}

//functions

	ArrayList ^ MatToArrayList(Mat *mat){
		//if (!mat)
		//	return 0;
		long row=mat->Row();
		long col=mat->Col();
		ArrayList ^ temparr=gcnew ArrayList();	
			
		for(long r=0;r<row;r++){
				String ^str="";
			for(long c=0;c<col;c++){
				str=String::Concat(str,mat->get(r,c).ToString()," ");
			}
//			String ^clsstr=gcnew String(mat->classes[r]);
//			str=String::Concat(str,clsstr);
			str=String::Concat(str,Convert::ToString(mat->classint[r]));
			temparr->Add(str);
		}
		return temparr;
	}
	struct TrainTestMats{
		Mat *train;
		Mat *test;
	};
//split array list to train and test Matrixses based on input indexes
TrainTestMats ArrayListToMat(ArrayList ^ temparr, long * testIndexes, long n){
		long row=temparr->Count;
	//	if (row==0)
	//		return NULL;
		String ^line= safe_cast <String ^> (temparr[0]);
		String^ delimStr;
		long indexofcomma=line->IndexOf(",");
		if (indexofcomma > 0 && indexofcomma < line->Length-1)
			delimStr= ",";
		else
			delimStr= " ";
		array<Char>^ delimiter = delimStr->ToCharArray( );
		array<String^>^ WordsNumbers;
		WordsNumbers = line->Split(delimiter);
		long col=WordsNumbers->Length-1;

		TrainTestMats TTm;
		long testRow=n;//test size
		TTm.test  =new Mat(testRow,col);	//create mat for test
		long trainRow= row - testRow;//train size
		TTm.train =new Mat(trainRow,col);	//create mat for train
		bool *visit=new bool[row];	
		for (long i=0;i<row;i++)
			visit[i]=false;
		//fill test mat
		for (long i=0;i<testRow;i++){
			long ahmad=testIndexes[i];
			visit[ahmad]=true;
			String ^temp= safe_cast <String ^> (temparr[testIndexes[i]])  ;
			WordsNumbers->Clear;
			WordsNumbers = temp->Split(delimiter);
			for(long j=0;j<col;j++)
				TTm.test->set(i,j,Convert::ToDouble(WordsNumbers[j]));
			TTm.test->classint[i]=Convert::ToInt32(WordsNumbers[col]);
		}

		//fill train mat
		long rowCtr=0;
		for (long i=0;i<row;i++){
			if (visit[i])
				continue;

			String ^temp= safe_cast <String ^> (temparr[i])  ;
			WordsNumbers->Clear;
			WordsNumbers = temp->Split(delimiter);
			for(long j=0;j<col;j++)
				TTm.train->set(rowCtr,j,Convert::ToDouble(WordsNumbers[j]));
			TTm.train->classint[rowCtr]=Convert::ToInt32(WordsNumbers[col]);
			rowCtr++;
		}
		delete [] visit; visit=0;
		return TTm;
	}
//split Matrix into to train and test Matrixses based on input indexes
TrainTestMats MatToMats(Mat * tempMat, long * testIndexes, long n){
		long row=tempMat->Row();
		long col=tempMat->Col();

		TrainTestMats TTm;
		long testRow=n;//test size
		TTm.test  =new Mat(testRow,col);	//create mat for test
		long trainRow= row - testRow;		//train size
		TTm.train =new Mat(trainRow,col);	//create mat for train
		bool *visit=new bool[row];	
		for (long i=0;i<row;i++)
			visit[i]=false;
		//fill test mat
		for (long i=0;i<testRow;i++){
			long indexofRow=testIndexes[i];
			visit[indexofRow]=true;
			float * ROW=tempMat->getRow(indexofRow);
			for(long j=0;j<col;j++)
				TTm.test->set(i,j,ROW[j]);//the set function can be optimized too set one row at once
			TTm.test->classint[i]=tempMat->classint[indexofRow];
			delete [] ROW;
		}

		//fill train mat
		long rowCtr=0;
		for (long i=0;i<row;i++){
			if (visit[i])
				continue;
			float * ROW=tempMat->getRow(i);
			for(long j=0;j<col;j++)
				TTm.train->set(rowCtr,j,ROW[j]);
			TTm.train->classint[rowCtr]=tempMat->classint[i];
			rowCtr++;
			delete [] ROW;
		}
		delete [] visit; visit=0;
		return TTm;
	}
Mat * ArrayListToMat(ArrayList ^ temparr){
		long row=temparr->Count;
		if (row==0)
			return 0;
		String ^line= safe_cast <String ^> (temparr[0]);
		String^ delimStr;
		long indexofcomma=line->IndexOf(",");
		if (indexofcomma > 0 && indexofcomma < line->Length-1)
			delimStr= ",";
		else
			delimStr= " ";
		array<Char>^ delimiter = delimStr->ToCharArray( );
		array<String^>^ WordsNumbers;
		WordsNumbers = line->Split(delimiter);
		long col=WordsNumbers->Length-1;
		Mat* TempMat=new Mat(row,col);	
			
				for (long i=1;i<=row;i++){
					long j;
					for( j=0;j<col;j++){
						TempMat->set(i-1,j,Convert::ToDouble(WordsNumbers[j]));
					}
					TempMat->classint[i-1]=Convert::ToInt32(WordsNumbers[j]);
					if (i<row){
						String ^temp= safe_cast <String ^> (temparr[i])  ;
						WordsNumbers->Clear;
						WordsNumbers = temp->Split(delimiter);
					}
				}
		return TempMat;
	}
///===============
//merge fetures
ArrayList ^ ArrayListMergeFeatures(ArrayList ^ temparr, float MergeRatio){
		long row=temparr->Count;
		if (row==0)
			return temparr;
		String ^line= safe_cast <String ^> (temparr[0]);
				String^ delimStr= " ";
				array<Char>^ delimiter = delimStr->ToCharArray( );
				array<String^>^ WordsNumbers;
				WordsNumbers = line->Split(delimiter);
		long col=WordsNumbers->Length-1;
		ArrayList ^ TempMat=gcnew ArrayList();	
			long stride =	1/MergeRatio;
				for (long i=1;i<=row;i++){
					long j;
					String ^tempstr="";
					for( j=0;j<col-stride+1;j+=stride){
						float sum=0.0;
						for( long k=0;k<stride;k++)
							sum+=Convert::ToDouble(WordsNumbers[j+k])* Math::Pow(2,k);
							//tempstr= String::Concat(tempstr,WordsNumbers[j+k]);
						//TempMat->Add(tempstr);//set(i-1,j,Convert::ToDouble(WordsNumbers[j]));
						tempstr= String::Concat(tempstr,sum.ToString()," ");
					}
					tempstr= String::Concat(tempstr,WordsNumbers[col]);
					TempMat->Add(tempstr);//classint[i-1]=Convert::ToInt32(WordsNumbers[col]);
					if (i<row){
						String ^temp= safe_cast <String ^> (temparr[i])  ;
						WordsNumbers->Clear;
						WordsNumbers = temp->Split(delimiter);
					}
				}
		return TempMat;
	}
//add array of float to row in array list
void	AddtoArrayList(ArrayList ^ arraylist, float arr[],long n,long cls){
			
			String ^str="";
			for(long c=0;c<n;c++){
				str=String::Concat(str,arr[c].ToString()," ");
			}
			str=String::Concat(str,Convert::ToString(cls));
			arraylist->Add(str);
		
		return ;
	}
//add 2 matrexes to a new one 
Mat *	Add2Mats(Mat * mat1, Mat *mat2){
	long col1=mat1->Col(), col2=mat2->Col();
	long row1=mat1->Row(), row2=mat2->Row();
	if (col1!=col2)
		return 0;
	long row=row1+row2; long col=col1;
	Mat * newmat=new Mat(row,col);
	//copy mat1 into newmat
	for(long r=0;r<row1;r++){
		for(long c=0;c<col;c++){
			newmat->set(r,c,mat1->get(r,c));
		}
		newmat->classint[r]=mat1->classint[r];
	}
	//copy mat2 into newmat
	for(long r=0;r<row2;r++){
		for(long c=0;c<col;c++){
			newmat->set(r+row1,c,mat2->get(r,c));
		}
		newmat->classint[r+row1]=mat2->classint[r];
	}

			return newmat;
	}

//============
//merge features

// return the row number index to array of floats including the class at the end
float * ArrayListRowToArrdouble(ArrayList ^ temparr,long index){
		String ^line= safe_cast <String ^> (temparr[index]);
		String^ delimStr;
		long indexofcomma=line->IndexOf(",");
		if (indexofcomma > 0 && indexofcomma < line->Length-1)
			delimStr= ",";
		else
			delimStr= " ";
			array<Char>^ delimiter = delimStr->ToCharArray( );
			array<String^>^ WordsNumbers;
			WordsNumbers = line->Split(delimiter);
		long col=WordsNumbers->Length;
		float* TempArr=new float[col];	
			
		long j;
		for( j=0;j<col;j++){
			TempArr[j]=Convert::ToDouble(WordsNumbers[j]);
		}
				
		return TempArr;
	}
// return the average FV of all FVs belong to a class cls
float * ArrayListRowToAvrgArr(ArrayList ^ temparr,long cls){
	long row=temparr->Count;
		String ^line= safe_cast <String ^> (temparr[0]);
			String^ delimStr= " ";
			array<Char>^ delimiter = delimStr->ToCharArray( );
			array<String^>^ WordsNumbers;
			WordsNumbers = line->Split(delimiter);
		long col=WordsNumbers->Length;
		float* AvrgArr=new float[col];	
		for(long i=0;i<col;i++)
			AvrgArr[i]=0.0;
		float ctrcls=0.0;
		for(long i=0;i<row;i++){
			String ^temp= safe_cast <String ^> (temparr[i])  ;
			WordsNumbers = temp->Split(delimiter);
			if (cls==Convert::ToInt32(WordsNumbers[col-1])){
				ctrcls++;
				for( int j=0;j<col-1;j++){
					AvrgArr[j]+=Convert::ToDouble(WordsNumbers[j]);
				}
			}
		}	

		for(long i=0;i<col-1;i++)
			if(ctrcls==0.0)
				AvrgArr[i]=999999999999999.0;
			else
				AvrgArr[i]=AvrgArr[i]/ctrcls;
		AvrgArr[col-1]=cls;
		return AvrgArr;
	}
//----------------KNN using  average float of the nearest points 
int  knnSumDist(Mat *trnMat, float datum[], int k){
	long row=trnMat->Row(),  col=trnMat->Col();
	float *distance = new float [row];
	long i,r,c;

	int _max= trnMat->NumberOfClasses();
	float *classes =new float[_max];

	//intialize classes counters and floats
	for (i=0;i<_max;i++)
		classes[i]=9999999999999999999.0;
	for (i=0;i<row;i++)
		distance[i]=0.0;
	//clac floats bet datum and each row in data, exception the last column the y col
	for (r=0;r<row;r++){
		for (c=0;c<col;c++)
			distance[r]+= Math::Pow(trnMat->get(r,c)-datum[c],2.0);
		distance[r]=Math::Sqrt(distance[r]);
	}

	// calc the minimum distanc for each k	
	float *classctr =new float [_max];
	for (i=0;i<_max;i++)
		classctr[i]=0.0;
	while(k){
		float min=distance[0];
		int index=0;
		for (i=1;i<row;i++)// this is not correct the best class appear much and its float is added much this is not good
			if (distance[i]<min){
				min=distance[i];
				index=i;
			}
		distance[index]=9999999999999999999.0;
		//String ^str=gcnew String(trnMat->classes[index]);
		//float ind=Convert::ToDouble(str);
		int classindex=trnMat->classint[index];//(int) ind;
		classctr[classindex]++;
		if (classes[classindex]==9999999999999999999.0)
			classes[classindex]=min;
		else
			classes[classindex]+=min;
	k--;
	}

	//calc average floats of each class
	for (i=0;i<_max;i++){
		
		if (classctr[i]!= 0.0)
			classes[i]=classes[i]/classctr[i];
		else
			classes[i]=99999999999999999999999999999.0;

	}

// calc the min calsses counter to find the best class (index of classes)
	int classindex=argmin(classes,_max);

	delete [] classes; classes=0;
	delete [] distance; distance=0;
	delete [] classctr; classctr=0;
return classindex;
	}
//----------end------KNN average float of the nearest points 
twovalues *twovaluesarr; 
float *twovaluesarr1;
//----------------KNN using min sum of floats weighted using inverse fib
int  knnSumDistFib(Mat *trnMat, float datum[], int k){
	long row=trnMat->Row(),  col=trnMat->Col();
	float *distance = new float [row];
	long i;//,r,c;

	int _max=trnMat->NumberOfClasses();
	float *classes =new float[_max];
	
	//intialize classes counters and floats
	for (i=0;i<_max;i++)
		classes[i]=9999999999999999999.0;
	for (i=0;i<row;i++)
		distance[i]=0.0;
	//clac floats bet datum and each row in data, exception the last column 
	for (long r=0;r<row;r++){
		for (long c=0;c<col;c++){
			float v1=trnMat->get(r,c);
			float v2=datum[c];

			distance[r]+= Math::Abs(v1 - v2);//,2.0);
		}
		distance[r]= Math::Sqrt(distance[r]);
	}
	//move floats and class to two values
	 twovaluesarr = new twovalues [row];
	for (i=0;i<row;i++){
		twovaluesarr[i].v1=distance[i];
		twovaluesarr[i].v2=trnMat->classint[i];
	}
	//test
//sort floats keep track of their classes in v2
	qs(twovaluesarr,row);
//clacl fibs
	int *f =new int[row+1];

	fib(f,row+1);
//add weights
//	for (i=0;i<row;i++){
//		float weight=1.0/(float)f[i];
//		twovaluesarr[i].v1=twovaluesarr[i].v1 * weight;
//	}
	// acumilate k distanc for each class
	int kk;
	for (int cls=0;cls<_max;cls++){
		kk=k;
		i=0;
		while (kk && i<row){
			if (twovaluesarr[i].v2==cls){
				float weight=1.0/(float) f[k-kk];
				if (classes[cls]==9999999999999999999.0)
					classes[cls]=weight*twovaluesarr[i].v1;
				else{
					classes[cls]+=weight*twovaluesarr[i].v1;}
				kk--;
			}
			i++;
		}
	}
// find the calss of the min  weighted sum  (index of classes)
	int cs=argmin(classes,_max);
	delete []twovaluesarr; twovaluesarr=0;
	delete []f; f=0;
	delete [] classes; classes=0;
	delete [] distance; distance=0;
return cs;
	}
//----------end------KNN min sum of floats weighted using inverse fib


//----------------KNN 
int  knn(Mat *trnMat, float datum[], int k){
	long row=trnMat->Row(),  col=trnMat->Col();
	float *distance = new float [row];
	long i,r,c;
	float * fv;
	float MaxV=-99999999999999999.0;
	for (r=0;r<row;r++){
		float cl=trnMat->classint[r];
		if (cl > MaxV)
			MaxV=cl;
	}
	int _max=(int)	MaxV;
	int *classes =new int[_max+1];

	//intialize classes counters and floats
	for (i=0;i<_max+1;i++)
		classes[i]=0;
	for (i=0;i<row;i++)
		distance[i]=0.0;
	//clac floats bet datum and each row in data, exception the last column the y col
	 for (r=0;r<row;r++){
		if (DistanceType==3){
			float *ah= new float[col];
			trnMat->getRow(ah,r);
			distance[r]=Hausdorff(ah, datum, col);
			delete [] ah;
		}
		else{
		switch (DistanceType){
			case 0: //ED
				for (c=0;c<col;c++)
					distance[r]+= Math::Pow(trnMat->get(r,c)-datum[c],2.0);
				distance[r]=Math::Sqrt(distance[r]);
				break;
			case 1: //weighted ED
				for (c=0;c<col;c++)
					distance[r]+= trnMat->weights[c] * Math::Pow(trnMat->get(r,c)-datum[c],2.0);
				distance[r]=Math::Sqrt(distance[r]);
				break;
			case 2: //manhatin
				for (c=0;c<col;c++)
					distance[r]+= Math::Abs(trnMat->get(r,c)-datum[c]);
				break;
			case 4: //Minmax IF(MIN(A3,$A$1)<0,1-(1+MIN(A3,$A$1)+ABS(MIN(A3,$A$1)))/(1+MAX(A3,$A$1)+ABS(MIN(A3,$A$1))),1-(1+MIN(A3,$A$1))/(1+MAX(A3,$A$1)))
				// minmax ditance Hassanat
				for (c=0;c<col;c++){
					(Math::Min(trnMat->get(r,c),datum[c])<0) ? 
						distance[r]+= 1.0 -
						(1+ Math::Min(trnMat->get(r,c),datum[c])+ Math::Abs(Math::Min(trnMat->get(r,c),datum[c])))/
					    (1+ Math::Max(trnMat->get(r,c),datum[c])+ Math::Abs(Math::Min(trnMat->get(r,c),datum[c])))
						: distance[r]+= 1.0 -(1+ Math::Min(trnMat->get(r,c),datum[c]))/
					                         (1+ Math::Max(trnMat->get(r,c),datum[c]));
				}
				//distance[r]=distance[r];
				break;
			case 5: //1-(1+p1)/(1+p2)
				//Tanh float: TANH(ABS(X-Y)/max i)
				for (c=0;c<col;c++)
					//float maxfeature=trnMat
					distance[r]+= Math::Tanh( Math::Abs(trnMat->get(r,c)-datum[c])/trnMat->Max[c]);
				break;       
			case 6: //Wave hedges 

				//float minmax=0.0
				for (c=0;c<col;c++)
					distance[r]+= Math::Abs(datum[c] - trnMat->get(r,c))/Range[c];
				//	distance[r]+= Math::Abs(datum[c] - trnMat->get(r,c))/Math::Max(trnMat->get(r,c),datum[c]);
				
				break;
			case 7: //new Hassanat float
				fv = trnMat->getRow(r);
				distance[r]= Hassanat(datum, fv,col);
				delete fv;
				break;
			case 8: //ADR 
					distance[r]= ADR(datum, trnMat->getRow(r),col);				
				break;
			case 9: //exp 
				distance[r] = ExpDistance(datum, trnMat->getRow(r), col);
				break;


		}
		}
	 }

	// calc the minimum distanc for each k	
	while(k){
		float min=distance[0];
		long index=0;
		for (i=1;i<row;i++)
			if (distance[i]<min){
				min=distance[i];
				index=i;
			}
		distance[index]=9999999999999999999.0;
		int classindex=trnMat->classint[index];//(int) ind;

		classes[classindex]++;
	k--;
	}
// calc the maximum calsses counter to find the best class (index of classes)
	int maxclass=classes[0];
	long classindex=0;
	for (i=0;i<_max+1;i++)
		if (classes[i]>maxclass){
			maxclass=classes[i];
			classindex=i;
		}

	delete [] classes; classes=0;
	delete [] distance; distance=0;
return classindex;
	}
//----------end------KNN using sum floats

//----------------KNN for BST nodes 
int  knnBtree(Mat *trnMat, float datum[], int k, BTreeNode * temp, float MaxV){
//	int row=trnMat->Row(),  col=trnMat->Col();
	//int row=trnMat->Row(),  
	long col=trnMat->Col();
	long n=temp->size;
	float *distance = new float [n];
	long i,r,c;
	float *fv;

	int _max=(int)	MaxV;
	int *classes =new int[_max+1];

	//intialize classes counters and floats
	for (i=0;i<_max+1;i++)
		classes[i]=0;
	for (i=0;i<n;i++)
		distance[i]=0.0;
	//clac floats bet datum and each row in data, exception the last column the y col
	 for (r=0;r<n;r++){
		if (DistanceType==3){
			float *ah= new float[col];
			trnMat->getRow(ah,r);
			distance[r]=Hausdorff(ah, datum, col);
			delete [] ah;
		}
		else{
		switch (DistanceType){
			case 0: //ED
				for (c=0;c<col;c++)
					distance[r]+= Math::Pow(trnMat->get(temp->ExamplesIndx[r],c)-datum[c],2.0);
				distance[r]=Math::Sqrt(distance[r]);
				break;
			case 1: //weighted ED
				for (c=0;c<col;c++)
					distance[r]+= trnMat->weights[c] * Math::Pow(trnMat->get(temp->ExamplesIndx[r],c)-datum[c],2.0);
				distance[r]=Math::Sqrt(distance[r]);
				break;
			case 2: //manhatin
				for (c=0;c<col;c++)
					distance[r]+= Math::Abs(trnMat->get(temp->ExamplesIndx[r],c)-datum[c]);
				break;
			case 4: //Minmax IF(MIN(A3,$A$1)<0,1-(1+MIN(A3,$A$1)+ABS(MIN(A3,$A$1)))/(1+MAX(A3,$A$1)+ABS(MIN(A3,$A$1))),1-(1+MIN(A3,$A$1))/(1+MAX(A3,$A$1)))
				// minmax ditance Hasssanat
				fv = trnMat->getRow(temp->ExamplesIndx[r]);
				distance[r]= Hassanat(datum, fv,col);
				delete fv;
				//distance[r]=distance[r];
				break;
			case 5: //1-(1+p1)/(1+p2)
				//Tanh float: TANH(ABS(X-Y)/max i)
				for (c=0;c<col;c++)
					//float maxfeature=trnMat
					distance[r]+= Math::Tanh( Math::Abs(trnMat->get(temp->ExamplesIndx[r],c)-datum[c])/trnMat->Max[c]);
				break;       
			case 6: //Wave hedges 

				//float minmax=0.0
				for (c=0;c<col;c++)
					distance[r]+= Math::Abs(datum[c] - trnMat->get(temp->ExamplesIndx[r],c))/Range[c];
				//	distance[r]+= Math::Abs(datum[c] - trnMat->get(r,c))/Math::Max(trnMat->get(r,c),datum[c]);
				
				break;
			case 7: //new Hassanat float
				for (c=0;c<col;c++){
					float dist;
					(Math::Min(trnMat->get(temp->ExamplesIndx[r],c),datum[c])<0) ? 
						dist = 1.0 -
						(Range[c] + Math::Min(trnMat->get(temp->ExamplesIndx[r],c),datum[c])+ Math::Abs(Math::Min(trnMat->get(temp->ExamplesIndx[r],c),datum[c])))/
					    (Range[c] + Math::Max(trnMat->get(temp->ExamplesIndx[r],c),datum[c])+ Math::Abs(Math::Min(trnMat->get(temp->ExamplesIndx[r],c),datum[c])))
						: dist = 1.0 -(Range[c] + Math::Min(trnMat->get(temp->ExamplesIndx[r],c),datum[c]))/
					                         (Range[c] + Math::Max(trnMat->get(temp->ExamplesIndx[r],c),datum[c]));
					distance[r]+= 2*dist;
				}
				//distance[r]=distance[r];
				break;


		}
		}
	 }

	// calc the minimum distanc for each k	
	while(k){
		float min=distance[0];
		long index=0;
		for (i=1;i<n;i++)
			if (distance[i]<min){
				min=distance[i];
				index=i;
			}
		distance[index]=9999999999999999999.0;
		//String ^str=gcnew String(trnMat->classes[index]);
		//float ind=Convert::ToDouble(str);
		int classindex=trnMat->classint[temp->ExamplesIndx[index]];//(int) ind;

		classes[classindex]++;
	k--;
	}
// calc the maximum calsses counter to find the best class (index of classes)
	int maxclass=classes[0];
	int classindex=0;
	for (i=0;i<_max+1;i++)
		if (classes[i]>maxclass){
			maxclass=classes[i];
			classindex=i;
		}

	delete [] classes; classes=0;
	delete [] distance; distance=0;
return classindex;
	}

//----------------CBIR for BST nodes 
void  CBIRBtree(Mat *trnMat, float datum[], int k, BTreeNode * temp, float MaxV, int * output){
//	int row=trnMat->Row(),  col=trnMat->Col();
	//int row=trnMat->Row(),  
	long col=trnMat->Col();
	long n=temp->size;
	float *distance = new float [n];
	long i,r,c;
	float *fv;

	for (i=0;i<n;i++)
		distance[i]=0.0;
	//clac floats bet datum and each row in data, exception the last column the y col
	 for (r=0;r<n;r++){
		if (DistanceType==3){
			float *ah= new float[col];
			trnMat->getRow(ah,r);
			distance[r]=Hausdorff(ah, datum, col);
			delete [] ah;
		}
		else{
		switch (DistanceType){
			case 0: //ED
				for (c=0;c<col;c++)
					distance[r]+= Math::Pow(trnMat->get(temp->ExamplesIndx[r],c)-datum[c],2.0);
				distance[r]=Math::Sqrt(distance[r]);
				break;
			case 1: //weighted ED
				for (c=0;c<col;c++)
					distance[r]+= trnMat->weights[c] * Math::Pow(trnMat->get(temp->ExamplesIndx[r],c)-datum[c],2.0);
				distance[r]=Math::Sqrt(distance[r]);
				break;
			case 2: //manhatin
				for (c=0;c<col;c++)
					distance[r]+= Math::Abs(trnMat->get(temp->ExamplesIndx[r],c)-datum[c]);
				break;
			case 4: //Minmax IF(MIN(A3,$A$1)<0,1-(1+MIN(A3,$A$1)+ABS(MIN(A3,$A$1)))/(1+MAX(A3,$A$1)+ABS(MIN(A3,$A$1))),1-(1+MIN(A3,$A$1))/(1+MAX(A3,$A$1)))
				// minmax ditance Hasssanat
				fv = trnMat->getRow(temp->ExamplesIndx[r]);
				distance[r]= Hassanat(datum, fv,col);
				delete fv;
				//distance[r]=distance[r];
				break;
			case 5: //1-(1+p1)/(1+p2)
				//Tanh float: TANH(ABS(X-Y)/max i)
				for (c=0;c<col;c++)
					//float maxfeature=trnMat
					distance[r]+= Math::Tanh( Math::Abs(trnMat->get(temp->ExamplesIndx[r],c)-datum[c])/trnMat->Max[c]);
				break;       
			case 6: //Wave hedges 

				//float minmax=0.0
				for (c=0;c<col;c++)
					distance[r]+= Math::Abs(datum[c] - trnMat->get(temp->ExamplesIndx[r],c))/Range[c];
				//	distance[r]+= Math::Abs(datum[c] - trnMat->get(r,c))/Math::Max(trnMat->get(r,c),datum[c]);
				
				break;
			case 7: //new Hassanat float
				for (c=0;c<col;c++){
					float dist;
					(Math::Min(trnMat->get(temp->ExamplesIndx[r],c),datum[c])<0) ? 
						dist = 1.0 -
						(Range[c] + Math::Min(trnMat->get(temp->ExamplesIndx[r],c),datum[c])+ Math::Abs(Math::Min(trnMat->get(temp->ExamplesIndx[r],c),datum[c])))/
					    (Range[c] + Math::Max(trnMat->get(temp->ExamplesIndx[r],c),datum[c])+ Math::Abs(Math::Min(trnMat->get(temp->ExamplesIndx[r],c),datum[c])))
						: dist = 1.0 -(Range[c] + Math::Min(trnMat->get(temp->ExamplesIndx[r],c),datum[c]))/
					                         (Range[c] + Math::Max(trnMat->get(temp->ExamplesIndx[r],c),datum[c]));
					distance[r]+= 2*dist;
				}
				//distance[r]=distance[r];
				break;


		}
		}
	 }

	// calc the minimum distanc for each k	
	 int kk=0;
	while(k){
		float min=distance[0];
		long index=0;
		for (i=1;i<n;i++)
			if (distance[i]<min){
				min=distance[i];
				index=i;
			}
		distance[index]=999999999999999999999999999999999999999999999999999999999999999999.0;
		//String ^str=gcnew String(trnMat->classes[index]);
		//float ind=Convert::ToDouble(str);
		output[kk++]=trnMat->classint[temp->ExamplesIndx[index]];//(int) ind;

	
	k--;
	}

	delete [] distance; distance=0;
//return classindex;
	}



///////////////////
//----------------KNf 
//----------------KNN 
int  knf(Mat *trnMat, float datum[], int k){
	int row=trnMat->Row(),  col=trnMat->Col();
	float *distance = new float [row];
	int i,r,c;

	float MaxV=-99999999999999999.0;
	for (r=0;r<row;r++){
		float cl=trnMat->classint[r];
		if (cl > MaxV)
			MaxV=cl;
	}
	int _max=(int)	MaxV;
	int *classes =new int[_max+1];
	int *classes2 =new int[_max+1];

	//intialize classes counters and floats
	for (i=0;i<_max+1;i++){
		classes[i]=0;
		classes2[i]=0;
	}
	//clac floats bet datum and each featur in data, exception the last column the y col
	Random rnd;//=gcnew Random();
	for (c=0;c<col;c++){
		int c2=rnd.Next(0,col);
		int c3=rnd.Next(0,col);
	for (i=0;i<row;i++)
		distance[i]=0.0;
	 for (r=0;r<row;r++){
		if (DistanceType==3){
			float *ah= new float[col];
			trnMat->getRow(ah,r);
			distance[r]=Hausdorff(ah, datum, col);
			delete [] ah;
		}
		else{
		switch (DistanceType){
			case 0: //ED
				distance[r]= Math::Pow(trnMat->get(r,c)-datum[c],2.0);
				distance[r]=Math::Sqrt(distance[r]);
				break;
			case 1: //weighted ED
				distance[r]= trnMat->weights[c] * Math::Pow(trnMat->get(r,c)-datum[c],2.0);
				distance[r]=Math::Sqrt(distance[r]);
				break;
			case 2: //manhatin
				distance[r]= Math::Abs(trnMat->get(r,c)-datum[c]);
				distance[r]+= Math::Abs(trnMat->get(r,c+1<col?c+1:0)-datum[c+1<col?c+1:0]);
				distance[r]+= Math::Abs(trnMat->get(r,c+2<col?c+2:1)-datum[c+2<col?c+2:1]);
				break;
			case 4: //Minmax IF(MIN(A3,$A$1)<0,1-(1+MIN(A3,$A$1)+ABS(MIN(A3,$A$1)))/(1+MAX(A3,$A$1)+ABS(MIN(A3,$A$1))),1-(1+MIN(A3,$A$1))/(1+MAX(A3,$A$1)))
				// minmax ditance
				(Math::Min(trnMat->get(r,c),datum[c])<0) ? 
						distance[r]= 1.0 -
						(1+ Math::Min(trnMat->get(r,c),datum[c])+ Math::Abs(Math::Min(trnMat->get(r,c),datum[c])))/
					    (1+ Math::Max(trnMat->get(r,c),datum[c])+ Math::Abs(Math::Min(trnMat->get(r,c),datum[c])))
						: distance[r]= 1.0 -(1+ Math::Min(trnMat->get(r,c),datum[c]))/
					                         (1+ Math::Max(trnMat->get(r,c),datum[c]));
				
				//distance[r]=distance[r];
				break;
			case 5: //1-(1+p1)/(1+p2)
				//float minmax=0.0
				distance[r]= Math::Abs(1.0- (1.0 + datum[c]) / (1.0 + trnMat->get(r,c)));
					              
			case 6: //Wave hedges 

				//float minmax=0.0
				distance[r]= Math::Abs(datum[c] - trnMat->get(r,c))/Math::Max(trnMat->get(r,c),datum[c]);
				
				break;
			case 7: //Weighted Manhaten
				(Math::Min(trnMat->get(r,c),datum[c])<0) ? 
						distance[r]+= (1.0 -
						(1+ Math::Min(trnMat->get(r,c),datum[c])+ Math::Abs(Math::Min(trnMat->get(r,c),datum[c])))/
					    (1+ Math::Max(trnMat->get(r,c),datum[c])+ Math::Abs(Math::Min(trnMat->get(r,c),datum[c]))))*
						Math::Abs(trnMat->get(r,c)- datum[c])
						: distance[r]+= (1.0 -(1+ Math::Min(trnMat->get(r,c),datum[c]))/
					                         (1+ Math::Max(trnMat->get(r,c),datum[c])))*
											 Math::Abs(trnMat->get(r,c)- datum[c]);
				
				//distance[r]=distance[r];
				break;


		}
		}
	 }

	// calc the minimum distanc for each k	
	 int kk=k;
	while(kk){
		float min=distance[0];
		int index=0;
		for (i=1;i<row;i++)
			if (distance[i]<min){
				min=distance[i];
				index=i;
			}
		distance[index]=9999999999999999999.0;
		//String ^str=gcnew String(trnMat->classes[index]);
		//float ind=Convert::ToDouble(str);
		int classindex=trnMat->classint[index];//(int) ind;

		classes[classindex]++;
	kk--;
	}
	int mostvotedclass=argmax(classes,_max+1);
	classes2[mostvotedclass]++;
	for (i=0;i<_max+1;i++)
		classes[i]=0;

	}

// calc the maximum calsses counter to find the best class (index of classes)
	int maxclass=classes2[0];
	int classindex=0;
	for (i=0;i<_max+1;i++)
		if (classes2[i]>maxclass){
			maxclass=classes2[i];
			classindex=i;
		}

	delete [] classes; classes=0;
	delete [] classes2; classes2=0;
	delete [] distance; distance=0;
return classindex;
	}

///////////////end knf

int  Ensimbleknn(Mat *trnMat, float datum[], int k){
	int row=trnMat->Row(),  col=trnMat->Col();
	float *distance = new float [row];
	int i,r,c;

	float MaxV=-99999999999999999.0;
	for (r=0;r<row;r++){
		float cl=trnMat->classint[r];
		if (cl > MaxV)
			MaxV=cl;
	}
	int _max=(int)	MaxV;
	float *classes =new float[_max+1];

	//intialize classes counters and floats
	for (i=0;i<_max+1;i++)
		classes[i]=0.0;
	for (i=0;i<row;i++)
		distance[i]=0.0;
	//clac floats bet datum and each row in data, exception the last column the y col
	 for (r=0;r<row;r++){
		if (DistanceType==3){
			float *ah= new float[col];
			trnMat->getRow(ah,r);
			distance[r]=Hausdorff(ah, datum, col);
			delete [] ah;
		}
		else{
		switch (DistanceType){
			case 0: //ED
				for (c=0;c<col;c++)
					distance[r]+= Math::Pow(trnMat->get(r,c)-datum[c],2.0);
				distance[r]=Math::Sqrt(distance[r]);
				break;
			case 1: //weighted ED
				for (c=0;c<col;c++)
					distance[r]+= trnMat->weights[c] * Math::Pow(trnMat->get(r,c)-datum[c],2.0);
				distance[r]=Math::Sqrt(distance[r]);
				break;
			case 2: //manhatin
				for (c=0;c<col;c++)
					distance[r]+= Math::Abs(trnMat->get(r,c)-datum[c]);
				break;
			case 4: //Minmax IF(MIN(A3,$A$1)<0,1-(1+MIN(A3,$A$1)+ABS(MIN(A3,$A$1)))/(1+MAX(A3,$A$1)+ABS(MIN(A3,$A$1))),1-(1+MIN(A3,$A$1))/(1+MAX(A3,$A$1)))
				// minmax ditance
				for (c=0;c<col;c++){
					(Math::Min(trnMat->get(r,c),datum[c])<0) ? 
						distance[r]+= 1.0 -
						(1+ Math::Min(trnMat->get(r,c),datum[c])+ Math::Abs(Math::Min(trnMat->get(r,c),datum[c])))/
					    (1+ Math::Max(trnMat->get(r,c),datum[c])+ Math::Abs(Math::Min(trnMat->get(r,c),datum[c])))
						: distance[r]+= 1.0 -(1+ Math::Min(trnMat->get(r,c),datum[c]))/
					                         (1+ Math::Max(trnMat->get(r,c),datum[c]));
				}
				//distance[r]=distance[r];
				break;
			case 5: //1-(1+p1)/(1+p2)
				//float minmax=0.0
				for (c=0;c<col;c++)
					distance[r]+= Math::Abs(1.0- (1.0 + datum[c]) / (1.0 + trnMat->get(r,c)));
				break;             
			case 6: //Wave hedges 

				//float minmax=0.0
				for (c=0;c<col;c++)
					distance[r]+= Math::Abs(datum[c] - trnMat->get(r,c))/Math::Max(trnMat->get(r,c),datum[c]);
				
				break;
			case 7: //Weighted Manhaten
				for (c=0;c<col;c++){
					(Math::Min(trnMat->get(r,c),datum[c])<0) ? 
						distance[r]+= (1.0 -
						(1+ Math::Min(trnMat->get(r,c),datum[c])+ Math::Abs(Math::Min(trnMat->get(r,c),datum[c])))/
					    (1+ Math::Max(trnMat->get(r,c),datum[c])+ Math::Abs(Math::Min(trnMat->get(r,c),datum[c]))))*
						Math::Abs(trnMat->get(r,c)- datum[c])
						: distance[r]+= (1.0 -(1+ Math::Min(trnMat->get(r,c),datum[c]))/
					                         (1+ Math::Max(trnMat->get(r,c),datum[c])))*
											 Math::Abs(trnMat->get(r,c)- datum[c]);
				}
				//distance[r]=distance[r];
				break;


		}
		}
	 }

	// calc the minimum distanc for each k
	
	 int * minClasses=new int [k];
	 int minclassindex=0;
	 int kk=k;
	while(k){
		float min=distance[0];
		int index=0;
		for (i=1;i<row;i++)
			if (distance[i]<min){
				min=distance[i];
				index=i;
			}
		distance[index]=9999999999999999999.0;
		//int classindex=trnMat->classint[index];//(int) ind;
		minClasses[minclassindex++]=trnMat->classint[index];
		//classes[classindex]++;
	k--;
	}
	for (int i=0;i<kk;i+=2){
		for (int j=0;j<=i;j++){
			classes[minClasses[j]]+=1.0/Math::Log(2+j,2.0);
			//what if we multiply the weight with the float
		}
	}


// calc the maximum calsses counter to find the best class (index of classes)
	float maxclass=classes[0];
	int classindex=0;
	for (i=0;i<_max+1;i++)
		if (classes[i]>maxclass){
			maxclass=classes[i];
			classindex=i;
		}
	delete [] minClasses;minClasses=0;
	delete [] classes; classes=0;
	delete [] distance; distance=0;
return classindex;
	}

/////////=============================
int  EnsimbleknnWDsitance(Mat *trnMat, float datum[], int k){
	int row=trnMat->Row(),  col=trnMat->Col();
	float *distance = new float [row];
	int i,r,c;

	float MaxV=-99999999999999999.0;
	for (r=0;r<row;r++){
		float cl=trnMat->classint[r];
		if (cl > MaxV)
			MaxV=cl;
	}
	int _max=(int)	MaxV;
	float *classes =new float[_max+1];

	//intialize classes counters and floats
	for (i=0;i<_max+1;i++)
		classes[i]=0.0;
	for (i=0;i<row;i++)
		distance[i]=0.0;
	//clac floats bet datum and each row in data, exception the last column the y col
	 for (r=0;r<row;r++){
		if (DistanceType==3){
			float *ah= new float[col];
			trnMat->getRow(ah,r);
			distance[r]=Hausdorff(ah, datum, col);
			delete [] ah;
		}
		else{
		switch (DistanceType){
			case 0: //ED
				for (c=0;c<col;c++)
					distance[r]+= Math::Pow(trnMat->get(r,c)-datum[c],2.0);
				distance[r]=Math::Sqrt(distance[r]);
				break;
			case 1: //weighted ED
				for (c=0;c<col;c++)
					distance[r]+= trnMat->weights[c] * Math::Pow(trnMat->get(r,c)-datum[c],2.0);
				distance[r]=Math::Sqrt(distance[r]);
				break;
			case 2: //manhatin
				for (c=0;c<col;c++)
					distance[r]+= Math::Abs(trnMat->get(r,c)-datum[c]);
				break;
			case 4: //Minmax IF(MIN(A3,$A$1)<0,1-(1+MIN(A3,$A$1)+ABS(MIN(A3,$A$1)))/(1+MAX(A3,$A$1)+ABS(MIN(A3,$A$1))),1-(1+MIN(A3,$A$1))/(1+MAX(A3,$A$1)))
				// minmax ditance
				for (c=0;c<col;c++){
					(Math::Min(trnMat->get(r,c),datum[c])<0) ? 
						distance[r]+= 1.0 -
						(1+ Math::Min(trnMat->get(r,c),datum[c])+ Math::Abs(Math::Min(trnMat->get(r,c),datum[c])))/
					    (1+ Math::Max(trnMat->get(r,c),datum[c])+ Math::Abs(Math::Min(trnMat->get(r,c),datum[c])))
						: distance[r]+= 1.0 -(1+ Math::Min(trnMat->get(r,c),datum[c]))/
					                         (1+ Math::Max(trnMat->get(r,c),datum[c]));
				}
				//distance[r]=distance[r];
				break;
			case 5: //1-(1+p1)/(1+p2)
				//float minmax=0.0
				for (c=0;c<col;c++)
					distance[r]+= Math::Abs(1.0- (1.0 + datum[c]) / (1.0 + trnMat->get(r,c)));
					              
			case 6: //Wave hedges 

				//float minmax=0.0
				for (c=0;c<col;c++)
					distance[r]+= Math::Abs(datum[c] - trnMat->get(r,c))/Math::Max(trnMat->get(r,c),datum[c]);
				
				break;
			case 7: //Weighted Manhaten
				for (c=0;c<col;c++){
					(Math::Min(trnMat->get(r,c),datum[c])<0) ? 
						distance[r]+= (1.0 -
						(1+ Math::Min(trnMat->get(r,c),datum[c])+ Math::Abs(Math::Min(trnMat->get(r,c),datum[c])))/
					    (1+ Math::Max(trnMat->get(r,c),datum[c])+ Math::Abs(Math::Min(trnMat->get(r,c),datum[c]))))*
						Math::Abs(trnMat->get(r,c)- datum[c])
						: distance[r]+= (1.0 -(1+ Math::Min(trnMat->get(r,c),datum[c]))/
					                         (1+ Math::Max(trnMat->get(r,c),datum[c])))*
											 Math::Abs(trnMat->get(r,c)- datum[c]);
				}
				//distance[r]=distance[r];
				break;


		}
		}
	 }
//find the max float
		float max=distance[0];
		for (i=1;i<row;i++)
			if (distance[i]>max){
				max=distance[i];
			}


	// calc the minimum distanc for each k
	 int * minClasses=new int [k];
	 float * minfloats=new float [k];
	 int minclassindex=0;
	 int kk=k;
	while(k){
		float min=distance[0];
		int index=0;
		for (i=1;i<row;i++)
			if (distance[i]<min){
				min=distance[i];
				index=i;
			}
		minfloats[minclassindex]=min;
		minClasses[minclassindex]=trnMat->classint[index];
		minclassindex++;
		distance[index]=9999999999999999999.0;
	k--;
	}
	for (int i=0;i<kk;i+=2){
		for (int j=0;j<=i;j++){
			classes[minClasses[j]]+=(max-minfloats[j])*1.0/Math::Log(2+j,2.0);//what if we multiply the weight with the float
		}
	}


// calc the maximum calsses counter to find the best class (index of classes)
	float maxclass=classes[0];
	int classindex=0;
	for (i=0;i<_max+1;i++)
		if (classes[i]>maxclass){
			maxclass=classes[i];
			classindex=i;
		}
	delete [] minClasses;minClasses=0;
	delete [] classes; classes=0;
	delete [] distance; distance=0;
	delete [] minfloats; minfloats=0;
	
return classindex;
	}

/////////

//========================
int  InvetedIndeces(Mat *trnMat, float datum[]){
	int row=trnMat->Row(),  col=trnMat->Col();


	/////
	twovalues *distance; 
	distance = new twovalues [row];
	
	////
	//float *distance = new float [row];
	int i,r,c;

	float MaxV=-99999999999999999.0;
	for (r=0;r<row;r++){
		float cl=trnMat->classint[r];
		if (cl > MaxV)
			MaxV=cl;
	}
	int _max=(int)	MaxV;
	float *classes =new float[_max+1];

	//intialize classes counters and floats
	for (i=0;i<_max+1;i++)
		classes[i]=0.0;
	for (i=0;i<row;i++){
		distance[i].v1=0.0;
		distance[i].v2=0.0;
	}
	//clac floats bet datum and each row in data, exception the last column the y col
	 for (r=0;r<row;r++){
		if (DistanceType==3){
			float *ah= new float[col];
			trnMat->getRow(ah,r);
			distance[r].v1=Hausdorff(ah, datum, col);
			delete [] ah;
		}
		else{
		switch (DistanceType){
			case 0: //ED
				for (c=0;c<col;c++)
					distance[r].v1 += Math::Pow(trnMat->get(r,c)-datum[c],2.0);
				distance[r].v1=Math::Sqrt(distance[r].v1);
				break;
			case 1: //weighted ED
				for (c=0;c<col;c++)
					distance[r].v1+= trnMat->weights[c] * Math::Pow(trnMat->get(r,c)-datum[c],2.0);
				distance[r].v1=Math::Sqrt(distance[r].v1);
				break;
			case 2: //manhatin
				for (c=0;c<col;c++)
					distance[r].v1+= Math::Abs(trnMat->get(r,c)-datum[c]);
				break;
			case 4: //Minmax IF(MIN(A3,$A$1)<0,1-(1+MIN(A3,$A$1)+ABS(MIN(A3,$A$1)))/(1+MAX(A3,$A$1)+ABS(MIN(A3,$A$1))),1-(1+MIN(A3,$A$1))/(1+MAX(A3,$A$1)))
				// minmax ditance
				for (c=0;c<col;c++){
					(Math::Min(trnMat->get(r,c),datum[c])<0) ? 
						distance[r].v1+= 1.0 -
						(1+ Math::Min(trnMat->get(r,c),datum[c])+ Math::Abs(Math::Min(trnMat->get(r,c),datum[c])))/
					    (1+ Math::Max(trnMat->get(r,c),datum[c])+ Math::Abs(Math::Min(trnMat->get(r,c),datum[c])))
						: distance[r].v1+= 1.0 -(1+ Math::Min(trnMat->get(r,c),datum[c]))/
					                         (1+ Math::Max(trnMat->get(r,c),datum[c]));
				}
				//distance[r]=distance[r];
				break;
			case 5: //1-(1+p1)/(1+p2)
				//float minmax=0.0
				for (c=0;c<col;c++)
					distance[r].v1+= Math::Abs(1.0- (1.0 + datum[c]) / (1.0 + trnMat->get(r,c)));
					              
			case 6: //Wave hedges 

				//float minmax=0.0
				for (c=0;c<col;c++)
					distance[r].v1+= Math::Abs(datum[c] - trnMat->get(r,c))/Math::Max(trnMat->get(r,c),datum[c]);
				
				break;
			case 7: //Weighted Manhaten
				for (c=0;c<col;c++){
					(Math::Min(trnMat->get(r,c),datum[c])<0) ? 
						distance[r].v1+= (1.0 -
						(1+ Math::Min(trnMat->get(r,c),datum[c])+ Math::Abs(Math::Min(trnMat->get(r,c),datum[c])))/
					    (1+ Math::Max(trnMat->get(r,c),datum[c])+ Math::Abs(Math::Min(trnMat->get(r,c),datum[c]))))*
						Math::Abs(trnMat->get(r,c)- datum[c])
						: distance[r].v1+= (1.0 -(1+ Math::Min(trnMat->get(r,c),datum[c]))/
					                         (1+ Math::Max(trnMat->get(r,c),datum[c])))*
											 Math::Abs(trnMat->get(r,c)- datum[c]);
				}
				//distance[r]=distance[r];
				break;


		}
		}
		//update class
		distance[r].v2=trnMat->classint[r];
	 }
	 //sort the float according to the nearest to the test example 
	qs(distance,row);
	// calc the minimum distanc for each k	
	for (r=0;r<row;r++){
		float InvertedIndex= 1.0/(float)(r+ 1.0);

		classes[(int) distance[r].v2]+= InvertedIndex;
	}
// calc the maximum calsses counter to find the best class (index of classes)
	float maxclass=classes[0];
	int classindex=0;
	for (i=0;i<_max+1;i++)
		if (classes[i]>maxclass){
			maxclass=classes[i];
			classindex=i;
		}
    
	delete [] classes; classes=0;
	delete [] distance; distance=0;
return classindex;
	}
//----------end------IINC using sum of inverted indeces after sorting floats

//========================
int  EnsimbleIINC(Mat *trnMat, float datum[]){
	int row=trnMat->Row(),  col=trnMat->Col();


	/////
	twovalues *distance; 
	distance = new twovalues [row];
	
	////
	//float *distance = new float [row];
	int i,r,c;

	float MaxV=-99999999999999999.0;
	for (r=0;r<row;r++){
		float cl=trnMat->classint[r];
		if (cl > MaxV)
			MaxV=cl;
	}
	int _max=(int)	MaxV;
	float *classes =new float[_max+1];
	//int *classes2 =new int[_max+1];

	//intialize classes2 counters and floats
	for (i=0;i<_max+1;i++){
	//	classes2[i]=0;
		classes[i]=0;
	}
	//clac floats bet datum and each col in data, exception the last column the y col
	/*for (i=0;i<row;i++){
		distance[i].v1=0;
		distance[i].v2=0;
	}*/
	for (c=0;c<col;c++){
	//intialize floats for each colomn 
	 for (r=0;r<row;r++){
		if (DistanceType==3){
			float *ah= new float[col];
			trnMat->getRow(ah,r);
			distance[r].v1=Hausdorff(ah, datum, col);
			delete [] ah;
		}
		else{
		switch (DistanceType){
			case 0: //ED
				//for (c=0;c<col;c++)
					distance[r].v1 = Math::Pow(trnMat->get(r,c)-datum[c],2.0);
				distance[r].v1=Math::Sqrt(distance[r].v1);
				break;
			case 1: //weighted ED
				//for (c=0;c<col;c++)
					distance[r].v1= trnMat->weights[c] * Math::Pow(trnMat->get(r,c)-datum[c],2.0);
				distance[r].v1=Math::Sqrt(distance[r].v1);
				break;
			case 2: //manhatin
				
					distance[r].v1= Math::Abs(trnMat->get(r,c)-datum[c]);
				break;
			case 4: //Minmax IF(MIN(A3,$A$1)<0,1-(1+MIN(A3,$A$1)+ABS(MIN(A3,$A$1)))/(1+MAX(A3,$A$1)+ABS(MIN(A3,$A$1))),1-(1+MIN(A3,$A$1))/(1+MAX(A3,$A$1)))
				// minmax ditance
				//for (c=0;c<col;c++){
					(Math::Min(trnMat->get(r,c),datum[c])<0) ? 
						distance[r].v1= 1.0 -
						(1+ Math::Min(trnMat->get(r,c),datum[c])+ Math::Abs(Math::Min(trnMat->get(r,c),datum[c])))/
					    (1+ Math::Max(trnMat->get(r,c),datum[c])+ Math::Abs(Math::Min(trnMat->get(r,c),datum[c])))
						: distance[r].v1= 1.0 -(1+ Math::Min(trnMat->get(r,c),datum[c]))/
					                         (1+ Math::Max(trnMat->get(r,c),datum[c]));
				//}
				//distance[r]=distance[r];
				break;
			case 5: //1-(1+p1)/(1+p2)
				//float minmax=0.0
				//for (c=0;c<col;c++)
					distance[r].v1= Math::Abs(1.0- (1.0 + datum[c]) / (1.0 + trnMat->get(r,c)));
					              
			case 6: //Wave hedges 

				//float minmax=0.0
				//for (c=0;c<col;c++)
					distance[r].v1= Math::Abs(datum[c] - trnMat->get(r,c))/Math::Max(trnMat->get(r,c),datum[c]);
				
				break;
			case 7: //Weighted Manhaten
			//	for (c=0;c<col;c++){
					(Math::Min(trnMat->get(r,c),datum[c])<0) ? 
						distance[r].v1= (1.0 -
						(1+ Math::Min(trnMat->get(r,c),datum[c])+ Math::Abs(Math::Min(trnMat->get(r,c),datum[c])))/
					    (1+ Math::Max(trnMat->get(r,c),datum[c])+ Math::Abs(Math::Min(trnMat->get(r,c),datum[c]))))*
						Math::Abs(trnMat->get(r,c)- datum[c])
						: distance[r].v1= (1.0 -(1+ Math::Min(trnMat->get(r,c),datum[c]))/
					                         (1+ Math::Max(trnMat->get(r,c),datum[c])))*
											 Math::Abs(trnMat->get(r,c)- datum[c]);
			//	}
				//distance[r]=distance[r];
				break;


		}
		}
		//update class
		distance[r].v2= (float) trnMat->classint[r];
	 }//for each row for each coloman
	 //sort the floats according to the nearest feature to the tested feature  
	qs(distance,row);
	// calc the minimum distanc for each k	
	float InvertedIndex = 1.0;
	float oldvalue =distance[0].v1;
	classes[(int) (distance[0].v2) ] += 1.0;
	int rr=0;
	for (r=1;r<=Math::Sqrt(row);r++){
		if (oldvalue != distance[r].v1){
			//rr++;
			InvertedIndex= 1.0/(float)(++rr + 1.0);
			oldvalue = distance[r].v1;
		}
		classes[(int) (distance[r].v2) ] += InvertedIndex;
	}

	
// calc the maximum calsses counter to find the best class (index of classes)
/*	float maxclass=classes[0];
	int classindex=0;
	for (i=0;i<_max+1;i++)
		if (classes[i]>maxclass){
			maxclass=classes[i];
			classindex=i;
		}
	classes2[classindex]++;*/
//	classes2[argmax(classes,_max+1)]++;
	//intialize classes for each colomn vote
//	for (i=0;i<_max+1;i++)
//		classes[i]=0;

}///to here for each column
////
//	int classindex2=argmax(classes2,_max+1);
	int classindex=argmax(classes,_max+1);
	delete [] classes; classes=0;
//	delete [] classes2; classes2=0;
	delete [] distance; distance=0;
return classindex;
	}
//end------ensimble IINC using sum of inverted indeces for each feature after sorting thier floats

////////////////



////////////////////////////////////knn on nearst norms from training data

int  knnNorm(Mat *trnMat, float datum[], int k,twovalues A2v[], twovalues range, float MaxV){
	int row=range.v2-range.v1,  col=trnMat->Col();
	float *distance = new float [row];
	int i,r,c;
	int _max=(int)	MaxV;
	int *classes =new int[_max+1];

	//intialize classes counters and floats
	for (i=0;i<_max+1;i++)
		classes[i]=0;
	for (i=0;i<row;i++)
		distance[i]=0.0;
	//clac floats bet datum and each row in data, exception the last column the y col
	 for (r=0;r<row;r++){
		if (DistanceType==3){
			float *ah= new float[col];
			trnMat->getRow(ah,(int)A2v[r+(int)range.v1].v2);
			distance[r]=Hausdorff(ah, datum, col);
			delete [] ah;ah=0;
		}
		else{
		switch (DistanceType){
			case 0: //ED
				for (c=0;c<col;c++)
					distance[r]+= Math::Pow(trnMat->get((int)A2v[r+(int)range.v1].v2,c)-datum[c],2.0);
				distance[r]=Math::Sqrt(distance[r]);
				break;
			case 1: //weighted ED
				for (c=0;c<col;c++)
					distance[r]+= trnMat->weights[c] * Math::Pow(trnMat->get((int)A2v[r+(int)range.v1].v2,c)-datum[c],2.0);
				distance[r]=Math::Sqrt(distance[r]);
				break;
			case 2: //manhatin
				for (c=0;c<col;c++)
					distance[r]+= Math::Abs(trnMat->get((int)A2v[r+(int)range.v1].v2,c)-datum[c]);
				break;
			case 4: //Minmax IF(MIN(A3,$A$1)<0,1-(1+MIN(A3,$A$1)+ABS(MIN(A3,$A$1)))/(1+MAX(A3,$A$1)+ABS(MIN(A3,$A$1))),1-(1+MIN(A3,$A$1))/(1+MAX(A3,$A$1)))
				// minmax ditance
				for (c=0;c<col;c++){
					(Math::Min(trnMat->get((int)A2v[r+(int)range.v1].v2,c),datum[c])<0) ? 
						distance[r]+= 1.0 -
						(1+ Math::Min(trnMat->get((int)A2v[r+(int)range.v1].v2,c),datum[c])+ Math::Abs(Math::Min(trnMat->get((int)A2v[r+(int)range.v1].v2,c),datum[c])))/
					    (1+ Math::Max(trnMat->get((int)A2v[r+(int)range.v1].v2,c),datum[c])+ Math::Abs(Math::Min(trnMat->get((int)A2v[r+(int)range.v1].v2,c),datum[c])))
						: distance[r]+= 1.0 -(1+ Math::Min(trnMat->get((int)A2v[r+(int)range.v1].v2,c),datum[c]))/
					                         (1+ Math::Max(trnMat->get((int)A2v[r+(int)range.v1].v2,c),datum[c]));
				}
				//distance[r]=distance[r];
				break;
			case 5: //1-(1+p1)/(1+p2)
				//float minmax=0.0
				for (c=0;c<col;c++)
					distance[r]+= Math::Abs(1.0- (1.0 + datum[c]) / (1.0 + trnMat->get((int)A2v[r+(int)range.v1].v2,c)));
					              
			case 6: //Wave hedges 

				//float minmax=0.0
				for (c=0;c<col;c++)
					distance[r]+= Math::Abs(datum[c] - trnMat->get((int)A2v[r+(int)range.v1].v2,c))/Math::Max(trnMat->get((int)A2v[r+(int)range.v1].v2,c),datum[c]);
				
				break;
			case 7: //Weighted Manhaten
				for (c=0;c<col;c++){
					(Math::Min(trnMat->get((int)A2v[r+(int)range.v1].v2,c),datum[c])<0) ? 
						distance[r]+= (1.0 -
						(1+ Math::Min(trnMat->get((int)A2v[r+(int)range.v1].v2,c),datum[c])+ Math::Abs(Math::Min(trnMat->get((int)A2v[r+(int)range.v1].v2,c),datum[c])))/
					    (1+ Math::Max(trnMat->get((int)A2v[r+(int)range.v1].v2,c),datum[c])+ Math::Abs(Math::Min(trnMat->get((int)A2v[r+(int)range.v1].v2,c),datum[c]))))*
						Math::Abs(trnMat->get((int)A2v[r+(int)range.v1].v2,c)- datum[c])
						: distance[r]+= (1.0 -(1+ Math::Min(trnMat->get((int)A2v[r+(int)range.v1].v2,c),datum[c]))/
					                         (1+ Math::Max(trnMat->get((int)A2v[r+(int)range.v1].v2,c),datum[c])))*
											 Math::Abs(trnMat->get((int)A2v[r+(int)range.v1].v2,c)- datum[c]);
				}
				//distance[r]=distance[r];
				break;


		}
		}
	 }

	// calc the minimum distanc for each k	
	while(k){
		float min=distance[0];
		int index=0;
		for (i=1;i<row;i++)
			if (distance[i]<min){
				min=distance[i];
				index=i;
			}
		distance[index]=9999999999999999999.0;
		int classindex=trnMat->classint[  (int)A2v[index+(int)range.v1].v2];//(int) ind;

		classes[classindex]++;
	k--;
	}
// calc the maximum calsses counter to find the best class (index of classes)
	int maxclass=classes[0];
	int classindex=0;
	for (i=0;i<_max+1;i++)
		if (classes[i]>maxclass){
			maxclass=classes[i];
			classindex=i;
		}

	delete [] classes; classes=0;
	delete [] distance; distance=0;
return classindex;
	}
//----------end------KNN using sum floats

//////////////////////////////////////////
//-----------------------------------------------------------------
//----------------KNN 
int  knnSubFeature(Mat *trnMat, float datum[], int k, int Feature, int ExampleNum){
	int row=trnMat->Row(),  col=trnMat->Col();
	float *distance = new float [row];
	int i,r,c;

	float MaxV=-99999999999999999.0;
	for (r=0;r<row;r++){
		float cl=trnMat->classint[r];
		if (cl > MaxV)
			MaxV=cl;
	}
	int _max=(int)	MaxV;
	int *classes =new int[_max+1];

	//intialize classes counters and floats
	for (i=0;i<_max+1;i++)
		classes[i]=0;
	for (i=0;i<row;i++)
		distance[i]=0.0;
	//clac floats bet datum and each row in data, exception the last column the y col
	for (r=0;r<row;r++){
		switch (DistanceType){
			case 0: //ED
				for (c=0;c<col;c++)
					if (c!=Feature)
						distance[r]+= Math::Pow(trnMat->get(r,c)-datum[c],2.0);
				distance[r]=Math::Sqrt(distance[r]);
				break;
			case 1: //ED
				for (c=0;c<col;c++)
					if (c!=Feature)
						distance[r]+= Math::Pow(trnMat->get(r,c)-datum[c],2.0);
				break;
			case 2: //manhatin
				for (c=0;c<col;c++)
					if (c!=Feature)
						distance[r]+= Math::Abs(trnMat->get(r,c)-datum[c]);
				break;
		}
	}
	distance[ExampleNum]=9999999999999999999.0;//relax the test example from testing against it self
	// calc the minimum distanc for each k	 
	while(k){
		float min=distance[0];
		int index=0;
		for (i=1;i<row;i++)
			if (distance[i]<min){
				min=distance[i];
				index=i;
			}
		distance[index]=9999999999999999999.0;
		//String ^str=gcnew String(trnMat->classes[index]);
		//float ind=Convert::ToDouble(str);
		int classindex=trnMat->classint[index];//(int) ind;

		classes[classindex]++;
	k--;
	}
// calc the maximum calsses counter to find the best class (index of classes)
	int maxclass=classes[0];
	int classindex=0;
	for (i=0;i<_max+1;i++)
		if (classes[i]>maxclass){
			maxclass=classes[i];
			classindex=i;
		}

	delete [] classes; classes=0;
	delete [] distance; distance=0;
return classindex;
	}
//----------end------KNN using sum floats



//--------------------------------------------------------------------


//min average floats between all points of each class and test point
int  AverageDistances(Mat *trnMat, float datum[]){
	int row=trnMat->Row(),  col=trnMat->Col();
	int i,r,c;

	float MaxV=-99999999999999999.0;
	for (r=0;r<row;r++){
		float cl=trnMat->classint[r];
		if (cl > MaxV)
			MaxV=cl;
	}
	int _max=(int)	(MaxV +1) ;
	float *distance = new float [_max];
	float *classcounter = new float [_max];

	//intialize classes counters and floats
	for (i=0;i<_max;i++){
		classcounter[i]=0;
		distance[i]=0.0;

	}
	//clac floats bet datum and each row in data and accumilate floats to distance[]
	for (r=0;r<row;r++){
		for (c=0;c<col;c++){
			distance[trnMat->classint[r]]+= Math::Sqrt( Math::Pow(trnMat->get(r,c)-datum[c],2.0));
		}
		classcounter[trnMat->classint[r]]++;
	}
	//calc average floats of each class
	for (i=0;i<_max;i++){
		
		if (classcounter[i]!=0.0)
			distance[i]=distance[i]/classcounter[i];
		else
			distance[i]=99999999999999999999999999999.0;

	}


	// calc the minimum distanc of a class	

	float min=distance[0];
	int index=0;
	for (i=1;i<_max;i++)
		if (distance[i]<min){
			min=distance[i];
			index=i;
		}

	delete [] distance; distance=0;
	delete [] classcounter;
return index;
	}
//----------end--min average floats


//Train cnetroids using averages
void  TrainAverageClasses(Mat *trnMat){
	if (TrainOut){
		delete TrainOut; TrainOut=0;
	}
	int row=trnMat->Row(),  col=trnMat->Col();
	int i,r,c;

	float MaxV=-99999999999999999.0;
	for (r=0;r<row;r++){
		float cl=trnMat->classint[r];
		if (cl > MaxV)
			MaxV=cl;
	}
	int _max=(int)	(MaxV +1) ;
//	TrainOut= new Mat(_max,col*col*2) 
	TrainOut= new Mat(_max,col);
	float *classcounter = new float [_max];

	//intialize classes counters and TrainOut matrix
	for (i=0;i<_max;i++){
		classcounter[i]=0.0;
		for (c=0;c<col;c++){
			TrainOut->set(i,c,0.0);
		}


	}
	// accumilate vectors for each class
	for (r=0;r<row;r++){
	//	float *testRow=new distance[TestMat->Col()];
	//	trnMat->getRow(testRow,r);
		int cls=trnMat->classint[r];
		for (c=0;c<col;c++){
			TrainOut->set(cls,c,TrainOut->get(cls,c)+ trnMat->get(r,c));
		}
		classcounter[cls]++;
	//	delete [] testRow;
	}
	//calc average vector of each class
	for (i=0;i<_max;i++){
		
		if (classcounter[i]!=0.0)
			for (c=0;c<col;c++){
				TrainOut->set(i,c,TrainOut->get(i,c)/ classcounter[i]);
			}
		else
			for (c=0;c<col;c++){
				TrainOut->set(i,c,99999999999999999999999999.0);
			}
	}

	delete [] classcounter; classcounter=0;
return ;
	}
//----------end--training using average centroids


//test  using average centroids
int  TestAverageClasses(float datum[]){
	int row=TrainOut->Row(),  col=TrainOut->Col();
	int i,r,c;

	int _max=row ;
	float *distance = new float [_max];

	//clac floats bet datum and each row in TrainOut and add to distance[]
	for (r=0;r<row;r++){
		for (c=0;c<col;c++){
			distance[r]= Math::Sqrt( Math::Pow(TrainOut->get(r,c)-datum[c],2.0));
		}
	}

	// calc the minimum distanc of a class	
	float min=distance[0];
	int index=0;
	for (i=1;i<_max;i++)
		if (distance[i]<min){
			min=distance[i];
			index=i;
		}

	delete [] distance; distance=0;
return index;
	}
//----------end--test  using average centroids

//Train cnetroids using median
void  TrainMedianClasses(Mat *trnMat){
	if (TrainOut){
		delete TrainOut; TrainOut=0;
	}
	int row=trnMat->Row(),  col=trnMat->Col();
	int i,r,c;

	float MaxV=_MND;
	for (r=0;r<row;r++){
		float cl=trnMat->classint[r];
		if (cl > MaxV)
			MaxV=cl;
	}
	int _max=(int)	(MaxV +1) ;
//	TrainOut= new Mat(_max,col*col*2) 
	TrainOut= new Mat(_max,col);

//fill out matrix with medians of each class 
	for (i=0;i<_max;i++){
		for (c=0;c<col;c++){
			TrainOut->set(i,c,trnMat->getMedianOfClass(c,i));
		}
	}


return ;
	}
//----------end--training using median centroids
//
//test  using median centroids
int  TestMedianClasses(float datum[]){
	int row=TrainOut->Row(),  col=TrainOut->Col();
	int i,r,c;

	int _max=row ;
	float *distance = new float [_max];

	//clac floats bet datum and each row in TrainOut and add to distance[]
	for (r=0;r<row;r++){
		for (c=0;c<col;c++){
			distance[r]= Math::Sqrt( Math::Pow(TrainOut->get(r,c)-datum[c],2.0));
		}
	}

	// calc the minimum distanc of a class	
	float min=distance[0];
	int index=0;
	for (i=1;i<_max;i++)
		if (distance[i]<min){
			min=distance[i];
			index=i;
		}

	delete [] distance; distance=0;
return index;
	}
//----------end--test  using median centroids

// training using quartiles as lower and upper bound 
void  TrainQuartilesClasses(Mat *trnMat){

	if (TrainOut2){
		for (int i=0;i<ClassCount;i++)
		{delete TrainOut2[i];  TrainOut2[i]=0;}
		delete TrainOut2; TrainOut2=0;
	}

	int row=trnMat->Row(),  col=trnMat->Col();
//	int i,r,c;
	int c;


	ClassCount=trnMat->NumberOfClasses() ;
	
	TrainOut2= new Mat*[ClassCount];
	for (int i=0;i<ClassCount;i++){
		TrainOut2[i]= new Mat(2,col);
	}

//	TrainOut= new Mat(2*col,col) 

//fill out matrix with quartiles of each class 
for (int cls=0;cls<ClassCount;cls++)
		for (c=0;c<col;c++){
			twovalues qr;
			qr=trnMat->getQuartileOfClass(c,cls);
			TrainOut2[cls]->set(0,c,qr.v1);
			TrainOut2[cls]->set(1,c,qr.v2);
		}
return ;
	}
//----------end--training using quartiles as lower and upper bound 

//test   using quartiles as lower and upper bound
int  TestQuartilesClasses(float datum[]){
	int row=TrainOut2[0]->Row(),  col=TrainOut2[0]->Col();
	int i,c;

	
	float *distance = new float [ClassCount];
	//initilize dist
	for (int cls=0;cls<ClassCount;cls++)
		distance[cls]=0.0;
	//clac accumilated minimum float bet datum[i] and each col from the 2 rows in TrainOut2
	//and add to distance[]
	for (int cls=0;cls<ClassCount;cls++){
		for (c=0;c<col;c++){
			distance[cls]+=min2(Math::Abs(datum[c]-TrainOut2[cls]->get(0,c)),
								Math::Abs(datum[c]-TrainOut2[cls]->get(1,c)));
		}
	}

	// calc the minimum distanc of a class	
	float min= distance[0];
	int index=0;
	for (i=1;i<ClassCount;i++)
		if (distance[i]<min){
			min=distance[i];
			index=i;
		}

	delete [] distance; distance=0;
return index;
	}
//----------end--test  using quartiles as lower and upper bound


// training using rows of medians of classe  as boundaries 
void  TrainRowsMediansClasses(Mat *trnMat){

	if (TrainOut2){
		for (int i=0;i<ClassCount;i++)
			{delete TrainOut2[i]; TrainOut2[i]=0;}
		delete TrainOut2; TrainOut2=0;
	}

	int row=trnMat->Row(),  col=trnMat->Col();
	int i,c;


	ClassCount=trnMat->NumberOfClasses() ;
	
	TrainOut2= new Mat*[ClassCount];
	for (int i=0;i<ClassCount;i++){
		TrainOut2[i]= new Mat(col,col);
	}

//fill out matrix with quartiles of each class 
for (int cls=0;cls<ClassCount;cls++)
	for (i=0;i<col;i++){
		float *rowmed=new float [col];
		trnMat->getRowofMedianOfClass(rowmed,i,cls);
	//	trnMat->getRowaverageofMedianOfClass(rowmed,i,cls);
		for (c=0;c<col;c++){
			TrainOut2[cls]->set(i,c,rowmed[c]);
		}
		delete []rowmed; rowmed=0;
	}
return ;
}
//----------end--training using rows of medians of classe  as boundaries 


//----------test using rows of medians of classe  as boundaries 
int  TestRowsMediansClasses(float datum[]){
	int row=TrainOut2[0]->Row(),  col=TrainOut2[0]->Col();
	int r,c;

	
	float *distance = new float [ClassCount];
	//initilize dist
	for (int cls=0;cls<ClassCount;cls++)
		distance[cls]=0.0;
	//clac accumilated minimum float bet datum[i] and each col from median rows in TrainOut2
	//and add to distance[]
	for (int cls=0;cls<ClassCount;cls++){
		for (c=0;c<col;c++){
			float *arr=new float [col];//the number of boundaries point in train out2
			for (r=0;r<col;r++){
				arr[r]=Math::Abs(datum[c]-TrainOut2[cls]->get(r,c));}
			distance[cls]+=minofArr(arr,col);
			delete [] arr; arr=0;
			
		}
	}

	// calc the minimum distanc of a class	
	int index=argmin(distance,ClassCount);

	delete [] distance; distance=0;
return index;
	}
//----------end--test  using rows of medians of classe  as boundaries


// training using average rows of quartiles  of classe  as boundaries 
void  TrainRowsAvgQuartilesClasses(Mat *trnMat){

	if (TrainOut2){
		for (int i=0;i<ClassCount;i++)
		{delete TrainOut2[i]; TrainOut2[i]=0;}
		delete TrainOut2; TrainOut2=0;
	}

	int row=trnMat->Row(),  col=trnMat->Col();
	int i,c;


	ClassCount=trnMat->NumberOfClasses() ;
	
	TrainOut2= new Mat*[ClassCount];
	for (int i=0;i<ClassCount;i++){
		TrainOut2[i]= new Mat(2*col,col);
	}

//fill out matrix with quartiles of each class 
for (int cls=0;cls<ClassCount;cls++)
	for (i=0;i<col;i++){
		float *rowQr1=new float [col];
		float *rowQr2=new float [col];
		trnMat->getRowaverageofQuartilesOfClass(rowQr1,rowQr2,i,cls);
		for (c=0;c<col;c++){
			TrainOut2[cls]->set(2*i,c,rowQr1[c]);
			TrainOut2[cls]->set(2*i+1,c,rowQr2[c]);
		}
		delete []rowQr1; rowQr1=0;
		delete []rowQr2; rowQr2=0;
	}
return ;
}
//----------end--training average rows of quartiles  of classe  as boundaries 


//----------test using average rows of quartiles  of classe  as boundaries 
int  TestRowsAvgQuartilesClasses(float datum[]){
	int row=TrainOut2[0]->Row(),  col=TrainOut2[0]->Col();
	int r,c;
	
	
	float *distance = new float [ClassCount];
	//initilize dist
	for (int cls=0;cls<ClassCount;cls++)
		distance[cls]=0.0;
	//clac accumilated minimum float bet datum[i] and each col from qr avg rows in TrainOut2
	//and add to distance[]
	for (int cls=0;cls<ClassCount;cls++){
		for (c=0;c<col;c++){
			float *arr=new float [2*col];//the number of boundaries point in train out2 for each class
			for (r=0;r<2*col;r++){
				arr[r]=Math::Abs(datum[c]-TrainOut2[cls]->get(r,c));}
			distance[cls]+=minofArr(arr,2*col);
			delete [] arr; arr=0;
			
		}
	}

	// calc the minimum distanc of a class	
	int index=argmin(distance,ClassCount);

	delete [] distance; distance=0;
return index;
	}
//----------end--test  average rows of quartiles  of classe  as boundaries

//----------test using average rows of quartiles  of classe  as boundaries using ED
int  TestRowsAvgQuartilesClassesED(float datum[]){
	int row=TrainOut2[0]->Row(),  col=TrainOut2[0]->Col();
	int r,c;

	
	float *distance = new float [ClassCount];
	//initilize dist
	for (int cls=0;cls<ClassCount;cls++)
		distance[cls]=0.0;
	//clac accumilated minimum float bet datum[i] and each col from qr avg rows in TrainOut2
	//and add to distance[]
	for (int cls=0;cls<ClassCount;cls++){
		float *arr=new float [2*col];//the number of boundaries point in train out2 for each class
		for (int kk=0;kk<2*col;kk++)
			arr[kk]=0.0;
		for (r=0;r<2*col;r++){
			for (c=0;c<col;c++){
				arr[r]+=Math::Pow(datum[c]-TrainOut2[cls]->get(r,c),2.0);
			}
			arr[r]=Math::Sqrt(arr[r]);
		}
			distance[cls]=minofArr(arr,2*col);
			delete [] arr; arr=0;
	}

	// calc the minimum distanc of a class	
	int index=argmin(distance,ClassCount);

	delete [] distance; distance=0;
return index;
	}
//----------end--test  average rows of quartiles  of classe  as boundaries using ED


//NN Majority: take the minimum floats and go down until you get all the classes
int  NNMajority(Mat *trnMat, float datum[]){
	int row=trnMat->Row(),  col=trnMat->Col();
	float *distance = new float [row];
	int i,r,c;

	int _max=trnMat->NumberOfClasses();
	int *classes =new int[_max];

	//intialize classes counters and floats
	for (i=0;i<_max;i++)
		classes[i]=0;
	for (i=0;i<row;i++)
		distance[i]=0.0;
	//clac floats bet datum and each row in data, exception the last column the y col
	for (r=0;r<row;r++){
		switch (DistanceType){
			case 0: //ED
				for (c=0;c<col;c++)
					distance[r]+= Math::Pow(trnMat->get(r,c)-datum[c],2.0);
				distance[r]=Math::Sqrt(distance[r]);
				break;
			case 1: //ED
				for (c=0;c<col;c++)
					distance[r]+= trnMat->weights[c] * Math::Pow(trnMat->get(r,c)-datum[c],2.0);
				distance[r]=Math::Sqrt(distance[r]);
				break;
			case 2: //manhatin
				for (c=0;c<col;c++)
					distance[r]+= Math::Abs(trnMat->get(r,c)-datum[c]);
				break;

		}
	}

	// calc the minimum distanc for each point	
	bool *visitedclass=new bool [_max];
	for (i=0;i<_max;i++)
		visitedclass[i]=false;
	bool class0found=false;
	for (i=0;i<row;i++)
		if (trnMat->classint[i]==0){
			class0found=true;
			i=row;
			break;
		}
	if (!class0found)
		visitedclass[0]=true;
float *classesSum =new float[_max];
	for (i=0;i<_max;i++)
		classesSum[i]=9999999999999999999.0;
	bool lastone=false;
	while(!lastone){
		if (VisitedAll(visitedclass,_max))
			lastone=true;
		float min=distance[0];
		int index=0;
		for (i=1;i<row;i++)
			if (distance[i]<min){
				min=distance[i];
				index=i;
			}
		distance[index]=9999999999999999999.0;
		int classindex=trnMat->classint[index];//(int) ind;
		visitedclass[classindex]=true;
		classes[classindex]++;
		if (classesSum[classindex]==9999999999999999999.0)
				classesSum[classindex]=min;
		else
			classesSum[classindex]+=min;

	}
// find the class of the maximum counter majority rule (index of classes)
	int classindex=argmax(classes,_max);
//solve the problem of deadlock when thier are more than 1 min
	for (i=0;i<_max;i++)
		if (classes[i]!=0)
			classesSum[i]=classesSum[i]/(float) (classes[i]);
		
	int mx = MaxofArr(classes,_max);
	int ctr=0;
	for (i=0;i<_max;i++)
		if(classes[i]==mx){
			ctr++;
		}
	if (ctr>1)
		classindex=argmin(classesSum,_max);



	delete [] classes; classes=0;
	delete [] visitedclass; visitedclass=0;
	delete [] distance; distance=0;
	delete [] classesSum; classesSum=0;
	
return classindex;
	}
//end-NN Majority: take the minimum floats and go down until you get all the classes


//NN Majority: take the minimum floats and go down until you get all the classes
int  NNMinority(Mat *trnMat, float datum[]){
	int row=trnMat->Row(),  col=trnMat->Col();
	float *distance = new float [row];
	int i,r,c;

	int _max=trnMat->NumberOfClasses();
	int *classes =new int[_max];

	//intialize classes counters and floats
	for (i=0;i<_max;i++)
		classes[i]=0;
	for (i=0;i<row;i++)
		distance[i]=0.0;
	//clac floats bet datum and each row in data, exception the last column the y col
	for (r=0;r<row;r++){
		for (c=0;c<col;c++)
			distance[r]+= Math::Pow(trnMat->get(r,c)-datum[c],2.0);
		distance[r]=Math::Sqrt(distance[r]);
	}

	// find the maximum distanc for each point	
	bool *visitedclass=new bool [_max];
	for (i=0;i<_max;i++)
		visitedclass[i]=false;
	bool class0found=false;
	for (i=0;i<row;i++)
		if (trnMat->classint[i]==0){
			class0found=true;
			i=row;
			break;
		}
	if (!class0found)
		visitedclass[0]=true;

	while(!VisitedAll(visitedclass,_max)){
		float max=distance[0];
		int index=0;
		for (i=1;i<row;i++)
			if (distance[i]> max){
				max=distance[i];
				index=i;
			}
		distance[index]= -99999999999999999.0;
						 
		int classindex=trnMat->classint[index];//(int) ind;
		visitedclass[classindex]=true;
		classes[classindex]++;
	}
// find the class of the min counter, then minority rule (index of classes)
	int classindex=argmin(classes,_max);
	if (classindex==0 && classes[0]==0){
		 classes[0]=32000;
		 classindex=argmin(classes,_max);
	}
	delete [] classes; classes=0;
	delete [] visitedclass; visitedclass=0;
	delete [] distance; distance=0;
	
return classindex;
	}
//end-NN Majority: take the minimum floats and go down until you get all the classes


//----------------NN using  min average of min and max floats  
int  NNMinMaxAvrg(Mat *trnMat, float datum[]){
	int row=trnMat->Row(),  col=trnMat->Col();
	float *distance = new float [row];
	int i,r,c;

	int _max= trnMat->NumberOfClasses();
	float *classes =new float[_max];

	//intialize classes counters and floats
	for (i=0;i<_max;i++)
		classes[i]=9999999999999999999.0;
	for (i=0;i<row;i++)
		distance[i]=0.0;
	//clac floats bet datum and each row in data, exception the last column the y col
	for (r=0;r<row;r++){
		for (c=0;c<col;c++)
			distance[r]+= Math::Pow(trnMat->get(r,c)-datum[c],2.0);
		distance[r]=Math::Sqrt(distance[r]);
	}

	// calc the minimum and max distancs  and avrg em into classes array 	

	for (int cls=0;cls<_max;cls++){
		float min=9999999999999999999.0;
		float max= -9999999999999999999.0;
		int index= -1;
		for (i=0;i<row;i++){
			if (cls==trnMat->classint[i]){
				index=i;
				if (distance[i]<min){
					min=distance[i];
				}
				if (distance[i]>max){
					max=distance[i];
				}
			}
		}
		if (index == -1)
			classes[cls]=9999999999999999999.0;
		else
			classes[cls]=(min+max)/2.0;
	}


// calc the min calsses counter to find the best class (index of classes)
	int classindex=argmin(classes,_max);

	delete [] classes; classes=0;
	delete [] distance; distance=0;
return classindex;
	}
//----------end------KNN average float of the nearest point
//
//   averages of sub classes
//==================================================================

//local test for training averages of sub classes//knn
void KnnLocaltestforTrainingAveragesOfSubClasses(ArrayList ^UnClassifiedBag,
												 ArrayList ^ClassifiedBag,
												 ArrayList ^ClassesAverages){			 

	Mat * TrainMat1=ArrayListToMat(ClassesAverages);
	Mat * TestMat1=ArrayListToMat(UnClassifiedBag);
	for (int i=0;i<TestMat1->Row();i++){
		float *testRow=new float[TestMat1->Col()];
		TestMat1->getRow(testRow,i);
		int cs=knn(TrainMat1,testRow,1);
		if (TestMat1->classint[i]==cs){
			UnClassifiedBag[i]= 999999999999.0.ToString();
			AddtoArrayList(ClassifiedBag,testRow,TestMat1->Col(),TestMat1->classint[i]);
		}
		delete []testRow; testRow=0;
	}
	delete TrainMat1;	TrainMat1=0;
	delete TestMat1;	TestMat1=0;
}
///
//local test for training averages of sub classes of the classifed against the udated avrgs
void fromclassifiedtounclassifiedifnotwelclassifed(ArrayList ^UnClassifiedBag,
												 ArrayList ^ClassifiedBag,
												 ArrayList ^ClassesAverages){			 

	Mat * TrainMat1=ArrayListToMat(ClassesAverages);
	Mat * TestMat1=ArrayListToMat(ClassifiedBag);
	for (int i=0;i<TestMat1->Row();i++){
		float *testRow=new float[TestMat1->Col()];
		TestMat1->getRow(testRow,i);
		int cs=knn(TrainMat1,testRow,1);
		if (TestMat1->classint[i]!=cs){
			AddtoArrayList(UnClassifiedBag,testRow,TestMat1->Col(),TestMat1->classint[i]);
		}
		delete []testRow; testRow=0;
	}
	delete TrainMat1;	TrainMat1=0;
	delete TestMat1;	TestMat1=0;
}
/*String ^ flipStr(String ^str){
	String ^temp= gcnew String();
	for (int i=0;i<str->Length;i++){
		temp[i]=str[str->Length-1-i];
	}
	return temp;
}*/
// training averages of sub classes  
void  TrainingAveragesOfSubClasses(Mat *trnMat){

	if (TrainOut){
		delete TrainOut; TrainOut=0;
	}
	ArrayList ^UnClassifiedBag;
	ArrayList ^ClassifiedBag;
	ArrayList ^ClassesAverages;

	int row=trnMat->Row(),  col=trnMat->Col();
//	int i,r,c;
	ClassCount=trnMat->NumberOfClasses() ;
	UnClassifiedBag= gcnew ArrayList();
	ClassifiedBag= gcnew ArrayList();
	ClassesAverages= gcnew ArrayList();

	UnClassifiedBag = MatToArrayList(trnMat);
	bool nomoretoclassify=false;
while (UnClassifiedBag->Count> 0 && !nomoretoclassify){// not empty
//while (UnClassifiedBag->Count > ClassifiedBag->Count){// not empty
	for (int cls=0;cls<ClassCount;cls++){
		float *clasavrg = ArrayListRowToAvrgArr(UnClassifiedBag,cls); 
		AddtoArrayList(ClassesAverages,clasavrg,col,cls);
		delete []clasavrg;

	}
												
//test UnClassifiedBag against trainig ClassesAverages 
	//classified row removed from UnClassifiedBag and get into ClassifiedBag
	int unclassified=UnClassifiedBag->Count;
	KnnLocaltestforTrainingAveragesOfSubClasses(UnClassifiedBag, ClassifiedBag, ClassesAverages);
	//update UnClassifiedBag
	for (int i=0;i<UnClassifiedBag->Count;i++){
		String ^ a999= safe_cast <String ^> (UnClassifiedBag[i]);
		//float a=Convert::ToDouble(a999);
		if (String::Compare(a999, "999999999999" )==0){
			UnClassifiedBag->RemoveAt(i);
			i--;
		}
	}

//remove the last updated averges for each class and replace them with 
	//the real averge of the realy classfied ppoints
	if (ClassifiedBag->Count>0){
		for (int cls=0;cls<ClassCount;cls++){
			ClassesAverages->RemoveAt(ClassesAverages->Count-1);//remove last one
			}
		//replace with real avrgs
		for (int cls=0;cls<ClassCount;cls++){
			float *clasavrg = ArrayListRowToAvrgArr(ClassifiedBag,cls); 
			AddtoArrayList(ClassesAverages,clasavrg,col,cls);
			delete []clasavrg;
		}
fromclassifiedtounclassifiedifnotwelclassifed(UnClassifiedBag, ClassifiedBag, ClassesAverages);
		ClassifiedBag->Clear();
	}
	else{	//stop condition
		nomoretoclassify=true;
	}
	
//	if (unclassified==UnClassifiedBag->Count)
//		nomoretoclassify=true;
}//end while
	if (TrainOut3){
		for (int i=0;i<NumberofRuns;i++)
			{delete TrainOut3[i]; TrainOut3[i]=0;}
		delete TrainOut3; TrainOut3=0;
	}

	NumberofRuns=ClassesAverages->Count/ClassCount;
	TrainOut3= new Mat*[NumberofRuns];
	for (int i=0;i<NumberofRuns;i++){
		TrainOut3[i]= new Mat(ClassCount,col);
	}
	//copy from arraylist to Mat
	for (int i=0;i<ClassesAverages->Count;i+=ClassCount)
	  for (int j=0;j<ClassCount;j++){
		String ^line= safe_cast <String ^> (ClassesAverages[i+j]);
				String^ delimStr= " ";
				array<Char>^ delimiter = delimStr->ToCharArray( );
				array<String^>^ WordsNumbers;
				WordsNumbers = line->Split(delimiter);
				int k;
				for(k=0;k<col;k++){
						TrainOut3[i/ClassCount]->set(j,k,Convert::ToDouble(WordsNumbers[k]));
				}
				TrainOut3[i/ClassCount]->classint[j] = Convert::ToInt32(WordsNumbers[k]);
	
				float dbl1=999999999999999.0;
				float dbl2=Convert::ToDouble(WordsNumbers[0]);
	  }
//update 9999999s
	  float dbl1=999999999999999.0;
	 for (int i=1;i<NumberofRuns;i++)
	  for (int j=0;j<ClassCount;j++)
		  if (TrainOut3[i]->get(j,0)==dbl1)
				for(int k=0;k<col;k++)
						TrainOut3[i]->set(j,k, TrainOut3[i-1]->get(j,k));



//remove the values where there was no classes in classes averages
	for (int i=0;i<ClassesAverages->Count;i++){
		String ^line= safe_cast <String ^> (ClassesAverages[i]);
				String^ delimStr= " ";
				array<Char>^ delimiter = delimStr->ToCharArray( );
				array<String^>^ WordsNumbers;
				WordsNumbers = line->Split(delimiter);
				float dbl1=999999999999999.0;
				float dbl2=Convert::ToDouble(WordsNumbers[0]);
				if(dbl1==dbl2){
					ClassesAverages->RemoveAt(i);
					i--;
				}
	}

	TrainOut= ArrayListToMat(ClassesAverages);

return ;
}
//end ........training averages of sub classes

//TEST TRAINIG AVRGS of sub classes
int  TestAveragesOfSubClasses(float datum[]){
	int row=TrainOut->Row(),  col=TrainOut->Col();
	int r,c;
	ClassCount=TrainOut->NumberOfClasses();
	
	float *distance = new float [ClassCount];
	//initilize dist
	for (int cls=0;cls<ClassCount;cls++)
		distance[cls]=0.0;
	//clac accumilated minimum float bet datum[i] and each col from all rows in TrainOut
	//for each class and add to distance[class]
	for (int cls=0;cls<ClassCount;cls++){
		for (long c=0;c<col;c++){
			long n;
			float *arr=TrainOut->getColOfClass(n,c,cls);
			if (n==0){
				distance[cls]=_MXD;
				c=col;
				break;
			}
			else {
				for (r=0;r<n;r++)
					arr[r]=Math::Abs(arr[r]-datum[c]);
				distance[cls]+=minofArr(arr,n);
				delete [] arr; arr=0;
			}
		}
	}

	// calc the minimum distanc of a class	
	int index=argmin(distance,ClassCount);

	delete [] distance; distance=0;
return index;
	}

int  TestAveragesOfSubClasses2(float datum[]){
	int row=TrainOut->Row(),  col=TrainOut->Col();
	int r,c;
	ClassCount=TrainOut->NumberOfClasses();
	
	float *distance = new float [row];
	//initilize dist
	for (int r=0;r<row;r++)
		distance[r]=0.0;
	//clac accumilated minimum float bet datum[i] and each col from all rows in TrainOut
	//for each class and add to distance[class]
	for (r=0;r<row;r++){
		switch (DistanceType){
			case 0: //ED
				for (c=0;c<col;c++)
					distance[r]+= Math::Pow(TrainOut->get(r,c)-datum[c],2.0);
				distance[r]=Math::Sqrt(distance[r]);
				break;
			case 1: //ED
				for (c=0;c<col;c++)
					distance[r]+= Math::Pow(TrainOut->get(r,c)-datum[c],2.0);
				break;
			case 2: //manhatin
				for (c=0;c<col;c++)
					distance[r]+= Math::Abs(TrainOut->get(r,c)-datum[c]);
				break;
		}
	}

	// calc the minimum distanc of a class	
	int index=argmin(distance,row);
	index=TrainOut->classint[index];
	delete [] distance; distance=0;
return index;
	}
//
//TEST TRAINIG AVRGS of sub classes using voting
int  TestAveragesOfSubClassesVote(float datum[]){
	int row=TrainOut3[0]->Row(),  col=TrainOut3[0]->Col();
	int r,c; //NumberofRuns
	ClassCount=TrainOut3[0]->NumberOfClasses();
	
	float *classes = new float [ClassCount];
	//initilize dist
	for (int cls=0;cls<ClassCount;cls++)
		classes[cls]=0.0;
	//clac accumilated minimum float bet datum[i] and each col from all rows in TrainOut
	//for each class and add to distance[class]
	for (int i=0;i<NumberofRuns;i++){
		float *arr=new float [row];
		for (int k=0;k<row;k++)
			arr[k]=0.0;
		for (r=0;r<row;r++){
			for (c=0;c<col;c++){
				arr[r]+=Math::Abs(TrainOut3[i]->get(r,c)-datum[c]);
			}
		}
		classes[argmin(arr,row)]++;
		delete [] arr; arr=0;
	}

	// calc the minimum distanc of a class	
	int index=argmax(classes,ClassCount);

	delete [] classes; classes=0;
return index;
	}

//----------end--TEST TRAINIG AVRGS of sub classes
//=================================================================================

// training GA train best examples
//local test

float KnnLocalTestGA(Mat * TestMat1, ArrayList ^GoodExamples){			 
	int row=TestMat1->Row();
	float sum=0.0;
	Mat * TrainMat1=ArrayListToMat(GoodExamples);
	for (int i=0;i<row;i++){
		float *testRow=new float[TestMat1->Col()];
		TestMat1->getRow(testRow,i);
		int cs=knn(TrainMat1,testRow,1);
		if (TestMat1->classint[i]==cs){
			sum++;
		}
		delete []testRow; testRow=0;
	}
	sum=sum/(float) row;
	delete TrainMat1;	TrainMat1=0;
	return sum;
}
///
//random eaxmple for each class
void AddRandomExampleFromEachClass(bool class0found, bool taken [], 
									Mat * trnMat1, ArrayList ^GoodExamples, Random ^rnd1){
//take random eaxmple for each class
	int row=trnMat1->Row(),  col=trnMat1->Col();
	int InitialClass;
	
	if (class0found)
		InitialClass=0;
	else
		InitialClass=1;

	for (int cls=InitialClass;cls<ClassCount;cls++){
		int tomuchirtrations=0;
nextrnd1:
		tomuchirtrations++;
			int rownum=rnd1->Next(0,row-1);
		//	if(tomuchirtrations < row && (taken[rownum] || trnMat1->classint[rownum]!= cls))
			if(tomuchirtrations < 2*row && trnMat1->classint[rownum]!= cls)
				goto nextrnd1;
			if(tomuchirtrations < 2 * row){
				float *example=new float [col];
				trnMat1->getRow(example,rownum); 
				AddtoArrayList(GoodExamples,example,col,cls);
				taken[rownum]=true;
				delete []example;
			}
	}
}
//training GA BestExamples
float  GATrainBestExamples(Mat *trnMat, int k){

	if (TrainOut){
		delete TrainOut; TrainOut=0;
	}
	ArrayList ^GoodExamples;

	int row=trnMat->Row(),  col=trnMat->Col();
	int i;//,r,c;
	ClassCount=trnMat->NumberOfClasses() ;
	GoodExamples= gcnew ArrayList();

	bool *taken=new bool [row];
	for (int i=0;i<row;i++){
		taken[i]=false;
	}
	bool class0found=false;
	for (i=0;i<row;i++){
		if (trnMat->classint[i]==0){
			class0found=true;
			i=row;
			break;
		}
	}
	int InitialClass;
	if (class0found)
		InitialClass=0;
	else
		InitialClass=1;
Random ^rnd1= gcnew Random(1234);
//initial genes
		AddRandomExampleFromEachClass(class0found,taken,trnMat,GoodExamples , rnd1);
float GaAccuracy=KnnLocalTestGA(trnMat,GoodExamples);
while (k){// GA iterations
	AddRandomExampleFromEachClass(class0found,taken,trnMat,GoodExamples , rnd1);								
	float accuracy=KnnLocalTestGA(trnMat,GoodExamples);
	if (accuracy <= GaAccuracy && GoodExamples->Count > ClassCount){
		for (int cls=InitialClass;cls<ClassCount;cls++){
			GoodExamples->RemoveAt(GoodExamples->Count-1);//remove last one
			}
	}
	else if (accuracy > GaAccuracy)
		GaAccuracy=accuracy;
	k--;
	if (GaAccuracy >0.99){
		k=0;
		break;
	}
}//end while

	TrainOut= ArrayListToMat(GoodExamples);
delete [] taken; taken=0;
return GaAccuracy;
}
//end ........training  GA train best examples 

//------------------------------------------------------
//  NN-centriods train best examples
void  NNTrainBestExamples(Mat *trnMat, int k){

	if (TrainOut){
		delete TrainOut; TrainOut=0;
	}
	ArrayList ^GoodExamples;

	int row=trnMat->Row(),  col=trnMat->Col();
	int i,r,c;
	ClassCount=trnMat->NumberOfClasses() ;
	GoodExamples= gcnew ArrayList();

	bool class0found=false;
	for (i=0;i<row;i++){
		if (trnMat->classint[i]==0){
			class0found=true;
			i=row;
			break;
		}
	}
	int InitialClass;
	if (class0found)
		InitialClass=0;
	else
		InitialClass=1;
//initiallize averages 

	Mat * TrainOutAvrg= new Mat(ClassCount,col);
	float *classcounter = new float [ClassCount];

	//intialize classes counters and TrainOut matrix
	for (int cls=0;cls<ClassCount;cls++){
		classcounter[cls]=0.0;
		for (c=0;c<col;c++){
			TrainOutAvrg->set(cls,c,0.0);
		}


	}
	// accumilate vectors for each class
	for (r=0;r<row;r++){
		int cls=trnMat->classint[r];
		for (c=0;c<col;c++){
			TrainOutAvrg->set(cls,c,TrainOutAvrg->get(cls,c)+ trnMat->get(r,c));
		}
		classcounter[cls]++;
	}
	//calc average vector of each class
	for (int cls=0;cls<ClassCount;cls++){
		
		if (classcounter[cls]!=0.0)
			for (c=0;c<col;c++){
				TrainOutAvrg->set(cls,c,TrainOutAvrg->get(cls,c)/ classcounter[cls]);
			}
		else
			for (c=0;c<col;c++){
				TrainOutAvrg->set(cls,c,99999999999999999999999999.0);
			}
	}

	delete [] classcounter; classcounter=0;

// end initilize avrg
	float *Accuracy = new float[row];
//	for each eaxmple do
		float *example=new float [col];
		for (r=0;r<row;r++){
			trnMat->getRow(example,r); 
			int CurrentClass=trnMat->classint[r];
			AddtoArrayList(GoodExamples,example,col,CurrentClass);
			for (int cls=InitialClass;cls<ClassCount;cls++){
				if (cls != CurrentClass){
					TrainOutAvrg->getRow(example,cls);
					AddtoArrayList(GoodExamples,example,col,cls);
				}
			}
			Accuracy[r]=KnnLocalTestGA(trnMat,GoodExamples);
		//	Accuracy[r].v2=trnMat->classint[r];
			GoodExamples->Clear();
		}

//fill good exapmles with the maximum accuracy eaxmples
	int *NumExamples= new int [ClassCount];
	for (int cls=0;cls<ClassCount;cls++){
		NumExamples[cls]=0;
	}

bool stop=false;
while (!stop){
	int index=argmax(Accuracy,row);
	Accuracy[index]= -99999999999999999.0;
	trnMat->getRow(example,index); 
	int CurrentClass=trnMat->classint[index];
	if (NumExamples[CurrentClass]<k){
		AddtoArrayList(GoodExamples,example,col,CurrentClass);
		NumExamples[CurrentClass]++;
	}
	bool more=false;
	for (int cls=InitialClass;cls<ClassCount;cls++){
		if (NumExamples[cls]<k)
			more=true;
	}
	if (!more)
		stop=true;
}

			TrainOut= ArrayListToMat(GoodExamples);

delete TrainOutAvrg; TrainOutAvrg=0;
delete [] NumExamples; NumExamples=0;
delete [] Accuracy; Accuracy=0;
delete [] example; example=0; 
return ;
}
//end ........training  NN-centriods train best examples 
//-------------------------------------------------------------




////train using minimum float to get boundary points
String ^  MinDistanceBoundaryPoints(Mat *trnMat, int k){

	if (TrainOut){
		delete TrainOut; TrainOut=0;
	}
	ArrayList ^GoodExamples;

	int row=trnMat->Row(),  col=trnMat->Col();
	int i,j,c;
	ClassCount=trnMat->NumberOfClasses() ;
	GoodExamples= gcnew ArrayList();



	bool class0found=false;
	for (int i=0;i<row;i++){
		if (trnMat->classint[i]==0){
			class0found=true;
			i=row;
			break;
		}
	}
	int InitialClass;
	if (class0found)
		InitialClass=0;
	else
		InitialClass=1;
int *pointshist= new int [row];
for (int i=0;i<row;i++){
	pointshist[i]=0;
}
float distance;
	for (int cls1=InitialClass; cls1<ClassCount; cls1++){
		for (int cls2=InitialClass; cls2<ClassCount; cls2++){
			if (cls1!=cls2){
				for ( i=0;i<row;i++){
					float Mindist= _MXD;
					int index=-1;
					for ( j=0;j<row;j++){
						if (i!=j){
							if ((trnMat->classint[i]==cls1) && (trnMat->classint[j]==cls2)){
								distance=0.0;
								for ( c=0;c<col;c++)
									distance += Math::Pow(trnMat->get(i,c)-trnMat->get(j,c),2.0);
								if (distance <Mindist){
									Mindist= distance;
									index=j;
								}

							}
						}
					}
					//if ((i!=j) && (cls1!=cls2))
					//if (index==-1)
					//	MessageBox::Show(String::Concat(i.ToString(), "    ",j.ToString()));
					if (trnMat->classint[i]==cls1)
						pointshist[index]++;
				}
			}
		}
	}


//move boundary points (non zero votes) to good example 
if (k==0)
	for (int i=0;i<row;i++){
		if (pointshist[i]){
			float *testRow=new float[col];
			trnMat->getRow(testRow,i);
			AddtoArrayList(GoodExamples,testRow,col,trnMat->classint[i]);
			delete [] testRow; testRow=0;
			}
	}
//end move
//demo
	String ^str1=gcnew String("");

	for (int i=0;i<row;i++){
		str1=String::Concat(str1,pointshist[i].ToString(),"\t");
	}
//k>0
//get the  k point with hieghest votes
if (k>0)
	for (int i=0;i<k;i++){
		int index=argmax(pointshist,row);
		pointshist[index]= -99999999999999999.0;
			float *testRow=new float[col];
			trnMat->getRow(testRow,index);
			AddtoArrayList(GoodExamples,testRow,col,trnMat->classint[index]);
			delete [] testRow; testRow=0;
	}
//copy good examples to trainout
	if (TrainOut){
		delete TrainOut; TrainOut=0;
	}
	TrainOut= ArrayListToMat(GoodExamples);

	delete [] pointshist;
	return str1;
}
//end ........training  MinfloatBoundaryPoints 

//training GA BestExamples
float  GATrainBestExamplesofMDBP(Mat *trnMat, int k){
	//input trainout
	//output trainout1

	if (TrainOut1){
		delete TrainOut1; TrainOut1=0;
	}
	ArrayList ^GoodExamples;

	int row=TrainOut->Row(),  col=TrainOut->Col();
	int i;//,r,c;
	ClassCount=TrainOut->NumberOfClasses() ;
	GoodExamples= gcnew ArrayList();

	bool *taken=new bool [row];
	for (int i=0;i<row;i++){
		taken[i]=false;
	}
	bool class0found=false;
	for (i=0;i<row;i++){
		if (trnMat->classint[i]==0){
			class0found=true;
			i=row;
			break;
		}
	}
	int InitialClass;
	if (class0found)
		InitialClass=0;
	else
		InitialClass=1;
Random ^rnd1= gcnew Random(1234);
//initial genes
		AddRandomExampleFromEachClass(class0found,taken,TrainOut,GoodExamples , rnd1);
float GaAccuracy=KnnLocalTestGA(trnMat,GoodExamples);
while (k){// GA iterations
	AddRandomExampleFromEachClass(class0found,taken,TrainOut,GoodExamples , rnd1);								
	float accuracy=KnnLocalTestGA(trnMat,GoodExamples);
	if (accuracy <= GaAccuracy && GoodExamples->Count > ClassCount){
		for (int cls=InitialClass;cls<ClassCount;cls++){
			GoodExamples->RemoveAt(GoodExamples->Count-1);//remove last one
			}
	}
	else if (accuracy > GaAccuracy)
		GaAccuracy=accuracy;
	k--;
	if (GaAccuracy >0.99){
		k=0;
		break;
	}
}//end while

	TrainOut1= ArrayListToMat(GoodExamples);
delete [] taken; taken=0;
return GaAccuracy;
}
//end ........training  GA train best examples 
