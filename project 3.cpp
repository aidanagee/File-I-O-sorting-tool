#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <numeric>
#include <limits>


using namespace std;

double t_low = std::numeric_limits<int>::max();
double v_low = std::numeric_limits<int>::max();
double t_high = std::numeric_limits<int>::min();
double v_high = std::numeric_limits<int>::min();
double t, v, a;

int main()
{
    ifstream open("C:\\Users\\Kneer\\Documents\\Volts.txt");
    if(!open)
    {
        cout << "File could not open!";
        return 0;
    }

    
    string var;
    getline(open, var);
    
    while(open >> t >> v >> a)
    {
        if(v < v_low)
        {
            v_low = v;
            t_low = t;
        }
        if(v > v_high)
        {
            v_high = v;
            t_high = t;
        }
    }

    
    cout << " low: " << v_low << " at " << t_low << "\n";
    cout << "high: " << v_high << " at " << t_high << "\n";
    return 0;
}
