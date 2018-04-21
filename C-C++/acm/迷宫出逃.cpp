#include<iostream>  
using namespace std;  
#include<cstdio>  
#include<queue>  
#include<cstring>  
#include<vector>  
int tx[] = { -1,1,0,0 };//上下左右移动x的改变量   
int ty[] = { 0,0,-1,1 };//上下左右移动y的改变量   
int ii = 0;  
typedef unsigned long long LL;  
struct datatype//队列中状态信息   
 {  
    int bs;//步数   
    LL zt1;//第一个状态，储存每个点的状态是否反转   
    LL zt2;//第二个状态，储存是否有钥匙   
    int x;//所在的x坐标   
    int y;//所在的y坐标   
    datatype()//初始化   
    {  
        bs = 0;  
        zt1 = 0;  
        x = 0;  
        y = 0;  
        zt2 = 0;  
    }  
};  
queue<datatype> team;//BFS所用的队列   
int maps[70][70];//初始的地图图信息   
struct mapdata {//hash判重所用的信息类型   
    int x, y;//x，y坐标   
    LL zt1;//第一个状态   
    int zt2;//第二个状态   
    LL count()//每个状态的和 mod 10000，取得hash值   
    {  
        LL ans = zt1 % 10000;  
        ans = (ans + zt2) % 10000;  
        ans = (ans + x) % 10000;  
        ans = (ans + y) % 10000;  
        return ans;  
    }  
    bool operator<(const mapdata &b)const//重载   
    {  
        if (this->x != b.x) return this->x< b.x;  
        if (this->y != b.y) return this->y< b.y;  
        if (this->zt1 != b.zt1) return this->zt1 < b.zt1;  
        return this->zt2 < b.zt2;  
    }  
    bool operator==(const mapdata &b)const//重载   
    {  
        if (this->x != b.x) return this->x == b.x;  
        if (this->y != b.y) return this->y == b.y;  
        if (this->zt1 != b.zt1) return this->zt1 == b.zt1;  
        return this->zt2 == b.zt2;  
    }  
};  
char s[70][100];//最初读入得字符串地图信息   
vector<mapdata> has[10010];//hash判重用到得vector数组   
void deal()   
{  
    memset(s, 0, sizeof(s));//初始化   
    memset(maps, 0, sizeof(maps));//初始化   
    int n, m;   
    while (!team.empty()) team.pop();//清空队列   
    datatype pt;//一个读取队列状态的变量   
    cin >> n >> m;//读取n,m，地图长,宽   
    for (int i = 0; i <= 10000; i++)  
        has[i].clear();//清空hash表   
    for (int i = 1; i <= n; i++)  
    {  
        scanf("%s", s[i] + 1);//读取地图信息   
    }  
    int qdx, qdy;//保存起点x，y坐标   
    for (int i = 1; i <= n; i++)//处理地图   
    {  
        for (int j = 1; j <= m; j++)  
        {  
            if (s[i][j] == '.') maps[i][j] = 1;//可行为1   
            if (s[i][j] == 'x') maps[i][j] = 0;//不可行为0   
            if (s[i][j] == 'E') maps[i][j] = -666;//出口为-666   
            if (s[i][j] == '*') maps[i][j] = -10;//机关为-10   
            if (s[i][j] == 'K') maps[i][j] = -66;//钥匙为-66   
            if (s[i][j] == 'S') {//找到起点，将起点入队   
                maps[i][j] = 1, qdx = i, qdy = j;  
                pt.bs = 0, pt.zt1 = 0, pt.zt2 = 0, pt.x = qdx, pt.y = qdy;  
                team.push(pt);  
            }  
        }  
    }  
    datatype pd;  
    int ans = -1;//初始化答案变量   
    while (!team.empty())//BFS   
    {  
        pt = team.front();//取队首元素   
        team.pop();//队首元素出队   
        if (maps[pt.x][pt.y] == -666)//如果是出口，且有钥匙，找到答案，退出搜索   
        {  
            if (pt.zt2 == 1)  
            {  
                ans = pt.bs;  
                break;  
            }  
        }  
        for (int i = 0; i < 4; i++)//向当前位置的x，y轴移动   
        {  
            pd.bs = pt.bs + 1;//更新步数   
            pd.zt1 = pt.zt1;   
            pd.zt2 = pt.zt2;  
            pd.x = pt.x + tx[i];//更新x坐标   
            pd.y = pt.y + ty[i];//更新y坐标   
            if (pd.x <= 0 || pd.y <= 0 || pd.x > n || pd.y > m) continue;//超出边界，舍弃这个位置   
            LL cj = (LL)(m)*(pd.x - 1) + pd.y;//看当前坐标是地图横着数第几个位置，也就是状态压缩后的第几位，式子:(x-1)*m+y   
            LL zt = ((pd.zt1 >> (LL)(cj - 1)) & (LL)1);//看当前坐标是否受机关影响   
            if (zt == 0 && maps[pd.x][pd.y] == 0) continue;//不受影响，原本不可行，舍弃这个位置   
            if (zt == 1)   
            {  
                if (maps[pd.x][pd.y] != 0) continue;//受机关影响，原本可行，舍弃这个位置   
            }  
            LL ws1, ws2, ws3, ws4;//储存上下左右四点 ，是地图横着数第几个位置，也就是状态压缩后的第几位  
            ws1 = 0; ws2 = 0; ws3 = 0; ws4 = 0;  
            ws1 = (pd.x - 2)*(m)+pd.y;  
            ws2 = (pd.x)*m + (pd.y);  
            ws3 = (pd.x - 1)*m + (pd.y - 1);  
            ws4 = (pd.x - 1)*m + (pd.y + 1);  
            if (maps[pd.x][pd.y] == -10)//如果这个点是机关，就更新上下左右四点的反转状态   
            {  
                if (pd.x - 1 > 0)//判断向上走超不超过边界   
                {  
                    if ((pd.zt1 >> (ws1 - (LL)1)) & (LL)1)//对应位置的翻转状态   
                        pd.zt1 = pd.zt1 - ((LL)1 << (ws1 - (LL)1));//是1变成0   
                    else  
                        pd.zt1 = pd.zt1 + ((LL)1 << (ws1 - (LL)1));//是0变成1   
                }  
                /*后面的以此类推*/   
                if (pd.x + 1 <= n)  
                {  
                    if ((pd.zt1 >> (ws2 - (LL)1)) & (LL)1)  
                        pd.zt1 = pd.zt1 - ((LL)1 << (ws2 - (LL)1));  
                    else  
                        pd.zt1 = pd.zt1 + ((LL)1 << (ws2 - (LL)1));  
                }  
                if (pd.y - 1 > 0)  
                {  
                    if ((pd.zt1 >> (ws3 - (LL)1)) & (LL)1)  
                        pd.zt1 = pd.zt1 - ((LL)1 << (ws3 - (LL)1));  
                    else  
                        pd.zt1 = pd.zt1 + ((LL)1 << (ws3 - (LL)1));  
                }  
                if (pd.y + 1 <= m)  
                {  
                    if ((pd.zt1 >> (ws4 - (LL)1)) & (LL)1)  
                        pd.zt1 = pd.zt1 - ((LL)1 << (ws4 - (LL)1));  
                    else  
                        pd.zt1 = pd.zt1 + ((LL)1 << (ws4 - (LL)1));  
                }  
            }  
            if (maps[pd.x][pd.y] == -66)//该点存在钥匙，钥匙状态设为1   
            {  
                pd.zt2 = 1;  
            }  
            mapdata h;//建立一个hash信息的变量   
            h.x = pd.x; h.y = pd.y; h.zt1 = pd.zt1; h.zt2 = pd.zt2;//变量赋值   
            int zzt = h.count();//计算hash值   
            int vvv = 0;//判断访问与否的变量   
            for (int k = 0; k < has[zzt].size(); k++)//遍历所在hash表中的节点   
            {  
                if (has[zzt][k] == h)//该状态已存在，标记已访问   
                {  
                    vvv = 1;  
                    break;  
                }  
            }  
            if (vvv) continue;//如果标记访问，舍弃该状态   
            has[zzt].push_back(h);//未访问，hash信息入表   
            team.push(pd);//状态信息入队   
        }  
    }  
    /*输出答案*/   
    printf("Case #%d:\n", ii);   
    cout << ans << endl;  
}  
int main()  
{  
    int t;  
    cin >> t;  
    while (t--)  
    {  
        ii++;  
        deal();  
    }  
    return 0;  
}
