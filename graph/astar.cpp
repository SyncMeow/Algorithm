#include <bits/stdc++.h>
using namespace std;

struct Point{
    int x, y;
    Point(int _x, int _y) : x(_x), y(_y) {} 
};

struct Node{
    Point pos;
    int g; //起點到節點的實際成本
    int h; //節點到終點的估算成本
    Node* parent;
    Node(Point _pos, int _g, int _h, Node* _parent) : pos(_pos), g(_g), h(_h), parent(_parent) {}
    bool operator<(const Node& rhs) const{
        return (g+h) > (rhs.g + rhs.h);
    }
};

vector<Point> AStar(vector<vector<int>>& grid, Point start, Point end){
    vector<Point> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

    priority_queue<Node> openList;
    vector<vector<bool>> closedList(grid.size(), vector<bool>(grid.size(), false));

    openList.push(Node(start, 0, abs(start.x - end.x) + abs(start.y - end.y), nullptr));

    while(!openList.empty()){
        Node current = openList.top();
        openList.pop();

        if (current.pos.x == end.x && current.pos.y == end.y){
            vector<Point> path;
            while(current.parent != nullptr){
                path.push_back(current.pos);
                current = *current.parent;
            }
            path.push_back(start);
            reverse(path.begin(), path.end());
            return path;
        }

        closedList[current.pos.x][current.pos.y] = true;

        for (Point& dir : directions){
            int newX = current.pos.x + dir.x;
            int newY = current.pos.y + dir.y;

            if (newX < 0 || newX >= grid.size() || newY < 0 || newY >= grid.size() || grid[newX][newY] == 1){
                continue;
            }
            if (closedList[newX][newY]){
                continue;
            }
            int newG = current.g + 1;
            int newH = abs(current.pos.x - end.x) + abs(current.pos.y - end.y);

            openList.push(Node(Point(newX, newY), newG, newH, new Node(current.pos, current.g, current.h, current.parent)));
        }

    }

    return {};
}

int main(){
    vector<vector<int>> grid = {
        {0, 1, 0, 0, 0, 1, 1, 0, 0, 0},
        {0, 0, 0, 1, 0, 0, 0, 1, 1, 0},
        {0, 1, 0, 1, 1, 1, 0, 0, 0, 0},
        {0, 1, 0, 0, 0, 1, 0, 1, 1, 1},
        {0, 1, 0, 1, 0, 1, 0, 1, 1, 1},
        {0, 0, 0, 1, 0, 0, 0, 0, 0, 1},
        {0, 1, 1, 1, 0, 1, 1, 1, 0, 1},
        {0, 1, 0, 0, 0, 0, 0, 1, 0, 1},
        {0, 0, 0, 1, 0, 1, 0, 0, 0, 1},
        {0, 1, 1, 0, 0, 1, 1, 1, 0, 0},
    };
    Point start(0, 0);
    Point end(9, 9);

    vector<Point> path = AStar(grid, start, end);

    if (path.empty()){
        cout << "No valid path found.\n";
    }else{
        cout << "Best path found.\n";
        for (const auto& p: path){
            cout << "(" << p.x << "," << p.y << ") -> ";
        }
        cout << "\n";
    }

    int c; cin >> c;
    return 0;
}