# HW4
## TEST DATA 
**AVL Tree**

| K/N  | M = 2000 | M = 10000 | M = 50000 | M = 200000 |
|:----:|:--------:|:---------:|:---------:|:----------:|
| 5 %  |   2781   |   4495    |   4243    |    5586    |
| 25 % |   2230   |   4386    |   4823    |    4375    |
| 45 % |   4384   |   5301    |   3410    |    3548    |
| 65 % |   4876   |   5179    |   5977    |    4537    |
| 85 % |   4565   |   5242    |   5361    |    5976    |

**Splay Tree**

| K/N  | M = 2000 | M = 10000 | M = 50000 | M = 200000 |
|:----:|:--------:|:---------:|:---------:|:----------:|
| 5 %  |    12    |    24     |    47     |    125     |
| 25 % |    11    |    25     |    65     |    192     |
| 45 % |    12    |    31     |    56     |    265     |
| 65 % |    14    |    51     |    149    |    199     |
| 85 % |    24    |    20     |    81     |    483     |

**interpret**
* 节点个数`N`取`10000`
* 其余测试数据数据选取完全按照ppt上要求完成

## DATA ANALYSIS

||AVL Tree|Splay Tree|
|:-------:|:------:|:-------:|
|Insert|O(logN)|O(logN)|
|Search|O(logN)|O(logN)|
|Difference|AVL树的优越性在于它可以通过插入删除始终维持这棵二叉树接近于完全二叉树，从而严格控制树的高度为logN|Splay Tree树并没有像AVL树那样严格控制每个节点平衡因子，从而保证树的高度，不过Splay树在插入、搜索操作过程中可以使当前插入、搜索的节点经过logN次的旋转操作转移到树的根节点，被“推”到下面的节点也都是最近查找过的节点，从而使最近查找过的节点位置上很接近根节点|

**proof**
* 由于测试点选取一系列连续的插入值，故数据点很连续，有利于Splay Tree的查找速率
* AVL Tree时间较Splay Tree耗时更稳定