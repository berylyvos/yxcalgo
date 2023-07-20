## 1. 01背包

`f[i][j]` 表示从前 `i` 个物品中选（每件物品只能选1个或不选），且总体积不超过 `j` 的情况下，最大的总价值。

1. 不选第 i 件物品： `f[i][j] = f[i - 1][j]`

2. 选第 i 件物品：   `f[i][j] = f[i - 1][j - v[i]] + w[i]`
   $$
   f[i][j] = max( f[i - 1][j], f[i - 1][j - v[i]] + w[i] )
   $$
   初始化：`f[0][0] = 0`

```c++
for (int i = 1; i <= n; ++ i)
    for (int j = 0; j <= m; ++ j) {
        f[i][j] = f[i - 1][j];
        if (j >= v[i]) f[i][j] = max(f[i][j], f[i - 1][j - v[i]] + w[i]);
    }
```

#### 空间优化

```C++
for (int i = 1; i <= n; ++ i)
	for (int j = m; j >= v[i]; -- j) // j 从大到小枚举
		f[j] = max(f[j], f[j - v[i]] + w[i]); 
// j - v[i]小于j，f[j - v[i]]一定是 i - 1 的状态
```

#### 最大价值

1. 总体积**不超过**背包容量的最大价值

   初始化：`f[0 ~ m] = 0`

   最大值：`f[m]`

2. 总体积**恰好为m**的最大价值

   初始化：`f[0] = 0, f[1 ~ m] = -INF`

   最大值：`f[m]`

   

## 2. 完全背包

`f[i][j]`表示只从前 `i` 个物品中选（每件物品可选任意个），且总体积不超过 `j` 的最大价值。

#### 状态计算

根据第 `i` 件物品的选择数量（假设最多能选 k 个）划分状态：

* 不选第 `i` 件物品：`f[i][j] = f[i - 1][j]`

* 选 `1` 个 第 `i` 件物品：`f[i][j] = f[i - 1][j - v[i]] + w[i]`

   ...

* 选 `k` 个 第 `i` 件物品：`f[i][j] = f[i - 1][j - k * v[i]] + k * w[i]`

```C++
f[i][j]     = max{ f[i-1][j], f[i-1][j - v] + w, f[i-1][j-2*v] + 2*w..., f[i-1][j - k*v] + k*w }
f[i][j - v] = max{            f[i-1][j - v],     f[i-1][j-2*v] + w, ..., f[i-1][j - k*v] + (k-1)*w }
=> 
f[i][j] = max{f[i - 1][j], f[i][j - v] + w}
```

$$
f[i][j] = max( f[i - 1][j], f[i][j - v[i]] + w[i] )
$$

```C++
for (int i = 1; i <= n; ++ i)
    for (int j = 0; j <= m; ++ j) {
        f[i][j] = f[i - 1][j];
        if (j >= v[i]) f[i][j] = max(f[i][j], f[i][j - v[i]] + w[i]);
    }
```

#### 空间优化

```C++
for (int i = 1; i <= n; ++ i)
	for (int j = v[i]; j <= m; ++ j) // j 从小到大枚举
		f[j] = max(f[j], f[j - v[i]] + w[i]);
// j - v[i] < j,  f[j - v[i]] 一定是 i 的状态
```



## 3. 多重背包

01背包的扩展：每种物品选 `[1 ~ s]` 件或不选。
$$
O(n*m*s)
$$

```C++
for (int i = 1; i <= n; ++ i)
    for (int j = m; j >= 0; -- j)
        for (int k = 1; k <= s && k * v[i] <= j; ++ k)
            f[j] = max(f[j], f[j - k * v[i]] + k * w[i]);
```

#### 多重背包的二进制优化

$$
O(n*m*log(s))
$$

思路：转化成01背包，将每种物品的件数`s`拆成`s`份，这样一共有`n*s`件物品，每件物品选或不选。

该方法的时间复杂度为`n*s*m`，还是太高。

优化：将每种物品的件数`s`拆成`log(s)`份：`1, 2, 4, ..., k`。

```C++
while (n --) {
    scanf("%d%d%d", &v, &w, &s);
    for (int k = 1; k <= s; k *= 2) {
        s -= k;
        goods.emplace(k * v, k * w);
    }
    if (s) goods.emplace(s * v, s * w);
}

for (auto good: goods)
    for (int j = m; j >= good.v; -- j)
        f[j] = max(f[j], f[j - good.v] + good.w);
```



## 4. 混合背包

01背包、完全背包、多重背包的缝合。



## 5. 二维费用的背包

`f[i][j][k]` 表示从前 `i` 件物品中选，总体积不超过 `j` 且 总重量不超过 `k` 的最大价值。
$$
f[i][j][k] = max( f[i - 1][j][k], f[i - 1][j - v[i]][k - m[i]] + w[i] )
$$


```C++
for (int i = 0; i < n; ++ i)
    for (int j = V; j >= v[i]; -- j)
        for (int k = M; k >= m[i]; -- k)
            f[j][k] = max(f[j][k], f[j - v[i]][k - m[i]] + w[i]);
```



## 6. 分组背包

`n` 件物品分成若干组，每组最多只能选 `1` 个。

```C++
for (int i = 0; i < n; ++ i)
    for (int j = m; j >= 0; --j)
        for (int k = 0; k < s[i]; ++ k)
            if (j >= v[i][k])
                f[j] = max(f[j], f[j - v[i][k]] + w[i][k]);
```



## 7. 背包方案数

`f[i][j]` 表示从前 `i` 件物品中选，且体积**恰好**为 `j` 的最大价值。

`g[i][j]` 表示 `f[i][j]` 取最大值的方案数。
$$g[i][j] = \begin{cases}g[i-1][j],&f[i-1][j] > f[i-1][j-v[i]] + w[i]\\g[i-1][j-v[i]],&f[i-1][j]<f[i-1][j-v[i]] + w[i]\\g[i-1][j]+g[i-1][j-v[i]],&f[i-1][j]=f[i-1][j-v[i]]+w[i]\end{cases}$$


```C++
for (int i = 0; i < n; ++ i)
    for (int j = m; j >= v[i]; --j) {
        int t = max(f[j], f[j - v[i]] + w[i]);
        int cnt = 0;
        if (t == f[j]) cnt += g[j];
        if (t == f[j - v[i]] + w[i]) cnt += g[j - v[i]];
        g[j] = cnt % MOD;
        f[j] = t;
    }

int maxv = 0;
for (int i = 0; i <= m; ++ i) maxv = max(maxv, f[i]);

int res = 0;
for (int i = 0; i <= m; ++ i)
    if (f[i] == maxv)
        res = (res + g[i]) % MOD;
```



## 8. 背包具体方案

1. 反向求 `n ~ 1` 件物品的最大价值。

2. 正向推 `1 ~ n` 的转移路径。

   
```C++
for (int i = n; i >= 1; -- i)
    for (int j = 0; j <= m; ++ j) {
        f[i][j] = f[i + 1][j];
        if (j >= v[i]) f[i][j] = max(f[i][j], f[i + 1][j - v[i]] + w[i]);
    }
    
int j = m;
for (int i = 1; i <= n; ++ i)
    if (j >= v[i] && f[i][j] == f[i + 1][j - v[i]] + w[i]) {
        printf("%d ", i);
        j -= v[i];
    }
```



## 9. 有依赖的背包

#### 树形 DP ：DFS + 分组背包

`f[u][j]` 表示从以 `u` 为根的子树中选，总体积不超过 `j` 的最大价值。

```C++
void dfs(int u) {
    // 将当前子树的根节点u放入背包
	for (int i = v[u]; i <= m; ++ i) f[u][i] = w[u];
    
    // 枚举所有子树
    for (int i = h[u]; ~i; i = ne[i]) {
        int son = e[i];
        
        dfs(son); // 递归求出 当前子树 满足的所有体积下 的最大价值：f[son][v[son] ~ m]
        
        for (int j = m; j >= v[u]; -- j) // 枚举总体积，不能小于根节点的体积，分配给根和当前子树
            for (int k = 0; k <= j - v[u]; ++ k) // 枚举子树分得的体积 = 分配的总体积 - 根的体积
                f[u][j] = max(f[u][j], f[u][j - k] + f[son][k]);
    }
}
```

