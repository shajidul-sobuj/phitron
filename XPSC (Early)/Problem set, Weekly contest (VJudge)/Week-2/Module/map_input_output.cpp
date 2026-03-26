#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    map<int, int> mp;

    return 0;
}


/*

    ## C++ STL `map` — Short Note

---

### `map` কী?

`map` হলো C++ STL-এর একটি **associative container** যেটা **key-value pair** আকারে data store করে। প্রতিটি key **unique** এবং automatically **sorted** (ascending order) থাকে।

---

### Header

```cpp
#include <map>
```

---

### Declaration

```cpp
map<key_type, value_type> m;

// Example:
map<string, int> marks;
```

---

### Common Operations

```cpp
// Insert
marks["Rahim"] = 90;
marks.insert({"Karim", 85});

// Access
cout << marks["Rahim"];      // 90

// Find
if (marks.find("Karim") != marks.end())
    cout << "Found!";

// Delete
marks.erase("Rahim");

// Size
cout << marks.size();

// Iterate
for (auto& [key, val] : marks)
    cout << key << " -> " << val << "\n";
```

---

### Key Properties

| বিষয় | বিবরণ |
|---|---|
| Key | Unique হতে হবে |
| Ordering | Key অনুযায়ী sorted (BST) |
| Access Time | O(log n) |
| Duplicate Key | Allow করে না |

---

### `map` vs `unordered_map`

| | `map` | `unordered_map` |
|---|---|---|
| Ordering | Sorted | Unsorted |
| Time Complexity | O(log n) | O(1) average |
| Implementation | Red-Black Tree | Hash Table |

---

**সহজ কথায়:** যখন data **sorted order-এ** রাখতে চাও এবং key দিয়ে দ্রুত খুঁজতে চাও — তখন `map` ব্যবহার করো।

*/