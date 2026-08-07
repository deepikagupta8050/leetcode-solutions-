class Solution {
public:
    string smallestNumber(string num, long long t) {
        long long tt = t;
        int a0=0,b0=0,c0=0,d0=0;
        while (tt % 2 == 0) { tt/=2; a0++; }
        while (tt % 3 == 0) { tt/=3; b0++; }
        while (tt % 5 == 0) { tt/=5; c0++; }
        while (tt % 7 == 0) { tt/=7; d0++; }
        if (tt != 1) return "-1";

        int A=a0+1,B=b0+1,C=c0+1,D=d0+1;
        long long size = (long long)A*B*C*D;
        vector<int> minDigits(size, INT_MAX);

        static const int fa[10]={0,0,1,0,2,0,1,0,3,0};
        static const int fb[10]={0,0,0,1,0,0,1,0,0,2};
        static const int fc[10]={0,0,0,0,0,1,0,0,0,0};
        static const int fd[10]={0,0,0,0,0,0,0,1,0,0};

        auto idx=[&](int a,int b,int c,int d)->long long{
            return (((long long)a*B+b)*C+c)*D+d;
        };

        int maxSum=a0+b0+c0+d0;
        vector<vector<array<int,4>>> buckets(maxSum+1);
        for(int a=0;a<A;a++)for(int b=0;b<B;b++)for(int c=0;c<C;c++)for(int d=0;d<D;d++)
            buckets[a+b+c+d].push_back({a,b,c,d});

        minDigits[idx(0,0,0,0)]=0;
        for(int s=1;s<=maxSum;s++){
            for(auto &st: buckets[s]){
                int a=st[0],b=st[1],c=st[2],d=st[3];
                int best=INT_MAX;
                for(int dig=2;dig<=9;dig++){
                    int na=max(a-fa[dig],0), nb=max(b-fb[dig],0);
                    int nc=max(c-fc[dig],0), nd=max(d-fd[dig],0);
                    if(na==a&&nb==b&&nc==c&&nd==d) continue;
                    long long ni=idx(na,nb,nc,nd);
                    if(minDigits[ni]!=INT_MAX) best=min(best, minDigits[ni]+1);
                }
                minDigits[idx(a,b,c,d)]=best;
            }
        }

        int n=num.size();
        vector<int> pa(n+1,0),pb(n+1,0),pc(n+1,0),pd(n+1,0);
        int firstZero=n;
        for(int i=0;i<n;i++){
            int dg=num[i]-'0';
            if(dg==0 && firstZero==n) firstZero=i;
            pa[i+1]=min(a0,pa[i]+fa[dg]);
            pb[i+1]=min(b0,pb[i]+fb[dg]);
            pc[i+1]=min(c0,pc[i]+fc[dg]);
            pd[i+1]=min(d0,pd[i]+fd[dg]);
        }

        if(firstZero==n){
            if(pa[n]==a0&&pb[n]==b0&&pc[n]==c0&&pd[n]==d0) return num;
        }

        auto construct=[&](int a,int b,int c,int d,int len)->string{
            string res; res.reserve(len);
            int ca=a,cb=b,cc=c,cd=d,remLen=len;
            for(int pos=0;pos<len;pos++){
                for(int dig=1;dig<=9;dig++){
                    int na=max(ca-fa[dig],0), nb=max(cb-fb[dig],0);
                    int nc=max(cc-fc[dig],0), nd=max(cd-fd[dig],0);
                    long long ni=idx(na,nb,nc,nd);
                    if(minDigits[ni]<=remLen-1){
                        res.push_back('0'+dig);
                        ca=na;cb=nb;cc=nc;cd=nd;
                        remLen--;
                        break;
                    }
                }
            }
            return res;
        };

        int topI=(firstZero==n)? n-1: firstZero;
        for(int i=topI;i>=0;i--){
            int startD=(num[i]-'0')+1;
            for(int dg=startD;dg<=9;dg++){
                int ta=min(a0,pa[i]+fa[dg]), tb=min(b0,pb[i]+fb[dg]);
                int tc=min(c0,pc[i]+fc[dg]), td=min(d0,pd[i]+fd[dg]);
                int ra=a0-ta, rb=b0-tb, rc=c0-tc, rd=d0-td;
                int remLen=n-1-i;
                long long ri=idx(ra,rb,rc,rd);
                if(minDigits[ri]<=remLen){
                    string prefix=num.substr(0,i);
                    string suffix=construct(ra,rb,rc,rd,remLen);
                    return prefix+char('0'+dg)+suffix;
                }
            }
        }

        // FIX: don't force a leading '1'; let construct() pick the
        // smallest feasible leading digit at the minimal required length.
        int M=minDigits[idx(a0,b0,c0,d0)];
        int L=max(n+1, M);
        return construct(a0,b0,c0,d0,L);
    }
};