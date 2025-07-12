class Solution {
  public:
    string findOrder(vector<string> &words) {
        unordered_map<int, vector<int>> adj;
        unordered_map<int, int> indegree;
        vector<bool> used(26, false);  // Track all used characters
        int n = words.size();

        // Mark all characters that appear in any word
        for (string &word : words) {
            for (char c : word) {
                used[c - 'a'] = true;
            }
        }

        // Build graph
        for (int i = 1; i < n; i++) {
            string &prev = words[i - 1];
            string &curr = words[i];
            int len = min(prev.length(), curr.length());
            bool found = false;

            for (int j = 0; j < len; j++) {
                if (prev[j] != curr[j]) {
                    int u = prev[j] - 'a';
                    int v = curr[j] - 'a';
                    adj[u].push_back(v);
                    indegree[v]++;
                    found = true;
                    break;
                }
            }

            // If no differing character and prev is longer than curr — invalid order
            if (!found && prev.length() > curr.length()) {
                return "";
            }
        }

        // Topological sort
        queue<int> q;
        string result = "";

        for (int i = 0; i < 26; i++) {
            if (used[i] && indegree[i] == 0) {
                q.push(i);
            }
        }

        while (!q.empty()) {
            int u = q.front();
            q.pop();
            result += (char)(u + 'a');

            for (int v : adj[u]) {
                indegree[v]--;
                if (indegree[v] == 0) {
                    q.push(v);
                }
            }
        }

        // Ensure all used characters are in result (i.e., no cycle)
        int total_chars = count(used.begin(), used.end(), true);
        if (result.length() != total_chars) {
            return "";
        }

        return result;
    }
};