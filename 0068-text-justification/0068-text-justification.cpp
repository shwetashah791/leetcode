class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> line;
        int lineSize=0;
        int curr=0;
        int n=words.size();
        vector<string> ans;
        while(curr<n){
            if(lineSize+(line.size()-1)+(1+words[curr].size())<=maxWidth){
                lineSize+=words[curr].size();
                line.push_back(words[curr]);
                ++curr;
            }else{
                string str="";
                if(line.size()==1){
                    str+=line[0];
                    str+=string(maxWidth-str.size(),' ');
                }else{
                    int quot=(maxWidth-lineSize)/(line.size()-1);
                    int mod=(maxWidth-lineSize)%(line.size()-1);
                
                    for(int i=0;i<line.size();++i){
                        str+=line[i];
                        if(i!=line.size()-1)
                        str+=string(quot+(i<mod),' ');
                    }                
            }
            ans.push_back(str);
            line.clear();
            lineSize=0;
        }
        }
        string str="";
        for(int i=0;i<line.size();++i){
            str+=line[i];
            if(i!=line.size()-1) 
            {
                str+=" ";
            }
        }
        str+=string(maxWidth-str.size(),' ');
        ans.push_back(str);
        line.clear();
        lineSize=0;
        ans.back()+=string(maxWidth-ans.back().size(),' ');
        return ans;
        }
        };