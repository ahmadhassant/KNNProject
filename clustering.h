#include <stdlib.h>
#include <assert.h>
#include <float.h>
#include <math.h>

#include <stdio.h>
using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::IO;

//Kmean clustering==========================


//   int *k_means(double**, int, int, int, double, double**);

int *k_means(float **data, int n, int m, int k, float t, float **centroids)
{
   /* output cluster label for each data point */
   int *labels = (int*)calloc(n, sizeof(int));

   int h, i, j; /* loop counters, of course :) */
   int *counts = (int*)calloc(k, sizeof(int)); /* size of each cluster */
   float old_error, error = DBL_MAX; /* sum of squared euclidean distance */
   float **c = centroids ? centroids : (float**)calloc(k, sizeof(float*));
   float **c1 = (float**)calloc(k, sizeof(float*)); /* temp centroids */

   assert(data && k > 0 && k <= n && m > 0 && t >= 0); /* for debugging */

   /*******************************************
   ************* initialization ***************
   ********************************************/

   for (h = i = 0; i < k; h += n / k, i++) {
      c1[i] = (float*)calloc(m, sizeof(float));
      if (!centroids) {
         c[i] = (float*)calloc(m, sizeof(float));
      }
      /* pick k points as initial centroids */
      for (j = m; j-- > 0; c[i][j] = data[h][j]);
   }

   /****
   ** main loop */

   do {
      /* save error from last step */
      old_error = error, error = 0;

      /* clear old counts and temp centroids */
      for (i = 0; i < k; counts[i++] = 0) {
         for (j = 0; j < m; c1[i][j++] = 0);
      }

      for (h = 0; h < n; h++) {
         /* identify the closest cluster */
         float min_distance = DBL_MAX;
         for (i = 0; i < k; i++) {
            float distance = 0;
            for (j = m; j-- > 0; distance += pow(data[h][j] - c[i][j], 2));
            if (distance < min_distance) {
               labels[h] = i;
               min_distance = distance;
            }
         }
         /* update size and temp centroid of the destination cluster */
         for (j = m; j-- > 0; c1[labels[h]][j] += data[h][j]);
         counts[labels[h]]++;
         /* update standard error */
         error += min_distance;
      }

      for (i = 0; i < k; i++) { /* update all centroids */
         for (j = 0; j < m; j++) {
            c[i][j] = counts[i] ? c1[i][j] / counts[i] : c1[i][j];
         }
      }

   } while (fabs(error - old_error) > t);

   /****
   ** housekeeping */

   for (i = 0; i < k; i++) {
      if (!centroids) {
         free(c[i]);
      }
      free(c1[i]);
   }

   if (!centroids) {
      free(c);
   }
   free(c1);

   free(counts);

   return labels;
}
//end of k-mean eucleadian
int *k_meansHas(float **data, int n, int m, int k, float t, float **centroids)
{
   /* output cluster label for each data point */
   int *labels = (int*)calloc(n, sizeof(int));

   int h, i, j; /* loop counters, of course :) */
   int *counts = (int*)calloc(k, sizeof(int)); /* size of each cluster */
   float old_error, error = DBL_MAX; /* sum of squared euclidean distance */
   float **c = centroids ? centroids : (float**)calloc(k, sizeof(float*));
   float **c1 = (float**)calloc(k, sizeof(float*)); /* temp centroids */

   assert(data && k > 0 && k <= n && m > 0 && t >= 0); /* for debugging */

   /*******************************************
   ************* initialization ***************
   ********************************************/

   for (h = i = 0; i < k; h += n / k, i++) {
      c1[i] = (float*)calloc(m, sizeof(float));
      if (!centroids) {
         c[i] = (float*)calloc(m, sizeof(float));
      }
      /* pick k points as initial centroids */
      for (j = m; j-- > 0; c[i][j] = data[h][j]);
   }

   /****
   ** main loop */

   do {
      /* save error from last step */
      old_error = error, error = 0;

      /* clear old counts and temp centroids */
      for (i = 0; i < k; counts[i++] = 0) {
         for (j = 0; j < m; c1[i][j++] = 0);
      }

      for (h = 0; h < n; h++) {
         /* identify the closest cluster */
         float min_distance = DBL_MAX;
         for (i = 0; i < k; i++) {
            float distance = 0.0;
		for (j = m; j-- > 0; 

					(Math::Min(data[h][j],c[i][j])<0) ? 
						distance+= 1.0 -
						(1+ Math::Min(data[h][j],c[i][j])+ Math::Abs(Math::Min(data[h][j],c[i][j])))/
					(float)    (1+ Math::Max(data[h][j],c[i][j])+ Math::Abs(Math::Min(data[h][j],c[i][j])))
						: distance += 1.0 -(1+ Math::Min(data[h][j],c[i][j]))/
					                        (float) (1+ Math::Max(data[h][j],c[i][j]))
			);
            if (distance < min_distance) {
               labels[h] = i;
               min_distance = distance;
            }
         }
         /* update size and temp centroid of the destination cluster */
         for (j = m; j-- > 0; c1[labels[h]][j] += data[h][j]);
         counts[labels[h]]++;
         /* update standard error */
         error += min_distance;
      }

      for (i = 0; i < k; i++) { /* update all centroids */
         for (j = 0; j < m; j++) {
            c[i][j] = counts[i] ? c1[i][j] / counts[i] : c1[i][j];
         }
      }

   } while (fabs(error - old_error) > t);

   /****
   ** housekeeping */

   for (i = 0; i < k; i++) {
      if (!centroids) {
         free(c[i]);
      }
      free(c1[i]);
   }

   if (!centroids) {
      free(c);
   }
   free(c1);

   free(counts);

   return labels;
}

//====================================================
// scale  matrix data
void ScaleFrom0To(float **data, int row, int col, float ScaleTo){
	//this function scale data in  amtrix from 0 to ScaleTo .

	int r,c;
	for (c=0;c<col;c++){
		float MaxV=-9999999999.0; float MinV=9999999999.0;
			for (r=0;r<row;r++){
				if (data[r][c]<MinV)
					MinV=data[r][c];
				if (data[r][c]>MaxV)
					MaxV=data[r][c];
			}
			for (r=0;r<row;r++)
				if (MaxV==MinV)
					data[r][c]=MaxV;
				else
                    data[r][c]=(data[r][c]-MinV)*ScaleTo/(MaxV-MinV);
		}// next column

}// end scale  matrix data

//====================================================
// scale  array data
void ScaleFrom0To(float *data, int row, float ScaleTo){
	//this function scale data in  array from 0 to ScaleTo .
	int r;
		float MaxV=-9999999999; float MinV=9999999999;
			for (r=0;r<row;r++){
				if (data[r]<MinV)
					MinV=data[r];
				if (data[r]>MaxV)
					MaxV=data[r];
			}
	for (r=0;r<row;r++)
		if (MaxV==MinV)
			data[r]=MaxV;
		else
			data[r]=(data[r]-MinV)*ScaleTo/(MaxV-MinV);

}// end scale  matrix data


////////////////////////////////////////////////////////////////////
//=======================================farthest and nearest points =====
// A divide and conquer program in C/C++ to find the smallest distance from a
// given set of points.
 

 
// A structure to represent a Point in 2D plane
struct point
{
    int x, y;
};
 
/* Following two functions are needed for library function qsort().
   Refer: http://www.cplusplus.com/reference/clibrary/cstdlib/qsort/ */
 
// Needed to sort array of points according to X coordinate
int compareX(const void* a, const void* b)
{
    point *p1 = (point *)a,  *p2 = (point *)b;
    return (p1->x - p2->x);
}
// Needed to sort array of points according to Y coordinate
int compareY(const void* a, const void* b)
{
    point *p1 = (point *)a,   *p2 = (point *)b;
    return (p1->y - p2->y);
}
 
// A utility function to find the distance between two points
float dist(point p1, point p2)
{
	return Math::Sqrt ( (p1.x - p2.x)*(p1.x - p2.x) +
                 (p1.y - p2.y)*(p1.y - p2.y)
               );
}
 
// A Brute Force method to return the smallest distance between two points
// in P[] of size n
float bruteForce(point P[], int n)
{
    float min = FLT_MAX;
    for (int i = 0; i < n; ++i)
        for (int j = i+1; j < n; ++j)
            if (dist(P[i], P[j]) < min)
                min = dist(P[i], P[j]);
    return min;
}
 
// A utility function to find minimum of two float values
float min(float x, float y)
{
    return (x < y)? x : y;
}
 
 
// A utility function to find the distance beween the closest points of
// strip of given size. All points in strip[] are sorted accordint to
// y coordinate. They all have an upper bound on minimum distance as d.
// Note that this method seems to be a O(n^2) method, but it's a O(n)
// method as the inner loop runs at most 6 times
float stripClosest(point strip[], int size, float d)
{
    float min = d;  // Initialize the minimum distance as d
 
    qsort(strip, size, sizeof(point), compareY); 
 
    // Pick all points one by one and try the next points till the difference
    // between y coordinates is smaller than d.
    // This is a proven fact that this loop runs at most 6 times
    for (int i = 0; i < size; ++i)
        for (int j = i+1; j < size && (strip[j].y - strip[i].y) < min; ++j)
            if (dist(strip[i],strip[j]) < min)
                min = dist(strip[i], strip[j]);
	delete [] strip;
    return min;
}
 
// A recursive function to find the smallest distance. The array P contains
// all points sorted according to x coordinate
float closestUtil(point P[], int n)
{
    // If there are 2 or 3 points, then use brute force
    if (n <= 3)
        return bruteForce(P, n);
 
    // Find the middle point
    int mid = n/2;
    point midPoint = P[mid];
 
    // Consider the vertical line passing through the middle point
    // calculate the smallest distance dl on left of middle point and
    // dr on right side
    float dl = closestUtil(P, mid);
    float dr = closestUtil(P + mid, n-mid);
 
    // Find the smaller of two distances
    float d = min(dl, dr);
 
    // Build an array strip[] that contains points close (closer than d)
    // to the line passing through the middle point
    point *strip= new point[n];
    int j = 0;
    for (int i = 0; i < n; i++)
        if (abs(P[i].x - midPoint.x) < d)
            strip[j] = P[i], j++;
 
    // Find the closest points in strip.  Return the minimum of d and closest
    // distance is strip[]
    return min(d, stripClosest(strip, j, d) );
}
 
// The main functin that finds the smallest distance
// This method mainly uses closestUtil()
float closest(point P[], int n)
{
    qsort(P, n, sizeof(point), compareX);
 
    // Use recursive function closestUtil() to find the smallest distance
    return closestUtil(P, n);
}
 
// Driver program to test above functions
/*int main()
{
    Point P[] = {{2, 3}, {12, 30}, {40, 50}, {5, 1}, {12, 10}, {3, 4}};
    int n = sizeof(P) / sizeof(P[0]);
    printf("The smallest distance is %f ", closest(P, n));
    return 0;
}*/

