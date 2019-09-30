/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package com.sg.hacktoberfest;

import java.util.Scanner;

/**
 *
 * @author Gina
 */
public class FactorialFun {

    public static void main(String[] args) {

        int numberEntered;
        int factorial;

        numberEntered = readInt("Enter a number: ", 0);
        factorial = numberEntered;
        int tempNum = numberEntered;

        if (numberEntered < 2) {
            factorial = 1;
        } else {
            for (int i = 1; i < numberEntered; i++) {
                factorial = factorial * (tempNum - 1);
                tempNum = tempNum - 1;
            }
        }
        
        System.out.println("\nThe factorial of " + numberEntered + " is " + factorial);
    }

    public static int readInt(String prompt, int min) {
        Scanner sc = new Scanner(System.in);
        int num = 0;
        boolean validInput = false;
        while (validInput == false) {
            System.out.println(prompt);
            String intString = sc.nextLine();
            try {
                num = Integer.parseInt(intString);
                validInput = true;
                if (num < min) {
                    validInput = false;
                    System.out.println("Please enter a number greater than or equal to " + min + ".");
                }
            } catch (NumberFormatException e) {
                System.out.println("Please enter a valid number.\n");
            }
        }
        return num;
    }
}