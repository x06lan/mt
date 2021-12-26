class Solution:
    def threeSum(self, nums) :
        ans=[]
        nums.sort()
        if nums==[]:
            return []
        for i in range(len(nums)-1):
            j=i+1
            k=len(nums)-1
            while j<k:
                x = nums[i]+nums[j]+nums[k]
                if x==0:
                    y=[nums[i],nums[j],nums[k]]
                    ans.append(y)
                    j+=1
                    k-=1
                else:
                    if x>0:
                        k-=1
                    else:
                        j+=1
        ans.sort()
        out=[]
        
        # for removing the duplicate triplates
        for i in range(1,len(ans)):
            if ans[i-1]!=ans[i]:
                out.append(ans[i-1])
        if ans !=[]:
           out.append(ans[-1])
        return out
d= Solution()
d=d.threeSum([-1,0,1,2,-1,-4,0,0,0])
print(d)