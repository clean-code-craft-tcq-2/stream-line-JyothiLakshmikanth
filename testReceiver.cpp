#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file

#include "test/catch.hpp"
#include "receiver.h"

int temperatureDataStream[STREAM_LENGTH];
int currentDataStream[STREAM_LENGTH];
int voltageDataStream[STREAM_LENGTH];

TEST_CASE("Test reading the stream of values of all parameters (verify console output)")
{
    int idx;

    getSingleStreamOfValues(&temperatureDataStream[0]);
    getSingleStreamOfValues(&currentDataStream[0]);
    getSingleStreamOfValues(&voltageDataStream[0]);

    printf("TEMPERATURE");
    for (idx = 0; idx < STREAM_LENGTH; idx++)
    {
        printf(" %i", temperatureDataStream[idx]);
    }
    printf("\n");

    printf("CURRENT");
    for (idx = 0; idx < STREAM_LENGTH; idx++)
    {
        printf(" %i", currentDataStream[idx]);
    }
    printf("\n");

    printf("VOLTAGE");
    for (idx = 0; idx < STREAM_LENGTH; idx++)
    {
        printf(" %i", voltageDataStream[idx]);
    }
    printf("\n");
}

TEST_CASE("Test correct range of values is received (0-100) for each parameter")
{
    int idx;

    for (idx = 0; idx < STREAM_LENGTH; idx++)
    {
        REQUIRE(temperatureDataStream[idx] >= MIN_VALUE);
        REQUIRE(temperatureDataStream[idx] <= MAX_VALUE);
        REQUIRE(currentDataStream[idx] >= MIN_VALUE);
        REQUIRE(currentDataStream[idx] <= MAX_VALUE);
        REQUIRE(voltageDataStream[idx] >= MIN_VALUE);
        REQUIRE(voltageDataStream[idx] <= MAX_VALUE);
    }
}


TEST_CASE("Get minimum and maximum values for each parameter")
{
    int idx;

    REQUIRE(getMinValueFromStream(&temperatureDataStream[0])== 0);
    REQUIRE(getMaxValueFromStream(&temperatureDataStream[0]) == 98);
    REQUIRE(getMinValueFromStream(&currentDataStream[0]) == 0);
    REQUIRE(getMaxValueFromStream(&currentDataStream[0]) == 98);
    REQUIRE(getMinValueFromStream(&voltageDataStream[0]) == 0);
    REQUIRE(getMaxValueFromStream(&voltageDataStream[0]) == 98);

    printf("Temperature MIN value - %i\n", getMinValueFromStream(&temperatureDataStream[0]));
    printf("Temperature MAX value - %i\n", getMaxValueFromStream(&temperatureDataStream[0]));
    printf("Current MIN value - %i\n", getMinValueFromStream(&currentDataStream[0]));
    printf("Current MAX value - %i\n", getMaxValueFromStream(&currentDataStream[0]));
    printf("Voltage MIN value - %i\n", getMinValueFromStream(&voltageDataStream[0]));
    printf("Voltage MAX value - %i\n", getMaxValueFromStream(&voltageDataStream[0]));
}

TEST_CASE("Get simple moving average (last 5 values) for each parameter")
{
    int idx;

    REQUIRE(getAverageFromLastFiveStreamValues(&temperatureDataStream[0]) == 52);
    REQUIRE(getAverageFromLastFiveStreamValues(&currentDataStream[0]) == 52);
    REQUIRE(getAverageFromLastFiveStreamValues(&voltageDataStream[0]) == 52);

    printf("Temperature SMA - %.2f\n", getAverageFromLastFiveStreamValues(&temperatureDataStream[0]));
    printf("Current SMA - %.2f\n", getAverageFromLastFiveStreamValues(&currentDataStream[0]));
    printf("Voltage SMA - %.2f\n", getAverageFromLastFiveStreamValues(&voltageDataStream[0]));
}

