class Solution {
public:
    Node* cloneGraph(Node* node) {

        if (node == NULL)
            return NULL;

        unordered_map<Node*, Node*> mp;
        queue<Node*> q;

        // Create clone of starting node
        Node* clone = new Node(node->val);

        mp[node] = clone;
        q.push(node);

        while (!q.empty()) {

            Node* curr = q.front();
            q.pop();

            for (Node* neighbor : curr->neighbors) {

                // If neighbor is not cloned
                if (mp.find(neighbor) == mp.end()) {

                    mp[neighbor] = new Node(neighbor->val);

                    q.push(neighbor);
                }

                // Connect cloned nodes
                mp[curr]->neighbors.push_back(mp[neighbor]);
            }
        }

        return clone;
    }
};