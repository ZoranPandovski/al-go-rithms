/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package com.sg.factorial;

/**
 *
 * @author Lucas
 */
public class Factorial {   
    
    public static int factor(int n){
        int product = 1;
        
        for (int i = 1; i <= n; i++ ){
           product = product*i;
        }
        
        return product;
    }
}
