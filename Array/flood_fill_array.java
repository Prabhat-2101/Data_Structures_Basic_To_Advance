import java.util.*;

public class Main {
	static void printImage(int a[][]) {
		for(int i = 0; i < a.length; i++) {
			for(int j = 0; j < a[0].length; j++)
					System.out.print(a[i][j]+" ");
			System.out.println();
		}
	}
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		System.out.print("Enter row and column of matrix: ");
		int row = sc.nextInt();
		int col = sc.nextInt();
		int[][] image = new int[row][col];
		for(int i =  0; i<row; i++) {
			for(int j = 0; j < row; j++) {
				image[i][j] = sc.nextInt();
			}
		}
		System.out.print("Enter cordinates of starting cell: ");
		int x = sc.nextInt();
		int y = sc.nextInt();
		System.out.print("Enter color: ");
		int color = sc.nextInt();
		System.out.println("BEFORE FLOOD FILL: ");
		printImage(image);
		floodFill(image,x,y,color);
		System.out.println("AFTER FLOOD FILL: ");
		printImage(image);
		sc.close();
	}
	
	static int[][] floodFill(int[][] image, int x, int y, int newColor) {
		int color = image[x][y];
		if(color != newColor)
			solve(image,x,y,newColor,color);
		return image;
	}
	
	static void solve(int a[][] ,int x, int y, int newColor,int color) {
		if(x < 0||x >= a.length || y < 0 || y >= a[0].length || a[x][y] != color)
			return ;
		a[x][y] = newColor;
		solve(a,x+1,y,newColor,color);
		solve(a,x,y+1,newColor,color);
		solve(a,x-1,y,newColor,color);
		solve(a,x,y-1,newColor,color);
	}
}