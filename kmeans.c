#include "kmeans.h"

void readDatapoints(Datapoint *datapoints, char *filename)
{
    FILE *fp;
    fp = fopen(filename, "r");
    int num;
    int turn = 0, i = 0;
    while (fscanf(fp, "%d", &num) != EOF)
    {
        if (turn == 0)
        {
            datapoints[i].x = num;
            turn = 1;
        }
        else
        {
            datapoints[i].y = num;
            i++;
            turn = 0;
        }
    }
    fclose(fp);
}

double distance(Datapoint datapoint, Centroid centroid)
{
    double distance = sqrt(pow((centroid.x - datapoint.x), 2) + pow((centroid.y - datapoint.y), 2));
    return distance;
}

void average(Datapoint *datapoint, Centroid *centroids, int datapoints_num, int k)
{
    Centroid newCentroids[k];
    int amount[k];
    for (int i = 0; i < k; i++)
    {
        newCentroids[i].x = 0.0;
        newCentroids[i].y = 0.0;
        amount[i] = 0;
    }
    for (int i = 0; i < datapoints_num; i++)
    {
        int cluster = datapoint[i].cluster;
        newCentroids[cluster - 1].x += datapoint[i].x;
        newCentroids[cluster - 1].y += datapoint[i].y;
        amount[cluster - 1]++;
    }
    for (int i = 0; i < k; i++)
    {
        newCentroids[i].x /= amount[i];
        newCentroids[i].y /= amount[i];
        centroids[i].x = newCentroids[i].x;
        centroids[i].y = newCentroids[i].y;
    }
}

void kMeans(Datapoint *datapoints, Centroid *centroids, int datapoints_num, int k, int maxIterations)
{
    for (int i = 0; i < maxIterations; i++)
    {
        for (int j = 0; j < datapoints_num; j++)
        {
            double min = FLT_MAX;
            int cluster = 0;
            for (int h = 0; h < k; h++)
            {
                double d = distance(datapoints[j], centroids[h]);
                if (d <= min)
                {
                    min = d;
                    cluster = h + 1;
                }
            }
            datapoints[j].cluster = cluster;
        }
        average(datapoints, centroids, datapoints_num, k);
    }
}

void printDatapoints(Datapoint *datapoints, Centroid *centroids)
{
    for (int i = 0; i < K; i++)
    {
        printf("Data Points assigned to Cluster #%d:\n", i + 1);
        for (int j = 0; j < DATAPOINTS_NUM; j++)
        {
            if (datapoints[j].cluster == i + 1)
            {
                printf("%d, ", j + 1);
            }
        }
        printf("\n\n");
    }
    printf("Final Centroids after convergence:\n");
    for (int i = 0; i < K; i++)
    {
        printf("Centroid %d: (%.2f, %.2f)\n", i + 1, centroids[i].x, centroids[i].y);
    }
    printf("\n");
}