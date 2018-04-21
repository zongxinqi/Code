#include<iostream>  
using namespace std;  
#include<cstdio>  
#include<queue>  
#include<cstring>  
#include<vector>  
int tx[] = { -1,1,0,0 };//���������ƶ�x�ĸı���   
int ty[] = { 0,0,-1,1 };//���������ƶ�y�ĸı���   
int ii = 0;  
typedef unsigned long long LL;  
struct datatype//������״̬��Ϣ   
 {  
    int bs;//����   
    LL zt1;//��һ��״̬������ÿ�����״̬�Ƿ�ת   
    LL zt2;//�ڶ���״̬�������Ƿ���Կ��   
    int x;//���ڵ�x����   
    int y;//���ڵ�y����   
    datatype()//��ʼ��   
    {  
        bs = 0;  
        zt1 = 0;  
        x = 0;  
        y = 0;  
        zt2 = 0;  
    }  
};  
queue<datatype> team;//BFS���õĶ���   
int maps[70][70];//��ʼ�ĵ�ͼͼ��Ϣ   
struct mapdata {//hash�������õ���Ϣ����   
    int x, y;//x��y����   
    LL zt1;//��һ��״̬   
    int zt2;//�ڶ���״̬   
    LL count()//ÿ��״̬�ĺ� mod 10000��ȡ��hashֵ   
    {  
        LL ans = zt1 % 10000;  
        ans = (ans + zt2) % 10000;  
        ans = (ans + x) % 10000;  
        ans = (ans + y) % 10000;  
        return ans;  
    }  
    bool operator<(const mapdata &b)const//����   
    {  
        if (this->x != b.x) return this->x< b.x;  
        if (this->y != b.y) return this->y< b.y;  
        if (this->zt1 != b.zt1) return this->zt1 < b.zt1;  
        return this->zt2 < b.zt2;  
    }  
    bool operator==(const mapdata &b)const//����   
    {  
        if (this->x != b.x) return this->x == b.x;  
        if (this->y != b.y) return this->y == b.y;  
        if (this->zt1 != b.zt1) return this->zt1 == b.zt1;  
        return this->zt2 == b.zt2;  
    }  
};  
char s[70][100];//���������ַ�����ͼ��Ϣ   
vector<mapdata> has[10010];//hash�����õ���vector����   
void deal()   
{  
    memset(s, 0, sizeof(s));//��ʼ��   
    memset(maps, 0, sizeof(maps));//��ʼ��   
    int n, m;   
    while (!team.empty()) team.pop();//��ն���   
    datatype pt;//һ����ȡ����״̬�ı���   
    cin >> n >> m;//��ȡn,m����ͼ��,��   
    for (int i = 0; i <= 10000; i++)  
        has[i].clear();//���hash��   
    for (int i = 1; i <= n; i++)  
    {  
        scanf("%s", s[i] + 1);//��ȡ��ͼ��Ϣ   
    }  
    int qdx, qdy;//�������x��y����   
    for (int i = 1; i <= n; i++)//�����ͼ   
    {  
        for (int j = 1; j <= m; j++)  
        {  
            if (s[i][j] == '.') maps[i][j] = 1;//����Ϊ1   
            if (s[i][j] == 'x') maps[i][j] = 0;//������Ϊ0   
            if (s[i][j] == 'E') maps[i][j] = -666;//����Ϊ-666   
            if (s[i][j] == '*') maps[i][j] = -10;//����Ϊ-10   
            if (s[i][j] == 'K') maps[i][j] = -66;//Կ��Ϊ-66   
            if (s[i][j] == 'S') {//�ҵ���㣬��������   
                maps[i][j] = 1, qdx = i, qdy = j;  
                pt.bs = 0, pt.zt1 = 0, pt.zt2 = 0, pt.x = qdx, pt.y = qdy;  
                team.push(pt);  
            }  
        }  
    }  
    datatype pd;  
    int ans = -1;//��ʼ���𰸱���   
    while (!team.empty())//BFS   
    {  
        pt = team.front();//ȡ����Ԫ��   
        team.pop();//����Ԫ�س���   
        if (maps[pt.x][pt.y] == -666)//����ǳ��ڣ�����Կ�ף��ҵ��𰸣��˳�����   
        {  
            if (pt.zt2 == 1)  
            {  
                ans = pt.bs;  
                break;  
            }  
        }  
        for (int i = 0; i < 4; i++)//��ǰλ�õ�x��y���ƶ�   
        {  
            pd.bs = pt.bs + 1;//���²���   
            pd.zt1 = pt.zt1;   
            pd.zt2 = pt.zt2;  
            pd.x = pt.x + tx[i];//����x����   
            pd.y = pt.y + ty[i];//����y����   
            if (pd.x <= 0 || pd.y <= 0 || pd.x > n || pd.y > m) continue;//�����߽磬�������λ��   
            LL cj = (LL)(m)*(pd.x - 1) + pd.y;//����ǰ�����ǵ�ͼ�������ڼ���λ�ã�Ҳ����״̬ѹ����ĵڼ�λ��ʽ��:(x-1)*m+y   
            LL zt = ((pd.zt1 >> (LL)(cj - 1)) & (LL)1);//����ǰ�����Ƿ��ܻ���Ӱ��   
            if (zt == 0 && maps[pd.x][pd.y] == 0) continue;//����Ӱ�죬ԭ�������У��������λ��   
            if (zt == 1)   
            {  
                if (maps[pd.x][pd.y] != 0) continue;//�ܻ���Ӱ�죬ԭ�����У��������λ��   
            }  
            LL ws1, ws2, ws3, ws4;//�������������ĵ� ���ǵ�ͼ�������ڼ���λ�ã�Ҳ����״̬ѹ����ĵڼ�λ  
            ws1 = 0; ws2 = 0; ws3 = 0; ws4 = 0;  
            ws1 = (pd.x - 2)*(m)+pd.y;  
            ws2 = (pd.x)*m + (pd.y);  
            ws3 = (pd.x - 1)*m + (pd.y - 1);  
            ws4 = (pd.x - 1)*m + (pd.y + 1);  
            if (maps[pd.x][pd.y] == -10)//���������ǻ��أ��͸������������ĵ�ķ�ת״̬   
            {  
                if (pd.x - 1 > 0)//�ж������߳��������߽�   
                {  
                    if ((pd.zt1 >> (ws1 - (LL)1)) & (LL)1)//��Ӧλ�õķ�ת״̬   
                        pd.zt1 = pd.zt1 - ((LL)1 << (ws1 - (LL)1));//��1���0   
                    else  
                        pd.zt1 = pd.zt1 + ((LL)1 << (ws1 - (LL)1));//��0���1   
                }  
                /*������Դ�����*/   
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
            if (maps[pd.x][pd.y] == -66)//�õ����Կ�ף�Կ��״̬��Ϊ1   
            {  
                pd.zt2 = 1;  
            }  
            mapdata h;//����һ��hash��Ϣ�ı���   
            h.x = pd.x; h.y = pd.y; h.zt1 = pd.zt1; h.zt2 = pd.zt2;//������ֵ   
            int zzt = h.count();//����hashֵ   
            int vvv = 0;//�жϷ������ı���   
            for (int k = 0; k < has[zzt].size(); k++)//��������hash���еĽڵ�   
            {  
                if (has[zzt][k] == h)//��״̬�Ѵ��ڣ�����ѷ���   
                {  
                    vvv = 1;  
                    break;  
                }  
            }  
            if (vvv) continue;//�����Ƿ��ʣ�������״̬   
            has[zzt].push_back(h);//δ���ʣ�hash��Ϣ���   
            team.push(pd);//״̬��Ϣ���   
        }  
    }  
    /*�����*/   
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
