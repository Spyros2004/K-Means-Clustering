#include "kmeans.h"

int main()
{
    Datapoint *datapoints = (Datapoint *)malloc(DATAPOINTS_NUM * sizeof(Datapoint));
    readDatapoints(datapoints, "input.txt");
    Centroid centroids[K] = {{26, 62}, {78, 13}, {65, 48}};
    kMeans(datapoints, centroids, DATAPOINTS_NUM, K, MAX_ITERATIONS);
    printDatapoints(datapoints, centroids);
    return 0;
}