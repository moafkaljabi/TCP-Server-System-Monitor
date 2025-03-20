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


std::string SystemMonitor::getCPUInfo()
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


// std::string SystemMonitor::getSystemStatsJSON()
// {
//     std::ostringstream stats;

//     stats << "{"
//             << "\"cpu\": \"" << getCPUInfo() << "\" , "
//             << "\"ram\": \""  << getMemoryUsage() << "\""
//             << "}";

//     return stats.str();
// }


std::string SystemMonitor::getSystemStatsJSON() 
{
        // Create a RapidJSON Document
        rapidjson::Document doc;
        doc.SetObject();
        rapidjson::Document::AllocatorType& allocator = doc.GetAllocator();
    
        std::string cpu = getCPUInfo();
        std::string ram = getMemoryUsage();
    
        doc.AddMember("cpu", rapidjson::Value(cpu.c_str(), allocator), allocator);
        doc.AddMember("ram", rapidjson::Value(ram.c_str(), allocator), allocator);
    
        // Convert to JSON string
        rapidjson::StringBuffer buffer;
        rapidjson::Writer<rapidjson::StringBuffer> writer(buffer);
        doc.Accept(writer);
    
        return buffer.GetString();
    }
