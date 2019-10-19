//{{NO_DEPENDENCIES}}
// Microsoft Visual C++ generated include file.
// Used by app.rc

/*
done good results
knn: take the minimum distances and go down until you get all the classes : now majority role
done
knn: take the Maimim distances and go up until you get all the classes : now minority role
done
knn: take the Maimim  and maximum distances for each class average them and take the class of the min verage 
///
Knn: train: sort all fvs for each class depending on the summation of the FV, 
then take the average of each consequitive pairs, and the average of the consequitive averages
until reaching to one average fv, consider the last 3 levels (7 fvs) tp represents the class
test: use Knn(k=7) on the trained output model.
////
done by someone---
sub classes: use clustering algorithm to cluster fvs to subclasses and take the average vectors
of these sub classes to represent each class 
///
Done--good results
genatic algorithm to find the best FV to represent each class
take randomly a number of fv for each class, classify trainnig data using these feature vectors
fitness function is the maximum accuricey, keep good fvs, 
cross-over: rplace with other fv of the same class
mutation, increament and decremnet by a smal fraction on randomly chosen feature.
//done good results
another method: take for each fv for each class , use this feature vector as a centroid, use the average as centroid
for other classes, test trainig set based on these m fvs and record the accuricy, consider the feature vectors of 
the maximu classifying accuricy to represent their clsses in the training model
//
to determine the best Feature:
remove the first feature from all FVs, 
for each example use knn to test it against the rest training data,
do this for all examples and get the over all accuracey for F1
do the same for the other Fs
when the accuracy is max this means the selected F is not good enough
give the feature with the maximum accuracy the min weight =1-(its acuracey/sum(all accuracies) )
we get m weight , one for each F
now use the weighted ED with KNN...or any alternative
//
another one using chi square to approximate each Feature weught

/////////////
use linear regression for each class to find the line that best fit all points withen 
a class.
represent each ..... line is not good for multi dimensions


///////////////////
training averages of sub classes// done
1- take all the average of each class
2- classify all points based on the averages of each class
3- any point does not classified well remove it from the class bag and put it in the unknown class i bag
4- take the new average again and classify the rest of the points until no more fvs are moving to unknown bags
5- the resulting averages are to be used in the model later
now go to the unknown bags of each class until now more fv in all unknown bags 
//////////////
FOR EACH POINT CLACL THE AVERGAE DISTANCES TO ALL POINTS IN ITS CLASS
TAKE THE MINIMUM K POINTS TO REPRESENT CLASS

*/

/*
Custering algorithm
1- calculate the distance between each point(fv) we get n sqr/2 to get struct of 2 points and 
	the distance between them
2- sort all points based on the distance 
3- get the first k points that include all points
4- insert each point into a different class list class1,class2, ..., classk
5- 
==================================
//new classification
1- each time take only two feature x,y
2- find the best line (regression ) to seprate classes 
3- do the same for all pairs of features
4- use the output lines for decesion in testing 
=====
//classification
work on the trainig data of each class and do
1- find the eignen vectors for the data using PCA
2- take the first n eigne vectors to represent the class
===
usee LDA to the previous


*/
