package Package1;

public class Class1 {
    public static void main(String[] args) {

    }

    public String getName(String name){
        String name1;
        if(name.equalsIgnoreCase("Raman")){
            name1 = "Raman Manjhi";
        }
        else {
            name1 = "Wrong Entry";
        }

        return name1;
    }
}
