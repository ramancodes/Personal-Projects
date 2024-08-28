package Package2;

class MyThread extends Thread{
    @Override
    public void run() {
        while (true) System.out.println("Good Morning");
    }
}

class MyThread1 extends Thread{
    @Override
    public void run(){
        while (true) System.out.println("Welcome");
    }
}

public class Prc_Multithreading{
    public static void main(String[] args) {
        MyThread ob = new MyThread();
        MyThread1 ob1 = new MyThread1();
        ob.start();
        ob1.start();
    }
}
