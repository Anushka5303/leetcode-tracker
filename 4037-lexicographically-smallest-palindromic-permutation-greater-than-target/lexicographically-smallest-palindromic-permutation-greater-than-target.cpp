class Solution {
public:
    string lexPalindromicPermutation(string s, string target) {
        int n = s.size();
        vector<int> cnt(26,0);
        for(char c: s) cnt[c-'a']++;

        int oddCount=0, oddChar=-1;
        for(int c=0;c<26;c++) if(cnt[c]%2==1){ oddCount++; oddChar=c; }
        bool feasible = (n%2==0) ? (oddCount==0) : (oddCount==1);
        if(!feasible) return "";

        int half = n/2;
        vector<int> halfCnt(26,0);
        for(int c=0;c<26;c++) halfCnt[c]=cnt[c]/2;

        string targetHalf = target.substr(0, half);
        string targetRest = target.substr(half);

        auto buildFull = [&](const string& firstHalf)->string{
            string res = firstHalf;
            if(n%2==1) res.push_back('a'+oddChar);
            string rev = firstHalf;
            reverse(rev.begin(), rev.end());
            return res + rev;
        };

        // Case B: firstHalf == targetHalf exactly achievable?
        {
            vector<int> freq(26,0);
            for(char c: targetHalf) freq[c-'a']++;
            bool matchExact = (freq == halfCnt);
            if(matchExact){
                string rest = (n%2==1? string(1, char('a'+oddChar)) : string());
                string revTH = targetHalf;
                reverse(revTH.begin(), revTH.end());
                rest += revTH;
                if(rest > targetRest) return buildFull(targetHalf);
            }
        }

        // Case A: smallest firstHalf strictly greater than targetHalf
        vector<int> avail = halfCnt;
        string matchedPrefix;
        int matchedLen = 0;
        for(int i=0;i<half;i++){
            int tc = targetHalf[i]-'a';
            if(avail[tc] > 0){ avail[tc]--; matchedPrefix.push_back('a'+tc); matchedLen++; }
            else break;
        }

        auto buildSmallest = [&](vector<int> a, int len)->string{
            string res;
            for(int i=0;i<len;i++)
                for(int c=0;c<26;c++)
                    if(a[c]>0){ res.push_back('a'+c); a[c]--; break; }
            return res;
        };

        string bestFirstHalf = "";
        int startP = min(matchedLen, half-1);
        for(int p = startP; p>=0 && bestFirstHalf.empty(); p--){
            vector<int> avail2 = halfCnt;
            bool ok = true;
            for(int k=0;k<p;k++){
                int c = matchedPrefix[k]-'a';
                if(avail2[c]<=0){ ok=false; break; }
                avail2[c]--;
            }
            if(!ok) continue;
            int tc = targetHalf[p]-'a';
            for(int c=tc+1;c<26;c++){
                if(avail2[c]>0){
                    avail2[c]--;
                    string rest = buildSmallest(avail2, half-p-1);
                    bestFirstHalf = targetHalf.substr(0,p) + char('a'+c) + rest;
                    break;
                }
            }
        }

        if(bestFirstHalf.empty()) return "";
        return buildFull(bestFirstHalf);
    }
};