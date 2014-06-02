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

void process(void) {
    cin >> N >> M;
    for(int i=0;i<N;i++) {
        cin >> st[i] >> et[i] >> sn[i];
        sn[i] = (sn[i] + M-1) / M;
        cls[i] = make_tuple(st[i], et[i], sn[i]);
    }
    for(int i=0;i<N;i++) {
        for(int j=0;j<N;j++) cin >> matrix[i][j];
    }

    sort(cls, cls+N);
    for(int i=0;i<N;i++) cout << cls[i] << endl;
    cout << endl;
}

int main(void) {
    int T;
    cin >> T;
    for(int i=0;i<T;i++) process();
    return 0;
}
