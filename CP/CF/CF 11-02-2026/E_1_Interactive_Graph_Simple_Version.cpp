#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

// Cache to store query results to avoid redundant queries and save budget.
// Key: index k, Value: the path returned by the interactor.
map<long long, vector<int>> cache_map;

// Function to perform a query.
// It checks the cache first. If not found, queries the system.
vector<int> query(long long k) {
    if (cache_map.count(k)) return cache_map[k];

    cout << "? " << k << endl;
    
    int len;
    cin >> len;
    
    // -1 indicates invalid query or other error, exit immediately.
    if (len == -1) {
        exit(0);
    }
    
    vector<int> path;
    if (len > 0) {
        path.resize(len);
        for (int i = 0; i < len; ++i) {
            cin >> path[i];
        }
    }
    // If len == 0, the path does not exist (index out of bounds).
    
    return cache_map[k] = path;
}

void solve() {
    int n;
    cin >> n;
    
    cache_map.clear();
    
    // Step 1: Find the total number of paths in the graph.
    // We are looking for the smallest index S such that the path at S does not exist.
    // This is equivalent to finding the boundary where paths stop.
    // The problem states the number of paths <= 2^30.
    
    long long S = -1;
    long long L = 1, R = (1LL << 30);
    long long ans_S = R; // Default to max if not found earlier (unlikely given constraints)
    
    while (L <= R) {
        long long mid = L + (R - L) / 2;
        vector<int> res = query(mid);
        if (res.empty()) {
            ans_S = mid;
            R = mid - 1;
        } else {
            L = mid + 1;
        }
    }
    S = ans_S;
    
    // Step 2: Find the starting index range for each vertex.
    // P[i] will store the index of the first path that starts with a vertex > i.
    // Consequently, paths starting with vertex 'u' are in the index range [P[u-1], P[u] - 1].
    // Note: Since paths are lexicographically sorted, all paths starting with u come together.
    
    vector<long long> P(n + 1);
    P[0] = 1;      // Paths start at index 1
    P[n] = S;      // Paths starting with > n start at S (i.e., they don't exist)
    
    for (int i = 1; i < n; ++i) {
        // Binary search for P[i] in the range [P[i-1], S].
        // We want the smallest index 'mid' such that path(mid) starts with a vertex > i.
        // If path(mid) is empty, it effectively starts with infinity > i.
        
        long long l_search = P[i-1];
        long long r_search = S;
        long long ans = S;
        
        while (l_search <= r_search) {
            long long mid = l_search + (r_search - l_search) / 2;
            
            // Optimization: if we hit the "empty" region, it satisfies condition > i
            if (mid == S) {
                ans = mid;
                r_search = mid - 1;
                continue;
            }
            
            vector<int> res = query(mid);
            if (res.empty()) {
                ans = mid;
                r_search = mid - 1;
            } else {
                // Check the starting vertex of the path
                if (res[0] > i) {
                    ans = mid;
                    r_search = mid - 1;
                } else {
                    l_search = mid + 1;
                }
            }
        }
        P[i] = ans;
    }
    
    // Calculate the total number of paths starting with each vertex v.
    // This is needed to skip over blocks of paths when identifying edges.
    vector<long long> Count(n + 1);
    for (int i = 1; i <= n; ++i) {
        Count[i] = P[i] - P[i-1];
    }
    
    vector<pair<int, int>> edges;
    
    // Step 3: Identify edges.
    // For each vertex u, iterate through its range of paths to find neighbors.
    for (int u = 1; u <= n; ++u) {
        // The first path starting with u is always just the single vertex path (u).
        // This is at index P[u-1]. We don't need to query it.
        // The subsequent paths in u's range correspond to edges u -> v.
        // The paths starting with u -> v appear immediately after (u) or previous u -> neighbor blocks.
        
        long long curr = P[u-1] + 1;
        long long limit = P[u] - 1;
        
        while (curr <= limit) {
            vector<int> path = query(curr);
            
            // The path must look like u -> v -> ...
            // So the second vertex is the neighbor.
            int v = path[1];
            edges.push_back({u, v});
            
            // The paths starting with u -> v are in one-to-one correspondence with paths starting with v.
            // There are exactly Count[v] such paths.
            // We skip this block to find the next neighbor.
            curr += Count[v];
        }
    }
    
    // Output the answer
    cout << "! " << edges.size() << endl;
    for (auto& edge : edges) {
        cout << edge.first << " " << edge.second << endl;
    }
}

int main() {
    // Standard competitive programming setup, though strictly flushing is handled by endl.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    if (cin >> t) {
        while(t--) {
            solve();
        }
    }
    return 0;
}