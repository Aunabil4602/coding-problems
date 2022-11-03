class Solution {
    
    private Map<String, Integer> countMap;
    
    public int longestPalindrome(String[] words) {
        init();
        
        processInputs(words);
        
        return calculatePalindromes();
    }
    
    
    private void init() {
        countMap = new HashMap<>();
        
        for(int i=0;i<26;i++){
            for(int j=i;j<26;j++){
                String pattern = createPattern(i, j);
                String patternReverse = createPattern(j, i);
                
                countMap.put(pattern, 0);
                countMap.put(patternReverse, 0);
            }
        }
    }
    
    private String createPattern(int firstCharPosition, int secondCharPosition) {
        StringBuilder pattern = new StringBuilder();
        pattern.append((char)('a' + firstCharPosition));
        pattern.append((char)('a' + secondCharPosition));

        return pattern.toString();
    }
    
    private void processInputs(String[] words) {
        for(int i=0;i<words.length;i++){
            Integer currentCount = countMap.get(words[i]);
            currentCount++;
            countMap.put(words[i], currentCount);
        }
    }
    
    private int calculatePalindromes() {
        int result = 0;
        boolean isSingleMirrorExists = false;
        
        for(int i=0;i<26;i++){
            String patternMirror = createPattern(i, i);
            result+=(countMap.get(patternMirror)/2);
            isSingleMirrorExists = isSingleMirrorExists || (countMap.get(patternMirror)%2)==1;
            
            for(int j=i+1;j<26;j++){
                String pattern = createPattern(i, j);
                String patternReverse = createPattern(j, i);
                
                Integer currentCount = countMap.get(pattern);
                Integer currentCountReverse = countMap.get(patternReverse);
                
                
                result+=Math.min(currentCount, currentCountReverse);
            }
        }
        
        return result*4 + (isSingleMirrorExists?2:0);
    }
}
