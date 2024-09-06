#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <float.h>

#define K 3
#define DATAPOINTS_NUM 500
#define MAX_ITERATIONS 100

typedef struct
{
    double x;
    double y;
    int cluster;
} Datapoint;

typedef struct
{
    double x;
    double y;
} Centroid;

void readDatapoints(Datapoint *datapoints, char *filename);
double distance(Datapoint datapoint, Centroid centroid);
void average(Datapoint *datapoint, Centroid *centroids, int datapoints_num, int k);
void kMeans(Datapoint *datapoints, Centroid *centroids, int datapoints_num, int k, int maxIterations);
void printDatapoints(Datapoint *datapoints, Centroid *centroids);