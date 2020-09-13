class GFG{ 
      
    // Utility function to check whether 
    // number is semiprime or not 
    static int checkSemiprime(int num) 
    { 
        int cnt = 0; 
      
        for (int i = 2; cnt < 2 &&  
                     i * i <= num; ++i) 
                       
            while (num % i == 0){ 
                num /= i; 
                  
                // Increment count 
                // of prime numbers 
                ++cnt; 
                } 
      
        // If number is greater than 1,  
        // add it to the count variable  
        // as it indicates the number  
        // remain is prime number 
        if (num > 1) 
            ++cnt; 
      
        // Return '1' if count is equal  
        // to '2' else return '0' 
        return cnt == 2 ? 1 : 0; 
    } 
      
    // Function to print 'True' or 'False' 
    // according to condition of semiprime 
    static void semiprime(int n) 
    { 
        if (checkSemiprime(n) != 0) 
            System.out.printf("True\n"); 
        else
            System.out.printf("False\n"); 
    } 
      
    // Driver code 
    public static void main(String[] args) 
    { 
        int n = 6; 
        semiprime(n); 
      
        n = 8; 
        semiprime(n); 
    } 
} 
