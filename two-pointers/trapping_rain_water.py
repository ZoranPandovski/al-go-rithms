def trap(self, height):
        left_max=0
        right_max=0
        left=0
        ans=0
        right=len(height)-1
        while right>left:
            if height[left]<height[right]:
                if left_max<=height[left]:
                    left_max=height[left]
                else:
                    ans+=left_max-height[left]
                left+=1
            else:
                if right_max<=height[right]:
                    right_max=height[right]
                else:
                    ans+=right_max-height[right]
                right-=1
        return ans
