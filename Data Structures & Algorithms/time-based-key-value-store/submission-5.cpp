class TimeMap {
public:
    TimeMap() {
        
    }
    unordered_map<string, vector<pair<int, string>>> timemap;
    
    void set(string key, string value, int timestamp) {
        timemap[key].push_back({timestamp, value});
    }
    
    string get(string key, int timestamp) {
        // vector<pair<int, string>> vc = &timemap[key];
        // cout << vc.size() << "\n";
        // if (timestamp[key].size() == 0) return "";
        int l = -1, r = (int)timemap[key].size();
        while (r > l + 1) {
            int m = (l + r) / 2;
            if (timemap[key][m].first <= timestamp) {
                l = m;
            } else {
                r = m;
            }
        }

        if (l == -1) return "";
        return timemap[key][l].second;
    }
};
