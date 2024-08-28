package Package2;

interface BasicAnimal{
    void eat();
    void sleep();
}

class Monkey{
    void jump(){
        System.out.println("Hey hey jumping...");
    }
    void bite(){
        System.out.println("I will bite you...");
    }
}

class Human extends Monkey implements BasicAnimal{
    public void eat(){
        System.out.println("eating...");
    }
    public void sleep(){
        System.out.println("Shhh!! Sleeping....");
    }
}

public class AnimalClass {
    public static void main(String[] args) {
        Human aman = new Human();
        aman.eat();
        aman.bite();
        aman.jump();
        aman.sleep();

        BasicAnimal pagl = new Human();
        pagl.eat();
        pagl.sleep();
    }
}
