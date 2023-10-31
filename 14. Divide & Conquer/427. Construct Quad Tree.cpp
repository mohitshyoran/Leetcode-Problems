Given a n * n matrix grid of 0's and 1's only. We want to represent grid with a Quad-Tree.

Return the root of the Quad-Tree representing grid.

A Quad-Tree is a tree data structure in which each internal node has exactly four children. Besides, each node has two attributes:

val: True if the node represents a grid of 1's or False if the node represents a grid of 0's. Notice that you can assign the val to True or False when isLeaf is False, and both are accepted in the answer.
isLeaf: True if the node is a leaf node on the tree or False if the node has four children.
class Node {
    public boolean val;
    public boolean isLeaf;
    public Node topLeft;
    public Node topRight;
    public Node bottomLeft;
    public Node bottomRight;
}
We can construct a Quad-Tree from a two-dimensional area using the following steps:

If the current grid has the same value (i.e all 1's or all 0's) set isLeaf True and set val to the value of the grid and set the four children to Null and stop.
If the current grid has different values, set isLeaf to False and set val to any value and divide the current grid into four sub-grids as shown in the photo.
Recurse for each of the children with the proper sub-grid.


//////////////////////////////////////////
/////////////////////////////////////////

Node* zero = new Node(false, true);
Node* one = new Node(true, true);

class Solution {
public:
    Node* create(vector<vector<int>>& grid, int x, int y, int n) {
        if (n == 1) {
            return grid[x][y] == 1 ? one : zero;
        }
        int mid = n / 2;
        Node *topLeft = create(grid, x, y, mid);
        Node *topRight = create(grid, x, y+mid, mid);
        Node *botLeft = create(grid, x+mid, y, mid);
        Node *botRight = create(grid, x+mid, y+mid, mid);
        if (topLeft == topRight and botLeft == botRight and topLeft == botLeft) {
            return topLeft;
        }
        return new Node(false, false, topLeft, topRight, botLeft, botRight);
    }
    
    Node* construct(vector<vector<int>>& grid) {
        return create(grid, 0, 0, grid.size());    
    }
};
