#include<iostream>
using namespace std;

//struct created for the nodes in the queue
struct node
{
    int data;
    node* next;
    node(int val)
    {
        data = val;
        next = nullptr;
    }
};
//class queue created with the help of the node struct
class queue
{
public:
    //inititalizing front and back of the queue
    node* front;
    node* rear;
    //inititalizing the the queue in the basic constructor
    queue()
    {
        front = nullptr;
        rear = nullptr;
    }
    //function to add a node at the rear of the queue
    void enqueue(int val)
    {
        node* newnode = new node(val);
        if (front == nullptr && rear == nullptr)
        {
            front = newnode;
            rear = newnode;
            return;
        }
        rear->next = newnode;
        rear = newnode;
    }
    //function to dequeue the front most node
    void dequeue()
    {
        if (front == nullptr && rear == nullptr)
        {
            cout << "Queue is empty" << endl;
            return;
        }
        node* temp = front;
        front = front->next;
        delete temp;
        if (front == nullptr)
        {
            rear = nullptr;  // Update rear to null if queue is empty
        }
    }
    //function to get the value of the from most node
    int frontval()
    {
        if (front == nullptr && rear == nullptr)
        {
            cout << "Queue is empty" << endl;
            return 0;
        }
        return front->data;
    }
    //function to check whether the function is empty and full
    bool isempty()
    {
        if (front == nullptr && rear == nullptr)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    //function to dequeue all elements in the queue
    void clear()
    {
        while (front != nullptr)
        {
            node* temp = front;
            front = front->next;
            delete temp;
        }
        rear = nullptr;
        cout << "Queue dequeued" << endl;
    }
};

//class for graph
class graph
{
private:
    int vertices;//number of vertices
    int** matrix;//matrix of the graph
    int arr[100] = { 0 };//array to store the shortest route
    int count;//array to count the number of nodes in this shortest node
public:
    graph(int cities)//constructor to initalize the matrix and set count to 0
    {
        vertices = cities;
        matrix = new int* [cities];
        for (int i = 0; i < cities; i++)
        {
            matrix[i] = new int[cities]();
        }
        count = 0;
    }
    //assigning edges sequentially from first node to the total number of cities
    void addroadedge(int cities)
    {
        for (int i = 0; i < cities - 1; i++)
        {
            matrix[i][i + 1] = 1;
        }
    }
    //assigning edges to the aerial routes
    void addaerialedge()
    {
        cout << "Enter the number of aerial routes:" << endl;
        int c;
        cin >> c;
        cout << "Enter the origin and destination of the aerial routes" << endl;
        int origin;
        int dest;
        for (int i = 0; i < c; i++)
        {
            cin >> origin >> dest;
            matrix[origin][dest] = 1;
        }
    }
    //using bfs to calculate the shortest path to the desired node
    void bfsshortestpath(int start, int target)
    {
        bool* visited = new bool[vertices]();//bool array to keep track of the visited nodes 
        int* root = new int[vertices];//int array to keep track of the root node of each vertex
        for (int i = 0; i < vertices; ++i)//initializing the to root array with -1
        {
            root[i] = -1;
        }
        queue q;//making queue to store the nodes for bfs traversal
        q.enqueue(start);//add the starting node of the graph in the queue
        visited[start] = true;//assigning true in the bool array at the pos of start node
        while (!q.isempty())
        {
            int curr = q.frontval();
            q.dequeue();
            for (int i = 0; i < vertices; ++i)//exploring the next and aerial routes of the specific node
            {
                if (matrix[curr][i] == 1 && !visited[i] && root[curr] != i)
                    //ensuring there are edges of the specific node
                    //the node is not already visited 
                    //and ensuring it is isn't the root node of the specific node
                {
                    q.enqueue(i);//enqueing the edges of the node
                    visited[i] = true;//making sure to mark it as visited 
                    root[i] = curr;//updating the root node array

                    if (i == target)//checking if i is the target we are going to
                    {
                        printshortestpath(root, start, target);//printing the shortest path to array
                        delete[] visited;
                        delete[] root;
                        return;
                    }
                }
            }
        }
        //incase if the node is not found
        cout << target << " not found" << endl;
        delete[] visited;
        delete[] root;
    }
    //fucntion to print the shortest path 
    void printshortestpath(const int* root, int start, int target)
    {
        if (start == target)
        {
            arr[count] = start;
            count++;
            return;
        }
        printshortestpath(root, start, root[target]);
        arr[count] = target;//storing it to above array
        count++;
    }
    //function to calculate the total days
    int countdays()
    {
        int days = 0;
        int c = 0;
        //using the array calculating days
        for (int i = 0; i < count - 1; i++)
        {
            int next = arr[i] + 1;
            //if next node is +1 then c increments
            if (arr[i + 1] == next)
            {
                c++;
            }
            //if not day gets incremented
            else
            {
                days++;
                c = 0;
            }
            if (c == 6)
            {
                //---------------------------------uncomment to show the case 2 working---------------------------------

                //checking if the next node is not a aerial route
                //if is day does not get incremented and it increments the next time 
                //int nextNode = arr[i + 1];
                //if (nextNode == next + 1)
                //{
                days++;
                c = 0;
                //}
            }
        }
        //checking for additional nodes if the array ends if so add a day
        if (c > 0)
        {
            days++;
        }
        return days;
    }
    //printing the shortest path
    void printpath()
    {
        cout << "Shortest path:";
        for (int i = 0; i < count; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main()
{
    int* arr;//creating array for days to be stored for the specific number of cases
    int cases;
    cout << "Enter number of test cases:" << endl;
    cin >> cases;//getting number of cases
    arr = new int[cases];
    for (int i = 0; i < cases; i++)
    {
        int cities;
        cout << "Enter number of cities:" << endl;
        cin >> cities;
        graph g(cities + 1);//making graph of number of cities
        g.addroadedge(cities + 1);//adding road routes
        g.addaerialedge();//adding aerial routes
        g.bfsshortestpath(1, cities);//calculating shortest route
        arr[i] = g.countdays();//assigning days of specific case
    }
    for (int i = 0; i < cases; i++)
    {
        cout << "Case " << i + 1 << " :" << arr[i] << endl;//printing days for each specific case
    }
    return 0;
}
