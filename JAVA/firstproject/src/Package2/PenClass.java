package Package2;

abstract class Pen{
    abstract void refill();
    abstract void write();
}

class Doms extends Pen{
    void refill(){
        System.out.println("Refilling....");
    }
    void write(){
        System.out.println("Writing....");
    }
    void changeNib(){
        System.out.println("Changing Nib....");
    }
}

public class PenClass {
    public static void main(String[] args) {
        Pen user1 = new Doms();
        user1.refill();
        user1.write();

        Doms user2 = new Doms();
        user2.write();
        user2.refill();
        user2.changeNib();
    }
}