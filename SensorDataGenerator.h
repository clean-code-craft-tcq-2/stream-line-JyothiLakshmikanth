#include <iostream>
#include <random>
#include <map>
#include <vector>
#include<random>

#define MAX 100
#define MIN 0
#define NUMBER_OF_Readings 50

using namespace std;

typedef enum
{
  TEMPERATURE,
  CURRENT,
  VOLTAGE
}Senors;

static const char *sensor_str[] =
        { "TEMPERATURE", "CURRENT", "VOLTAGE" };

typedef ::std::map<Senors, ::std::vector<int>> T_SenorReadings;

class SensorDataGenerator
{
public:
    static T_SenorReadings getTheSenorReadings();
private:
    static T_SenorReadings prepareSensorReadingsMap();
    static ::std::vector< int> generateTheReadings();
    static T_SenorReadings m_sensorReadingsMap;
};
T_SenorReadings SensorDataGenerator::getTheSenorReadings()
{
  return m_sensorReadingsMap;
}

T_SenorReadings SensorDataGenerator::m_sensorReadingsMap = prepareSensorReadingsMap();

T_SenorReadings SensorDataGenerator::prepareSensorReadingsMap()
 {
     T_SenorReadings sensorReadingsMap;
   sensorReadingsMap[TEMPERATURE] = generateTheReadings();
   sensorReadingsMap[CURRENT] = generateTheReadings();
  sensorReadingsMap[VOLTAGE] = generateTheReadings();
   return sensorReadingsMap;
 }

::std::vector< int> SensorDataGenerator::generateTheReadings()
{
  ::std::vector< int> readings;
  std::random_device rd; // obtain a random number from hardware
  std::mt19937 gen(rd()); // seed the generator
  std::uniform_int_distribution<> distr(MIN, MAX); // define the range
  for(int n=0; n<NUMBER_OF_Readings; ++n)
  {
    readings.push_back(distr(gen));
  }
  return readings;
}
