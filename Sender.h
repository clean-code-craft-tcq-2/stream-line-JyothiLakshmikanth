#include <iostream>
#include <string>
#include <bits/stdc++.h>
#include "SensorDataGenerator.h"

using namespace std;

T_SenorReadings m_sensorReadings;

::string prepareCSVOuptput(T_SenorReadings sensorReadings)
{
  ::string outputStream;
   T_SenorReadings::const_iterator sensorReadingsIt = sensorReadings.begin();
  char space = ' ';
   for(; sensorReadingsIt != sensorReadings.end(); ++sensorReadingsIt)
   {
     outputStream.append((sensor_str[sensorReadingsIt->first]));
     outputStream += space;
     ::std::vector<int> readings = sensorReadingsIt->second;
     for(int i = 0; i<readings.size(); ++i)
     {
       outputStream.append(::std::to_string(readings[i]));
       outputStream += space;
     }
     outputStream.append("\n");
   }
   return outputStream;
}

void printOnConsole(::string outputStream)
{
    ::cout<<outputStream<<endl;
}

void getAndPrintSensorDataOnConsole(T_SenorReadings(*fn_ptr)(), void(*printFn_ptr)(::string))
{
    m_sensorReadings = fn_ptr();
    ::string outputStream = prepareCSVOuptput(m_sensorReadings);
    printFn_ptr(outputStream);
}
