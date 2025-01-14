class Solution {
public:
    int trap(vector<int>& height) {
        int left=0,right=0;
        int ans=0;
        int N=height.size();
        while(right<N){
            int valley=height[left];
            while(left<N && height[left]==0){
                left++;
            }
            if(left==N) break;
            for(right=left+1;right<N && height[right]<=valley;right++){
                valley=min(valley,height[right]);
            }
            if(right==N) break;
            int head=right+1;
            if(height[left]>height[right]){
                int last=right;
                while(head<N && height[head]<height[left]){
                    if(height[head]>height[last]){
                        last=head;
                    }
                    head++;
                }
                if(head<N && height[head]>=height[left]){
                    right=head;
                }else{
                    right=last;
                }
            }
            int lh=height[left],rh=height[right];
            for(int i=left+1;i<min(right,N);i++){
                ans+=max(0,min(lh,rh)-height[i]);
            }
            left=right;
        }
        return ans;
    }
};