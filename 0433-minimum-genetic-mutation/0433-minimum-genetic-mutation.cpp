class Solution {
public:
    int minMutation(string startGene, string endGene, vector<string>& bank) {
        unordered_set<string>bankSet(bank.begin(),bank.end());
        if(bankSet.find(endGene)==bankSet.end()) return -1;;

        queue<pair<string,int>>q;
        q.push({startGene,0});
        vector<char>choices={'A','C','G','T'};
        while(!q.empty()){
            auto[gene,mutations]=q.front(); q.pop();
            if(gene==endGene) return mutations;
            for(int i=0;i<gene.size();i++){
                char original=gene[i];
                for(char c:choices){
                    if(c==original) continue;
                    gene[i]=c;
                    if(bankSet.find(gene)!=bankSet.end()){
                        q.push({gene,mutations+1});
                        bankSet.erase(gene);
                    }
                }
                gene[i]=original;
            }
        }
        return -1;
    }
};