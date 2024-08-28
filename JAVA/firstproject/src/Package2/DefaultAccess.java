package Package2;

class DefaultTest{
    int var1 = 1;
    private int var2 = 2;
    protected int var3 = 3;
    public int var4 = 4;
    public static int var5 = 5;
    public void methPrint(){
        System.out.println(var1);
        System.out.println(var2);
        System.out.println(var3);
        System.out.println(var4);
        System.out.println(var5);
    }
}

class DefaultTest2 extends DefaultTest{

    public void methPrint1(){
        System.out.println(var1);
//        System.out.println(var2);
        System.out.println(var3);
        System.out.println(var4);
        System.out.println(var5);
    }
}

public class DefaultAccess {
    public static void main(String[] args) {
        DefaultTest ob = new DefaultTest();
        ob.methPrint();
        ob.var1 = 7;
        System.out.println(ob.var1);
    }
}
