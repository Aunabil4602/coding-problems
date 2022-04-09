class Solution {
    public int[] topKFrequent(int[] nums, int k) {
        
        Map<Integer, Integer> cnt = new HashMap();
        List<Integer> arr = new ArrayList();
        
        
        for(int i=0;i<nums.length;i++){
            if(cnt.containsKey(nums[i])) {
                cnt.put(nums[i], cnt.get(nums[i]) + 1);
            } else {
                cnt.put(nums[i], 1);
                arr.add(nums[i]);
            }
        }
        
        Collections.sort(arr, (o1, o2) -> cnt.get(o2).compareTo(cnt.get(o1)));
        
        int ans[] = new int[k];
        for(int i=0;i<k;i++){
            ans[i] = arr.get(i);
        }
        
        return ans;
    }
}
