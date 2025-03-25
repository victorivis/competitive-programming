/*
https://leetcode.com/problems/merge-sorted-array/description/?envType=study-plan-v2&envId=top-interview-150
*/

class Solution {
    public:
        void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
            int p1=0;
            int p2=0;
            vector<int> ans;
    
            while(p1<m && p2<n){
                if(nums1[p1] < nums2[p2]){
                    ans.push_back(nums1[p1]);
                    p1++;
                }
                else{
                    ans.push_back(nums2[p2]);
                    p2++;
                }
            }
            
            vector<int>* lower = (p2==n ? &nums1 : &nums2);
            int pL = (p2==n ? p1 : p2);
            int len = (p2==n ? m : n);
            while(pL < len){
                ans.push_back((*lower)[pL++]);
            }
            nums1 = ans;
        }
};