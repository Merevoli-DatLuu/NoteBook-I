import java.util.Scanner;
import java.lang.Math.*;

class Bai_1{
    private int a, b;
    public void Do(){
        Scanner sin = new Scanner(System.in);
        a = sin.nextInt();
        b = sin.nextInt();
        System.out.println("Tong: " + (a + b));
        System.out.println("Hieu: " + (a - b));
        System.out.println("Tich: " + (a*b));
        System.out.println("Thuong: " + (a/b));
    }
}

class Bai_2{
    private int d, r;
    public int ChuVi(){
        return (this.d + this.r) << 1;
    }
    public int DienTich(){
        return this.d*this.r;
    }
    public void Do(){
        Scanner sin = new Scanner(System.in);
        this.d = sin.nextInt();
        this.r = sin.nextInt();
        System.out.println("Chu Vi: " + ChuVi());
        System.out.println("Dien Tich: " + DienTich());
    }
}

class Bai_3{
    private int r;
    public double ChuVi(){
        return Math.PI*2*this.r;
    }
    public double DienTich(){
        return Math.PI*this.r*this.r;
    }
    public void Do(){
        Scanner sin = new Scanner(System.in);
        this.r = sin.nextInt();
        System.out.println("Chu Vi: " + ChuVi());
        System.out.println("Dien Tich: " + DienTich());
    }
}

class Bai_4{
    private int n;
    public void Do(){
        Scanner sin = new Scanner(System.in);
        n = sin.nextInt();
        if ((n & 1) != 0){
            System.out.println("So le");
        }
        else{   
            System.out.println("So chan");
        }
    }
}

class Bai_5{
    private int n;
    public void Do(){
        Scanner sin = new Scanner(System.in);
        n = sin.nextInt();
        if (n > 0){
            System.out.println("So duong");
        }
        else if (n == 0){   
            System.out.println("So zero");
        }
        else{
            System.out.println("So am");
        }
    }
}

class Bai_6{
    private int n;
    public boolean Check(int a){
        if (a < 2){
            return false;
        }
        else{
            for (int i=2; i*i <= a; i++){
                if (a%i == 0){
                    return false;
                }
            }
            return true;
        }
    }
    public void Do(){
        Scanner sin = new Scanner(System.in);
        n = sin.nextInt();
        if (Check(n)){
            System.out.println("So nguyen to");
        }
        else{   
            System.out.println("Hop so");
        }
    }
}

class Bai_7{
    private int n;
    public boolean Check(int a){
        if (a < 2){
            return false;
        }
        else{
            for (int i=2; i*i <= a; i++){
                if (a%i == 0){
                    return false;
                }
            }
            return true;
        }
    }
    public void Do(){
        Scanner sin = new Scanner(System.in);
        n = sin.nextInt();
        System.out.println("a.");
        for (int i=1; i<=n; i++){
            System.out.print(i + " ");
        }
        System.out.println();
        System.out.println((n*(n+1))/2);
        
        System.out.println("b.");
        int t = 0;
        for (int i=2; i<=n; i+=2){
            System.out.print(i + " ");
            t += i;
        }
        System.out.println();
        System.out.println(t);
        
        System.out.println("c.");
        t = 0;
        for (int i=1; i<=n; i+=2){
            System.out.print(i + " ");
            t += i;
        }
        System.out.println();
        System.out.println(t);
        
        System.out.println("d.");
        t = 0;
        for (int i=1; i<=n; i++){
            if (Check(i)){
                System.out.print(i + " ");
                t += i;
            }
        }
        System.out.println();
        System.out.println(t);
        
        System.out.println("e.");
        int i = 0;
        int a = 1;
        while (i < n){
            if (Check(a)){
                System.out.print(a + " ");
                i++;
            }
            a++;
        }
    }
}

class Bai_8{
    private int n;
    private int[] a;
    public boolean Check(int a){
        if (a < 2){
            return false;
        }
        else{
            for (int i=2; i*i <= a; i++){
                if (a%i == 0){
                    return false;
                }
            }
            return true;
        }
    }
    public void Do(){
        Scanner sin = new Scanner(System.in);
        n = sin.nextInt();
        a = new int[2*n];
        for (int i=1; i<=n; i++){
            a[i] = sin.nextInt();
        }
        System.out.println("a.");
        int t = 0;
        for (int i=1; i<=n; i++){
            System.out.print(a[i] + " ");
            t += a[i];
        }
        System.out.println();
        System.out.println((n*(n+1))/2);
        
        System.out.println("b.");
        t = 0;
        for (int i=1; i<=n; i++){
            if (a[i]%2 == 0){
                System.out.print(a[i] + " ");
                t += a[i];
            }
        }
        System.out.println();
        System.out.println(t);
        
        System.out.println("c.");
        t = 0;
        for (int i=1; i<=n; i++){
            if (a[i]%2 == 1){
                System.out.print(a[i] + " ");
                t += a[i];
            }
        }
        System.out.println();
        System.out.println(t);
        
        System.out.println("d.");
        t = 0;
        for (int i=1; i<=n; i++){
            if (Check(a[i])){
                System.out.print(a[i] + " ");
                t += a[i];
            }
        }
        System.out.println();
        System.out.println(t);
        
        System.out.println("e.");
        System.out.println("Them phan tu moi: ");
        int p = sin.nextInt();
        n++;
        a[n] = p;
        for (int i=1; i<=n; i++){
            System.out.print(a[i] + " ");
        }
        System.out.println();

        System.out.println("f.");
        System.out.println("Xoa phan tu: ");
        int k = sin.nextInt();
        for (int i=k; i<n; i++){
            a[i] = a[i+1];
        }
        n--;
        for (int i=1; i<=n; i++){
            System.out.print(a[i] + " ");
        }
        System.out.println();

        System.out.println("g.");
        System.out.println("Tim phan tu: ");
        int x = sin.nextInt();
        boolean found = false;
        for (int i=1; i<=n; i++){
            if (a[i] == x){
                System.out.println(i);
                found = true;
                break;
            }
        }
        if (!found){
            System.out.println("Khong co x");
        }
    }
}

class Bai_9{
    private String s;
    public void Do(){
        Scanner sin = new Scanner(System.in);
        this.s = sin.nextLine();
        System.out.println("a. ");
        System.out.println(this.s.length());

        System.out.println("b. ");
        System.out.println(s.replace(" ", ""));

        System.out.println("c. ");
        String[] as = s.split(" "); 

        for (String a : as) 
            System.out.print(a + " , ");

        System.out.println();
        System.out.println("d. ");
        int k = sin.nextInt();
        System.out.println(s.substring(0, k));
        System.out.println(s.substring(s.length()-k, s.length()));
        
        System.out.println("e. ");
        int n = sin.nextInt();
        k = sin.nextInt();
        System.out.println(s.substring(n, n + k));
    }
}

public class Main{
    public static void main(String[] args){
        // Bai 1
        Bai_1 t1 = new Bai_1();
        t1.Do();

        // Bai 2
        Bai_2 t2 = new Bai_2();
        t2.Do();

        // Bai 3
        Bai_3 t3 = new Bai_3();
        t3.Do();

        // Bai 4
        Bai_4 t4 = new Bai_4();
        t4.Do();

        // Bai 5
        Bai_5 t5 = new Bai_5();
        t5.Do();

        // Bai 6
        Bai_6 t6 = new Bai_6();
        t6.Do();

        // Bai 7
        Bai_7 t7 = new Bai_7();
        t7.Do();

        // Bai 8
        Bai_8 t8 = new Bai_8();
        t1.Do();

        // Bai 9
        Bai_9 t9 = new Bai_9();
        t9.Do();
        
    }
}
