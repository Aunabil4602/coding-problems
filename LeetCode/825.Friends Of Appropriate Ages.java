class Solution {
    public int numFriendRequests(int[] ages) {
        int n = ages.length;
        int MAX_AGE = 120;
        int[] bucketAge = new int[MAX_AGE+1];
        int answer = 0;

        for(int age:ages){
            bucketAge[age]++;
        }

        for(int i=1;i<=MAX_AGE;i++){
            bucketAge[i]+=bucketAge[i-1];
        }

        for(int i = MAX_AGE, j = MAX_AGE;i>=1;i--){
            while(j>(i/2+7)){
                j--;
            }
            j++;

            answer+= (j<=i) ? (bucketAge[i]-bucketAge[i-1])*(bucketAge[i]-bucketAge[j-1]-1) : 0; 
        }

        return answer;
    }
}
