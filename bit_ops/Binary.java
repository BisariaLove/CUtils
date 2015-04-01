import java.io.*;
import java.util.*;



class Binary{

	boolean getBit(int num, int i){
	return ((num&(1<<i)) != 0);
	}

	public static void main(String[] love){

		Binary obj = new Binary();
		int b = 0B1010101010;
		System.out.println("Binary Literal: "+b);
		boolean c= obj.getBit(b, 4);
		System.out.println("C: "+c);
	}



}