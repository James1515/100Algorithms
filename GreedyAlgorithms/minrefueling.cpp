//======================================================================
//Author: James Anthony Ortiz
//File: main.cpp
//Description: CarFueling optimization problem.
//
//======================================================================
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

//Function: MinRefills(x, n, L)
//Params:
// x - a vector with the values of the distances between stations
// n - the number of stops
// L - the car's maximum mileage range
//Return: the Minimum number of stops needed to refill.

long MinRefills(std::vector<long> x, int n, int L)
{

    int numRefills=0, currentRefill=0;

    while(currentRefill <= n)
    {
        int lastRefill = currentRefill;

        while(currentRefill <= n && x[currentRefill + 1] - x[lastRefill] <= L)
            ++currentRefill;

        if (currentRefill == lastRefill)
            return -1;
        else
            //std::cout << x[lastRefill] << "  --  ";

        if (currentRefill <= n)
            ++numRefills;
    }

    return numRefills;
}


int main() {

    //Vector of Stations:
    std::vector<long> stations;
    //Maximum distance between stations:
    int max_distance = 0;
    int car_max_mileage = 0;
    int number_of_stops = 0;

    //Enter: Maximum distance (d):
    cin >> max_distance;
    //Enter: Car Mileage (m):
    cin >> car_max_mileage;
    //Enter: Number of Stops (n):
    cin >> number_of_stops;

    int n_stops = number_of_stops;

    stations.push_back(0);

    int stop_value;

    while(number_of_stops > 0)
    {
        cin >> stop_value;
        stations.push_back(stop_value);
        number_of_stops--;
    }

    stations.push_back(max_distance);

    std::cout << MinRefills(stations, n_stops, car_max_mileage) << std::endl;

    return 0;

}
