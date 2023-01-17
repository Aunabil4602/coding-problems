class Solution {
    public boolean areSentencesSimilar(String sentence1, String sentence2) {
        String[] words1 = sentence1.split("\s");
        String[] words2 = sentence2.split("\s");
        
        int left = 0;
        while(left<words1.length && left<words2.length
            && words1[left].equals(words2[left]))left++;

        int right2 = words2.length-1;
        int right1 = words1.length-1;

        while(right1>=0 && right2>=0 && words2[right2].equals(words1[right1])){
            right1--;
            right2--;
        }
     
        return left>right2 || left>right1;
    }
}
