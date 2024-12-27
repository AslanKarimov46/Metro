#include <iostream>
#include <cmath>
#include <vector>
#include <string>
#include <algorithm>
#include <stdexcept>

struct StationError
{
	bool isFirst;
	std::string station;
};

void find_stations(const std::string& first, const std::string& second, std::pair<std::string, int>& index1, std::pair<std::string, int>& index2);
int route(const std::pair<std::string, int>& Coord1, const std::pair<std::string, int>& Coord2);