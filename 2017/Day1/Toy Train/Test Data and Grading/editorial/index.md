For a set of stations $S$, define $f_A(S)$ as the set of all stations such that if the train is placed on them,
Arezou can play in a way that the train reaches one of the stations in $S$ at some point regardless
of Borzou's moves (therefore $S \subseteq f_A (S)$ by definition). We define $f_B(S)$ similarly.

Initially let $T = S$, and we iteratively add stations to $T$ such that eventually $T$ equals $f_A(S)$.

While there exists a station $v$ that satisfies one of the following conditions, we add $v$ to set $T$.
1. $v$ is owned by Arezou, and there exists an outgoing track from $v$ that leads to a station already in $T$.
1. $v$ is owned by Borzou, and all of the outgoing tracks from $v$ leads to the stations already in $T$.
Similarly we can compute $f_B(S)$.
Notice that both $f_A(S)$ and $f_B(S)$ can be computed iteratively in time $O(n + m)$.

Now let $R$ be the set of all the charging stations.
By definition, for every station $v \notin f_A(R)$, Borzou can win the game if the train is initially
placed on $v$. 

Therefore, we can solve the problem as follows:
1. If $f_A(R)$ is the set of all remaining stations, Arezou can win the game for all initial stations.
1. Otherwise:
   1. Let $X$ be set of stations not in $f_A(R)$.
   1. Borzou can win the game if the initial stations is in $f_B(X)$.
   1. Remove $f_B(X)$ from the graph and solve the problem recursively.

This algorithm runs in time $O(nm)$.
