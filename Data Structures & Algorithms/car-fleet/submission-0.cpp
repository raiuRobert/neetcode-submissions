class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = position.size();

        // pair each car's position with its time to reach the target
        vector<pair<int, double>> cars;
        for (int i = 0; i < n; i++) {
            double time = (double)(target - position[i]) / speed[i];
            cars.push_back({position[i], time});
        }

        // closest to the target first
        sort(cars.begin(), cars.end(), greater<pair<int, double>>());

        int fleets = 0;
        double fleetTime = 0;   // arrival time of the fleet directly ahead

        for (auto& [pos, time] : cars) {
            if (time > fleetTime) {      // slower than the fleet ahead → can't catch it
                fleets++;
                fleetTime = time;        // this car leads a new fleet
            }
            // else: it catches up and joins; fleetTime stays the same
        }

        return fleets;
    }
};