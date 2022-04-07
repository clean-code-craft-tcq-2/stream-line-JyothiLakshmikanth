#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "test/catch.hpp"

#define private public
#include "Sender.h"

using namespace std;

TEST_CASE("Check_Print_Sensor_Data_OnConsole")
{
  getAndPrintSensorDataOnConsole(&SensorDataGenerator::getTheSenorReadings, &printOnConsole);
  T_SenorReadings::const_iterator sensorReadingsIt = m_sensorReadings.begin();
  for(; sensorReadingsIt != m_sensorReadings.end(); ++sensorReadingsIt)
  {
    ::std::vector<int> readings = sensorReadingsIt->second;
      REQUIRE(readings.size() == NUMBER_OF_Readings)
  }

}
