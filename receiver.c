#include "receiver.h"
#include <stdio.h>

void getSingleStreamOfValues(int dataStream[])
{
    int idx;
    scanf("%*s", &dataStream); // Skip parameter string at beginning of stream
    for (idx = 0; idx < STREAM_LENGTH; idx++)
    {
        scanf("%i", &dataStream[idx]);
    }
}

int getMinValueFromStream(int * dataStream)
{
    int idx;
    int minValue = MAX_VALUE;

    for (idx = 0; idx < STREAM_LENGTH; idx++)
    {
        if (*dataStream < minValue)
        {
            minValue = *dataStream;
        }
        dataStream++;
    }
    return minValue;
}

int getMaxValueFromStream(int * dataStream)
{
    int idx;
    int maxValue = MIN_VALUE;

    for (idx = 0; idx < STREAM_LENGTH; idx++)
    {
        if (*dataStream > maxValue)
        {
            maxValue = *dataStream;
        }
        dataStream++;
    }
    return maxValue;
}

float getAverageFromLastFiveStreamValues(int * dataStream)
{
    int idx;
    float average = 0;

    for (idx = 0; idx < 5; idx++)
    {
        average += *(dataStream + (STREAM_LENGTH - 5));
        dataStream++;
    }
    average = average/5;
    return average;
}
