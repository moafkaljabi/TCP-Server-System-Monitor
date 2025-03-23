#include  <iostream>
#include <string>
#include <cstring>
int main()
{

std::string string("Hello, World!");
std::size_t pos1 = string.find_first_of('w');

std::size_t pos2 = static_cast<std::size_t>(std::strchr(string.c_str(), 'w') - string.c_str());

if (pos1 == pos2) {
    std::printf("Both ways give the same result.\n");
    
    
}
else 
std::cout << pos1 << std::endl;
std::cout << pos2 << std::endl;

}