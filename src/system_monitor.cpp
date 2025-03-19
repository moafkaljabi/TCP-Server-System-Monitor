/*

2025
Moafk Aljabi

TCP Servr for system monitoring


*/

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

#include "system_monitor.h"



// Implement the get_xx functions 


std::string get_cpu_info()
{
    // Read 
    std::ifstream stat_file("/proc/stat");
    std::string line;

    std::getline(stat_file, line);

    return line;
}

std::string SystemMonitor::getMemoryUsage()
{
    // Read
    std::ifstream meminfo_file("/proc/meminfo");
    std::string line;

    std::getline(meminfo_file, line);

    return line;
}


std::string get_system_stats()
{
    std::ostringstream stats;

    stats << "{"
            << "\"cpu\": \"" << get_cpu_info() << "\" , "
            << "\"ram\": \""  << getMemoryUsage() << "\""
            << "}";

    return stats.str();
}