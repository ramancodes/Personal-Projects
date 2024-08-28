package Package2;

abstract class TelePhone{
    abstract void ring();
    abstract void lift();
    abstract void disconnect();
}

class SmartPhone extends TelePhone{
    public void ring(){
        System.out.println("Ringing...");
    }

    public void lift(){
        System.out.println("Wait!! Lifting....");
    }

    public void disconnect(){
        System.out.println("Disconnected.....");
    }
}

public class Phone {
    public static void main(String[] args) {
        TelePhone user1 = new SmartPhone();
        user1.ring();
        user1.lift();
        user1.disconnect();
    }
}
