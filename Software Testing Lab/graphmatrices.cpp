#include <fstream>
#include <iostream>
#include <vector>
using namespace std;
class vertex{
 public:
 int in_deg;
 vector<int> e_list;
 int line_num;
 vertex(){
 in_deg = 0;
 }
 vertex(const vertex & v){
 in_deg = v.in_deg;
 for (int i=0;i<v.e_list.size();i++)
 e_list.push_back(v.e_list[i]);
 line_num = v.line_num;
 }
};
struct graph{
 int num_vertex;
 vector<vertex> v_list;
 void insert(const vertex & v){
 vertex v2 = v;
 num_vertex ++;
 v2.line_num = num_vertex;
 v_list.push_back(v2);
 }
 void erase(int i){
 num_vertex--;
 v_list.erase(v_list.begin() + i);
 }
 graph(const graph & cfg){
 num_vertex = cfg.num_vertex;
 for (int i=0;i<num_vertex;i++)
 v_list.push_back(cfg.v_list[i]);
 }
 graph(){
 num_vertex = 0;
 }
};
int buildDDHelper(graph & dd, int index, int & deleted){
 int i,prev_val;
 for (i=index;i<dd.num_vertex;){
 if (dd.v_list[i].in_deg == 1 &&
 dd.v_list[i].e_list.size() == 1){
 prev_val = i;
 i++;
 while (dd.v_list[i].in_deg == 1 &&
 dd.v_list[i].e_list.size() == 1){
 int val = dd.v_list[i].e_list[0] - deleted - 2;
 dd.erase(i);
 deleted++;
 i = val;
 }
 dd.v_list[prev_val].e_list[0] = i + deleted + 1;
 }
 if (dd.v_list[i].e_list.size() > 1){
 buildDDHelper(dd,dd.v_list[i].e_list[0] - deleted - 1, deleted);
 i = buildDDHelper(dd,dd.v_list[i].e_list[1] - deleted - 1,deleted);
 }
 else
 break;
 }
 return i;
}
void buildDD(graph & dd){
 int deleted = 0;
 for (int i=0;i<dd.num_vertex;){
 if (dd.v_list[i].in_deg == 1 &&
 dd.v_list[i].e_list.size() == 1){
 i++;
 while (dd.v_list[i].in_deg == 1 &&
 dd.v_list[i].e_list.size() == 1){
 dd.erase(i);
 deleted ++;
 }
 dd.v_list[i-1].e_list[0] = dd.v_list[i].line_num;
 }
 if (dd.v_list[i].e_list.size() > 1){
 buildDDHelper(dd,dd.v_list[i].e_list[0] - deleted - 1,deleted);
 i = buildDDHelper(dd,dd.v_list[i].e_list[1] - deleted - 1,deleted);
 }
 else
 i++;
 }
}
void buildCFG(graph & cfg, ifstream & fin){
 char ar[100];
 do{
 fin.getline(ar,100);
 string str(ar);
 int pos = str.find_first_not_of(' ');
 if (pos == string::npos)
 continue;
 int prev_pos = cfg.num_vertex - 1;
 if (str.substr(pos,2) == "if"){
 vertex v;
 v.in_deg = 1;
 cfg.insert(v);
 p1:
 cfg.v_list[prev_pos].e_list.push_back(cfg.num_vertex);
 buildCFG(cfg,fin);
 int prev_pos2 = cfg.num_vertex - 1;
 do{
 fin.getline(ar,100);
 string str(ar);
 int pos = str.find_first_not_of(' ');
 if (pos == string::npos)
 continue;
 if (str.substr(pos,4) == "else"){
 vertex v;
 v.in_deg = 1;
 cfg.insert(v);
 cfg.v_list[prev_pos + 1].e_list.push_back(cfg.num_vertex);
 buildCFG(cfg,fin);
 do{
 fin.getline(ar,100);
 string str(ar);
 int pos = str.find_first_not_of(' ');
 if (pos == string::npos)
 continue;
 vertex v2;
 v2.in_deg = 2;
 cfg.insert(v2);
 cfg.v_list[cfg.num_vertex -2].e_list.push_back(cfg.num_vertex);
 cfg.v_list[prev_pos2].e_list.push_back(cfg.num_vertex);
 if (str[pos] == '}')
 return;
 break;
 }
 while (true);
 }
 else{
 vertex v2;
 v2.in_deg = 2;
 cfg.insert(v2);
 cfg.v_list[cfg.num_vertex -2].e_list.push_back(cfg.num_vertex);
 cfg.v_list[prev_pos2 - 2].e_list.push_back(cfg.num_vertex);
 if (str.substr(pos,2) == "if")
 goto p1;
 else if (str[pos] == '}')
 return;
 }
 break;
 }
 while (true);
 }
 else{
 vertex v;
 v.in_deg = 1;
 cfg.insert(v);
 cfg.v_list[prev_pos].e_list.push_back(cfg.num_vertex);
 if (str[pos] == '}')
 break;
 }
 }while (true);
}
void printGraph(const graph & cfg){
 for (int i=0;i<cfg.num_vertex;i++){
 cout << cfg.v_list[i].line_num << ": Indegree: "<<cfg.v_list[i].in_deg<<" Edge List-> ";
 int size_edge = cfg.v_list[i].e_list.size();
 for (int j=0;j<size_edge;j++)
 cout << cfg.v_list[i].e_list[j] << " ";
 cout << endl;
 }
}
void graph_matrix(const graph & cfg){
 int size = cfg.num_vertex;
 int i,j,k,num;
 int ar1[size];
 int arr[size][size];
 for(i=0;i<size;i++){
 ar1[i] = cfg.v_list[i].line_num;
 }
 for(i=0;i<size;i++){
 for(j=0;j<size;j++){
 arr[i][j]=0;
 }
 }
 for(i=0;i<size;i++){
 int size_edge = cfg.v_list[i].e_list.size();
 for (int j=0;j<size_edge;j++){
 num= cfg.v_list[i].e_list[j];
 for(k=0;k<size;k++){
 if(ar1[k]==num){
 arr[i][k]=1;
 break;
 }
 }
 }
 }
 cout<<" ";
 for(i=0;i<size;i++){
 cout<<" "<<i;
  }
  int count=2;
 printf("\n");
 for(i=0;i<size;i++){
 cout<<i<<" ";
 for(j=0;j<size;j++){
 printf("%d ",arr[i][j]);
 if(arr[i][j]==1)
 count++;
 }
 count--;
 printf("\n");
 }
 printf("\n Number of Independent Path : %d",count);
}
int main(){
 char file_name[100];
 cout << "ENTER THE NAME OF THE FILE TO BE ANALYSED: ";
 cin.getline(file_name,100);
 ifstream fin(file_name);
 if (!fin){
 cout << "FILE NOT FOUND!\n";
 }
 else{
 char ar[100];
 bool terminate = false;
 while (!terminate){
 fin.getline(ar,100 - 1);
 string str(ar);
 int pos = str.find_first_not_of(' ');
 if (str[pos] == '#')
 continue;
 if (str.find("main()") != string::npos){
 graph cfg;
 vertex v;
 cfg.insert(v);
 buildCFG(cfg,fin);
 cout << "\nTHE GRAPH MATRIX IS AS FOLLOWS: \n";
 graph dd(cfg);
 buildDD(dd);
 graph_matrix(dd);
 terminate = true;
 }
 }
 }
 return 0;
}

