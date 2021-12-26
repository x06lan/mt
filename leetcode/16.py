class Solution:
    def threeSumClosest(self, nums,target):
        nums.sort()
        out=0
        for i in range(len(nums)-1):
            j=i+1
            k=len(nums)-1
            while j<k:
                # print(nums[i]+nums[j]+nums[k],out)
                if i==0 and j==1 and k==len(nums)-1:
                    out=nums[i]+nums[j]+nums[k]
                    if nums[i]+nums[j]+nums[k]<target:
                        j+=1
                    else:
                        k-=1

                else:
                    if abs(nums[i]+nums[j]+nums[k]-target)<abs(out-target):
                        out=nums[i]+nums[j]+nums[k]
                    if nums[i]+nums[j]+nums[k]<target:
                        j+=1
                    else:
                        k-=1


        return out 
        

d= Solution()
d=d.threeSumClosest([1,1,-1,-1,3],-1)
print(d)