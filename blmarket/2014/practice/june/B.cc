#include <iostream>
#include <sys/wait.h>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <sstream>
#include <numeric>
#include <iterator>
#include <queue>
#include <set>
#include <map>
#include <vector>

#define mp make_pair
#define pb push_back
#define sqr(x) ((x)*(x))
#define foreach(it,c) for(typeof((c).begin()) it = (c).begin(); it != (c).end(); ++it)

using namespace std;

typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<string> VS;
typedef pair<int,int> PII;

template<typename T> int size(const T &a) { return a.size(); } 

namespace aux{
    template<std::size_t...> struct seq{};

    template<std::size_t N, std::size_t... Is>
        struct gen_seq : gen_seq<N-1, N-1, Is...>{};

    template<std::size_t... Is>
        struct gen_seq<0, Is...> : seq<Is...>{};

    template<class Ch, class Tr, class Tuple, std::size_t... Is>
        void print_tuple(std::basic_ostream<Ch,Tr>& os, Tuple const& t, seq<Is...>){
            using swallow = int[];
            (void)swallow{0, (void(os << (Is == 0? "" : ", ") << std::get<Is>(t)), 0)...};
        }
} // aux::

    template<class Ch, class Tr, class... Args>
auto operator<<(std::basic_ostream<Ch, Tr>& os, std::tuple<Args...> const& t)
    -> std::basic_ostream<Ch, Tr>&
{
    os << "(";
    aux::print_tuple(os, t, aux::gen_seq<sizeof...(Args)>());
    return os << ")";
}

int N, M;
int st[105], et[105], sn[105];
tuple<int, int, int> cls[105];
int matrix[105][105];

vector<PII> links[220];

void add_link(int s, int e, int flow) {
    for(int i=0;i<size(links[s]);i++) {
        if(links[s][i].first == e) {
            links[s][i].second += flow;
            if(links[s][i].second == 0) {
                swap(links[s][i], links[s].back());
                links[s].pop_back();
            }
            return;
        }
    }
    links[s].pb(mp(e, flow));
}

int maxflow(int s, int e) {
    bool visit[220];
    function<int(int, int)> go = [&](int a, int flow) -> int {
        if(visit[a]) return 0;
        visit[a] = true;
        if(a == e) return flow;

        for(auto &it : links[a]) if(it.second) {
            int tmp = go(it.first, min(flow, it.second));
            if(tmp) {
                add_link(a, it.first, -tmp);
                add_link(it.first, a, tmp);
                return tmp;
            }
        }
        return 0;
    };

    int ret = 0;
    int tmp;
    memset(visit, 0, sizeof(visit));
    while((tmp = go(s, 100000))) {
        ret += tmp;
        memset(visit, 0, sizeof(visit));
    }
    return ret;
}

void process(int case_id) {
    cin >> N >> M;

    for(int i=0;i<N;i++) {
        cin >> st[i] >> et[i] >> sn[i];
        sn[i] = (sn[i] + M-1) / M;
        cls[i] = make_tuple(st[i], et[i], sn[i]);
    }
    for(int i=0;i<N;i++) {
        for(int j=0;j<N;j++) cin >> matrix[i][j];
    }

    int src = 205;
    int sink = 206;

    int ret = 0;

    for(int i=0;i<N;i++) {
        ret += get<2>(cls[i]);
        add_link(src, i*2, get<2>(cls[i]));
        add_link(i*2+1, sink, get<2>(cls[i]));

        for(int j=0;j<N;j++) {
            if(get<1>(cls[j]) + matrix[j][i] <= get<0>(cls[i])) {
                add_link(j*2, i*2+1, 100000);
            }
        }
    }
    
    int tmp = maxflow(src, sink);
    cout << "MAXFLOW = " << tmp << endl;
    ret -= tmp;
    printf("Case %d: %d\n", case_id, ret);
}

int main(void) {
    int T;
    cin >> T;
    for(int i=0;i<T;i++) process(i+1);
    return 0;
}
