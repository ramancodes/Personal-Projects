package Package2;

abstract class Pen1{
    public abstract void write();
    public abstract void read();
}

public class Prc_Abstract_1 extends Pen1 {
    @Override
    public void write() {
        System.out.println("Writing...");
    }

    @Override
    public void read() {
        System.out.println("Reading...");
    }

    public void refill(){
        System.out.println("Refilling...");
    }

    public static void main(String[] args) {
        Prc_Abstract_1 ob = new Prc_Abstract_1();
        ob.write();
        ob.read();
        ob.refill();
    }
}
