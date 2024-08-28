package Package2;

class MyThreadRunnable implements Runnable{
    @Override
    public void run() {
        int i = 0;
        while (i<10) {
//            System.out.println("Hello");
            i++;
        }
    }
}

class MyThreadRunnable1 implements Runnable{
    @Override
    public void run() {
        int i = 0;
        while (i<10) {
//            System.out.println("Welcome");
            i++;
        }
    }
}

public class Prc_Multithreading_2 {
    public static void main(String[] args) {
        MyThreadRunnable ob = new MyThreadRunnable();
        Thread obj = new Thread(ob);

        obj.start();


        MyThreadRunnable1 ob1 = new MyThreadRunnable1();
        Thread obj1 = new Thread(ob1);

        obj1.start();

        obj.setPriority(Thread.MAX_PRIORITY);
        System.out.println(obj1.getPriority());
        System.out.println(Thread.currentThread());


    }

}
