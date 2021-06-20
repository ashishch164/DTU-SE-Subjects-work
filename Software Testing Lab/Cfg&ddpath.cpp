#include<iostream>
#include<fstream>
#include<vector>
#include<queue>
#include<stack>
using namespace std;
// constants
const int NOTYPE = 0 , TYPE_REGULAR = 1, TYPE_IF = 2, TYPE_ELSE = 3, TYPE_IF_CLOSE = 4, TYPE_ELSE_CLOSE = 5;
const string IF_STRING = "if(", ELSE_STRING = "else" , CLOSE_STRING = "}";
class Node
{
public:
    int num;
    static int node_count;
// list of ptrs to next nodes
    vector<Node*> next;
    static Node* create_new_node() {
        Node* new_node = new Node();
        new_node->num = Node::node_count++;
        return new_node;
    }
};
int Node::node_count = 1;
class Stack_Node {
public:
    Node* ptr;
    int type;
    Stack_Node() {
        this->ptr = NULL;
        this->type = NOTYPE;
    }
    Stack_Node(Node* ptr, int type) {
        this->ptr = ptr;
        this->type = type;
    }
};
stack<Stack_Node> mStack;
class Graph {
public:
    Node* head;
    void printGraph() {
        queue<Node*> q;
        q.push(head);
        while (!q.empty()) {
            Node* travel_ptr = q.front();
            q.pop();
            cout << travel_ptr->num << " -> ";
            for (std::vector<Node*>::iterator i = travel_ptr->next.begin(); i != travel_ptr->next.end(); ++i)
            {
                cout << (*i)->num << " ";
                q.push((*i));
            }
            
            cout<<endl;
        }
        cout<<"END";
    }
    
};
void process_line(string line, Graph* g) {
    Node* current_node = NULL;
// if the line is not empty create a new node for this line
    if (line.find_first_not_of(' ') != string::npos)
    {
        current_node = Node::create_new_node();
    }
    if (g->head == NULL)
    {
        g->head = current_node;
        Stack_Node new_node(current_node, TYPE_REGULAR);
        mStack.push(new_node);
        return;
    }
// ------------------------------ ATTACHMENT CODE -------------------------------------------------
    /*
    Check if the top of the stack is an 'ELSE_CLOSE' node , if so then attach the current node to the else
    tail and pop the 'ELSE CLOSE AND ELSE' nodes from the stack. Then attach the IF CLOSE to the current node
    and pop the IF CLOSE AND IF nodes from the stack */
    if (mStack.top().type == TYPE_ELSE_CLOSE)
    {
// Attach to the else node
        mStack.top().ptr->next.push_back(current_node);
// Pop ELSE CLOSE
        mStack.pop();
// Pop ELSE
        mStack.pop();
// Attach IF_CLOSE
        mStack.top().ptr->next.push_back(current_node);
// Pop IF_CLOSE
        mStack.pop();
// Pop IF
        mStack.pop();
    }
    else {
// if the current node is not an else node Attach like normal
        if (line.find(ELSE_STRING) == string::npos) {
            mStack.top().ptr->next.push_back(current_node);
        }
    }
// ----------------------------------- PROCESSING CODE --------------------------------------
// if line contains 'if' then
// we push the if node to the stack
    if (line.find(IF_STRING) != string::npos) {
// Push the if node to the stack
        Stack_Node new_node(current_node, TYPE_IF);
        mStack.push(new_node);
    }
// if the line contains 'else' we push the
// else node to the stack
    else if (line.find(ELSE_STRING) != string::npos) {
// Attach the current node to the last if
        Stack_Node node_if_close = mStack.top();
        mStack.pop();
        mStack.top().ptr->next.push_back(current_node);
        mStack.push(node_if_close);
        Stack_Node new_node(current_node, TYPE_ELSE);
        mStack.push(new_node);
    }
// if the line contains a '}' we check if it is a IF_CLOSE or an
// ELSE_CLOSE
    else if (line.find(CLOSE_STRING) != string::npos) {
// Check if the top of the stack is a regular node
        if (mStack.top().type == TYPE_REGULAR) {
            mStack.pop();
            if (!mStack.empty() && mStack.top().type == TYPE_IF) {
                Stack_Node new_node(current_node, TYPE_IF_CLOSE);
                mStack.push(new_node);
            } else if (!mStack.empty() && mStack.top().type == TYPE_ELSE) {
                Stack_Node new_node(current_node, TYPE_ELSE_CLOSE);
                mStack.push(new_node);
            } else {
                Stack_Node new_node(current_node , TYPE_REGULAR);
                mStack.push(new_node);
            }
        } else {
            if (mStack.top().type == TYPE_IF)
            {
                Stack_Node new_node(current_node, TYPE_IF_CLOSE);
                mStack.push(new_node);
            } else if (mStack.top().type == TYPE_ELSE) {
                Stack_Node new_node(current_node, TYPE_ELSE_CLOSE);
                mStack.push(new_node);
            }
        }
    }
// if the line is a regular line we see if the top is a regular line and pop it and push this line
// else if the top node is IF_TYPE or ELSE_TYPE we simply push it
    else {
        if (mStack.top().type == TYPE_REGULAR) {
            mStack.pop();
            Stack_Node new_node(current_node, TYPE_REGULAR);
            mStack.push(new_node);
        }
        else if (mStack.top().type == TYPE_IF || mStack.top().type == TYPE_ELSE) {
            Stack_Node new_node(current_node, TYPE_REGULAR);
            mStack.push(new_node);
        }
    }
}
int main(int argc, char const *argv[])
{
    char filename[100];
    string line;
// input the filename
    cout << "Enter the filename : ";
    cin >> filename;
    Graph* g = new Graph();
    ifstream file(filename);
    if (file.is_open())
    {
// start reading the file
        while (getline(file, line))
        {
            process_line(line, g);
        }
    }
    cout<<"\nControl Flow Graph(CFG) for the above file's code:\n\n";
    g->printGraph();
     return 0;
}

