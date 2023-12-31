Given a reference of a node in a connected undirected graph.
Return a deep copy (clone) of the graph.
Each node in the graph contains a value (int) and a list (List[Node]) of its neighbors.
class Node {
    public int val;
    public List<Node> neighbors;
}
 

Test case format:
For simplicity, each node's value is the same as the node's index (1-indexed). For example, the first node with val == 1, the second node with val == 2, and so on. The graph is represented in the test case using an adjacency list.
An adjacency list is a collection of unordered lists used to represent a finite graph. Each list describes the set of neighbors of a node in the graph.

The given node will always be the first node with val = 1. You must return the copy of the given node as a reference to the cloned graph.



class Solution {
public:
    Node* cloneGraph(Node* node) {
        if(!node)   return NULL;
        unordered_map<Node*, Node*> mp;
        queue<Node*> q;
        mp[node] = new Node(node->val, {});
        q.push(node);

        while(!q.empty()){
            Node * currNode = q.front();
            q.pop();

            vector<Node*> nbrs = currNode->neighbors;
            for(Node* nbr : nbrs){
                if(mp.find(nbr) == mp.end()){
                    mp[nbr] = new Node(nbr->val, {});
                }
                mp[currNode]->neighbors.push_back(mp[nbr]);
            }
        }
        return mp[node];
    }
};
