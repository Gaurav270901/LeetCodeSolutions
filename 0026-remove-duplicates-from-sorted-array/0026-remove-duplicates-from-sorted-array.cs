public class Solution {
    public int RemoveDuplicates(int[] arr) {
       int size = arr.Length;
        if (size == 0) return 0;
        
        int i = 0; 
        for (int j = 1; j < size; j++) {
            if (arr[j] != arr[i]) {
                i++;            
                arr[i] = arr[j]; 
            }
        }

        return i + 1; 
    }
}