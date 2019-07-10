#include <stdio.h>
#include <algorithm>
using namespace std;

//typedef pair<int, int> pii; //src, dst
struct Order {
    int src, dst, size;
};

Order orders[10001];

bool cmp(const struct Order& lhs, const struct Order& rhs) {
    if (lhs.dst != rhs.dst) return lhs.dst < rhs.dst;
    return lhs.src < rhs.src;
}
int loaded[2001]; //해당 위치에 있을 때, 트럭에 차있는 양
int main() {
    int ans = 0;
    int n, c, m;
    scanf("%d %d", &n,&c);
    scanf("%d", &m);
    for (int i=0; i < m; i++)
        scanf("%d %d %d", &orders[i].src, &orders[i].dst, &orders[i].size);

    sort(orders, orders + m, cmp);

    for (int i=0; i<m; i++) {
        Order order = orders[i];
        int already_loaded_amount = 0;
        for (int pos = order.src; pos < order.dst; pos++) { //구간을 돌면서 가장 많이 적제된 양을 찾는다.
            if (loaded[pos] > already_loaded_amount) {
                already_loaded_amount = loaded[pos];
            }
        }
        int can_be_more_load_amt = min(order.size, c - already_loaded_amount); //더 적재할 양을 고른다.
        for (int pos = order.src; pos < order.dst; pos++) { //구간에 적재 시킨다.
            loaded[pos] += can_be_more_load_amt;
        }
        ans += can_be_more_load_amt;
    }
    printf("%d", ans);
    return 0;
}
