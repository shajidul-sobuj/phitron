#include <bits/stdc++.h>

using namespace std;

// Global state
long long current_k;
vector<pair<int, int>> edges;
map<int, long long> memo_count; // Stores total paths starting at u
vector<int> last_path;
bool buffer_full = false;

// Function to perform query
// We only query when we actually need to see the path.
void query() {
    cout << "? " << current_k << endl;
    int len;
    cin >> len;
    if (len == -1) exit(0); 
    if (len == 0) {
        last_path.clear();
    } else {
        last_path.resize(len);
        for (int i = 0; i < len; ++i) cin >> last_path[i];
    }
    buffer_full = true;
}

// Returns the total number of paths starting at u
long long dfs(int u) {
    long long my_paths = 1; // Count the path [u] itself
    current_k++;            // Move past [u]
    buffer_full = false;    // The path [u] is consumed

    while (true) {
        // If we don't have the current path in buffer, ask for it
        if (!buffer_full) {
            query();
        }

        // Check if we are still looking at extensions of u
        // 1. End of all paths?
        if (last_path.empty()) break;
        // 2. Does the path start with u?
        // Note: The path will be [u, v, ...] if it extends u.
        // If it's just [w, ...], then we are done with u.
        if (last_path[0] != u) break;

        // If we are here, the path is [u, v, ...]
        int v = last_path[1];

        // We found an edge (u, v)!
        edges.push_back({u, v});

        // Check if we already know everything about v
        if (memo_count.count(v)) {
            // We know v has memo_count[v] paths.
            // These paths occupy the range [current_k, current_k + memo_count[v] - 1]
            // We consume them all virtually.
            long long skip = memo_count[v];
            my_paths += skip;
            current_k += skip;
            
            // Our buffer currently holds the first path of this block (the one that revealed v).
            // After skipping, that buffer is stale.
            buffer_full = false;
        } else {
            // v is a new node (or at least one we haven't fully resolved yet).
            // However, in this logic, since we are exploring lexicographically,
            // if we encounter v as a neighbor here, we are "entering" v for the first time
            // in the context of this specific path structure check.
            // Wait: v might have been visited as a root of a separate component earlier?
            // Actually, because it's a DAG and we iterate k from 1, if v was a separate component start,
            // it would have appeared as [v] much later in the lexicographical order (after [u]).
            // If v appears here as a neighbor of u, and we haven't memoized it, we must solve it now.
            
            // Note: The path in 'last_path' is [u, v, ...].
            // To solve v, we need to pretend we are looking at paths starting with v.
            // But the query system returns global paths.
            // The global paths starting at current_k are exactly:
            // [u, (1st path of v)], [u, (2nd path of v)], ...
            // This maps 1-to-1 with paths of v.
            // We can recurse, but we must be careful:
            // The dfs(v) expects `current_k` to point to [v].
            // But here `current_k` points to [u, v].
            // This is a slight mismatch in the abstraction.
            
            // Correct Logic for Recursing:
            // We are currently at index `current_k` which is [u, v, ...].
            // This corresponds to the 1st path of v appended to u.
            // We need to count how many paths start with v.
            // We can essentially run the same logic "as if" we were at v,
            // but knowing every path will be prefixed by u.
            
            // Let's refine the DFS:
            // We pass the expected prefix length.
            // `depth` = index in last_path where the current node `u` is located.
            
            // If we are solving for u, and we see [..., u, v, ...], 
            // we recurse for v with depth+1.
            
            // But wait, if we recurse, we will eventually return the count for v.
            // And we add that to u.
            
            // Is it possible we visited v before?
            // Since it's a DAG, and we scan k=1..end, we might see v as a neighbor of u 
            // BEFORE we see v as a root [v] (if u < v).
            // Or we might see v as a root [v] before u (if v < u), but then v < u implies 
            // we wouldn't see u -> v edge? No, values don't determine direction.
            // Example: 2 -> 1.
            // Sorted paths: [1], [2], [2, 1].
            // k=1: [1]. dfs(1) returns 1. Memo[1]=1.
            // k=2: [2]. dfs(2) starts.
            // k=3: [2, 1]. Neighbor 1. We check Memo[1], it exists! Add 1, skip.
            
            // Example: 1 -> 2.
            // Sorted paths: [1], [1, 2], [2].
            // k=1: [1]. dfs(1) starts.
            // k=2: [1, 2]. Neighbor 2. Memo[2] unknown.
            // We must solve 2 *inside* the context of 1.
            // Recursive Step: dfs(2, depth=1).
            // It sees [1, 2]. It knows this is effectively [2].
            // It marks 2 as discovered.
            // ... solves 2 ...
            // Returns count for 2. Memo[2] = result.
            // Later, k moves to [2]. We see [2]. We check Memo[2], it exists.
            // We skip [2] entirely (since it's a root path).
            
            // So we need a `depth` parameter.
            
            long long v_paths = dfs_recursive(v, last_path.size() - 1); 
            // Note: last_path is [u, v], so v is at index 1. 
            // But be careful, last_path might be longer [u, v, w].
            // The 'depth' logic handles where to look.
            
            my_paths += v_paths;
            // dfs_recursive updates current_k internally
            // buffer_full status is updated by dfs_recursive
        }
    }
    
    memo_count[u] = my_paths;
    return my_paths;
}

// Helper to handle the recursion with depth
long long dfs_recursive(int u, int depth) {
    // If we've solved u before (fully), we return the cached count.
    // BUT we must also advance K.
    // Wait, if we are calling this, it means we are "inside" a parent path (e.g. 1->2).
    // We shouldn't advance K if we are just looking up a value?
    // NO. If we are here, it means we are seeing valid paths that correspond to u's subtree.
    // We must consume them.
    
    // However, the standard memoization check `if (memo_count.count(v))` inside the parent loop
    // handles the "skip" logic efficiently.
    // So if we enter this function, it means we *haven't* solved u yet.
    // We are solving u for the first time, in the context of a parent.
    
    long long my_paths = 1; // [..., u]
    current_k++;
    buffer_full = false;
    
    while(true) {
        if (!buffer_full) query();
        
        if (last_path.empty()) break;
        if ((int)last_path.size() <= depth + 1) break; // Not deep enough to be extension
        if (last_path[depth] != u) break; // Sibling or higher level change
        
        int v = last_path[depth + 1];
        
        bool is_new_edge = true;
        // Check if edge already recorded (not strictly necessary with logic, but safe)
        // Actually, since we only process U once, we only add edges once.
        edges.push_back({u, v});
        
        if (memo_count.count(v)) {
            long long skip = memo_count[v];
            my_paths += skip;
            current_k += skip;
            buffer_full = false;
        } else {
            // Recurse
            my_paths += dfs_recursive(v, depth + 1);
        }
    }
    
    memo_count[u] = my_paths;
    return my_paths;
}

void solve() {
    int n;
    cin >> n;
    
    edges.clear();
    memo_count.clear();
    current_k = 1;
    buffer_full = false;
    
    while (true) {
        if (!buffer_full) query();
        
        if (last_path.empty()) break;
        
        // We are at a root path [u, ...] (depth 0)
        int u = last_path[0];
        
        if (memo_count.count(u)) {
            // We already solved u (perhaps as a child of someone else).
            // We just skip this block.
            current_k += memo_count[u];
            buffer_full = false;
        } else {
            // Solve u for the first time
            dfs_recursive(u, 0);
        }
    }
    
    cout << "! " << edges.size() << endl;
    for (auto p : edges) {
        cout << p.first << " " << p.second << endl;
    }
}

int main() {
    int t;
    if (cin >> t) {
        while(t--) {
            solve();
        }
    }
    return 0;
}