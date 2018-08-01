/*
  开发一个简单错误记录功能小模块，能够记录出错的代码所在的文件名称和行号。 
  处理:
  1.记录最多8条错误记录，对相同的错误记录(即文件名称和行号完全匹配)只记录一条，错误计数增加；(文件所在的目录不同，文件名和行号相同也要合并)
  2.超过16个字符的文件名称，只记录文件的最后有效16个字符；(如果文件名不同，而只是文件名的后16个字符和行号相同，也不要合并)
  3.输入的文件可能带路径，记录文件名称不能带路径
*/


#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
 
struct node {
    string file;//path+hanghao
    int cunt;
    int rank; //出现次序
    node(string file, int cunt, int appear) {
        this->file = file;
        this->cunt = cunt;
        this->rank = appear;
    }
};
typedef struct node Node;
bool mycomp(const Node &Node1, const Node &Node2) {
    if(Node1.cunt == Node2.cunt)
        return (Node1.rank < Node2.rank);
    else
        return Node1.cunt > Node2.cunt;
}
 
int has(const vector<Node> &s, string path)
{
    for(int i=0; i<s.size(); ++i) {
        if(s[i].file == path)
            return i;
    }
    return -1;
}
 
int main()
{
    string line;
    string file;
    vector<Node> rec;
    int appear_cnt=0;
    while(getline(cin, line)) {
        int t=line.rfind('\\');
        file = line.substr(t+1);
         
        int has_i = has(rec, file);
        if(has_i!=-1) {
            rec[has_i].cunt += 1;
        }
        else {
            appear_cnt++;
            Node temp(file, 1, appear_cnt);
            rec.push_back(temp);
             
        }
    }
    sort(rec.begin(), rec.end(), mycomp);
    for(int i=0; i<8 && i<rec.size(); ++i) {
        string path = rec[i].file;
        int t = path.find(' ');
        string num = path.substr(t+1);
        path = path.substr(0, t);
        if(path.size()>16)
            path = path.substr(t-16);
        cout << path << ' ' << num << ' '<<rec[i].cunt <<endl;
         
    }
     
    return 0;
}

