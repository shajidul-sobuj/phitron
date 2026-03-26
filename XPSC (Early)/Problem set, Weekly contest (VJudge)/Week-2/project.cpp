#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
#define endl '\n'

#define forr(i,a,b) for(int i=a;i<b;i++)
#define forb(i,a,b) for(int i=a;i>=b;i--)

const ll INF = 1e18;
const int MOD = 1e9 + 7;

void yes() { cout << "YES\n"; }
void no()  { cout << "NO\n";  }

/*=====================================
        WEATHER DATA STRUCTURE
=====================================*/

struct WeatherData {
    int timestamp;
    double temperature;
    double humidity;

    WeatherData(int t, double temp, double hum) {
        timestamp = t;
        temperature = temp;
        humidity = hum;
    }
};

/*=====================================
        BINARY SEARCH TREE
=====================================*/

struct Node {
    WeatherData data;
    Node* left;
    Node* right;

    Node(WeatherData d) : data(d), left(NULL), right(NULL) {}
};

class BST {
private:
    Node* root;

    Node* insert(Node* node, WeatherData data) {
        if (node == NULL)
            return new Node(data);

        if (data.timestamp < node->data.timestamp)
            node->left = insert(node->left, data);
        else
            node->right = insert(node->right, data);

        return node;
    }

    Node* search(Node* node, int timestamp) {
        if (node == NULL || node->data.timestamp == timestamp)
            return node;

        if (timestamp < node->data.timestamp)
            return search(node->left, timestamp);
        else
            return search(node->right, timestamp);
    }

    void inorder(Node* node) {
        if (node == NULL) return;

        inorder(node->left);
        cout << "Time: " << node->data.timestamp
             << " | Temp: " << node->data.temperature
             << " | Humidity: " << node->data.humidity << endl;
        inorder(node->right);
    }

public:
    BST() { root = NULL; }

    void insert(WeatherData data) {
        root = insert(root, data);
    }

    void search(int timestamp) {
        Node* result = search(root, timestamp);
        if (result)
            cout << "Found -> Temp: " << result->data.temperature
                 << ", Humidity: " << result->data.humidity << endl;
        else
            cout << "No data found at this timestamp.\n";
    }

    void display() {
        inorder(root);
    }
};

/*=====================================
        WEATHER ANALYSIS SYSTEM
=====================================*/

class WeatherSystem {
private:
    BST bst;

    // Max Heap → Highest temperature
    priority_queue<double> maxHeap;

    // Min Heap → Lowest temperature
    priority_queue<double, vector<double>, greater<double>> minHeap;

    // Queue → Moving average
    queue<double> tempQueue;
    int windowSize;

public:
    WeatherSystem(int window = 3) {
        windowSize = window;
    }

    void addData() {
        int time;
        double temp, hum;

        cout << "Enter Timestamp: ";
        cin >> time;
        cout << "Enter Temperature: ";
        cin >> temp;
        cout << "Enter Humidity: ";
        cin >> hum;

        WeatherData data(time, temp, hum);

        bst.insert(data);
        maxHeap.push(temp);
        minHeap.push(temp);

        tempQueue.push(temp);
        if (tempQueue.size() > windowSize)
            tempQueue.pop();

        cout << "Data inserted successfully!\n";
    }

    void showAllData() {
        cout << "\n--- All Weather Data (Sorted by Time) ---\n";
        bst.display();
    }

    void searchData() {
        int time;
        cout << "Enter timestamp to search: ";
        cin >> time;
        bst.search(time);
    }

    void showMaxTemp() {
        if (!maxHeap.empty())
            cout << "Maximum Temperature Recorded: "
                 << maxHeap.top() << endl;
        else
            cout << "No data available.\n";
    }

    void showMinTemp() {
        if (!minHeap.empty())
            cout << "Minimum Temperature Recorded: "
                 << minHeap.top() << endl;
        else
            cout << "No data available.\n";
    }

    void movingAverage() {
        if (tempQueue.empty()) {
            cout << "Not enough data.\n";
            return;
        }

        queue<double> tempCopy = tempQueue;
        double sum = 0;
        int count = tempCopy.size();

        while (!tempCopy.empty()) {
            sum += tempCopy.front();
            tempCopy.pop();
        }

        cout << "Moving Average (Last "
             << count << " readings): "
             << sum / count << endl;
    }
};

/*=====================================
                MAIN
=====================================*/


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    WeatherSystem system(3);

    int choice;

    while (true) {
        cout << "\n====== Weather Data Analysis System ======\n";
        cout << "1. Add Weather Data\n";
        cout << "2. Display All Data\n";
        cout << "3. Search by Timestamp\n";
        cout << "4. Show Maximum Temperature\n";
        cout << "5. Show Minimum Temperature\n";
        cout << "6. Show Moving Average\n";
        cout << "7. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1: system.addData(); break;
            case 2: system.showAllData(); break;
            case 3: system.searchData(); break;
            case 4: system.showMaxTemp(); break;
            case 5: system.showMinTemp(); break;
            case 6: system.movingAverage(); break;
            case 7: cout << "Exiting...\n"; return 0;
            default: cout << "Invalid choice.\n";
        }
    }

    return 0;
}
