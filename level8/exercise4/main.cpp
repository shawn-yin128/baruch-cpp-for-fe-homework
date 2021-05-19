#include <boost/random.hpp>
#include <boost/limits.hpp>
#include <iostream>
#include <ctime>
#include <map>

using namespace std;

int main() {
    // Throwing dice.
    // Mersenne Twister.
    boost::random::mt19937 myRng;

    // Set the seed.
    myRng.seed(static_cast<boost::uint32_t> (std::time(0)));

    // Uniform in range [1,6]
    boost::random::uniform_int_distribution<int> six(1, 6);

    map<int, long> statistics; // Structure to hold outcome + frequencies
    int outcome; // Current outcome

    // initialize the map
    for (int i = 0; i < 7; i++) {
        statistics[i] = 0;
    }

    // ask for trial number
    long int num_trial;
    cout << "how many trail?" << endl;
    cin >> num_trial;

    // generate random number
    for (int i = 0; i <= num_trial; i++) {
        outcome = six(myRng);
        statistics[outcome]++;
    }

    // print probability
    for (int i = 1; i < 7; i++) {
        cout << "Trial " << i << " has " << (static_cast<double>(statistics[i]) / num_trial) * 100 << "% outcomes" << endl;
    }
}