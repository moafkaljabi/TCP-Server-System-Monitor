#pragma once 

#include "main.h"

class SystemMonitor {

public:
  SystemMonitor() = default ;
  ~SystemMonitor() = default;
  
  std::string getSystemStatsJSON();


private:
    std::string getCPUInfo();
    std::string getMemoryUsage();
};