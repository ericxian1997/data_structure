#include <bits/stdc++.h>
using namespace std;
//  数据结构机试模版
//  Eric Xian 2017.6
//  1.堆栈： stack用法、表达式转换
//  2.队列： queue,deque,priority_queue用法
//  3.链表： list用法，list实现（指针+数组）、去重、查环，插入与删除
//  4.查找： 二分查找、二叉搜索树
//  5.排序： 归并排序、堆排序
//  6.哈希： 哈希函数、线性探测、拉链法
//  7.二叉树： 递归遍历、层次遍历、求深度、先中后序转换
//  8.树应用： 并查集
//  9.图表示： 邻接矩阵、邻接表、DFS、BFS
//  10.图论：  拓扑排序、Prim、Kruskal、Djikstra、Floyd

//  1.stack 用法
void stack()
{
    stack<int> s;
    s.empty();
    s.size();
    s.top();
    s.push();
    s.pop();
}
//  2.queue,deque,priority_queue 用法
void queue()
{
    queue<int> q;
    priority_queue<int> pq;
    q.empty();
    q.size();
    q.push();
    q.pop();
    q.front();
    q.back();
    deque() dq;
    dq.push_front();
    dq.push_back();
    dq.pop_front();
    dq.pop_back();
    dq.front();
    dq.back();
}
//  3.list用法
void list()
{
    list<int> l;
    l.insert(pos,num);
    l.push_back();
    l.pop_back();
    l.push_front();
    l.pop_front();
    l.front();
    l.back();
}
//  3.链表查环
bool check(node *head)
{
	node *fast = head, *slow = head;
	if(head == NULL) return false;
	if(fast->next == NULL)	return false;
	while(fast->next->next != NULL)
	{
		fast = fast->next->next;
		slow = slow->next;
		if(fast == slow)	return true;
		if(fast->next == NULL)	break;
	}
	return false;
}
//  4.二分查找（递归版本）
int BinarySearchRecursive(int *a, int low, int high, int key)
{
    if ( low > high )
        return -1;
    int mid = ( low + high )/2;

    if ( a[mid] == key )
        return mid;
    else if ( a[mid] < key )
        return BinarySearchRecursive(a, mid+1, high, key);
    else
        return BinarySearchRecursive(a, low, mid-1, key);
}
//  4.二分查找（非递归版本）
int BinarySearch(const int s[], const int size, const int target)
{
	int pos = -1;
	int top = 0, bottom = size-1;
	while(top <= bottom)
	{
		int mid = (top+bottom)/2;
		if(target > s[mid])     top = mid+1;
		else if(target < s[mid])    bottom = mid-1;
		else
		{
			pos = mid;
			while(pos+1 < size && s[pos+1] == target)	pos++;
            return pos;
		}
	}
	return pos;
}
//  4.二叉搜索树
{
    struct Node
    {
        int data;
        Node *lc;
        Node *rc;
    };

    void b_insert(Node* &root, int key)
    {
        if(root == NULL)
        {
            root = new Node;
            root->data = key;
            root->lc = NULL;
            root->rc = NULL;
            return;
        }
        else if(key < root->data)   b_insert(root->lc, key);
        else    b_insert(root->rc, key);
        return;
    }

    void inorder(Node* root)
    {
        if(root)
        {
            inorder(root->lc);
            cout << root->data << " ";
            inorder(root->rc);
        }
    }

    int main()
    {
        int n;
        while(cin >> n && n)
        {
            Node *root = NULL;
            int key;
            while(n--)
            {
                cin >> key;
                b_insert(root, key);
            }
            inorder(root);
            cout << endl;

        }
        return 0;
    }
}
//  5.归并排序1
void merge_sort(int *A, int l, int r, int*T)
{
	if(r>l)
	{
		int m = (l+r) / 2;
		int p = l, q = m+1, i = l;
		merge_sort(A, l, m, T);
		merge_sort(A, m+1, r, T);
		while(p <= m || q <= r)
		{
			if(q > r || (p <= m && A[p] <= A[q]))
				T[i++] = A[p++];
			else	T[i++] = A[q++];
		}
		for(i = l; i <= r; i++)
        {
            A[i] = T[i];
        }
	}
}
//  5.归并排序2
{
    void Merge(int *a, int l, int mid, int r)
    {
        int n1 = mid-l+1;
        int n2 = r-mid;
        int  *L = new int[n1+1];
        int  *R = new int[n2+1];
        int i, j, k;
        for (i = 0; i < n1; i++)
            L[i] = a[l+i];
        for (j = 0; j < n2; j++)
            R[j] = a[mid+j+1];
        L[n1] = 1000000;
        R[n2] = 1000000;
        // 如果是非递增排序L[n1] = R[n2] < min(a)
        for (i = 0, j = 0, k = l; k <= r; k++)
        {
            if (L[i] <= R[j])       // 非递减排序
            {
                a[k] = L[i];
                i++;
            }
            else
            {
                a[k] = R[j];
                j++;
            }
        }
        delete []L;
        delete []R;
    }
    void Merge_Sort(int *a, int l, int r)
    {
        if (l<r)
        {
            int mid = (l+r)/2;
            Merge_Sort(a, l, mid);
            Merge_Sort(a, mid+1, r);
            Merge(a, l, mid, r);
        }
    }
}
//  5.堆排序
{
    class array
    {
    private:
        int elem[100000];

    public:
        int &operator[](int i) { return elem[i]; }
    };

    class heap
    {
    private:
        int n;
        array h;

    public:
        void clear() { n = 0; }
        int top() { return h[1]; }
        int size() { return n; }
        void push(int);
        void pop();
    };

    void heap::push(int x)
    {
        h[++n] = x;
        for(int i = n; i > 1; i /= 2)
        {
            if(h[i/2] <= h[i])  break;
            else    swap(h[i], h[i/2]);
        }
    }

    void heap::pop()
    {
        if(n == 0)  return;
        h[1] = h[n--];
        int s = 1
        for(int i = 2*s; i <= n; i *= 2)
        {
            if(i < n && h[i] > h[i+1]) ++i;
            if(h[s] < h[i])  break;
            swap(h[i], h[s]);
            s = i;
        }
    }
}
//  6.字符串哈希
{
    string table[1997417];

    int ELFhash(const char *key)
    {
        unsigned long h = 0;
        while(*key)
        {
            h = (h<<4) + *key++;
            unsigned long g = h & 0xf0000000L;
            if (g) h^= g >> 24;
            h &= ~g;
        }
        return h % 1997417;
    }

    void query(string A[], int n, string B[], int m)
    {

        for(int i = 0; i < n; i++)
        {
            int index = ELFhash(A[i].c_str());
            while(table[index].size() != 0)
            {
                if(index < 1997416)  index++;
                else    index = 0;
            }
            table[index] = A[i];
        }
        for(int i = 0; i < m; i++)
        {
            if(table[ELFhash(B[i].c_str())].size() != 0)
            {
                int index = ELFhash(B[i].c_str());
                int ok = 1;
                while(table[index] != B[i])
                {
                    if(table[index].size() == 0)
                    {
                        ok = 0;
                        break;
                    }
                    if(index < 1997416)   index++;
                    else    index = 0;
                }
                if(ok)  printf("%s\n", B[i].c_str());
            }
        }
    }
}
//  7.二叉树的深度和大小
{
    struct Node {
            Node *lc, *rc;
    };

    void traversal(const Node* root, int &size)
    {
        if(root != NULL)
        {
            size++;
            traversal(root->lc, size);
            traversal(root->rc, size);
        }
    }

    void high(const Node *root,int &h)
    {
        if(root == NULL)    h = 0;
        else
        {
           int h1,h2;
           high(root->lc, h1);
           high(root->rc, h2);
           h = ((h1 > h2) ? h1 : h2)+1;
        }
    }

    void query(const Node *root, int &size, int &height)
    {
        size = 0;
        height = 0;
        traversal(root, size);
        high(root, height);
    }
}
//  7.二叉树遍历转换
{
    int step = 0;
    /*
    1 确定根,确定左子树，确定右子树。
    2 在左子树中递归。
    3 在右子树中递归。
    4 打印当前根。
    */
    //  由二叉树的先序遍历和中序遍历求后序遍历
    void re_order1(int* inorder, int* preorder, int length)
    {
        if(length != 0)
        {
            step++;
            int root = 0;
            for(; root < length; root++)
            {
                if(inorder[root] == *preorder)  break;
            }
            int elem = *preorder;
            re_order1(inorder, preorder+1, root);
            re_order1(inorder+root+1, preorder+root+1, length - (root+1));
            cout << elem;
            if(step!=1) cout << " ";
            step--;
            return;
        }
    }
    /*
    1 确定根,确定左子树，确定右子树。
    2 打印当前根。
    3 在左子树中递归。
    4 在右子树中递归。
    */
    //  由二叉树的后序遍历和中序遍历求先序遍历
    void re_order2(int* inorder, int* postorder, int length)
    {
        if(length != 0)
        {
            int root = 0;
            step++;
            for(; root < length; root++)
            {
                if(inorder[root] == *(postorder+length-1))  break;
            }
            int elem = *(postorder+length-1);
            cout << elem << " ";
            re_order2(inorder, postorder, root);
            re_order2(inorder+root+1, postorder+root, length - (root+1));
            if(step!=1) cout << " ";
            step--;
            return;
        }
    }
}
//  8.并查集
{
    while(t--)
    {
        int n,m;
        scanf("%d %d", &n, &m);
        int father[5100] = {0};
        //  add elements
        for(int i = 0; i < m; i++)
        {
            int a, b;
            int x = a, y;
            scanf("%d %d", &a, &b);
            while(father[a] != 0)
                a = father[a];
            while(x != a)
            {
            	y = father[x];
            	father[x] = a;
            	x = y;
            }
            while(father[b] != 0)
                b = father[b];
            x = b;
            while( x != b)
            {
            	y = father[x];
            	father[x] = b;
            	x = y;
            }
            if(a != b)
                father[a] = b;
        }
        int q;
        scanf("%d", &q);
        //  search elements
        while(q--)
        {
            int a, b;
            scanf("%d %d", &a, &b);
            while(father[a] != 0)
                a = father[a];
            while(father[b] != 0)
                b = father[b];
            if(a == b)
                printf("Yes\n");
            else
                printf("No\n");
        }
        if(t)
            printf("\n");
    }
}
//  9.DFS遍历
{
    void DFS(Vertex v)
    {
        Vertex w;
        visited[v] = true;
        (*visit)(v);
        for(all w adjacent to v)
            if(!visited[w])
                DFS(Vertex w);
    }
}
//  9.BFS遍历（邻接矩阵）
{
    int visited[1010] = {0};
    queue<int> q;
    for(int i = 0; i < n; i++)
    {
        if(visited[i])  continue;
        q.push(i);
        while(!q.empty())
        {
            int now = q.front();
            q.pop();
            //  Visit();
            visited[now] = 1;
            for(int j = 0; j < n; j++)
            {
                if(graph[now][j] == 1 && !visited[j])
                    q.push(j);
            }
        }
    }
}
//  9.BFS遍历（邻接表）
{
    int visited[1010] = {0};
    queue<int> q;
    for(int i = 0; i < n; i++)
    {
        if(visited[i])  continue;
        q.push(i);
        while(!q.empty())
        {
            int now = q.front();
            q.pop();
            //  Visit();
            visited[now] = 1;
            for(int j = 01; j < graph[now].size(); j++)
            {
                if(graph[now][j] == 1 && !visited[j])
                    q.push(j);
            }
        }
    }
}
//  10.拓扑排序
{
    vector<int> a[100010];
    int degree[100010];

    void topsort()
    {
        set<int> s;
        for(int i = 1; i<=n; i++)
            if(degree[i]==0)
                s.insert(i);
        while(!s.empty())
        {
            int i = *s.begin();
            s.erase(s.begin());
            cout << i << " ";
            for(int j = 0; j < a[i].size(); j++)
                if((--degree[ a[i][j] ])==0)
            		s.insert(a[i][j]);
        }
        cout << endl;
    }
}
//  10.DAG判断
bool DAG(int graph[][120], int n, int InDegree[])
{
    list<int> l;
    queue<int> s;
    for(int i = 1; i <= n; i++)
    {
        if(InDegree[i] == 0)
            s.push(i);
    }
    while(!s.empty())
    {
        int node = s.front();
        l.push_back(node);
        s.pop();
        for(int i = 1; i <= n; i++)
        {
            if(graph[node][i] == 1)
            {
                graph[node][i] == 0;
                InDegree[i]--;
                if(InDegree[i] == 0)
                    s.push(i);
            }
        }
    }
    return (l.size() == n);
}
//  10.Kruskal算法
{
    int path[510][510];
    int vexnum;
    int edgenum;

    struct Edge
    {
        int begin;
        int end;
        int weight;
        bool operator < (Edge const &another) const
        {
            return weight < another.weight;
        }
    };

    void Kruskal(Graph G)
    {
        vector<Edge> edges;
        int father[vexnum+10] = {0};
        //  Extract and build edges from the graph
        sort(edges.begin(), edges.end());
        //  Sort the edges according to weight
        for(int i = 0; i < edgenum; i++)
        {
            int a = father[edges[i].begin];
            int b = father[edges[i].end];
            while(father[a] > 0)
                a = father[a];
            while(father[b] > 0)
                b = father[b];
            if(a != b)
            {
                father[a] = b;
                //  add this edge to the span tree
            }
        }
    }
}
// 10.Prim算法
{
    int path[510][510];
    int vexnum;

    void Prim(int &longest_way)
    {
        longest_way = 0;
        int next = 0;
        int closest[510];
        closest[next] = 0;
        for(int i = 0; i < vexnum; i++)
            if(i != next)
            	closest[i] = path[next][i];
        for(int i = 1; i < vexnum; i++)
        {
            int min = INF;
            int index;
            for(int j = 0; j < vexnum; j++)
            {
                if(closest[j] != 0 && closest[j] < min)
                {
                    index = j;
                    min = closest[j];
                }
            }
            next = index;
            // Add this vertex to the tree
            closest[index] = 0;
            for(int j = 0; j < vexnum; j++)
            {
                if(path[next][j] < closest[j])
                    closest[j] = path[next][j];
            }
        }
    }
}
// 10.Dijkstra算法
{
    struct Path
    {
        int length;
        int w;
        bool operator < (const Path &b) const
        {
            if(length != b.length)
                return length < b.length;
            else
                return w < b.w;
        }
        Path(int ww, int ll)
        {
            w = ww;
            length = ll;
        }
    };

    struct Graph
    {
        int vexnum;
        vector<set<Path> > path;
    };

    void Dij(Graph G, int vs, int *shortest)
    {
        for(int i = 0; i < G.vexnum; i++)
        {
            if(i == vs) shortest[i] = 0;
            else    shortest[i] = INF;

        }
        set<Path>::iterator iter;
        for(iter = G.path[vs].begin(); iter != G.path[vs].end(); iter++)
        	if(shortest[(*iter).w] > (*iter).length)
            	shortest[(*iter).w] = (*iter).length;
        bool found[10010] = {0};
        found[vs] = true;
        for(int i = 1; i < G.vexnum; i++)
        {
            int min = INF;
            int v;
            for(int w = 0; w < G.vexnum; w++)
                if(!found[w] && shortest[w] < min)
                {
                    v = w;
                    min = shortest[w];
                }
            found[v] = true;
            set<Path>::iterator iter;
            for(iter = G.path[v].begin(); iter != G.path[v].end(); iter++)
            {
                if(!found[(*iter).w] && (min + (*iter).length < shortest[(*iter).w]))
                    shortest[(*iter).w] = min + (*iter).length;
            }
        }
        return;
    }
}
// 10.Dijkstra算法
{
	#define INF 10000000
	int n;
	int graph[1010][1010];
	int visited[1010];
	int d[1010];

	void Dijkstra(int vs)
	{
		int i, j, min, p;
		for(int i = 1; i <=n; i++)
			d[i] = graph[vs][i];
		visited[vs] = 1;
		d[vs] = 0;
		for(i = 1; i < n; i++)
		{
			min = INF;
			for(j = 1; j <= n; j++)
			{
				if(!visited[j] && min > d[j])
				{
					p = j;
					min = d[j];
				}
			}
			visited[p] = 1;
			for(j =1; j <= n; j++)
				if(!visited[j] && min+graph[p][j] < d[j])
					d[j] = min+graph[p][j];
		}
	}
}
// 10.Floyd算法
{
    void Floyd(int n)
    {
        for(int k = 1; k <= n; k++)
            for(int i = 1; i <= n; i++)
                for(int j = 1; j <= n; j++)
                {
                    if(a[i][j] > a[i][k] + a[k][j])
                        a[i][j] = a[i][k] + a[k][j];
                }
    }
}
// Dijkstra
{
    const int N = 1e3+5, inf = 1e8;
    struct road
    {
        int t, x;
        road(int to, int dx)
        {
            t = to;
            x = dx;
        }
    };
    list<road> a[N];
    int n, m;
    int lowcost[N];
    int solve(int s, int t)
    {
        for(int i = 0; i < n; i++)
            lowcost[i] = inf;
        int ans = 0;
        while(s != t)
        {
            lowcost[s] = -1;
            list<road>::iterator it;
            for(it = a[s].begin(); it != a[s].end(); it++)
            {
                if(lowcost[it->t] != -1 && lowcost[it->t] > ans + it->x)
                    lowcost[it->t] = ans + it->x;
            }
            s = t;
            for(int i = 0; i < n; i++)
                if(lowcost[i] != -1 && lowcost[i] < lowcost[s])
                    s = i;
            ans = lowcost[s];
        }
        return ans;
    }

    int main()
    {
        int u, v, x;
        while(scanf("%d%d", &n, &m) != EOF)
        {
            for(int i=0; i<n; i++)
                a[i].clear();
            for(int i = 1; i<=m; i++)
            {
                scanf("%d%d%d", &u, &v, &x);
                a[u].push_back(road(v, x));
                a[v].push_back(road(u, x));
            }
            int s, t;
            scanf("%d%d", &s, &t);
            int ans = solve(s, t);
            if(ans < inf)
                printf("%d\n", ans);
            else
                printf("-1\n");
        }
        return 0;
    }
}
